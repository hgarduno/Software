#include <zCorteCaja.h>
#include <zSiscomCampo.h>
zCorteCaja::zCorteCaja()
{
(*this) 				<< 
new zSiscomCampo("IdCorte")		<<
new zSiscomCampo("FechaInicio")		<<
new zSiscomCampo("FechaFin")		<<
new zSiscomCampo("Transferencias")	<<
new zSiscomCampo("Tarjeta")		<<
new zSiscomCampo("DineroEntroCaja")	<<
new zSiscomCampo("Gastos")		<<
new zSiscomCampo("CambioDiaAnterior")	<<
new zSiscomCampo("Cajas")		<<
new zSiscomCampo("IdEstado")		<<
new zSiscomCampo("VentasTotales")	<<
new zSiscomCampo("EdoCuentaCambio");
}

void zCorteCaja::Cajas(zCajas *pzCajas)
{
 AsociadosAlCampo("Cajas",(zCajas *)pzCajas);
}
void zCorteCaja::IdCorte(const char *pchrPtrIdCorte)
{
ActualizaCampo("IdCorte",(const unsigned char *)pchrPtrIdCorte);
}
void zCorteCaja::FechaInicio(const char *pchrPtrFechaInicio)
{
ActualizaCampo("FechaInicio",(const unsigned char *)pchrPtrFechaInicio);
}

void zCorteCaja::FechaFin(const char *pchrPtrFechaFin)
{
ActualizaCampo("FechaFin",(const unsigned char *)pchrPtrFechaFin);
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

void zCorteCaja::CambioDiaAnterior(const char *pchrPtrCambioDiaAnterior)	
{
ActualizaCampo("CambioDiaAnterior",(const unsigned char *)pchrPtrCambioDiaAnterior);
}

void zCorteCaja::CorteCaja(zSiscomRegistro *pzSisRegRegreso)
{
   ActualizaCampo("EdoCuentaCambio",
   		   (*pzSisRegRegreso)["EdoCuentaCambio"]);
   ActualizaCampo("DineroEntroCaja",
   		  pzSisRegRegreso->CampoAsociado("PagaConP","importe"));

   ActualizaCampo("Transferencias",
   		  pzSisRegRegreso->CampoAsociado("TransferenciasP","importe"));
   ActualizaCampo("VentasTotales",
   		  pzSisRegRegreso->CampoAsociado("VentasTotalesP","importe"));
}
void zCorteCaja::VentasTotales(const char *pchrPtrVentasT)
{
   ActualizaCampo("VentasTotales",(const unsigned char *)pchrPtrVentasT);
}
void zCorteCaja::EdoCuentaCambio(const char *pchrPtrEdoCuentaCambio)
{
   ActualizaCampo("EdoCuentaCambio",(const unsigned char *)pchrPtrEdoCuentaCambio);
  
}
const char *zCorteCaja::DineroEntroCaja()
{
  return (const char *)Campo("DineroEntroCaja");
}

const char *zCorteCaja::Transferencias()
{
  return (const char *)Campo("Transferencias");
}
const char *zCorteCaja::VentasTotales()
{
   return (const char *)Campo("VentasTotales");
}
const char *zCorteCaja::EdoCuentaCambio()
{
   return (const char *)Campo("EdoCuentaCambio");
}

const char *zCorteCaja::CambioDiaAnterior()
{
  return (const char *)Campo("CambioDiaAnterior");
}
 
zCajas *zCorteCaja::Cajas()
{
  return (zCajas *)AsociadosDelCampo("Cajas");
}
