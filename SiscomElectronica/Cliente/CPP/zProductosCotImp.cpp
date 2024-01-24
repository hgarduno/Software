#include <zProductosCotImp.h>
#include <zProductoCotImp.h>
#include <zSiscomDesarrollo4.h>
zProductosCotImp::zProductosCotImp()
{

}
void zProductosCotImp::Agrega(zProductoCotImp *pzProdCotImp)
{
    (*this) << pzProdCotImp;
}
void zProductosCotImp::Agrega(zProductosCotImp *pzProdsCotImp)
{
zProductoCotImp *lzProdCotImp;
  for(lzProdCotImp=(zProductoCotImp *)pzProdsCotImp->Primer(); 
      lzProdCotImp;
      lzProdCotImp=(zProductoCotImp *)pzProdsCotImp->Siguiente())
   Agrega(lzProdCotImp);
}
void zProductosCotImp::Agrega(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistro *lzSisRegProducto;
  for(lzSisRegProducto=pzSisRegsProductos->Primer();
      lzSisRegProducto;
      lzSisRegProducto=pzSisRegsProductos->Siguiente())
    Agrega(zProductoCotImp::ProductoDeRegistro(lzSisRegProducto));

}
void zProductosCotImp::PesoTotalProducto(const char *pchrPtrCveProducto,
				         const char *pchrPtrPesoTotal)
{
zProductoCotImp *lzProdCotImp=Producto(pchrPtrCveProducto);
if(lzProdCotImp)
 lzProdCotImp->PesoTotal(pchrPtrPesoTotal); 

}
void zProductosCotImp::ImporteProducto(const char *pchrPtrCveProducto,
				         const char *pchrPtrPesoTotal)
{
zProductoCotImp *lzProdCotImp=Producto(pchrPtrCveProducto);
if(lzProdCotImp)
 lzProdCotImp->Importe(pchrPtrPesoTotal); 
}

zProductoCotImp *zProductosCotImp::Producto(const char *pchrPtrCveProducto)
{
zProductoCotImp *lzProductoCotImp;
for(lzProductoCotImp=(zProductoCotImp *)Primer(); 
    lzProductoCotImp; 
    lzProductoCotImp=(zProductoCotImp *)Siguiente())
{
     if((*lzProductoCotImp)==pchrPtrCveProducto)
     return lzProductoCotImp;
}
return 0;
}
