#include <SqlOrdenes.h>
#include <Cotizando4.h>
#include <OperacionesPedidos.h>
#include <ImpresionTicketVenta.h>

#include <RegistraOrden.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomInsercionesSql.h>

#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <stdio.h>
#include <string.h>

int SqlPagaConEfectivo(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPagaCon);
return 0;
}


int SqlFormaPagoTransferencia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPagoTransferencia);
return 0;
}
int SqlRegistraOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadosArgumentoLog("SqlOrden","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaRegistrosAlServidorBD("SqlOrden",
			       lchrArrBuffer,
			       pSiscomOpePtrDato);
return 0;
}
int SqlMaterialAAreaDiseno(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(EsMaterialAAreaDiseno(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToMaterialAAreaDiseno);
return 0;
}

int SqlDonacionMaterial(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(EsDonacionMaterial(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToDonacionMaterial);
return 0;
}


int SqlImporteOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(SeAgreganImportes(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToImporteOrden);
return 0;
}

int SqlEscuelaOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(!EsCancelacion(pSiscomOpePtrDato))
{
if(EsCotizacion(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteEscuelaOrdenModificando);
if(SeAgreganImportes(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToEscuelaOrden);
}
return 0;
}
int SqlOrdenCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(!EsCancelacion(pSiscomOpePtrDato))
{
if(EsCotizacion(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteOrdenClienteModificando);
if(SeAgreganImportes(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToOrdenCliente);
}
return 0;
}

int SqlApartados(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(EsApartado(pSiscomOpePtrDato))
{
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToApartado);

SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToEstadoApartado);

}
return 0;
}
int SqlCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(EsCotizacion(pSiscomOpePtrDato))
{
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteCotizacionModificando);
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToCotizacion);

}
return 0;
}

int SqlVentas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];

if(EsCotizacion(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteVentasModificando);

  SiscomAgregaSentenciasSqlCampoAsociado("SqlOrden",
  					 "Envio",
					 "Productos",
					 lchrArrBuffer,
					 lchrArrSql,
					 pSiscomOpePtrDato,
					 InsertToVentas);

return 0;
}



int SqlExistencias(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(!EsCotizacion(pSiscomOpePtrDato) &&
   !EsCancelacion(pSiscomOpePtrDato))
  SiscomAgregaSentenciasSqlCampoAsociado("SqlOrden",
  					 "Envio",
					 "Productos",
					 lchrArrBuffer,
					 lchrArrSql,
					 pSiscomOpePtrDato,
					 InsertToExistencias);
return 0;
}
void SqlSentenciasActualizacionDefinicionProducto(SiscomOperaciones *pSiscomOpePtrDato,
						  SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
SiscomRegistroProL *lSiscomRegProLPtrProductos;
char lchrArrBuffer[256],
	lchrArrBufferSql[256];
if((lSiscomRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",pSiscomRegProLPtrProducto)))
{
 SiscomAgregaSentenciasSqlRegistros("SqlOrden",
 				    lchrArrBuffer,
				    lchrArrBufferSql,
				    lSiscomRegProLPtrProductos,
				    pSiscomOpePtrDato,
				    InsertToExistenciasKitPracticaEtc);
}
}
int SqlExistenciasProductosKitPracticaEtc(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrProductos;
if(!EsCancelacion(pSiscomOpePtrDato))
{
if((lSiscomRegProLPtrProductos=SiscomRegistrosAsociadosCampoEntrada("Envio",
								    "Productos",
								    pSiscomOpePtrDato)))
{
for(;
     lSiscomRegProLPtrProductos;
     lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
/* CDMX Martes 13 de Julio 2021 
 * En medio del Covid, ya pasaron muchos meses, y seguimos en medio de 
 * la pandemia :( :) 
 * Con la integracion del registro de productos siscom , practicas , Kits etc 
 * el descuento de las existencias se hacen en el momento del registro del 
 * producto, por lo que solo el circuito 
if(EsProductoKit(lSiscomRegProLPtrProductos) 		||
   EsProductoPractica(lSiscomRegProLPtrProductos) 	||
   EsCircuitoImpreso(lSiscomRegProLPtrProductos)	||
   EsProductoSiscom(lSiscomRegProLPtrProductos))
   SqlSentenciasActualizacionDefinicionProducto(pSiscomOpePtrDato,lSiscomRegProLPtrProductos);  
*/
if(EsCircuitoImpreso(lSiscomRegProLPtrProductos))
   SqlSentenciasActualizacionDefinicionProducto(pSiscomOpePtrDato,lSiscomRegProLPtrProductos);  
}
}
return 0;
}
int SqlCierraApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(FechaApartadoEntregaHoy(pSiscomOpePtrDato))
{
if(PagoApartadoEfectivo(pSiscomOpePtrDato))
{
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToEstadoApartadoADos);
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToVentasCierraApartado);
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToImporteOrdenCierraApartadoMismoDia);
}
}
else
if(FechaEntregaProgramada(pSiscomOpePtrDato))
{
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToEstadoApartado);
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToImporteOrdenCierraApartado);
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToVentasCierraApartado);
}
else
CierraApartadoCualquierOtroDia(pSiscomOpePtrDato);
return 0;
}
int SqlDatosPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(EsPedido(pSiscomOpePtrDato))
  SiscomAgregaSentenciasSqlCampoAsociado("SqlOrden",
  					 "Envio",
					 "Pedido",
					 lchrArrBuffer,
					 lchrArrSql,
					 pSiscomOpePtrDato,
					 InsertToDatosPedido);
