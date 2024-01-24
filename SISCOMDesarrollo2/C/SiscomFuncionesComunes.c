/*! \file SiscomFuncionesComunes.c
 *  \brief SISCOM Electronica.
 *         Archivo desarrolloda por Heli Garduno Esquivel 2007
 *
 *         Archivo que contiene las funciones de uso general 
 *         que se emplean para el desarrollo basados en el 
 *         esquema SISCOM.
 *
 */



#include <SiscomFuncionesComunes.h>
#include <SiscomNormalizacion.h>
#include <time.h>
#include <stdarg.h>
#include <sys/timeb.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>


void SiscomAjustaImporteAChar(float pfltImpTotal,
		        char *pchrPtrImporteTotal)
{
float lfltEntero;
float lfltFraccion=(float )(pfltImpTotal-(lfltEntero=(int )pfltImpTotal));

	 if(lfltFraccion>0.5)
	  sprintf(pchrPtrImporteTotal,"%.2f",lfltEntero+1);
	 if(lfltFraccion<0.5)
	 sprintf(pchrPtrImporteTotal,"%.2f",lfltEntero);
}

void SiscomSiguienteDia(char *pchrPtrFecha,
			char *pchrPtrFechaSigDia)
{
int lintDia,lintMes,lintAno;
SiscomDescomponFecha(pchrPtrFecha,&lintDia,&lintMes,&lintAno);
lintDia++;
sprintf(pchrPtrFechaSigDia,"%04d-%02d-%02d",lintAno,lintMes,lintDia);
strcpy(pchrPtrFecha,pchrPtrFechaSigDia);
}


void SiscomHoraFloatAChar(float pfltHora,
			  char *pchrPtrHora)
{
int lintHora=(int )pfltHora,
    lintMinutos;
float lfltResto=pfltHora-(float )lintHora,
      lfltHora=(float )lintHora;
lintMinutos=(int )((float )lfltResto*60);
sprintf(pchrPtrHora,"%02d:%02d:00",lintHora,lintMinutos);
}
void SiscomDescomponHora(const char *pchrPtrHora,
			 int *pintPtrHoras,
			 int *pintPtrMinutos,
			 int *pintPtrSegundos)
{
char lchrArrHoras[3],lchrArrMinutos[3],lchrArrSegundos[3];
strncpy(lchrArrHoras,pchrPtrHora,2);
strncpy(lchrArrMinutos,pchrPtrHora+3,2);
strncpy(lchrArrSegundos,pchrPtrHora+5,2);
lchrArrHoras[2]=0;
lchrArrMinutos[2]=0;
lchrArrSegundos[2]=0;
*pintPtrHoras=atoi(lchrArrHoras);
*pintPtrMinutos=atoi(lchrArrMinutos);
*pintPtrSegundos=atoi(lchrArrSegundos);
}
/*
 *   1  ---->  60 Minu
 *   x  ---->  30 Minu
 */
void SiscomIncrementaHora(char *pchrPtrHora,
			  char *pchrPtrHoraIncrementada,
			  int pintMinutos)
{
int lintHoras,lintMinutos,lintSegundos;
float lfltHora,lfltFraccionHora,lfltFraccionHoraIncr;
SiscomDescomponHora(pchrPtrHora,&lintHoras,&lintMinutos,&lintSegundos);
lfltFraccionHora=(float )lintMinutos/(float )60;
lfltFraccionHoraIncr=(float )pintMinutos/(float )60;
lfltHora=(float )lintHoras+lfltFraccionHora+lfltFraccionHoraIncr;
SiscomHoraFloatAChar(lfltHora,pchrPtrHora);
}
/* 1 ---------> 60
 * x ---------> 30
 * --------------
 */
float SiscomHoraAFloat(const char *pchrPtrHora)
{
int lintHoras,lintMinutos,lintSegundos;
float lfltFraccionMin;
SiscomDescomponHora(pchrPtrHora,&lintHoras,&lintMinutos,&lintSegundos);
lfltFraccionMin=(float )lintMinutos/(float )60;
return (float )lintHoras+lfltFraccionMin;
}
int SiscomVerificaHoraRango(const char *pchrPtrHora,
			    const char *pchrPtrHoraInicio,
			    const char *pchrPtrHoraFin)
{
float lfltHora,lfltHoraInicio,lfltHoraFin;

lfltHora=SiscomHoraAFloat(pchrPtrHora);
lfltHoraInicio=SiscomHoraAFloat(pchrPtrHoraInicio);
lfltHoraFin=SiscomHoraAFloat(pchrPtrHoraFin);

if(lfltHora>=lfltHoraInicio &&
   lfltHora<=lfltHoraFin)
 return 1;
 else
 return 0;
}

void SiscomObtenDatosSemana(const char *pchrPtrFecha,
			    char *pchrPtrFechaInicio,
			    char *pchrPtrFechaFin)
{
long llngGregFecha=SiscomGregorianoAJuliano2(pchrPtrFecha);
int lintDiaDeLaSemana=SiscomZeller2(pchrPtrFecha);


	SiscomJulianoAGregoriano(
			llngGregFecha - (lintDiaDeLaSemana - 1),
			pchrPtrFechaInicio);

	SiscomJulianoAGregoriano(
			llngGregFecha - (lintDiaDeLaSemana  - 1)+5,
			pchrPtrFechaFin);

}

void SiscomJulianoAGregoriano(long jdia,
			      char *pchrPtrFecha)
{
long anno, mes, dia;
long tmp1, tmp2;
tmp1 = jdia - 1721119;
anno = ((tmp1 - 1) / 1460969) * 4000;
tmp1 = ((tmp1 - 1) % 1460969) + 1;
tmp1 = (4 * tmp1) - 1;
tmp2 = (4 * ((tmp1 % 146097) / 4)) + 3;
anno = (100 * (tmp1 / 146097)) + (tmp2 / 1461) + anno;
tmp1 = (5 * (((tmp2 % 1461) + 4) / 4)) - 3;
mes = tmp1 / 153;
dia = ((tmp1 % 153) + 5) / 5;
if (mes < 10)
mes = mes + 3;
else
{
mes = mes - 9;
anno = anno + 1;
}
 sprintf(pchrPtrFecha,"%04d-%02d-%02d",(int )anno,(int )(mes),(int )dia);
}

