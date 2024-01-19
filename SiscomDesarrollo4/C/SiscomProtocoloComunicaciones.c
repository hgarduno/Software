#include <SiscomProtocoloComunicaciones.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomServidor.h>
#include <SiscomFuncionesComunes.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
/*
 * Tepotzotlan Mexico A 10 Mayo 2020 
 * No lo puedo creer , a;os y no tenia esta funcion , 
 * la agrego, para poder actualizar el campo de un registro asociado 
 *
 * La funcion no asigna memoria, al campo
 *
 */
void SiscomActualizaCampoAsociado(const char *pchrPtrCampo,
				  const char *pchrPtrAsociado,
				  const char *pchrPtrValor,
				  SiscomRegistroProL *pSisRegProLPtrDato)
{
SiscomRegistroProL *lSisRegProLPtrRegistroAsociado;
if((lSisRegProLPtrRegistroAsociado=SiscomObtenRegistrosCampoProL(pchrPtrAsociado,pSisRegProLPtrDato)))
 SiscomActualizaCampoRegistro(pchrPtrCampo,(char *)pchrPtrValor,lSisRegProLPtrRegistroAsociado);
else
{

}
}
int SiscomAgregaCampoRegistros(const char *pchrPtrNmbCampo,
			       const char *pchrPtrDato,
			       SiscomRegistroProL *pSiscomRegProLPtrDato)
{

for( ; 
     pSiscomRegProLPtrDato;
     pSiscomRegProLPtrDato=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrDato))
   SiscomAgregaCampoRegistro(pchrPtrNmbCampo,pchrPtrDato,pSiscomRegProLPtrDato);
}
/* 29 de diciembre del 2014
 * Para hacer que la intefaz grafica solo envie los 
 * campos que tiene en un instante, y en el servidor 
 * se agregue esta informacion, es necesario agregar la 
 * siguiente funcion, previamente a la estructura SiscomCampoProL 
 * se le agrego un campo SiscomCampoProL para almacenar la direccion
 * del ultimo campo agregado a la lista
 * Sabado 13 de agosto 2016
 * Cuando la lista ya tiene campos
 */
int SiscomAgregaCampoRegistro(const char *pchrPtrNmbCampo,
			 const char *pchrPtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato)
{
if(!SiscomEstaElCampo4(pchrPtrNmbCampo,pSiscomRegProLPtrDato))
SiscomNodoCampoPro(pchrPtrNmbCampo,
		   pchrPtrDato,
		   &pSiscomRegProLPtrDato->SiscomCamProLPtrDato,
		   &pSiscomRegProLPtrDato->SiscomCamProLPtrDato->SiscomCamProLPtrActual);
}
/* Sabado 13 de Agosto 2016 
 * Inicia con un nodo vacio para los campos 
 */
int SiscomAgregaCampoRegistro2(const char *pchrPtrNmbCampo,
			 const char *pchrPtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomCampoProL *lSiscomCamProLPtrPrim=0,
		*lSiscomCamProLPtrAct=0;
SiscomNodoCampoPro(pchrPtrNmbCampo,
		   pchrPtrDato,
		   &lSiscomCamProLPtrPrim,
		   &lSiscomCamProLPtrAct);
pSiscomRegProLPtrDato->SiscomCamProLPtrDato=lSiscomCamProLPtrPrim;
}

/* Lunes 30 de Abril del 2012
 * Se agrega la funcion que asigna memoria para el 
 * nodo del campo que asigna de forma directa los 
 * campos pchtPtrNmbCampo y pchrPtrDato, estos campos
 * previamente se asignaron via strdup
 */
int SiscomMemoriaNodoCampoPro2(const char *pchrPtrNmbCampo,
			  const char *pchrPtrDato,
			  SiscomCampoProL **pSiscomCamProLPtrDat)
{
if((*pSiscomCamProLPtrDat=(SiscomCampoProL *)malloc(sizeof(SiscomCampoProL)))) 
{
 (*pSiscomCamProLPtrDat)->chrPtrNmbCampo=pchrPtrNmbCampo;
 if(pchrPtrDato)
  (*pSiscomCamProLPtrDat)->chrPtrDato=(char *)pchrPtrDato;
  else
  (*pSiscomCamProLPtrDat)->chrPtrDato=0;
 (*pSiscomCamProLPtrDat)->SiscomCamProLPtrSig=0;
 (*pSiscomCamProLPtrDat)->SiscomCamProLPtrAnt=0;
 (*pSiscomCamProLPtrDat)->vidPtrSubPrim=0;
 (*pSiscomCamProLPtrDat)->vidPtrSubAct=0;
}
else
LogSiscom("Error al asignar memoria");
}
int SiscomMemoriaNodoCampoPro(const char *pchrPtrNmbCampo,
			  const char *pchrPtrDato,
			  SiscomCampoProL **pSiscomCamProLPtrDat)
{
if((*pSiscomCamProLPtrDat=(SiscomCampoProL *)malloc(sizeof(SiscomCampoProL))))
{
 (*pSiscomCamProLPtrDat)->chrPtrNmbCampo=strdup(pchrPtrNmbCampo);
 if(pchrPtrDato)
  (*pSiscomCamProLPtrDat)->chrPtrDato=strdup(pchrPtrDato);
  else
  (*pSiscomCamProLPtrDat)->chrPtrDato=0;
 (*pSiscomCamProLPtrDat)->SiscomCamProLPtrSig=0;
 (*pSiscomCamProLPtrDat)->SiscomCamProLPtrAnt=0;
 (*pSiscomCamProLPtrDat)->vidPtrSubPrim=0;
 (*pSiscomCamProLPtrDat)->vidPtrSubAct=0;
}

}
int SiscomNodoCampoPro2(const char *pchrPtrNmbCampo,
			const char *pchrPtrDato,
			SiscomCampoProL **pSiscomCamProLPtrPrim,
			SiscomCampoProL **pSiscomCamProLPtrAct)
{
SiscomCampoProL *lSiscomCamProLPtrDat=0;
SiscomMemoriaNodoCampoPro2(pchrPtrNmbCampo,
			  pchrPtrDato,
			  &lSiscomCamProLPtrDat);
if(!(*pSiscomCamProLPtrPrim))
{
(*pSiscomCamProLPtrPrim)=(*pSiscomCamProLPtrAct)=lSiscomCamProLPtrDat;
(*pSiscomCamProLPtrPrim)->intNCampos=0;
}
else
{
(*pSiscomCamProLPtrAct)->SiscomCamProLPtrSig=lSiscomCamProLPtrDat;
(*pSiscomCamProLPtrAct)=(*pSiscomCamProLPtrAct)->SiscomCamProLPtrSig;
}
(*pSiscomCamProLPtrPrim)->intNCampos++;
(*pSiscomCamProLPtrPrim)->SiscomCamProLPtrActual=*pSiscomCamProLPtrAct;
}
int SiscomNodoCampoPro(const char *pchrPtrNmbCampo,
			   const char *pchrPtrDato,
			   SiscomCampoProL **pSiscomCamProLPtrPrim,
			   SiscomCampoProL **pSiscomCamProLPtrAct)
{
SiscomCampoProL *lSiscomCamProLPtrDat=0;

SiscomMemoriaNodoCampoPro(pchrPtrNmbCampo,
			  pchrPtrDato,
			  &lSiscomCamProLPtrDat);
if(!(*pSiscomCamProLPtrPrim))
{
(*pSiscomCamProLPtrPrim)=(*pSiscomCamProLPtrAct)=lSiscomCamProLPtrDat;
(*pSiscomCamProLPtrPrim)->intNCampos=0;
}
else
{
(*pSiscomCamProLPtrAct)->SiscomCamProLPtrSig=lSiscomCamProLPtrDat;
(*pSiscomCamProLPtrAct)=(*pSiscomCamProLPtrAct)->SiscomCamProLPtrSig;
}
(*pSiscomCamProLPtrPrim)->intNCampos++;
(*pSiscomCamProLPtrPrim)->SiscomCamProLPtrActual=*pSiscomCamProLPtrAct;
}

