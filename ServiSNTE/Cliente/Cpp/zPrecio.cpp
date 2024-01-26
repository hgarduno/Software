#include <zPrecio.h>
#include <zSiscomCampo.h>
zPrecio::zPrecio(const char *pchrPtrIdPrecio,
		 const char *pchrPtrPrecio,
		 const char *pchrPtrMargen)
{
  (*this)				<< 
  new zSiscomCampo("IdPrecio")		<<
  new zSiscomCampo("Precio",(const unsigned char *)pchrPtrPrecio) <<
  new zSiscomCampo("Margen",(const unsigned char *)pchrPtrMargen);
}
void zPrecio::Precio(const unsigned char *pchrPtrPrecio)
{
  ActualizaCampo("Precio",pchrPtrPrecio);
}

const char *zPrecio::Precio()
{
	return (const char *)(*this)["Precio"];
}
		 