void SiscomDescomponFecha(const char *pchrPtrFecha,
		       int *pintPtrDia,
		       int *pintPtrMes,
		       int *pintPtrAno)
{
char lchrArrDia[3],
     lchrArrMes[3],
     lchrArrAno[5];         
int lintDia,                
	lintAno,
	lintMes;
	strncpy(lchrArrAno,pchrPtrFecha,4);
	lchrArrAno[4]=0;
	strncpy(lchrArrMes,pchrPtrFecha+5,2);
	lchrArrMes[2]=0;
	strncpy(lchrArrDia,pchrPtrFecha+8,2);
	lchrArrDia[2]=0;
	
*pintPtrDia=atoi(lchrArrDia);
*pintPtrMes=atoi(lchrArrMes);
*pintPtrAno=atoi(lchrArrAno);
}

int SiscomRestaFechas(const char *pchrPtrFecha1,
		      const char *pchrPtrFecha2)
{
long llngFecha1,
	llngFecha2;

	llngFecha1=SiscomGregorianoAJuliano2(pchrPtrFecha1);
	llngFecha2=SiscomGregorianoAJuliano2(pchrPtrFecha2);

	return (int )(llngFecha1-llngFecha2);

}
long SiscomGregorianoAJuliano2(const char *pchrPtrFecha)
{
int lintAno,
    lintMes,
    lintDia;

    	SiscomDescomponFecha(pchrPtrFecha,
			     &lintDia,
			     &lintMes,
			     &lintAno);

       return SiscomGregorianoAJuliano(lintDia,
       				       lintMes,
				       lintAno);
}

long SiscomGregorianoAJuliano(int dia, int mes, int anno)
{
   /*dada una fecha del calendario gregoriano, obtiene */
   /*un entero que la representa*/
   long tmes, tanno;
   long jdia;
   /*marzo es el mes 0 del año */
   if (mes > 2)
   {
      tmes = mes - 3;
      tanno = anno;
   }
   else
   /*febrero es el mes 11 del año anterior. */
   {
      tmes = mes + 9;
      tanno = anno - 1;
   }
   jdia = (tanno / 4000) * 1460969;
   tanno = (tanno % 4000);
   jdia = jdia +
      (((tanno / 100) * 146097) / 4) +
      (((tanno % 100) * 1461) / 4) +
      (((153 * tmes) + 2) / 5) +
      dia +
      1721119;
   return jdia;    
}

int SiscomObtenNumeroSemana(const char *pchrPtrFecha)
{
int lintDia,
	lintMes,
	lintAno;
int lintPrimerDiaAno;
int lintRestaFechaPDia;
int lintDiaDeLaSemana;
int lintNumSemana;
	SiscomDescomponFecha(pchrPtrFecha,&lintDia,&lintMes,&lintAno);
	lintPrimerDiaAno=SiscomGregorianoAJuliano(1,1,lintAno);
	lintRestaFechaPDia=SiscomGregorianoAJuliano2(pchrPtrFecha)-
			   lintPrimerDiaAno;
	lintDiaDeLaSemana=SiscomZeller(lintAno,lintMes,lintDia);

	lintNumSemana=( lintRestaFechaPDia+lintDiaDeLaSemana-1)/7 + 1;

	return lintDiaDeLaSemana>=5 ? lintNumSemana-1 : lintNumSemana;


}

const char *SiscomZellerFecha(const char *pchrPtrFecha)
{
char lchrArrDia[3],
     lchrArrMes[3],
     lchrArrAno[5];
int lintDia,
 	lintAno,
	lintMes;
     strncpy(lchrArrAno,pchrPtrFecha,4);
     lchrArrAno[4]=0;
     strncpy(lchrArrMes,pchrPtrFecha+5,2);
     lchrArrMes[2]=0;
     strncpy(lchrArrDia,pchrPtrFecha+8,2);
     lchrArrDia[2]=0;

	lintDia=atoi(lchrArrDia);
	lintMes=atoi(lchrArrMes);
	lintAno=atoi(lchrArrAno);

	return SiscomZellerDia(lintAno,
			       lintMes,
			       lintDia);


}
const char *SiscomZellerDia(int pintAno,
			    int pintMes,
			    int pintDia)
{
static char *lchrPtrDias[]={
			    "Domingo",
			    "Lunes",
			    "Martes",
			    "Miercoles",
			    "Jueves",
			    "Viernes",
			    "Sabado"
			    };

	return lchrPtrDias[SiscomZeller(pintAno,
			    pintMes,
			    pintDia)];

}


int SiscomZeller(int anno, int mes, int dia)
{ 
if (mes <= 2)
{
	mes = mes + 10;
	anno = anno - 1;
}
else
{
mes = mes - 2;
}
int a= anno % 100;
int b= anno / 100;
int resultado = ( 700 + ((26 * mes -2) / 10) + dia + a+ a/ 4 + b/ 4 - 2 * b) % 7;
return resultado;
}

int SiscomZeller2(const char *pchrPtrFecha)
{
int lintDia,
	lintMes,
	lintAno;

	SiscomDescomponFecha(pchrPtrFecha,&lintDia,&lintMes,&lintAno);
	return SiscomZeller(lintAno,lintMes,lintDia);
}

void SiscomObtenFechaSemanasDespues(const char *pchrPtrFecha,
				     int pintNumSemanasMas,
				     char *pchrPtrFechaUltimoDia,
				     char *pchrPtrFechaSiguienteSemana)
{
char lchrArrFechaIni[20];
char lchrArrFechaFin[20];
long llngFechaIni;
		SiscomObtenDatosSemana(pchrPtrFecha,lchrArrFechaIni,lchrArrFechaFin);
		llngFechaIni=SiscomGregorianoAJuliano2(lchrArrFechaIni);
		llngFechaIni+=(long )(7*pintNumSemanasMas);
		SiscomJulianoAGregoriano(llngFechaIni-1,pchrPtrFechaUltimoDia);
		SiscomJulianoAGregoriano(llngFechaIni,pchrPtrFechaSiguienteSemana);
}

int SiscomEstaLaFechaEnLaSemana(const char *pchrPtrFechaIni,
				const char *pchrPtrFechaFin,
				const char *pchrPtrFecha)
{
long llngFechaIni;
long llngFechaFin;
long llngFecha;

	llngFechaIni=SiscomGregorianoAJuliano2(pchrPtrFechaIni);
	llngFechaFin=SiscomGregorianoAJuliano2(pchrPtrFechaFin);
	llngFecha=SiscomGregorianoAJuliano2(pchrPtrFecha);

	return llngFecha>=llngFechaIni &&
	       llngFecha<=llngFechaFin;
}



