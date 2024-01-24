#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <netdb.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <RNADFuncionesComunes.h>
#include <FuncionesComunes.h>
#include <ctype.h>
#include <string.h>
#include <sys/timeb.h>
#include <stdlib.h>
/*! \file FuncionesComunes.c

*/
/*!
	\fn int SISCOMEnviaYRecibeCadenaFormateandoAD(int,
						      const char *,
						      const char *,
						      const char *,
						      const char *,
						      const char *,
						      int *,
						      StcLtaRegComSISCOM **,
						      char *,
						      const char *,
						      ...);
	\brief Funcion que tiene como objetivo, tomar una cadena con formato, 
	       igual al del print, formar una cadena de envio para el servidor
	       enviar la cadena y esperar la respuesta
	\param pintPtoComAD 		Puerto del servidor a donde se enviara la cadena 
	\param pchrPtrDirIpSvrAD 	Direccion ip del servidor a donde se enviara la cadena
	\param pchrPtrUsuario		Usuario del servidor a donde ser enviara la cadena
	\param pchrPtrPassword		Password del usuario en el servidor al que se enviara la cadena
	\param pchrPtrSvrAD		Nombre de la biblioteca dinamica que el servidor cargara para
					ejecutar la orden enviada. 
	\param pchrPtrNmbFSvrAD		Nombre de la funcion que se debera ejecutar para ejecutar 
					la cadena de envio
	\param pintPtrNRegistros	Parametro de salida, al cual se asignara el numero de registros
					que se responderan despues de ejecutar el envio
	\param pSLRCSisRegreso		Parametro de salida, al cual se asignara la lista simplemente
					ligada que contiene la respuesta de la cadena que se envio 
					al servidor
	\param pchrPtrBuffer		Parametro que se usa como paso, para almacenar la cadena que
					se formara para el envio	 
	\param pchrPtrFormato		Formato de Envio Igual al del printf

*/
							



int SISCOMEnviaYRecibeCadenaFormateandoAD(int pintPtoComAD,
				const char *pchrPtrDirIpSvrAD,
				const char *pchrPtrUsuario,
				const char *pchrPtrPassword,
				const char *pchrPtrSvrAD,
				const char *pchrPtrNmbFSvrAD,
				int *pintPtrNRegistros,
				StcLtaRegComSISCOM **pSLRCSisRegreso,
				char *pchrPtrBuffer,
				const char *pchrPtrFormato,
				...)
{
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisActual=0;
va_list lVLArg;
char **lchrPtrCampos=(char **)malloc(sizeof(char *)*(1));
char *lchrPtrArgumento;
int lintContador=0;
char lchrArrBuffer[20];
long llngArgumentoLong;
int lintNRegistros=1;
	(*pintPtrNRegistros)++;	
	va_start(lVLArg,pchrPtrFormato);
	lchrPtrCampos[1]=0;
	while(*pchrPtrFormato)
	{
		if(*pchrPtrFormato=='%')	
		{
		*pchrPtrFormato++;	
		switch(*pchrPtrFormato)
		{
		  case 's':
			   lchrPtrArgumento=va_arg(lVLArg,char *);
			   strcpy(pchrPtrBuffer+lintContador,lchrPtrArgumento);
			   lintContador+=strlen(lchrPtrArgumento);
		  break;
		  case 'l':
			     *pchrPtrFormato++;
			   if(*pchrPtrFormato=='d')
			   {
			      llngArgumentoLong=va_arg(lVLArg,long );
			      sprintf(lchrArrBuffer, "%ld",llngArgumentoLong);
			      strcpy(pchrPtrBuffer+lintContador,lchrArrBuffer);
			      lintContador+=strlen(lchrArrBuffer);	
			   }
		  break;
		}
		}
		else
		{
		pchrPtrBuffer[lintContador]=*pchrPtrFormato;
		lintContador++;
		}

	    *pchrPtrFormato++;
	}
	pchrPtrBuffer[lintContador]=0;
	lchrPtrCampos[0]=strdup(pchrPtrBuffer);
	 va_end(lVLArg);
	SISCOMCreaListaRegCom(lchrPtrCampos,&lSLRCSisPrim,&lSLRCSisActual);




	 SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
			 	       pchrPtrDirIpSvrAD,
				       pchrPtrUsuario,
				       pchrPtrPassword,
				       pchrPtrSvrAD,
				       pchrPtrNmbFSvrAD,
				       lintNRegistros,
				       lSLRCSisPrim,
				       pSLRCSisRegreso,
				       pintPtrNRegistros);
}




int SISCOMObtenDiaDeLaSemana()
{
time_t regTime;
struct tm *stctm;
regTime=time(NULL);
stctm=gmtime(&regTime);
return stctm->tm_wday;
}
/*!
	\fn void SISCOMSeleccionaYEjecutaOperacionAlSistema(int,
							    const char *,
							    StcOperacionesAlSistemaSISCOM *,
							    int,
							    StcLtaRegComSISCOM *,
							    StcLtaRegComSISCOM **,
							    int *);
	\brief	Funcion que se encarga de seleccionar de una lista de posibles operaciones
		que se encuentran especificadas en el arreglo del
	\param  pintPtoComAD	Puerto de comunicaciones con el servidor 
		

*/

void SISCOMSeleccionaYEjecutaOperacionAlSistema(int pintPtoComAD,
                                       const char *pchrPtrDirIpSvr,
                                       StcOperacionesAlSistemaSISCOM *pSCNSAlSistema,
                                       int pintNConsultas,
                                       StcLtaRegComSISCOM *pSLRCSisEntrada,
                                       StcLtaRegComSISCOM **pSLRCSisRespuesta,
                                       int *pintPtrNRegistros)
{                               
int lintContador;               
char **lchrPtrParametrosConsulta;
char lchrArrConsulta[8192];
StcLtaRegComSISCOM *lSLRCSisRegreso=0,
                   *lSLRCSisInserciones=0;
int lintNRegistrosReg=0;
int lintNRegInserciones=0;
        SISCOMCopiaACharCharDeComunicaciones2(1,
                                             &pSLRCSisEntrada,
                                             &lchrPtrParametrosConsulta);
        for(lintContador=0;
            lintContador<pintNConsultas; 
            lintContador++)              
        if((pSCNSAlSistema+lintContador)->EsOperacion(lchrPtrParametrosConsulta,
                                                     lchrArrConsulta,
                                                     pSLRCSisEntrada,
                                                     &lSLRCSisInserciones,
						     &lintNRegInserciones))
        {                                   
           (pSCNSAlSistema+lintContador)->EjecutaOperacionAlSistema(
                                pintPtoComAD,
                                pchrPtrDirIpSvr,
                                lchrArrConsulta,
                                lSLRCSisInserciones,
				lintNRegInserciones,
                                &lSLRCSisRegreso,
                                &lintNRegistrosReg);
           (pSCNSAlSistema+lintContador)->FormaRespuestaOperacion(
                                pintPtoComAD,
                                pchrPtrDirIpSvr,
                                lintNRegistrosReg,
                                lSLRCSisRegreso,
                                pSLRCSisRespuesta,
                                pintPtrNRegistros);
        }                              
}
void SISCOMSeleccionaYEjecutaOperacionAlSistema2(int pintPtoComAD,
                                       const char *pchrPtrDirIpSvr,
                                       StcOperacionesAlSistema2SISCOM *pSCNSAlSistema,
                                       int pintNConsultas,
                                       StcLtaRegComSISCOM *pSLRCSisEntrada,
                                       StcLtaRegComSISCOM **pSLRCSisRespuesta,
                                       int *pintPtrNRegistros)
{                               
int lintContador;               
char **lchrPtrParametrosConsulta;
char lchrArrConsulta[2048];
StcLtaRegComSISCOM *lSLRCSisRegreso=0,
                   *lSLRCSisInserciones=0;
int lintNRegistrosReg=0;
int lintNRegInserciones=0;
        SISCOMCopiaACharCharDeComunicaciones2(1,
                                             &pSLRCSisEntrada,
                                             &lchrPtrParametrosConsulta);
        for(lintContador=0;
            lintContador<pintNConsultas; 
            lintContador++)              
        if((pSCNSAlSistema+lintContador)->EsOperacion(pintPtoComAD,
						      pchrPtrDirIpSvr,
							lchrPtrParametrosConsulta,
                                                     lchrArrConsulta,
                                                     pSLRCSisEntrada,
                                                     &lSLRCSisInserciones,
						     &lintNRegInserciones))
        {                                   

           (pSCNSAlSistema+lintContador)->EjecutaOperacionAlSistema(
                                pintPtoComAD,
                                pchrPtrDirIpSvr,
                                lchrArrConsulta,
                                lSLRCSisInserciones,
				lintNRegInserciones,
                                &lSLRCSisRegreso,
                                &lintNRegistrosReg);
           (pSCNSAlSistema+lintContador)->FormaRespuestaOperacion(
                                pintPtoComAD,
                                pchrPtrDirIpSvr,
                                lintNRegistrosReg,
                                lSLRCSisRegreso,
                                pSLRCSisRespuesta,
                                pintPtrNRegistros);
        }                              

}
void SISCOMCopiaACharCharDeComunicaciones2(int pintNumCampo,
					 StcLtaRegComSISCOM **pSLRCSisDat,
					 char ***pchrPtrRegreso)
{
int lintContador;
	(*pchrPtrRegreso)=(char **)malloc(sizeof(char*));
	for(lintContador=0;
	    !SISCOMEsRegistroVacio((*pSLRCSisDat)->chrPtrRegistro);
	    lintContador++,
	    *pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig)
	 {
	   (*pchrPtrRegreso)[lintContador]=(*pSLRCSisDat)->chrPtrRegistro[pintNumCampo];
	   (*pchrPtrRegreso)=(char **)realloc(*pchrPtrRegreso,sizeof(char *)*(lintContador+2));
	 }
	(*pchrPtrRegreso)[lintContador]=0;
	    *pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;
}


