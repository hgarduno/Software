#include <SqlCargoPublico.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include  <stdio.h>
int SqlInsertaCargoPublico(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlCargoPublico",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlDelAsociado("SqlCargoPublico",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToCargoPublico);

SiscomAgregaSentenciasSqlDelAsociado("SqlCargoPublico",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToCargoPublicoPersona);
SiscomReplicaMaquinaLocal("SqlCargoPublico", lchrArrBuffer, 0, pSiscomOpePtrDat);
return 0;
}
void InsertToCargoPublico(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CargosPublicos values(%s,'%s','%s','%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdCargoPublico",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Dependencia",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Puesto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Funciones",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Periodo",pSiscomRegProLPtrEnt));
}

void InsertToCargoPublicoPersona(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CargoPublicoPersona values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdCargoPublico",pSiscomRegProLPtrEnt));
}