void SiscomFechasSemana(int pintAno,
			int pintSemana,
			char *pchrPtrFechaIni,
			char *pchrPtrFechaFin)

{
long llngSemanaFin=SiscomSemanaInicioAALong(pintAno);
long llngSemanaInicio;

llngSemanaFin+=(7*pintSemana)-2;
llngSemanaInicio=llngSemanaFin-6;
SiscomJulianoAGregoriano(llngSemanaFin,pchrPtrFechaFin);
SiscomJulianoAGregoriano(llngSemanaInicio,pchrPtrFechaIni);

}

void SiscomSemanaInicioA(int pintAno,
			 char *pchrPtrFecha)
{
sprintf(pchrPtrFecha,"%04d-01-01",pintAno);
}
long SiscomSemanaInicioAALong(int pintAno)
{
char lchrArrFechaIAno[12];
SiscomSemanaInicioA(pintAno,lchrArrFechaIAno);
return SiscomGregorianoAJuliano2(lchrArrFechaIAno);
}


void SiscomObtenSemanasAnual(int pintAno,StcSiscomSemanasAnual *pStcSemanasAnual)
{
int lintContador;

for(lintContador=1; 
    lintContador<=52;
    lintContador++,
    pStcSemanasAnual++)
  SiscomFechasSemana(pintAno,
		     lintContador,
		     pStcSemanasAnual->chrArrFechaIni,
		     pStcSemanasAnual->chrArrFechaFin);
}



void SiscomObtenDirIpMaquina(const char *pzCNmbHost,
			     char *pzCDirIPHost)
{
struct hostent *lzStcHostentReg;
int liContador=0;
struct in_addr lStcInAddrPas;
        if(lzStcHostentReg=gethostbyname(pzCNmbHost))
	for(liContador=0;lzStcHostentReg->h_addr_list[liContador];liContador++)
	{
	     memcpy(&lStcInAddrPas,
		    lzStcHostentReg->h_addr_list[liContador],
		    sizeof(lStcInAddrPas.s_addr));
	      strcpy(pzCDirIPHost,inet_ntoa(lStcInAddrPas));
	}
	else
	{
	SiscomLog(
			  "SiscomObtenDirIpMaquina:No se encontro la maquina [%s]",
			  pzCNmbHost);
	}




}
void SiscomAnexaComandoSql(const char *pchrPtrComando,
			   SiscomOperacionesServidor *pSOperacionesServidor)
{
	pSOperacionesServidor->chrPtrComandoSQL=(const char *)strdup(pchrPtrComando);
}
void SiscomIniciaComunicacionesSrv(const char *pchrPtrDirIpSvr,
				     int pintPtoCom,
				     SiscomOperacionesServidor *pSOperacionesServidor)
{
	/* 
	memset(pSOperacionesServidor,0,sizeof(SiscomOperacionesServidor));

	*/
	pSOperacionesServidor->intSocket=0;
	pSOperacionesServidor->intNRegistrosRes=0;
	pSOperacionesServidor->chrPtrEdoConexion=0;
	pSOperacionesServidor->chrPtrOperacionRes;
	pSOperacionesServidor->LCSiscomPro2=0;
	pSOperacionesServidor->LCSiscomPro2Dat=0;
	pSOperacionesServidor->intNRegistros=0;
	pSOperacionesServidor->LCSiscomPro2EPrim=0;
	pSOperacionesServidor->LCSiscomPro2EAct=0;
	pSOperacionesServidor->chrPtrComandoSQL=0;
	pSOperacionesServidor->chrPtrOperacionServidor[0]=0;
	pSOperacionesServidor->chrPtrOperacionSQL[0]=0;
	pSOperacionesServidor->intPtoCom=0;
	pSOperacionesServidor->chrPtrDirIpSvr[0]=0;
	pSOperacionesServidor->EjecutaProcesoDespues=0;

	strcpy(pSOperacionesServidor->chrPtrDirIpSvr,
	       pchrPtrDirIpSvr);
	pSOperacionesServidor->intPtoCom=pintPtoCom;
	if(pSOperacionesServidor->EjecutaProcesoAntes)
	{
	 /*
	  * HGE 6 De agosto del 2008
	  * Queretaro.
	  * En el proceso de ejecucion del sistema
	  * SISCOMElectronica, en el apartado de 
	  * busqueda de productos por descripcion
	  * al no iniciar con un dato valido EjecutaProcesoAntes
	  * se llamaba este segmento del codigo, 
	  * se procedio a enviar un mensaje al log
	  * para saber que se esta ejecutando el 
	  * proceso EjecutaProcesoAntes, y al no tener
	  * un dato valido tronaba, el mensaje en el 
	  * log permitira depurar esta caso de una
	  * forma mas rapida
	  */
	 SiscomLog("Ejecutando Proceso Antes ....");
	 pSOperacionesServidor->EjecutaProcesoAntes(pSOperacionesServidor);
	}

	 		

}
void SiscomInformacionOperaciones(const char *pchrPtrOperacionServidor,
				  const char *pchrPtrOperacionSQL,
				  SiscomOperacionesServidor *pSOperacionesServidor)
{
	strcpy(pSOperacionesServidor->chrPtrOperacionServidor,pchrPtrOperacionServidor);
	strcpy(pSOperacionesServidor->chrPtrOperacionSQL,pchrPtrOperacionSQL);
}
				    
