#include <zProductoCotImp.h>
#include <zSiscomCampo.h>

#include <zSiscomDesarrollo4.h>
zProductoCotImp::zProductoCotImp(zSiscomRegistro *pzSisRegProducto):zProducto()
{
 ActualizaCampo("Clave",(*pzSisRegProducto)["cveproducto"]);
 
 (*this)  				<< 
 new zSiscomCampo("Cantidad")		<<
 new zSiscomCampo("Peso")		<<
 new zSiscomCampo("Precio")		<<
 new zSiscomCampo("PesoTotal")		<<
 new zSiscomCampo("Importe");

}
zProductoCotImp *zProductoCotImp::ProductoDeRegistro(zSiscomRegistro *pzSisRegProducto)
{
zProductoCotImp *lzProdCotImp=new zProductoCotImp(pzSisRegProducto);
   lzProdCotImp->Cantidad((const char *)(*pzSisRegProducto)["cantidad"]);
   lzProdCotImp->Peso((const char *)(*pzSisRegProducto)["peso"]);
   lzProdCotImp->Precio((const char *)(*pzSisRegProducto)["precio"]);
   lzProdCotImp->PesoTotal((const char *)(*pzSisRegProducto)["pesototal"]);
   lzProdCotImp->Importe((const char *)(*pzSisRegProducto)["importe"]);
   return lzProdCotImp;
}
void zProductoCotImp::Peso(const char *pchrPtrPeso)
{
	ActualizaCampo("Peso",(const unsigned char *)pchrPtrPeso);
}

void zProductoCotImp::Precio(const char *pchrPtrPrecio)
{
	ActualizaCampo("Precio",(const unsigned char *)pchrPtrPrecio);
}
void zProductoCotImp::Cantidad(const char *pchrPtrCantidad)
{
	ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}

void zProductoCotImp::PesoTotal(const char *pchrPtrPeso)
{
    ActualizaCampo("PesoTotal",(const unsigned char *)pchrPtrPeso);
}
void zProductoCotImp::Importe(const char *pchrPtrImporte)
{
   ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}

const char *zProductoCotImp::Cantidad()
{
	return (const char *)(*this)["Cantidad"];
}

const char *zProductoCotImp::Peso()
{
	return (const char *)(*this)["Peso"];
}
const char *zProductoCotImp::Precio()
{
	return (const char *)(*this)["Precio"];
}
const char *zProductoCotImp::PesoTotal()
{
	return (const char *)(*this)["PesoTotal"];
}
const char *zProductoCotImp::Importe()
{
	return (const char *)(*this)["Importe"];
}
