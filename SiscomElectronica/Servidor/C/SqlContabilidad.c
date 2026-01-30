#include <SqlContabilidad.h>
#include <ExistenciaExpendios.h>
#include <stdio.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include <string.h>
#include <stdlib.h>

int SqlInsertaOrdenesCantabilidad(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrBuffer[256];
 SiscomEnviaRegistrosAlServidorBD("SqlContabilidad",
 				  lchrArrBuffer,
				  pSiscomOpePtrDatos);


return 0;
}
int SqlOrdenesTarjetaTransferencia(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrPtrBuffer[1024],
     lchrArrSqlTaTra[1024];
char lchrArrBuffer[1024];
SiscomRegistroProL *lSiscomRegProLPtrServidores;
SqlConsultaOrdenesTarjetaTransferencia(pSiscomOpePtrDatos,lchrArrSqlTaTra);
lSiscomRegProLPtrServidores=pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes;
pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes=0;
SiscomConsultasSqlSistema("Expendio",
			   "idempresa",
			   1,
			   lSiscomRegProLPtrServidores,
			   ConexionExpendioConsultaSiscom,
			   ErrorConexionExpendio,
			   EstadoConsultaSistemaSiscom,
			   lchrArrBuffer,
			   pSiscomOpePtrDatos,
			   "Ordenes%",
			   lchrArrSqlTaTra);
LogSiscom("Termino la Consulta a todos los expendio");
return 0;
}

void SqlConsultaOrdenesTarjetaTransferencia(SiscomOperaciones *pSiscomOpePtrDatos,
				   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"select idventa ,							\n\
        cveproducto,							\n\
        cantidad,							\n\
        precio,								\n\
        d.importe,							\n\
	1 as comopago 					-- transferencia\n\
from    pagotransferencia as b left outer join				\n\
	importeorden as a using(idventa) inner join			\n\
        ventas as d using(idventa) 					\n\
where fecha::date>='%s' and 						\n\
      fecha::date<='%s'							\n\
union									\n\
select idventa ,							\n\
        cveproducto,							\n\
        cantidad,							\n\
        precio,								\n\
        d.importe,							\n\
	2 as comopago					-- tarjeta	\n\
from    pagotarjeta as b left outer join				\n\
	importeorden as a using(idventa) inner join			\n\
        ventas as d using(idventa) 					\n\
where fecha::date>='%s' 	and 					\n\
      fecha::date<='%s'							\n\
order by comopago,idventa",
 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDatos),
 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDatos),
 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDatos),
 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDatos));
}
void SqlInsertIntoFacturacionPeriodica(SiscomOperaciones *pSisOpePtrDatos,
				       char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into FacturacionPeriodica values(%s,'%s','%s');",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdFacturacion",pSisOpePtrDatos),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSisOpePtrDatos),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSisOpePtrDatos));


}
void SqlInsertIntoOrdenesContabilidad(SiscomOperaciones *pSisOpePtrDatos,
				     SiscomRegistroProL *pSisRegProLPtrOrdenes,
				     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into OrdenesContabilidad values(%s,%s,%s,%s);",
 	 SiscomCampoAsociadoEntradaOperacion("Envio","IdFacturacion",pSisOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idventa",pSisRegProLPtrOrdenes),
 	 SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSisOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("comopago",pSisRegProLPtrOrdenes));
}
void SqlInsertIntoDetalleOrdenContabilidad(SiscomOperaciones *pSisOpePtrDato,
					   SiscomRegistroProL *pSisRegProLPtrDatos,
					   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleOrdenContabilidad values(%s,%s,%s,'%s',%s,%s,%s,%s);",
 	 SiscomCampoAsociadoEntradaOperacion("Envio","IdFacturacion",pSisOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("idventa",pSisRegProLPtrDatos),
 	 SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSisOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrDatos),
	 SiscomObtenCampoRegistroProLChar("cantidad",pSisRegProLPtrDatos),
	 SiscomObtenCampoRegistroProLChar("precio",pSisRegProLPtrDatos),
	 "0",
	 SiscomObtenCampoRegistroProLChar("importe",pSisRegProLPtrDatos));
}
void SqlAgregaSentenciaContabilidad(char *pchrPtrSql,
				    char *pchrPtrBuffer,
				    SiscomRegistroProL *pSisRegProLPtrSql)
{
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			    pSisRegProLPtrSql,
			    pchrPtrBuffer,
			    "Sql,"
			    "Estado,",
			    pchrPtrSql,
			    "");

}
void InsertandoFacturacionPeriodica(SiscomOperaciones *pSisOpePtrDatos,
				    SiscomRegistroProL *pSisRegProLPtrSql)
{
char lchrArrSql[256],
     lchrArrBuffer[256];
SqlInsertIntoFacturacionPeriodica(pSisOpePtrDatos,lchrArrSql);
SqlAgregaSentenciaContabilidad(lchrArrSql,lchrArrBuffer,pSisRegProLPtrSql);
}
				    
