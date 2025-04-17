#include <SiscomManejoLog.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomServidor.h>
#include <SiscomDesarrolloMacros.h>
#include <stdarg.h>
#include <string.h>
void SiscomMensajesLog4(const char *pchrPtrArchivo,
			 const char *pchrPtrFuncion,
			 int pintNoLinea,
			 char *pzCadenaFormato,
			 ...)
 {
 va_list lzArgumentos;
 char *lzCadenaFormato=pzCadenaFormato;
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
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                                int);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%x",
                                         lzMen,
                                         liParametroInt);
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
        fflush(gPtrFleArchivoLog);
        va_end(lzArgumentos);
}

void SiscomArregloCadenasLog(const char *pchrPtrArchivo,
			     const char *pchrPtrFuncion,
			     int pintNoLinea,
			     char **pchrPtrCadenas)
{
int lintContador=0;
while(*pchrPtrCadenas)
{
  SiscomMensajesLog4(pchrPtrArchivo,
  		    pchrPtrFuncion,
		    pintNoLinea,
		    "%d.- %s",
		    lintContador,
		    *pchrPtrCadenas);
   lintContador++;
   pchrPtrCadenas++;


}


}


void SiscomVariablesIniLog(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   const SiscomVariablesIniL *pSiscomVILPtrDatos)
{
    while(pSiscomVILPtrDatos)
    {
       SiscomMensajesLog4(pchrPtrArchivo,
       			 pchrPtrFuncion,
			 pintNLinea,
			 "%s=%s",
			 pSiscomVILPtrDatos->SiscomVIni.chrArrNombre,
			 pSiscomVILPtrDatos->SiscomVIni.chrArrDato);
	pSiscomVILPtrDatos=(const SiscomVariablesIniL *)pSiscomVILPtrDatos->SiscomVIniLPtrSig;
     }
	

}

void SiscomVariablesArregloIniLog(const char *pchrPtrArchivo,
				  const char *pchrPtrFuncion,
				  int pintNLinea,
				  const SiscomVariableIniArregloL *pSiscomVIALPtrDato)
{
while(pSiscomVIALPtrDato)
{
  SiscomMensajesLog4(pchrPtrArchivo,
  		    pchrPtrFuncion,
		    pintNLinea,
		    "Arreglo(%s)",
		    pSiscomVIALPtrDato->chrArrNombre);
  SiscomVariablesIniLog(pchrPtrArchivo,
  			pchrPtrFuncion,
			pintNLinea,
			pSiscomVIALPtrDato->SiscomVILPtrDatos);
  pSiscomVIALPtrDato=pSiscomVIALPtrDato->SiscomVIAPtrSig;
}
}

void SiscomMuestraCamposProtocolo(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   const SiscomCampoProL *pSiscomCamProLPtrDato)
{
	while(pSiscomCamProLPtrDato)
	{
	   SiscomMensajesLog4(pchrPtrArchivo,
	   		     pchrPtrFuncion,
			     pintNLinea,
			     "Campo(%s)=Dato(%s)",
			     pSiscomCamProLPtrDato->chrPtrNmbCampo,
			     pSiscomCamProLPtrDato->chrPtrDato ? 
			     pSiscomCamProLPtrDato->chrPtrDato : "");
	   pSiscomCamProLPtrDato=pSiscomCamProLPtrDato->SiscomCamProLPtrSig;
	}
}
void SiscomMuestraCamposProtocolo2(const char *pchrPtrArchivo,
				   const char *pchrPtrFuncion,
				   int pintNLinea,
				   const SiscomRegistroProL *pSiscomRegProLPtrDat)
{
SiscomMuestraCamposProtocolo(pchrPtrArchivo,
			     pchrPtrFuncion,
			     pintNLinea,
			     pSiscomRegProLPtrDat->SiscomCamProLPtrDato);

}

