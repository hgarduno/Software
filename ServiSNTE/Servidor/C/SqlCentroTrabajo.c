#include <SqlCentroTrabajo.h>
#include <stdio.h>
#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
int SqlInsertaCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlCentroTrabajo",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);


SiscomAgregaSentenciasSqlDelAsociado("SqlCentroTrabajo",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
					InsertToCentroTrabajo);
SiscomReplicaMaquinaLocal("SqlCentroTrabajo", lchrArrBuffer, 0, pSiscomOpePtrDat); 
return 0;

}
void InsertToCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into centrotrabajo values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdPersona",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("CentroTrabajo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("ClavePresupuestal",pSiscomRegProLPtrEnt));
}

