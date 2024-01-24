/*! \file SiscomProtocolo2.c
 *  \brief SISCOM Electronica.
 *  	   Archivo desarrolloado por Heli Garduno Esquivel 2007
 *
 *  	   Archivo que contiene las funciones que se utilizan para
 *  	   manipular el protocolo de comunicaciones SISCOM2 
 */


#include <SiscomDesarrollo2.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <arpa/inet.h>


void SiscomCopiaDatosProtocoloCharChar(LCamposSiscomPro2 *pLCSiscomPro2,
				       int pintNRegistros,
				       const char *pchrPtrNmbCampo,
				       char ***pchrPtrRegreso)
{
int lintContador;

	*pchrPtrRegreso=(char **)malloc(sizeof(char *)*(pintNRegistros+1));
/*
SiscomLog("Registros=%d Tamano=%d Char *(%d)",
	 pintNRegistros,
	 (sizeof(char *)*(pintNRegistros+1)),
	 sizeof(char *));
*/
	for(lintContador=0;
		pLCSiscomPro2;
	    pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig,
	    lintContador++)
	 (*pchrPtrRegreso)[lintContador]=strdup(SiscomObtenDato(pLCSiscomPro2,pchrPtrNmbCampo));

	(*pchrPtrRegreso)[pintNRegistros]=0;
}
void SiscomInformacionServidor(int pintPtoCom,
			       const char *pchrPtrDirIpSvr,
			       const char *pchrPtrOperacion,
			       int pintNRegistros,
			       LCamposSiscomPro2 *pLCSiscomPro2,
			       char **pchrPtrEdoConexion,
			       int *pintPtrSocket)
{
	
	if((*pintPtrSocket=SiscomConectateServidor(pintPtoCom,
						   pchrPtrDirIpSvr,
						   pchrPtrEdoConexion))<0)	
	  SiscomLog("Error:%s",*pchrPtrEdoConexion);
	else
	SiscomEnviaAlServidor(*pintPtrSocket,
				pintNRegistros,
				pchrPtrOperacion,
				pLCSiscomPro2);
}

/* Tepotzotlan Mexico a 24 de Agosto del 2017
 * Para eliminar del execeso de tiempo al actualizar 
 * un precio, se agrega la version NoBloqueante 
 */

void SiscomInformacionServidorNoBloqueante(int pintPtoCom,
			       const char *pchrPtrDirIpSvr,
			       const char *pchrPtrOperacion,
			       int pintNRegistros,
			       LCamposSiscomPro2 *pLCSiscomPro2,
			       int pintNTiempo,
			       char **pchrPtrEdoConexion,
			       int *pintPtrSocket)
{
	
	if((*pintPtrSocket=SiscomConectateClienteNoBloqueante(pchrPtrDirIpSvr,
						   pintPtoCom,
						   pintNTiempo,
						   pchrPtrEdoConexion))<0)	
	{

	}
	else
	SiscomEnviaAlServidor(*pintPtrSocket,
				pintNRegistros,
				pchrPtrOperacion,
				pLCSiscomPro2);
}


void SiscomInformacionServidorConRespuesta(
			int pintPtoCom,
			const char *pchrPtrDirIpSvr,
			const char *pchrPtrOperacion,
			int pintNRegistros,
			LCamposSiscomPro2 *pLCSiscomPro2,
			char **pchrPtrEdoConexion,
			int *pintPtrSocket,
			LCamposSiscomPro2 **pLCSiscomPro2Reg,
			int *pintPtrNRespuesta)
{

	SiscomInformacionServidor(pintPtoCom,
			  pchrPtrDirIpSvr,
			  pchrPtrOperacion,
			  pintNRegistros,
			  pLCSiscomPro2,
			  pchrPtrEdoConexion,
			  pintPtrSocket);
	if(!*pchrPtrEdoConexion)
	SiscomLeeInformacionRespuesta(*pintPtrSocket,
				       pintPtrNRespuesta,
				       pLCSiscomPro2Reg);
}
const char *SiscomObtenNombreCampo(LCamposSiscomPro2 *pLCSiscomPro2)
{

	return pLCSiscomPro2->SCSiscomPro2->chrPtrNmbCampo;

}
/*
 * Lunes 22 De Agosto 2011 
 * En las rutinas de normalizacion se identifico que los
 * nombres de los campos al tomarse de la base de datos 
 * se regresan en minusculas, lo que genero no reconocer
 * los nombres de los campos, por tal motivo se escribio
 * la funcion para cambiar a mayusculas los nombres de 
 * los campos que se estan comparando y asi poder continuar 
 * con las rutinas de normalizacion
 *
 */
int SiscomComparaNombreCampo(const char *pchrPtrNmbCampo,
			     const char *pchrPtrNmbCampo1)
{
char lchrArrNmbCampo[128];
char lchrArrNmbCampo1[128];
strcpy(lchrArrNmbCampo,pchrPtrNmbCampo);
strcpy(lchrArrNmbCampo1,pchrPtrNmbCampo1);
SiscomCambiaMayusculas(lchrArrNmbCampo);
SiscomCambiaMayusculas(lchrArrNmbCampo1);
return strcmp(lchrArrNmbCampo,lchrArrNmbCampo1);

}
const char *SiscomObtenDato(LCamposSiscomPro2 *pLCSiscomPro2,
			    const char *pchrPtrNmbCampo)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2;
	if(pLCSiscomPro2 &&
	   pLCSiscomPro2->SCSiscomPro2)
	{
	lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
	for(lintContador=0;
	    lintContador<lSCSiscomPro2->intNumCampos;
	    lintContador++)
	/*
	 if(!strcmp(pchrPtrNmbCampo,
	            (lSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	 */
	  if(!SiscomComparaNombreCampo(pchrPtrNmbCampo,
	  			     (lSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	  return (lSCSiscomPro2+lintContador)->chrPtrDato;
	  /*
	SiscomLog("SiscomObtenDato:No Se Encontro El Campo:%s",
			  pchrPtrNmbCampo);

	 */
	return "No Se Encontro El Campo";
	}
	else
	{
	SiscomLog("SiscomObtenDato:(Campo %s) Lista Nula",
			  pchrPtrNmbCampo);
	/*return "Error General";	 */
	return "";	
	}
}
/* Lunes 17 de Septiembre del 2012 
 * Se agregan las funciones para regresar un campo en Float o Int
 */
float SiscomObtenDatoFloat(LCamposSiscomPro2 *pLCSiscomPro2,
			   const char *pchrPtrNmbCampo)
{
return atof(SiscomObtenDato(pLCSiscomPro2,pchrPtrNmbCampo));
}
int SiscomObtenDatoInt(LCamposSiscomPro2 *pLCSiscomPro2,const char *pchrPtrNmbCampo)
{
return atoi(SiscomObtenDato(pLCSiscomPro2,pchrPtrNmbCampo));
}
void SiscomImprimeContenidoProtocolo2(const char *pchrPtrNmbFuncion,
				    LCamposSiscomPro2 *pLCSiscomPro2)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
char lchrArrFecha[30];
if(pLCSiscomPro2)
{
lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;

	SiscomFechaLocal(lchrArrFecha);
	fprintf(gPtrFleArchivoLog,"%s: (%s) ", lchrArrFecha,pchrPtrNmbFuncion);
	for(lintContador=0;
	    lintContador<lSCSiscomPro2->intNumCampos;
	    lintContador++)
	  fprintf(gPtrFleArchivoLog,
		  "%s|",
		  (lSCSiscomPro2+lintContador)->chrPtrNmbCampo);
	 fprintf(gPtrFleArchivoLog,"\n");
	for(;
	      pLCSiscomPro2;
	      pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
	     lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
	     fprintf(gPtrFleArchivoLog,"%s: (%s) ", lchrArrFecha,pchrPtrNmbFuncion);
	     for(lintContador=0;
		 lintContador<lSCSiscomPro2->intNumCampos;
		 lintContador++)
	       fprintf(gPtrFleArchivoLog,
		       "%s|",
		      (lSCSiscomPro2+lintContador)->chrPtrDato);
		fprintf(gPtrFleArchivoLog,"\n");
	}
}
}


void SiscomImprimeContenidoProtocoloVertical(const char *pchrPtrArchivo,
				       const char *pchrPtrFuncion,
				       int pintNoLinea,
				    LCamposSiscomPro2 *pLCSiscomPro2)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2;

if(pLCSiscomPro2)
{
lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
char lchrArrFecha[30];
if(pLCSiscomPro2)
{

	SiscomFechaLocal(lchrArrFecha);
	fprintf(gPtrFleArchivoLog,
	        "%s: (%s %s %d ) ",
		lchrArrFecha,
		pchrPtrArchivo,
		pchrPtrFuncion,
		pintNoLinea);

	 fprintf(gPtrFleArchivoLog,"\n");
	for(;
	      pLCSiscomPro2;
	      pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
		lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
		for(lintContador=0;
	    	    lintContador<lSCSiscomPro2->intNumCampos;
	    	    lintContador++)
	  	 fprintf(gPtrFleArchivoLog,
		  	 "(%s: (%s %s %d) %d %s %s\n",
			 lchrArrFecha,
			 pchrPtrArchivo,
			 pchrPtrFuncion,
			 pintNoLinea,
			 lintContador,
		  	(lSCSiscomPro2+lintContador)->chrPtrNmbCampo,
		  	(lSCSiscomPro2+lintContador)->chrPtrDato);
	}
}
}

}


