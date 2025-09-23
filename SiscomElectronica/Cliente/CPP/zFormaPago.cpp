#include <zFormaPago.h>
#include <zSiscomCampo.h>
#include <zFormaPagoTarjeta.h>
#include <zFormaPagoTransferencia.h>
zFormaPago::zFormaPago()
{
  (*this) 				<< 
   new zSiscomCampo("Telefono") 	<<
   new zSiscomCampo("Observaciones")	<<
   new zSiscomCampo("Tarjeta")		<<
   new zSiscomCampo("Transferencia");
}

void zFormaPago::Telefono(const char *pchrPtrTelefono)
{
ActualizaCampo("Telefono",(const unsigned char *)pchrPtrTelefono);
}

zFormaPagoTransferencia *zFormaPago::Transferencia()
{
  return (zFormaPagoTransferencia *)AsociadoDelCampo("Transferencia");
}
zFormaPagoTarjeta *zFormaPago::Tarjeta()
{
  return (zFormaPagoTarjeta *)AsociadoDelCampo("Tarjeta");
} 
void zFormaPago::Observaciones(const char *pchrPtrObservaciones)
{

   ActualizaCampo("Observaciones",(const unsigned char *)pchrPtrObservaciones);

}
void zFormaPago::Transferencia(zFormaPagoTransferencia *pzPagoT)
{
   ActualizaCampo("Transferencia",pzPagoT);
}
void zFormaPago::Tarjeta(zFormaPagoTarjeta *pzPagoTarjeta)
{
  ActualizaCampo("Tarjeta",pzPagoTarjeta);
}
const char *zFormaPago::Telefono()
{
   return (const char *)Campo("Telefono");
}

const char *zFormaPago::Observaciones()
{
    return (const  char *)Campo("Observaciones");
}

