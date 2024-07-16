#include <zCorteCaja.h>
#include <zSiscomCampo.h>
zCorteCaja::zCorteCaja()
{
(*this) 				<< 
new zSiscomCampo("IdCorte")		<<
new zSiscomCampo("Fecha")		<<
new zSiscomCampo("Transferencias")	<<
new zSiscomCampo("Tarjeta")		<<
new zSiscomCampo("DineroEntroCaja")	<<
new zSiscomCampo("Gastos")		<<
new zSiscomCampo("Cambio")		<<
new zSiscomCampo("Cajas")		<<
new zSiscomCampo("IdEstado");
}
void zCorteCaja::IdCorte(const char *pchrPtrIdCorte)
{
ActualizaCampo("IdCorte",(const unsigned char *)pchrPtrIdCorte);
}
void zCorteCaja::Fecha(const char *pchrPtrFecha)
{
ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}
void zCorteCaja::Transferencias(const char *pchrPtrTransferencias)
{
ActualizaCampo("Transferencias",(const unsigned char *)pchrPtrTransferencias);
}
void zCorteCaja::Tarjeta(const char *pchrPtrTarjeta)	
{
ActualizaCampo("Tarjeta",(const unsigned char *)pchrPtrTarjeta);
}
void zCorteCaja::DineroEntroCaja(const char *pchrPtrDineroEntroCaja)	
{
ActualizaCampo("DineroEntroCaja",(const unsigned char *)pchrPtrDineroEntroCaja);
}
void zCorteCaja::Gastos(const char *pchrPtrGastos)	
{
ActualizaCampo("Gastos",(const unsigned char *)pchrPtrGastos);
}
void zCorteCaja::IdEstado(const char *pchrPtrIdEstado)	
{
ActualizaCampo("IdEstado",(const unsigned char *)pchrPtrIdEstado);
}

void zCorteCaja::CorteCaja(zSiscomRegistro *pzSisRegRegreso)
{
   ActualizaCampo("DineroEntroCaja",
   		  pzSisRegRegreso->CampoAsociado("PagaCon","importe"));

   ActualizaCampo("Transferencias",
   		  pzSisRegRegreso->CampoAsociado("Transferencias","importe"));
}

const char *zCorteCaja::DineroEntroCaja()
{
  return (const char *)Campo("DineroEntroCaja");
}

const char *zCorteCaja::Transferencias()
{
  return (const char *)Campo("Transferencias");
}
