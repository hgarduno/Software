#include <Personas.h>
#include <stdlib.h>
#include <string.h>

void NormalizaPersonas(SArgsSiscom *pSAgsSiscom)
{

LCamposSiscomPro2 *lLCSiscomPro2PersonaPrim,
		  *lLCSiscomPro2PersonaAct,
		  *lLCSiscomPro2Normalizado;
int lintNRegistros;
unsigned char *lchrPtrCambia=SiscomCaracteresCambiados();
SiscomObtenInformacionArgumento("Personas",
				pSAgsSiscom,
				&lLCSiscomPro2PersonaPrim,
				&lLCSiscomPro2PersonaAct,
				&lintNRegistros);
SiscomNormalizaNombre(lchrPtrCambia,
		       lLCSiscomPro2PersonaPrim,
		       &lLCSiscomPro2Normalizado);
SiscomAsignaInformacionArgumento("PersonaNormalizada",
                              pSAgsSiscom,
                              lLCSiscomPro2Normalizado,
                              0,
                              0);
}