SiscomCampoProL *SiscomFormaRegistro(char **pchrPtrCampos,
		 	SiscomCampoProL **pSiscomCamProLPtrPrim,
			SiscomCampoProL **pSiscomCamProLPtrAct)
{
	while(*pchrPtrCampos)
	{
	SiscomNodoCampoPro(*pchrPtrCampos,
			   0,
			   pSiscomCamProLPtrPrim,
			   pSiscomCamProLPtrAct);
	pchrPtrCampos++;
	}
  return *pSiscomCamProLPtrPrim;
}
int SiscomAgregaCampo(const char *pchrPtrNmbCampo,
		      const char *pchrPtrDato,
		      SiscomCampoProL **pSiscomCamProLPtrPrim,
		      SiscomCampoProL **pSiscomCamProLPtrAct)
{
SiscomNodoCampoPro(pchrPtrNmbCampo,
		      pchrPtrDato,
		      pSiscomCamProLPtrPrim,
		      pSiscomCamProLPtrAct);
}

int SiscomMemoriaRegistroPro(const SiscomCampoProL *pSiscomCamProLPtrDat,
		      SiscomRegistroProL **pSiscomRegProLPtrDat)
{
if((*pSiscomRegProLPtrDat=(SiscomRegistroProL *)malloc(sizeof(SiscomRegistroProL))))
{
(*pSiscomRegProLPtrDat)->intNRegistros=0;
(*pSiscomRegProLPtrDat)->SiscomCamProLPtrDato=(SiscomCampoProL *)pSiscomCamProLPtrDat;
(*pSiscomRegProLPtrDat)->SiscomRegProLPtrSig=0;
(*pSiscomRegProLPtrDat)->SiscomRegProLPtrAnt=0;
}
}

int SiscomNodoRegistroPro(const SiscomCampoProL *pSiscomCamProLPtrDat,
			  SiscomRegistroProL **pSiscomRegProLPtrPrim,
			  SiscomRegistroProL **pSiscomRegProLPtrAct)
{
SiscomRegistroProL *lSiscomRegProLPtrDat=0;
SiscomMemoriaRegistroPro(pSiscomCamProLPtrDat,
			 &lSiscomRegProLPtrDat);
if(!(*pSiscomRegProLPtrPrim))
{
(*pSiscomRegProLPtrPrim)=(*pSiscomRegProLPtrAct)=lSiscomRegProLPtrDat;
(*pSiscomRegProLPtrPrim)->intNRegistros=0;
}
else
{
(*pSiscomRegProLPtrAct)->SiscomRegProLPtrSig=lSiscomRegProLPtrDat;
(*pSiscomRegProLPtrAct)=(*pSiscomRegProLPtrAct)->SiscomRegProLPtrSig;
}
(*pSiscomRegProLPtrPrim)->intNRegistros++;
}

/* Miercoles 25 de Abril del 2012 
 * En este punto se debera iniciar con el desarrollo de las 
 * funciones para el manejo de registros, por lo que se tomara
 * el siguiente prototipo 
 * La variable buffer debera ser una cadena que permita almacenar
 * el tamano del nombre del campo mas grande que se pase, ya que 
 * en las versiones previas se asignaba memoria dinamica para realizar
 * esto, lo cual no es buena idea
 * SiscomAnexaRegistroPro(SiscomRegistroProL **pSiscomRegProLPtrPrim,
 * 			  SiscomRegistroProL **pSiscomRegProLPtrAct,
 * 			  char *pchrPtrBuffer,
 * 			  const char *pchrPtrFormato,
 * 			  ...);
 *
 * La funcion debera pasar en en pchrPtrFormato separado por comas
 * el nombre de los campos de cada registro y en el argumento el 
 * valor del campo para el registro.
 *
 * Por ejemplo:
 * SiscomAnexaRegistroPro(pSiscomRegProLPtrPrim,
 * 			  pSiscomRegProLPtrAct,
 * 			  lchrArrBuffer,
 * 			  "Nombre,APaterno,AMaterno,Edad,Sexo",
 * 			  "Heli",
 * 			  "Garduno",
 * 			  "Esquivel",
 * 			  "Masculino");
 *
 * Queretaro 13 Noviembre del 2015 
 * En caso de pasar un nulo (0) en cualquiera de los valores 
 * se debera indicar de manera explicita como (const char *)0
 */

int SiscomAnexaRegistroPro(SiscomRegistroProL **pSiscomRegProLPtrPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrAct,
			   char *pchrPtrBuffer,
			   const char *pchrPtrFormato,
			   ...)
{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
		*lSiscomCamProLPtrPaso;
va_list lvaListInfo;
char *lchrPtrCampo;
va_start(lvaListInfo,pchrPtrFormato);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposFormato(pchrPtrFormato,pchrPtrBuffer);
while(lSiscomCamProLPtrDato)
{
lchrPtrCampo=va_arg(lvaListInfo,char *);
lSiscomCamProLPtrDato->chrPtrDato=lchrPtrCampo ? strdup(lchrPtrCampo):0;
lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      pSiscomRegProLPtrPrim,
		      pSiscomRegProLPtrAct);
va_end(lvaListInfo);
}
/*
int SiscomAnexaRegistroPro2(SiscomRegistroProL **pSiscomRegProLPtrPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrAct,
			   SiscomRegistroProL *pSiscomRegProLDato)
{
SiscomNodoRegistroPro(pSiscomRegProLDato->SiscomCamProLPtrDato,
		      pSiscomRegProLPtrPrim,
		      pSiscomRegProLPtrAct);
}
*/
/* Sabado 13 de Agosto del 2016 
 * Agrega un nodo vacio, en los campos , para poder agregarlo
 * 
 */
int SiscomAnexaRegistroPro3(SiscomRegistroProL **pSiscomRegProLPtrPrim,
			    SiscomRegistroProL **pSiscomRegProLPtrAct)
{
SiscomNodoRegistroPro(0,
		      pSiscomRegProLPtrPrim,
		      pSiscomRegProLPtrAct);
}

/* Miercoles 25 de Abril 2012 
 * Esta rutina tiene un error en la parte
 * final del analisis de la cadena ahorita
 * se salto poniendo una ',' en el ultimo 
 * dato
 */