void SISCOMCopiaACharCharDeComunicaciones(StcLtaRegComSISCOM *pSLRCSisDat,
					 int pintNumCampo,
					 char ***pchrPtrRegreso)
{
int lintContador;
	(*pchrPtrRegreso)=(char **)malloc(sizeof(char*));
	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	 {
	   (*pchrPtrRegreso)[lintContador]=pSLRCSisDat->chrPtrRegistro[pintNumCampo];
	   (*pchrPtrRegreso)=(char **)realloc(*pchrPtrRegreso,sizeof(char *)*(lintContador+2));
	 }
	(*pchrPtrRegreso)[lintContador]=0;
	SISCOMImprimeContenidoRegistro(*pchrPtrRegreso,"SISCOMCopiaACharCharDeComunicaciones");
}
int SISCOMEsRegistroVacio(char **pchrPtrRegistro)
{
int lintContador;
int lintNumVacios=0;

	for(lintContador=0;pchrPtrRegistro[lintContador];lintContador++)
	if(pchrPtrRegistro[lintContador][0]==0)
	 lintNumVacios++;

	return lintContador==lintNumVacios;


}
void SISCOMImprimeContenidoRegistro(char **pchrPtrRegistro,const char *pchrPtrRotulo)
{
int lintContador;

	printf("%s{",pchrPtrRotulo);
	for(lintContador=0;pchrPtrRegistro[lintContador];lintContador++)
	{
	printf("'%s'",pchrPtrRegistro[lintContador]);
	if(pchrPtrRegistro[lintContador+1])
	printf(",");
	}
	printf("}\n");

}
int SISCOMValidaRegistro(char **pchrPtrRegistro,
			 StcDRegistroAValidar pSDRAValidar)
{
int lintContador;
int lintNVacios=0,
    lintNConInfo=0;
int lintIndice;

int lintValidaConInfo,
    lintValidaSinInfo;

		for(lintContador=0;
		    pSDRAValidar.intArrConInfo[lintContador]!=-1;
		    lintContador++)
		{
		   lintIndice=pSDRAValidar.intArrConInfo[lintContador];
		   if(pchrPtrRegistro[lintIndice][0])
		    lintNConInfo++;
		}
		
	  lintValidaConInfo=lintNConInfo==lintContador;

	       for(lintContador=0;
		   pSDRAValidar.intArrSinInfo[lintContador]!=-1;
		   lintContador++)
		{
		   lintIndice=pSDRAValidar.intArrSinInfo[lintContador];
		   if(!pchrPtrRegistro[lintIndice][0])
		   lintNVacios++;
		}	
	   lintValidaSinInfo=lintNVacios==lintContador;

	return lintValidaConInfo && lintValidaSinInfo;
}
void SISCOMObtenRangoDeFechas(const char *pchrPtrRango,
		      char *pchrPtrFInicio,
		      char *pchrPtrFFin)
{
char lchrArrFechas[30];
char **lchrPtrFechas;
int lintContador;
	SISCOMAnalizaCadenas(pchrPtrRango,
			     '/',
			     lchrArrFechas,
			     &lchrPtrFechas);

	SISCOMPonFechaEntradaEnFormato(lchrPtrFechas[0],
			               "mmddaaaa",
				       "aaaammdd",
				       pchrPtrFInicio);
	SISCOMPonFechaEntradaEnFormato(lchrPtrFechas[1],
			               "mmddaaaa",
				       "aaaammdd",
				       pchrPtrFFin);
	SISCOMLiberaCharChar2((const char **)lchrPtrFechas);
}

char *SISCOMNumeroACadena(float pfltNumero)
{
char lchrArrNumero[20];
sprintf(lchrArrNumero,"%.3f",pfltNumero);
return (char *)strdup(lchrArrNumero);
}
char *SISCOMNumeroACadenaLong(long pfltNumero)
{
char lchrArrNumero[20];
sprintf(lchrArrNumero,"%ld",pfltNumero);
return (char *)strdup(lchrArrNumero);
}
void SISCOMLiberaCharChar2(const char **pchrPtrCadenas)
{
int lintContador;
	for(lintContador=0;pchrPtrCadenas[lintContador];lintContador++)
	  free(pchrPtrCadenas[lintContador]);
    free(pchrPtrCadenas);
}
void SISCOMPonFechaEntradaEnFormato(const char *pchrPtrFecha,
				    const char *pchrPtrForEnt,
				    const char *pchrPtrForSal,
				    char *pchrPtrFechaSal)
{
char **lchrPtrCadenas;
char lchrArrPartes[5];
int lintContador;
	 SISCOMAnalizaCadenas(pchrPtrFecha,'.',lchrArrPartes,&lchrPtrCadenas);
	if(!strcmp(pchrPtrForEnt,"mmddaaaa") &&
	   !strcmp(pchrPtrForSal,"aaaammdd"))
	   sprintf(pchrPtrFechaSal,
		   "%s-%s-%s",
		   lchrPtrCadenas[2],
		   lchrPtrCadenas[1],
		   lchrPtrCadenas[0]);
   SISCOMLiberaCharChar2(lchrPtrCadenas);	
}

