#include <zContenedor.h>
#include <zSiscomCampo.h>

#include <zCompraImportacion.h>

zContenedor::zContenedor()
{
(*this)					<<
new zSiscomCampo("IdContenedor")	<<
new zSiscomCampo("Descripcion")		<<
new zSiscomCampo("Partidas")		<<
new zSiscomCampo("Peso")		<<
new zSiscomCampo("Compras");
}
void zContenedor::AgregaCompra(zCompraImportacion *pzComImportacion)
{
   AsociadoAlCampo("Compras",pzComImportacion);  
}
