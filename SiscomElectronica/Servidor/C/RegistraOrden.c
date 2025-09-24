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
SiscomAgregaOperacion(SePagoConTarjeta,&lSiscomProDat); 
SiscomAgregaOperacion(EsOrdenVentaPagaEfectivo,&lSiscomProDat);  
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

void VerificaConCuantoPago(int pintSocket,
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
SiscomAgregaOperacion(VerificandoConCuantoPago,&lSiscomProDat); 
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}


int RegistrandoOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoAsociadoLog("Envio","Cliente",lchrArrBuffer,pSiscomOpePtrDato);
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
return 0;
}

int ValidandoFechaPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
AgregaCampoFechaHora(pSiscomOpePtrDato);
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
return 0;
}
int SePagoConTarjeta(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrTrans;
lSisRegProLPtrTrans=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									 "FormaPago",
									 "Tarjeta",
									 pSiscomOpePtrDato);

if(lSisRegProLPtrTrans)
{
LogSiscom("Se pago con tarjeta");
SqlFormaPagoTarjeta(pSiscomOpePtrDato);
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
SiscomRegistroProL *lSisRegProLPtrTrans;
lSisRegProLPtrTrans=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									 "FormaPago",
									 "Transferencia",
									 pSiscomOpePtrDato);
return lSisRegProLPtrTrans;
}

SiscomRegistroProL *InformacionTarjeta(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrTrans;
lSisRegProLPtrTrans=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									 "FormaPago",
									 "Tarjeta",
									 pSiscomOpePtrDato);
return lSisRegProLPtrTrans;
}
const char *InformacionTarjetaObservaciones(SiscomOperaciones *pSisOpePtrDato)
{

return SiscomObtenCampoRegistroProLChar("Observaciones",InformacionTarjeta(pSisOpePtrDato));

}
int EsOrdenVentaPagaEfectivo(SiscomOperaciones *pSiscomOpePtrDato)
{
if(!EsCotizacion(pSiscomOpePtrDato) && 
   !SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
						"FormaPago",
						"Transferencia",
						pSiscomOpePtrDato) &&
   !SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
   							 "FormaPago",
							 "Tarjeta",
							 pSiscomOpePtrDato))
SqlPagaConEfectivo(pSiscomOpePtrDato);
return 0;
}
float CampoConCuantoPago(SiscomOperaciones *pSisOpePtrDato,const char *pchrPtrCampo)
{
return SiscomCampoAsociadoEntradaOperacionFloat("Envio",pchrPtrCampo,pSisOpePtrDato);
}
const char *TipoOrdenVenta(SiscomOperaciones *pSisOpePtrDato)
{
if(CampoConCuantoPago(pSisOpePtrDato,"ConCuantoPago") >= 
   CampoConCuantoPago(pSisOpePtrDato,"Importe"))
  return "1";
else
  return "0";
}
const char *TipoOrdenApartado(SiscomOperaciones *pSisOpePtrDato)
{
if(CampoConCuantoPago(pSisOpePtrDato,"ConCuantoPago")>=
   CampoConCuantoPago(pSisOpePtrDato,"ACuenta"))
   return "1";
  else
   return "0";
}
int VerificandoConCuantoPago(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
const char *lchrPtrSiAlcanza;
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
if(EsApartado(pSisOpePtrDato))
  lchrPtrSiAlcanza=TipoOrdenApartado(pSisOpePtrDato);
else
 lchrPtrSiAlcanza=TipoOrdenVenta(pSisOpePtrDato);

SiscomFormaEnviaRegistroRespuesta(pSisOpePtrDato,
  				    lchrArrBuffer,
				    "SiAlcanza,Cambio",
				    lchrPtrSiAlcanza,
				    "0");
return 0;
}