void SISCOMCopiaOtraCadena(int pintNCadena,
		     const char *pchrPtrCadena,
		     char ***pchrPtrCadenas)
{

	(*pchrPtrCadenas)[pintNCadena]=(char *)strdup(pchrPtrCadena);
	*pchrPtrCadenas=(char **)realloc(*pchrPtrCadenas,sizeof(char *)*(pintNCadena+2));

}
int SISCOMAnalizaCadenas(const char *pchrPtrCadena,
		   char pchrSeparador,
		   char *pchrPtrBuffer,
		   char ***pchrPtrRegreso)
{
int lintContador=0;
int lintNCadenas=0;
	*pchrPtrRegreso=(char **)malloc(sizeof(char *));
	while(*pchrPtrCadena)
	{
	    if(*pchrPtrCadena==pchrSeparador)
	    {
		*pchrPtrCadena++;
		pchrPtrBuffer[lintContador]=0;
		SISCOMCopiaOtraCadena(lintNCadenas,pchrPtrBuffer,pchrPtrRegreso);
		*pchrPtrBuffer=0;
		lintContador=0;
		lintNCadenas++;
    	        (*pchrPtrRegreso)[lintNCadenas]=0; 
	    }
	    else
	    {
	    pchrPtrBuffer[lintContador]=*pchrPtrCadena;
	    *pchrPtrCadena++;
	    lintContador++;
	    }
	}
    if(lintContador)
    {
		pchrPtrBuffer[lintContador]=0;
     SISCOMCopiaOtraCadena(lintNCadenas++,pchrPtrBuffer,pchrPtrRegreso);
     (*pchrPtrRegreso)[lintNCadenas]=0; 
    }
    return lintNCadenas;

}
int SISCOMEnviaYRecibeCadenasAD(int pintPtoComAD,
				const char *pchrPtrDirIpSvrAD,
				const char *pchrPtrUsuario,
				const char *pchrPtrPassword,
				const char *pchrPtrSvrAD,
				const char *pchrPtrNmbFSvrAD,
				int *pintPtrNRegistros,
				StcLtaRegComSISCOM **pSLRCSisRegreso,
				const char *pchrPtrFormato,
				...)
{
va_list lVLArg;
StcLtaRegComSISCOM *lSLRCSisComActual=0,
		   *lSLRCSisComPriInfo=0;
int lintNRegistros=0;

	

	va_start(lVLArg,pchrPtrFormato);

	while(*pchrPtrFormato)
	{
		if(*pchrPtrFormato++=='%')	
		switch(*pchrPtrFormato)
		{
		  case 's':
			  SISCOMAnexaRegistroLEnvio(&lSLRCSisComPriInfo,
					  	    &lSLRCSisComActual,
						    1,
						    "%s",
						    va_arg(lVLArg,char *));
			  lintNRegistros++;
		  break;
		}
	}
	 va_end(lVLArg);

	 SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
			 	       pchrPtrDirIpSvrAD,
				       pchrPtrUsuario,
				       pchrPtrPassword,
				       pchrPtrSvrAD,
				       pchrPtrNmbFSvrAD,
				       lintNRegistros,
				       lSLRCSisComPriInfo,
				       pSLRCSisRegreso,
				       pintPtrNRegistros);
}

int SISCOMEjecutaConsultaSvrSiscomYEnviaAlClienteConRespuestaConstruida(int pintSCliente,
				   int pintPtoComAD,
				   const char *pchrPtrDirIpAD,
				   const char *pchrPtrUsuario,
				   const char *pchrPtrPassword,
				   const char *pchrPtrNmbDllSvrAD,
				   const char *pchrPtrNmbFuncion,
				   StcLtaRegComSISCOM *(*FormaConsultas)(int,const char *,StcLtaRegComSISCOM *,int *),
				   StcLtaRegComSISCOM *(ConstruyeRespuesta)(int,const char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM *,int *))
{
int lintNCampos,
    lintNRegistros,
    lintI,
    lintNRegRes,
    lintNRegResFormateados;
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisPActual=0,
		   *lSLRCSisPtrEnvios=0,
		   *lSLRCSisPResR=0,
		   *lSLRCSisPResFormateados;

SISCOMObtenRespuestaSVR(pintSCliente,
			&lintNCampos,
			&lintNRegistros,
			&lSLRCSisPrim);
lSLRCSisPtrEnvios=FormaConsultas(pintPtoComAD,
				 pchrPtrDirIpAD,
				 lSLRCSisPrim,
				 &lintNRegistros);
printf("%x\n",lSLRCSisPtrEnvios);
SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
		              pchrPtrDirIpAD,
			      pchrPtrUsuario,
			      pchrPtrPassword,
			      pchrPtrNmbDllSvrAD, 
			      pchrPtrNmbFuncion,
			      lintNRegistros,
			      lSLRCSisPtrEnvios,
			      &lSLRCSisPResR,
			      &lintNRegRes); 

lSLRCSisPResFormateados=ConstruyeRespuesta(pintPtoComAD,
					  pchrPtrDirIpAD,
					  lSLRCSisPrim,
					  lSLRCSisPResR,
					  &lintNRegResFormateados);
SISCOMEnviaRespuestaAlCliente(pintSCliente,
			      lSLRCSisPResFormateados,
		              lintNRegResFormateados);
}
int SISCOMEjecutaConsultaSvrSiscomYEnviaAlClienteSinEnvioAD(int pintSCliente,
							    int pintPtoComAD,
							    const char *pchrPtrDirIpAD,
							    StcLtaRegComSISCOM *(*EjecutaOperacion)(int,const char *,StcLtaRegComSISCOM *,int *))
{
int lintNCampos,
    lintNRegistros,
    lintI,
    lintNRegRes;
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisPActual=0,
		   *lSLRCSisPtrEnvios=0;

SISCOMObtenRespuestaSVR(pintSCliente,
			&lintNCampos,
			&lintNRegistros,
			&lSLRCSisPrim);
lSLRCSisPtrEnvios=EjecutaOperacion(pintPtoComAD,
				 pchrPtrDirIpAD,
				 lSLRCSisPrim,
				 &lintNRegistros);
SISCOMEnviaRespuestaAlCliente(pintSCliente,
			      lSLRCSisPtrEnvios,
		              lintNRegistros);





}
int SISCOMEjecutaConsultaSvrSiscomYEnviaAlCliente2(int pintSCliente,
				   int pintPtoComAD,
				   const char *pchrPtrDirIpAD,
				   const char *pchrPtrUsuario,
				   const char *pchrPtrPassword,
				   const char *pchrPtrNmbDllSvrAD,
				   const char *pchrPtrNmbFuncion,
				   StcLtaRegComSISCOM *(*FormaConsultas)(int,const char *,StcLtaRegComSISCOM *,int *))
{
int lintNCampos,
    lintNRegistros,
    lintI,
    lintNRegRes;
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisPActual=0,
		   *lSLRCSisPtrEnvios=0,
		   *lSLRCSisPResR=0;

SISCOMObtenRespuestaSVR(pintSCliente,
			&lintNCampos,
			&lintNRegistros,
			&lSLRCSisPrim);
lSLRCSisPtrEnvios=FormaConsultas(pintPtoComAD,
				 pchrPtrDirIpAD,
				 lSLRCSisPrim,
				 &lintNRegistros);
/*SiscomImprimeContenidoCom('|','\n',lSLRCSisPtrEnvios);*/
SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
		              pchrPtrDirIpAD,
			      pchrPtrUsuario,
			      pchrPtrPassword,
			      pchrPtrNmbDllSvrAD, 
			      pchrPtrNmbFuncion,
			      lintNRegistros,
			      lSLRCSisPtrEnvios,
			      &lSLRCSisPResR,
			      &lintNRegRes); 
SISCOMEnviaRespuestaAlCliente(pintSCliente,
			      lSLRCSisPResR,
		              lintNRegRes);
}

int SISCOMEjecutaConsultaSvrSiscomYEnviaAlCliente(int pintSCliente,
				   int pintPtoComAD,
				   const char *pchrPtrDirIpAD,
				   const char *pchrPtrUsuario,
				   const char *pchrPtrPassword,
				   const char *pchrPtrNmbDllSvrAD,
				   const char *pchrPtrNmbFuncion,
				   StcLtaRegComSISCOM *(*FormaConsultas)(StcLtaRegComSISCOM *,int *))
{
int lintNCampos,
    lintNRegistros,
    lintI,
    lintNRegRes;
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisPActual=0,
		   *lSLRCSisPtrEnvios=0,
		   *lSLRCSisPResR=0;

SISCOMObtenRespuestaSVR(pintSCliente,
			&lintNCampos,
			&lintNRegistros,
			&lSLRCSisPrim);
lSLRCSisPtrEnvios=FormaConsultas(lSLRCSisPrim,
				 &lintNRegistros);
SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
		              pchrPtrDirIpAD,
			      pchrPtrUsuario,
			      pchrPtrPassword,
			      pchrPtrNmbDllSvrAD, 
			      pchrPtrNmbFuncion,
			      lintNRegistros,
			      lSLRCSisPtrEnvios,
			      &lSLRCSisPResR,
			      &lintNRegRes); 
SISCOMEnviaRespuestaAlCliente(pintSCliente,
			      lSLRCSisPResR,
		              lintNRegRes);
}
			
