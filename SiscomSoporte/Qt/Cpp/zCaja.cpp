#include <zCaja.h>
#include <zSiscomCampo.h>
#include <zEncabezadoCaja.h>
#include <zGasto.h>
#include <zDenominaciones.h>
#include <zEncabezadosCaja.h>
#include <zGastos.h>

#include <string.h>
zCaja::zCaja(const char *pchrPtrCaja)
{
 (*this) 							<<
 new zSiscomCampo("Caja",(const unsigned char *)pchrPtrCaja)	<<
 new zSiscomCampo("Encabezados")				<<
 new zSiscomCampo("Total")					<<
 new zSiscomCampo("TotalGastos")				<<
 new zSiscomCampo("Dinero")					<<
 new zSiscomCampo("Gastos")					<<
 new zSiscomCampo("PagoTarjeta")				<<
 new zSiscomCampo("Transferencias");
}
void zCaja::Dinero(zDenominaciones *pzDenoSCaja)
{

   ActualizaCampo("Dinero",pzDenoSCaja);
}

void zCaja::Total(const char *pchrPtrTotal)
{
    ActualizaCampo("Total",(const unsigned char *)pchrPtrTotal);
}

void zCaja::TotalGastos(const char *pchrPtrTotalGastos)
{
    ActualizaCampo("TotalGastos",(const unsigned char *)pchrPtrTotalGastos);
}

void zCaja::PagoTarjeta(const char *pchrPtrTotalGastos)
{
    ActualizaCampo("PagoTarjeta",(const unsigned char *)pchrPtrTotalGastos);
}
void zCaja::EncabezadosCaja(zEncabezadosCaja *pzEncaSCaja)
{
  ActualizaCampo("Encabezados",pzEncaSCaja);
}
const char *zCaja::Caja()
{
   return (const char *)(*this)["Caja"];
}
zDenominaciones *zCaja::Dinero()
{
   return (zDenominaciones *)AsociadosDelCampo("Dinero");
}
zEncabezadosCaja *zCaja::EncabezadosCaja()
{
   return (zEncabezadosCaja *)AsociadosDelCampo("Encabezados");
}
zGastos *zCaja::Gastos()
{
   return (zGastos *)AsociadosDelCampo("Gastos");
}
const char *zCaja::Total()
{
   return (const char *)(*this)["Total"];
}
const char *zCaja::TotalGastos()
{
   return (const char *)(*this)["TotalGastos"];
}
const char *zCaja::PagoTarjeta()
{
   return (const char *)(*this)["PagoTarjeta"];
}
void zCaja::Actualiza(zSiscomRegistro *pzSisRegCaja)
{
zDenominaciones *lzDenoS;
Total((const char *)(*pzSisRegCaja)["Total"]);
lzDenoS=(zDenominaciones *)AsociadosDelCampo("Dinero");
lzDenoS->Actualiza(pzSisRegCaja->AsociadosDelCampo("Dinero"));
}
zEncabezadoCaja *zCaja::EncabezadoTotal()
{
  return EncabezadosCaja()->Encabezado("Total");
}
void zCaja::Gasto(zGasto *pzGasto)
{
    AsociadoAlCampo("Gastos",pzGasto);
}
int zCaja::EsElGasto(zGasto *pzGasto,int pintFila,int pintColumna)
{
  return pzGasto->Fila()==pintFila && (pzGasto->Columna()+1)==pintColumna;
}
zGasto *zCaja::Gasto(int pintFila,int pintColumna)
{
zGasto *lzGasto;
if(Gastos())
for(lzGasto=(zGasto *)Gastos()->Primer();lzGasto;lzGasto=(zGasto *)Gastos()->Siguiente())
if(EsElGasto(lzGasto,pintFila,pintColumna))
  return lzGasto;

return 0;
}
bool operator==(zCaja &pzCaja1,zCaja &pzCaja2)
{
    return !strcmp(pzCaja1.Caja(),pzCaja2.Caja());
}
