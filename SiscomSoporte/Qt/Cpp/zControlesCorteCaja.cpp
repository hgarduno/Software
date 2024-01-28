#include <zControlesCorteCaja.h>
#include <zSiscomCampo.h>
zControlesCorteCaja::zControlesCorteCaja()
{
  (*this) << new zSiscomCampo("Celdas") ;
}