long SISCOMObtenNumeroUnico()
{
struct timeb ltmbFechaH;
        ftime(&ltmbFechaH);
	return ltmbFechaH.millitm+ltmbFechaH.time;;
}
void SISCOMLiberaListaComuncaciones(StcLtaRegComSISCOM *pSLRCSisDat)
{

}
void SISCOMEnviaInformacionAlSvrAD(int pintPtoCom,
		      		   const char *pchrPtrDirIpSvrAD,
				   const char *pchrPtrUsuario,
				   const char *pchrPtrPassword,
				   const char *pchrPtrDllSvrAD,
				   const char *pchrPtrFuncionSvrAD,
		      		   int pintNRegistros,
		      		   StcLtaRegComSISCOM *pSLRCSisDat,
		                   StcLtaRegComSISCOM **pSLRCSisPtrRegPrim,
		                   int *pintPtrNReg)
{

char **lchrPtrDatosCom;
int lintSocket;
int lintNCamposR;
	SISCOMFormaDatosProtocoloInfoUsuario((char *)pchrPtrUsuario,(char *)pchrPtrPassword,&lchrPtrDatosCom);
	SISCOMFormaDatosProtocoloInfoServidor(pintPtoCom,
				              (char *)pchrPtrDirIpSvrAD,
					      (char *)pchrPtrDllSvrAD,
					      (char *)pchrPtrFuncionSvrAD,
					      &lchrPtrDatosCom);
	SISCOMEnviaInfAlServidor(lchrPtrDatosCom,
			         pintNRegistros,
				 pSLRCSisDat,
				 &lintSocket);
	SISCOMObtenRespuestaSVR(lintSocket,
				&lintNCamposR,
				pintPtrNReg,
				pSLRCSisPtrRegPrim);
				 
}
void SISCOMImprimeContenidoCom(FILE *pFlePtrSalida,
			      char pchrSepCampo,
			      char pchrSepLinea,
			      StcLtaRegComSISCOM *pSLRCSisDat)
{
int lintContador;
	while(pSLRCSisDat)
	{
		for(lintContador=0;pSLRCSisDat->chrPtrRegistro[lintContador];lintContador++)
		fprintf(pFlePtrSalida,"%s%c",
			pSLRCSisDat->chrPtrRegistro[lintContador],
			pchrSepCampo);
		fprintf(pFlePtrSalida,"%c",pchrSepLinea);
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	}
}


void SISCOMImprimeContenidoCom2(FILE *pFlePtrSalida,
			      char *pchrPtrNmbFuncion,
			      char pchrSepCampo,
			      char pchrSepLinea,
			      StcLtaRegComSISCOM *pSLRCSisDat)
{
int lintContador;
	while(pSLRCSisDat)
	{
		fprintf(pFlePtrSalida,"%s\t",pchrPtrNmbFuncion);

		for(lintContador=0;pSLRCSisDat->chrPtrRegistro[lintContador];lintContador++)
		fprintf(pFlePtrSalida,"%s%c",
			pSLRCSisDat->chrPtrRegistro[lintContador],
			pchrSepCampo);
		fprintf(pFlePtrSalida,"%c",pchrSepLinea);
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	}
}


void SISCOMImprimeContenidoCom3(const char *pchrPtrArchivo,
			      const char *pchrPtrNmbFuncion,
			      int pintNLinea,
			      char pchrSepCampo,
			      char pchrSepLinea,
			      StcLtaRegComSISCOM *pSLRCSisDat)
{
int lintContador;
	while(pSLRCSisDat)
	{
		printf("(%s) (%s) (%d) ",pchrPtrArchivo,pchrPtrNmbFuncion,pintNLinea);

		for(lintContador=0;pSLRCSisDat->chrPtrRegistro[lintContador];lintContador++)
		printf("%s%c",
			pSLRCSisDat->chrPtrRegistro[lintContador],
			pchrSepCampo);
		printf("%c",pchrSepLinea);
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig;
	}
}

void SISCOMObtenRespuestaSVR(int pintSCliente,
			     int *pintPtrNCampos,
			     int *pintPtrNRegistros,
			    StcLtaRegComSISCOM **pSLRCSisPrim)
{
StcLtaRegComSISCOM *lSLRCSisActual=0;
int lintJ,
    lintI;
char **lchrPtrRegistro;
    	SISCOMObtenInfoDelRegistro(pintSCliente,
		 		   pintPtrNCampos,
				   pintPtrNRegistros);
	for(lintI=0;lintI<*pintPtrNRegistros;lintI++)
	{
	   SISCOMObtenRegistro(pintSCliente,
			       *pintPtrNCampos,
			       &lchrPtrRegistro);
	   SISCOMCreaListaRegCom(lchrPtrRegistro,
				 pSLRCSisPrim,
				 &lSLRCSisActual);
	}	 
}


void SISCOMAnexaRegistroFormateandoParaEnvio(StcLtaRegComSISCOM **pSLRCSisPrim,
			       StcLtaRegComSISCOM **pSLRCSisActual,
			       int *pintPtrNRegistros,
			       char *pchrPtrBuffer,
			       const char *pchrPtrFormato,...)
{
va_list lVLArg;
char **lchrPtrCampos=(char **)malloc(sizeof(char *)*(1));
char *lchrPtrArgumento;
int lintContador=0;
char lchrArrBuffer[20];
long llngArgumentoLong;
	(*pintPtrNRegistros)++;	
	va_start(lVLArg,pchrPtrFormato);
	lchrPtrCampos[1]=0;
	while(*pchrPtrFormato)
	{
		if(*pchrPtrFormato=='%')	
		{
		*pchrPtrFormato++;	
		switch(*pchrPtrFormato)
		{
		  case 's':
			   lchrPtrArgumento=va_arg(lVLArg,char *);
			   strcpy(pchrPtrBuffer+lintContador,lchrPtrArgumento);
			   lintContador+=strlen(lchrPtrArgumento);
		  break;
		  case 'l':
			     *pchrPtrFormato++;
			   if(*pchrPtrFormato=='d')
			   {
			      llngArgumentoLong=va_arg(lVLArg,long );
			      sprintf(lchrArrBuffer, "%ld",llngArgumentoLong);
			      strcpy(pchrPtrBuffer+lintContador,lchrArrBuffer);
			      lintContador+=strlen(lchrArrBuffer);	
			   }
		  break;
		}
		}
		else
		{
		pchrPtrBuffer[lintContador]=*pchrPtrFormato;
		lintContador++;
		}

	    *pchrPtrFormato++;
	}
	pchrPtrBuffer[lintContador]=0;
	lchrPtrCampos[0]=strdup(pchrPtrBuffer);
	 va_end(lVLArg);
	SISCOMCreaListaRegCom(lchrPtrCampos,pSLRCSisPrim,pSLRCSisActual);
}


void SISCOMAnexaRegistroLEnvio(StcLtaRegComSISCOM **pSLRCSisPrim,
			       StcLtaRegComSISCOM **pSLRCSisActual,
			       int pintNumCampos,
			       const char *pchrPtrFormato,...)
{
va_list lVLArg;
char **lchrPtrCampos=(char **)malloc(sizeof(char *)*(pintNumCampos+1));
char *lchrPtrArgumento;
int lintContador=0;
char lchrArrFloat[20];
float lfltFloat;
long llngArgumentoLong;
	va_start(lVLArg,pchrPtrFormato);
	lchrPtrCampos[pintNumCampos]=0;
	while(*pchrPtrFormato)
	{
		if(*pchrPtrFormato++=='%')	
		switch(*pchrPtrFormato)
		{
		  case 's':
			   lchrPtrArgumento=va_arg(lVLArg,char *);
			   lchrPtrCampos[lintContador]=(char *)strdup(lchrPtrArgumento);
			   lintContador++;
		  break;
		  case 'f':
			  sprintf(lchrArrFloat,"%.2f",(float )va_arg(lVLArg,double));
			   lchrPtrCampos[lintContador]=(char *)strdup(lchrArrFloat);
			   lintContador++;

			  
		  break;
		  case 'l':
			     *pchrPtrFormato++;
			   if(*pchrPtrFormato=='d')
			   {
				printf("Combirtiendo A Long \n");
				 llngArgumentoLong=va_arg(lVLArg,long );
			      sprintf(lchrArrFloat, "%ld",llngArgumentoLong);
			      lchrPtrCampos[lintContador]=(char *)strdup(lchrArrFloat);
			      lintContador++;
			   }


		  break;
		}
	    *pchrPtrFormato++;
	}
	 va_end(lVLArg);
	SISCOMCreaListaRegCom(lchrPtrCampos,pSLRCSisPrim,pSLRCSisActual);
}

