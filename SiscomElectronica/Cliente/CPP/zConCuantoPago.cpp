#include <zConCuantoPago.h>
#include <zSiscomCampo.h>
/* Tepotzotlan Mexico a  20 de Octubre del 2024 
 *
 * Cuando es un apartado , se puede dejar una parte a cuenta 
 * con lo que la validacion de con cuanto Paga, no se hace sobre 
 * el importe total de la orden sino, con lo que deja a cuenta
 *
 * Para manejar de esta validacion se agrega el campo IdTipoOrden 
 *
 */
zConCuantoPago::zConCuantoPago(const char *pchrPtrConCuantoPago,
			      const char *pchrPtrImporte)
{
(*this) 									<<
new zSiscomCampo("ConCuantoPago",(const unsigned char *)pchrPtrConCuantoPago)	<<
new zSiscomCampo("Importe",(const unsigned char *)pchrPtrImporte)		<<
new zSiscomCampo("Cambio")							<<
new zSiscomCampo("SiAlcanza")							<<
new zSiscomCampo("ACuenta")							<<
new zSiscomCampo("IdTipoOrden");
}
void zConCuantoPago::SiAlcanza(const char *pchrPtrSiAlcanza)
{
ActualizaCampo("SiAlcanza",(const unsigned char *)pchrPtrSiAlcanza);
}
int zConCuantoPago::SiAlcanzaInt()
{
  return CampoInt("SiAlcanza");
}

void  zConCuantoPago::IdTipoOrden(const char *pchrPtrIdTipoOrden)
{

      ActualizaCampo("IdTipoOrden",(const unsigned char *)pchrPtrIdTipoOrden);
}

void zConCuantoPago::ACuenta(const char *pchrPtrACuenta)
{
     ActualizaCampo("ACuenta",(const unsigned char *)pchrPtrACuenta);
}