void SiscomOperacionesServidores(SiscomOperacionesServidor *pSOperacionesServidor)
{
int lintNRegistros=0;
	pSOperacionesServidor->chrPtrEdoConexion=0;
	if(pSOperacionesServidor->LCSiscomPro2EPrim)
	{
	SiscomInformacionServidor(pSOperacionesServidor->intPtoCom,
				  pSOperacionesServidor->chrPtrDirIpSvr,
				  pSOperacionesServidor->chrPtrOperacionSQL,
				  pSOperacionesServidor->intNRegistros,
				  pSOperacionesServidor->LCSiscomPro2EPrim,
				  &pSOperacionesServidor->chrPtrEdoConexion,
				  &pSOperacionesServidor->intSocket); 
	if(!pSOperacionesServidor->chrPtrEdoConexion)
	{
	SiscomLeeNumeroRegistros(pSOperacionesServidor->intSocket,
				 &pSOperacionesServidor->intNRegistrosRes);
	SiscomLeeOperacion(pSOperacionesServidor->intSocket,
			   &pSOperacionesServidor->chrPtrOperacionRes);
	SiscomLeeInformacionProtocolo(pSOperacionesServidor->intSocket,
				      pSOperacionesServidor->intNRegistrosRes,
				      &pSOperacionesServidor->LCSiscomPro2);
	if(pSOperacionesServidor->EjecutaProcesoDespues)
	  pSOperacionesServidor->EjecutaProcesoDespues(pSOperacionesServidor);
	}
	else
	SiscomLog("%s",pSOperacionesServidor->chrPtrEdoConexion);
			
	}
	else
	if(pSOperacionesServidor->EjecutaProcesoDespues)
	  pSOperacionesServidor->EjecutaProcesoDespues(pSOperacionesServidor);


	


	

}
void SiscomConsultaBaseDatosSinDatosConexion(const char *pchrPtrConsulta,
					     const char *pchrPtrDirIpSvr,
					     int pintPtoComSvr,
					     LCamposSiscomPro2 **pLCSiscomPro2Reg,
					     int *pintPtrNRegRespuesta)
{

char *lchrPtrEdoConexion=0;
char *lchrPtrOperacionRes=0;
int lintSocketAD=0;


	SiscomConsultaBaseDeDatos(pchrPtrConsulta,
				  pchrPtrDirIpSvr,
				  pintPtoComSvr,
				  &lchrPtrEdoConexion,
				  &lintSocketAD,
				  pintPtrNRegRespuesta,
				  &lchrPtrOperacionRes,
				  pLCSiscomPro2Reg);

}

void SiscomLeeInformacionRespuesta(int pintSocket,
				   int *pintPtrNRegistros,
				   LCamposSiscomPro2 **pLCSiscomPro2)
{
char *lchrPtrOperacion;

		SiscomLeeNumeroRegistros(pintSocket,
					 pintPtrNRegistros);
		SiscomLeeOperacion(pintSocket,
				   &lchrPtrOperacion);
		SiscomLeeInformacionProtocolo(pintSocket,
					      *pintPtrNRegistros,
					      pLCSiscomPro2);

}

void SiscomConsultaBaseDeDatos(const char *pchrPtrConsultaSQL,
			       const char *pchrPtrDirIpSvr,
			       int pintPtoCom,
			       char **pchrPtrEdoConexion,
			       int *pintPtrSocket,
			       int *pintPtrNRegistrosRes,
			       char **pchrPtrOperacionRes,
			       LCamposSiscomPro2 **pLCSiscomPro2)
{
int lintNRegistros=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
		*pchrPtrEdoConexion=0;
		*pchrPtrOperacionRes=0;
		*pLCSiscomPro2=0;
	     SiscomAnexaRegistroPro2(
			&lLCSiscomPro2Ins,
                        &lLCSiscomPro2InsAct,
                        &lintNRegistros, 
			"ConsultaSQL",
			pchrPtrConsultaSQL);
	SiscomInformacionServidor(pintPtoCom,
				  pchrPtrDirIpSvr,
				  "Consultas",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  pchrPtrEdoConexion,
				  pintPtrSocket); 
	if(!*pchrPtrEdoConexion)
	{	
	SiscomLeeNumeroRegistros(*pintPtrSocket,
				 pintPtrNRegistrosRes);
	SiscomLeeOperacion(*pintPtrSocket,
			   pchrPtrOperacionRes);
	SiscomLeeInformacionProtocolo(*pintPtrSocket,
				      *pintPtrNRegistrosRes,
				      pLCSiscomPro2);
	}
	

	

}
			
				
void SiscomCopiaOtraCadena(int pintNCadena,
		     const char *pchrPtrCadena,
		     char ***pchrPtrCadenas)
{

	(*pchrPtrCadenas)[pintNCadena]=(char *)strdup(pchrPtrCadena);
	*pchrPtrCadenas=(char **)realloc(*pchrPtrCadenas,sizeof(char *)*(pintNCadena+2));

}
int SiscomAnalizaCadenas(const char *pchrPtrCadena,
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
		SiscomCopiaOtraCadena(lintNCadenas,pchrPtrBuffer,pchrPtrRegreso);
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
     SiscomCopiaOtraCadena(lintNCadenas++,pchrPtrBuffer,pchrPtrRegreso);
     (*pchrPtrRegreso)[lintNCadenas]=0; 
    }
    return lintNCadenas;

}
void SiscomEliminaCaracteres(const char *pchrPtrCaracteres,
			    char *pchrPtrCadena)
{
	
	while(*pchrPtrCaracteres)
	{
	 SiscomEliminaCaracter(*pchrPtrCaracteres,pchrPtrCadena);
	 *pchrPtrCaracteres++;
	}
	 
}
void SiscomEliminaCaracter(char pchrCaracter,
			   char *pchrPtrCadena)
{
char *lchrPtrRespaldo=(char *)strdup(pchrPtrCadena);
char *lchrPtrRespaldoRes=lchrPtrRespaldo;
int lintContador=0;
		   for(;
		       *lchrPtrRespaldo;
		       *lchrPtrRespaldo++)
		       if(*lchrPtrRespaldo!=pchrCaracter)
		       {
			  pchrPtrCadena[lintContador]=*lchrPtrRespaldo;
			  lintContador++;
		       }
	pchrPtrCadena[lintContador]=0;
	free(lchrPtrRespaldoRes); 
}
int AsignaInformacionALaEstructura(const char *pchrPtrLinea,
				    int pintNLineas,
				    SiscomDatosConfiguracion *pSDConfiguracion)
{
char *lchrPtrLinea;
int lintPosicion,
    lintTamanoSub;
	if(pchrPtrLinea[0] &&
	   pchrPtrLinea[0]!='#')
	{
	SiscomEliminaCaracter(' ',(char *)pchrPtrLinea);
	lchrPtrLinea=(char *)strdup(pchrPtrLinea);
	SiscomBuscaSubCadena(lchrPtrLinea,
			     "=",
			     &lintPosicion,
			     &lintTamanoSub);
	lchrPtrLinea[lintPosicion-1]=0;
	(pSDConfiguracion+pintNLineas)->chrPtrNmbDato=(const char *)strdup(lchrPtrLinea);
	(pSDConfiguracion+pintNLineas)->chrPtrValorDato=(const char *)strdup(pchrPtrLinea+lintPosicion);
	free(lchrPtrLinea);	
	return 1;
	}
	else
	return 0;

}
void LeeArchivo(const char *pchrPtrArchivo,
		SiscomDatosConfiguracion **pSDConfiguracion)
{
char lchrArrLinea[1024];
FILE *lFlePtrArchivo;
int lintNumEntradas=0;
if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
{
	*pSDConfiguracion=(SiscomDatosConfiguracion *)malloc(sizeof(SiscomDatosConfiguracion));
	while(!SiscomLeeLineaArchivo(lFlePtrArchivo,lchrArrLinea))
	{
	   SiscomEliminaCaracter('\t',lchrArrLinea);
				 
	   if(AsignaInformacionALaEstructura(lchrArrLinea, 
					     lintNumEntradas,
					     *pSDConfiguracion))
	   {
	        lintNumEntradas++;
	       *pSDConfiguracion=(SiscomDatosConfiguracion *)realloc(*pSDConfiguracion,
								     sizeof(SiscomDatosConfiguracion)*
								     (lintNumEntradas+1));
	   }
	}
	(*pSDConfiguracion)->intNumEntradas=lintNumEntradas;
}
				    



}
void SiscomEliminaCadenaDespuesCadena(const char *pchrPtrSubCadena,
				      char *pchrPtrCadena)
{
int lintPosicion;
int lintTamano;
if(SiscomBuscaSubCadena(pchrPtrCadena,
			pchrPtrSubCadena,
			&lintPosicion,
			&lintTamano))
     *(pchrPtrCadena+lintPosicion-1)=0;

}


