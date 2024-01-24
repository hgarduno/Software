#include <SqlBodegas.h>
#include <SiscomInsercionesSql.h>
#include <Bodegas4.h>
#include <stdio.h>
#include <stdlib.h>
int SqlBodegasExpendios(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"							\n\
select *							\n\
from bodegas as a inner join					\n\
     bodegaexpendio as b using(idbodega) inner join		\n\
     expendios as c using(idempresa) inner join 		\n\
     servidoressiscom4 as d using(idempresa) inner join		\n\
     empresas as e using(idempresa)");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSisOpePtrDatos,
		   "BodegasExpendios%",
		   lchrArrSql);

return 0;
}

int SqlExistenciaBodega4(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrSql[256],
     lchrArrBuffer[256];

sprintf(lchrArrSql,
	"select *			\n\
	 from materialbodega 		\n\
	 where idbodega=%s and 		\n\
	       cveproducto='%s'",
DatoBodega("IdBodega",pSisOpePtrDatos),
SiscomCampoAsociadoEntradaOperacion("Envio","CveProducto",pSisOpePtrDatos));
SiscomEnviaConsultaSqlAsignaArgumento(
	DatoBodegaExpendio("DirIp",pSisOpePtrDatos),
	DatoBodegaExpendio("Base",pSisOpePtrDatos),
	(char *)0,
	lchrArrSql,
	"ExistenciaBodega",
	lchrArrBuffer,
	PuertoExpendioBodega(pSisOpePtrDatos),
	pSisOpePtrDatos);
return 0;
}
int SqlActualizaExistenciaBodega4(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
int lintPuerto;
SiscomAgregaSentenciasSqlDelAsociado("SqlExistenciaBodega",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSisOpePtrDatos,
				     UpdateExistenciaBodega4);
lintPuerto=atoi(DatoBodegaExpendio("Puerto",pSisOpePtrDatos));
SiscomEnviaRegistrosBD(DatoBodegaExpendio("DirIp",pSisOpePtrDatos),
		       lintPuerto,
		       "SqlExistenciaBodega",
		       lchrArrBuffer,
		       pSisOpePtrDatos);
		       
return 0;
}

int SqlActualizaBodegaOrigenDestino(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
int lintPuerto;
SiscomAgregaSentenciasSqlDelAsociado("SqlBodegaO",
				      "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSisOpePtrDato,
				     UpdateExistenciaBodegaOrigen);

SiscomEnviaRegistrosBD(ObtenDirIpExpendioBodegaO(pSisOpePtrDato),
		       ObtenPuertoExpendioBodegaO(pSisOpePtrDato),
		       "SqlBodegaO",
		       lchrArrBuffer,
		       pSisOpePtrDato);

SiscomAgregaSentenciasSqlDelAsociado("SqlBodegaD",
				      "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSisOpePtrDato,
				     UpdateExistenciaBodegaDestino);

SiscomEnviaRegistrosBD(ObtenDirIpExpendioBodegaD(pSisOpePtrDato),
		       ObtenPuertoExpendioBodegaD(pSisOpePtrDato),
		       "SqlBodegaD",
		       lchrArrBuffer,
		       pSisOpePtrDato);


return 0;
}

void UpdateExistenciaBodega4(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql)
{

sprintf(pchrPtrSql,
 "update materialbodega set existencia=%s where idbodega=%s and cveproducto='%s';",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSisRegProLPtrDato),
	DatoBodega("IdBodega",pSisOpePtrDato),
	SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrDato));
}


void UpdateExistenciaBodegaOrigen(SiscomOperaciones *pSisOpePtrDato,
			          SiscomRegistroProL *pSisRegProLPtrDato,
			          char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update materialbodega set existencia=existencia-%s where idbodega=%s and cveproducto='%s';",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSisRegProLPtrDato),
	ObtenIdBodegaO(pSisOpePtrDato),
	SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrDato));
		
}

void UpdateExistenciaBodegaDestino(SiscomOperaciones *pSisOpePtrDato,
			          SiscomRegistroProL *pSisRegProLPtrDato,
			          char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update materialbodega set existencia=existencia+%s where idbodega=%s and cveproducto='%s';",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSisRegProLPtrDato),
	ObtenIdBodegaD(pSisOpePtrDato),
	SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrDato));
}
