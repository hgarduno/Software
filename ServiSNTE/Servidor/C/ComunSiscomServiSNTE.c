#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomReplicacion.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int ComunicacionAccesoDatos(SiscomOperaciones *pSiscomOpePtrDato)
{
pSiscomOpePtrDato->intPuertoSvrAccesoDatos=SiscomVariableIniAInt(
					"PuertoSvrAccesoDatos",&gSiscomDatIni);
SiscomVariableIniAChar("DirIpSvrAccesoDatos",
			&gSiscomDatIni,
			pSiscomOpePtrDato->chrArrDirIpSvrAccesoDatos);
SiscomVariableIniAChar("BaseDatos",
			&gSiscomDatIni,
			pSiscomOpePtrDato->chrArrBaseDatos);
SiscomVariableIniAChar("PuertoBD",
			&gSiscomDatIni,
			pSiscomOpePtrDato->chrArrPuertoBaseDatos);
return 0;
}

int EnviaMensajeCliente(const char *pchrPtrArchivo,
			const char *pchrPtrFuncion,
			int pintNoLinea,
			const char *pchrPtrEstado,
			const char *pchrPtrMensaje,
			SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "Estado,Mensaje,",
		       pchrPtrEstado,
		       pchrPtrMensaje);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
 SiscomMuestraRegistrosProtocolo(pchrPtrArchivo, 
                                 pchrPtrFuncion,
				 pintNoLinea,
				lchrArrBuffer,       
				lSiscomRegProLPtrPrim);
return 0;
}



int RespondeConsultaSinRegistros(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "EstadoConsulta,Mensajes,",
		       "0",
		       "La consulta no genero registros");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
return 0;
}



void RespondeRegistroExitoso(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[512];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "EdoRegistro,Mensaje,",
		       "0",
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
}
void RespondiendoEstadoInsercion(const char *pchrPtrArgumento,
				  SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[512];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "EdoRegistro,Mensaje,",
		       "0",
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);

}
void DatosFecha(const char *pchrPtrFecha,
        char *pchrPtrAnio,
        char *pchrPtrMes,
        char *pchrPtrDia)
{
    strncpy(pchrPtrAnio,pchrPtrFecha,4);
    *(pchrPtrAnio+4)=0;
    strncpy(pchrPtrMes,pchrPtrFecha+5,2);
    *(pchrPtrMes+2)=0;
    strncpy(pchrPtrDia,pchrPtrFecha+8,2);
    *(pchrPtrDia+2)=0;
}


void ExistenciasTiendaLocalRemota(SiscomRegistroProL *pSiscomRegProLPtrServidores,
		       SiscomOperaciones *pSiscomOpePtrDat,
		       const char *pchrPtrSql)
{
const char *lchrPtrIdTienda;
char *lchrArrBuffer;
lchrArrBuffer=(char *)malloc(strlen(pchrPtrSql)+256);
if((lchrPtrIdTienda=SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDat)))
SiscomConsultasSqlServidorPorIdMaquina(lchrPtrIdTienda,
				  	pSiscomRegProLPtrServidores,
					lchrArrBuffer,
					pSiscomOpePtrDat,
					"ExistenciasTienda%",
					pchrPtrSql);
else
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDat,
		   "ExistenciasTienda%",
		   pchrPtrSql);

}
