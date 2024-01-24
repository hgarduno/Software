#include <SqlBusquedaProductos.h>

void SqlBusquedaPorAproximacionClave(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];

sprintf(lchrArrSql,
"								\n\
select clave,							\n\
	idproducto,						\n\
	a.dsc,							\n\
	existencia,						\n\
	precio,							\n\
	nombre,							\n\
	c.cantidad						\n\
from producto as a inner join 					\n\
     inventario as b using(idproducto) inner join		\n\
     preciosproducto as c using(idproducto) inner join 		\n\
     precios as d using(idprecio)				\n\
where clave like '%%%s%%' 					\n\
order by clave,nombre,cantidad					\n\
",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("Productos",
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlTodosLosProductos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];

sprintf(lchrArrSql,
"								\n\
select clave,							\n\
	idproducto,						\n\
	a.dsc,							\n\
	existencia,						\n\
	precio,							\n\
	nombre,							\n\
	c.cantidad						\n\
from producto as a inner join 					\n\
     inventario as b using(idproducto) inner join		\n\
     preciosproducto as c using(idproducto) inner join 		\n\
     precios as d using(idprecio)				\n\
where nombre='MENUDEO'						\n\
order by clave,nombre,cantidad");
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("Productos",
				  lchrArrSql,
				  pSAgsSiscom);

}
