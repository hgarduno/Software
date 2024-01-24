#include <zMoneda.h>
#include <zSiscomCampo.h>
zMoneda::zMoneda()
{
  (*this) 			<<  
  new zSiscomCampo("Cantidad")   <<
  new zSiscomCampo("Importe") ;
}