return 0;
}


int SqlPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(EsPedido(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPedidoCliente);
LogSiscom("");
return 0;
}

int SqlEstadosPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
if(EsPedido(pSiscomOpePtrDato))
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToEstadosPedidoCliente);
return 0;
}

int SqlDireccionEntrega(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
     lchrArrSql[512];
if(EsPedido(pSiscomOpePtrDato))
  SiscomAgregaSentenciasSqlCampoAsociado("SqlOrden",
  					 "Envio",
					 "Pedido",
					 lchrArrBuffer,
					 lchrArrSql,
					 pSiscomOpePtrDato,
					 InsertToDireccionEntrega);
return 0;
}

int SqlActualizaDescripcionCotizacion(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSisOpePtrDato,
				     UpdateDescripcionCotizacion);
return 0;
}
void InsertToMaterialAAreaDiseno(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{

sprintf(pchrPtrSql,
"insert into MaterialAAreaDiseno values(%s,'%s','%s',%s);",
SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","MaterialAAreaDiseno","Explicacion",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrDato));
}

void InsertToDonacionMaterial(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{

sprintf(pchrPtrSql,
"insert into DonacionMaterial values(%s,'%s','%s',%s);",
SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","DonacionMaterial","Explicacion",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrDato));
}



void InsertToEstadosPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrEdoPedido;
lSisRegProLPtrEdoPedido=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion(
				"Envio",
				"Pedido",
				"EstadoPedido",
				pSiscomOpePtrDato);
			
sprintf(pchrPtrSql,
	"insert into EstadosPedidoCliente values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdEstado",lSisRegProLPtrEdoPedido));
}

void InsertToPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
const char *lchrPtrIdEstado;
lchrPtrIdEstado=SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into PedidoCliente values(%s,%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	lchrPtrIdEstado ? lchrPtrIdEstado : "0",
	SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato));
}

void InsertToImporteOrden(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
char lchrArrBuffer[256];

SiscomAsociadoAsociadoLog("Envio","Apartado",lchrArrBuffer,pSiscomOpePtrDato);
*pchrPtrSql=0;
if(EsApartado(pSiscomOpePtrDato))
{

sprintf(pchrPtrSql,
	"insert into ImporteOrden values(%s,%s,'%s',%s);",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Apartado","ACuenta",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato),
	FormaPagoApartado(pSiscomOpePtrDato));
}
else
if(!EsCotizacion(pSiscomOpePtrDato) &&
   !EsCancelacion(pSiscomOpePtrDato))
sprintf(pchrPtrSql,
	"insert into ImporteOrden values(%s,%s,'%s',%s);",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato),
	FormaPagoOrden(pSiscomOpePtrDato));
