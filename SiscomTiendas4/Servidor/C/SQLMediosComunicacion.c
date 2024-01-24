#include <SQLMediosComunicacion.h>
#include <string.h>
#include <stdlib.h>

void SQLMediosComunicacion(SArgsSiscom *pSAgsSiscom)
{

EjecutaConsultaYResponde(pSAgsSiscom,
	"SELECT * from catmediocomunicacion;");
}
