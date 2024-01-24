#include <SqlMotivosSalidas.h>
void SqlMotivosSalidas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];

sprintf(lchrArrSql,
	"select * from MotivosSalidaMaterial");
SiscomConsultaBaseAsignaArgumento(
                "SqlMotivosSalidas",
		lchrArrSql,       
		pSAgsSiscom);

}
