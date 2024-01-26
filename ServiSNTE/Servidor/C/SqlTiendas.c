#include <SqlTiendas.h>
#include <stdio.h>
void SqlConsultaTienda(char *pchrPtrSql)
{
sprintf(pchrPtrSql,
 	"select * 			\n\
	 from tienda inner join 	\n\
	      tiendas using(idtienda);");
}