SiscomCampoProL *SiscomFormaCamposFormato(const char *pchrPtrFormato,
					  char *pchrPtrBuffer)
{
SiscomCampoProL *lSiscomCamProLPtrPrim=0,
 		*lSiscomCamProLPtrAct=0;
char *lchrPtrInicio=pchrPtrBuffer;
	do{
	   if(*pchrPtrFormato==',')
	   {
	     pchrPtrFormato++;
	     *pchrPtrBuffer=0;
	     pchrPtrBuffer=lchrPtrInicio;
	     SiscomNodoCampoPro(lchrPtrInicio,
	     			0,
				&lSiscomCamProLPtrPrim,
				&lSiscomCamProLPtrAct);
	   }
	   else
	   {
	      *pchrPtrBuffer=*pchrPtrFormato;
	      pchrPtrBuffer++;
	      pchrPtrFormato++;
	   }
	}while(*pchrPtrFormato); 
return lSiscomCamProLPtrPrim;
}
SiscomCampoProL *SiscomObtenCampoRegistroProL(
			const char *pchrPtrNmbCampo,
			SiscomRegistroProL *pSiscomRegProLPtrDat)
{
SiscomCampoProL *lSiscomCamProLPtrDato;
lSiscomCamProLPtrDato=pSiscomRegProLPtrDat->SiscomCamProLPtrDato;
while(lSiscomCamProLPtrDato)
{
if(!strcmp(lSiscomCamProLPtrDato->chrPtrNmbCampo,pchrPtrNmbCampo))
return lSiscomCamProLPtrDato;
lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
return 0;
}


const char *SiscomObtenCampoRegistroProLChar(const char *pchrPtrNmbCampo,
					     SiscomRegistroProL *pSiscomRegProLPtrDat)
{
SiscomCampoProL *lSiscomCamProLPtrDato;
if((lSiscomCamProLPtrDato=SiscomObtenCampoRegistroProL(pchrPtrNmbCampo,
						   pSiscomRegProLPtrDat)))
return lSiscomCamProLPtrDato->chrPtrDato;
else
/* Miercoles 13 de Abril del 2015
 * Se cambia a nulo el campo no encontrado
 * ....
return "Campo No Encontrado";
*/
return (const char *)0;
}
const char *SiscomCampoProLCharNulo(const char *pchrPtrNmbCampo,
					     SiscomRegistroProL *pSiscomRegProLPtrDat)
{
const char *lchrPtrCampo;
if((lchrPtrCampo=SiscomObtenCampoRegistroProLChar(pchrPtrNmbCampo,pSiscomRegProLPtrDat)))
return lchrPtrCampo;
else
return "";
}

int SiscomCampoRegistroProLCharEsVacio(const char *pchrPtrNmbCampo,
				       SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomCampoProL *lSiscomCamProLPtrDato;
if((lSiscomCamProLPtrDato=SiscomObtenCampoRegistroProL(pchrPtrNmbCampo,
						   pSiscomRegProLPtrDato)))
return lSiscomCamProLPtrDato->chrPtrDato &&
       *(lSiscomCamProLPtrDato->chrPtrDato) ? 0 :1 ;
else
return -1;
}



int SiscomObtenCampoRegistroProLInt(const char *pchrPtrNmbCampo,
					     SiscomRegistroProL *pSiscomRegProLPtrDat)
{
return atoi(SiscomObtenCampoRegistroProLChar(pchrPtrNmbCampo,pSiscomRegProLPtrDat));
}

float SiscomObtenCampoRegistroProLFloat(const char *pchrPtrNmbCampo,
					     SiscomRegistroProL *pSiscomRegProLPtrDat)
{
const char *lchrPtrNumero;
lchrPtrNumero=SiscomObtenCampoRegistroProLChar(pchrPtrNmbCampo,pSiscomRegProLPtrDat);
 return atof(lchrPtrNumero ? lchrPtrNumero : "0" );
}

int SiscomRegistrosAlCampo(
		const char *pchrPtrNmbCampo,
		const SiscomRegistroProL *pSiscomRegProLPtrPrim,
		const SiscomRegistroProL *pSiscomRegProLPtrAct,
		SiscomRegistroProL *pSiscomRegProLPtrDat)
{
SiscomCampoProL *lSiscomCamProLPtrCampo;  

if((lSiscomCamProLPtrCampo=SiscomObtenCampoRegistroProL(pchrPtrNmbCampo,
						    pSiscomRegProLPtrDat)))
{
  lSiscomCamProLPtrCampo->vidPtrSubPrim=(void *)pSiscomRegProLPtrPrim;
  lSiscomCamProLPtrCampo->vidPtrSubAct=(void *)pSiscomRegProLPtrAct;
}
else
LogSiscom("NO se encontro el campo %s",pchrPtrNmbCampo);
}
int SiscomAnexaRegistrosAlCampo(const char *pchrPtrNmbCampo,
				SiscomRegistroProL *pSiscomRegProLPtrDat,
				char *pchrPtrBuffer,
				const char *pchrPtrFormato,
				...)
{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
		*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
va_list lvaListInfo;
const char *lchrPtrCampo;
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposFormato(pchrPtrFormato,pchrPtrBuffer);
va_start(lvaListInfo,pchrPtrFormato);
while(lSiscomCamProLPtrDato)
{
lchrPtrCampo=va_arg(lvaListInfo,char *);
lSiscomCamProLPtrDato->chrPtrDato=lchrPtrCampo ? strdup(lchrPtrCampo):0;
lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
va_end(lvaListInfo);
lSiscomCamProLPtrCampo=SiscomObtenCampoRegistroProL(pchrPtrNmbCampo,
						    pSiscomRegProLPtrDat); 
SiscomNodoRegistroPro(
	lSiscomCamProLPtrPaso,
	(SiscomRegistroProL **)&lSiscomCamProLPtrCampo->vidPtrSubPrim,
	(SiscomRegistroProL **)&lSiscomCamProLPtrCampo->vidPtrSubAct);
}
SiscomRegistroProL *SiscomObtenRegistrosCampoProL(
			const char *pchrPtrNmbCampo,
			SiscomRegistroProL *pSiscomProLPtrAct)
{
SiscomCampoProL *lSiscomCamProLPtrCampo;
if((lSiscomCamProLPtrCampo=SiscomObtenCampoRegistroProL(
				pchrPtrNmbCampo,
				pSiscomProLPtrAct)))
return (SiscomRegistroProL *)lSiscomCamProLPtrCampo->vidPtrSubPrim;
else
return 0;
}


SiscomRegistroProL *SiscomObtenRegistroActualCampoProL(
			const char *pchrPtrNmbCampo,
			SiscomRegistroProL *pSiscomProLPtrAct)
{
SiscomCampoProL *lSiscomCamProLPtrCampo;
lSiscomCamProLPtrCampo=SiscomObtenCampoRegistroProL(
				pchrPtrNmbCampo,
				pSiscomProLPtrAct);
return (SiscomRegistroProL *)lSiscomCamProLPtrCampo->vidPtrSubAct;
}


SiscomRegistroProL *SiscomObtenRegistroPrimCampoProL(
			const char *pchrPtrNmbCampo,
			SiscomRegistroProL *pSiscomProLPtrAct)
{
SiscomCampoProL *lSiscomCamProLPtrCampo;
lSiscomCamProLPtrCampo=SiscomObtenCampoRegistroProL(
				pchrPtrNmbCampo,
				pSiscomProLPtrAct);
return (SiscomRegistroProL *)lSiscomCamProLPtrCampo->vidPtrSubPrim;
}

/* Jueves 26 de Abril del 2012 
 * Esta sera la base de intercambio de la informacion entre el cliente
 * y el servidor, con lo que se tiene en este momento ya se logro 
 * incorporar el manejo de registros asociados a un campo del registo
 * ahora la siguiente funcion debera de encargarse de formar los trenes
 * de datos que deberan enviarse por el socket
 *
 * 00002 ----> Numero de registros
 * 00004 ----> Numero de campos
 * 00004 ----> Longitud del nombre del campo
 * xxxxx ----> Campo
 * 1     ----> Flag registros asociados al campo
 *
 */

int SiscomEnviaRegistrosSocket(int pintSocket,
			       char *pchrPtrBuffer,
			       const SiscomRegistroProL *pSiscomRegProLPtrDat)
{

  while(pSiscomRegProLPtrDat)
  {
    SiscomEnviaRegistroSocket(pintSocket,
    			      pchrPtrBuffer,
    			      pSiscomRegProLPtrDat);
    
    pSiscomRegProLPtrDat=pSiscomRegProLPtrDat->SiscomRegProLPtrSig;
  }
  SiscomEnviaCadenaSocket(pintSocket,"00000");
}
/* Miercoles 16 de mayo del 2012
 * Al momento de enviar los registros se identifco que las rutinas 
 * de lectura del socket, se quedaban esperando 5 caracteres mas 
 * al inicio se puso la linea  SiscomEnviaCadenaSocket(pintSocket,"00000"); 
 * en la rutina SiscomEnviaRegistrosSocket, pero como esta rutina se utiliza
 * en el envio de los registros asociados se defasafa toda la informacion
 * entonces la solucion fue escribir una rutina exactamente igual que 
 * SiscomEnviaRegistrosSocket pero sin la linea que envia los 5 caracteres
 * y todo fue felicidad.
 */
int SiscomEnviaRegistrosSocketSinFinal(int pintSocket,
			       char *pchrPtrBuffer,
			       const SiscomRegistroProL *pSiscomRegProLPtrDat)
{

  while(pSiscomRegProLPtrDat)
  {
    SiscomEnviaRegistroSocket(pintSocket,
    			      pchrPtrBuffer,
    			      pSiscomRegProLPtrDat);
    
    pSiscomRegProLPtrDat=pSiscomRegProLPtrDat->SiscomRegProLPtrSig;
  }
}
int SiscomEnviaCadenaSocket(int pintSocket,
			    const char *pchrPtrCadena)
{
int lintNCaracteres;
int lintNBytesEnviados;
lintNCaracteres=strlen(pchrPtrCadena);
if((lintNBytesEnviados=write(pintSocket,pchrPtrCadena,lintNCaracteres))!=lintNCaracteres)
LogSiscom("Se Enviaron solo %d bytes de %d",lintNBytesEnviados,lintNCaracteres);

SiscomSocketProtocoloLog("%s",pchrPtrCadena);
}

int SiscomEnviaIntSocket(int pintSocket,
			 int pintCerosIzquierda,
			 int pintEnvio)
{
char lchrArrEnvio[20];
char lchrArrPaso[20];
sprintf(lchrArrPaso,"%%0%dd",pintCerosIzquierda);
sprintf(lchrArrEnvio,lchrArrPaso,pintEnvio);
SiscomEnviaCadenaSocket(pintSocket,lchrArrEnvio);
}

int SiscomEnviaRegistroSocket(int pintSocket,
			      char *pchrPtrBuffer,
			      const SiscomRegistroProL *pSiscomRegProLPtrDat)
{
const SiscomCampoProL *lSiscomCamProLPtrDato;
lSiscomCamProLPtrDato=pSiscomRegProLPtrDat->SiscomCamProLPtrDato;
sprintf(pchrPtrBuffer,
	"%05d%05d",
	pSiscomRegProLPtrDat->intNRegistros,
	lSiscomCamProLPtrDato->intNCampos);
SiscomEnviaCadenaSocket(pintSocket,pchrPtrBuffer); 
while(lSiscomCamProLPtrDato)
{
sprintf(pchrPtrBuffer,
	"%05d%s%05d%s",
	(int )strlen(lSiscomCamProLPtrDato->chrPtrNmbCampo),
	lSiscomCamProLPtrDato->chrPtrNmbCampo,
	lSiscomCamProLPtrDato->chrPtrDato ? 
	(int )strlen(lSiscomCamProLPtrDato->chrPtrDato):0,
	lSiscomCamProLPtrDato->chrPtrDato ? 
	lSiscomCamProLPtrDato->chrPtrDato:"");
SiscomEnviaCadenaSocket(pintSocket,pchrPtrBuffer);
SiscomEnviaRegistrosAsociadosSocket(
		pintSocket,
		pchrPtrBuffer,
		(SiscomRegistroProL *)lSiscomCamProLPtrDato->vidPtrSubPrim);

lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
}

int SiscomEnviaRegistrosAsociadosSocket(
		int pintSocket,
		char *pchrPtrBuffer,
		const SiscomRegistroProL *pSiscomRegProLPtrDat)
{
 if(pSiscomRegProLPtrDat)
 {
    SiscomEnviaCadenaSocket(pintSocket,"1");
    SiscomEnviaRegistrosSocketSinFinal(pintSocket,
			      pchrPtrBuffer,
			      pSiscomRegProLPtrDat);
    SiscomEnviaCadenaSocket(pintSocket,"0000000000");
    
  }
  else
    SiscomEnviaCadenaSocket(pintSocket,"0");
}
int SiscomLeeCaracteresSocket(int pintSocket,
			      int pintNCaracteres,
			      char *pchrPtrBuffer)
{
int lintNRegreso;
int lintContador;
/*
  if((lintNRegreso=read(pintSocket,pchrPtrBuffer,pintNCaracteres))!=pintNCaracteres)
  LogSiscom("Solo se recibiero %d bytes de %d",lintNRegreso,pintNCaracteres);

  *(pchrPtrBuffer+lintNRegreso)=0;

 */
 for(lintContador=0;
     lintContador<pintNCaracteres;
     lintContador++)
  read(pintSocket,pchrPtrBuffer+lintContador,1);
 SiscomSocketProtocoloLog("%s",pchrPtrBuffer); 
 *(pchrPtrBuffer+lintContador)=0;
}
int SiscomLeeCaracteresSocketInt(int pintSocket,
				 int pintNCaracteres,
				 char *pchrPtrBuffer)
{
   SiscomLeeCaracteresSocket(pintSocket,pintNCaracteres,pchrPtrBuffer);
 return atoi(pchrPtrBuffer);
}
int SiscomLeeCampoDatoSocket(int pintSocket,
			     char *pchrPtrBuffer,
			     char **pchrPtrNmbCampo,
			     char **pchrPtrCampo)
{
    SiscomLeeInformacionCampoSocket(pintSocket,pchrPtrBuffer);
    *pchrPtrNmbCampo=strdup(pchrPtrBuffer);
    SiscomLeeInformacionCampoSocket(pintSocket,pchrPtrBuffer);
    if(*pchrPtrBuffer)
    *pchrPtrCampo=strdup(pchrPtrBuffer);
    else
    *pchrPtrCampo=0;
}
int SiscomLeeInformacionCampoSocket(int pintSocket,
			    char *pchrPtrBuffer)
{
int lintTamNmbCampo=SiscomLeeCaracteresSocketInt(pintSocket,
						 5,
						 pchrPtrBuffer);
if(lintTamNmbCampo)
SiscomLeeCaracteresSocket(pintSocket,
			  lintTamNmbCampo,
			  pchrPtrBuffer);
else
*pchrPtrBuffer=0;
}
int SiscomLeeRegistrosAsociadosSocket(
		int pintSocket,
		char *pchrPtrBuffer,
		SiscomCampoProL *pSiscomCamProLPtrAct)
{
int lintRegAsociados;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
lintRegAsociados=SiscomLeeCaracteresSocketInt(pintSocket,
				 1,
				 pchrPtrBuffer);
if(lintRegAsociados)
{
SiscomSocketProtocoloLog("Campo con registros asociados");
SiscomLeeRegistrosSocket(pintSocket,
			 pchrPtrBuffer,
			 &lSiscomRegProLPtrPrim,
			 &lSiscomRegProLPtrAct);
pSiscomCamProLPtrAct->vidPtrSubPrim=(void *)lSiscomRegProLPtrPrim;
pSiscomCamProLPtrAct->vidPtrSubAct=(void *)lSiscomRegProLPtrAct;
SiscomLeeCaracteresSocket(pintSocket,5,pchrPtrBuffer);
SiscomSocketProtocoloLog("Se leyeron los registros asociados");
}
}
				      
int SiscomLeeRegistroSocket(int pintSocket,
			    int pintNCampos,
			    char *pchrPtrBuffer,
			    SiscomCampoProL **pSiscomCamProLPtrReg)
{
int lintContador;
char *lchrPtrNmbCampo=0,
     *lchrPtrDato;
SiscomCampoProL *lSiscomCamProLPtrAct=0;
for(lintContador=0;
    lintContador<pintNCampos;
    lintContador++)
{
SiscomLeeCampoDatoSocket(pintSocket,
			 pchrPtrBuffer,
			 &lchrPtrNmbCampo,
			 &lchrPtrDato);
SiscomNodoCampoPro2(lchrPtrNmbCampo,
		    lchrPtrDato,
		    pSiscomCamProLPtrReg,
		    &lSiscomCamProLPtrAct);
SiscomLeeRegistrosAsociadosSocket(pintSocket,
			    pchrPtrBuffer,
			    lSiscomCamProLPtrAct);
}
}
int SiscomLeeRegistrosSocket(int pintSocket,
			     char *pchrPtrBuffer,
			     SiscomRegistroProL **pSiscomRegProLPtrPrim,
			     SiscomRegistroProL **pSiscomRegProLPtrAct)
{
int lintNRegistros=SiscomLeeCaracteresSocketInt(pintSocket,
						5,
						pchrPtrBuffer);
int lintNCampos; 
char *lchrPtrNmbCampo,*lchrPtrDato;
int lintContador;
SiscomCampoProL *lSiscomCamProLPtrDat=0;
for(lintContador=0;
    lintContador<lintNRegistros;
    lintContador++)
{
lintNCampos=SiscomLeeCaracteresSocketInt(pintSocket,5,pchrPtrBuffer);
SiscomLeeRegistroSocket(pintSocket,
			lintNCampos,
			pchrPtrBuffer,
			&lSiscomCamProLPtrDat);
SiscomLeeCaracteresSocket(pintSocket,5,pchrPtrBuffer);
SiscomNodoRegistroPro(lSiscomCamProLPtrDat,
		    pSiscomRegProLPtrPrim,
		    pSiscomRegProLPtrAct);
lSiscomCamProLPtrDat=0;
}
return 0;
}


int SiscomConectateCliente(const char *pchrPtrDirIpSvr,
  			   int pintPuerto,
			   char **pchrPtrEdoConexion)
{
int lintSocket;
struct sockaddr_in lSocAddrInCon;
*pchrPtrEdoConexion=0;
	if((lintSocket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
	}
	else
	{
	  lSocAddrInCon.sin_family=AF_INET;
	  lSocAddrInCon.sin_port=htons(pintPuerto);
	  lSocAddrInCon.sin_addr.s_addr=inet_addr(pchrPtrDirIpSvr);
	  if((connect(lintSocket,
		      (struct sockaddr *)&lSocAddrInCon,
		      sizeof(struct sockaddr_in)))<0)
	  {
	     LogSiscom("%s",strerror(errno));
	     *pchrPtrEdoConexion=(char *)strerror(errno); 
	     return -1;
	  }
	   else
	   return lintSocket;

	}
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
   if((lintRegreso=connect(lintSocket,(struct sockaddr *)&lSocAddrInCon,sizeof(struct sockaddr_in)))<0)
	  {
	    LogSiscom("Conectando %d",errno);
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
		   
		}
		else
		{
		    LogSiscom("Timeout, se espero %d seg para la conexion %d %s",
		    		pintTiempo,
		    		errno,
				strerror(errno));
		    return -1;
		}
	    }
	    else
	    {
	 	LogSiscom("Error Conexion %d %s %d %d",
			 errno,
			 strerror(errno),
			 EINPROGRESS,
			 lintRegreso);
		return -1;
	    }
	    
	  }
	  else
	  {
	  	LogSiscom("NO SE Conecto");
	 	LogSiscom("NO Se pudo conectar a %s:%d",
			   pchrPtrDirIpSvr,
			   pintPuerto);
		return -1;
	  }



	}
	llngArgSocket = fcntl(lintSocket, F_GETFL, NULL); 
	llngArgSocket &= (~O_NONBLOCK); 
	fcntl(lintSocket, F_SETFL, llngArgSocket); 
	return lintSocket;
}


int SiscomConectateClienteNoBloqueante4(const char *pchrPtrDirIpSvr,
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
		if((lintRegreso=select(lintSocket+1,NULL,&lfdSetSocket,NULL,&lTimValTiempo)))
		{
		  /*LogSiscom("select %d errno:%d",lintRegreso,errno);  */
	 	   llngTamEntero=sizeof(int);
		   lintRegreso=getsockopt(lintSocket,
		   	     SOL_SOCKET,
			     SO_ERROR,
			     (void *)&lintValOpt,
			     (socklen_t *)&llngTamEntero);
		/*  LogSiscom("getsockopt %d errno:%d lintValOpt:%d",lintRegreso,errno,lintValOpt);  */
		  if(lintValOpt==111)
		   return -1;
		   
		}
		else
		{
		    LogSiscom("Timeout, se espero %d seg para la conexion %d %s",
		    		pintTiempo,
		    		errno,
				strerror(errno));
		    return -1;
		}
	    }
	    else
	    {
	 	LogSiscom("Error Conexion %d %s %d %d",
			 errno,
			 strerror(errno),
			 EINPROGRESS,
			 lintRegreso);
		return -1;
	    }
	    
	  }
	  else
	  {
	  	LogSiscom("NO SE Conecto");
	 	LogSiscom("NO Se pudo conectar a %s:%d",
			   pchrPtrDirIpSvr,
			   pintPuerto);
	  }



	}
	llngArgSocket = fcntl(lintSocket, F_GETFL, NULL); 
	llngArgSocket &= (~O_NONBLOCK); 
	fcntl(lintSocket, F_SETFL, llngArgSocket); 
	return lintSocket;
}