const char *SiscomObtenCadenaSeparador(const char *pchrPtrCadena,
						      char pchrSeparador)
{
	while(*pchrPtrCadena &&
	     *pchrPtrCadena!=pchrSeparador)
	pchrPtrCadena++;
	if(*pchrPtrCadena)
	return ++pchrPtrCadena;
	else
	return pchrPtrCadena;
}

const char *SiscomCadenaEntreSeparadores(
				  const char *pchrPtrEntrada,
				  char pchrSepInicio,
				  char pchrSepFin,
				  char *pchrPtrCadena)
{
const char *lchrPtrCadena;

   lchrPtrCadena=SiscomObtenCadenaSeparador(pchrPtrEntrada,
   				      pchrSepInicio);
   while(*lchrPtrCadena!=pchrSepFin)
   {
	*pchrPtrCadena=*lchrPtrCadena;
	pchrPtrCadena++;
	lchrPtrCadena++;

   }
*pchrPtrCadena=0;	
return ++lchrPtrCadena;
}


int SiscomBuscaSubCadena(const char *pzCCadena,
                         const char *pzCSubCadena,
                         int *pzIPosicion,
                         int *pzITamano)
{
        char *lzCRegreso;
        int liRegreso=0;
        if((lzCRegreso=strstr(pzCCadena,
                              pzCSubCadena)))
        {
                *pzIPosicion=lzCRegreso-pzCCadena+1;
                liRegreso=1;
                *pzITamano=strlen(pzCSubCadena);
        }
        return liRegreso;
}
void SiscomAnalizaArchivoConfiguracion(const char *pchrPtrArchivo,
				       void (*AsignaInformacion)(SiscomDatosConfiguracion *,void *),
				       void *pvidPtrConfiguracion)
{
SiscomDatosConfiguracion *lSDatosConf;
int lintContador;
	LeeArchivo(pchrPtrArchivo,
		   &lSDatosConf);	
	AsignaInformacion(lSDatosConf,pvidPtrConfiguracion);
}	
int SiscomLeeLineaArchivo(FILE *pzFleArchivo,
                     char *pzCCadena)
{
int liContador=0;
             while((pzCCadena[liContador]=getc(pzFleArchivo))!='\n' &&
                    pzCCadena[liContador]!=(char )EOF)
                 liContador++;
           pzCCadena[liContador]=0;
        return feof(pzFleArchivo); 
}
const char *BuscaDatoConfiguracion(SiscomDatosConfiguracion *pSiscomConfiguracion,
				   const char *pchrPtrDato)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSiscomConfiguracion->intNumEntradas;
	    lintContador++)
	  if(!strcmp((pSiscomConfiguracion+lintContador)->chrPtrNmbDato,
		     pchrPtrDato))
	    return (pSiscomConfiguracion+lintContador)->chrPtrValorDato;

	return 0;

}
void SiscomAsignaDatoConfiguracionINT(SiscomDatosConfiguracion *pSiscomConfiguracion,
				   const char *pchrPtrDato,
				   int *pintPtrDatoInt)
{
const char *lchrPtrDato;
	lchrPtrDato=BuscaDatoConfiguracion(pSiscomConfiguracion,pchrPtrDato);
	if(lchrPtrDato)
	 *pintPtrDatoInt=atoi(lchrPtrDato);			
}

void SiscomAsignaDatoConfiguracionFLOAT(SiscomDatosConfiguracion *pSiscomConfiguracion,
				   const char *pchrPtrDato,
				   float *pintPtrDatoFloat)
{
const char *lchrPtrDato;
	lchrPtrDato=BuscaDatoConfiguracion(pSiscomConfiguracion,pchrPtrDato);
	if(lchrPtrDato)
	 *pintPtrDatoFloat=atof(lchrPtrDato);			
}
void SiscomAsignaDatoConfiguracionCHAR(SiscomDatosConfiguracion *pSiscomConfiguracion,
				   const char *pchrPtrDato,
				   char **pchrPtrDatoChar)
{
const char *lchrPtrDato;
	lchrPtrDato=BuscaDatoConfiguracion(pSiscomConfiguracion,pchrPtrDato);
	if(lchrPtrDato)
	 *pchrPtrDatoChar=(char *)lchrPtrDato;			
}


