#include <SqlCompraImportacion.h>
#include <SqlPesoProducto.h>
#include <SiscomInsercionesSql.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SqlActualizandoCompraRegistrada(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],lchrArrSql[256];

SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSisOpePtrDato,
                                        UpdateDetalleCompraImportacionRegistrada);

SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSisOpePtrDato,
                                        UpdateExistenciaCompraImportacion);

SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSisOpePtrDato,
                                        UpdateCompraImportacionPorActualizacion);

SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
                                        "Envio",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSisOpePtrDato,
                                        UpdateRegistroCompraImportacionPorActualizacion);

SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
                                        "Envio",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSisOpePtrDato,
                                        UpdateGeneralesCompraImportacion);

SiscomEnviaRegistrosAlServidorBD("SqlCompraImportacion",
			       lchrArrBuffer,
			       pSisOpePtrDato);
return 0;
}
int SqlProductosCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
SqlConsultandoProductosCompra(pSiscomOpePtrDato);

return 0;
}

int SqlGuardaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteDescripcionCompraImportacion);

SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteDetalleCompraImportacion);
SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteProductoProveedorImportacion);
SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteProveedoresCompraImportacion);

SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteCompraImportacion);


SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToCompraImportacion);


SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToDescripcionCompraImportacion);
SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        InsertToDetalleCompraImportacion);

SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        InsertToProductoProveedorImportacion);

SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
                                        "Proveedores",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        InsertToProveedoresCompraImportacion);

SiscomEnviaRegistrosAlServidorBD("SqlCompraImportacion",
			       lchrArrBuffer,
			       pSiscomOpePtrDato);
return 0;
}
int SqlRegistraCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToRegistroCompra);
SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        InsertToProductoCompraImportacion);

SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        UpdateExistenciaCompraImportacion);

SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateRegistroCompraImportacion);

SiscomEnviaRegistrosAlServidorBD("SqlCompraImportacion",
			       lchrArrBuffer,
			       pSiscomOpePtrDato);
return 0;
}
int SqlRegistroParcialCompraImportacionFaltaronProductos(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];

SiscomAgregaSentenciasSqlCampoAsociadoAsociado("SqlCompraImportacion",
                                        "Envio",
					"Parcial",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        InsertToProductoCompraImportacionPorCambio);

SiscomAgregaSentenciasSqlCampoAsociadoAsociado("SqlCompraImportacion",
                                        "Envio",
					"Parcial",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        UpdateExistenciaCompraImportacionPorCambio);

SiscomAgregaSentenciasSqlDelAsociado("SqlCompraImportacion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateRegistroCompraImportacionPorCambio);


SiscomAgregaSentenciasSqlCampoAsociadoAsociado("SqlCompraImportacion",
                                        "Envio",
					"Compra",
                                        "Productos",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        UpdateCompraImportacionPorModificacion);
SiscomAgregaSentenciasSqlCampoAsociado("SqlCompraImportacion",
                                        "Envio",
					"Compra",
                                        lchrArrBuffer,
                                        lchrArrSql,
                                        pSiscomOpePtrDato,
                                        UpdateGeneralesCompraImportacion);

SiscomEnviaRegistrosAlServidorBD("SqlCompraImportacion",
			       lchrArrBuffer,
			       pSiscomOpePtrDato);


return 0;

}


void UpdateCompraImportacionPorModificacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"update compras set precio=%s,preciosiniva=%f,importe=%s,cantidad=cantidad+%s where idcompra=%s and cveproducto='%s';",
	 SiscomObtenCampoRegistroProLChar("CostoFinalMasCosAdm",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLFloat("CostoFinalMasCosAdm",pSiscomRegProLPtrDato)/1.16,
	 SiscomObtenCampoRegistroProLChar("CostoPartida",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
         SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Compra","IdCompraImportacion",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));


}

void UpdateCompraImportacionPorActualizacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update compras set precio=%s,preciosiniva=%f,importe=%s,cantidad=cantidad+%s where idcompra=%s and cveproducto='%s';",
	 SiscomObtenCampoRegistroProLChar("CostoFinalMasCosAdm",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLFloat("CostoFinalMasCosAdm",pSiscomRegProLPtrDato)/1.16,
	 SiscomObtenCampoRegistroProLChar("CostoPartida",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
         SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));


}