void SISCOMPonEncEnvio(int pintContador,
		       int pintNumCampos,
		       int pintNumRegistros,
		       int pintSocketSvrRN)
{

if(!pintContador)
{
char lchrArrCadEnvio[12];
	sprintf(lchrArrCadEnvio,
		"%05d%05d",
		pintNumRegistros,
		pintNumCampos);
	Write(pintSocketSvrRN,lchrArrCadEnvio,strlen(lchrArrCadEnvio));
}
}
int SISCOMFormaCadenaEnvioDinamica(char **pchrPtrRegistro,
				   int pintTamBuffer,
				   char **pchrPtrCadEnvio)
{
int lintContador;
int lintPos=0,lintTam=0;
	*pchrPtrCadEnvio=(char *)malloc(pintTamBuffer+23);
		for(lintContador=0;pchrPtrRegistro[lintContador];lintContador++)
		{
		    SISCOMFormaDatosProtocoloCHAR(pchrPtrRegistro[lintContador],
				    		  lintContador+1,
						  1,
				                  &lintTam,
						  (*pchrPtrCadEnvio)+lintPos);
		    lintPos+=lintTam;
		}
}
int SISCOMEnviaRespuestaAlCliente(int pintSCliente,
				  StcLtaRegComSISCOM *pSLRCSISCOMPtrPrimInf,
				  int pintNumRegistros)
{
int lintContador=0;
StcLtaRegComSISCOM *lSLRCSISCOMPtrDat=pSLRCSISCOMPtrPrimInf;
char *lchrPtrCadEnvio;
int lintTamBuffer;
int lintNumCampos;
	while(lSLRCSISCOMPtrDat)
	{
	    lintTamBuffer=SISCOMObtenTamanoBufferCadEnvio(lSLRCSISCOMPtrDat->chrPtrRegistro,
			    				  &lintNumCampos);
	    SISCOMFormaCadenaEnvioDinamica(lSLRCSISCOMPtrDat->chrPtrRegistro,
			    		   lintTamBuffer,
					   &lchrPtrCadEnvio);
	    SISCOMPonEncEnvio(lintContador,
			      lintNumCampos,
			      pintNumRegistros,
			      pintSCliente);
	    Write(pintSCliente,lchrPtrCadEnvio,strlen(lchrPtrCadEnvio));
	    free(lchrPtrCadEnvio);
	    lintContador++;
	    lSLRCSISCOMPtrDat=lSLRCSISCOMPtrDat->LSRCSISCOMPtrSig;
	}

}
int SISCOMEnviaInfAlServidor(char **pchrPtrDatosCom,
			      int pintNumRegistros,
			      StcLtaRegComSISCOM *pSLRCSISCOMPtrPrimInf,
			      int *pintPtrSocketSvrRN)
{
int lintContador=0;
StcLtaRegComSISCOM *lSLRCSISCOMPtrDat=pSLRCSISCOMPtrPrimInf;
int lintTamBuffer;
int lintNumCampos;
char *lchrPtrCadEnvio;
char lchrPtrCadConsulta[1024];
char lchrArrModFncYCns[1024];
int lintDesConsulta;
RNADFormaCadenaEncabezado(pchrPtrDatosCom[PROTSISCOMCNSUSUARIO],
			  pchrPtrDatosCom[PROTSISCOMCNSPASSWORD],
			  pchrPtrDatosCom[PROTSISCOMCNSDLLCNSSVR],
			  pchrPtrDatosCom[PROTSISCOMCNSFNCDLLCNS],
			  "5",
			  lchrPtrCadConsulta);
SISCOMConectateServidor(atoi(pchrPtrDatosCom[PROTSISCOMPTOSVR]),
			pchrPtrDatosCom[PROTSISCOMDIRIPSVR],
			pintPtrSocketSvrRN,
			0);
Write(*pintPtrSocketSvrRN,lchrPtrCadConsulta,strlen(lchrPtrCadConsulta));
	while(lSLRCSISCOMPtrDat)
	{
	    lintTamBuffer=SISCOMObtenTamanoBufferCadEnvio(lSLRCSISCOMPtrDat->chrPtrRegistro,
			    				  &lintNumCampos);
	    SISCOMFormaCadenaEnvioDinamica(lSLRCSISCOMPtrDat->chrPtrRegistro,
			    		   lintTamBuffer,
					   &lchrPtrCadEnvio);
	    SISCOMPonEncEnvio(lintContador,
			      lintNumCampos,
			      pintNumRegistros,
			      *pintPtrSocketSvrRN);
	    Write(*pintPtrSocketSvrRN,lchrPtrCadEnvio,strlen(lchrPtrCadEnvio));
	    free(lchrPtrCadEnvio);
	    lintContador++;
	    
	    lSLRCSISCOMPtrDat=lSLRCSISCOMPtrDat->LSRCSISCOMPtrSig;
	}
}

