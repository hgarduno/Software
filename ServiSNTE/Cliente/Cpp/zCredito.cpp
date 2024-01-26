#include <zCredito.h>
#include <zSiscomCampo.h>
zCredito::zCredito()
{
 (*this)				<<
 new zSiscomCampo("IdVenta")		<<
 new zSiscomCampo("IdFinanciadora")	<<
 new zSiscomCampo("IdPlazo")		<<
 new zSiscomCampo("Tasa")		<<
 new zSiscomCampo("PagoQuincenal")	<<
 new zSiscomCampo("PagoTotal")	<<
 new zSiscomCampo("NumeroPagos");
 	
}
void zCredito::IdVenta(const unsigned char *pchrPtrIdVenta)
{
ActualizaCampo("IdVenta",pchrPtrIdVenta);
}

void zCredito::IdFinanciadora(const unsigned char *pchrPtrIdFinanciadora)
{
ActualizaCampo("IdFinanciadora",pchrPtrIdFinanciadora);
}
void zCredito::IdPlazo(const unsigned char *pchrPtrIdPlazo)
{
ActualizaCampo("IdPlazo",pchrPtrIdPlazo);
}
void zCredito::PagoQuincenal(const unsigned char *pchrPtrPagoQuincenal)
{
ActualizaCampo("PagoQuincenal",pchrPtrPagoQuincenal);
}
void zCredito::PagoTotal(const unsigned char *pchrPtrPagoTotal)
{
ActualizaCampo("PagoTotal",pchrPtrPagoTotal);
}
void zCredito::NumeroPagos(const unsigned char *pchrPtrNumeroPagos)
{
ActualizaCampo("NumeroPagos",pchrPtrNumeroPagos);
}
