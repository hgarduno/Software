#include <zCircuitoImpreso.h>
#include <zSiscomCampo.h>
zCircuitoImpreso::zCircuitoImpreso(const char *pchrPtrIdImpreso)
{
   (*this) 									<< 
   new zSiscomCampo("IdImpreso",(const unsigned char *)pchrPtrIdImpreso) 	<<
   new zSiscomCampo("IdVenta")							<<
   new zSiscomCampo("Cliente")							<<
   new zSiscomCampo("CveProducto")						<<
   new zSiscomCampo("Memoria")							<<
   new zSiscomCampo("Archivo")							<<
   new zSiscomCampo("FechaHoraEntrega")						<<
   new zSiscomCampo("IdEstado",(const unsigned char *)"0")			<<
   new zSiscomCampo("Pagado");
}
void zCircuitoImpreso::IdVenta(const char *pchrPtrIdVenta)
{
  ActualizaCampo("IdVenta",(const unsigned char *)pchrPtrIdVenta);
}
void zCircuitoImpreso::IdCliente(const char *pchrPtrIdCliente)
{
 ActualizaCampo("Cliente",(const unsigned char *)pchrPtrIdCliente);
}
void zCircuitoImpreso::CveProducto(const char *pchrPtrCveProducto)
{
  ActualizaCampo("CveProducto",(const unsigned char *)pchrPtrCveProducto);
}
void zCircuitoImpreso::Memoria(const char *pchrPtrMemoria)
{
  ActualizaCampo("Memoria",(const unsigned char *)pchrPtrMemoria);
}
void zCircuitoImpreso::Archivo(const char *pchrPtrArchivo)
{
  ActualizaCampo("Archivo",(const unsigned char *)pchrPtrArchivo);
}

void zCircuitoImpreso::FechaHoraEntrega(const char *pchrPtrFechaHoraEntrega)
{
  ActualizaCampo("FechaHoraEntrega",(const unsigned char *)pchrPtrFechaHoraEntrega);
}
void zCircuitoImpreso::Pagado(const char *pchrPtrPagado)
{
   ActualizaCampo("Pagado",(const unsigned char *)pchrPtrPagado);
}