void SiscomObtenHoraActualChar(char *pchrPtrHora)
{
int lintHora,
    lintMinuto,
    lintSegundo;
        SiscomObtenHoraActual(&lintHora,
                              &lintMinuto,
                              &lintSegundo);
        sprintf(pchrPtrHora,
                "%02d:%02d:%02d",
                lintHora,
                lintMinuto,
                lintSegundo);
                       

}
void SiscomObtenHoraActual(int *pintPtrHora,
                           int *pintPtrMinuto,
                           int *pintPtrSegundo)
{
time_t regTime;
struct tm *stctm;
regTime=time(NULL);
stctm=localtime(&regTime);

        *pintPtrHora=stctm->tm_hour;
        *pintPtrMinuto=stctm->tm_min;
        *pintPtrSegundo=stctm->tm_sec;
}
void SiscomObtenFechaHoraActualAAAADDMM(char *pchrPtrFechaConHora)
{
char lchrArrFecha[25],
     lchrArrHora[20];
        SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
        SiscomObtenHoraActualChar(lchrArrHora);
        sprintf(pchrPtrFechaConHora,
                "%sT%s",
                lchrArrFecha,
                lchrArrHora);
}
void SiscomObtenFechaHoyCharAAAADDMM(char *pchrPtrFecha)
{
int lintAno,
    lintMes,
    lintDia;
        SiscomObtenFechaHoyINT(&lintDia,
                               &lintMes,
                               &lintAno);
        sprintf(pchrPtrFecha,"%04d-%02d-%02d",lintAno,lintMes,lintDia);
}
int SiscomObtenFechaHoyINT(int *pintPtrDia,
                           int *pintPtrMes,
                           int *pintPtrAno)
{
time_t regTime;
struct tm *stctm;
regTime=time(0); 
stctm=localtime(&regTime); 
*pintPtrDia=stctm->tm_mday;
*pintPtrMes=stctm->tm_mon+1;
*pintPtrAno=stctm->tm_year+1900;
}
void SiscomObtenFechaHoy(char *pchrPtrFecha)
{
char *lchrArrDias[]={ ""
		     "Lunes",
		     "Martes",
		     "Miercoles",
		     "Jueves",
		     "Viernes",
		     "Sabado",
		     "Domingo"};
char *lchrArrMeses[]={"",
		      "Enero",
		      "Febrero",
		      "Marzo",
		      "Abril",
		      "Mayo",
		      "Junio",
		      "Julio",
		      "Agosto",
		      "Septiembre",
		      "Octubre",
		      "Noviembre",
		      "Diciembre"};
int lintDia,
    lintMes,
    lintAno;

SiscomObtenFechaHoyINT(&lintDia,
		       &lintMes,
		       &lintAno);
sprintf(pchrPtrFecha,
	"%02d de %s de %d",
	lintDia,
	lchrArrMeses[lintMes],
	lintAno);
}
void SiscomFechaLocal(char *pchrPtrFecha)
{
time_t ltimeRegreso;
char *lchrPtrRegreso;
        ltimeRegreso=time(0);
        lchrPtrRegreso=(char *)strdup(ctime(&ltimeRegreso));

	SiscomEliminaCaracter('\n',lchrPtrRegreso);
	strcpy(pchrPtrFecha,lchrPtrRegreso);
	free(lchrPtrRegreso);	

}
void SiscomMensajesLog2(const char *pzCadenaFormato,...)
 {
         va_list lzArgumentos;
        const char *lzCadenaFormato=pzCadenaFormato;
   char  lzMen[1024];
        char *lzParametroChar;
   char  lzFechaActual[25];
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
	SiscomFechaLocal(lzFechaActual);
        va_start(lzArgumentos,pzCadenaFormato);
        fprintf(gPtrFleArchivoLog,
		"%s:",
                lzFechaActual);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,
                                                       char *);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%s",
                                        lzMen,
                                        lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%f",
                                         lzMen,
                                         lfParametroFloat);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%d",
                                        lzMen,
                                        liParametroInt);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%x",
                                         lzMen,
                                         lzParametroChar);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        if(lzMen[0])
        fprintf(gPtrFleArchivoLog,"%s",lzMen);
        fprintf(gPtrFleArchivoLog,"\n");
        va_end(lzArgumentos);
        fflush(gPtrFleArchivoLog);
 
 }

void SiscomMensajesLog2A(const char *pchrPtrArchivo,
			 const char *pchrPtrFuncion,
			 int pintNoLinea,
			 const char *pzCadenaFormato,...)
 {
         va_list lzArgumentos;
        const char *lzCadenaFormato=pzCadenaFormato;
   char  lzMen[1024];
        char *lzParametroChar;
   char  lzFechaActual[25];
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
	SiscomFechaLocal(lzFechaActual);
        va_start(lzArgumentos,pzCadenaFormato);
        fprintf(gPtrFleArchivoLog,
		"%s:( %s %s %d ) ",
                lzFechaActual,
		pchrPtrArchivo,
		pchrPtrFuncion,
		pintNoLinea);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,
                                                       char *);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%s",
                                        lzMen,
                                        lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%f",
                                         lzMen,
                                         lfParametroFloat);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%d",
                                        lzMen,
                                        liParametroInt);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%x",
                                         lzMen,
                                         lzParametroChar);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        if(lzMen[0])
        fprintf(gPtrFleArchivoLog,"%s",lzMen);
        fprintf(gPtrFleArchivoLog,"\n");
        va_end(lzArgumentos);
        fflush(gPtrFleArchivoLog);
 
 }
void SiscomMensajesLog(FILE *pFlePtrArchivoLog,
			const char *pzCadenaFormato,...)
 {
         va_list lzArgumentos;
        const char *lzCadenaFormato=pzCadenaFormato;
   char  lzMen[1024];
        char *lzParametroChar;
   char  lzFechaActual[25];
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
	SiscomFechaLocal(lzFechaActual);
        va_start(lzArgumentos,pzCadenaFormato);
        fprintf(pFlePtrArchivoLog,
		"%s:",
                lzFechaActual);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,
                                                       char *);
                                fprintf(pFlePtrArchivoLog,
                                        "%s%s",
                                        lzMen,
                                        lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                fprintf(pFlePtrArchivoLog,
                                        "%s%f",
                                         lzMen,
                                         lfParametroFloat);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                fprintf(pFlePtrArchivoLog,
                                        "%s%d",
                                        lzMen,
                                        liParametroInt);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                fprintf(pFlePtrArchivoLog,
                                        "%s%x",
                                         lzMen,
                                         lzParametroChar);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        if(lzMen[0])
        fprintf(pFlePtrArchivoLog,"%s",lzMen);
        fprintf(pFlePtrArchivoLog,"\n");
        va_end(lzArgumentos);
        fflush(pFlePtrArchivoLog);
 
 }

