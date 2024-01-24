#include <SqlProductosSE.h>
#include <Cotizando4.h>
#include <ProductosSE.h>
#include <stdio.h>
#include <SiscomDesarrolloMacros.h>

int SqlGastosSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"			\n\
	 select *		\n\
	 from gastos");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Gastos%",
		   lchrArrSql);
return 0;
}


