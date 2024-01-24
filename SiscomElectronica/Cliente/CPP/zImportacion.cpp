#include <zImportacion.h>
#include <zSiscomCampo.h>

zImportacion::zImportacion()
{
 (*this) 				<<
 new zSiscomCampo("IdProveedor")	<<
 new zSiscomCampo("Fecha")		<<
 new zSiscomCampo("Descripcion")	<<
 new zSiscomCampo("Cotizaciones")	<<
 new zSiscomCampo("CompraImportacion");

}
