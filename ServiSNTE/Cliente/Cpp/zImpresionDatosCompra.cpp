#include <zImpresionDatosCompra.h>
#include <zDatosCompra.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionDatosCompra::zImpresionDatosCompra(zDatosCompra *pzDatosCompra):
						zSopComp(pzDatosCompra)
{
Encabezado();
}


void zImpresionDatosCompra::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("ServiSNTE","SERVISNTE")	 			<<
   RegistroEncabezado("Sistema","Registro de Compras")	 		<<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00") 				<<
   RegistroEncabezado("Depto","Depto:") 				<<
   RegistroEncabezado("Proveedor","Proveedor:") 			<<
   RegistroEncabezado("Telefonos","Telefonos:") 			<<
   RegistroEncabezado("Plazo","Plazo:") 				<<
   RegistroEncabezado("CP","CP:") 					<<
   RegistroEncabezado("Cve","Cve")					<<
   RegistroEncabezado("Modelo","Modelo")				<<
   RegistroEncabezado("NombreProducto","Nombre del producto")		<<
   RegistroEncabezado("CostoBruto","C. Bruto")				<<
   RegistroEncabezado("D1","1")						<<
   RegistroEncabezado("D2","2")						<<
   RegistroEncabezado("D3","3")						<<
   RegistroEncabezado("D4","4")						<<
   RegistroEncabezado("CostoNeto","C. Neto")				<<
   RegistroEncabezado("PrecioVenta","P. Venta")				<<
   RegistroEncabezado("Margen","Margen");
}

zSiscomRegistro *zImpresionDatosCompra::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zDatosCompra *zImpresionDatosCompra::DatosCompra()
{
 return zSopComp;
}

void zImpresionDatosCompra::Departamento(zSiscomRegistro *pzSisRegDepartamento)
{
   zSisRegDepartamento=pzSisRegDepartamento;
}

zSiscomRegistro *zImpresionDatosCompra::Departamento()
{
	return zSisRegDepartamento;
}
