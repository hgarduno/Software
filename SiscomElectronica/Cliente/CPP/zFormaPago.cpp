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
   new zSiscomCampo("Transferencia")	<<
   new zSiscomCampo("Efectivo")		<<
   new zSiscomCampo("Total")		<<
   new zSiscomCampo("PorPagar")		<<
   new zSiscomCampo("Combinada")	<<
   new zSiscomCampo("PagoCompleto");
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

void zFormaPago::Efectivo(const char *pchrPtrEfectivo)
{
   ActualizaCampo("Efectivo",(const unsigned char *)pchrPtrEfectivo);
}
void zFormaPago::PorPagar(const char *pchrPtrPorPagar)
{
   ActualizaCampo("PorPagar",(const unsigned char *)pchrPtrPorPagar);
}

void zFormaPago::Total(const char *pchrPtrTotal)
{
   ActualizaCampo("Total",(const unsigned char *)pchrPtrTotal);
}

void zFormaPago::PagoCompleto(const char *pchrPtrPagoCompleto)
{
   ActualizaCampo("PagoCompleto",(const unsigned char *)pchrPtrPagoCompleto);
}

void zFormaPago::Combinada(const char *pchrPtrCombinada)
{
   ActualizaCampo("Combinada",(const unsigned char *)pchrPtrCombinada);
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


const char *zFormaPago::Efectivo()
{
    return (const  char *)Campo("Efectivo");
}
const char *zFormaPago::PorPagar()
{
    return (const  char *)Campo("PorPagar");
}

const char *zFormaPago::Total()
{
    return (const  char *)Campo("Total");
}

const char *zFormaPago::PagoCompleto()
{
    return (const  char *)Campo("PagoCompleto");
}

const char *zFormaPago::Combinada()
{
    return (const  char *)Campo("Combinada");
}

int zFormaPago::PagoCompletoInt()
{
   return CampoInt("PagoCompleto");
}
