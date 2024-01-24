#include <SqlProveedores.h>
void SqlProveedoresRegistrados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];

sprintf(lchrArrSql,
	"				\n\
select *				\n\
from empresas  left outer join		\n\
     direcciones using(idempresa)	\n\
where idempresa>0			\n\
");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
