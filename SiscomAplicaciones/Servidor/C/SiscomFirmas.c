#include <SiscomFirmas.h>

void SiscomVerificaPassword(SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrPassword;
const char *lchrPtrRePassword;
lchrPtrPassword=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Password");
lchrPtrRePassword=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"RePassword");
pSAgsSiscom->intCodigoRetorno=!strcmp(lchrPtrPassword,lchrPtrRePassword) ? 0 : 3;
SiscomMensajesLog2("SiscomVerificaPassword:%d",
		   pSAgsSiscom->intCodigoRetorno);
}
void SiscomPasswordVacio(SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrPassword;
lchrPtrPassword=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Password");
pSAgsSiscom->intCodigoRetorno=lchrPtrPassword[0] ? 0 : 4;
}