void SiscomImprimeContenidoProtocolo2A(const char *pchrPtrArchivo,
				       const char *pchrPtrFuncion,
				       int pintNoLinea,
				    LCamposSiscomPro2 *pLCSiscomPro2)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2;

if(pLCSiscomPro2)
{
lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
char lchrArrFecha[30];
if(pLCSiscomPro2)
{
lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;

	SiscomFechaLocal(lchrArrFecha);
	fprintf(gPtrFleArchivoLog,
	        "%s: (%s %s %d ) ",
		lchrArrFecha,
		pchrPtrArchivo,
		pchrPtrFuncion,
		pintNoLinea);
	for(lintContador=0;
	    lintContador<lSCSiscomPro2->intNumCampos;
	    lintContador++)
	  fprintf(gPtrFleArchivoLog,
		  "%s|",
		  (lSCSiscomPro2+lintContador)->chrPtrNmbCampo);
	 fprintf(gPtrFleArchivoLog,"\n");
	for(;
	      pLCSiscomPro2;
	      pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
	     lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;

	fprintf(gPtrFleArchivoLog,
	        "%s: (%s %s %d ) ",
		lchrArrFecha,
		pchrPtrArchivo,
		pchrPtrFuncion,
		pintNoLinea);
	     for(lintContador=0;
		 lintContador<lSCSiscomPro2->intNumCampos;
		 lintContador++)
	       fprintf(gPtrFleArchivoLog,
		       "%s|",
		      (lSCSiscomPro2+lintContador)->chrPtrDato);
		fprintf(gPtrFleArchivoLog,"\n");
	}
}
}

}
/*
void SiscomImprimeContenidoProtocoloRegistroPorRegistro(
				   const char *pchrPtrNmbFuncion,
				    LCamposSiscomPro2 *pLCSiscomPro2)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
char lchrArrFecha[30];
if(pLCSiscomPro2)
{
lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;

	SiscomFechaLocal(lchrArrFecha);
	fprintf(gPtrFleArchivoLog,"%s:", lchrArrFecha);
	for(lintContador=0;
	    lintContador<lSCSiscomPro2->intNumCampos;
	    lintContador++)
	  fprintf(gPtrFleArchivoLog,
		  "%s|",
		  (lSCSiscomPro2+lintContador)->chrPtrNmbCampo);
	 fprintf(gPtrFleArchivoLog,"\n");
	for(;
	      pLCSiscomPro2;
	      pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
	     lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
	     fprintf(gPtrFleArchivoLog,"%s:", lchrArrFecha);
	     for(lintContador=0;
		 lintContador<lSCSiscomPro2->intNumCampos;
		 lintContador++)
	       fprintf(gPtrFleArchivoLog,
		       "%s|",
		      (lSCSiscomPro2+lintContador)->chrPtrDato);
		fprintf(gPtrFleArchivoLog,"\n");
	}
}
}
*/
void SiscomImprimeContenidoProtocolo(const char *pchrPtrNmbFuncion,
				    FILE *pPtrFleArchivo,
				    LCamposSiscomPro2 *pLCSiscomPro2)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
char lchrArrFecha[30];
if(pLCSiscomPro2)
{
lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
	SiscomFechaLocal(lchrArrFecha);
	fprintf(pPtrFleArchivo,"%s:", lchrArrFecha);
	for(lintContador=0;
	    lintContador<lSCSiscomPro2->intNumCampos;
	    lintContador++)
	  fprintf(pPtrFleArchivo,
		  "%s|",
		  (lSCSiscomPro2+lintContador)->chrPtrNmbCampo);
	 fprintf(pPtrFleArchivo,"\n");
	for(;
	      pLCSiscomPro2;
	      pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
	     lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
	     fprintf(pPtrFleArchivo,"%s:", lchrArrFecha);
	     for(lintContador=0;
		 lintContador<lSCSiscomPro2->intNumCampos;
		 lintContador++)
	       fprintf(pPtrFleArchivo,
		       "%s|",
		      (lSCSiscomPro2+lintContador)->chrPtrDato);
		fprintf(pPtrFleArchivo,"\n");
	}
}
}
/*
	Se debera de leer primero por fuera 
	la informacion de la operacion, es decir ,
	el proceso que resuelve la peticion, determina
	con base a la informacino de la operacion que
	funcion se llama, posteriormente la funcion 
	que resuelve la peticion, invoca a
	SiscomLeeInformacionProtocolo, para obtener 
	una lista con los registros que se leyeron
	asi, como el numero de campos y el numero
	de registros enviados

*/

	
void SiscomLeeInformacionProtocolo(int pintSocket,
				   int pintPtrNRegistros,
				   LCamposSiscomPro2 **pLCSiscomPro2)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
SCampoSiscomPro2 *lSCSiscomPro2Reg=0;
char *lchrPtrOperacion=0;
int lintContador;
int lintNRegistros;

