#include <SqlComprasSiscom.h>
#include <stdio.h>

#include <SiscomDesarrolloMacros.h>

int SqlComprasSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
        lchrArrSqlCompras[256],
	lchrArrSqlDetalleC[256];

SqlConsultaComprasPeriodo(pSiscomOpePtrDato,lchrArrSqlCompras);
SqlConsultaDetalleComprasPeriodo(pSiscomOpePtrDato,lchrArrSqlDetalleC);

SiscomConsultasSqlOperaciones(lchrArrBuffer,
                   pSiscomOpePtrDato,
                   "Compras%DetalleCompras%",
                   lchrArrSqlCompras,
		   lchrArrSqlDetalleC);
return 0;
}

void SqlConsultaComprasPeriodo(SiscomOperaciones *pSisOpePtrDato,
			       char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"select * 		\n\
	  from registrocompra	\n\
	  where fecha::date>='%s' and  \n\
	        fecha::date<='%s'",
        SiscomCampoAsociadoEntradaOperacion("Envio",
					    "FechaIni",
					    pSisOpePtrDato),
        SiscomCampoAsociadoEntradaOperacion("Envio",
					    "FechaFin",
					    pSisOpePtrDato));
}


void SqlConsultaDetalleComprasPeriodo(SiscomOperaciones *pSisOpePtrDato,
			       char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 			\n\
	  from compras			\n\
	  where fecha::date>='%s' and 	\n\
	        fecha::date<='%s' 	\n\
	   order by idcompra",
        SiscomCampoAsociadoEntradaOperacion("Envio",
					    "FechaIni",
					    pSisOpePtrDato),
        SiscomCampoAsociadoEntradaOperacion("Envio",
					    "FechaFin",
					    pSisOpePtrDato));
}
