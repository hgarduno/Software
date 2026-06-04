#include <zPedidoExistenciaM.h>
#include <zSiscomCampo.h>
#include <zProductoCotizar.h>

zPedidoExistenciaM::zPedidoExistenciaM()
{
(*this) << 
new zSiscomCampo("Porcentaje") 		<<
new zSiscomCampo("IdExpendio") 		<<
new zSiscomCampo("IdPedido") 		<<
new zSiscomCampo("Fecha") 		<<
new zSiscomCampo("Observaciones") 	<<
new zSiscomCampo("Productos");

}


void zPedidoExistenciaM::IdExpendio(const char *pchrPtrIdExpendio)
{
   ActualizaCampo("IdExpendio",(const unsigned char *)pchrPtrIdExpendio);
}
void zPedidoExistenciaM::Porcentaje(const char *pchrPtrPorcentaje)
{
  ActualizaCampo("Porcentaje",(const unsigned char *)pchrPtrPorcentaje);
}

void zPedidoExistenciaM::IdPedido(const char *pchrPtrIdPedido)
{
  ActualizaCampo("IdPedido",(const unsigned char *)pchrPtrIdPedido);
}

void zPedidoExistenciaM::Fecha(const char *pchrPtrFecha)
{
  ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}


void zPedidoExistenciaM::Observaciones(const char *pchrPtrObservaciones)
{
  ActualizaCampo("Observaciones",(const unsigned char *)pchrPtrObservaciones);
}

void zPedidoExistenciaM::Productos(zProductos *pzProductos)
{
  ActualizaCampo("Productos",(zSiscomRegistros *)pzProductos);
}
void zPedidoExistenciaM::Productos(zSiscomRegistros *pzSisRegProductos)
{
zProductoCotizar *lzProdCotizar=new zProductoCotizar;

}
const char *zPedidoExistenciaM::IdExpendio()
{
  return  (const char *)(*this)["IdExpendio"];
}
const char *zPedidoExistenciaM::Porcentaje()
{
  return (const char *)(*this)["Porcentaje"];
}

const char *zPedidoExistenciaM::IdPedido()
{
  return (const char *)(*this)["IdPedido"];
}
const char *zPedidoExistenciaM::Fecha()
{
  return (const char *)(*this)["Fecha"];
}

const char *zPedidoExistenciaM::Observaciones()
{
  return (const char *)(*this)["Observaciones"];
}

zProductos *zPedidoExistenciaM::Productos()
{
  return (zProductos *)AsociadosDelCampo("Productos");
}