void SiscomObtenNumeroUnicoChar(char *pchrPtrUnico)
{
static int lintContador=0;
	sprintf(pchrPtrUnico,
		"%ld",
		SiscomObtenNumeroUnico()+lintContador);
	lintContador++;
}
long SiscomObtenNumeroUnico()
{
/*
struct timeb ltmbFechaH;
        ftime(&ltmbFechaH);
	return ltmbFechaH.millitm+ltmbFechaH.time;;
*/
struct timeval ltRegreso;
gettimeofday(&ltRegreso,0);
return ltRegreso.tv_sec+ltRegreso.tv_usec;
}
void SiscomFormaComandosSql(int pintSocket,
			    int pintNRegistros,
			    int pintPtoComSvr,
			    const char *pchrPtrDirIpSvr,
			    const char *pchrPtrBaseDatos,
			    const char *pchrPtrPtoBaseDatos,
			    void (*CreaCadenaComando)(int,
			    			     const char *,
						     const char *,
						     const char *,
						     LCamposSiscomPro2 *,
						     char *),
			    char *pchrPtrBufferComando,
			    LCamposSiscomPro2 **pLCSiscomPro2Reg)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char *lchrPtrEdoConexion=0;
int lintNRegistros=0,
    lintSocketAD;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
	 CreaCadenaComando(pintPtoComSvr,
	 		   pchrPtrDirIpSvr,
			   pchrPtrBaseDatos,
			   pchrPtrPtoBaseDatos,
			   lLCSiscomPro2,
			   pchrPtrBufferComando);
	 if(pchrPtrBaseDatos)
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "BaseDatos,	\
				  PtoBaseDatos, \
				  ComandoSQL",
				  pchrPtrBaseDatos,
				  pchrPtrPtoBaseDatos,
				  pchrPtrBufferComando);
	 else
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 pchrPtrBufferComando);

  }
  	if(pchrPtrBaseDatos)
	SiscomInformacionServidor(pintPtoComSvr,
	                          pchrPtrDirIpSvr,
				  "InsercionesBaseDatos",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	else
	SiscomInformacionServidor(pintPtoComSvr,
	                          pchrPtrDirIpSvr,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
}
			    		
void SiscomCreaNodoListaGeneral(void *pvidPtrInformacion,
			    void (*SiscomCreaNodoLista)(void *,StcListaGeneral **),
			    StcListaGeneral **pLLGenPrim,
			    StcListaGeneral **pLLGenActual)
{
StcListaGeneral *lSLGeneral=0;

		SiscomCreaNodoLista(pvidPtrInformacion,
				    &lSLGeneral);
		if(!*pLLGenPrim)
		 *pLLGenPrim=*pLLGenActual=lSLGeneral;
		 else
		 {
		   (*pLLGenActual)->LGenSig=lSLGeneral;
		   (*pLLGenActual)=(*pLLGenActual)->LGenSig;
		 }

}
		

void SiscomNormalizaNombre(unsigned char *pchrPtrCambia,
		     LCamposSiscomPro2 *pLCSiscomPro2,
		     LCamposSiscomPro2 **pLCSiscomPro2Normalizados)
{
unsigned char *lchrPtrNombre;
unsigned char *lchrPtrAPaterno;
unsigned char *lchrPtrAMaterno;
LCamposSiscomPro2 *lLCSiscomPro2Actual=0;
int lintNumRegistros=0;
	  *pLCSiscomPro2Normalizados=0;
	  for(;
	  	pLCSiscomPro2;
		pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	  {
	  SiscomNormaliza2(
	  	SiscomObtenDato(pLCSiscomPro2,"Nombre"),
		pchrPtrCambia,
		&lchrPtrNombre);
	  SiscomNormaliza2(
	  	SiscomObtenDato(pLCSiscomPro2,"APaterno"),
		pchrPtrCambia,
		&lchrPtrAPaterno);
	  SiscomNormaliza2(
	  	SiscomObtenDato(pLCSiscomPro2,"AMaterno"),
		pchrPtrCambia,
		&lchrPtrAMaterno);
	   SiscomAnexaRegistroPro2(pLCSiscomPro2Normalizados,
	   			   &lLCSiscomPro2Actual,
				   &lintNumRegistros,
				   "Nombre,		\
				    APaterno,		\
				    AMaterno,		\
				    IdPersona",
				    lchrPtrNombre,
				    lchrPtrAPaterno,
				    lchrPtrAMaterno,
				    SiscomObtenDato(pLCSiscomPro2,"IdPersona"));
	  }

}



void SiscomNormalizaEmpresaPrincipalSR2(unsigned char *pchrPtrCambia,
					LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
					LCamposSiscomPro2 *pLCSiscomPro2Salida)
{
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;
unsigned char *lchrPtrRSocial;
LCamposSiscomPro2 *lLCSiscomPro2Actual=0;
int lintNumRegistros=0;
for(lLCSiscomPro2SRDat=pLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
SiscomNormaliza2(
	SiscomObtenDatoDelRegistro(
		SiscomCamposRegistroPrincipal(pLCSiscomPro2SRDat),
			"RazonSocial",
			0),
	  pchrPtrCambia,
	  &lchrPtrRSocial);
SiscomAnexaRegistroPro2(&pLCSiscomPro2Salida,
			&lLCSiscomPro2Actual,
			&lintNumRegistros,
			"IdEmpresa,RazonSocial",
			SiscomObtenDatoDelRegistro(
			    SiscomCamposRegistroPrincipal(pLCSiscomPro2SRDat),
			    "IdEmpresa",
			    0),
			lchrPtrRSocial);
}

}
			
void SiscomNormalizaEmpresa(unsigned char *pchrPtrCambia,
			    LCamposSiscomPro2 *pLCSiscomPro2Entrada,
			    LCamposSiscomPro2 **pLCSiscomPro2Salida)
{
unsigned char *lchrPtrRSocial;
LCamposSiscomPro2 *lLCSiscomPro2Actual=0;
int lintNumRegistros;


	*pLCSiscomPro2Salida=0;
for(;
     pLCSiscomPro2Entrada;
     pLCSiscomPro2Entrada=pLCSiscomPro2Entrada->SCP2PtrSig)
{
SiscomNormaliza2(
	 SiscomObtenDato(pLCSiscomPro2Entrada,"RazonSocial"),
	 pchrPtrCambia,
	 &lchrPtrRSocial);
SiscomAnexaRegistroPro2(pLCSiscomPro2Salida,
			&lLCSiscomPro2Actual,
			&lintNumRegistros,
			"IdEmpresa,RazonSocial",
			SiscomObtenDato(pLCSiscomPro2Entrada,"IdEmpresa"),
			lchrPtrRSocial);
}
}

void SiscomAgrupaRegistrosPorCampo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				   int pintNRegistros,
				   const char *pchrPtrNmbCampo,
				   int pintNRegistroFiltro,
				   int *pintPtrNRegistros,
				   LCamposSiscomPro2 **pLCSiscomPro2DatPrim)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
LCamposSiscomPro2 *lLCSiscomPro2Cont=0;
const char *lchrPtrDatoActual=0;
const char *lchrPtrSiguiente="";
const char *lchrPtrUltimo="";
int lintNDatos;
*pLCSiscomPro2DatPrim=0;
*pintPtrNRegistros=0;
for(lLCSiscomPro2Dat=pLCSiscomPro2Dat;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
  lchrPtrDatoActual=SiscomObtenDato(lLCSiscomPro2Dat,pchrPtrNmbCampo);
    lintNDatos=0;
if(strcmp(lchrPtrDatoActual,lchrPtrUltimo))
for(lLCSiscomPro2Cont=lLCSiscomPro2Dat;
    lLCSiscomPro2Cont; 
    lLCSiscomPro2Cont=lLCSiscomPro2Cont->SCP2PtrSig)
{
lchrPtrSiguiente=SiscomObtenDato(lLCSiscomPro2Cont,pchrPtrNmbCampo);
if(!strcmp(lchrPtrDatoActual,lchrPtrSiguiente) &&
    lintNDatos<pintNRegistroFiltro)
{
SiscomCreaListaCamposPro2(lLCSiscomPro2Dat->SCSiscomPro2,
			  pLCSiscomPro2DatPrim,
			  &lLCSiscomPro2Act);
lintNDatos++;
(*pintPtrNRegistros)++;
}
}
lchrPtrUltimo=lchrPtrDatoActual;
}
}