for(lintContador=0;
    lintContador<pintPtrNRegistros;
    lintContador++)
{
	SiscomLeeRegistroProtocolo2(pintSocket,
				    &lSCSiscomPro2Reg);
	SiscomCreaListaCamposPro2(lSCSiscomPro2Reg,
				  pLCSiscomPro2,
				  &lLCSiscomPro2Act);
	if(lchrPtrOperacion)
	{
	free(lchrPtrOperacion);
	lchrPtrOperacion=0;
	}
	if(pintPtrNRegistros>1 &&
	   lintContador<pintPtrNRegistros-1)
	 SiscomLeeOperacion(pintSocket,
			    &lchrPtrOperacion);
	
}

}
void SiscomLeeInformacionProtocoloUltimoRegistro(int pintSocket,
				   int pintPtrNRegistros,
				   LCamposSiscomPro2 **pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Ultimo)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
SCampoSiscomPro2 *lSCSiscomPro2Reg=0;
char *lchrPtrOperacion=0;
int lintContador;
int lintNRegistros;

for(lintContador=0;
    lintContador<pintPtrNRegistros;
    lintContador++)
{
	SiscomLeeRegistroProtocolo2(pintSocket,
				    &lSCSiscomPro2Reg);
	SiscomCreaListaCamposPro2(lSCSiscomPro2Reg,
				  pLCSiscomPro2,
				  &lLCSiscomPro2Act);
	*pLCSiscomPro2Ultimo=lLCSiscomPro2Act;
	if(lchrPtrOperacion)
	{
	free(lchrPtrOperacion);
	lchrPtrOperacion=0;
	}
	if(pintPtrNRegistros>1 &&
	   lintContador<pintPtrNRegistros-1)
	 SiscomLeeOperacion(pintSocket,
			    &lchrPtrOperacion);
	
}

}
void SiscomLeeInformacionProtocolo2(int pintSocket,
				   int pintPtrNRegistros,
				   const char *pchrPtrCampoConfig,
				   LCamposSiscomPro2 **pLCSiscomPro2DatConfig,
				   LCamposSiscomPro2 **pLCSiscomPro2Dat)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
LCamposSiscomPro2 *lLCSiscomPro2ActConfig=0;
SCampoSiscomPro2 *lSCSiscomPro2Reg=0;
char *lchrPtrOperacion=0;
int lintContador;
int lintNRegistros;

for(lintContador=0;
    lintContador<pintPtrNRegistros;
    lintContador++)
{
	SiscomLeeRegistroProtocolo2(pintSocket,
				    &lSCSiscomPro2Reg);
	if(!strcmp(lSCSiscomPro2Reg->chrPtrNmbCampo,
		   pchrPtrCampoConfig))
	
	SiscomCreaListaCamposPro2(lSCSiscomPro2Reg,
				  pLCSiscomPro2DatConfig,
				  &lLCSiscomPro2ActConfig);
	else
	SiscomCreaListaCamposPro2(lSCSiscomPro2Reg,
				  pLCSiscomPro2Dat,
				  &lLCSiscomPro2Act);
	if(lchrPtrOperacion)
	{
	free(lchrPtrOperacion);
	lchrPtrOperacion=0;
	}
	if(pintPtrNRegistros>1 &&
	   lintContador<pintPtrNRegistros-1)
	 SiscomLeeOperacion(pintSocket,
			    &lchrPtrOperacion);
	
}

}
void EliminaCaracteresNoValidosCampos(char **pchrPtrCampos)
{
int lintContador;

for(lintContador=0;
	     pchrPtrCampos[lintContador];
	     lintContador++)
	 {
	   SiscomEliminaCaracter('\t',pchrPtrCampos[lintContador]); 
	   SiscomEliminaCaracter(' ',pchrPtrCampos[lintContador]); 
	 }
}
void SiscomAsignaDatosCampoAlCampo(char **pchrPtrNmbCampos,
			     SCampoSiscomPro2 *pSCSiscomPro2)
{
int lintContador;
char lchrArrNoCampo[5];
	for(lintContador=0;
	    pchrPtrNmbCampos[lintContador];
	    lintContador++)
	{
	   sprintf(lchrArrNoCampo,"%d",lintContador); 
	   (pSCSiscomPro2+lintContador)->chrPtrNmbCampo=pchrPtrNmbCampos[lintContador];
	   (pSCSiscomPro2+lintContador)->chrPtrNoCampo=(char *)strdup(lchrArrNoCampo);
	}
	pSCSiscomPro2->intNumCampos=lintContador;
}
void SiscomAnexaRegistroPro2(LCamposSiscomPro2 **pLCSiscomPro2Prim,
			     LCamposSiscomPro2 **pLCSiscomPro2Act,
			     int *pintPtrNRegistros,
			     const char *pchrPtrFormato,
			     ...)
{
va_list lVLArg;
char **lchrPtrNmbCampos;
char *lchrPtrBuffer=(char *)malloc(strlen(pchrPtrFormato)+1);
SCampoSiscomPro2 *lSCSiscomPro2;
int lintContador,
    lintNCampos;
(*pintPtrNRegistros)++;
	if((lintNCampos=SiscomAnalizaCadenas(pchrPtrFormato,
				',',
				lchrPtrBuffer,
				&lchrPtrNmbCampos)))
	{
	 EliminaCaracteresNoValidosCampos(lchrPtrNmbCampos);	 
	 lSCSiscomPro2=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2)*(lintNCampos+1)); 
	 lSCSiscomPro2->intNumCampos=lintNCampos;
	 SiscomAsignaDatosCampoAlCampo(lchrPtrNmbCampos,lSCSiscomPro2);
	 va_start(lVLArg,pchrPtrFormato);
	 for(lintContador=0;
	     lintContador<lintNCampos;
	     lintContador++)
	 {
	  SiscomAsignaDatoCampo(lchrPtrNmbCampos[lintContador],
				lintNCampos,
          			va_arg(lVLArg,char *),
				lSCSiscomPro2); 
	  }
	 SiscomCreaListaCamposPro2(lSCSiscomPro2,
				   pLCSiscomPro2Prim,
				   pLCSiscomPro2Act);
	 va_end(lVLArg);
	}
}

/* Miercoles 25 de Septiembre del 2013
 * %s [EstadoSincronizacion] %s [Mensaje] ",
 * se debera pasar en la variable pchrPtrFormato
 * un % por cada campo del registro despues entre [] el nombre 
 * del campo que se enviara, el valor del campo se tomara del %s
 *
 */
