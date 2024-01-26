#include<SqlAdministracionServiSNTE.h>
#include <stdio.h>
int SqlEstadoServidores(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
"								\n\
select *							\n\
from maquinas as a inner join 					\n\
     tiendas as b on a.idmaquina=b.idtienda inner join		\n\
     servidoractivo as c using(idmaquina)			\n\
order by idmaquina");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "EstadoServidores%",
                 lchrArrSql);
}