void InsertToRegistroCompra(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into RegistroCompra values(%s,0,'%s',%s);",
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrDato),
"0");
}

void InsertToProductoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Compras values('%s','%s',%s,%s,%s,0,%s,%s,'Contado','%s',%s,%.2f,%s);",
SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoPartida",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("IdProveedor",pSiscomRegProLPtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdResponsable",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","NumFactura",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("CostoFinalMasCosAdm",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLFloat("CostoFinalMasCosAdm",pSiscomRegProLPtrDato)/1.16,
SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSiscomOpePtrDato));
}

void InsertToProductoCompraImportacionPorCambio(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Compras values('%s','%s',%s,%s,%s,0,%s,%s,'Contado','%s',%s,%.2f,%s);",
SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoPartida",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("IdProveedor",pSiscomRegProLPtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Compra","IdResponsable",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Compra","IdExpendio",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Compra","NumFactura",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("CostoFinalMasCosAdm",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLFloat("CostoFinalMasCosAdm",pSiscomRegProLPtrDato)/1.16,
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Compra","IdCompraImportacion",pSiscomOpePtrDato));
}

void UpdateExistenciaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"update materialbodega set existencia=existencia+%s where idbodega=%s and cveproducto='%s';",
SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdBodega",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));
}

void UpdateExistenciaCompraImportacionPorCambio(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"update materialbodega set existencia=existencia+%s where idbodega=%s and cveproducto='%s';",
SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Compra","IdBodega",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));
}

void UpdateRegistroCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"update RegistroCompra set Importe=%s where IdCompra=%s;",
SiscomObtenCampoRegistroProLChar("ImporteFactura",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato));
}

void UpdateRegistroCompraImportacionPorActualizacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"update RegistroCompra set Importe=%s where IdCompra=%s;",
SiscomCampoAsociadoEntradaOperacion("Envio","ImporteFactura",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSiscomOpePtrDato));
}
void UpdateRegistroCompraImportacionPorCambio(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"update RegistroCompra set Importe=%s where IdCompra=%s;",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Compra","ImporteFactura",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Compra","IdCompraImportacion",pSiscomOpePtrDato));
}

void UpdateGeneralesCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update CompraImportacion set NumeroFactura=%s,CostoEnvioDolares=%s,CostoDolar=%s,CostoAdministrativo=%s,numeropartidas=%s,pesocompra=%s,importefactura=%s where IdCompraImportacion=%s",
SiscomObtenCampoRegistroProLChar("NumFactura",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoEnvio",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoDolar",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoAdministrativo",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("NumPartidas",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("PesoCompra",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("ImporteFactura",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato));
}
/*
void UpdateGeneralesCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update CompraImportacion set NumeroFactura=%s,CostoEnvioDolares=%s,CostoDolar=%s,CostoAdministrativo=%s,numeropartidas=%s where IdCompraImportacion=%s",
SiscomObtenCampoRegistroProLChar("NumFactura",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoEnvio",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoDolar",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoAdministrativo",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("NumPartidas",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato));

}
*/
void DeleteDescripcionCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql, "delete from DescripcionCompraImportacion where IdCompraImportacion=%s;",
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato));
}

void DeleteProveedoresCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql, "delete from ProveedoresCompraImportacion where IdCompraImportacion=%s;",
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato));
}

void DeleteCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql, "delete from CompraImportacion where IdCompraImportacion=%s;",
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato));
}

void DeleteDetalleCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql, "delete from DetalleCompraImportacion where IdCompraImportacion=%s;",
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato));
}
void DeleteProductoProveedorImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql, "delete from ProductoProveedorImportacion where IdCompraImportacion=%s;",
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato));
}

void InsertToCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{

/*{Definicion Tabla CompraImportacion
 * idcompraimportacion  
 * idempresa             
 * fecha                
 * numerofactura       
 * importefactura     
 * costoenviodolares
 * costodolar      
 * costoadministrativo 
 * ponderacioncostoadministrativo
 * numeropartidas               
 * pesocompra
 }*/
sprintf(pchrPtrSql, "insert into CompraImportacion values(%s,%s,'%s','%s',%s,%s,%s,%s,%s,%s,%s);",
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Empresa","IdEmpresa",pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("NumFactura",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("ImporteFactura",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoEnvio",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoDolar",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CostoAdministrativo",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("PonderacionCostoAdministrativo",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("NumPartidas",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("PesoCompra",pSiscomRegProLPtrDato));
}

void InsertToDescripcionCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DescripcionCompraImportacion values(%s,'%s');",
SiscomObtenCampoRegistroProLChar("IdCompraImportacion",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrDato));
}


void InsertToProductoProveedorImportacion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ProductoProveedorImportacion values(%s,%s,'%s');",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Empresa","IdEmpresa",pSiscomOpePtrDato),
	SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));


}

void InsertToProveedoresCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ProveedoresCompraImportacion(IdCompraImportacion,IdEmpresa)  values(%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrDato));
}

void InsertToDetalleCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleCompraImportacion(IdCompraImportacion, CveProducto,Cantidad,CostoUnitario,IdEmpresa) values(%s,'%s',%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("CostoUnitarioDolares",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("IdProveedor",pSiscomRegProLPtrDato));
}
int SqlProductosPorFiltro(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"select cveproducto as \"CveProducto\"	\n\
	 from productos				\n\
	 where cveproducto like '%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Filtro",pSiscomOpePtrDato));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Productos%",
		   lchrArrSql);
return 0;

}
void UpdateDetalleCompraImportacionRegistrada(SiscomOperaciones *pSisOpePtrDato,
					      SiscomRegistroProL *pSisRegProLPtrDatos,
					      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update detallecompraimportacion set cantidad=cantidad+%s where idCompraImportacion=%s and cveproducto='%s'",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSisRegProLPtrDatos),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSisOpePtrDato),
	SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrDatos));
}
void SqlFormaConsultaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
				       char *pchrPtrSqlConsulta)
{
const char *lchrPtrIdCompraImportacion;
lchrPtrIdCompraImportacion=SiscomCampoAsociadoEntradaOperacion("Envio",
							       "IdCompra",
							       pSiscomOpePtrDato);
if(lchrPtrIdCompraImportacion)
sprintf(pchrPtrSqlConsulta,
	"select a.*,							  		\n\
		b.descripcion,								\n\
		c.razonsocial,								\n\
		c.rfc									\n\
	 from compraimportacion as a inner join 					\n\
	      descripcioncompraimportacion as b using(idcompraimportacion) inner join	\n\
	      empresas as c using(idempresa) 						\n\
	 where idcompraimportacion=%s 							\n\
	 order by fecha desc",
	 lchrPtrIdCompraImportacion);
else
if(1) /* Se debe integrar la consulta por rango de fecha 
       */
sprintf(pchrPtrSqlConsulta,
	"select a.*,							  		\n\
		b.descripcion,								\n\
		c.razonsocial,								\n\
		c.rfc									\n\
	 from compraimportacion as a inner join 					\n\
	      descripcioncompraimportacion as b using(idcompraimportacion) inner join	\n\
	      empresas as c using(idempresa) 						\n\
	 order by fecha desc");
}
void SqlFormaConsultaDetalleCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato,
					      char *pchrPtrSqlConsulta)
{
const char *lchrPtrIdCompraImportacion;
lchrPtrIdCompraImportacion=SiscomCampoAsociadoEntradaOperacion("Envio",
							       "IdCompra",
							       pSiscomOpePtrDato);
/*
 *CDMX Domingo 12 Noviembre del 2022
 Ajustando la compra de importacion con varios proveedores ...
if(lchrPtrIdCompraImportacion)
sprintf(pchrPtrSqlConsulta,
	"											\n\
select distinct a.*,											\n\
	b.*,											\n\
	c.cveproveedor,										\n\
	d.idproveedor										\n\
from detallecompraimportacion as a inner join 							\n\
	pesoproducto as b using(cveproducto) left outer join					\n\
	clavesproveedores as c using(cveproducto) left outer join				\n\
	ProductoProveedorImportacion as d on (a.idcompraimportacion=d.idcompraimportacion and	\n\
	      				      a.cveproducto=d.cveproducto)			\n\
	 where a.idcompraimportacion=%s and							\n\
	       idempresa in (select idempresa 							\n\
	                    from proveedorescompraimportacion \n\
			    where idcompraimportacion=%s)					\n\
	 order by idconsecutivo",
	 lchrPtrIdCompraImportacion,
	 lchrPtrIdCompraImportacion);

else
*/
if(lchrPtrIdCompraImportacion)
/*
 * Tepotzotlan Mexico a 10 de abril del 2023 
 * un dia antes de la operacion de prostata
sprintf(pchrPtrSqlConsulta,
	"											\n\
select distinct a.*,										\n\
	b.*,											\n\
	c.cveproveedor,										\n\
	d.idempresa,										\n\
	d.razonsocial										\n\
from detallecompraimportacion as a inner join 							\n\
	pesoproducto as b using(cveproducto) left outer join					\n\
	clavesproveedores as c using(cveproducto) inner join					\n\
	empresas as d using(idempresa)								\n\
	 where a.idcompraimportacion=%s and							\n\
	       idempresa in (select idempresa 							\n\
	                    from proveedorescompraimportacion 					\n\
			    where idcompraimportacion=%s)					\n\
	 order by d.idempresa,idconsecutivo",
	 lchrPtrIdCompraImportacion,
	 lchrPtrIdCompraImportacion);
*/
sprintf(pchrPtrSqlConsulta,
	"select a.*,									\n\
        b.cveproveedor,									\n\
        c.peso,										\n\
	d.razonsocial									\n\
from detallecompraimportacion as a inner join						\n\
        clavesproveedores as b on (a.idempresa=b.idempresa and 				\n\
                                   a.cveproducto=b.cveproducto) inner join		\n\
        pesoproducto as c on a.cveproducto=c.cveproducto inner join 			\n\
        empresas as d on a.idempresa=d.idempresa					\n\
where idcompraimportacion=%s								\n\
order by a.idempresa,idconsecutivo",
     lchrPtrIdCompraImportacion);
else
if(1)
sprintf(pchrPtrSqlConsulta,
	"select *					\n\
	 from detallecompraimportacion as a inner join 	\n\
	      pesoproducto as b using(cveproducto)	\n\
	 order by idconsecutivo");

LogSiscom("%s",pchrPtrSqlConsulta);
}