void SiscomEnviaRegistroConFormato(int pintSocket,
				   SCampoSiscomPro2 *pSCSiscomPro2Buffer,
				   char *pchrPtrFormato,
				   ...)
{
LCamposSiscomPro2 *lLCSiscomPro2PrimRegEnvio=0,
		  *lLCSiscomPro2ActRegEnvio=0;
int lintNRegEnvio=0;
va_list lVLArg;
va_start(lVLArg,pchrPtrFormato);
	while(*pchrPtrFormato)
	{
	    
	    if(*pchrPtrFormato=='%')
		pchrPtrFormato=AgregandoCampoAlRegistroPorEnviar(
				pchrPtrFormato,
			 	va_arg(lVLArg,char *),
				pSCSiscomPro2Buffer);
	  else
	  pchrPtrFormato++;
	}
va_end(lVLArg);
SiscomCreaListaCamposPro2(pSCSiscomPro2Buffer,
			  &lLCSiscomPro2PrimRegEnvio,
			  &lLCSiscomPro2ActRegEnvio);
SiscomEnviaAlServidor(pintSocket,
		      1,
		      "Respuesta",
		      lLCSiscomPro2PrimRegEnvio);
SiscomContenidoProtocolo(lLCSiscomPro2PrimRegEnvio);
}
char *AgregandoCampoAlRegistroPorEnviar(
			char *pchrPtrFormato,
			const char *pchrPtrCampo,
			SCampoSiscomPro2 *pSCSiscomPro2)
{
char lchrArrCadenaESeparadores[256];
char lchrArrNumCampo[5];
int lintContador=pSCSiscomPro2->intNumCampos;
   pchrPtrFormato=(char *)SiscomCadenaEntreSeparadores(
   				pchrPtrFormato,
				'[',
				']',
				lchrArrCadenaESeparadores);
    sprintf(lchrArrNumCampo,"%d",pSCSiscomPro2->intNumCampos);
    (pSCSiscomPro2+lintContador)->chrPtrNmbCampo=strdup(lchrArrCadenaESeparadores);
    (pSCSiscomPro2+lintContador)->chrPtrNoCampo=strdup(lchrArrNumCampo);
    (pSCSiscomPro2+lintContador)->chrPtrDato=strdup(pchrPtrCampo);
    pSCSiscomPro2->intNumCampos++;
return pchrPtrFormato;
}
/*
*/
#define __UNOPORUNO__ 
void SiscomLeeInformacion1(int pintSocket,
			   int pintNCaracteres,
			   char *pchrPtrRegreso)
{

#ifdef __UNOPORUNO__
int lintContador;
	for(lintContador=0;
	    lintContador<pintNCaracteres;
	    lintContador++)
	 read(pintSocket,
		  pchrPtrRegreso+lintContador,
		  1);
 pchrPtrRegreso[lintContador]=0;
#else
 read(pintSocket,pchrPtrRegreso,pintNCaracteres);
 pchrPtrRegreso[pintNCaracteres]=0;
#endif


}
void SiscomLeeInformacion(int pintSocket,
			  int pintNCaracteres,
			  char **pchrPtrRegreso)
{
int lintContador;
	*pchrPtrRegreso=(char *)malloc(pintNCaracteres+1);
#ifdef __UNOPORUNO__

	for(lintContador=0;
	    lintContador<pintNCaracteres;
	    lintContador++)
	 read(pintSocket,
		  (*pchrPtrRegreso)+lintContador,
		  1);

   (*pchrPtrRegreso)[lintContador]=0;
#else
	read(pintSocket,*pchrPtrRegreso,pintNCaracteres);
        (*pchrPtrRegreso)[pintNCaracteres]=0;
#endif
}
void LeeYAsignaInformacion(int pintSocket,
			   int pintTamano,
			   char **pchrPtrRegreso)
{
int lintNLectura;

/*
   SiscomLog(
   		     "LeeYAsignaInformacion:Se Deben leer %d bytes",
		     pintTamano);
*/
/*
   	   *pchrPtrRegreso=(char *)malloc(pintTamano+8);
	if((lintNLectura=read(pintSocket,
	     *pchrPtrRegreso,
	      pintTamano))!=pintTamano)
	    SiscomLog(
	    		      "LeeYAsignaInformacion:Error en el protocolo Leyendo %d !+ Tamano %d {%s}",
			       lintNLectura,
			       pintTamano,
			       strerror(errno));
	(*pchrPtrRegreso)[pintTamano]=0;
*/
	/*
	SiscomLog(
			  "LeeYAsignaInformacion:Se Leyo {%s}",
			  *pchrPtrRegreso);

	*/
	SiscomLeeInformacion(pintSocket,pintTamano,pchrPtrRegreso);

}
void LeeYAsignaInformacionINT(int pintSocket,
			      int pintTamano,
			      int *pintPtrRegreso)
{
char *lchrPtrTamano;
	LeeYAsignaInformacion(pintSocket,
			      pintTamano,
			      &lchrPtrTamano);
	*pintPtrRegreso=atoi(lchrPtrTamano);
	free(lchrPtrTamano);

}
int SiscomLeeNumeroRegistros(int pintSocket,
			     int *pintPtrNRegistros)
{
char lchrArrPaso[7];
int lintTamano;
	SiscomLeeInformacion1(pintSocket,6,lchrArrPaso);
	*pintPtrNRegistros=atoi(lchrArrPaso);
}
int SiscomLeeOperacion(int pintSocket,
		  char **pchrPtrOperacion)
{
int lintTamano;
char lchrArrPaso[5];
	SiscomLeeInformacion1(pintSocket,4,lchrArrPaso);
	 lintTamano=atoi(lchrArrPaso);
	LeeYAsignaInformacion(pintSocket,
			      lintTamano,
			      pchrPtrOperacion);

	return 1;
}
void LeeCampoProtocolo2(int pintSocket,
			SCampoSiscomPro2 *pSCSiscomPro2)
{
int lintTamano;
char lchrArrPaso[5];

	SiscomLeeInformacion1(pintSocket,4,lchrArrPaso);
	lintTamano=atoi(lchrArrPaso);
	LeeYAsignaInformacion(pintSocket,
			      lintTamano,
			      &pSCSiscomPro2->chrPtrNmbCampo);
	SiscomLeeInformacion1(pintSocket,4,lchrArrPaso);
	lintTamano=atoi(lchrArrPaso);

	LeeYAsignaInformacion(pintSocket,
			      4,
			      &pSCSiscomPro2->chrPtrNoCampo);
	SiscomLeeInformacion1(pintSocket,4,lchrArrPaso);
	lintTamano=atoi(lchrArrPaso);
	LeeYAsignaInformacion(pintSocket,
			      lintTamano,
			      &pSCSiscomPro2->chrPtrDato);
}
void SiscomLeeRegistroProtocolo2(int pintSocket,
			SCampoSiscomPro2 **pSCSiscomPro2)

{
char lchrArrNumCampos[5];
int lintContador;
int lintRegreso;
int lintNCampos;
int lintNDatos;
	SiscomLeeInformacion1(pintSocket,4,lchrArrNumCampos);
	lintNCampos=atoi(lchrArrNumCampos);
	*pSCSiscomPro2=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2)*(lintNCampos+1));
	(*pSCSiscomPro2)->intNumCampos=lintNCampos;
	for(lintContador=0;
	    lintContador<(*pSCSiscomPro2)->intNumCampos;
	    lintContador++)
	 LeeCampoProtocolo2(pintSocket,
			    &(*pSCSiscomPro2)[lintContador]);	
}