int SiscomComparaCadenaCampoRegistroProL(const char *pchrPtrCadena,
					 const char *pchrPtrCampo,
					 SiscomRegistroProL *pSiscomRegProLPtrDat)
{
const char *lchrPtrDatoCampo;
if((lchrPtrDatoCampo=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrDat)) &&
    lchrPtrDatoCampo)
return strcmp(pchrPtrCadena,lchrPtrDatoCampo);
else
return -10;
}

const char *SiscomBuscaCadenaCampoRegistroProL(const char *pchrPtrCadena,
					       const char *pchrPtrCampo,
					       SiscomRegistroProL *pSiscomRegProLPtrDat)
{
const char *lchrPtrRegreso;
if((lchrPtrRegreso=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrDat)))
    return strstr(lchrPtrRegreso,pchrPtrCadena);
else
return 0;
}


int SiscomComparaCampoRegistrosProL(const char *pchrPtrCampo,
				    SiscomRegistroProL *pSiscomRegProLPtrUno,
				    SiscomRegistroProL *pSiscomRegProLPtrDos)
{
const char *lchrPtrCampoUno=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrUno),
	   *lchrPtrCampoDos=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrDos);
if(lchrPtrCampoUno && 
   lchrPtrCampoDos )
  return strcmp(lchrPtrCampoUno,lchrPtrCampoDos);
