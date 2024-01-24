#include <SqlSistemaPedidos.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>
int SqlOrdenesPendientes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"							\n\
	select * from cajacentral");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "OrdenesPendientes%",
		   lchrArrSql);
}
