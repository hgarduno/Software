#include <zCierreCaja.h>

#include <zSiscomCampo.h>

zCierreCaja::zCierreCaja()
{
  (*this)				<< 
  new zSiscomCampo("EfectivoCaja")	<<
  new zSiscomCampo("Cambio")		<<
  new zSiscomCampo("Bolsa");
}
