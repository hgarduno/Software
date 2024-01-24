#include <zFormaPagoTarjeta.h>
#include <zSiscomCampo.h>
zFormaPagoTarjeta::zFormaPagoTarjeta()
{
  (*this) <<   
  new zSiscomCampo("Observaciones");
}
