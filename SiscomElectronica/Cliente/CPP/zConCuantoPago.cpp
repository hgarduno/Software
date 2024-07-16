#include <zConCuantoPago.h>
#include <zSiscomCampo.h>
zConCuantoPago::zConCuantoPago(const char *pchrPtrConCuantoPago,
			      const char *pchrPtrImporte)
{
(*this) 		<<
new zSiscomCampo("ConCuantoPago",(const unsigned char *)pchrPtrConCuantoPago)	<<
new zSiscomCampo("Importe",(const unsigned char *)pchrPtrImporte)		<<
new zSiscomCampo("Cambio")							<<
new zSiscomCampo("SiAlcanza");
}
void zConCuantoPago::SiAlcanza(const char *pchrPtrSiAlcanza)
{
ActualizaCampo("SiAlcanza",(const unsigned char *)pchrPtrSiAlcanza);
}
int zConCuantoPago::SiAlcanzaInt()
{
  return CampoInt("SiAlcanza");
}
