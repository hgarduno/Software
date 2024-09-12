#include <zCompraParcialImportacion.h>
#include <zSiscomCampo.h>

#include <zCompraImportacion.h> 

zCompraParcialImportacion::zCompraParcialImportacion()
{

(*this)	<<  
new zSiscomCampo("Compra")		<<
new zSiscomCampo("Parcial") ;

}
void zCompraParcialImportacion::Compra(zCompraImportacion *pzCompraC)
{

   AsociadoAlCampo("Compra",pzCompraC);

}
void zCompraParcialImportacion::Parcial(zCompraImportacion *pzCompraF)
{
   AsociadoAlCampo("Parcial",pzCompraF);
}