int SiscomComparaCampoPro2(const char *pchrPtrNmbCampo,
			LCamposSiscomPro2 *pLCSiscomPro2Dat,
			LCamposSiscomPro2 *pLCSiscomPro2Dat1)
{
const char *lchrPtrDato=SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrNmbCampo),
      *lchrPtrDato1=SiscomObtenDato(pLCSiscomPro2Dat1,pchrPtrNmbCampo); 
return strcmp(lchrPtrDato,lchrPtrDato1);

}
void SiscomOrdenaPorCampo(const char *pchrPtrNmbCampo,
			  LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  int pintNRegistros,
			  LCamposSiscomPro2 **pLCSiscomPro2Ord)
{
LCamposSiscomPro2 **lLCSiscomPro2Matriz;
LCamposSiscomPro2 *lLCSiscomPro2Temp;
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
int lintContador;
int lintContadorI;
lLCSiscomPro2Matriz=(LCamposSiscomPro2 **)malloc(
					   sizeof(LCamposSiscomPro2 *)*
					   (pintNRegistros+1));
for(lintContador=0;
    pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig,
    lintContador++)
 lLCSiscomPro2Matriz[lintContador]=pLCSiscomPro2Dat;
 
 for(lintContador=0;
     lintContador<pintNRegistros;
     lintContador++)
 {
  
  for(lintContadorI=0;
      lintContadorI<pintNRegistros-1;
      lintContadorI++)
  {
     if(SiscomComparaCampoPro2(pchrPtrNmbCampo,
     			   lLCSiscomPro2Matriz[lintContador],
			   lLCSiscomPro2Matriz[lintContadorI])<0)
     {
	lLCSiscomPro2Temp=lLCSiscomPro2Matriz[lintContador];
	lLCSiscomPro2Matriz[lintContador]=lLCSiscomPro2Matriz[lintContadorI];
	lLCSiscomPro2Matriz[lintContadorI]=lLCSiscomPro2Temp;
     }
  }

 }
for(lintContador=0;
    lintContador<pintNRegistros;
    lintContador++)
{
SiscomCreaListaCamposPro2(lLCSiscomPro2Matriz[lintContador]->SCSiscomPro2,
			 pLCSiscomPro2Ord,
			 &lLCSiscomPro2Act);
free(lLCSiscomPro2Matriz[lintContador]);
}
}


void SiscomEliminaEspaciosInicio(char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena;
      while(*lchrPtrPaso==' ')
      lchrPtrPaso++;
strcpy(pchrPtrCadena,lchrPtrPaso);
}

void SiscomEliminaEspaciosFinal(char *pchrPtrCadena)
{

char *lchrPtrPaso=pchrPtrCadena+strlen(pchrPtrCadena)-1;
		while(*lchrPtrPaso==' ')
		 lchrPtrPaso--;
    *(lchrPtrPaso+1)=0;

}


void SiscomObten2CadenasPorSeparador(const char *pchrPtrCadena,
				     char pchrSeparador,
				     char *pchrPtrCadena1,
				     char *pchrPtrCadena2)
{
     while(*pchrPtrCadena!=pchrSeparador)
     {
 	*pchrPtrCadena1=*pchrPtrCadena;	
	pchrPtrCadena++;
	pchrPtrCadena1++;
     }
    *pchrPtrCadena1=0;
    pchrPtrCadena++;
    strcpy(pchrPtrCadena2,pchrPtrCadena);
}
/*
 * Puede ser buena idea cuando sepamos el numero de separadores 
 * que contiene una cadena
void SiscomObtenCadenasPorSeparador(const char *pchrPtrCadena,
				    char pchrSeparador,
				    const char *pchrPtrCadenaFormato,
				    ...)
{
va_list lzArgumentos;

va_start(lzArgumentos,pzCadenaFormato);

}
*/

void SiscomEnteroACadena(int pintDato,char *pchrPtrSalida)
{
 sprintf(pchrPtrSalida,"%d",pintDato);
}
void SiscomFloatACadena(float pfltDato,
			const char *pchrPtrFormato,
			char *pchrPtrSalida)
{
	if(pchrPtrFormato)
	sprintf(pchrPtrSalida,pchrPtrFormato,pfltDato);
	else
	sprintf(pchrPtrSalida,"%f",pfltDato);
}