void SiscomMuestraRegistrosProtocolo(const char *pchrPtrArchivo,
			      const char *pchrPtrFuncion,
			      int pintNLinea,
			      char *pchrPtrBuffer,
			      const SiscomRegistroProL *pSiscomRegProLPtrDat)
{
if(pSiscomRegProLPtrDat)
{
SiscomFormaEncabezadoRegistroLog(pSiscomRegProLPtrDat->SiscomCamProLPtrDato,
		      pchrPtrBuffer);
SiscomMensajesLog4(pchrPtrArchivo,
		   pchrPtrFuncion,
		   pintNLinea,
		   "Se tienen %d Registros",
		   pSiscomRegProLPtrDat->intNRegistros);
SiscomMensajesLog4(pchrPtrArchivo,
		  pchrPtrFuncion,
		  pintNLinea,
		  "%s",
		  pchrPtrBuffer);
while(pSiscomRegProLPtrDat)
{
SiscomFormaRegistroADesplegarLog(pSiscomRegProLPtrDat->SiscomCamProLPtrDato,
				 pchrPtrBuffer);
SiscomMensajesLog4(pchrPtrArchivo,
		  pchrPtrFuncion,
		  pintNLinea,
		  "%s",
		  pchrPtrBuffer);
pSiscomRegProLPtrDat=pSiscomRegProLPtrDat->SiscomRegProLPtrSig;
}
}
else
SiscomMensajesLog4(pchrPtrArchivo,pchrPtrFuncion,pintNLinea,"%s","Lista NULA");

}
void SiscomFormaRegistroADesplegarLog(
	const SiscomCampoProL *pSiscomCamProLPtrDato,
	char *pchrPtrBuffer)
{
char lchrArrPaso[256];
*pchrPtrBuffer=0;
 while(pSiscomCamProLPtrDato)
 {
   if(pSiscomCamProLPtrDato->SiscomCamProLPtrSig)
   sprintf(lchrArrPaso,
   	   "%s|",
	   SiscomObtenDatoValido(pSiscomCamProLPtrDato->chrPtrDato));
   else
   sprintf(lchrArrPaso,
   	   "%s",
	   SiscomObtenDatoValido(pSiscomCamProLPtrDato->chrPtrDato));
  strcat(pchrPtrBuffer,lchrArrPaso); 
  pSiscomCamProLPtrDato=pSiscomCamProLPtrDato->SiscomCamProLPtrSig;
 }

}
void SiscomFormaEncabezadoRegistroLog(
		const SiscomCampoProL *pSiscomCamProLPtrDato,
		char *pchrPtrBuffer)
{
char lchrArrPaso[512];
*pchrPtrBuffer=0;
 while(pSiscomCamProLPtrDato)
 {
   if(pSiscomCamProLPtrDato->SiscomCamProLPtrSig)
   sprintf(lchrArrPaso,"%s|",pSiscomCamProLPtrDato->chrPtrNmbCampo);
   else
   sprintf(lchrArrPaso,"%s",pSiscomCamProLPtrDato->chrPtrNmbCampo);
  strcat(pchrPtrBuffer,lchrArrPaso); 
  pSiscomCamProLPtrDato=pSiscomCamProLPtrDato->SiscomCamProLPtrSig;
 }
}
void SiscomMuestraRegistrosAsociados(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNoLinea,
				     char *pchrPtrBuffer,
				     const char *pchrPtrCampo,
				     SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomRegistroProL *lSiscomProLPtrDat;
if((lSiscomProLPtrDat=SiscomObtenRegistrosCampoProL(pchrPtrCampo,pSiscomRegProLPtrAct)))
  SiscomMuestraRegistrosProtocolo(pchrPtrArchivo,
  				  pchrPtrFuncion,
				  pintNoLinea,
				  pchrPtrBuffer,
				  lSiscomProLPtrDat);
else
SiscomMensajesLog4(pchrPtrArchivo,
		  pchrPtrFuncion,
		  pintNoLinea,
		  "NO se encontro el campo:(%s)",
		  pchrPtrCampo);
}


void SiscomSocketProtocolo(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNoLinea,
			   const char *pzCadenaFormato,
			   ...)
 {
if(gintSocketProtocoloLog) 
{
 va_list lzArgumentos;
 char *lzCadenaFormato=(char *)pzCadenaFormato;
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
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                                int);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%x",
                                         lzMen,
                                         liParametroInt);
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
}


void SiscomAsignaArchivoLog(FILE *pFlePtrArchivoLog)
{
}
