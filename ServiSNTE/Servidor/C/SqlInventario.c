#include <SqlInventario.h>
#include <SqlTransferencias.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlProgramaInventario(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaInventario",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaInventario",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToInventario);
SiscomReplicaMaquinaLocal("SqlInsertaInventario", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlPreRegistraInventario(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;

SiscomAgregaArgumentoInsercionSql("SqlInsertaInventario",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaInventario",
				     "Envio",
				     "Producto",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDetalleInventarioPaso);

SiscomReplicaMaquinaLocal("SqlInsertaInventario", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlRegistraInventario(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaInventario",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaInventario",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateToInventario);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaInventario",
				     "Envio",
				     "Productos",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDetalleInventario);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaInventario",
				     "Envio",
				     "Productos",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateToExistencia);
SiscomReplicaMaquinaLocal("SqlInsertaInventario", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlVerificarInventarioEnCurso(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
    lchrArrSql[512];
sprintf(lchrArrSql,
    "select *                         \n\
     from inventario                  \n\
     where idmotivoinventario='0'");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "Inventarios%",
                 lchrArrSql);
}

int SqlRecuperaInventario(SiscomOperaciones *pSiscomOpePtrDat)
{
    char lchrArrSqlDetalleTransferencia[1024],
         lchrArrSqlProductosTransferencia[1024],
         lchrArrBuffer[1024];
    SqlDetalleTransferencia(pSiscomOpePtrDat,lchrArrSqlDetalleTransferencia);
    SqlProductosTransferencia(pSiscomOpePtrDat,lchrArrSqlProductosTransferencia);
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "DetalleTransferencia%ProductosTransferencia%",
                  lchrArrSqlDetalleTransferencia,
                  lchrArrSqlProductosTransferencia);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"DetalleTransferencia",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"ProductosTransferencia",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
}

int SqlCancelaInventario(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlCancelaInventario",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlCancelaInventario",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateToInventario);

SiscomReplicaMaquinaLocal("SqlCancelaInventario", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlProgramaInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaInventario",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaInventario",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToInventarioAlmacen);

SiscomReplicaMaquinaLocal("SqlInsertaInventario", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlPreRegistraInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaInventario",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaInventario",
				     "Envio",
				     "Producto",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDetalleInventarioAlmacenPaso);

SiscomReplicaMaquinaLocal("SqlInsertaInventario", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlRegistraInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaInventario",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaInventario",
				     "Envio",
				     "Productos",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDetalleInventarioAlmacen);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaInventario",
				     "Envio",
				     "Productos",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateToExistenciaAlmacen);

SiscomReplicaMaquinaLocal("SqlInsertaInventario", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlVerificarInventarioEnCursoAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
    lchrArrSql[512];
sprintf(lchrArrSql,
    "select *                         \n\
     from InventarioAlmacen                  \n\
     where idmotivoinventario='0'");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "Inventarios%",
                 lchrArrSql);
}

int SqlRecuperaInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
    char lchrArrSqlDetalleTransferencia[1024],
         lchrArrSqlProductosTransferencia[1024],
         lchrArrBuffer[1024];
    SqlDetalleTransferencia(pSiscomOpePtrDat,lchrArrSqlDetalleTransferencia);
    SqlProductosTransferencia(pSiscomOpePtrDat,lchrArrSqlProductosTransferencia);
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "DetalleTransferencia%ProductosTransferencia%",
                  lchrArrSqlDetalleTransferencia,
                  lchrArrSqlProductosTransferencia);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"DetalleTransferencia",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"ProductosTransferencia",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
}

int SqlCancelaInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlCancelaInventario",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlCancelaInventario",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateToInventarioAlmacen);

SiscomReplicaMaquinaLocal("SqlCancelaInventario", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

void InsertToInventario(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Inventario values(%s,'%s',%s);",
	 SiscomObtenCampoRegistroProLChar("IdInventario",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdMotivoInventario",pSiscomRegProLPtrEnt));
}

void InsertToDetalleInventarioPaso(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleInventarioPaso values(%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdInventario",pSiscomOpePtrDatos),
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt));
}

void InsertToDetalleInventario(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleInventario values(%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdInventario",pSiscomOpePtrDatos),
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt));
}

void UpdateToInventario(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Inventario set IdMotivoInventario=%s where idInventario=%s;",
	 SiscomObtenCampoRegistroProLChar("IdMotivoInventario",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdInventario",pSiscomRegProLPtrEnt));
}

void UpdateToExistencia(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update Existencia set Existencia=%s where idproducto=%s;",
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
}

void InsertToInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into InventarioAlmacen values(%s,'%s',%s);",
	 SiscomObtenCampoRegistroProLChar("IdInventario",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdMotivoInventario",pSiscomRegProLPtrEnt));
}

void InsertToDetalleInventarioAlmacenPaso(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleInventarioAlmacenPaso values(%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdInventario",pSiscomOpePtrDatos),
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt));
}

void InsertToDetalleInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleInventarioAlmacen values(%s,%s,%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdInventario",pSiscomOpePtrDatos),
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt));
}

void UpdateToInventarioAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update InventarioAlmacen set IdMotivoInventario=%s where idInventario=%s;",
	 SiscomObtenCampoRegistroProLChar("IdMotivoInventario",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdInventario",pSiscomRegProLPtrEnt));
}

void UpdateToExistenciaAlmacen(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update ExistenciaAlmacen set Existencia=%s where idproducto=%s;",
	 SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
}

void UpdateToExistenciaAlmacen2(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update ExistenciaAlmacen set Existencia=Existencia-%s where idproducto=%s;",
	 SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
}

