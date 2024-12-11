#include <SqlAbonoAApartado.h>
#include <SiscomInsercionesSql.h>

#include <SiscomMacrosOperaciones.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int SqlAbonoAApartado(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlAbonoAApartado",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSisOpePtrDato,
				     InsertToAbonoAApartado);

return 0;
}


int SqlRegistraAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadosArgumentoLog("SqlAbonoAApartado",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
SiscomEnviaRegistrosAlServidorBD("SqlAbonoAApartado",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

void InsertToAbonoAApartado(SiscomOperaciones *pSisOpePtrDato,
			    SiscomRegistroProL *pSisRegProLPtrDato,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into AbonoApartado values(%s,'%s',%s);",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Fecha",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Importe",pSisRegProLPtrDato));
}