else
return -1;
}
int SiscomComparaCampoRegistrosProL2(const char *pchrPtrCampoUno,
				     const char *pchrPtrCampoDos,
				    SiscomRegistroProL *pSiscomRegProLPtrUno,
				    SiscomRegistroProL *pSiscomRegProLPtrDos)
{
const char *lchrPtrCampoUno=SiscomObtenCampoRegistroProLChar(pchrPtrCampoUno,pSiscomRegProLPtrUno),
	   *lchrPtrCampoDos=SiscomObtenCampoRegistroProLChar(pchrPtrCampoDos,pSiscomRegProLPtrDos);
if(lchrPtrCampoUno && 
   lchrPtrCampoDos )
  return strcmp(lchrPtrCampoUno,lchrPtrCampoDos);
else
return -1;
}


SiscomRegistroProL *SiscomSiguienteNodoRegistroProL(SiscomRegistroProL *pSiscomRegProLPtrDat)
{
	return pSiscomRegProLPtrDat->SiscomRegProLPtrSig;
}

int SiscomRegistrosConCampoIguales(const char *pchrPtrCampo,
				   SiscomRegistroProL *pSiscomRegProLPtrA,
				   SiscomRegistroProL *pSiscomRegProLPtrB)
{
const char *lchrPtrCampoA=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrA),
           *lchrPtrCampoB=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrB);
return !strcmp(lchrPtrCampoA,lchrPtrCampoB);
}
/* Sabado 20 de diciembre, cuando el campo se asigno via malloc, o se 
 * leyo del protocolo
 */
