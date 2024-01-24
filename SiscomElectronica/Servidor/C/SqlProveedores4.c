#include <SqlProveedores4.h>
#include <stdio.h>


int SqlProveedores4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"select substring(razonsocial for 30) as razonsocial,	\n\
		idempresa,					\n\
		rfc						\n\
	 from empresas 						\n\
	 where idempresa > 0");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Proveedores%",
		   lchrArrSql);

return 0;
}
