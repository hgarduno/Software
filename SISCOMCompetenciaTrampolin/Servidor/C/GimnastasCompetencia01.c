#include <GimnastasCompetencia01.h>

void AsignaArgumentosGimnastasCompetencia01(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"GimClasificadas",pSAgsSiscom);
}

void EnviaGimnastasCompetencia01(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaAlServidor(
	pSAgsSiscom->intSocketCliente,
	SiscomArgumentosNumeroRegistros("GimClasificadas",pSAgsSiscom),
	"Respuesta",
	SiscomArgumentoOperacionPrim("GimClasificadas",pSAgsSiscom));

}
