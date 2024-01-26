#include <zImpresionListaPreciosComprador.h>
#include <zListaPreciosComprador.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionListaPreciosComprador::zImpresionListaPreciosComprador(zListaPreciosComprador *pzLstPrecios):
							zImpresionListaPrecios(pzLstPrecios,"Productos Para Tiendas Por Tienda y Proveedor")
						
{
  (*this)		<<
   RegistroEncabezado("PrecioMexico","Precio Mexico")	<<
   RegistroEncabezado("PrecioForaneo","Precio Foraneo");
}

