#include <zProductosImportados.h>
#include <zProductoImportado.h>
#include <zSiscomDesarrollo4.h>
#include <string.h>
zProductosImportados::zProductosImportados()
{

}
zProductosImportados &zProductosImportados::operator<<(zProductoImportado *pzProdImportado)
{
	Agrega(pzProdImportado);
      return (*this);
}

void zProductosImportados::Actualiza(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistro *lzSisRegProducto;
zProductoImportado *lzProdImportado;
for(lzSisRegProducto=pzSisRegsProductos->Primer();
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsProductos->Siguiente())
  
 if((lzProdImportado=Producto((zProductoImportado *)lzSisRegProducto)))
     (*lzProdImportado)=(zProductoImportado *)lzSisRegProducto;

}
zProductoImportado *zProductosImportados::Producto(zProductoImportado *pzProdImportado)
{
zProductoImportado *lzProdImportado;

for(lzProdImportado=(zProductoImportado *)Primer();
    lzProdImportado;
    lzProdImportado=(zProductoImportado *)Siguiente())
{
    if( (*lzProdImportado)==pzProdImportado)
      return lzProdImportado;
}
return 0;
}

void zProductosImportados::ProductosFiltrados(const char *pchrPtrCantidad,
					      const char *pchrPtrCostoUnitario,
					      const char *pchrPtrPeso,
						zSiscomRegistros *pzSisRegsProductos)
{
zProductoImportado *lzProdImportado;
for(lzProdImportado=(zProductoImportado *)pzSisRegsProductos->Primer();
    lzProdImportado;
    lzProdImportado=(zProductoImportado *)pzSisRegsProductos->Siguiente())
{
    lzProdImportado->AgregaCampos();
    lzProdImportado->Cantidad(pchrPtrCantidad);
    lzProdImportado->Peso(pchrPtrPeso);
    lzProdImportado->CostoUnitarioDolares(pchrPtrCostoUnitario);
}
}
void zProductosImportados::Partidas(char *pchrPtrPartidas)
{
   sprintf(pchrPtrPartidas,"%d",NNodos());
}
void zProductosImportados::ActualizandoClave(zSiscomRegistro *pzSisRegProducto)
{
zProductoImportado *lzProdImportado;

for(lzProdImportado=(zProductoImportado *)Primer();
    lzProdImportado;
    lzProdImportado=(zProductoImportado *)Siguiente())
{
     if(!strcmp((const char *)pzSisRegProducto->Campo("CveProveedor"),
     		lzProdImportado->CveProveedor()))
     lzProdImportado->Clave((const char *)pzSisRegProducto->Campo("CveProducto"));
}

}
void zProductosImportados::AsignaClave(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistro *lzSisRegProducto;
 for(lzSisRegProducto=pzSisRegsProductos->Primer();
     lzSisRegProducto;
     lzSisRegProducto=pzSisRegsProductos->Siguiente())
 {
     ActualizandoClave(lzSisRegProducto);
 }
}
