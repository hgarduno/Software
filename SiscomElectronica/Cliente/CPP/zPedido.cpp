#include <zPedido.h>
#include <zSiscomCampo.h>
#include <zPuntoEntrega.h>
#include <zDireccion.h>
#include <zEstadoPedido.h>
zPedido::zPedido()
{
  (*this)				<<
  new zSiscomCampo("FechaHoraE") 	<<
 new zSiscomCampo("SePagaCon")		<<
  new zSiscomCampo("Cambio")		<<
  new zSiscomCampo("Observaciones")	<<
  new zSiscomCampo("EstadoPedido")	<<
  new zSiscomCampo("TipoEntrega")	<<
  new zSiscomCampo("PuntoEntrega");
}

zPedido::zPedido(zSiscomRegistro *pzSisRegDato)
{
  (*this)								<<
  new zSiscomCampo("FechaHoraE",pzSisRegDato->Campo("fechaentrega")) 	<<
  new zSiscomCampo("SePagaCon",pzSisRegDato->Campo("sepagacon"))	<<
  new zSiscomCampo("Cambio",pzSisRegDato->Campo("cambio"))		<<
  new zSiscomCampo("Observaciones",pzSisRegDato->Campo("observaciones"))<<
  new zSiscomCampo("EstadoPedido")					<<
  new zSiscomCampo("TipoEntrega",pzSisRegDato->Campo("tipoentrega"))	<<
  new zSiscomCampo("PuntoEntrega");
}


void zPedido::FechaHoraE(const char *pchrPtrFechaHoraE)
{
	ActualizaCampo("FechaHoraE",(const unsigned char *)pchrPtrFechaHoraE);
}
void zPedido::SePagaCon(const char *pchrPtrSePagaCon)
{
	ActualizaCampo("SePagaCon",(const unsigned char *)pchrPtrSePagaCon);
}
void zPedido::Cambio(const char *pchrPtrCambio)
{
	ActualizaCampo("Cambio",(const unsigned char *)pchrPtrCambio);
}
void zPedido::Observaciones(const char *pchrPtrObservaciones)
{
     ActualizaCampo("Observaciones",(const unsigned char *)pchrPtrObservaciones);
}
void zPedido::EstadoPedido(zEstadoPedido *pzEstadoPedido)
{
	ActualizaCampo("EstadoPedido",pzEstadoPedido);
}
void zPedido::PuntoEntrega(zPuntoEntrega *pzPEntrega)
{
	ActualizaCampo("PuntoEntrega",pzPEntrega);
}
void zPedido::TipoEntrega(const char *pchrPtrTipoEntrega)
{
	ActualizaCampo("TipoEntrega",(const unsigned char *)pchrPtrTipoEntrega);
}
void zPedido::Direccion(zDireccion *pzDireccion)
{
  PuntoEntrega()->Direccion(pzDireccion);
}
const  char *zPedido::FechaHoraE()
{
	return (const char *)Campo("FechaHoraE");
}
const  char *zPedido::SePagaCon()
{
	return (const char *)Campo("SePagaCon");
}

const  char *zPedido::Observaciones()
{
	return (const char *)Campo("Observaciones");
}
const char *zPedido::Cambio()
{
	return (const char *)Campo("Cambio");
}
const char *zPedido::TipoEntrega()
{
  return CampoConstChar("TipoEntrega");
}
int zPedido::TipoEntregaInt()
{
  return CampoInt("TipoEntrega");
}
zPuntoEntrega *zPedido::PuntoEntrega()
{
    return (zPuntoEntrega *)AsociadoDelCampo("PuntoEntrega");
}
zEstadoPedido *zPedido::EstadoPedido()
{
	return (zEstadoPedido *)AsociadoDelCampo("EstadoPedido");
}
const char *zPedido::Calle()
{
  return PuntoEntrega()->Direccion()->Calle();
}

