#include <ComunClinicas3.h>
#include <ServidorGeneral.h>
#include <string.h>
#include <stdlib.h>

void ObtenDatosComunicacionAD(SArgsSiscom *pSAgsSiscom)
{
	pSAgsSiscom->intPtoComAD=gSSiscomConfiguracionSvr.intPtoAccesoDatos;
	strcpy(pSAgsSiscom->chrArrDirIpAD,
	       gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos);
}
