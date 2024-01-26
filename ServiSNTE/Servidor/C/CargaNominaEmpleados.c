#include <CargaNominaEmpleados.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomRecibeArchivo.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomOperaciones.h>
/*
#include <SqlCargaNominaEmpleados.h>

*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void CargaNominaEmpleados(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);

SiscomAgregaOperacion(RecibeArchivoNomina,&lSiscomProDat);
SiscomAgregaOperacion(EscribeArchivoNomina,&lSiscomProDat);

SiscomAgregaOperacion(ProcesaNomina,&lSiscomProDat);
SiscomAgregaOperacion(EnviaNominaEmpleados,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviaNominaEmpleados(SiscomOperaciones *pSiscomOpePtrDat)
{
/*
char lchrArrBuffer[1024];
if(SiscomObtenRegistrosCampoRespuesta("NominaEmpleados",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("NominaEmpleados",pSiscomOpePtrDat));
else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
*/
/*SiscomRegistrosAsociadosLog(lchrArrBuffer,"NominaEmpleados",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes); */
}

int RecibeArchivoNomina(SiscomOperaciones *pSiscomOpePtrDat)
{
SiscomBloqueArchivoL *lSiscomBloArLArchivo=0;
SiscomRecibeArchivo(pSiscomOpePtrDat->intSocket,&lSiscomBloArLArchivo);
pSiscomOpePtrDat->SiscomBloArLArchivo=lSiscomBloArLArchivo;
}
const char *ObtenNombre(const char *pchrPtrArchivo)
{
const char *lchrPtrPaso;
int lintTamano=strlen(pchrPtrArchivo);
lchrPtrPaso=pchrPtrArchivo+lintTamano-1;
    while(*lchrPtrPaso!='/')
    lchrPtrPaso--;
return ++lchrPtrPaso;
}
void NombreArchivo(const char *pchrPtrArchivo,
		   char *pchrPtrArchivoSalida)
{
const char *lchrPtrArchivo=ObtenNombre(pchrPtrArchivo);
const char *lchrPtrDirectorio=getenv("ArchivosNomina");
sprintf(pchrPtrArchivoSalida,"%s/%s",lchrPtrDirectorio,lchrPtrArchivo);
}
int AbreArchivoNomina(const char *pchrPtrArchivo,
		       FILE **pFlePtrArchivo)
{

if((*pFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
   return 1;
else
{
LogSiscom("No se encontro el archivo :%s",
	  pchrPtrArchivo);
return 0;
}

}
int EscribeArchivoNomina(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrArchivoSalida[1024];
const char *lchrPtrNombre=SiscomCampoAsociadoEntradaOperacion("Envio",
							      "Archivo",
							      pSiscomOpePtrDat);
NombreArchivo(lchrPtrNombre,lchrArrArchivoSalida);
SiscomEscribeArchivoSocket(lchrArrArchivoSalida,pSiscomOpePtrDat->SiscomBloArLArchivo);


}


void MuestraMaestros(SiscomRegistroProL *pSiscomRegProLPtrDatos)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrDeducciones,
		   *lSiscomRegProLPtrPercepciones;
for(;
     pSiscomRegProLPtrDatos;
     pSiscomRegProLPtrDatos=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrDatos))
{
  LogSiscom("Maestro %s No Empleado %s",
  	   SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrDatos),
	   SiscomObtenCampoRegistroProLChar("NoEmpleado",pSiscomRegProLPtrDatos));
  lSiscomRegProLPtrDeducciones=SiscomObtenRegistrosCampoProL("PERs",pSiscomRegProLPtrDatos);
  lSiscomRegProLPtrPercepciones=SiscomObtenRegistrosCampoProL("DEDs",pSiscomRegProLPtrDatos);
  SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrDeducciones);
  SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPercepciones);
}

}
int ProcesaNomina(SiscomOperaciones *pSiscomOpePtrDat)
{
    char lchrArrArchivoSalida[1024],lchrArrBuffer[256];
    FILE *lFltPtrArchivo;
    SiscomRegistroProL *lSiscomRegProLPtrMaestrosPrim=0,
		   *lSiscomRegProLPtrMaestrosAct=0;
    const char *lchrPtrNombre=SiscomCampoAsociadoEntradaOperacion("Envio",
							      "Archivo",
							      pSiscomOpePtrDat);
    NombreArchivo(lchrPtrNombre,lchrArrArchivoSalida);
    LogSiscom("El Archivo a Analizar:%s",lchrArrArchivoSalida);
    LogSiscom("Procesando el archivo");



    AbreArchivoNomina(lchrArrArchivoSalida,&lFltPtrArchivo);
     
    ObtenDatosArchivoMaestros(lFltPtrArchivo,
      		 &lSiscomRegProLPtrMaestrosPrim,
      		 &lSiscomRegProLPtrMaestrosAct);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrMaestrosPrim);

