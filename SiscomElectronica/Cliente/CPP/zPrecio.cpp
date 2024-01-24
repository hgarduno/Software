#include <zPrecio.h>
#include <zSiscomCampo.h>

#include <TipoPrecios.h>

zPrecio::zPrecio(const char *pchrPtrPrecio,
		 const char *pchrPtrIdPersona)
{
(*this)	<<  
new zSiscomCampo("Precio",(const unsigned char *)pchrPtrPrecio) << 
new zSiscomCampo("IdPersona",(const unsigned char *)pchrPtrIdPersona);
}
void zPrecio::Precio(const char *pchrPtrPrecio)
{
ActualizaCampo("Precio",(const unsigned char *)pchrPtrPrecio);
}
zPrecio *zPrecio::DeTipoPrecio(TipoPrecio *pTPrecio)
{
return new zPrecio(0,(*pTPrecio)["NmbTipoPrecio"]);
}