else
{
/*
 LogSiscom("Es un %s",SiscomObtenCampoRegistroProLChar("IdTipoOrden",pSiscomRegProLPtrDato));
*/
}
}

void InsertToEscuelaOrden(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
SiscomRegistroProL *lSiscomRegProLPtrEscuela;
if((lSiscomRegProLPtrEscuela=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
									      "Cliente",
									      "Escuela",
									      pSiscomOpePtrDato)))
sprintf(pchrPtrSql,
	"insert into EscuelaOrden values(%s,%s,%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdExpendio",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("idescuela",lSiscomRegProLPtrEscuela), 
	SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato));
else
LogSiscom("NO Llego la escuela");
}
void InsertToVentas(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
const char *lchrPtrTipoOrden;
float lfltCantidad;
const char *lchrPtrIdProducto;
lfltCantidad=SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrDato)*
	     SiscomCampoAsociadoEntradaOperacionFloat("Envio","Juegos",pSiscomOpePtrDato); 



if(EsApartado(pSiscomOpePtrDato))
lchrPtrTipoOrden=FormaPagoApartado(pSiscomOpePtrDato);
/* Tepotzotlan a 4 de diciembre del 2023
 * 
 * Aqui va lo de la forma de pago ....
else
if(!SiscomComparaCampoAsociadoEntradaCadena("Envio","FormaPago","1",pSiscomOpePtrDato))
lchrPtrTipoOrden="7";
*/
else
lchrPtrTipoOrden=SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato);
lchrPtrIdProducto=SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrDato);
lchrPtrIdProducto=lchrPtrIdProducto ? lchrPtrIdProducto : "0" ;


sprintf(pchrPtrSql,
	"insert into Ventas values(%s,%s,'%s','%s',%f,%s,%s,%s,%s,%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaHora",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
	lfltCantidad,
	SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Precio",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVendedor",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","IdPersona",pSiscomOpePtrDato),
	lchrPtrTipoOrden,
 	SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdConsecutivo",pSiscomRegProLPtrDato));	
}

void InsertToExistencias(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
char lchrArrBuffer[256];
float lfltCantidad;
*pchrPtrSql=0;
lfltCantidad=SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrDato)*
	     SiscomCampoAsociadoEntradaOperacionFloat("Envio","Juegos",pSiscomOpePtrDato); 
sprintf(pchrPtrSql,
	"update existencias set Existencia=Existencia-%f where cveProducto='%s' and idExpendio=%s;",
	lfltCantidad,
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato));
}

void InsertToExistenciasKitPracticaEtc(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
float lfltCantidad;
lfltCantidad=SiscomObtenCampoRegistroProLFloat("cantidad",pSiscomRegProLPtrDato)*
	     SiscomCampoAsociadoEntradaOperacionFloat("Envio","Juegos",pSiscomOpePtrDato); 
sprintf(pchrPtrSql,
	"update existencias set Existencia=Existencia-%f where cveProducto='%s' and idExpendio=%s;",
	lfltCantidad,
	SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato));
}
void InsertToOrdenCliente(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into OrdenCliente values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","IdPersona",pSiscomOpePtrDato));
}
void InsertToApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
*pchrPtrSql=0;
sprintf(pchrPtrSql,
	"insert into Apartado values(%s,%s,%.2f,'%s');",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						    "Apartado",
						    "ACuenta",
						    pSiscomOpePtrDato),
	ObtenRestaPago(pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						    "Apartado",
						    "FechaHoraE",
						    pSiscomOpePtrDato));
}
void InsertToEstadoApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
*pchrPtrSql=0;
sprintf(pchrPtrSql,
	"insert into EstadoApartado values(%s,2);",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato));
}

