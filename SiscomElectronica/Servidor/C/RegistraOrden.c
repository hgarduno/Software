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
#include <stdlib.h>


SiscomOperacion gSiscomPa[]={0,
				 SePagaraConEfectivo,
				 SePagaraConTarjeta,
				 SePagaraConTransferencia,
				 0
				 };
/*
SiscomCerrandoApartado gSiscomCAp[]={{0,0},
				     {AdelantoPagoEfectivo,PagandoCierreConEfectivo},
				     {0,0}
				     };
					
*/

void FormandoComoPago(int pintSocket,
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
SiscomAgregaOperacion(CalculandoComoPago,&lSiscomProDat);  
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void RegistraOrden(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSisOpErrValExi={0,
                                        FormaPagoCombinada,
                                        0};

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
SiscomAgregaOperacion(SePagoCombinado,&lSiscomProDat);  
SiscomAgregaOperacion(SePagoConTransferencia,&lSiscomProDat); 
SiscomAgregaOperacion(SePagoConTarjeta,&lSiscomProDat); 
SiscomAgregaOperacion(EsOrdenVentaPagaEfectivo,&lSiscomProDat);  
SiscomAgregaOperacion(SqlRegistraOrden,&lSiscomProDat);  
SiscomAgregaOperacion(RegistrandoOrden,&lSiscomProDat);  
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSisOpErrValExi,lSiscomProDat); 
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
SiscomAgregaOperacion(SqlAcuentaApartados,&lSiscomProDat);
SiscomAgregaOperacion(CerrandoApartado,&lSiscomProDat);
SiscomAgregaOperacion(SePagoConTransferencia,&lSiscomProDat); 
SiscomAgregaOperacion(SePagoConTarjeta,&lSiscomProDat); 
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
return 0;
}
int SePagaraConTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrTrans;
lSisRegProLPtrTrans=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									 "FormaPago",
									 "Transferencia",
									 pSiscomOpePtrDato);
return lSisRegProLPtrTrans ? 3 : 0;
}

int SePagaraConTarjeta(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrTrans;
lSisRegProLPtrTrans=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									 "FormaPago",
									 "Tarjeta",
									 pSiscomOpePtrDato);
return lSisRegProLPtrTrans ? 2 : 0;
}

int SePagaraConEfectivo(SiscomOperaciones *pSiscomOpePtrDato)
{
return PagoApartadoEfectivo(pSiscomOpePtrDato);
}

int PagoApartadoEfectivo(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrConCuantoPago;
lchrPtrConCuantoPago=SiscomCampoAsociadoEntradaOperacion("Envio",
							 "ConCuantoPaga",
							 pSiscomOpePtrDato);
 return  lchrPtrConCuantoPago ? 1 : 0;
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
  return SiscomObtenCampoRegistroProLChar("YaSeReflejo",
  					  InformacionTransferencia(pSisOpePtrDato));
}
const char *InformacionTransferenciaObservaciones(SiscomOperaciones *pSisOpePtrDato)
{
return  ValorValidoFormaPagoTransferencia(pSisOpePtrDato,"Observaciones","");
}

