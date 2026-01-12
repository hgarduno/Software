#include <SqlCotizando4.h>
#include <Cotizando4.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SqlProductosCotizando(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomRegistrosAsociadosCampoEntrada("Envio",
								"Productos",
								pSiscomOpePtrDato);
SqlProductosCotizacion(pSiscomOpePtrDato,
		       "Productos%",
		       lSiscomRegProLPtrProductos);
return 0;
}

int SqlProductosCotizacion(SiscomOperaciones *pSiscomOpePtrDato,
			   const char *pchrPtrAsociadoReg,
			   SiscomRegistroProL *pSiscomRegProLPtrProductos)
{
char *lchrPtrBuffer=0,
	*lchrPtrSql=0,
	*lchrPtrSqlCondicion=0;
int lintTamano;
ArmaCondicionConsultaProductos(pSiscomOpePtrDato,
			       pSiscomRegProLPtrProductos,
			       &lchrPtrSqlCondicion);
lintTamano=strlen(lchrPtrSqlCondicion)+256;
lchrPtrSql=(char *)malloc(lintTamano);
lchrPtrBuffer=(char *)malloc(lintTamano);
sprintf(lchrPtrSql,
	"select * 									\n\
	 from precios as a  inner join 							\n\
	      existenciaexpendiobodegas as b using(cveproducto) left outer join		\n\
	      productoportipoproducto as c using(cveproducto) 				\n\
	 %s",
	 lchrPtrSqlCondicion);

LogSiscom("La consulta para cotizar productos %s",lchrPtrSql);
SiscomConsultasSqlOperaciones(lchrPtrBuffer,
		   pSiscomOpePtrDato,
		   pchrPtrAsociadoReg,
		   lchrPtrSql);
}
