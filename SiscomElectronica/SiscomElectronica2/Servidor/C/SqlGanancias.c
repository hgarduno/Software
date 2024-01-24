#include <SqlGanancias.h>

void SqlProductosVendidos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"						\n\
select fechahora::date,					\n\
	cveproducto,					\n\
	cantidad,					\n\
	precio,						\n\
	ultimoprecio(cveproducto,fechahora::date)	\n\
from ventas 						\n\
where fechahora::date>='%s' and				\n\
      fechahora::date<='%s' and				\n\
      idexpendio=%s					\n\
order by fechahora,					\n\
	 cveproducto",
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseAsignaArgumento(
                "SqlProductosVenta",
		lchrArrSql,
		pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}