void SqlFormaConsultaProveedoresCompraImportacion(SiscomOperaciones *pSisOpePtrDato,
					       char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select a.*,						\n\
		b.razonsocial,					\n\
		b.rfc						\n\
	 from ProveedoresCompraImportacion as a  inner join 	\n\
	      empresas as b using(idempresa)			\n\
	 where idCompraImportacion=%s				\n\
	 order by idproveedor desc",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCompra",pSisOpePtrDato));
}

int SqlConsultaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSqlCompraImp[512],
	lchrArrSqlDetalleCompraImp[1024],
	lchrArrSqlProveedoresCompImp[512];

SqlFormaConsultaCompraImportacion(pSiscomOpePtrDato,lchrArrSqlCompraImp);
SqlFormaConsultaDetalleCompraImportacion(pSiscomOpePtrDato,lchrArrSqlDetalleCompraImp);
SqlFormaConsultaProveedoresCompraImportacion(pSiscomOpePtrDato,lchrArrSqlProveedoresCompImp);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "Compra%DetalleCompra%ProveedoresCompra%",
			      lchrArrSqlCompraImp,
			      lchrArrSqlDetalleCompraImp,
			      lchrArrSqlProveedoresCompImp);
return 0;
}

int SqlConsultaComprasImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSqlCompraImp[512];
SqlFormaConsultaCompraImportacion(pSiscomOpePtrDato,lchrArrSqlCompraImp);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "Compra%",
			      lchrArrSqlCompraImp);
