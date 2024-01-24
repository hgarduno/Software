#include <CircuitosImpresos.h>
#include <SqlCircuitoImpreso.h>
#include <ImpresionTicketVenta.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h> 

void EstadosImpresosSE(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlEstadosImpresosSE,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoEstadosImpresosSE,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviandoEstadosImpresosSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
if(SiscomObtenRegistrosCampoRespuesta("EstadosImpresos",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  SiscomRegistrosCampoO("EstadosImpresos",pSiscomOpePtrDato));
return 0;
}

void CircuitosImpresosPendientes(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlCircuitosImpresosPendientes,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaCircuitosImpresosPendientes,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);


}
void ImpresosPorEstadoFecha(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlCircuitosImpresosPorFechaEstado,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaCircuitosImpresosPendientes,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistraCircuitoImpreso(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoRegistroCircuitoImpreso,&lSiscomProDat);
SiscomAgregaOperacion(AsignaIdCircuitoImpreso,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCampoFechaHora,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCircuitoImpreso,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaCircuitoImpreso,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}
void CircuitoImpresoActualizaEdo(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoRegistroCircuitoImpreso,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCampoFechaHora,&lSiscomProDat);
SiscomAgregaOperacion(SqlCircuitoImpresoActualizaEdo,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaCircuitoImpreso,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}

int EnviaCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Registrando el impreso");
SiscomAsociadosArgumentoLog("SqlCircuitoImpreso",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomFormaEnviaRegistroRespuesta(pSiscomOpePtrDato,lchrArrBuffer, "Estado,", "1");

return 0;
}

int EnviaCircuitosImpresosPendientes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomEnviaAsociadoRespuestaCliente("ImpresosRegistrados",lchrArrBuffer,pSiscomOpePtrDato);
}

int ArgumentoRegistroCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlCircuitoImpreso",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int AsignaIdCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdImpreso",pSiscomOpePtrDato);
return 0;
}

