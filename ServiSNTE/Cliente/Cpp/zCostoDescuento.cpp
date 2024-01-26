#include <zCostoDescuento.h>
#include <zCosto.h>
#include <zDescuento.h>
zCostoDescuento::zCostoDescuento(zCosto *pzCosto,
				 zDescuento *pzDescuento)
{
  AgregaCampo("Costo",pzCosto);
  AgregaCampo("Descuento",pzDescuento);

}
