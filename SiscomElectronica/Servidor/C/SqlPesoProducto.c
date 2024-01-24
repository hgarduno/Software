#include <SqlPesoProducto.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>

#include <stdio.h> 


int SqlPesoProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
/*
sprintf(lchrArrSql,
	"select *						\n\
	 from PesoProducto 					\n\
	 where cveproducto='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","CveProducto",pSiscomOpePtrDato));
*/
SqlConsultaPesoProducto(pSiscomOpePtrDato,lchrArrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "PesoProducto%",
		   lchrArrSql);
return 0;
}
void SqlConsultaPesoProducto(SiscomOperaciones *pSiscomOpePtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *						\n\
	 from PesoProducto 					\n\
	 where cveproducto='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","CveProducto",pSiscomOpePtrDato));
}
int SqlRegistraPesoProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlPesoProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToPesoProducto);



SiscomEnviaRegistrosAlServidorBD("SqlPesoProducto",
			       lchrArrBuffer,
			       pSiscomOpePtrDato);
}

void InsertToPesoProducto(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"insert into PesoProducto values('%s',%s);",
SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("Peso",pSiscomRegProLPtrDato));
LogSiscom("%s",pchrPtrSql);
}

int SqlActualizaPesoProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlPesoProducto",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateFromPesoProducto);
SiscomEnviaRegistrosAlServidorBD("SqlPesoProducto",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

void UpdateFromPesoProducto(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"update PesoProducto set peso=%s where cveproducto='%s';",
SiscomObtenCampoRegistroProLChar("Peso",pSiscomRegProLPtrDato),
SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));
}
