#include <zImpresionProveedores.h>
#include <zProveedores.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionProveedores::zImpresionProveedores(zProveedores *pzProveedores):
					     zProvDatos(pzProveedores)
{
Encabezado();
}


void zImpresionProveedores::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("ServiSNTE","SERVISNTE")	 			<<
   RegistroEncabezado("Sistema","Catalogo de Proveedores del sistema")	 		<<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00")				<<
   RegistroEncabezado("Cve","Cve")				<<
   RegistroEncabezado("NombreProveedor","Nombre del Proveedor")				<<
   RegistroEncabezado("Estado","Estado")				<<
   RegistroEncabezado("Direccion","Direccion")				<<
   RegistroEncabezado("Descuentos","Descuentos")				<<
   RegistroEncabezado("CP","CP")				<<
   RegistroEncabezado("Telefonos","Telefonos");
}

zSiscomRegistro *zImpresionProveedores::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zProveedores *zImpresionProveedores::Proveedores()
{
 return zProvDatos;
}

