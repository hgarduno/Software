#include <SqlActualizaExpendio.h>

void SqlProductosRegistradosMatriz(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"					\n\
select a.cveproducto as \"CveProducto\",	\n\
	a.dscproducto as \"DscProducto\",	\n\
	unidad	as \"Unidad\",			\n\
	idfamilia as \"IdFamilia\"		\n\
from productos as a				\n\
order by a.cveproducto");
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("SqlProductosMatriz",lchrArrSql,pSAgsSiscom); 
}


void SqlProductosRegistradosExpendio(SArgsSiscom *pSAgsSiscom)
{
SqlAExpendioAsignaArgumento(SiscomCampoDatosEntrada("IdExpendio",pSAgsSiscom),
			    "SqlProductosExpendio",
			    "select cveproducto as \"CveProducto\" \n\
			     from productos order by cveproducto",
			    pSAgsSiscom);
}
