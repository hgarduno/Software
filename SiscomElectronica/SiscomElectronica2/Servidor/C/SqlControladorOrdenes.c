#include <SqlControladorOrdenes.h>

void SqlProductosOrden(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];

sprintf(lchrArrSql,
	"								\n\
select a.cveproducto as \"CveProducto\",				\n\
       b.dscproducto as \"DscProducto\",				\n\
       a.precio as \"Precio\",						\n\
       'DEFAULT' as \"NmbTipoPrecio\",					\n\
       'DEFAULT' as \"NmbPrecio\",					\n\
       a.cantidad as \"Cantidad\",					\n\
       c.existencia as \"Existencia\",					\n\
       a.cliente as \"IdCliente\",					\n\
       a.idexpendio as \"IdExpendio\",					\n\
       a.importe as \"ImporteCantidad\",				\n\
       '' as \"SePuedeVender\",						\n\
       1 as \"NumJuegos\",						\n\
       0 as \"EdoRegistro\",						\n\
       a.idventa as \"IdPractica\",					\n\
       '' as \"ClienteFrecuente\",					\n\
       1  as \"PorDescuento\",						\n\
       d.rfc as \"RFC\",						\n\
       0 as   \"IdCaja\"						\n\
from ventas as a inner join						\n\
     productos as b using(cveproducto) inner join			\n\
     existencias as c on (a.cveproducto=c.cveproducto and 		\n\
                          a.idexpendio=c.idexpendio) inner join		\n\
     personas as d on(cliente=idpersona)				\n\
where idventa=%s",
pSAgsSiscom->chrPtrArgConsulta[2]);

SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
