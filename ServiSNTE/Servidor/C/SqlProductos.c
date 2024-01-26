#include <SqlProductos.h>
#include <SqlPrecios.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include <stdio.h>

int SqlPreciosDescuentosProducto(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
char lchrArrSqlCostoBruto[256],
     lchrArrSqlPrecioGeneral[256],
     lchrArrSqlPrecioForaneo[256],
     lchrArrSqlDescuento[256];
SqlDescuentosProducto(pSiscomOpePtrDat,lchrArrSqlDescuento);
SqlCostosBrutoProducto(pSiscomOpePtrDat,lchrArrSqlCostoBruto);
SqlPreciosForaneoProducto(pSiscomOpePtrDat,lchrArrSqlPrecioForaneo);
SqlPreciosGeneralProducto(pSiscomOpePtrDat,lchrArrSqlPrecioGeneral);
 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "PreciosForaneos%PreciosGeneral%CostoBruto%Descuentos%",
			      lchrArrSqlPrecioForaneo,
			      lchrArrSqlPrecioGeneral,
			      lchrArrSqlCostoBruto,
			      lchrArrSqlDescuento);

}

void SqlPreciosGeneralProducto(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 			\n\
	 from preciogeneral 		\n\
	 where idproducto=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDat));
}




void SqlPreciosForaneoProducto(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 			\n\
	 from precioforaneo 		\n\
	 where idproducto=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDat));
}
void SqlCostosBrutoProducto(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 			\n\
	 from  costobruto 		\n\
	 where idproducto=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDat));
}
void SqlDescuentosProducto(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 			\n\
	 from preciogeneral 		\n\
	 where idproducto=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDat));
}


int SqlProductoPorCodigoBarras(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select * 						\n\
	 from productocodigobarras inner join 			\n\
	      productos using(idproducto) inner join 		\n\
	      preciogeneral using(idproducto) inner join 	\n\
	      existencia using(idproducto) inner join 		\n\
	      productoproveedor using(idproducto)		\n\
	 where codigobarras='%s'				\n\
	 order by fecha desc,preciogeneral desc 		\n\
	 limit 1",
	 SiscomCampoAsociadoEntradaOperacion("Envio",
	 				     "CodigoBarras",
					     pSiscomOpePtrDat));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "ProductoPorCodigo%",
			      lchrArrSql);

}

int SqlPreciosProducto(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaProducto",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaProducto",
				     "Envio",
				     "CostoBruto",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToCostoBruto);
SiscomReplicaMaquinaLocal("SqlInsertaProducto", lchrArrBuffer, 0, pSiscomOpePtrDat);

SiscomReplicaMaquinasSistema("Servidor",
			     "SqlInsertaProducto",
			     lchrArrBuffer,
			     gSiscomRegProLPtrMemoria,
			     0,
			    pSiscomOpePtrDat);
}

int SqlRegistraProducto(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDat);

SiscomAgregaArgumentoInsercionSql("SqlInsertaProducto",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToProductos);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToProductoProveedor);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToExistencia);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToExistenciaAlmacen);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToProductoCodigoBarrasCrea);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToEstatusProducto);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDepartamentoProducto);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToStock);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToProductoStockRegProd);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToPrecioGeneral2);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToUltimoPrecioGeneral2);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToCostoBruto3);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToUltimoCosto);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDescuentoEmpresa);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToUltimoDescuentoEmpresa);
SiscomReplicaMaquinasSistema("Servidor",
			     "SqlInsertaProducto",
			     lchrArrBuffer,
			     gSiscomRegProLPtrMemoria,
			     0,
			    pSiscomOpePtrDat);
}
int SqlActualizandoStock(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaProducto",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateStock);
/*
SiscomReplicaMaquinasSistema("Servidor",
			     "SqlInsertaProducto",
			     lchrArrBuffer,
			     gSiscomRegProLPtrMemoria,
			     0,
			    pSiscomOpePtrDat);
*/
SiscomReplicaMaquinaSistema(
	SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDat),
			    "SqlInsertaProducto",
			    lchrArrBuffer,
			    gSiscomRegProLPtrMemoria,
			    0,
			    pSiscomOpePtrDat);
}

void InsertToCostoBruto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CostoBruto values(%s,%s,%s,%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdCosto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Costo",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("CostoMIva",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("CostoIva",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}


void InsertToCostoBrutoProducto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CostoBrutoProducto values(%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdCosto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}

void InsertToProductos(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Productos(idproducto,numproducto,nombreproducto,modelo)  values(%s,%s,'%s','%s');",
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("NumeroProducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Modelo",pSiscomRegProLPtrEnt));
}

void InsertToProductoProveedor(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ProductoProveedor  values(%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdProveedor",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt));
}

void InsertToExistencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Existencia values(%s,0);",
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt));
}

void InsertToExistenciaAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ExistenciaAlmacen values(%s,0);",
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt));
}

void InsertToProductoCodigoBarrasCrea(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ProductoCodigoBarras values('%s',%s);",
	 SiscomObtenCampoRegistroProLChar("CodigoBarras",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt));
}

void InsertToEstatusProducto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into EstatusProducto values(%s,1);",
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt));
}

void InsertToDepartamentoProducto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DepartamentoProducto values(%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdDepartamento",pSiscomRegProLPtrEnt));
}

void InsertToStock(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Stock values(%s,0);",
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt));
}
void InsertToProductoStockRegProd(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ProductoStock values(%s);",
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt));
}

void UpdateStock(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update stock set existencia=%s where idproducto=%s;",
	SiscomCampoAsociadoEntradaOperacion("Envio","Cantidad",pSiscomOpePtrDatos),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDatos));
}
const char *DescuentoProveedor(SiscomOperaciones *pSiscomOpePtrDatos,
			       const char *pchrPtrDescuento)
{
const char *lchrPtrDescuento;
lchrPtrDescuento=SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
							     "Descuento",
							     pchrPtrDescuento,
							     pSiscomOpePtrDatos);
return lchrPtrDescuento ? lchrPtrDescuento : "0";
}
void InsertToDescuentoEmpresa(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into DescuentosEmpresa  values(%s,%s,%s,%s,%s,%s,'%s');",
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						  "Descuento",
						  "iddescuentoempresa",
						  pSiscomOpePtrDatos),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDatos),
	DescuentoProveedor(pSiscomOpePtrDatos,"d1"),	
	DescuentoProveedor(pSiscomOpePtrDatos,"d2"),	
	DescuentoProveedor(pSiscomOpePtrDatos,"d3"),	
	DescuentoProveedor(pSiscomOpePtrDatos,"d4"),	
	SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDatos));
}

void InsertToUltimoDescuentoEmpresa(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into UltimoDescuentoEmpresa values(%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdProveedor",pSiscomOpePtrDatos),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						    "Descuento",
						    "iddescuentoempresa",
						    pSiscomOpePtrDatos));
}