MuestraMaestros(lSiscomRegProLPtrMaestrosPrim);
    //Cerrar archivo.
}

void ObtenDatosGeneralesMaestro(FILE *pFlePtrArchivo,
				char *pchrPtrNombre,
				char *pchrPtrAMaterno,
				char *pchrPtrAPaterno)
{
    char lchrArrLinea[1024];
	
    SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);
    LogSiscom("%s",lchrArrLinea);

}

void ObtenDatosArchivoMaestros(FILE *pFltPtrArchivo,
		SiscomRegistroProL **pSiscomRegProLPtrMaestrosPrim, 
		SiscomRegistroProL **pSiscomRegProLPtrMaestrosAct)
{
    SiscomRegistroProL *lSiscomRegProLPtrPercepcionesPrim=0,
                       *lSiscomRegProLPtrPercepcionesAct=0,
                       *lSiscomRegProLPtrDeduccionesPrim=0,
                       *lSiscomRegProLPtrDeduccionesAct=0;
    char lchrArrBuffer[256];
    char lchrArrNombre [28],
	     lchrArrAPaterno[28],
	     lchrArrAMaterno[28],
         lchrArrRFC[28],
         lchrArrNoEmpleado[28];
    char buf[145],
         bufAux[145],
         ctPercepcion1[3],
         ctPercepcion2[3],
         ctDeduccion1[3],
         ctDeduccion2[3];
    int *ubidots;
    int linea = 0;
    int contador = 0;
    
    //Aquí contamos el número de registros.
    while (fgets(buf, sizeof buf, pFltPtrArchivo) != NULL){
        if(rfc_regex(buf) >= 0){
            contador++;
        }
    }
    LogSiscom("Coincidencias: %d\n", contador);
    ubidots = (int*) malloc((contador+1)*sizeof(int));
    int *ptr = ubidots;
    //Aquí leemos nuevamente el archivo y guardamos referencias a lineas especificas del mismo.
    fseek(pFltPtrArchivo,0,SEEK_SET);
    linea = contador = 0;
    while (fgets(buf, sizeof buf, pFltPtrArchivo) != NULL){
        if(rfc_regex(buf) >= 0){
            ubidots[contador] = linea-1;
            contador++;
        }
        linea++;
    }
    ubidots[contador] = 0;

    linea = 0;
    ptr = ubidots;
    fseek(pFltPtrArchivo,0,SEEK_SET);
    while (fgets(buf, sizeof buf, pFltPtrArchivo) != NULL){
        if(linea == *ptr){
            ptr++;
            subString(bufAux, buf, 1, 30);
            normalizarNombrePropio(bufAux,lchrArrNombre,lchrArrAPaterno,lchrArrAMaterno);

            subString(ctPercepcion1, buf, 49, 50);
            subString(ctPercepcion2, buf, 71, 72);
            subString(ctDeduccion1, buf, 93, 94);
            subString(ctDeduccion2, buf, 115, 116);
            fgets(buf, sizeof buf, pFltPtrArchivo);
            subString(lchrArrRFC, buf, 1, 13);
            if( buf[24] == ' ') subString(lchrArrNoEmpleado, buf, 25, 38);
            else subString(lchrArrNoEmpleado, buf, 24, 38);

            //Aquí vienen los CT
            lSiscomRegProLPtrPercepcionesPrim=0;
            lSiscomRegProLPtrPercepcionesAct=0;
            lSiscomRegProLPtrDeduccionesPrim=0;
            lSiscomRegProLPtrDeduccionesAct=0;
            SiscomAnexaRegistroPro(&lSiscomRegProLPtrPercepcionesPrim,
  			    &lSiscomRegProLPtrPercepcionesAct,
			    lchrArrBuffer,
			    "id,Percepcion,",
			    "",
                ctPercepcion1);
            SiscomAnexaRegistroPro(&lSiscomRegProLPtrPercepcionesPrim,
  			    &lSiscomRegProLPtrPercepcionesAct,
			    lchrArrBuffer,
			    "id,Percepcion,",
			    "",
                ctPercepcion2);
            SiscomAnexaRegistroPro(&lSiscomRegProLPtrDeduccionesPrim,
  			    &lSiscomRegProLPtrDeduccionesAct,
			    lchrArrBuffer,
			    "id,Deduccion,",
			    "",
                ctDeduccion1);
            SiscomAnexaRegistroPro(&lSiscomRegProLPtrDeduccionesPrim,
  			    &lSiscomRegProLPtrDeduccionesAct,
			    lchrArrBuffer,
			    "id,Deduccion,",
			    "",
                ctDeduccion2);
            //Iterador de CT´s
            fgets(buf, sizeof buf, pFltPtrArchivo);
            linea++;
            while(strlen(buf) > 50){    //Verificamos que haya caracteres por leer
                subString(ctPercepcion1, buf, 49, 50);
                subString(ctPercepcion2, buf, 71, 72);
                subString(ctDeduccion1, buf, 93, 94);
                subString(ctDeduccion2, buf, 115, 116);
                if(ctPercepcion1[0]!=' ')
                {
            SiscomAnexaRegistroPro(&lSiscomRegProLPtrPercepcionesPrim,
  			    &lSiscomRegProLPtrPercepcionesAct,
			    lchrArrBuffer,
			    "id,Percepcion,",
			    "",
                ctPercepcion1);
                }
                if(ctPercepcion2[0]!=' ')
                { 
            SiscomAnexaRegistroPro(&lSiscomRegProLPtrPercepcionesPrim,
  			    &lSiscomRegProLPtrPercepcionesAct,
			    lchrArrBuffer,
			    "id,Percepcion,",
			    "",
                ctPercepcion2);
                }
                if(ctDeduccion1[0]!=' ')
                {
            SiscomAnexaRegistroPro(&lSiscomRegProLPtrDeduccionesPrim,
  			    &lSiscomRegProLPtrDeduccionesAct,
			    lchrArrBuffer,
			    "id,Deduccion,",
			    "",
                ctDeduccion1);
                }
                if(ctDeduccion2[0]!=' ')
                {
            SiscomAnexaRegistroPro(&lSiscomRegProLPtrDeduccionesPrim,
  			    &lSiscomRegProLPtrDeduccionesAct,
			    lchrArrBuffer,
			    "id,Deduccion,",
			    "",
                ctDeduccion2);
                }
                fgets(buf, sizeof buf, pFltPtrArchivo);
                linea++;
            }
            linea++;
            //Limpiamos resto de precepciones y deducciones
            
            SiscomAnexaRegistroPro(
                pSiscomRegProLPtrMaestrosPrim,
  			    pSiscomRegProLPtrMaestrosAct,
			    lchrArrBuffer,
			    "Nombre,APaterno,AMaterno,RFC,NoEmpleado,PERs,DEDs,",
			    lchrArrNombre,
			    lchrArrAPaterno,
			    lchrArrAMaterno,
			    lchrArrRFC,
			    lchrArrNoEmpleado,
			    (char *)0,
			    (char *)0);
            SiscomRegistrosAlCampo((const char *)"PERs" ,
		           lSiscomRegProLPtrPercepcionesPrim,
			   lSiscomRegProLPtrPercepcionesAct ,
			    *pSiscomRegProLPtrMaestrosAct);
            SiscomRegistrosAlCampo((const char *)"DEDs" ,
		           lSiscomRegProLPtrDeduccionesPrim,
			   lSiscomRegProLPtrDeduccionesAct ,
			    *pSiscomRegProLPtrMaestrosAct);
        }
        linea++;
    }
    free(ubidots);
    //fclose(pFltPtrArchivo);
    //ObtenDatosGeneralesMaestro(pFltPtrArchivo,lchrArrNombre,lchrArrAPaterno,lchrArrAMaterno);
	///ObtenDeducciones();
LogSiscom("--------------");
}