void SiscomCreaNodoLCamposPro2(SCampoSiscomPro2 *pSCSiscomPro2,
			       LCamposSiscomPro2 **pLCSiscomPro2)
{

	*pLCSiscomPro2=(LCamposSiscomPro2 *)malloc(sizeof(LCamposSiscomPro2 ));
	(*pLCSiscomPro2)->SCSiscomPro2=pSCSiscomPro2;
	(*pLCSiscomPro2)->SCP2PtrSig=0;
	(*pLCSiscomPro2)->SCP2PtrAnt=0;
}
void SiscomCreaListaCamposPro2(SCampoSiscomPro2 *pSCSiscomPro2,
			       LCamposSiscomPro2 **pLCSiscomPro2Prim,
			       LCamposSiscomPro2 **pLCSiscomPro2Actual)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;

	SiscomCreaNodoLCamposPro2(pSCSiscomPro2,
				  &lLCSiscomPro2Dat);
	if(!*pLCSiscomPro2Prim)
	 *pLCSiscomPro2Prim=*pLCSiscomPro2Actual=lLCSiscomPro2Dat;
	else
	{
	(*pLCSiscomPro2Actual)->SCP2PtrSig=lLCSiscomPro2Dat;
	(*pLCSiscomPro2Actual)=(*pLCSiscomPro2Actual)->SCP2PtrSig;
	}
}
void SiscomFree(const char *pchrPtrDato)
{
  free((void *)pchrPtrDato);
  pchrPtrDato=0;
}
void SiscomLiberaCampo(SCampoSiscomPro2 *pSCSiscomPro2)
{
int lintContador;
for(lintContador=0;
    lintContador<pSCSiscomPro2->intNumCampos;
    lintContador++)
{
/*
	SiscomFree((pSCSiscomPro2+lintContador)->chrPtrNmbCampo);
	SiscomFree((pSCSiscomPro2+lintContador)->chrPtrNoCampo); 
	SiscomFree((pSCSiscomPro2+lintContador)->chrPtrDato);   
*/

}
}
void SiscomLiberaListaCamposPro2(LCamposSiscomPro2 *pLCSiscomPro2)
{
LCamposSiscomPro2 *lLCSiscomPro2Sig;
int lintContador=0;
while(pLCSiscomPro2)
{
 lLCSiscomPro2Sig=pLCSiscomPro2->SCP2PtrSig;
 SiscomLiberaCampo(pLCSiscomPro2->SCSiscomPro2); 
 /* free(pLCSiscomPro2); */
 pLCSiscomPro2=lLCSiscomPro2Sig; 

 lintContador++;

} 
}
void AnexaDatoCampo(const char *pchrPtrDato,
		    char **pchrPtrSalida)
{
       if(!pchrPtrDato)
        pchrPtrDato="";
        
	*pchrPtrSalida=(char *)malloc(strlen(pchrPtrDato)+5);
	sprintf(*pchrPtrSalida,
		"%04d%s",
		(int )strlen(pchrPtrDato),
		pchrPtrDato);	

}
void SiscomAnexaCampoProtocolo2(const char *pchrPtrNmbCampo,
				int *pintPtrNoCampo,
				const char *pchrPtrCampo,
				char **pchrPtrCadena)
{
char lchrArrNoCampo[12];
char *lchrPtrNmbCampo,
     *lchrPtrNoCampo,
     *lchrPtrCampo;
int lintTamano,
	lintTamanoIni=0,
	lintNmbCampo,
	lintNoCampo,
	lintCampo;
	lintTamanoIni=strlen(*pchrPtrCadena);
	sprintf(lchrArrNoCampo,"%04d",*pintPtrNoCampo);
	AnexaDatoCampo(pchrPtrNmbCampo,&lchrPtrNmbCampo);
	AnexaDatoCampo(lchrArrNoCampo,&lchrPtrNoCampo);
	AnexaDatoCampo(pchrPtrCampo,&lchrPtrCampo);

	lintTamano=4                                      +
		   (lintNmbCampo=strlen(lchrPtrNmbCampo)) +
		   (lintNoCampo=strlen(lchrPtrNoCampo))   +
		   (lintCampo=strlen(lchrPtrCampo));

	*pchrPtrCadena=(char *)realloc(*pchrPtrCadena,lintTamano+lintTamanoIni);
	sprintf(*pchrPtrCadena+lintTamanoIni,
		"%s%s%s",
		lchrPtrNmbCampo,
		lchrPtrNoCampo,
		lchrPtrCampo);
	(*pintPtrNoCampo)++;
}
void SiscomNumeroCamposAlProtocolo(int pintNoCampos,
				   char *pchrPtrCadenaEnvio)
{
int lintTamIni;
char lchrArrNoCampos[5],
	lchrArrTamOperacion[5];
	strncpy(lchrArrTamOperacion,pchrPtrCadenaEnvio,4);	
	lchrArrTamOperacion[4]=0;
	lintTamIni=atoi(lchrArrTamOperacion);
	sprintf(lchrArrNoCampos,
		"%04d",
		pintNoCampos);
	strncpy(pchrPtrCadenaEnvio+lintTamIni+4,
		lchrArrNoCampos,
		4);
}
void SiscomFormaRegistroIniEnvio(const char *pchrPtrOperacion,
				 char **pchrPtrCadena)
{
int lintTamano;
	*pchrPtrCadena=(char *)malloc((lintTamano=strlen(pchrPtrOperacion))+12);

	sprintf(*pchrPtrCadena,
		"%04d%s%04d",
		 lintTamano,
		 pchrPtrOperacion,
		 0);
}