void InsertToCotizacion(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Cotizacion values(%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						    "Cotizacion",
						    "Descripcion",
						    pSiscomOpePtrDato));
}

void InsertToDireccionEntrega(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
const char *lchrPtrIdVenta,*lchrPtrNmbPEntrega;
char lchrArrBuffer[256];
lchrPtrIdVenta=SiscomCampoAsociadoEntradaOperacion("Envio",
						   "IdVenta",
						   pSiscomOpePtrDato);
lchrPtrNmbPEntrega=NombrePuntoEntrega(pSiscomRegProLPtrDato);	
sprintf(pchrPtrSql,
	"insert into DireccionEntrega values(%s,%s,'%s',%s);",
	lchrPtrIdVenta,
	IdDireccionEntregaPedido(pSiscomOpePtrDato),
	lchrPtrNmbPEntrega ? lchrPtrNmbPEntrega : "",
	lchrPtrNmbPEntrega ? "0" :"1");
}

void DeleteCotizacionModificando(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from Cotizacion where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato));
}

void DeleteEscuelaOrdenModificando(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from escuelaorden where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato));
}

void DeleteOrdenClienteModificando(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from ordencliente where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato));
}
void DeleteVentasModificando(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from ventas where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato));
}

void InsertToDatosPedido(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
const char *lchrPtrCambio,
	   *lchrPtrObservaciones;
lchrPtrCambio=SiscomObtenCampoRegistroProLChar("Cambio",pSiscomRegProLPtrDato);
lchrPtrObservaciones=SiscomObtenCampoRegistroProLChar("Observaciones",pSiscomRegProLPtrDato);
sprintf(pchrPtrSql,
	"insert into DatosPedido values(%s,'%s',%s,%s,'%s');",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHoraE",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("SePagaCon",pSiscomRegProLPtrDato),
	lchrPtrCambio ? lchrPtrCambio:"0",
	lchrPtrObservaciones ? lchrPtrObservaciones :"");
}

void UpdateToVentasCierraApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update ventas set edoventa=0 where idventa=%s",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato));
}

void UpdateToVentasCierraApartadoTarjeta(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update ventas set edoventa=8 where idventa=%s",
	SiscomObtenCampoRegistroProLChar("idventa",pSiscomRegProLPtrDato));
}

void UpdateToImporteOrdenCierraApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update importeorden set edoventa=0 where idventa=%s",
	SiscomObtenCampoRegistroProLChar("idventa",pSiscomRegProLPtrDato));

}

void UpdateToImporteOrdenCierraApartadoMismoDia(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update importeorden set edoventa=0,importe=importe+%s where idventa=%s",
	SiscomObtenCampoRegistroProLChar("porpagar",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("idventa",pSiscomRegProLPtrDato));
}

void UpdateToImporteOrdenCierraApartadoApartoConTarjeta(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update EstadoApartado set estado=8 where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("idventa",pSiscomRegProLPtrDato));

}


void UpdateToEstadoApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"update EstadoApartado set estado=0 where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato));

}

void UpdateToEstadoApartadoADos(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"update EstadoApartado set estado=2 where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("idventa",pSiscomRegProLPtrDato));

}

void InsertToImporteOrdenCierreOtroDia(SiscomOperaciones *pSiscomOpePtrDato,
					SiscomRegistroProL *pSiscomRegProLPtrDato,
					char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ImporteOrden values(%s,%s,'%s',0);",
	SiscomObtenCampoRegistroProLChar("IdVentaPorEntregaOtroDia",pSiscomRegProLPtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Apartado","PorPagar",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHoy",pSiscomRegProLPtrDato));
}
void InsertToApartadoEntregadoOtroDia(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ApartadoEntregadoOtroDia values(%s,%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdVentaPorEntregaOtroDia",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHoy",pSiscomRegProLPtrDato));

}

