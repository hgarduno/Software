#include <SqlVentas.h>
#include <SqlDirecciones.h>
#include <SqlMediosComunicacion.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlDatosCalculoCredito(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
     lchrArrSql[256];

sprintf(lchrArrSql,
	"select nombre,				\n\
		idplazo,			\n\
		tasa,				\n\
		meses				\n\
	 from tasainteres as a inner join	\n\
	      plazos as b using(idplazo)	\n\
	 where idfinanciadora=%s and 		\n\
	 	idplazo=%s",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdFinanciadora",pSiscomOpePtrDat),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPlazo", pSiscomOpePtrDat));
LogSiscom("%s",lchrArrSql);	
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "DatosCalculoCredito%",
			      lchrArrSql);
SiscomRegistrosAsociadosLog(lchrArrBuffer,
			    "DatosCalculoCredito",
			    pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);  
}

int SqlDatosTiendaVenta(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
     lchrArrSql[1024];

sprintf(lchrArrSql,
	"select * 				\n\
	 from tienda inner join 		\n\
	      tiendas using(idtienda);");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "TiendaVenta%",
			      lchrArrSql);
LogSiscom("%s",lchrArrSql);
}

int SqlRegistraVenta(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
lSisRegProLPtrDat=SiscomObtenArgumentoPrimOperaciones("ProductosOrden",pSiscomOpePtrDat); 
SiscomAgregaArgumentoInsercionSql("SqlInsertaVenta",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaVenta",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToVentas);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaVenta",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDireccionesCliente);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaVenta",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToTelefonos);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaVenta",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToTelefonoCliente);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaVenta",
				       "Envio",
				       "Orden",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToImporteVenta);
SiscomAgregaSentenciasSqlRegistros("SqlInsertaVenta",
				   lchrArrBuffer,
				   lchrArrSql,
				   lSisRegProLPtrDat,
				   pSiscomOpePtrDat,
				   InsertToDetalleVenta);

SiscomAgregaSentenciasSqlRegistros("SqlInsertaVenta",
				   lchrArrBuffer,
				   lchrArrSql,
				   lSisRegProLPtrDat,
				   pSiscomOpePtrDat,
				   UpdateExistencia);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaVenta",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToVendedorVenta);


SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaVenta",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateFolioActualFactura);


if(SiscomCampoAsociadoEntradaOperacionInt("Envio","IdTipoVenta",pSiscomOpePtrDat)==2)
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaVenta",
				       "Envio",
				       "Credito",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToVentaCredito);
if(SiscomCampoAsociadoEntradaOperacionInt("Envio","IdTipoVenta",pSiscomOpePtrDat)==3)
{
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaVenta",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToTotalAbonado);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaVenta",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToEstatusVenta);
}

SiscomAsociadosArgumentoLog("SqlInsertaVenta","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDat);
SiscomReplicaMaquinaLocal("SqlInsertaVenta", lchrArrBuffer, 0, pSiscomOpePtrDat);
}
void InsertToVentaCredito(SiscomOperaciones *pSiscomOpePtrDatos,
			  SiscomRegistroProL *pSiscomRegProLPtrEnt,
			  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into VentaCredito values(%s,%s,%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos),
	 SiscomObtenCampoRegistroProLChar("IdFinanciadora",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdPlazo",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("PagoQuincenal",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("PagoTotal",pSiscomRegProLPtrEnt));
}
void InsertToImporteVenta(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ImporteVenta values(%s,%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos),
	 SiscomObtenCampoRegistroProLChar("SubTotal",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Iva",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Total",pSiscomRegProLPtrEnt));
}

void InsertToVentas(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into Ventas values(%s,%s,%s,%s,'%s','%s','%s');",
	 SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdCliente",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdTipoVenta",pSiscomRegProLPtrEnt),
	 SiscomAsociadoPrimerCampo("FormaEntrega","idformaentrega",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Folio",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("InstruccionesE",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}

void InsertToVentasCliente(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into VentasCliente values(%s);",
	 SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrEnt));
}

void InsertToDetalleVenta(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleVentas values(%s,%s,%s,%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("preciogeneral",pSiscomRegProLPtrEnt),
	"0",
	SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrEnt));
}

void UpdateExistencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update existencia set existencia=existencia-%s where idproducto=%s;",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
}

void InsertToVendedorVenta(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into VendedorVenta values(%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos),
	 SiscomObtenCampoRegistroProLChar("IdVendedor",pSiscomRegProLPtrEnt));
}

void InsertToTotalAbonado(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into TotalAbonado values(%s,0);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos));
}

void InsertToEstatusVenta(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into EstatusVenta values(%s,1);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos));
}

void InsertToAsignacionFolioFactura(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into AsignacionFolioFactura values(%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDatos),
	SiscomCampoAsociadoEntradaOperacion("Envio","Folio",pSiscomOpePtrDatos));
}

void UpdateFolioActualFactura(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql)
{
if(!SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoVenta","3",pSiscomOpePtrDatos))
sprintf(pchrPtrSql,"update folioactual set folio=folio+1 where idtipofolio=2;");
else
sprintf(pchrPtrSql,"update folioactual set folio=folio+1 where idtipofolio=0;");
}


