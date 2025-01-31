#include <zExistenciaVenta.h>

#include <zSiscomCampo.h> 
#include <zProductos.h>

zExistenciaVenta::zExistenciaVenta()
{
(*this) << 
new zSiscomCampo("FechaIni") 	<<
new zSiscomCampo("FechaFin")	<<
new zSiscomCampo("IdExpendio")	<<
new zSiscomCampo("Productos");

}
zExistenciaVenta::zExistenciaVenta(const char *pchrPtrFechaIni,
				   const char *pchrPtrFechaFin)
{
(*this) << 
new zSiscomCampo("FechaIni",(const unsigned char *)pchrPtrFechaIni) 	<<
new zSiscomCampo("FechaFin",(const unsigned char *)pchrPtrFechaFin)	<<
new zSiscomCampo("IdExpendio")						<<
new zSiscomCampo("Productos");
}

void zExistenciaVenta::Productos(zProductos *pzProductos)
{
  AsociadosAlCampo("Productos",pzProductos);
}
void zExistenciaVenta::FechaIni(const char *pchrPtrFechaIni)
{
ActualizaCampo("FechaIni",(const unsigned char *)pchrPtrFechaIni);
}


void zExistenciaVenta::FechaFin(const char *pchrPtrFechaFin)
{
ActualizaCampo("FechaFin",(const unsigned char *)pchrPtrFechaFin);
}

void zExistenciaVenta::IdExpendio(const char *pchrPtrIdExpendio)
{
ActualizaCampo("IdExpendio",(const unsigned char *)pchrPtrIdExpendio);
}
zProductos *zExistenciaVenta::Productos()
{
   return (zProductos *)AsociadosDelCampo("Productos");
}
