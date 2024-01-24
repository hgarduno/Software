#include <zDinero.h>
#include <zSiscomCampo.h>
zDinero::zDinero()
{
  (*this) 			<< 
  new zSiscomCampo("Importe") 	<<
  new zSiscomCampo("Monedas");
}