void UpdateDescripcionCotizacion(SiscomOperaciones *pSisOpePtrDato,
				  SiscomRegistroProL * pSisRegProLPtrDato,
				  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update cotizacion set descripcion='%s' where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("Descripcion",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdVenta",pSisRegProLPtrDato));
}

void InsertToPagoTransferencia(SiscomOperaciones *pSisOpePtrDato,
				SiscomRegistroProL *pSisRegProLPtrDato,
				char *pchrPtrSql)
{
const char *lchrPtrObservaciones,*lchrPtrPaso;

lchrPtrObservaciones=InformacionTransferenciaObservaciones(pSisOpePtrDato);
lchrPtrPaso=lchrPtrObservaciones ? lchrPtrObservaciones : "";
sprintf(pchrPtrSql,
"insert into PagoTransferencia values(%s,'%s',%s,'%s');",
SiscomObtenCampoRegistroProLChar("IdVenta",pSisRegProLPtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","FormaPago","Telefono",pSisOpePtrDato),
InformacionTransferenciaSeReflejo(pSisOpePtrDato),
lchrPtrPaso);
}

void InsertToPagaCon(SiscomOperaciones *pSisOpePtrDato,
				SiscomRegistroProL *pSisRegProLPtrDato,
				char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"insert into PagaCon values(%s,%s);",
SiscomObtenCampoRegistroProLChar("IdVenta",pSisRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("ConCuantoPaga",pSisRegProLPtrDato));
}


int SeAgreganImportes(SiscomOperaciones *pSiscomOpePtrDato)
{
return !(EsMaterialAAreaDiseno(pSiscomOpePtrDato) ||
       EsDonacionMaterial(pSiscomOpePtrDato));

}

int SeEntregaOtroDiaElApartado(const char *pchrPtrFechaApartado,
			       const char *pchrPtrFechaEntrega)
{
  return !strcmp(pchrPtrFechaApartado,pchrPtrFechaEntrega);
}
int FechaEntregaProgramada(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrFechaEntrega;
lchrPtrFechaEntrega=SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
							"Apartado",
							"FechaHoraE",
							pSiscomOpePtrDato);
   if(!SiscomEsHoyLaFecha(lchrPtrFechaEntrega))
    return 1;
   else
   return 0;
}
int FechaApartadoEntregaHoy(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrFechaApartado;
lchrPtrFechaApartado=SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
								"Apartado",
								"FechaHoraE",
								pSiscomOpePtrDato);
   if(!SiscomEsHoyLaFecha(lchrPtrFechaApartado))
      return 1;
   else
    return 0;
}

const char *FormaPagoApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("Revisar donde se usa y como ............................");
/*
  if(!SiscomComparaCampoAsociadoEntradaCadena("Envio","FormaPago","1",pSiscomOpePtrDato))
  return "11";
  else
  return "2";

  */
return "2";
}
const char *FormaPagoOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
/*
 * Ajustando para la forma de pago ....
  if(!SiscomComparaCampoAsociadoEntradaCadena("Envio","FormaPago","1",pSiscomOpePtrDato))
  return "7";
  else

*/
  return SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato);
}


int PagoApartadoEfectivo(SiscomOperaciones *pSiscomOpePtrDato)
{
 return !SiscomComparaCampoAsociadoEntradaCadena("Envio","formapago","0",pSiscomOpePtrDato);
}
int PagoApartadoTarjeta(SiscomOperaciones *pSiscomOpePtrDato)
{
 return !SiscomComparaCampoAsociadoEntradaCadena("Envio","formapago","1",pSiscomOpePtrDato);
}
void CierraApartadoCualquierOtroDia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

SiscomAsociadoAsociadoLog("Envio","Apartado",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToImporteOrdenCierreOtroDia);
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToApartadoEntregadoOtroDia);
SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToEstadoApartado);

SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToVentasCierraApartado);

}
