#include <SqlSeguridad3.h>
#include <stdio.h>
int SqlPerfilesAplicacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrSql[128];


sprintf(lchrArrSql,
	"select * 	\n\
	 from perfiles");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
				pSiscomOpePtrDato,
				"Perfiles%",
				lchrArrSql);
				
return 0;
}