const char *InformacionTransferenciaImporte(SiscomOperaciones *pSisOpePtrDato)
{
if(EsApartado(pSisOpePtrDato))
return InformacionApartadoPorPagar(pSisOpePtrDato);
else
return ValorValidoFormaPagoTransferencia(pSisOpePtrDato,"Importe","0");
}
const char *InformacionTransferenciaTelefono(SiscomOperaciones *pSisOpePtrDato)
{
return SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","FormaPago","Telefono",pSisOpePtrDato);
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
const char *InformacionTarjetaImporte(SiscomOperaciones *pSisOpePtrDato)
{
if(EsApartado(pSisOpePtrDato))
return InformacionApartadoPorPagar(pSisOpePtrDato);
else
return ValorValidoFormaPagoTarjeta(pSisOpePtrDato,"Importe","0");
}
const char *InformacionTarjetaObservaciones(SiscomOperaciones *pSisOpePtrDato)
{
return ValorValidoFormaPagoTarjeta(pSisOpePtrDato,"Observaciones","");

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
float ObtenImporteTransferencia(SiscomOperaciones *pSisOpePtrDato)
{
if(SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						"Transferencia",
						"Importe",
						pSisOpePtrDato))
return  SiscomCampoAsociadoAsociadoEntradaOperacionFloat("Envio",
							 "Transferencia",
							 "Importe",
							 pSisOpePtrDato);
else
return 0;
}

float ObtenImporteTarjeta(SiscomOperaciones *pSisOpePtrDato)
{
if(SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
					       "Tarjeta",
					       "Importe",
					       pSisOpePtrDato))
return  SiscomCampoAsociadoAsociadoEntradaOperacionFloat("Envio",
							 "Tarjeta",
							 "Importe",
							 pSisOpePtrDato);
else
return 0;
}
void EstadoPagoCompleto(char *pchrPtrEstado,SiscomOperaciones *pSisOpePtrDato)
{
SiscomActualizaCampoAsociadoEntrada("Envio","PagoCompleto",pchrPtrEstado,pSisOpePtrDato);
}
void CalculandoPorPagar(SiscomOperaciones *pSisOpePtrDato)
{
float lfltTotal,
	lfltPorPagar,
	lfltEfectivo,
	lfltTransferencia,
	lfltTarjeta;
lfltTotal=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Total",pSisOpePtrDato);
lfltEfectivo=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Efectivo",pSisOpePtrDato);
lfltTransferencia=ObtenImporteTransferencia(pSisOpePtrDato);
lfltTarjeta=ObtenImporteTarjeta(pSisOpePtrDato);
lfltPorPagar=lfltTotal-(lfltEfectivo+lfltTarjeta+lfltTransferencia);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","PorPagar",lfltPorPagar,pSisOpePtrDato);
if(lfltPorPagar==0.0)
EstadoPagoCompleto("1",pSisOpePtrDato);
else
EstadoPagoCompleto("0",pSisOpePtrDato);
}
void RespondeCalculandoComoPago(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomEnviaRegistrosEntrada(pSisOpePtrDato,lchrArrBuffer);
}
int CalculandoComoPago(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
CalculandoPorPagar(pSisOpePtrDato);
RespondeCalculandoComoPago(pSisOpePtrDato);
return 0;
}

SiscomRegistroProL *FormaPagoEnvio(SiscomOperaciones *pSisOpePtrDato)
{
 return SiscomRegistroAsociadoEntradaOperacion("Envio","FormaPago",pSisOpePtrDato);
}

int FormaPagoCombinada(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[1024];
LogSiscom("Se registra infomracion del pago combinado :) :) :)");
SePagoConTransferencia(pSisOpePtrDato);
SePagoConTarjeta(pSisOpePtrDato);
SqlPagaConEfectivo(pSisOpePtrDato);
SqlPagoCombinado(pSisOpePtrDato);
SqlRegistraOrden(pSisOpePtrDato);

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadosArgumentoLog("SqlOrden",
  			    "SentenciasSql",
			     lchrArrBuffer,
			   pSisOpePtrDato);
return 0;

}
const char *CampoFormaPago(const char *pchrPtrCampo,SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrDato;
if((lSisRegProLPtrDato=FormaPagoEnvio(pSisOpePtrDato)))
 return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSisRegProLPtrDato);
}

int FormaPagoCombinadaInt(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrCombinada=CampoFormaPago("Combinada",pSisOpePtrDato);
LogSiscom("La forma de pago %s",lchrPtrCombinada);
if(lchrPtrCombinada) 
return atoi(lchrPtrCombinada);
else
return 0;
}
int SePagoCombinado(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[128];
SiscomRegistroProtocoloLog(lchrArrBuffer,FormaPagoEnvio(pSisOpePtrDatos));
return FormaPagoCombinadaInt(pSisOpePtrDatos);
}

const char *ValorValidoFormaPagoTarjeta(SiscomOperaciones *pSisOpePtrDato,
				 const char *pchrPtrCampo,
				 const char *pchrPtrQPongo)
{
const char *lchrPtrCampo;
if((lchrPtrCampo=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,
		InformacionTarjeta(pSisOpePtrDato))))
  return  lchrPtrCampo;
