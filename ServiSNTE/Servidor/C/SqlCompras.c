#include <SqlCompras.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlRegistraCompra(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
lSisRegProLPtrDat=SiscomObtenArgumentoPrimOperaciones("ProductosOrden",
						pSiscomOpePtrDat);
SiscomAgregaArgumentoInsercionSql("SqlInsertaCompra",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaCompra",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToCompras);

SiscomAgregaSentenciasSqlRegistros("SqlInsertaCompra",
				   lchrArrBuffer,
				   lchrArrSql,
				   lSisRegProLPtrDat,
				   pSiscomOpePtrDat,
				   InsertToDetalleCompra);

SiscomAgregaSentenciasSqlRegistros("SqlInsertaCompra",
				   lchrArrBuffer,
				   lchrArrSql,
				   lSisRegProLPtrDat,
				   pSiscomOpePtrDat,
				   UpdateExistenciasAlmacen);
if(!SiscomReplicaMaquinaLocal("SqlInsertaCompra", lchrArrBuffer, 0, pSiscomOpePtrDat))
{
LogSiscom("No se encontraron datos de la maquina a enviar");
}
}

int SqlRegistraPrecioCompra(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaPrecio",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "Costo",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToCostoBruto2);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "Costo",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateDetalleCompraPrecios);

SiscomReplicaMaquinaLocal("SqlInsertaPrecio", lchrArrBuffer, 0, pSiscomOpePtrDat);
}
void UpdateDetalleCompraPrecios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update detallecompras set preciocompra=%s,ivacompra=%s,total=%s*cantidad  where idcompra=%s and idproducto=%s;",
	SiscomObtenCampoRegistroProLChar("Costo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("CostoIva",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("CostoMIva",pSiscomRegProLPtrEnt),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCompra",pSiscomOpePtrDatos),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDatos));




}
void InsertToCostoBruto2(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into costobruto values(%s,%s,%s,%s,'%s',%s);",
	SiscomObtenCampoRegistroProLChar("IdCosto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Costo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("CostoMIva",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("CostoIva",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDatos));

}

void InsertToImporteCompra(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ImporteCompra values(%s,%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCompra",pSiscomOpePtrDatos),
	 SiscomObtenCampoRegistroProLChar("SubTotal",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Iva",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Total",pSiscomRegProLPtrEnt));
}

void InsertToCompras(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Compras values(%s,%s,%s,%s,'%s','%s','%s');",
	 SiscomObtenCampoRegistroProLChar("IdCompra",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdProveedor",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdTipoDocumento",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdConcepto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("SerieFactura",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Folio",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
LogSiscom("%s",pchrPtrSql);
}

void InsertToDetalleCompra(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
const char *lchrPtrCostoBruto;
sprintf(pchrPtrSql,
	"insert into DetalleCompras values(%s,%s,'%s',%s,%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCompra",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Serie",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	"0",
	"0",
	"0");
LogSiscom("%s",pchrPtrSql);
}

void UpdateExistenciasAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Existencia set existencia=existencia+%s where idproducto=%s;",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
LogSiscom("%s",pchrPtrSql);
}

void UpdateExistenciasStock(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Stock set existencia=%s where idproducto=%s;",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
}
void UpdateExistenciasConsignacion(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Consignacion set existencia=%s where idproducto=%s;",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
}
void InsertToProductoCodigoBarras(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
const char *lchrPtrCostoBruto;
lchrPtrCostoBruto=SiscomObtenCampoRegistroProLChar("CostoBruto",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
	"insert into ProductoCodigoBarras values('%s','%s',%s,%s);",
	SiscomObtenCampoRegistroProLChar("Serie",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("CodigoBarras",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	"1");
}

void InsertToCostoBrutoCompra(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CostoBruto values(%s,%s,%s,%s,'%s',%s);",
	SiscomObtenCampoRegistroProLChar("IdCostoBruto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("CostoBruto",pSiscomRegProLPtrEnt),
	"0",
	"0",
	SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
}


