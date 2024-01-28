#include <zCajas.h>
#include <zDenominaciones.h>
#include <zEncabezadosCaja.h>
#include <zDenominacion.h>

#include <zCaja.h>


#include <zSiscomDesarrollo4.h>
zCajas::zCajas()
{
 
}
zDenominacion *zCajas::Denominacion(int pintFila,int pintColumna)
{
zCaja *lzCaja;
zDenominacion *lzDenominacion;
for(lzCaja=(zCaja *)Primer();lzCaja;lzCaja=(zCaja *)Siguiente())
  if((lzDenominacion=lzCaja->Dinero()->Denominacion(pintFila,pintColumna)))
  return lzDenominacion;
return 0;
}
void zCajas::Actualiza(zSiscomRegistros *pzSisRegsCajas)
{
 zCaja *lzCaja,*lzCajaPActualizar;
for(lzCaja=(zCaja *)Primer();lzCaja;lzCaja=(zCaja *)Siguiente())
if((lzCajaPActualizar=Caja(lzCaja,pzSisRegsCajas)))
{
  lzCaja->Actualiza(lzCajaPActualizar);
  lzCaja->TotalGastos(lzCajaPActualizar->TotalGastos());
}
}
zCaja *zCajas::Caja(zCaja *pzCaja,zSiscomRegistros *pzSisRegsCajas)
{
zCaja *lzCaja;
for(lzCaja=(zCaja *)pzSisRegsCajas->Primer();
    lzCaja;
    lzCaja=(zCaja *)pzSisRegsCajas->Siguiente())
 if((*pzCaja)==(*lzCaja))
  return lzCaja;
 return 0;
}
zCaja *zCajas::Principal()
{
  return (zCaja *)(*this)[0];
}
void zCajas::EncabezadosGastos(zEncabezadosCaja *pzEncaSGastos)
{
   zEncaSCorte=pzEncaSGastos; 
}
void zCajas::EncabezadosPagoTarjeta(zEncabezadosCaja *pzEncaSPagoT)
{
  (*zEncaSCorte)+=(*pzEncaSPagoT);
}
void zCajas::EncabezadosImporteGastos(zEncabezadosCaja *pzEncaSImGastos)
{
  (*zEncaSCorte)+=(*pzEncaSImGastos);
}
void zCajas::EncabezadosVentasEfectivo(zEncabezadosCaja *pzEncaSVenEfe)
{
 (*zEncaSCorte)+=(*pzEncaSVenEfe);
}
zEncabezadosCaja *zCajas::EncabezadosCorte()
{
   return zEncaSCorte;
}
	
