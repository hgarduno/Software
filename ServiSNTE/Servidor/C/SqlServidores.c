#include <SqlServidores.h>
#include <stdio.h>
#include <SiscomDesarrolloMacros.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
int SqlServidores(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrSql[256],
	lchrArrBuffer[512];
sprintf(lchrArrSql,
"		 						\n\
select * 							\n\
from servidoractivo as a inner join 				\n\
	maquinas as b using(idmaquina) inner join		\n\
	servidores as c using(idmaquina) left outer join 	\n\
	tiendas as d on a.idmaquina=d.idtienda 			\n\
where activo = 1;");
LogSiscom("Iniciando %s",lchrArrSql); 
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "Servidores%",
			      lchrArrSql);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Servidores",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes); 
}

