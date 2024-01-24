#include <SqlProductosNoSincronizados.h>
void SqlProductosNoSincronizados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"						\n\
select *						\n\
from productoexpendionosincronizado as a inner join	\n\
	empresas as b using(idempresa)");
SiscomConsultaBaseAsignaArgumento("SqlProductosASincronizar",
				  lchrArrSql,
				  pSAgsSiscom);
}

void SqlProductosParaSincronizar(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"						\n\
select distinct cveproducto as \"CveProducto\",		\n\
	idpersona as \"IdCliente\",			\n\
	dscproducto as \"DscProducto\",			\n\
	unidad as \"IdUnidad\",				\n\
	idfamilia as \"IdFamilia\",			\n\
	nmbtipoprecio as \"NmbPrecio\",			\n\
	precio as \"Precio\"				\n\
from productoexpendionosincronizado as a inner join	\n\
     productos as b using(cveproducto) inner join 	\n\
     precios as c using(cveproducto) inner join		\n\
     tipoprecio as d using(nmbtipoprecio)");
SiscomConsultaBaseAsignaArgumento("SqlProductosASincronizar",
				  lchrArrSql,
				  pSAgsSiscom);
}

void SqlExpendiosASincronizar(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];

sprintf(lchrArrSql,
	"						\n\
select distinct b.*					\n\
from productoexpendionosincronizado as a inner join	\n\
     empresas as b using(idempresa)");

SiscomConsultaBaseAsignaArgumento("SqlExpendiosASincronizar",
				  lchrArrSql,
				  pSAgsSiscom);

}
