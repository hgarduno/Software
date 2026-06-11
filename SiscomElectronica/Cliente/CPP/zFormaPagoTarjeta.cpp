#include <zFormaPagoTarjeta.h>
#include <zSiscomCampo.h>
zFormaPagoTarjeta::zFormaPagoTarjeta()
{
  (*this) <<   
  new zSiscomCampo("Observaciones") <<
  new zSiscomCampo("Importe");
}
void zFormaPagoTarjeta::Importe(const char *pchrPtrImporte)
{
   ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}

const char *zFormaPagoTarjeta::Importe()
{
   return (const char *)Campo("Importe");
}
