#include <SqlCamiones.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlRegistraCamion(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaCamion",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaCamion",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToCamiones);
SiscomReplicaMaquinaLocal("SqlInsertaCamion", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

void InsertToCamiones(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into camiones values(%s,'%s','%s','%s', %s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdCamion",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Nombre",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Marca",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Tipo",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Modelo",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Placas",pSiscomRegProLPtrEnt));
}