void InsertandoDetalleOrdenContabilidad(SiscomOperaciones *pSisOpePtrDatos,
					  SiscomRegistroProL *pSisRegProLPtrDatos,
					  SiscomRegistroProL *pSisRegProLPtrSql,
					  char *pchrPtrBuffer,
					  char *pchrPtrSql)
{
SqlInsertIntoDetalleOrdenContabilidad(pSisOpePtrDatos,pSisRegProLPtrDatos,pchrPtrSql);
SqlAgregaSentenciaContabilidad(pchrPtrSql,pchrPtrBuffer,pSisRegProLPtrSql);
}
SiscomRegistroProL *InsertandoOrdenesContabilidad(SiscomOperaciones *pSisOpePtrDatos,
				   SiscomRegistroProL *pSisRegProLPtrDatos,
				   SiscomRegistroProL *pSisRegProLPtrSql,
				   char *pchrPtrBuffer,
				   char *pchrPtrSql)

{
const char *lchrPtrIdVenta;
SiscomRegistroProL *lSisRegProLPtrAnterior;
SqlInsertIntoOrdenesContabilidad(pSisOpePtrDatos,pSisRegProLPtrDatos,pchrPtrSql);
SqlAgregaSentenciaContabilidad(pchrPtrSql,pchrPtrBuffer,pSisRegProLPtrSql);
lchrPtrIdVenta=SiscomObtenCampoRegistroProLChar("idventa",pSisRegProLPtrDatos);
while(pSisRegProLPtrDatos && 
      !SiscomComparaCadenaCampoRegistroProL(lchrPtrIdVenta,"idventa",pSisRegProLPtrDatos))
{
InsertandoDetalleOrdenContabilidad(pSisOpePtrDatos,
				     pSisRegProLPtrDatos,
				     pSisRegProLPtrSql,
				     pchrPtrBuffer,
				     pchrPtrSql);
lSisRegProLPtrAnterior=pSisRegProLPtrDatos;
pSisRegProLPtrDatos=pSisRegProLPtrDatos->SiscomRegProLPtrSig;
}
return lSisRegProLPtrAnterior;
}

void SqlOrdenesContabilidadExpendio(SiscomRegistroProL *pSisRegProLPtrDatos,
				   SiscomRegistroProL *pSisRegProLPtrSql,
				   SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrSql[256],lchrArrBuffer[256];
				  
while(pSisRegProLPtrDatos)
{
pSisRegProLPtrDatos=InsertandoOrdenesContabilidad(pSisOpePtrDatos,
			      pSisRegProLPtrDatos,
			      pSisRegProLPtrSql,
			      lchrArrSql,
			      lchrArrBuffer);
if(pSisRegProLPtrDatos)
pSisRegProLPtrDatos=pSisRegProLPtrDatos->SiscomRegProLPtrSig;
}


}
