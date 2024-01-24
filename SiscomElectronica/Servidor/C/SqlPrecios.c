#include <SqlPrecios.h>
#include <SqlReportesSiscom.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomOperaciones.h>
#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <SiscomMacrosOperaciones.h>


int SqlPreciosExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{
SqlPreciosExpendioOrigen(pSiscomOpePtrDato); 
SqlPreciosExpendioDestino(pSiscomOpePtrDato);  
}
void SqlConsultaPreciosExpendio(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 				\n\
	 from precios 				\n\
	 where nmbtipoprecio = 'DEFAULT' and 	\n\
	 idpersona=1153257207  			\n\
	 order by cveproducto;");
}

int SqlPreciosExpendioOrigen(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrPrecios;
const char *lchrPtrIdExpendio;
char lchrArrSqlPreciosE[256];
lchrPtrIdExpendio=SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendioO",pSiscomOpePtrDato);
SqlConsultaPreciosExpendio(pSiscomOpePtrDato,lchrArrSqlPreciosE);
if(!SqlConsultaPreciosPorExpendio(lchrPtrIdExpendio,"PreciosOrigen",lchrArrSqlPreciosE,pSiscomOpePtrDato))
{
}

}

int SqlPreciosExpendioDestino(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrIdExpendio;
char lchrArrSqlPreciosE[256];
lchrPtrIdExpendio=SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendioD",pSiscomOpePtrDato);
LogSiscom("El Id del Expendio %s",lchrPtrIdExpendio);
SqlConsultaPreciosExpendio(pSiscomOpePtrDato,lchrArrSqlPreciosE);
if(SqlConsultaPreciosPorExpendio(lchrPtrIdExpendio,
				 "PreciosDestino",
				 lchrArrSqlPreciosE,
				 pSiscomOpePtrDato))
{


}

}

int SqlConsultaPreciosPorExpendio(const char *pchrPtrIdExpendio,
				  const char *pchrPtrSalida,
				  const char *pchrPtrSql,
				  SiscomOperaciones *pSiscomOpePtrDato)
{ 
char lchrArrBuffer[256];
char lchrArrSalida[128];
SiscomRegistroProL *lSiscomRegProLPtrPrecios;
sprintf(lchrArrSalida,"%s%%",pchrPtrSalida);
 if(!SiscomConsultasSqlServidorPorIdMaquina3(pchrPtrIdExpendio,
 					    "Expendios",
					    pSiscomOpePtrDato,
					    ExpendioParaConsultar, 
					    lchrArrBuffer,
					    lchrArrSalida,
					    pchrPtrSql))
 {
   
    lSiscomRegProLPtrPrecios=SiscomObtenRegistrosCampoRespuesta(pchrPtrSalida,pSiscomOpePtrDato);
     SiscomAsignaRegistrosArgumentoOperaciones(lSiscomRegProLPtrPrecios,
     					       lSiscomRegProLPtrPrecios,
					       pchrPtrSalida,
					       pSiscomOpePtrDato);
 }


}
void SqlActualizaciondoPrecio(SiscomOperaciones *pSisOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"update precios set precio=%s where cveproducto='%s' and idpersona=%s and nmbtipoprecio='%s'",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Precios","Precio",pSisOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","Clave",pSisOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Precios","IdPersona",pSisOpePtrDato),
"DEFAULT");
}
void PreparandoParaRegistroExpendio(SiscomRegistroProL *pSisRegProLPtrExpendio,
				    char *pchrPtrSql,
				    SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrSqlPrim;

if((lSisRegProLPtrSqlPrim=SiscomObtenArgumentoActOperaciones("SqlPrecioExpendios",pSisOpePtrDato)))
{
 SiscomActualizaCampoRegistroActual(
 		"BaseDatos",
   		(char *)SiscomObtenCampoRegistroProLChar("basedatos",pSisRegProLPtrExpendio),
		 lSisRegProLPtrSqlPrim);
 SiscomAnexaRegistrosAlCampo("SentenciasSql",
 			        lSisRegProLPtrSqlPrim,
				lchrArrBuffer,
				"Sql,"
				"Estado,",
				pchrPtrSql,
				"");
}
}
int SqlActualizaPrecioAlgunosExpendios(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrExpendios;
char lchrArrBuffer[128],lchrArrSql[256];


if((lSisRegProLPtrExpendios=SiscomObtenArgumentoActOperaciones("Expendios",pSisOpePtrDato)))
{
SqlActualizaciondoPrecio(pSisOpePtrDato,lchrArrSql);
LogSiscom("%s",lchrArrSql);
for(;
    lSisRegProLPtrExpendios;
    lSisRegProLPtrExpendios=lSisRegProLPtrExpendios->SiscomRegProLPtrSig)
{
  PreparandoParaRegistroExpendio(lSisRegProLPtrExpendios,lchrArrSql,pSisOpePtrDato);
  SiscomEnviaRegistrosBD(SiscomObtenCampoRegistroProLChar("dirip",lSisRegProLPtrExpendios),
  			 SiscomObtenCampoRegistroProLInt("puerto",lSisRegProLPtrExpendios),
			 "SqlPrecioExpendios",
			 lchrArrBuffer,
			 pSisOpePtrDato);
}
}
}