void SiscomIniciaRegistro(SCampoSiscomPro2 *pSCSiscomPro2,
			  int *pintPtrNCampos,
			  const char *pchrPtrFormato,
			  ...)
{
va_list lVLArg;
int lintContador=0;
char *lchrPtrArgumento;
char lchrArrNumCampo[5];
	va_start(lVLArg,pchrPtrFormato);

	while(*pchrPtrFormato)
	{
	   if(*pchrPtrFormato=='%')
	   {
	   *pchrPtrFormato++;
	     switch(*pchrPtrFormato)
	     {
	     case 's':
			sprintf(lchrArrNumCampo,
				"%d",
				lintContador);
			lchrPtrArgumento=va_arg(lVLArg,char *);
		 	(pSCSiscomPro2+lintContador)->chrPtrNmbCampo=(char *)strdup(lchrPtrArgumento);	
			(pSCSiscomPro2+lintContador)->chrPtrNoCampo=(char *)strdup(lchrArrNumCampo);
			lintContador++;
	     break;
	     }
	   }
	   *pchrPtrFormato++;
	}
	 va_end(lVLArg);
	*pintPtrNCampos=lintContador;
}
void SiscomAsignaDatoCampo2A(const char *pchrPtrNmbCampo,
			    const char *pchrPtrDato,
			    SCampoSiscomPro2 *pSCSiscomPro2)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSCSiscomPro2->intNumCampos;
	    lintContador++)
	 /*
	if(!strcmp(pchrPtrNmbCampo,
		   (pSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	 */
	 if(!SiscomComparaNombreCampo(pchrPtrNmbCampo,(pSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	{
	 (pSCSiscomPro2+lintContador)->chrPtrDato=(char *)strdup(pchrPtrDato);
	 return ;
	}

    SiscomLog(
    		      "SiscomAsignaDatoCampo:El Campo {%s} No Existe En El Registro",
	    	       pchrPtrNmbCampo);
}
void SiscomAsignaDatoCampo2(const char *pchrPtrNmbCampo,
			    const char *pchrPtrDato,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2=pLCSiscomPro2Dat->SCSiscomPro2;
	for(lintContador=0;
	    lintContador<lSCSiscomPro2->intNumCampos;
	    lintContador++)
	/*
	if(!strcmp(pchrPtrNmbCampo,
		   (lSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	 */
	if(!SiscomComparaNombreCampo(pchrPtrNmbCampo,
				    (lSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	{
	 (lSCSiscomPro2+lintContador)->chrPtrDato=(char *)strdup(pchrPtrDato);
	 return ;
	}

    SiscomLog(
    		      "SiscomAsignaDatoCampo:El Campo {%s} No Existe En El Registro",
	    	       pchrPtrNmbCampo);
}
void SiscomAsignaDatoCampo(const char *pchrPtrNmbCampo,
			   int pintNCampos,
			   char *pchrPtrDato,
			   SCampoSiscomPro2 *pSCSiscomPro2)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pintNCampos;
	    lintContador++)
	if(!strcmp(pchrPtrNmbCampo,
		   (pSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	{
         if(pchrPtrDato)
	 (pSCSiscomPro2+lintContador)->chrPtrDato=(char *)strdup(pchrPtrDato);
	 return ;
	}

    SiscomLog(
    		      "SiscomAsignaDatoCampo:El Campo {%s} No Existe En El Registro",
	    	       pchrPtrNmbCampo);
}
void SiscomEnviaVersionProtocolo(int pintSocket)
{
char lchrArrVersionProtocolo[16];
SiscomFormaCadenaVersion(2,0,lchrArrVersionProtocolo);
write(pintSocket,lchrArrVersionProtocolo,15);
}
void SiscomFormaCadenaVersion(int pintVersion,
			      int pintSubVersion,
			      char *pchrPtrCadenaVersion)
{
sprintf(pchrPtrCadenaVersion,"%05d%05d%05d",pintVersion,pintSubVersion,0);
}
void SiscomEnviaAlServidor(int pintSocket,
			   int pintNRegistros,
			   const char *pchrPtrOperacion,
			   LCamposSiscomPro2 *pLCSiscomPro2)
{
char *lchrPtrProtocolo=0;
char lchrArrNumeroRegistros[20];
LCamposSiscomPro2 *lLCSiscomPro2=pLCSiscomPro2;
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2;
int lintNoCampo=0;
/*
 *  Numero de registros a 6 cifras
 */

/*
 * 6 Cifras
 *	sprintf(lchrArrNumeroRegistros,
 *		"%04d",
 *		pintNRegistros);
 */
	sprintf(lchrArrNumeroRegistros,
 		"%06d",
 		pintNRegistros);
	write(pintSocket,
	      lchrArrNumeroRegistros,
	      strlen(lchrArrNumeroRegistros));
	for(lLCSiscomPro2=pLCSiscomPro2;
	    lLCSiscomPro2;
	    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
	{
	SiscomFormaRegistroIniEnvio(pchrPtrOperacion,
				    &lchrPtrProtocolo);
	    lSCSiscomPro2=lLCSiscomPro2->SCSiscomPro2;
	    lintNoCampo=0;
	    for(lintContador=0;
		lintContador<lSCSiscomPro2->intNumCampos;
		lintContador++)
	     SiscomAnexaCampoProtocolo2(
			(lSCSiscomPro2+lintContador)->chrPtrNmbCampo,
			&lintNoCampo,
			(lSCSiscomPro2+lintContador)->chrPtrDato,
			&lchrPtrProtocolo);
	SiscomNumeroCamposAlProtocolo(lSCSiscomPro2->intNumCampos,
				     lchrPtrProtocolo);
	write(pintSocket,
	      lchrPtrProtocolo,
	      strlen(lchrPtrProtocolo));	
	free(lchrPtrProtocolo);
	lchrPtrProtocolo=0;
	}
}

int SiscomVeSiHayDatosParaEscribir(int pizSocket,
                              int piTimeOut)
{
fd_set lsFd_setReg;
struct timeval lsTimevalReg;
int liRegresoSelect=0;
FD_ZERO(&lsFd_setReg);
FD_SET((int )pizSocket,&lsFd_setReg);
                lsTimevalReg.tv_sec = piTimeOut;
                lsTimevalReg.tv_usec = 0;
                if((liRegresoSelect=select((int )pizSocket+1,0,&lsFd_setReg,0,&lsTimevalReg))<
0)
                {
                        exit(2);

                }
                else
                {
                   if(FD_ISSET(pizSocket,&lsFd_setReg))
                        liRegresoSelect=1;
                   else
                        liRegresoSelect=0;
                }
return liRegresoSelect;
}

int SiscomVeSiHayDatosParaLeer(int pintSocket,
			       int pintTimeOut)
{
fd_set lsFd_setReg;
struct timeval lsTimevalReg;
int liRegresoSelect=0;
FD_ZERO(&lsFd_setReg);
FD_SET((int )pintSocket,&lsFd_setReg);
                lsTimevalReg.tv_sec = pintTimeOut;
                lsTimevalReg.tv_usec = 0;
                if((liRegresoSelect=select((int )pintSocket+1,&lsFd_setReg,0,0,&lsTimevalReg))<
0)
                {
                        exit(2);

                }
                else
                {
                   if(FD_ISSET(pintSocket,&lsFd_setReg))
                        liRegresoSelect=1;
                   else
                        liRegresoSelect=0;
                }
return liRegresoSelect;

}

int SiscomConectateClienteNoBloqueante(const char *pchrPtrDirIpSvr,
  			   int pintPuerto,
			   int pintTiempo,
			   char **pchrPtrEdoConexion)
{
int lintSocket;
struct sockaddr_in lSocAddrInCon;
struct timeval lTimValTiempo;
long llngArgSocket,llngTamEntero;
int lintRegreso,lintValOpt;
fd_set lfdSetSocket;
*pchrPtrEdoConexion=0;
	if((lintSocket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
	}
	else
	{

	      llngArgSocket = fcntl(lintSocket, F_GETFL, NULL); 
	      llngArgSocket |= O_NONBLOCK; 
	      fcntl(lintSocket, F_SETFL, llngArgSocket); 

	  lSocAddrInCon.sin_family=AF_INET;
	  lSocAddrInCon.sin_port=htons(pintPuerto);
	  lSocAddrInCon.sin_addr.s_addr=inet_addr(pchrPtrDirIpSvr);
	  if((lintRegreso=connect(lintSocket,
		      (struct sockaddr *)&lSocAddrInCon,
		      sizeof(struct sockaddr_in)))<0)
	  {
	    if(errno==EINPROGRESS)
	    {
		lTimValTiempo.tv_sec=pintTiempo;
		lTimValTiempo.tv_usec=0;
		FD_ZERO(&lfdSetSocket);
		FD_SET(lintSocket,&lfdSetSocket);
		if(select(lintSocket+1,NULL,&lfdSetSocket,NULL,&lTimValTiempo))
		{
	 	   llngTamEntero=sizeof(int);
		   getsockopt(lintSocket,
		   	     SOL_SOCKET,
			     SO_ERROR,
			     (void *)&lintValOpt,
			     (socklen_t *)&llngTamEntero);
		    if(lintValOpt==111)
		    {
		    *pchrPtrEdoConexion=strdup("NO Se pudo conectar al servidor");
		    return -1;
		    }
		}
		else
		{
		    SiscomLog("Timeout, se espero %d seg para la conexion %d %s",
		    		pintTiempo,
		    		errno,
				strerror(errno));
		   *pchrPtrEdoConexion=strerror(errno);
		    return -1;
		}
	    }
	    else
	    {
	 	SiscomLog("Error Conexion %d %s %d %d",
			 errno,
			 strerror(errno),
			 EINPROGRESS,
			 lintRegreso);
		   *pchrPtrEdoConexion=strerror(errno);
		return -1;
	    }
	    
	  }
	  else
	  {
	  	SiscomLog("NO SE Conecto");
	 	SiscomLog("NO Se pudo conectar a %s:%d",
			   pchrPtrDirIpSvr,
			   pintPuerto);
		   *pchrPtrEdoConexion=strerror(errno);
		   return -1;
	  }


	}
	llngArgSocket = fcntl(lintSocket, F_GETFL, NULL); 
	llngArgSocket &= (~O_NONBLOCK); 
	fcntl(lintSocket, F_SETFL, llngArgSocket); 
	return lintSocket;
}
int SiscomConectateServidor(int pintPtoCom,
			    const char *pchrPtrDirIpSvr,
			    char **pchrPtrEdoConexion)
{
int lintSocket,
    lintSocketCliente;
struct sockaddr_in lSocAddrInCon;
*pchrPtrEdoConexion=0;
	if((lintSocket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
	}
	else
	{
	  lSocAddrInCon.sin_family=AF_INET;
	  lSocAddrInCon.sin_port=htons(pintPtoCom);
	  lSocAddrInCon.sin_addr.s_addr=inet_addr(pchrPtrDirIpSvr);
	  if((lintSocketCliente=connect(lintSocket,
					(struct sockaddr *)&lSocAddrInCon,
					sizeof(struct sockaddr_in)))<0)
	  {
	     SiscomLog( "SiscomConetateServidor:%s",
		     strerror(errno));
	     *pchrPtrEdoConexion=(char *)strerror(errno); 
	     return -1;
	  }
	   else
	   return lintSocket;
	}

}
const char *SiscomObtenDatoDelRegistro(SCampoSiscomPro2 *pSCSiscomPro2,
				       const char *pchrPtrNmbCampo,
				       int pintNCampos)
{
int lintContador;

	for(lintContador=0;
	    lintContador<pSCSiscomPro2->intNumCampos;
	    lintContador++)
	if(!strcmp(pchrPtrNmbCampo,
		   (pSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	 return (pSCSiscomPro2+lintContador)->chrPtrDato;

    SiscomLog(
    			"SiscomAsignaDatoCampo:El Campo {%s} No Existe En El Registro",
	    		pchrPtrNmbCampo);

	return 0;	

}
void SiscomMuestraContenidoRegistro(const char *pchrPtrName,
				   FILE *pFlePtrArchivo,
				  SCampoSiscomPro2 *pSCSiscomPro2)

{
char lchrArrFechaActual[25];
int lintContador;
	SiscomFechaLocal(lchrArrFechaActual);
	fprintf(pFlePtrArchivo,
		"%s:{",
		lchrArrFechaActual);
	for(lintContador=0;
	    lintContador<pSCSiscomPro2->intNumCampos;
	    lintContador++)
	  if((lintContador+1)<pSCSiscomPro2->intNumCampos)
	  fprintf(pFlePtrArchivo,
	  	  "%s,",
		  (pSCSiscomPro2+lintContador)->chrPtrDato);
	   else
	  fprintf(pFlePtrArchivo,
	  	  "%s}\n",
		  (pSCSiscomPro2+lintContador)->chrPtrDato);


}
void SiscomImprimeContenidoRegistro(const char *pchrPtrName,
				   FILE *pFlePtrArchivo,
				  SCampoSiscomPro2 *pSCSiscomPro2)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSCSiscomPro2->intNumCampos;
	    lintContador++)
	SiscomMensajesLog(pFlePtrArchivo,
			  "%s={%s}",
			  (pSCSiscomPro2+lintContador)->chrPtrNmbCampo,
			  (pSCSiscomPro2+lintContador)->chrPtrDato); 



}

void SiscomCopiaCampos(SCampoSiscomPro2 *pSCSiscomPro2Ent,
		       SCampoSiscomPro2 **pSCSiscomPro2Sal)
{
int lintContador;

	*pSCSiscomPro2Sal=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2)*
						     pSCSiscomPro2Ent->intNumCampos);
    (*pSCSiscomPro2Sal)->intNumCampos=pSCSiscomPro2Ent->intNumCampos;
for(lintContador=0;
    lintContador<pSCSiscomPro2Ent->intNumCampos;
    lintContador++)
{
   ((*pSCSiscomPro2Sal)+lintContador)->chrPtrNmbCampo=strdup(
   				(pSCSiscomPro2Ent+lintContador)->chrPtrNmbCampo);
   ((*pSCSiscomPro2Sal)+lintContador)->chrPtrNoCampo=strdup(
   				 (pSCSiscomPro2Ent+lintContador)->chrPtrNoCampo);
   ((*pSCSiscomPro2Sal)+lintContador)->chrPtrDato="";
}
}
		
void SiscomSumaListaCampos(LCamposSiscomPro2 **pLCSiscomPro2Uno,
			   LCamposSiscomPro2 *pLCSiscomPro2Dos)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=*pLCSiscomPro2Uno;
LCamposSiscomPro2 *lLCSiscomPro2Ultimo;
if(!*pLCSiscomPro2Uno)
 *pLCSiscomPro2Uno=pLCSiscomPro2Dos;
else
{
for(;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
 lLCSiscomPro2Ultimo=lLCSiscomPro2Dat;

 lLCSiscomPro2Ultimo->SCP2PtrSig=pLCSiscomPro2Dos;
}
}

void SiscomSumaListas(LCamposSiscomPro2 *pLCSiscomPro2Uno,
		      LCamposSiscomPro2 *pLCSiscomPro2Dos)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pLCSiscomPro2Uno;
LCamposSiscomPro2 *lLCSiscomPro2Ultimo;

for(;
     lLCSiscomPro2Dat;
     lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
lLCSiscomPro2Ultimo=lLCSiscomPro2Dat; 
lLCSiscomPro2Ultimo->SCP2PtrSig=pLCSiscomPro2Dos;
}


int SiscomEstaElCampo(LCamposSiscomPro2 *pLCSiscomPro2,
		      const char *pchrPtrNmbCampo)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2;
	if(pLCSiscomPro2 &&
	   pLCSiscomPro2->SCSiscomPro2)
	{
	lSCSiscomPro2=pLCSiscomPro2->SCSiscomPro2;
	for(lintContador=0;
	    lintContador<lSCSiscomPro2->intNumCampos;
	    lintContador++)
	 if(!strcmp(pchrPtrNmbCampo,
	            (lSCSiscomPro2+lintContador)->chrPtrNmbCampo))
	  return (lSCSiscomPro2+lintContador)->chrPtrDato ? 1 :0;
	return 0;
	}
	else
	{
	return 0;	
	}

}

void SiscomRestaCamposAB_R(const char *pchrPtrCampoA,
		      const char *pchrPtrCampoB,
		      const char *pchrPtrCampoRes,
		      LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
float lfltCampoA=atof(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampoA));
float lfltCampoB=atof(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampoB));
char lchrArrResultado[12];
sprintf(lchrArrResultado,
	"%.2f",
	lfltCampoA-lfltCampoB);
SiscomAsignaDatoCampo2(pchrPtrCampoRes,lchrArrResultado,pLCSiscomPro2Dat);
}
void SiscomSumaCamposAB_R(const char *pchrPtrCampoA,
		      const char *pchrPtrCampoB,
		      const char *pchrPtrCampoRes,
		      LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
float lfltCampoA=atof(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampoA));
float lfltCampoB=atof(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampoB));
char lchrArrResultado[12];
sprintf(lchrArrResultado,
	"%.2f",
	lfltCampoA+lfltCampoB);
SiscomAsignaDatoCampo2(pchrPtrCampoRes,lchrArrResultado,pLCSiscomPro2Dat);
}
float SiscomObtenCampoAFloat(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     const char *pchrPtrNmbCampo)
{
  return atof(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrNmbCampo));
}
void SiscomAsignaDatoCampoFloat2(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 const char *pchrPtrCampo,
				 float pfltDato)
{
char lchrArrDato[12];
	sprintf(lchrArrDato,
		"%.2f",
		pfltDato);
	SiscomAsignaDatoCampo2(pchrPtrCampo,
			       lchrArrDato,
			       pLCSiscomPro2Dat);

}

void SiscomAsignaDatoCampoInt2(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 const char *pchrPtrCampo,
				 int pintDato)
{
char lchrArrDato[12];
	sprintf(lchrArrDato,
		"%d",
		pintDato);
	SiscomAsignaDatoCampo2(pchrPtrCampo,
			       lchrArrDato,
			       pLCSiscomPro2Dat);
}
void ObtenNodoAgrupado(const char *pchrPtrCampo,
		       LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrupaPrim,
		       LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrupaAct,
		       LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrupaD)
{
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaD;
if(!*pLCSiscomPro2AgrupaPrim)
{
SiscomCreaListaCamposPro2Agrupados(pchrPtrCampo,
				   pLCSiscomPro2AgrupaPrim,
				   pLCSiscomPro2AgrupaAct);
*pLCSiscomPro2AgrupaD=*pLCSiscomPro2AgrupaPrim;
lLCSiscomPro2AgrupaD=*pLCSiscomPro2AgrupaPrim;
}
else
{
lLCSiscomPro2AgrupaD=*pLCSiscomPro2AgrupaPrim;
	for(;
	    lLCSiscomPro2AgrupaD;
	    lLCSiscomPro2AgrupaD=lLCSiscomPro2AgrupaD->LCSiscomPro2AgrupaS)
	{
	  if(!strcmp(lLCSiscomPro2AgrupaD->chrPtrCampo,
	  	     pchrPtrCampo))
	  {
	    *pLCSiscomPro2AgrupaD=lLCSiscomPro2AgrupaD;
	    return ;
	  }

	}
 SiscomCreaListaCamposPro2Agrupados(pchrPtrCampo,
				   pLCSiscomPro2AgrupaPrim,
				   pLCSiscomPro2AgrupaAct);
 *pLCSiscomPro2AgrupaD=*pLCSiscomPro2AgrupaAct;
}
}
void AgregaRegistroAgrupa(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  LCamposSiscomPro2Agrupados *pLCSiscomPro2AgrupaD)
{
   SiscomCreaListaCamposPro2(
   		pLCSiscomPro2Dat->SCSiscomPro2,
		&pLCSiscomPro2AgrupaD->LCSiscomPro2Prim,
		&pLCSiscomPro2AgrupaD->LCSiscomPro2Act);
}
void SiscomAgrupaListaPorCampoPro2(const char *pchrPtrCampo,
			 LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2Agrupados **pLCSiscomPro2Agrupa)
{
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaAct=0;
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaDat=0;
*pLCSiscomPro2Agrupa=0;
	for(;
	     pLCSiscomPro2Dat;
	     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
	{
	   ObtenNodoAgrupado(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampo),
	   		     pLCSiscomPro2Agrupa,
			     &lLCSiscomPro2AgrupaAct,
			     &lLCSiscomPro2AgrupaDat);

	   AgregaRegistroAgrupa(pLCSiscomPro2Dat,
	   			lLCSiscomPro2AgrupaDat);
	}
}

void SiscomAsignaMemoriaCPro2Agrupa(
		const char *pchrPtrCampo,
		LCamposSiscomPro2Agrupados **pLCSiscomPro2Agrupa)
{

	if(!(*pLCSiscomPro2Agrupa=
	     (LCamposSiscomPro2Agrupados *)malloc(sizeof(LCamposSiscomPro2Agrupados))))
	  {

	  }
	  else
	  {
	    memset(*pLCSiscomPro2Agrupa,
	    	   0,
		   sizeof(LCamposSiscomPro2Agrupados));
	   (*pLCSiscomPro2Agrupa)->chrPtrCampo=(char *)pchrPtrCampo;
	  }
}
void SiscomCreaListaCamposPro2Agrupados(
		const char *pchrPtrCampo,
	        LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrupaPrim,
	        LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrupaAct)
{
LCamposSiscomPro2Agrupados *lLCSiscomPro2Agrupa;


SiscomAsignaMemoriaCPro2Agrupa(pchrPtrCampo,
				&lLCSiscomPro2Agrupa);

if(!(*pLCSiscomPro2AgrupaPrim))
*pLCSiscomPro2AgrupaPrim=*pLCSiscomPro2AgrupaAct=lLCSiscomPro2Agrupa;
else
{
 (*pLCSiscomPro2AgrupaAct)->LCSiscomPro2AgrupaS=lLCSiscomPro2Agrupa;
 (*pLCSiscomPro2AgrupaAct)=(*pLCSiscomPro2AgrupaAct)->LCSiscomPro2AgrupaS;
}


}

int SiscomComparaCampo(LCamposSiscomPro2 *pLCSiscomPro2Uno,
		       LCamposSiscomPro2 *pLCSiscomPro2Dos,
		       const char *pchrPtrCampo)
{
return strcmp(SiscomObtenDato(pLCSiscomPro2Uno,pchrPtrCampo),
	      SiscomObtenDato(pLCSiscomPro2Dos,pchrPtrCampo));
}


int SiscomComparaCampo2(LCamposSiscomPro2 *pLCSiscomPro2Uno,
		       LCamposSiscomPro2 *pLCSiscomPro2Dos,
		       const char *pchrPtrCampoUno,
		       const char *pchrPtrCampoDos)
{
return strcmp(SiscomObtenDato(pLCSiscomPro2Uno,pchrPtrCampoUno),
	      SiscomObtenDato(pLCSiscomPro2Dos,pchrPtrCampoDos));
}


int SiscomComparaCampoChar(const char *pchrPtrCampo,
			   const char *pchrPtrCadena,
			   LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
const char *lchrPtrDato;
  if((lchrPtrDato=SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampo)))
   return strcmp(lchrPtrDato,pchrPtrCadena);
return -1;
}


int SiscomComparaNCaracteresCampoChar(const char *pchrPtrCampo,
			   const char *pchrPtrCadena,
			   int pintNCaracteres,
			   LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
const char *lchrPtrDato;
  if((lchrPtrDato=SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampo)))
   return strncmp(lchrPtrDato,pchrPtrCadena,pintNCaracteres);
return -1;
}



const char *SiscomBuscaSubCadenaCampo(const char *pchrPtrCampo,
				      const char *pchrPtrCadena,
				      LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
const char *lchrPtrDato;
    if((lchrPtrDato=SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampo)))
    return strstr(lchrPtrDato,pchrPtrCadena);

return 0;
}

LCamposSiscomPro2 *SiscomUltimoRegistro(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=0;
while(pLCSiscomPro2Dat)
{
     lLCSiscomPro2Dat=pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;

}
return lLCSiscomPro2Dat;
}

int SiscomVersionProtocolo(int pintSocket)
{
char *lchrPtrVersionProtocolo;
char lchrArrVersion[6];
SiscomLeeInformacion(pintSocket,15,&lchrPtrVersionProtocolo);
strncpy(lchrArrVersion,lchrPtrVersionProtocolo,5);
lchrArrVersion[5]=0;
return atoi(lchrArrVersion);
}