void SiscomActualizaCampoAsignaMemoria(char *pchrPtrDato,
			  SiscomCampoProL *pSiscomCampoProLDat)
{
   /*free(pSiscomCampoProLDat->chrPtrDato); */
   pSiscomCampoProLDat->chrPtrDato=strdup(pchrPtrDato);
}
void SiscomAsignaCampo(const char *pchrPtrCampo,
		       const char *pchrPtrDato,
		       SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomCampoProL *lSiscomCampoProL;
     	 if((lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
	 					       pSiscomRegProLPtrDato)))
	  lSiscomCampoProL->chrPtrDato=pchrPtrDato;
	 else
	   LogSiscom("El campo %s no encontro en el registro",pchrPtrCampo);


}
void SiscomActualizaCampoAsignaMemoria2(const char *pchrPtrCampo,
					char *pchrPtrDato,
					SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomCampoProL *lSiscomCampoProL;
     	 if((lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
	 					       pSiscomRegProLPtrDato)))
	 SiscomActualizaCampoAsignaMemoria(pchrPtrDato,lSiscomCampoProL);
	 else
	   LogSiscom("El campo %s no encontro en el registro",pchrPtrCampo);

}
void SiscomActualizaCampoAsignaMemoriaRegistro(const char *pchrPtrCampo,
			  char *pchrPtrValor,
			  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomCampoProL *lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
							       pSiscomRegProLPtrDato);
     while(pSiscomRegProLPtrDato)
     {	 
     	 lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
	 					       pSiscomRegProLPtrDato);
	 SiscomActualizaCampoAsignaMemoria(pchrPtrValor,lSiscomCampoProL);
	 pSiscomRegProLPtrDato=pSiscomRegProLPtrDato->SiscomRegProLPtrSig;
     }

}
void SiscomActualizaCampo(char *pchrPtrDato,
			  SiscomCampoProL *pSiscomCampoProLDat)
{
   /*free(pSiscomCampoProLDat->chrPtrDato); */
   pSiscomCampoProLDat->chrPtrDato=pchrPtrDato;
}

void SiscomActualizaCampo2(const char *pchrPtrCampo,
			  char *pchrPtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomCampoProL *lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
							       pSiscomRegProLPtrDato);
     	 if((lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
	 					       pSiscomRegProLPtrDato)))
	 SiscomActualizaCampo(pchrPtrDato,lSiscomCampoProL);
	 else
	   LogSiscom("El campo %s no encontro en el registro",pchrPtrCampo);
}

void SiscomActualizaCampoRegistro(const char *pchrPtrCampo,
			  char *pchrPtrValor,
			  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomCampoProL *lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
							       pSiscomRegProLPtrDato);
     while(pSiscomRegProLPtrDato)
     {	 
     	 lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
	 					       pSiscomRegProLPtrDato);
	 SiscomActualizaCampo(pchrPtrValor,lSiscomCampoProL);
	 pSiscomRegProLPtrDato=pSiscomRegProLPtrDato->SiscomRegProLPtrSig;
     }

}

void SiscomActualizaCampoRegistroActual(const char *pchrPtrCampo,
			  char *pchrPtrValor,
			  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomCampoProL *lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
							       pSiscomRegProLPtrDato);
 if((lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
	 					   pSiscomRegProLPtrDato)))
	 SiscomActualizaCampoAsignaMemoria(pchrPtrValor,lSiscomCampoProL);
}

void SiscomActualizaCampoFloatRegistroActual(const char *pchrPtrCampo,
			  const char *pchrPtrFormato,
			  float pfltDato,
			  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char lchrArrFloat[58];
SiscomCampoProL *lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
							       pSiscomRegProLPtrDato);
 if(pchrPtrFormato)
  sprintf(lchrArrFloat,pchrPtrFormato,pfltDato);
  else
  sprintf(lchrArrFloat,"%f",pfltDato);
 if((lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
	 					   pSiscomRegProLPtrDato)))
	 SiscomActualizaCampoAsignaMemoria(lchrArrFloat,lSiscomCampoProL);
}



void SiscomActualizaCampoFloatRegistro(const char *pchrPtrCampo,
			  const char *pchrPtrFormato,
			  float pfltValor,
			  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char lchrArrFloat[28];
   if(pchrPtrFormato)
   sprintf(lchrArrFloat,pchrPtrFormato,pfltValor);
   SiscomActualizaCampoRegistro(pchrPtrCampo,
   			        lchrArrFloat,
				pSiscomRegProLPtrDato);
}

void SiscomActualizaCampoIntRegistroActual(const char *pchrPtrCampo,
			  int pintDato,
			  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char lchrArrFloat[58];
SiscomCampoProL *lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
							       pSiscomRegProLPtrDato);
  sprintf(lchrArrFloat,"%d",pintDato);
 if((lSiscomCampoProL=SiscomObtenCampoRegistroProL(pchrPtrCampo,
	 					   pSiscomRegProLPtrDato)))
	 SiscomActualizaCampoAsignaMemoria(lchrArrFloat,lSiscomCampoProL);
}

void SiscomIdUnicoRegistros(const char *pchrPtrCampo,
			    SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char *lchrArrIdUnico;
while(pSiscomRegProLPtrDato)
{
lchrArrIdUnico=(char *)malloc(25);
SiscomObtenNumeroUnicoChar(lchrArrIdUnico);
SiscomActualizaCampoRegistro(pchrPtrCampo,lchrArrIdUnico,pSiscomRegProLPtrDato);
pSiscomRegProLPtrDato=pSiscomRegProLPtrDato->SiscomRegProLPtrSig;
}
}


const char *SiscomAsociadoPrimerCampo(const char *pchrPtrAsociado,
				const char *pchrPtrCampo,
				SiscomRegistroProL *pSiscomRegProLPtrActual)
{
SiscomRegistroProL *lSiscomProLPtrDato;

if((lSiscomProLPtrDato=SiscomObtenRegistrosCampoProL(pchrPtrAsociado,
						     pSiscomRegProLPtrActual)))
    return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSiscomProLPtrDato);  
else
return 0;
}


const char *SiscomBuscaDatoRegistros(const char *pchrPtrAsociado,
				     const char *pchrPtrCampo,
				     const char *pchrPtrCadena,
				     const char *pchrPtrCampoRegreso,
				     SiscomRegistroProL *pSiscomRegProLPtrDatos)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrDatos=SiscomObtenRegistrosCampoProL(pchrPtrAsociado,pSiscomRegProLPtrDatos);
for(; 
     lSiscomRegProLPtrDatos;
     lSiscomRegProLPtrDatos=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrDatos))
{
 
 if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrCadena,pchrPtrCampo,lSiscomRegProLPtrDatos))
     return SiscomObtenCampoRegistroProLChar(pchrPtrCampoRegreso,lSiscomRegProLPtrDatos);

}
return 0;
}


int SiscomBuscaDatoRegistrosInt(const char *pchrPtrAsociado,
				     const char *pchrPtrCampo,
				     const char *pchrPtrCadena,
				     const char *pchrPtrCampoRegreso,
				     SiscomRegistroProL *pSiscomRegProLPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrDatos=SiscomObtenRegistrosCampoProL(pchrPtrAsociado,pSiscomRegProLPtrDatos);
for(; 
     lSiscomRegProLPtrDatos;
     lSiscomRegProLPtrDatos=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrDatos))
{
 if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrCadena,pchrPtrCampo,lSiscomRegProLPtrDatos))
     return SiscomObtenCampoRegistroProLInt(pchrPtrCampoRegreso,lSiscomRegProLPtrDatos);

}
return -65000;
}

/* Lunes 5 de enero del 2015
 * Funcion que toma el campo pchrPtrCampo, de pSiscomRegPtrLPtrDato
 * y obtienes los registros Asociados al campo pchrPtrAsociado, regresando
 * los registros ..
 */

SiscomRegistroProL *SiscomRegistrosAsociadosCampo(const char *pchrPtrCampo,
						  const char *pchrPtrAsociado,
						  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomRegistroProL *lSiscomProLPtrDato;

if((lSiscomProLPtrDato=SiscomObtenRegistrosCampoProL(pchrPtrCampo,pSiscomRegProLPtrDato)))
   return SiscomObtenRegistrosCampoProL(pchrPtrAsociado,lSiscomProLPtrDato); 
else
return 0;

}

void SiscomMultiplicaCamposACampo(const char *pchrPtrCampoA,
				  const char *pchrPtrCampoB,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char lchrArrBuffer[128];
float lfltCampoA=SiscomObtenCampoRegistroProLFloat(pchrPtrCampoA,pSiscomRegProLPtrDato),
      lfltCampoB=SiscomObtenCampoRegistroProLFloat(pchrPtrCampoB,pSiscomRegProLPtrDato),
      lfltResultado;
char lchrArrNumero[28];
lfltResultado=lfltCampoA*lfltCampoB;
if(pchrPtrCadenaFormato)
 sprintf(lchrArrNumero,pchrPtrCadenaFormato,lfltResultado);
 else
 sprintf(lchrArrNumero,"%.2f",lfltResultado);
 SiscomActualizaCampoAsignaMemoria2(pchrPtrResultado,lchrArrNumero,pSiscomRegProLPtrDato);
}