int SISCOMObtenTamanoBufferCadEnvio(char **pchrPtrRegistro,
				    int *pintPtrNumCampos)
{
int lintContador;
int lintSumTam=0;
	for(lintContador=0;pchrPtrRegistro[lintContador];lintContador++)
	  lintSumTam+=strlen(pchrPtrRegistro[lintContador])+13; 
	 *pintPtrNumCampos=lintContador;
	 return lintSumTam;
}
void SISCOMFormaCadenaEnvioXRegistro(char **pchrPtrRegistro,
				     char **pchrPtrCadEnvio,
				     int *pintPtrNumCampos)
{
int liContador;
	
}
void SISCOMAsignaMemoriaLtaRegCom(char **pchrPtrRegistro,StcLtaRegComSISCOM **pSLRComSISCOMPtrReg)
{
	if(!(*pSLRComSISCOMPtrReg=(StcLtaRegComSISCOM *)malloc(sizeof(StcLtaRegComSISCOM ))))
	{
	}
	else
	{
	   (*pSLRComSISCOMPtrReg)->chrPtrRegistro=pchrPtrRegistro;
	   (*pSLRComSISCOMPtrReg)->LSRCSISCOMPtrSig=0;
	   (*pSLRComSISCOMPtrReg)->LSRCSISCOMPtrAnt=0;
	}
}
void SISCOMCreaListaRegCom(char **pchrPtrRegistro,
			   StcLtaRegComSISCOM **pSLRComSISCOMPtrPrim,
			   StcLtaRegComSISCOM **pSLRComSISCOMPtrActual)
{
StcLtaRegComSISCOM *lSLRCSISCOMPtrDat=0;

	SISCOMAsignaMemoriaLtaRegCom(pchrPtrRegistro,&lSLRCSISCOMPtrDat);
	if(!(*pSLRComSISCOMPtrPrim))
	*pSLRComSISCOMPtrPrim=*pSLRComSISCOMPtrActual=lSLRCSISCOMPtrDat;
	else
	{
	  (*pSLRComSISCOMPtrActual)->LSRCSISCOMPtrSig=lSLRCSISCOMPtrDat;
	  (*pSLRComSISCOMPtrActual)=(*pSLRComSISCOMPtrActual)->LSRCSISCOMPtrSig;
	}
}
int SISCOMObtenInfoDelRegistro(int pintSocket,
			       int *pintPtrNumCampos,
			       int *pintPtrNumRegistros)
{
char lchrArrCadNumRegistros[6];
char lchrArrCadNumCampos[6];
lchrArrCadNumCampos[0]=lchrArrCadNumRegistros[0]=0;
	SISCOMLeeDatos(pintSocket,5,lchrArrCadNumRegistros,0);
	SISCOMLeeDatos(pintSocket,5,lchrArrCadNumCampos,0);
	*pintPtrNumCampos=atoi(lchrArrCadNumCampos);
	*pintPtrNumRegistros=atoi(lchrArrCadNumRegistros);
}
int SISCOMObtenRegistro(int pintSocket,
			int pintNumCampos,
			char ***pchrPtrRegistro)
{
int lintContador;
	(*pchrPtrRegistro)=(char **)malloc(sizeof(char *)*(pintNumCampos+1));
	for(lintContador=0;lintContador<pintNumCampos;lintContador++)
	   SISCOMObtenDatoDinamicoProcotolo(pintSocket,
			   		    &(*pchrPtrRegistro)[lintContador],
					    0);
	(*pchrPtrRegistro)[lintContador]=0;
}
void SISCOMFormaDatosProtocoloInfoUsuario(char *pchrPtrUsuario,
		                          char *pchrPtrPassword,
					  char ***pchrPtrProto)
{
	(*pchrPtrProto)=(char **)malloc(sizeof(char *)*(PROTSISCOMNUMCAMPOS+1));
	(*pchrPtrProto)[PROTSISCOMCNSUSUARIO]=(char *)strdup(pchrPtrUsuario);
	(*pchrPtrProto)[PROTSISCOMCNSPASSWORD]=(char *)strdup(pchrPtrPassword);
	(*pchrPtrProto)[PROTSISCOMNUMCAMPOS]=0;
}
void SISCOMFormaDatosProtocoloInfoServidor(int pintPtoSvrRN,
					   char *pchrPtrDirIpSvrRN,
					   char *pchrPtrNmbDllSisCNS,
					   char *pchrPtrNmbFncSisCNS,
					   char ***pchrPtrProto)
{
char lchrArrPtoCom[10];
	sprintf(lchrArrPtoCom,"%d",pintPtoSvrRN);
	(*pchrPtrProto)[PROTSISCOMPTOSVR]=(char *)strdup(lchrArrPtoCom);
	(*pchrPtrProto)[PROTSISCOMDIRIPSVR]=(char *)strdup(pchrPtrDirIpSvrRN);
	(*pchrPtrProto)[PROTSISCOMCNSDLLCNSSVR]=(char *)strdup(pchrPtrNmbDllSisCNS);
	(*pchrPtrProto)[PROTSISCOMCNSFNCDLLCNS]=(char *)strdup(pchrPtrNmbFncSisCNS);
}
void SISCOMFormaDatosProtocoloInfoModuloCNS(char *pchrPtrModConsulta,
					    char *pchrPtrFncModConsulta,
					    char *pchrPtrTxtIdConsulta,
					    char ***pchrPtrProto)
{
	(*pchrPtrProto)[PROTSISCOMCNSMODCONSULTA]=(char *)strdup(pchrPtrModConsulta);
	(*pchrPtrProto)[PROTSISCOMCNSFNCMODCONSULTA]=(char *)strdup(pchrPtrFncModConsulta);
	(*pchrPtrProto)[PROTSISCOMCNSTXTIDCONSULTA]=(char *)strdup(pchrPtrTxtIdConsulta);
}
int SISCOMEjecutaConsultaSvrReglasDelNegocio(char **pchrPtrDatosConsulta,
					     char *pchrPtrCadConsulta,
					     int *pintPtrSocketSvrRN)
{
char lchrPtrCadConsulta[1024];
char lchrArrModFncYCns[1024];
int lintDesConsulta;
RNADFormaCadenaEncabezado(pchrPtrDatosConsulta[PROTSISCOMCNSUSUARIO],
			  pchrPtrDatosConsulta[PROTSISCOMCNSPASSWORD],
			  pchrPtrDatosConsulta[PROTSISCOMCNSDLLCNSSVR],
			  pchrPtrDatosConsulta[PROTSISCOMCNSFNCDLLCNS],
			  "2",
			  lchrPtrCadConsulta);
SISCOMConectateServidor(atoi(pchrPtrDatosConsulta[PROTSISCOMPTOSVR]),
			pchrPtrDatosConsulta[PROTSISCOMDIRIPSVR],
			pintPtrSocketSvrRN,
			0);

lintDesConsulta=strlen(lchrPtrCadConsulta);
sprintf(lchrArrModFncYCns,
	"%s,%s,%s,%s",
	pchrPtrDatosConsulta[PROTSISCOMCNSMODCONSULTA],
	pchrPtrDatosConsulta[PROTSISCOMCNSFNCMODCONSULTA],
	pchrPtrDatosConsulta[PROTSISCOMCNSTXTIDCONSULTA],
	pchrPtrCadConsulta);
sprintf(lchrPtrCadConsulta+lintDesConsulta,
       "%04d%04d%04d%04d%04d%s",
       1,
       1,
       1,
       1,
       strlen(lchrArrModFncYCns),
       lchrArrModFncYCns);
Write(*pintPtrSocketSvrRN,lchrPtrCadConsulta,strlen(lchrPtrCadConsulta));

}
void SISCOMCambiaExtension(char *pchrPtrExtActual,
			   char *pchrPtrNvaExtension,
			   char *pchrPtrArcActual,
			   char *pchrPtrArcNuevo)
{
	SISCOMCadenaSinCadena(pchrPtrArcActual,
			       pchrPtrExtActual,
			       pchrPtrArcNuevo);
	strcat(pchrPtrArcNuevo,pchrPtrNvaExtension);
}
void SISCOMCadenaSinCadena(char *pchrPtrCadena,char *pchrPtrSubCadena,char *pchrPtrCadenaR)
{
	char *lchrPtrRegreso;
	pchrPtrCadenaR[0]=0;
	if((lchrPtrRegreso=strstr(pchrPtrCadena,pchrPtrSubCadena)))
	{
		printf("La subcadena %s\n",pchrPtrSubCadena);
		strcpy(pchrPtrCadenaR,pchrPtrCadena);
		pchrPtrCadenaR[lchrPtrRegreso-pchrPtrCadena]=0;
	}
}
void SISCOMEliminaSubCadena(char *pchrPtrCadena,char *pchrPtrSubCadena,char *pchrPtrCadenaR)
{
	char *lchrPtrRegreso;
	pchrPtrCadenaR[0]=0;
	if((lchrPtrRegreso=strstr(pchrPtrCadena,pchrPtrSubCadena)))
		strcpy(pchrPtrCadenaR,pchrPtrCadena+(lchrPtrRegreso-pchrPtrCadena)+strlen(pchrPtrSubCadena));
}	

void SISCOMBuscaCaracter(char *pchrPtrCadena,char pchrCaracter,int *pintPtrPosicion,int *pintPtrTamDOrigen)
{
	
	*pintPtrPosicion=0;
	while(pchrPtrCadena[*pintPtrPosicion]!=pchrCaracter && pchrPtrCadena[(*pintPtrPosicion)++]);
	*pintPtrTamDOrigen=(pchrPtrCadena+*pintPtrPosicion)-pchrPtrCadena;
	

}
void SISCOMCambiaMayusculas(char *pchrPtrCadena)
{
	int lintI;
	for(lintI=0;pchrPtrCadena[lintI];lintI++)
		pchrPtrCadena[lintI]=toupper(pchrPtrCadena[lintI]);

}
int SISCOMObtenSHMSvrReplicacion(void **pvidPtrMemoriaSHM)
{
unsigned long lunslngIdSHM=atol(getenv("IDSHMSISCOM"));

	if((*pvidPtrMemoriaSHM=(void *)shmat(lunslngIdSHM,0,0))==(void *)-1)
	{
		printf("Error al pegar La Memoria \n");
		return 0;
	}
return 1;
}