return 0;
}
void SqlConsultaUltimaCompraProducto(SiscomOperaciones *pSiscomOpePtrDato,
				     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"								\n\
	select a.fecha,							\n\
		a.idempresa,						\n\
		b.*							\n\
	from compraimportacion as a inner join				\n\
	     detallecompraimportacion as b using(idcompraimportacion)	\n\
	where cveproducto='%s'						\n\
	order by fecha desc						\n\
	limit 1",
 SiscomCampoAsociadoEntradaOperacion("Envio","CveProducto",pSiscomOpePtrDato));	
}
void SqlConsultandoClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato,
			       char *pchrPtrSql)
{
const char *lchrPtrCveProducto,
	   *lchrPtrIdEmpresa;
lchrPtrCveProducto=SiscomCampoAsociadoEntradaOperacion("Envio",
						       "CveProducto",
						       pSiscomOpePtrDato);
lchrPtrIdEmpresa=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdEmpresa",
						     pSiscomOpePtrDato);
sprintf(pchrPtrSql,
	"select * 			\n\
	 from clavesproveedores 	\n\
	 where cveproducto ='%s' and 	\n\
	       idempresa=%s",
	      lchrPtrCveProducto,
	      lchrPtrIdEmpresa);
	 
}
int SqlProductoImportadoInf(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrSqlPesoProducto[512],
	lchrArrSqlUltimaCompra[512],
	lchrArrBuffer[512],
	lchrArrSqlClaveProveedor[512];
SqlConsultaPesoProducto(pSisOpePtrDato,lchrArrSqlPesoProducto);
SqlConsultaUltimaCompraProducto(pSisOpePtrDato,lchrArrSqlUltimaCompra);
SqlConsultandoClaveProveedor(pSisOpePtrDato,lchrArrSqlClaveProveedor);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSisOpePtrDato,
			      "PesoProducto%UltimaCompra%ClaveProveedor%",
			      lchrArrSqlPesoProducto,
			      lchrArrSqlUltimaCompra,
			      lchrArrSqlClaveProveedor);
return 0;
}
char *AsignaMemoriaParaCadenaSql(const char *pchrPtrCondicion)
{
char *lchrPtrMemoria;
int lintTamano=256+strlen(pchrPtrCondicion);
LogSiscom("Asignando %d",lintTamano);
lchrPtrMemoria=(char *)malloc(lintTamano);
return lchrPtrMemoria;
}
void FormaConsultaCompletaProductosImportacion(const char *pchrPtrCondicion,
					       char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"					\n\
select cveproducto,				\n\
	cveproveedor,				\n\
	0 as peso 				\n\
from clavesproveedores left outer join		\n\
	pesoproducto  using(cveproducto)	\n\
%s",pchrPtrCondicion);
	
}
int SqlCompletaProductosImportacion(SiscomOperaciones *pSisOpePtrDat)
{
const char *lchrPtrCondicion;
char *lchrPtrBuffer,
	*lchrPtrSql,
	lchrArrBuffer[8192];
lchrPtrCondicion=SiscomObtenCampoArgumento4("Condicion","CondicionConsulta",pSisOpePtrDat);
lchrPtrSql=AsignaMemoriaParaCadenaSql(lchrPtrCondicion);
lchrPtrBuffer=AsignaMemoriaParaCadenaSql(lchrPtrCondicion);
FormaConsultaCompletaProductosImportacion(lchrPtrCondicion,lchrPtrSql);
LogSiscom("-------------");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSisOpePtrDat,
			      "Productos%",
			      lchrPtrSql);
LogSiscom("-------------");
return 0;
}


void SqlFormaCadenaProductosCompraImportacion(SiscomOperaciones *pSisOpePtrDatos,
				  char *pchrPtrSql)
{
char lchrArrBuffer[128];

sprintf(pchrPtrSql,
	"select *		\n\
	 from compras 		\n\
	 where idcompra=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","IdCompraImportacion",pSisOpePtrDatos));


}
void SqlConsultandoProductosCompra(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrSql[128],lchrArrBuffer[128];;
SqlFormaCadenaProductosCompraImportacion(pSisOpePtrDatos,lchrArrSql);
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
				       "SqlProductosCompraImportacion",
				       lchrArrBuffer,
				       pSisOpePtrDatos);
}