int rfc_regex( char *ptr)
{
    // Expresion regular: "[a-zA-Z]{4}[0-9]{6}"
    estados edo = q0;
    while(*ptr)
    {
        switch(edo)
        {
            case q0: if(((*ptr>='a')&&(*ptr<='z'))||((*ptr>='A')&&(*ptr<='Z'))) edo = q1;
                     else edo = q0;
                break;
            case q1: if(((*ptr>='a')&&(*ptr<='z'))||((*ptr>='A')&&(*ptr<='Z'))) edo = q2;
                     else edo = q0;
                break;
            case q2: if(((*ptr>='a')&&(*ptr<='z'))||((*ptr>='A')&&(*ptr<='Z'))) edo = q3;
                     else edo = q0;
                break;
            case q3: if(((*ptr>='a')&&(*ptr<='z'))||((*ptr>='A')&&(*ptr<='Z'))) edo = q4;
                     else edo = q0;
                break;
            case q4: if((*ptr>='0')&&(*ptr<='9')) edo = q5;
                     else edo = q0;
                break;
            case q5: if((*ptr>='0')&&(*ptr<='9')) edo = q6;
                     else edo = q0;
                break;
            case q6: if((*ptr>='0')&&(*ptr<='9')) edo = q7;
                     else edo = q0;
                break;
            case q7: if((*ptr>='0')&&(*ptr<='9')) edo = q8;
                     else edo = q0;
                break;
            case q8: if((*ptr>='0')&&(*ptr<='9')) edo = q9;
                     else edo = q0;
                break;
            case q9: if((*ptr>='0')&&(*ptr<='9')) return 0;
                     else edo = q0;
                break;
        }
        //printf("Caracter: %c - estado: %d\n",*ptr,edo);
        ptr++;
    }
    return -1;
}

