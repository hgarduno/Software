#include <zCompra.h> 
#include <zProductoCompra.h>
#include <zSiscomCampo.h>

#include <zSiscomRegistros.h>


#include <zProductos.h> 


zCompra::zCompra()
{
(*this) 				<< 
new zSiscomCampo("IdCompra") 		<<
new zSiscomCampo("IdOrigenCompra") 	<<
new zSiscomCampo("Fecha") 		<<
new zSiscomCampo("Importe")		<<
new zSiscomCampo("Productos");
}

zCompra::zCompra(zSiscomRegistro *pzSisRegCompra)
{

(*this) 				<< 
new zSiscomCampo("IdCompra",(*pzSisRegCompra)["idcompra"]) <<
new zSiscomCampo("IdOrigenCompra") 			   <<
new zSiscomCampo("Fecha",(*pzSisRegCompra)["fecha"]) 	   <<
new zSiscomCampo("Importe",(*pzSisRegCompra)["importe"])   <<
new zSiscomCampo("Productos");

Productos(pzSisRegCompra->AsociadosDelCampo("Productos"));


}

void zCompra::IdCompra(const char *pchrPtrIdCompra)
{
ActualizaCampo("IdCompra",(const unsigned char *)pchrPtrIdCompra);
}
void zCompra::Fecha(const char *pchrPtrFecha)
{
ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}
void zCompra::Importe(const char *pchrPtrImporte)
{
ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}
void zCompra::Productos(zSiscomRegistros *pzSisRegsCompra)
{
zSiscomRegistro *lzSisRegCompra;
zProductos *lzProductos=new zProductos;
for(lzSisRegCompra=pzSisRegsCompra->Primer();
    lzSisRegCompra;
    lzSisRegCompra=pzSisRegsCompra->Siguiente())
  (*lzProductos) << zProductoCompra::DeCompra(lzSisRegCompra);
AsociadosAlCampo("Productos",lzProductos);
}
zProductos *zCompra::Productos()
{
  return (zProductos *)AsociadosDelCampo("Productos");
}
