#include <ComunElFresno.h>
#include <ServidorGeneral.h>
#include <string.h>
void ObtenComunicacionElFresno(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->intPtoComAD=gSSiscomConfiguracionSvr.intPtoAccesoDatos;
strcpy(
     pSAgsSiscom->chrArrDirIpAD,
     gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos);

}
