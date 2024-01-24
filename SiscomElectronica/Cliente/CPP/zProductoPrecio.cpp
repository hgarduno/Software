#include <zProductoPrecio.h>

#include <zPrecios.h>

#include <zSiscomCampo.h>

zProductoPrecio::zProductoPrecio(const char *pchrPtrClave):
		zProducto(pchrPtrClave)
{
  (*this) << new zSiscomCampo("Precios");
}
void zProductoPrecio::Precios(zPrecios *pzPrecios)
{
 ActualizaCampo("Precios",pzPrecios);
} 