void SiscomSumaCamposACampo(const char *pchrPtrCampoA,
				  const char *pchrPtrCampoB,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char lchrArrBuffer[128];
float lfltCampoA=SiscomObtenCampoRegistroProLFloat(pchrPtrCampoA,pSiscomRegProLPtrDato),
      lfltCampoB=SiscomObtenCampoRegistroProLFloat(pchrPtrCampoB,pSiscomRegProLPtrDato),
      lfltResultado;
char lchrArrNumero[28];
lfltResultado=lfltCampoA+lfltCampoB;
if(pchrPtrCadenaFormato)
 sprintf(lchrArrNumero,pchrPtrCadenaFormato,lfltResultado);
 else
 sprintf(lchrArrNumero,"%.2f",lfltResultado);
 SiscomActualizaCampoAsignaMemoria2(pchrPtrResultado,lchrArrNumero,pSiscomRegProLPtrDato);
}


void SiscomMultiplicaCampoPorDato(const char *pchrPtrCampo,
				  float pfltDato,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
float lfltResultado;
char lchrArrNumero[28];
lfltResultado=pfltDato*SiscomObtenCampoRegistroProLFloat(pchrPtrCampo,pSiscomRegProLPtrDato);
if(pchrPtrCadenaFormato)
sprintf(lchrArrNumero,pchrPtrCadenaFormato,lfltResultado);
else
sprintf(lchrArrNumero,"%.2f",lfltResultado);
SiscomActualizaCampoAsignaMemoria2(pchrPtrResultado,lchrArrNumero,pSiscomRegProLPtrDato);
}

void SiscomSumaCampoPorDato(const char *pchrPtrCampo,
				  float pfltDato,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
float lfltResultado;
char lchrArrNumero[28];
lfltResultado=pfltDato+SiscomObtenCampoRegistroProLFloat(pchrPtrCampo,pSiscomRegProLPtrDato);
if(pchrPtrCadenaFormato)
sprintf(lchrArrNumero,pchrPtrCadenaFormato,lfltResultado);
else
sprintf(lchrArrNumero,"%.2f",lfltResultado);
SiscomActualizaCampoAsignaMemoria2(pchrPtrResultado,lchrArrNumero,pSiscomRegProLPtrDato);
}


void SiscomDivideCampoPorDato(const char *pchrPtrCampo,
				  float pfltDato,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato)
{
float lfltResultado;
char lchrArrNumero[28];
lfltResultado=pfltDato/SiscomObtenCampoRegistroProLFloat(pchrPtrCampo,pSiscomRegProLPtrDato);
if(pchrPtrCadenaFormato)
sprintf(lchrArrNumero,pchrPtrCadenaFormato,lfltResultado);
else
sprintf(lchrArrNumero,"%.2f",lfltResultado);
SiscomActualizaCampoAsignaMemoria2(pchrPtrResultado,lchrArrNumero,pSiscomRegProLPtrDato);
}
void SiscomMultiplicaCamposACampoRegistros(const char *pchrPtrCampoA,
					   const char *pchrPtrCampoB,
					   const char *pchrPtrResultado,
					   const char *pchrPtrFormato,
					   SiscomRegistroProL *pSiscomRegProLPtrDato)
{

for(;
     pSiscomRegProLPtrDato;
     pSiscomRegProLPtrDato=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrDato))
SiscomMultiplicaCamposACampo(pchrPtrCampoA,
			     pchrPtrCampoB,
			     pchrPtrResultado,
			     pchrPtrFormato,
			     pSiscomRegProLPtrDato);
}

float SiscomObtenSumatoriaRegistros(const char *pchrPtrCampo,
				    SiscomRegistroProL *pSiscomRegProLPtrDato)
{
float lfltSumatoria=0.0;
for(;
    pSiscomRegProLPtrDato;
    pSiscomRegProLPtrDato=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrDato))
   lfltSumatoria+=SiscomObtenCampoRegistroProLFloat(pchrPtrCampo,pSiscomRegProLPtrDato);
return lfltSumatoria;
}

void SiscomAsignaFechaHoraCampo(const char *pchrPtrCampo,
			   SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char lchrArrFechaHora[35];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
SiscomActualizaCampoAsignaMemoria2(pchrPtrCampo,
				   lchrArrFechaHora,
				   pSiscomRegProLPtrDato);
}

void SiscomAsignaFechaCampo(const char *pchrPtrCampo,
			   SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char lchrArrFecha[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomActualizaCampoAsignaMemoria2(pchrPtrCampo,
				   lchrArrFecha,
				   pSiscomRegProLPtrDato);
}

SiscomRegistroProL *SiscomContadorRegistrosProL(const char *pchrPtrCampo,
                SiscomRegistroProL *pSiscomRegProLPtrDat)
{
    SiscomRegistroProL *lSiscomRegProLPtrDatosPrim=0,
                       *lSiscomRegProLPtrDatosAct=0;
    
    return lSiscomRegProLPtrDatosPrim;
}

void SiscomEliminaNodoPro(SiscomRegistroProL *pSisRegProLPtrLista,
                SiscomRegistroProL *pSisRegProLPtrElimina)
{
SiscomRegistroProL *lSisRegProLPtrListaAnt;

  for(;
  	pSisRegProLPtrLista;
	pSisRegProLPtrLista=pSisRegProLPtrLista->SiscomRegProLPtrSig)
  {
     if(pSisRegProLPtrLista==pSisRegProLPtrElimina)
         lSisRegProLPtrListaAnt->SiscomRegProLPtrSig=pSisRegProLPtrLista->SiscomRegProLPtrSig; 
      lSisRegProLPtrListaAnt=pSisRegProLPtrLista;
  }
}
/* Queretaro a Lunes 14 de Marzo del 2016
 * Se agrega el encabezado en el que va la
 * version del protocolo, esto se implemento
 * para poder integrar el sistema de Siscom Electronica
 * a la nueva version ...
 */
int SiscomVersionProtocolo4(int pintSocket)
{
char lchrArrVersionProtocolo[16];
char lchrArrVersion[6];
SiscomLeeCaracteresSocket(pintSocket,15,lchrArrVersionProtocolo);
strncpy(lchrArrVersion,lchrArrVersionProtocolo,5);
lchrArrVersion[5]=0;
return atoi(lchrArrVersion);
}



int SiscomEstaElCampo4(const char *pchrPtrCampo,
		      SiscomRegistroProL *pSiscomRegProLPtrDat)
{
return SiscomObtenCampoRegistroProL(pchrPtrCampo,pSiscomRegProLPtrDat) ? 1 :0 ;
}

void SiscomCambiaAMayusculas(const char *pchrPtrCampo,SiscomRegistroProL *pSiscomRegProLPtrDat)
{
char *lchrPtrCampo=(char *)SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrDat);
SiscomAMayusculas(lchrPtrCampo);
}

void SiscomEliminaEspaciosFinalCampo(const char *pchrPtrCampo,
				     SiscomRegistroProL  *pSiscomRegProLPtrDato)
{
char *lchrPtrCampo=(char *)SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrDato);
if(lchrPtrCampo)
SiscomEliminaEspaciosFinal(lchrPtrCampo);

}

