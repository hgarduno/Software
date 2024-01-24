#include <SqlOrdenCompraImportacion.h>
#include <SqlClavesProveedor.h>
#include <SiscomDesarrolloMacros.h>
int SqlProductoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[128],
	lchrArrSqlComprasImportacion[512],
	lchrArrSqlClaveProveedor[512];
SqlFormaConsultaProductoClaveProveedor(pSiscomOpePtrDato,lchrArrSqlClaveProveedor);
SqlFormaConsultaDetalleCompraImportacion2(pSiscomOpePtrDato,lchrArrSqlComprasImportacion);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDato,
			      "ProductoProveedor%Compras%",
			      lchrArrSqlClaveProveedor,
			      lchrArrSqlComprasImportacion);
return 0;
}
void SqlFormaConsultaDetalleCompraImportacion2(SiscomOperaciones *pSiscomOpePtrDato,
			               char *pchrPtrSqlCompraImportacion)
{
sprintf(pchrPtrSqlCompraImportacion,
	"select a.fecha,								\n\
		b.idcompraImportacion,							\n\
		b.cantidad,								\n\
		b.costounitario,							\n\
		b.cantidad*costounitario as costototal					\n\
	from 	CompraImportacion as a inner join 					\n\
		DetalleCompraImportacion as b using(IdCompraImportacion) 		\n\
	where idCompraImportacion in(select IdCompraImportacion				\n\
			     	     from CompraImportacion				\n\
			     	     where CveProducto='%s' and 			\n\
			                   IdEmpresa=%s)",
	SiscomCampoAsociadoEntradaOperacion("Envio","Clave",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdEmpresa",pSiscomOpePtrDato));
}