int SISCOMConcatenaSiEsNecesario(PARDEPURACION char *pchrPtrCadenaOrigen,char *pchrPtrCadenaQueSeSuma)
{
	int lintPos;
	if(pchrPtrCadenaOrigen[0])
	{
		lintPos=strlen(pchrPtrCadenaOrigen);
		strcpy(pchrPtrCadenaOrigen+lintPos,pchrPtrCadenaQueSeSuma);

	}
	else
	   strcpy(pchrPtrCadenaOrigen,pchrPtrCadenaQueSeSuma);

}
int SISCOMValidaSoloNumeros(PARDEPURACION char *pchrPtrCadena,char *pchrPtrCadenaError)
{
		int lintI;
		int lintSuma=0;
		for(lintI=0;pchrPtrCadena[lintI];lintI++)
		{
			if(isalpha(pchrPtrCadena[lintI]))
			{
				sprintf(pchrPtrCadenaError+lintSuma,"Error:El caracter [%c],No es un digito [0-9]\n",pchrPtrCadena[lintI]);
				lintSuma+=strlen(pchrPtrCadenaError+lintSuma);

			}
		}
	return lintSuma;	

}
void SISCOMObtenHoraActualChar(char *pchrPtrHora)
{
int lintHora,
    lintMinuto,
    lintSegundo;
	SISCOMObtenHoraActual(&lintHora,
			      &lintMinuto,
			      &lintSegundo);
	sprintf(pchrPtrHora,
		"%02d:%02d:%02d",
		lintHora,
		lintMinuto,
		lintSegundo);
				

}
void SISCOMObtenHoraActual(int *pintPtrHora,
			   int *pintPtrMinuto,
			   int *pintPtrSegundo)
{
time_t regTime;
struct tm *stctm;
/*regTime=time(NULL); */
if((regTime=time(0))==(time_t )-1)
{
printf("SISCOMObtenHoraActual:Error al obtener la fecha\n");
}
else
stctm=gmtime(&regTime);
/*
 * No se porque pero para que la hora funcionara en la
 * maquina instalada con knoppix se usa asi  en gentoo
 * trabaja sin esto
 */
ctime(&regTime);
printf("SISCOMObtenHoraActual:%s\n",asctime(stctm));


	*pintPtrHora=stctm->tm_hour;
	*pintPtrMinuto=stctm->tm_min;
	*pintPtrSegundo=stctm->tm_sec;
}
void SISCOMObtenFechaHoraActualAAAADDMM(char *pchrPtrFechaConHora)
{
char lchrArrFecha[25],
     lchrArrHora[20];
 	SISCOMObtenFechaHoyCharAAAADDMM(lchrArrFecha);
	SISCOMObtenHoraActualChar(lchrArrHora);
	sprintf(pchrPtrFechaConHora,
		"%s %s",
		lchrArrFecha,
		lchrArrHora);
}
void SISCOMObtenFechaHoyCharAAAADDMM(char *pchrPtrFecha)
{
int lintAno,
    lintMes,
    lintDia;
	SISCOMObtenFechaHoyINT(&lintDia,
			       &lintMes,
			       &lintAno);
	sprintf(pchrPtrFecha,"%04d-%02d-%02d",lintAno,lintMes,lintDia);
}
int SISCOMObtenFechaHoyINT(int *pintPtrDia,
			   int *pintPtrMes,
			   int *pintPtrAno)
{
time_t regTime;
struct tm *stctm;
struct tm res;
printf("SISCOMObtenFechaHoyINT:--->\n");
regTime=time(0);
stctm=gmtime_r(&regTime,&res); 
ctime(&regTime);
*pintPtrDia=stctm->tm_mday;
*pintPtrMes=stctm->tm_mon+1;
*pintPtrAno=stctm->tm_year+1900;

printf("SISCOMObtenFechaHoyINT:-> %d:%d:%d\n",
	res.tm_hour,
	res.tm_min,
	res.tm_sec);
printf("SISCOMObtenFechaHoyINT:%d-%d-%d:%d:%d:%d\n",
	*pintPtrDia,
	*pintPtrMes,
	*pintPtrAno,
	stctm->tm_hour,
	stctm->tm_min,
	stctm->tm_sec);
}
int SISCOMFechaDelPrecio(PARDEPURACION char *pchrPtrFechaHoy)
{
time_t regTime;
struct tm *stctm;
regTime=time(NULL);
stctm=gmtime(&regTime);
sprintf(pchrPtrFechaHoy,"%d.%d.%d",stctm->tm_mday,stctm->tm_mon+1,stctm->tm_year+1900);

}
int SISCOMConectateServidor(PARDEPURACION int pintPto,char *pchrPtrDirIP,int *pintSocket,STRUCTError *pSTRUCTErrorPtrReg)
{
struct sockaddr_in lsockaddr_inDir;
lsockaddr_inDir.sin_port=htons(pintPto);
lsockaddr_inDir.sin_family =AF_INET;
lsockaddr_inDir.sin_addr.s_addr=inet_addr(pchrPtrDirIP);
//#ifdef DEBUG
       // strcat(PDEPURACION "\t");
	//        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","SISCOMConectateServidor");
//#endif
if(pSTRUCTErrorPtrReg)
pSTRUCTErrorPtrReg->intNumError=0;
	if((*pintSocket=socket(PF_INET,SOCK_STREAM,0) )==-1 )
	{
		//un error a ocurrido
	}
	else
	if((connect(*pintSocket,(struct sockaddr *)&lsockaddr_inDir,sizeof(struct sockaddr_in))==-1))
	{
			
	}

if(pSTRUCTErrorPtrReg)
return SeDetectoError(*pSTRUCTErrorPtrReg);
}
int SISCOMObtenNombreDelBinario(PARDEPURACION char *pchrPtrNombreConRuta,char *pchrPtrNombreBinario)
{
	char *lchrPtrRegreso;
	int lintPosBin;
	if((lchrPtrRegreso=(char *)strstr(pchrPtrNombreConRuta,".bin")))
	{
		lintPosBin=strlen(lchrPtrRegreso);
		while(pchrPtrNombreConRuta[lintPosBin--]!='/');
		strcpy(pchrPtrNombreBinario,pchrPtrNombreConRuta+lintPosBin+1);
	}
}
int SISCOMLeeDatos(PARDEPURACION int pintSocket,int pintNDatos,char *pchrPtrRegreso,int pintSinEspacios)
{
	int lintI;
	char lchrCaracter;
	for(lintI=0;lintI<pintNDatos;lintI++)
	Read(pintSocket,pchrPtrRegreso+lintI,1);
	pchrPtrRegreso[pintNDatos]=0;
	if(pintSinEspacios)
	 SISCOMQuitaEspacios(pchrPtrRegreso);
}
int SISCOMCargaDllYBuscaFuncion(PARDEPURACION char *pchrPtrNombreDll,char *pchrPtrFunciones,void **pvidPtrFuncion)
{
	void *lvidDll;
	if(!(lvidDll=dlopen(pchrPtrNombreDll,RTLD_LAZY)))
	{
	printf("Error al cargar la dll *%s*\n",pchrPtrNombreDll);
	printf("error:%s\n",dlerror());
	}
	else
	if(!(*pvidPtrFuncion=dlsym(lvidDll,pchrPtrFunciones)))
	printf("La funcion %s no existe en la DLL\n",pchrPtrFunciones);
	dlclose(lvidDll);
}
int SISCOMQuitaEspacios(PARDEPURACION char *pchrPtrCadena)
{
char *lchrPtrRegreso;
	if((lchrPtrRegreso=(char *)strstr(pchrPtrCadena," ")))
	   pchrPtrCadena[lchrPtrRegreso-pchrPtrCadena]=0;	

}
int SISCOMFormaDatosProtocoloCHAR(PARDEPURACION char *pchrPtrDato,int pintNDato,int pintNCamposD,int *pintPtrTamano,char *pchrPtrCampo)
{
	sprintf(pchrPtrCampo,"%04d%04d%04d%s",pintNDato,pintNCamposD,strlen(pchrPtrDato),pchrPtrDato);
	*pintPtrTamano=strlen(pchrPtrCampo);
}

int SISCOMFormaDatosProtocoloINT(PARDEPURACION int pintDato,int pintNDato,int *pintPtrTamano,char *pchrPtrCampo)
{
	sprintf(pchrPtrCampo,"%04d%04d%05d",pintNDato,5,pintDato);
	*pintPtrTamano=strlen(pchrPtrCampo);
}

