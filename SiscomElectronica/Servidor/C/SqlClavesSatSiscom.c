#include <SqlClavesSatSiscom.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
int SqlClaveSat(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"				\n\
	 select * 			\n\
	 from clavesatsiscom		\n\
	 where clave='%s';",
	SiscomCampoAsociadoEntradaOperacion("Envio","Clave",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "ClaveSat%",
		   lchrArrSql);
}
int SqlRegistraClaveSatSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlClaveSat",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     InsertToClaveSatSiscom);
SiscomEnviaRegistrosAlServidorBD("SqlClaveSat",
                               lchrArrBuffer,
                               pSiscomOpePtrDato);
}

void InsertToClaveSatSiscom(SiscomOperaciones *pSiscomOpePtrDato,
                      SiscomRegistroProL *pSiscomRegProLPtrDato,
                      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
        "insert into ClaveSatSiscom values(%s,'%s','%s','%s');",
        SiscomObtenCampoRegistroProLChar("Id",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("Sat",pSiscomRegProLPtrDato),
        SiscomObtenCampoRegistroProLChar("PalabraClave",pSiscomRegProLPtrDato));
}
