#include <SqlEscuelasSE.h>
#include <stdio.h>
int SqlEscuelasSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"		\n\
	select * 	\n\
	from escuelas 	\n\
	order by nombre ");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Escuelas%",
		   lchrArrSql);
}

int SqlEntregaEscuela(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
      lchrArrSql[512];

 sprintf(lchrArrSql,
 	"select * 					\n\
	 from escuelas 					\n\
	 where idescuela in(select 			\n\
	 		    idescuela			\n\
			    from EntregaEscuela)	\n\
	 order by nombre" );

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Escuelas%",
		   lchrArrSql);
return 0;
}


void SqlFormaEscuelaPorNombre(SiscomOperaciones *pSiscomOpePtrDato,
			      char *pchrPtrSqlEscPorNombre)
{
sprintf(pchrPtrSqlEscPorNombre,
	"select * 						\n\
	 from escuelas as a inner join 				\n\
	      escuelaprincipalexpendio as b using(idescuela) 	\n\
	 where idexpendio=%s",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato));
}
void SqlFormaEscuelaOtro(SiscomOperaciones *pSiscomOpePtrDato,
		  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 			\n\
	 from escuelas			\n\
	 where nombre='OTRO'		\n\
	 limit 1 ");
}
