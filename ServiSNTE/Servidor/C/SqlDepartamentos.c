#include <SqlDepartamentos.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlRegistraDepartamento(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaDepartamento",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaDepartamento",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDepartamentos);
SiscomReplicaMaquinaLocal("SqlInsertaDepartamento", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

void InsertToDepartamentos(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Departamentos values(%s,'%s','%s');",
	 SiscomObtenCampoRegistroProLChar("IdDepartamento",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("AbrevDepto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("NombreDepto",pSiscomRegProLPtrEnt));
}

