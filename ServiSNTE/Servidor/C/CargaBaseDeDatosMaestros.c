#include <CargaBaseDeDatosMaestros.h>
#include <CargaNominaEmpleados.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomRecibeArchivo.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomOperaciones.h>
/*
#include <SqlCargaBaseDeDatosMaestros.h>

*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void CargaBaseDeDatosMaestros(int pintSocket,
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

SiscomAgregaOperacion(RecibeArchivoBaseDeDatos,&lSiscomProDat);
SiscomAgregaOperacion(EscribeArchivoBaseDeDatos,&lSiscomProDat);

SiscomAgregaOperacion(ProcesaBaseDeDatos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaBaseDeDatosMaestros,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviaBaseDeDatosMaestros(SiscomOperaciones *pSiscomOpePtrDat)
{
/*
char lchrArrBuffer[1024];
if(SiscomObtenRegistrosCampoRespuesta("BaseDeDatosMaestros",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("BaseDeDatosMaestros",pSiscomOpePtrDat));
else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
*/
/*SiscomRegistrosAsociadosLog(lchrArrBuffer,"BaseDeDatosMaestros",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes); */
}

int RecibeArchivoBaseDeDatos(SiscomOperaciones *pSiscomOpePtrDat)
{
SiscomBloqueArchivoL *lSiscomBloArLArchivo=0;
SiscomRecibeArchivo(pSiscomOpePtrDat->intSocket,&lSiscomBloArLArchivo);
pSiscomOpePtrDat->SiscomBloArLArchivo=lSiscomBloArLArchivo;
}
const char *ObtenNombre2(const char *pchrPtrArchivo)
{
const char *lchrPtrPaso;
int lintTamano=strlen(pchrPtrArchivo);
lchrPtrPaso=pchrPtrArchivo+lintTamano-1;
    while(*lchrPtrPaso!='/')
    lchrPtrPaso--;
return ++lchrPtrPaso;
}
void NombreArchivo2(const char *pchrPtrArchivo,
		   char *pchrPtrArchivoSalida)
{
const char *lchrPtrArchivo=ObtenNombre2(pchrPtrArchivo);
const char *lchrPtrDirectorio=getenv("ArchivosBaseDeDatos");
sprintf(pchrPtrArchivoSalida,"%s/%s",lchrPtrDirectorio,lchrPtrArchivo);
}
int AbreArchivoBaseDeDatos(const char *pchrPtrArchivo,
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
int EscribeArchivoBaseDeDatos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrArchivoSalida[1024];
const char *lchrPtrNombre=SiscomCampoAsociadoEntradaOperacion("Envio",
							      "Archivo",
							      pSiscomOpePtrDat);
/*NombreArchivo(lchrPtrNombre,lchrArrArchivoSalida); */
SiscomEscribeArchivoSocket(lchrArrArchivoSalida,pSiscomOpePtrDat->SiscomBloArLArchivo);


}


int ProcesaBaseDeDatos(SiscomOperaciones *pSiscomOpePtrDat)
{
    char lchrArrArchivoSalida[1024],lchrArrBuffer[256];
    FILE *lFltPtrArchivo;
    SiscomRegistroProL *lSiscomRegProLPtrMaestrosPrim=0,
		   *lSiscomRegProLPtrMaestrosAct=0;
    const char *lchrPtrNombre=SiscomCampoAsociadoEntradaOperacion("Envio",
							      "Archivo",
							      pSiscomOpePtrDat);
    /*NombreArchivo(lchrPtrNombre,lchrArrArchivoSalida); */
    LogSiscom("El Archivo a Analizar:%s",lchrArrArchivoSalida);
    LogSiscom("Procesando el archivo");



    AbreArchivoBaseDeDatos(lchrArrArchivoSalida,&lFltPtrArchivo);
    /* 
    ObtenDatosArchivoMaestros(lFltPtrArchivo,
      		 &lSiscomRegProLPtrMaestrosPrim,
      		 &lSiscomRegProLPtrMaestrosAct);
		 */
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrMaestrosPrim);

/*MuestraMaestros(lSiscomRegProLPtrMaestrosPrim); */
    //Cerrar archivo.
}