SiscomCampoProL *SiscomFormaRegistroAgrupado(char **pchrPtrCamposRegistroAgrupado,
					     const char *pchrPtrCampoAsociado,
					     SiscomRegistroProL *pSiscomRegProLPtrEntrada)
{
SiscomCampoProL *lSiscomCampoProLPtrPrim=0,
		*lSiscomCampoProLPtrAct=0;
const char *lchrPtrContenido;
  while(*pchrPtrCamposRegistroAgrupado)
  {
     lchrPtrContenido=SiscomObtenCampoRegistroProLChar(*pchrPtrCamposRegistroAgrupado,pSiscomRegProLPtrEntrada);
     SiscomNodoCampoPro2(*pchrPtrCamposRegistroAgrupado,
     			 lchrPtrContenido,
			 &lSiscomCampoProLPtrPrim,
			 &lSiscomCampoProLPtrAct);
    pchrPtrCamposRegistroAgrupado++;
  }
 if(pchrPtrCampoAsociado)
 SiscomNodoCampoPro2(pchrPtrCampoAsociado,
 		     0,
		     &lSiscomCampoProLPtrPrim,
		     &lSiscomCampoProLPtrAct);
return lSiscomCampoProLPtrPrim;
}
				 
void SiscomAgrupaPorCampo(const char *pchrPtrCampo,
			  const char *pchrPtrNombreAsociado,
			  char **pchrPtrCamposRegistroAgrupado,
			  char **pchrPtrCamposRegistros,
			  SiscomRegistroProL *pSiscomRegProLPtrEntrada,
			  SiscomRegistroProL **pSiscomRegProLPtrPrimAgrupado,
			  SiscomRegistroProL **pSiscomRegProLPtrActAgrupado)
{
char lchrArrBuffer[512];
const char *lchrPtrContenidoCampo;
SiscomRegistroProL *lSiscomRegProLPtrEntrada,
		   *lSiscomRegProLPtrRecorriendo,
		   *lSiscomRegProLPtrRecorriendoAnterior,
		   *lSiscomRegProLPtrDatoAgrupadoPrim=0,
		   *lSiscomRegProLPtrDatoAgrupadoAct=0;
SiscomCampoProL *lSiscomCamProLPtrAgrupado,
		*lSiscomCamProLPtrProducto;
for(lSiscomRegProLPtrEntrada=pSiscomRegProLPtrEntrada;
    lSiscomRegProLPtrEntrada;
    lSiscomRegProLPtrEntrada=lSiscomRegProLPtrEntrada->SiscomRegProLPtrSig)
{
   lSiscomCamProLPtrAgrupado=SiscomFormaRegistroAgrupado(pchrPtrCamposRegistroAgrupado,
   						        pchrPtrNombreAsociado,
							lSiscomRegProLPtrEntrada);
   SiscomNodoRegistroPro(lSiscomCamProLPtrAgrupado,
   			 pSiscomRegProLPtrPrimAgrupado,
			 pSiscomRegProLPtrActAgrupado);
   lchrPtrContenidoCampo=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSiscomRegProLPtrEntrada);
  for(lSiscomRegProLPtrRecorriendo=lSiscomRegProLPtrEntrada;
      lSiscomRegProLPtrRecorriendo &&
      !SiscomComparaCadenaCampoRegistroProL(lchrPtrContenidoCampo,pchrPtrCampo, lSiscomRegProLPtrRecorriendo);
      lSiscomRegProLPtrRecorriendo=lSiscomRegProLPtrRecorriendo->SiscomRegProLPtrSig)
 {
    lSiscomCamProLPtrProducto=SiscomFormaRegistroAgrupado(pchrPtrCamposRegistros,0,lSiscomRegProLPtrRecorriendo);
    SiscomNodoRegistroPro(lSiscomCamProLPtrProducto,
    			  &lSiscomRegProLPtrDatoAgrupadoPrim,
			  &lSiscomRegProLPtrDatoAgrupadoAct);
   lSiscomRegProLPtrRecorriendoAnterior=lSiscomRegProLPtrRecorriendo;
 }
   SiscomRegistrosAlCampo(pchrPtrNombreAsociado,
   			  lSiscomRegProLPtrDatoAgrupadoPrim,
			  lSiscomRegProLPtrDatoAgrupadoAct,
			  *pSiscomRegProLPtrActAgrupado);
  lSiscomRegProLPtrDatoAgrupadoPrim=0;
  lSiscomRegProLPtrDatoAgrupadoAct=0;
  lSiscomRegProLPtrEntrada=lSiscomRegProLPtrRecorriendoAnterior;
}
}

/* Domingo 14 de agosto 2016 
 * Se agrega la funcion para buscar un registro por campo y su contenido
 * La funciona genera un solo Registro con esta informacion , que 
 * sera el que regrese;
 */

SiscomRegistroProL *SiscomBuscaRegistroLista(const char *pchrPtrCampo,
					     const char *pchrPtrValor,
					     SiscomRegistroProL *pSiscomRegProLPtrLista)
{
SiscomRegistroProL *lSiscomRegProLPtrPrimReg=0,
		   *lSiscomRegProLPtrActReg=0;
	for(;
	    pSiscomRegProLPtrLista;
	    pSiscomRegProLPtrLista=pSiscomRegProLPtrLista->SiscomRegProLPtrSig)
	{
	   if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrValor,
	   					   pchrPtrCampo,
						   pSiscomRegProLPtrLista))
	   {
	     LogSiscom("----- Falta aqui algo ");
	     /*
	       SiscomAnexaRegistroPro2(&lSiscomRegProLPtrPrimReg,
	       			       &lSiscomRegProLPtrActReg,
				       pSiscomRegProLPtrLista);

	       */
		return lSiscomRegProLPtrPrimReg;
	   }
	}
return 0;
}
void SiscomOrdenaRegistroProL(const char *pchrPtrCampo,
			      SiscomRegistroProL *pSiscomRegProLPtrEntrada,
			      SiscomRegistroProL **pSiscomRegProLPtrSalPrim,
			      SiscomRegistroProL **pSiscomRegProLPtrSalAct)
{
SiscomRegistroProL **lSiscomRegProLPtrMatriz,
		    *lSiscomRegProLPtrTemp;
int lintContadorI,lintContador,lintNRegistros;

lSiscomRegProLPtrMatriz=(SiscomRegistroProL **)malloc(sizeof(SiscomRegistroProL *)*(
						     pSiscomRegProLPtrEntrada->intNRegistros+1));
for(lintContador=0;
    pSiscomRegProLPtrEntrada;
    lintContador++,
    pSiscomRegProLPtrEntrada=pSiscomRegProLPtrEntrada->SiscomRegProLPtrSig)
{
*(lSiscomRegProLPtrMatriz+lintContador)=(SiscomRegistroProL *)malloc(sizeof(SiscomRegistroProL));
*(*(lSiscomRegProLPtrMatriz+lintContador))=*pSiscomRegProLPtrEntrada;
}



lintNRegistros=lintContador;
for(lintContador=0;
    lintContador<lintNRegistros;
    lintContador++)
for(lintContadorI=0;
    lintContadorI<lintNRegistros-1;
    lintContadorI++)
 if(SiscomComparaCampoRegistrosProL(pchrPtrCampo,
 			       *(lSiscomRegProLPtrMatriz+lintContador),
			       *(lSiscomRegProLPtrMatriz+lintContadorI))<0)
{
   lSiscomRegProLPtrTemp=*(lSiscomRegProLPtrMatriz+lintContador);
   *(lSiscomRegProLPtrMatriz+lintContador)=*(lSiscomRegProLPtrMatriz+lintContadorI);
   *(lSiscomRegProLPtrMatriz+lintContadorI)=lSiscomRegProLPtrTemp;
}
for(lintContador=0;
    lintContador<lintNRegistros;
    lintContador++)
{
 SiscomNodoRegistroPro((*(lSiscomRegProLPtrMatriz+lintContador))->SiscomCamProLPtrDato,
 		       pSiscomRegProLPtrSalPrim,
		       pSiscomRegProLPtrSalAct);
free(*(lSiscomRegProLPtrMatriz+lintContador));   
}
}

SiscomRegistroProL *SiscomUltimoNodoLista(SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrAnt;
for(;
     pSiscomRegProLPtrDato;
     pSiscomRegProLPtrDato=pSiscomRegProLPtrDato->SiscomRegProLPtrSig)
   lSiscomRegProLPtrAnt=pSiscomRegProLPtrDato;
return lSiscomRegProLPtrAnt;
}
