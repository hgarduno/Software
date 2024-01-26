#include <zImpresionCuentasPagar.h>
#include <zCuentasPagar.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionCuentasPagar::zImpresionCuentasPagar(zCuentasPagar *pzCuentasPagar):
						zCtsPagar(pzCuentasPagar)
{
Encabezado();
}


void zImpresionCuentasPagar::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("Sistema","Reporte de Cuentas por Pagar") 	<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 			<<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00") 					<<
   RegistroEncabezado("LibroAplicacion","LibroAplicacion") 					<<
   RegistroEncabezado("Documento","Documento") 		<<
   RegistroEncabezado("FechaDocto","Fecha Docto") 				<<
   RegistroEncabezado("FechaVenc","Fecha Venc") 					<<
   RegistroEncabezado("Cargos","Cargos")					<<
   RegistroEncabezado("Abonos","Abonos")			<<
   RegistroEncabezado("PorPagar","porPagar");
}
zSiscomRegistro *zImpresionCuentasPagar::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zCuentasPagar *zImpresionCuentasPagar::CuentasPagar()
{
 return zCtsPagar;
}
