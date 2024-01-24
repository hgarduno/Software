#include <PagoCambio.h>
#include <stdlib.h>

SiscomOperaciones2 *OpCalculaCambio()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);

SiscomAnexaOperacionAlArreglo2(CalculaCambioPago,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EnviaCambio,lSOpOperaciones2);

return lSOpOperaciones2;
}
void EnviaCambio(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
SiscomEnviaRegreso(pSAgsSiscom);
}
void CalculaCambioPago(SArgsSiscom *pSAgsSiscom)
{
char lchrArrCambio[12];
char lchrArrImporteValido[2];
LCamposSiscomPro2 *lLCSiscomPro2CambioPrim=0,
		  *lLCSiscomPro2CambioAct=0;
int lintNRegistros=0;
float lfltRecibo=atof(pSAgsSiscom->chrPtrArgConsulta[2]);
float lfltImporte=atof(pSAgsSiscom->chrPtrArgConsulta[1]);
sprintf(lchrArrCambio,
	"%.2f",
	lfltRecibo-lfltImporte);
sprintf(lchrArrImporteValido,
	"%d",
	lfltRecibo>=lfltImporte);
SiscomAnexaRegistroPro2(&lLCSiscomPro2CambioPrim,
			&lLCSiscomPro2CambioAct,
			&lintNRegistros,
			"Cambio,ImporteValido",
			lchrArrCambio,
			lchrArrImporteValido);
pSAgsSiscom->LCSiscomPro2Regreso=lLCSiscomPro2CambioPrim;
pSAgsSiscom->intNumRegRegreso=lintNRegistros;
}
