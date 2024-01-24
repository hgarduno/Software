#include <SqlOrdenesFavoritas.h>
#include <SiscomInsercionesSql.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>

int SqlEliminaOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlOrdenFavorita",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteFromOrdenesFavoritas);
SiscomEnviaRegistrosAlServidorBD("SqlOrdenFavorita",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

int SqlOrdenesFavoritasRegistradas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"select *		\n\
	 from OrdenesFavoritas");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDato,
			     "OrdenesFavoritas%",
			     lchrArrSql);
return 0;
}
int SqlRegistraOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlOrdenFavorita",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToOrdenesFavoritas);
SiscomEnviaRegistrosAlServidorBD("SqlOrdenFavorita",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}



void InsertToOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato,
			      SiscomRegistroProL *pSiscomRegProLPtrDato,
			      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into OrdenesFavoritas values(%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdOrden",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Texto",pSiscomRegProLPtrDato));
}

void DeleteFromOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato,
			      SiscomRegistroProL *pSiscomRegProLPtrDato,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from ordenesfavoritas where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("IdOrden",pSiscomRegProLPtrDato));
}