else
if(pchrPtrQPongo)
 return pchrPtrQPongo;
}

const char *ValorValidoFormaPagoTransferencia(SiscomOperaciones *pSisOpePtrDato,
				 const char *pchrPtrCampo,
				 const char *pchrPtrQPongo)
{
const char *lchrPtrCampo;
if((lchrPtrCampo=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,
		InformacionTransferencia(pSisOpePtrDato))))
  return  lchrPtrCampo;
else
if(pchrPtrQPongo)
 return pchrPtrQPongo;
}

SiscomRegistroProL *InformacionRegistroApartado(SiscomOperaciones *pSisOpePtrDato)
{
return SiscomRegistroAsociadoEntradaOperacion("Envio","Apartado",pSisOpePtrDato);
}
const char *InformacionApartadoEstado(SiscomOperaciones *pSisOpePtrDato)
{
return SiscomObtenCampoRegistroProLChar("Estado",InformacionRegistroApartado(pSisOpePtrDato));
}
const char *InformacionApartadoPorPagar(SiscomOperaciones *pSisOpePtrDato)
{
if(!SiscomComparaCadenaCampoRegistroProL("2",
					"Estado",
					InformacionRegistroApartado(pSisOpePtrDato)))
return SiscomObtenCampoRegistroProLChar("ACuenta",InformacionRegistroApartado(pSisOpePtrDato));
else
return SiscomObtenCampoRegistroProLChar("PorPagar",InformacionRegistroApartado(pSisOpePtrDato));

}
SiscomRegistroProL *AdelantoEfectivo(SiscomOperaciones *pSisOpePtrDato)
{
 return SiscomObtenRegistrosCampoRespuesta("PagaCon",pSisOpePtrDato); 
}

SiscomRegistroProL *AdelantoTarjeta(SiscomOperaciones *pSisOpePtrDato)
{
 return SiscomObtenRegistrosCampoRespuesta("Pagotarjeta",pSisOpePtrDato); 
}

SiscomRegistroProL *AdelantoTransferencia(SiscomOperaciones *pSisOpePtrDato)
{
 return SiscomObtenRegistrosCampoRespuesta("PagoTransferencia",pSisOpePtrDato); 
}
/* Jueves 2 de Julio 2026
 * Tepotzotlan Mexico 
 *
 * El cierre del apartdo se hizo muy largo :) , llevo 3 dias con esto 
 *
 *    1   El Adelanto fue en Efectivo 
 *    2   El adelanto fue con tarjeta 
 *    3   El adelanto fue con transferencia
 *
 */
int ComoSePagoAdelanto(SiscomOperaciones *pSisOpePtrDatos,
		       SiscomRegistroProL **pSisRegProLPtrDatos)
{
if((*pSisRegProLPtrDatos=AdelantoEfectivo(pSisOpePtrDatos)))
return 1;
else
if((*pSisRegProLPtrDatos=AdelantoTarjeta(pSisOpePtrDatos)))
return 2;
if((*pSisRegProLPtrDatos=AdelantoTransferencia(pSisOpePtrDatos)))
return 3;
}
int ComoSePagaraApartado(SiscomOperaciones *pSisOpePtrDatos)
{
SiscomOperacion *lSiscomPa=gSiscomPa;
int lintComoPagara;
while(lSiscomPa)
{
  if((lintComoPagara=(*lSiscomPa)(pSisOpePtrDatos)))
  break;
  lSiscomPa++;
}
return lintComoPagara;
}
int CerrandoApartado(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[128];
SiscomAsociadoRespuestaLog("PagoTransferencia",lchrArrBuffer,pSisOpePtrDatos);
SiscomAsociadoRespuestaLog("PagoTarjeta",lchrArrBuffer,pSisOpePtrDatos);
SiscomAsociadoRespuestaLog("PagaCon",lchrArrBuffer,pSisOpePtrDatos);
}

int AdelantoPagadoEfectivo(SiscomOperaciones *pSIsOpePtrDato)
{


return 1;
}

int PagandoCierreConEfectivo(SiscomOperaciones *pSisOpePtrDato)
{


return 1;
}
