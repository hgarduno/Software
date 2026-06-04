#include <zPedidoPorCotizacion.h>
#include <zSiscomCampo.h>
zPedidoPorCotizacion::zPedidoPorCotizacion()
{
(*this) 						<<
new zSiscomCampo("IdExpendio")				<<
new zSiscomCampo("IdPedido") 				<<
new zSiscomCampo("Fecha")				<<
new zSiscomCampo("Observaciones")			<<
new zSiscomCampo("Productos");
}

void zPedidoPorCotizacion::Observaciones(const char *pchrPtrObservaciones)
{
  ActualizaCampo("Observaciones",(const unsigned char *)pchrPtrObservaciones);
}

void zPedidoPorCotizacion::Productos(zSiscomRegistros *pzSisRegsProductos)
{
  AsociadosAlCampo("Productos",pzSisRegsProductos); 
}

void zPedidoPorCotizacion::IdExpendio(const char *pchrPtrIdExpendio)
{
 ActualizaCampo("IdExpendio",(const unsigned char *)pchrPtrIdExpendio);
}