int SISCOMFormaDatosProtocoloFLOAT(PARDEPURACION float pfltDato,int pintNDato,int *pintPtrTamano,char *pchrPtrCampo)
{
}
int SISCOMFormaDatosProtocoloLONG(PARDEPURACION long plngDato,int pintNDato,int *pintPtrTamano,char *pchrPtrCampo)
{

}
int SISCOMObtenDatoDinamicoProcotolo(int pintSocket,
				     char **pchrPtrDato,
				     int *pintPtrNDato)
{
	int lintTamano;
	char lchrArrDato[6];
	SISCOMLeeDatos(pintSocket,4,lchrArrDato,0);
	if(pintPtrNDato)
	*pintPtrNDato=atoi(lchrArrDato);
	SISCOMLeeDatos(pintSocket,4,lchrArrDato,0);
	SISCOMLeeDatos(pintSocket,4,lchrArrDato,0);
	lintTamano=atoi(lchrArrDato);
	(*pchrPtrDato)=(char *)malloc(lintTamano+1);
	SISCOMLeeDatos(pintSocket,lintTamano,*pchrPtrDato,0);



}
int SISCOMObtenDatoProtocoloCHAR(PARDEPURACION int pintSocket,char *pchrPtrDato,int *pintPtrNDato)
{
	int lintTamano;
	char lchrArrDato[6];
	SISCOMLeeDatos(PDEPURACION pintSocket,4,lchrArrDato,0);
	if(pintPtrNDato)
	*pintPtrNDato=atoi(lchrArrDato);
	SISCOMLeeDatos(PDEPURACION pintSocket,4,lchrArrDato,0);
	SISCOMLeeDatos(PDEPURACION pintSocket,4,lchrArrDato,0);
	lintTamano=atoi(lchrArrDato);
	SISCOMLeeDatos(PDEPURACION pintSocket,lintTamano,pchrPtrDato,0);

}	
int SISCOMLiberaCharPtr(PARDEPURACION int pintNRegistros,int pintNColumnas,char ***pchrPtrCadena)
{
int lintI,lintJ;
	for(lintI=0;lintI<pintNRegistros;lintI++)
	{
	 for(lintJ=0;lintJ<pintNColumnas;lintJ++)
	  free(pchrPtrCadena[lintI][lintJ]);
	 free(pchrPtrCadena[lintI]);
	}
	free(pchrPtrCadena);
}
int SISCOMObtenInformacionDelProtocolo(PARDEPURACION int pintSocket,int *pintNRegistros,int *pintNColumnas,char ****pchrPtrDatos,STRUCTError *pstcErrorPtrReg)
{
	int lintNRegistros;
	int lintNColumnas;
	int lintI,lintJ;
	int lintNCaracteres;
	char lchrArrCadena[10000]; 
#ifdef DEBUG
        strcat(pchrPtrTabulador,"\t");
        SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","SISCOMObtenInformacionDelProtocolo");
#endif	
	Read(pintSocket,lchrArrCadena,4);
	lchrArrCadena[4]=0;
	*pintNRegistros=lintNRegistros=atoi(lchrArrCadena);
	Read(pintSocket,lchrArrCadena,4);
	*pintNColumnas=lintNColumnas=atoi(lchrArrCadena);
	*pchrPtrDatos=(char ***)malloc(sizeof(char **)*(lintNRegistros));
	for(lintI=0;lintI<lintNRegistros;lintI++)
	{
	    (*pchrPtrDatos)[lintI]=(char **)malloc(sizeof(char *)*(lintNColumnas+4));	
	  for(lintJ=0;lintJ<lintNColumnas;lintJ++)
	  {
		SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocket,lchrArrCadena,&lintNCaracteres);
		(*pchrPtrDatos)[lintI][lintJ]=(char *)malloc(strlen(lchrArrCadena)+1);
		strcpy((*pchrPtrDatos)[lintI][lintJ],lchrArrCadena);
	  }
	}
	(*pchrPtrDatos)[lintI]=0;
}
int SISCOMCreaSegmentoSHM(PARDEPURACION unsigned long plngKeySHM,unsigned long plngTamano,unsigned long *plngPtrRegSHMID,void **pvidPtrMemSHM,STRUCTError *pstcErrorPtrReg)
{

	if(( *plngPtrRegSHMID=shmget(plngKeySHM,plngTamano,IPC_CREAT|0666) )>0)
	{
	 if((*pvidPtrMemSHM=shmat(*plngPtrRegSHMID,0,0))==(void *)-1)
	 {
		 printf("Error al pegar el segmento de memoria compartida\n");
	 }	 
	}
	else
	printf("Error al generar el SHMID%ld %x\n",*plngPtrRegSHMID,*pvidPtrMemSHM);	


}
int SISCOMAsignaMemoriaARGS(PARDEPURACION int pintMax,int pintN,char ***pchrPtrArgv)
{
int lintI;

	*pchrPtrArgv=(char **)malloc(sizeof(char *)*pintN);
	for(lintI=0;lintI<pintN;lintI++)
	(*pchrPtrArgv)[lintI]=(char *)malloc(pintMax);
}
int SISCOMImprimeFuncionYArgumentos(char *pchrPtrTabuladores,char *pchrPtrFormato,...)
{
va_list ap;
char *lchrCadForm0,*lchrCadForm1;
char lchrReg[100];
char lchrRespaldo[100];
char *lchrPtrReg;
int i;
memset(lchrReg,0,100);
strcpy(lchrRespaldo,pchrPtrFormato);
va_start(ap, pchrPtrFormato);
printf("%s",pchrPtrTabuladores);
lchrCadForm0=lchrRespaldo;
         while(*(lchrCadForm0+1))
	 {
	  lchrCadForm0=(char *)strstr(lchrRespaldo,"%");
	  lchrCadForm1=(char *)strstr(lchrCadForm0+1,"%");
          strncpy(lchrReg,lchrCadForm0+1,lchrCadForm1-lchrCadForm0-1);
	  if(!strcmp(lchrReg,"00F"))
	  printf("%s(",(char *)va_arg(ap,char*));
	  else
	  if(!strcmp(lchrReg+3,"STRUCTDatosDeLaOperacion"))
	  RNADImprimeSTRUCTDatosDeLaOperacion((STRUCTDatosDeLaOperacion)va_arg(ap,STRUCTDatosDeLaOperacion));
          else	  
	 if(!strcmp(lchrReg+3,"char*"))
	 printf("[char *]'%s',",(char *)va_arg(ap,char*));
	 else
	 if(!strcmp(lchrReg+3,"STRUCTProductos"))
	 RNADImprimeSTRUCTProductos((STRUCTProductos)va_arg(ap,STRUCTProductos));
	 else
	 if(!strcmp(lchrReg+3,"STRUCTLtaProductos*"))
	  RNADImprimeSTRUCTLtaProductosPtr((STRUCTLtaProductos *)va_arg(ap,STRUCTLtaProductos *));
	 else
	  if(!strcmp(lchrReg+3,"STRUCTProductos*"))
	   RNADImprimeSTRUCTProductosPtr((STRUCTProductos *)va_arg(ap,STRUCTProductos *));
	 if(!strcmp(lchrReg+3,"int"))
	  printf("[int ]%d,",(int )va_arg(ap,int));
         if(!strcmp(lchrReg+3,"int*"))
	  printf("[int *] %x,",(int *)va_arg(ap,int));		
	if(!strcmp(lchrReg+3,"STRUCTProcesosYDll"))
	  ImprimeSTRUCTProcesosYDll((STRUCTProcesosYDll )va_arg(ap,STRUCTProcesosYDll));	
        strcpy(lchrRespaldo,lchrCadForm1);
        memset(lchrReg,0,100);
    }
  printf("\b)");
  va_end(ap);
}




int SiscomEscribeSocket(const char *pchrPtrArchivo,
			const char *pchrPtrFuncion,
			int pintNLinea,
			int pintSocket,
			const char *pchrPtrCadena,
			int pintTamano)
{
#ifdef __DEPURASOCKET__
printf("Write (%s) (%s) (%d) ",pchrPtrArchivo,pchrPtrFuncion,pintNLinea);
printf("(%s)(%d)\n",pchrPtrCadena,pintTamano);
#endif
write(pintSocket,pchrPtrCadena,pintTamano);

}


int SiscomLeeSocket(const char *pchrPtrArchivo,
			const char *pchrPtrFuncion,
			int pintNLinea,
			int pintSocket,
			const char *pchrPtrCadena,
			int pintTamano)
{
read(pintSocket,pchrPtrCadena,pintTamano);
#ifdef __DEPURASOCKET__
printf("Read (%s) (%s) (%d) ",pchrPtrArchivo,pchrPtrFuncion,pintNLinea);
printf("(%s)(%d)\n",pchrPtrCadena,pintTamano);
#endif
}




void SiscomMuestraCadenas(const char *pchrPtrArchivo,
			  const char *pchrPtrFuncion,
			  int pintNoLinea,
			  char **pchrPtrCadenas)
{
int lintContador=0;
printf("%s %s %d\n",pchrPtrArchivo,pchrPtrFuncion,pintNoLinea);
    while(*pchrPtrCadenas)
    {
    printf("\t %d.- %s\n",lintContador,*pchrPtrCadenas);
    lintContador++;
    pchrPtrCadenas++;
    }
}