int subString(char * destino, const char * fuente, unsigned int charIni, unsigned int charFin)
{
    unsigned int cont = 0;
    if(charIni > charFin) { //Indices fuera de lógica
        *destino = '\0';
        return -1;
    } else if(charFin > strlen(fuente)){
        charFin = strlen(fuente);
    }
    fuente += charIni;  //Offset donde inicia la cadena deseada.
    for (cont = charIni; cont <= charFin; cont++, destino++, fuente++)
    {
        *destino = *fuente;
    }
    *destino = '\0';    //Final de cadena.
    return 0;
}

void normalizarNombrePropio(char *pNombre, char *pChrNombre, char *pChrAPaterno, char *pChrAMaterno)
{
    char flagIniciaPalabra = 1;
    char *ptrAux = pNombre;
    char *ptrOffSet;
    int seek, estado, antSeek;
    //Todo a minusculas
    while(*pNombre)
    {
        if((*pNombre>='A')&&(*pNombre<='Z')) (*pNombre)+=32;
        pNombre++;
    }
    pNombre = ptrAux;
    //Iniciales a mayusculas
    while(*pNombre)
    {
        if((flagIniciaPalabra==1)&&(*pNombre>='a')&&(*pNombre<='z')) *pNombre-=32, flagIniciaPalabra=0;
        if(*pNombre==' ') flagIniciaPalabra=1;
        pNombre++;
    }
    pNombre = ptrAux;
    seek = estado  =  0;
    while(*pNombre)
    {
        if(*pNombre==' ')
        { 
            switch(estado)
            {
                case 0: subString(pChrAPaterno, ptrAux, 0, seek-1);
                        antSeek = seek+1;
                        estado++;
                    break;
                case 1: subString(pChrAMaterno, ptrAux, antSeek, seek-1);
                        antSeek = seek+1;
                        estado++;
                    break;
                default:// if(*(++pNombre)==' ') {antSeek++;continue;}
                        seek=strlen(ptrAux)-1;
                        pNombre=ptrAux+seek;
                        while(*pNombre==' ')
                        {
                            seek--;
                            pNombre--;
                        }
                        pNombre=ptrAux+antSeek;
                        while(*pNombre==' ')
                        {
                            antSeek++;
                            pNombre++;
                        }
                        subString(pChrNombre, ptrAux, antSeek, seek);
                    return;
            }
        }
        seek++;
        pNombre++;
    }
}

