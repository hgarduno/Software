#include <SqlGeneralesContratoBeneficios.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include  <stdio.h>
int SqlInsertaGeneralesContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlGeneralesContratoBeneficios",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlDelAsociado("SqlGeneralesContratoBeneficios",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToGeneralesContratoBeneficios);

SiscomReplicaMaquinaLocal("SqlGeneralesContratoBeneficios", lchrArrBuffer, 0, pSiscomOpePtrDat);
return 0;
}
void InsertToGeneralesContratoBeneficios(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into GeneralesContratoBeneficios values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Lugar",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}

