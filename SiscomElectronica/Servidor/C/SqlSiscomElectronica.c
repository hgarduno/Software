

#include <SqlSiscomElectronica.h> 
#include <SiscomDesarrolloMacros.h> 
#include <SiscomMacrosOperaciones.h> 
#include <stdio.h> 

int SqlConsultandoUnosExpendios(SiscomOperaciones *pSisOpPtrDatos)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SqlDatosComunicacionUnosExpendios(pSisOpPtrDatos,lchrArrSql);
LogSiscom("%s",lchrArrSql);
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
					"Expendios",
					lchrArrBuffer,
					pSisOpPtrDatos);
return 0;

}
int SqlComunicacionExpendios(SiscomOperaciones *pSiscomOpePtrDato) 
{ 
char lchrArrBuffer[1024],lchrArrSql[1024]; 
SqlDatosComunicacionExpendios(pSiscomOpePtrDato,lchrArrSql); 
SiscomConsultasSqlOperaciones(lchrArrBuffer, 
			      pSiscomOpePtrDato,
			      "Servidores%",
			      lchrArrSql); 
SiscomAsignaRegistrosArgumentoOperaciones(
				pSiscomOpePtrDato->SiscomRegProLPtrPrimRes, 
				pSiscomOpePtrDato->SiscomRegProLPtrPrimRes, 
				"Expendios", 
				pSiscomOpePtrDato);
return 0;
}


int SqlComunicacionMatriz(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
SqlConsultaComunicacionMatriz(pSiscomOpePtrDatos,lchrArrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDatos,
			     "Matriz%",
			     lchrArrSql);
return 0;
}

int SqlComunicacionMatrizAArgumento(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
SqlConsultaComunicacionMatriz(pSiscomOpePtrDatos,lchrArrSql);
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
					"Matriz",
					lchrArrBuffer,
					pSiscomOpePtrDatos);
return 0;
}

void SqlDatosComunicacionExpendios(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select 'Expendio' as tipoequipo,				\n\
		 diripsvrad as dirip,					\n\
		 puerto,						\n\
		 a.idempresa,						\n\
		 basedatos,						\n\
		 razonsocial						\n\
	 from expendios as a inner join					\n\
	      servidoressiscom4 as b using(idempresa) inner join	\n\
	      empresas as c using(idempresa) inner join			\n\
	      expendioabierto as d using(idempresa)			\n\
	 order by razonsocial");
}

void SqlDatosComunicacionUnosExpendios(SiscomOperaciones *pSiscomOpePtrDatos,
					char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select 'Expendio' as tipoequipo,				\n\
		 diripsvrad as dirip,					\n\
		 puerto,						\n\
		 a.idempresa,						\n\
		 basedatos,						\n\
		 razonsocial						\n\
	 from expendios as a inner join					\n\
	      servidoressiscom4 as b using(idempresa) inner join	\n\
	      empresas as c using(idempresa)				\n\
	 %s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Condicion",pSiscomOpePtrDatos));
}

void SqlConsultaComunicacionMatriz(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 						\n\
	 from expendios inner join 				\n\
	      servidoressiscom4 using(idempresa) inner join 	\n\
	      matriz using(idempresa);");
}
