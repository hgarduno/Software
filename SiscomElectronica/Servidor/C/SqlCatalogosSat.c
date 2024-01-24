#include <SqlCatalogosSat.h>

#include <stdio.h>
int SqlFormasPagoSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"					\n\
	select * 				\n\
	from FormaPagoSat 			\n\
	order by IdFormaPago ");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "FormaPagoSat%",
		   lchrArrSql);
return 0;
}

int SqlMetodoPagoSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"					\n\
	select * 				\n\
	from MetodoPagoSat 			\n\
	order by IdMetodoPago ");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "MetodoPagoSat%",
		   lchrArrSql);
return 0;
}

int SqlUsoFacturaSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"								\n\
	select codigo  || ' ' || uso as UsoCodigo,			\n\
	* 								\n\
	from UsoFacturaSat 						\n\
	order by IdUsoFactura");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "UsoFacturaSat%",
		   lchrArrSql);
return 0;
}


int SqlRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"									\n\
	select  regimen ||  ' ' || descripcion as RegimenSat ,	\n\
	* 									\n\
	from regimenfiscal \n\
	order by regimen");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "RegimenFiscal%",
		   lchrArrSql);
return 0;
}

