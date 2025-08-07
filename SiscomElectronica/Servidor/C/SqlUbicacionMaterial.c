#include <SqlUbicacionMaterial.h>
#include <UbicacionMaterial.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>

#include <stdio.h>

int SqlEstantes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
        lchrArrSql[256];
sprintf(lchrArrSql,
	"select -1 as idestante,			\n\
	        'Sin Estante' as estante,		\n\
		''					\n\
	  union						\n\
	  select *					\n\
	  from estante					\n\
	  order by idestante asc");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
                   pSiscomOpePtrDato,
                   "Estantes%",
                   lchrArrSql);
return 0;
}
int SqlCajasMaterial(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
        lchrArrSql[256];
sprintf(lchrArrSql,
	"select -1 as idcaja,			\n\
	        'Sin Caja' as caja,		\n\
		''				\n\
	union					\n\
	 select * 				\n\
	  from cajamaterial			\n\
	  order by idcaja asc");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
                   pSiscomOpePtrDato,
                   "CajaMaterial%",
                   lchrArrSql);
return 0;
}


int SqlRegistraCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlCajaMaterial",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToCajaMaterial);
 SiscomEnviaRegistrosAlServidorBD("SqlCajaMaterial",
 				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
int SqlAsignaCajaProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlCajaMaterial",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     DeleteFromUbicacionProductoOp);
SiscomAgregaSentenciasSqlDelAsociado("SqlCajaMaterial",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToUbicacionProductoOp);

SiscomAgregaSentenciasSqlDelAsociado("SqlCajaMaterial",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateUbicacionProducto);
 SiscomEnviaRegistrosAlServidorBD("SqlCajaMaterial",
 				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}


void InsertToCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CajaMaterial values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdCaja",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Caja",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrDato));
}

void DeleteFromUbicacionProductoOp(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from UbicacionProducto where cveproducto='%s';",
	SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato));
}
void InsertToUbicacionProductoOp(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
if(EstaEstanteYCajaPorId(pSiscomRegProLPtrDato))
sprintf(pchrPtrSql,
	"insert into UbicacionProducto values('%s',%s,%s);",
	SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("idestante",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("idcaja",pSiscomRegProLPtrDato));
else
if(EstaCajaPorId(pSiscomRegProLPtrDato))
sprintf(pchrPtrSql,
	"insert into UbicacionProducto(cveproducto,idcaja) values('%s',%s)",
	SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("idcaja",pSiscomRegProLPtrDato));
else
if(EstaEstantePorId(pSiscomRegProLPtrDato))
sprintf(pchrPtrSql,
	"insert into UbicacionProducto(cveproducto,idestante) values('%s',%s)",
	SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("idestante",pSiscomRegProLPtrDato));
else
LogSiscom("NO se cumplio nada\n"
          "EstaEstanteYCajaPorId(%d)\n"
	  "CajaPorId(%d)\n"
	  "EstantePorId(%d)",
	  EstaEstanteYCajaPorId(pSiscomRegProLPtrDato),
	  EstaCajaPorId(pSiscomRegProLPtrDato),
	  EstaEstantePorId(pSiscomRegProLPtrDato));

}
void UpdateUbicacionProducto(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update ProductoCaja set IdCaja=%s where cveproducto='%s'",
	SiscomObtenCampoRegistroProLChar("idcaja",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato));
}

void InsertToUbicacionProducto(SiscomRegistroProL *pSisRegProLPtrProducto,
			       char *pchrPtrSql)
{
char lchrArrBuffer[128];
if(EstaCajaYEstante(pSisRegProLPtrProducto))
sprintf(pchrPtrSql,
	"insert into UbicacionProducto values('%s',%s,%s);",
	SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("IdEstante",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("IdCaja",pSisRegProLPtrProducto));
else
if(EstaCaja(pSisRegProLPtrProducto))
sprintf(pchrPtrSql,
	"insert into UbicacionProducto(CveProducto,IdCaja) values('%s',%s);",
	SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("IdCaja",pSisRegProLPtrProducto));
else
if(EstaEstante(pSisRegProLPtrProducto))
sprintf(pchrPtrSql,
	"insert into UbicacionProducto(CveProducto,IdEstante) values('%s',%s);",
	SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("IdEstante",pSisRegProLPtrProducto));
}
void InsertToCaja(SiscomRegistroProL *pSisRegProLPtrProducto,
		  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CajaMaterial values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdCaja",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("Caja",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("Caja",pSisRegProLPtrProducto));

}

void InsertToEstante(SiscomRegistroProL *pSisRegProLPtrProducto,
		  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Estante values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdEstante",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("Estante",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("Estante",pSisRegProLPtrProducto));
}
