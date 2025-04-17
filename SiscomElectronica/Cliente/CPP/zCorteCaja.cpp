#include <zCorteCaja.h>
#include <zSiscomCampo.h>
zCorteCaja::zCorteCaja()
{
(*this) 				<< 
new zSiscomCampo("IdCorte")		<<
new zSiscomCampo("FechaInicio")		<<
new zSiscomCampo("FechaFin")		<<
new zSiscomCampo("Fecha")		<<
new zSiscomCampo("Transferencias")	<<
new zSiscomCampo("Tarjeta")		<<
new zSiscomCampo("DineroEntroCaja")	<<
new zSiscomCampo("Billetes")		<<
new zSiscomCampo("CambioDiaAnterior")	<<
new zSiscomCampo("Cajas")		<<
new zSiscomCampo("IdEstado")		<<
new zSiscomCampo("VentasTotales")	<<
new zSiscomCampo("CalculandoCorte")	<<
new zSiscomCampo("TotalGastos")		<<
new zSiscomCampo("EdoCuentaCambio")	<<
new zSiscomCampo("EdoCorteCaja")	<<
new zSiscomCampo("CorteTotal");
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
void zCorteCaja::IdEstado(const char *pchrPtrIdEstado)	
{
ActualizaCampo("IdEstado",(const unsigned char *)pchrPtrIdEstado);
}

void zCorteCaja::CambioDiaAnterior(const char *pchrPtrCambioDiaAnterior)	
{
ActualizaCampo("CambioDiaAnterior",(const unsigned char *)pchrPtrCambioDiaAnterior);
}
void zCorteCaja::EdoCuentaCambio(const char *pchrPtrEdoCuentaCambio)
{
ActualizaCampo("EdoCuentaCambio",(const unsigned char *)pchrPtrEdoCuentaCambio);
}
void zCorteCaja::CorteCaja(zSiscomRegistro *pzSisRegRegreso)
{
ActualizaCampo("EdoCuentaCambio",(*pzSisRegRegreso)["EdoCuentaCambio"]);
ActualizaCampo("Transferencias",(*pzSisRegRegreso)["Transferencias"]);
ActualizaCampo("VentasTotales",(*pzSisRegRegreso)["VentasTotales"]);
ActualizaCampo("DineroEntroCaja",(*pzSisRegRegreso)["DineroEntroCaja"]);
ActualizaCampo("CalculandoCorte",(*pzSisRegRegreso)["CalculandoCorte"]);
ActualizaCampo("TotalGastos",(*pzSisRegRegreso)["TotalGastos"]);
ActualizaCampo("CorteTotal",(*pzSisRegRegreso)["CorteTotal"]);
ActualizaCampo("Billetes",(*pzSisRegRegreso)["Billetes"]);
}
void zCorteCaja::VentasTotales(const char *pchrPtrVentasT)
{
ActualizaCampo("VentasTotales",(const unsigned char *)pchrPtrVentasT);
}

void zCorteCaja::CalculandoCorte(const char *pchrPtrVentasT)
{
ActualizaCampo("CalculandoCorte",(const unsigned char *)pchrPtrVentasT);
}
void zCorteCaja::TotalGastos(const char *pchrPtrVentasT)
{
ActualizaCampo("TotalGastos",(const unsigned char *)pchrPtrVentasT);
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
const char *zCorteCaja::CalculandoCorte()
{
   return (const char *)Campo("CalculandoCorte");
}

const char *zCorteCaja::TotalGastos()
{
   return (const char *)Campo("TotalGastos");
}
const char *zCorteCaja::EdoCuentaCambio()
{
   return (const char *)Campo("EdoCuentaCambio");
}
int zCorteCaja::EdoCuentaCambioInt()
{
  return CampoInt("EdoCuentaCambio");
}
const char *zCorteCaja::CambioDiaAnterior()
{
  return (const char *)Campo("CambioDiaAnterior");
}
const char *zCorteCaja::CorteTotal()
{
   return (const char *)Campo("CorteTotal");
}
zCajas *zCorteCaja::Cajas()
{
  return (zCajas *)AsociadosDelCampo("Cajas");
}
