#include <RegistraOrden.h>

#include <ImpresionTicketVenta.h>

#include <SqlOrdenes.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>

void RegistraOrden(int pintSocket,
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
SiscomAgregaOperacion(ValidandoFechaPedido,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoOrden,&lSiscomProDat);
SiscomAgregaOperacion(SqlMaterialAAreaDiseno,&lSiscomProDat);
SiscomAgregaOperacion(SqlDonacionMaterial,&lSiscomProDat);
SiscomAgregaOperacion(SqlImporteOrden,&lSiscomProDat);
SiscomAgregaOperacion(SqlEscuelaOrden,&lSiscomProDat);
SiscomAgregaOperacion(SqlVentas,&lSiscomProDat);
SiscomAgregaOperacion(SqlExistencias,&lSiscomProDat);
SiscomAgregaOperacion(SqlExistenciasProductosKitPracticaEtc,&lSiscomProDat);
SiscomAgregaOperacion(SqlOrdenCliente,&lSiscomProDat); 
SiscomAgregaOperacion(SqlApartados,&lSiscomProDat); 
SiscomAgregaOperacion(SqlCotizacion,&lSiscomProDat); 
SiscomAgregaOperacion(SqlDatosPedido,&lSiscomProDat); 
SiscomAgregaOperacion(SqlPedidoCliente,&lSiscomProDat); 
SiscomAgregaOperacion(SqlEstadosPedidoCliente,&lSiscomProDat); 
SiscomAgregaOperacion(SqlDireccionEntrega,&lSiscomProDat); 
SiscomAgregaOperacion(SePagoConTransferencia,&lSiscomProDat); 
SiscomAgregaOperacion(SqlRegistraOrden,&lSiscomProDat);  
SiscomAgregaOperacion(RegistrandoOrden,&lSiscomProDat);  
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PagarApartado(int pintSocket, SiscomRegistroProL *pSiscomRegProLPtrPrim,
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
SiscomAgregaOperacion(ArgumentoOrden,&lSiscomProDat);
SiscomAgregaOperacion(CamposCierraApartadoOtroDia,&lSiscomProDat);
SiscomAgregaOperacion(SqlCierraApartado,&lSiscomProDat); 
SiscomAgregaOperacion(SqlRegistraOrden,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoOrden,&lSiscomProDat); 
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ActualizaDescripcionCotizacion(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoOrden,&lSiscomProDat);
SiscomAgregaOperacion(SqlActualizaDescripcionCotizacion,&lSiscomProDat); 
SiscomAgregaOperacion(SqlRegistraOrden,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoOrden,&lSiscomProDat); 
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int RegistrandoOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
LOGOrden(pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlOrden",
  			    "SentenciasSql",
			     lchrArrBuffer,
			   pSiscomOpePtrDato);
return 0;
}

int ArgumentoOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlOrden",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
int CamposCierraApartadoOtroDia(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("IdVentaPorEntregaOtroDia",0,"Envio",pSiscomOpePtrDato);
SiscomAgregaCampoAsociadoEntrada("FechaHoy",0,"Envio",pSiscomOpePtrDato);
SiscomAsignaFechaHoraAsociadoEntrada("Envio","FechaHoy",pSiscomOpePtrDato);
SiscomIdARegistrosAsociadosEntrada("Envio","IdVentaPorEntregaOtroDia",pSiscomOpePtrDato);
}

int ValidandoFechaPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
AgregaCampoFechaHora(pSiscomOpePtrDato);
LogSiscom("");
return 1;
}

int SePagoConTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrTrans;
lSisRegProLPtrTrans=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									 "FormaPago",
									 "Transferencia",
									 pSiscomOpePtrDato);
if(lSisRegProLPtrTrans)
  SqlFormaPagoTransferencia(pSiscomOpePtrDato);
else
{
  LogSiscom("NO Se paga contransferencia");
}
return 0;
}
const char *InformacionTransferenciaSeReflejo(SiscomOperaciones *pSisOpePtrDato)
{
  return SiscomObtenCampoRegistroProLChar("YaSeReflejo",InformacionTransferencia(pSisOpePtrDato));

}
const char *InformacionTransferenciaObservaciones(SiscomOperaciones *pSisOpePtrDato)
{
  return SiscomObtenCampoRegistroProLChar("Observaciones",InformacionTransferencia(pSisOpePtrDato));

}

SiscomRegistroProL *InformacionTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrTrans;
lSisRegProLPtrTrans=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									 "FormaPago",
									 "Transferencia",
									 pSiscomOpePtrDato);
return lSisRegProLPtrTrans;
}
