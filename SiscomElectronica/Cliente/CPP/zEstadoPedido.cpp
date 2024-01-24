#include <zEstadoPedido.h>
#include <zSiscomCampo.h>
zEstadoPedido::zEstadoPedido(const char *pchrPtrIdEstado,
			     const char *pchrPtrDescripcion,
			     const char *pchrPtrFecha,
			     const char *pchrPtrAccion)
{
(*this)										<<
new zSiscomCampo("IdEstado",(const unsigned char *)pchrPtrIdEstado)		<<
new zSiscomCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion)	<<
new zSiscomCampo("Fecha",(const unsigned char *)pchrPtrFecha)			<<
new zSiscomCampo("Accion",(const unsigned char *)pchrPtrAccion);
}
zEstadoPedido::zEstadoPedido(zSiscomRegistro *pzSisRegEdoPedido):
	   zEstadoPedido(pzSisRegEdoPedido->CampoConstChar("idedopedido"),
	   		 pzSisRegEdoPedido->CampoConstChar("dscedopedido"),
	   		 pzSisRegEdoPedido->CampoConstChar("fecha"),
			 pzSisRegEdoPedido->CampoConstChar("accion"))
{

}
void zEstadoPedido::IdEstado(const char *pchrPtrIdEstado)
{
    ActualizaCampo("IdEstado",(const unsigned char *)pchrPtrIdEstado);
}


void zEstadoPedido::Descripcion(const char *pchrPtrDescripcion)
{
    ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion);
}
void zEstadoPedido::Fecha(const char *pchrPtrFecha)
{
    ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}
void zEstadoPedido::Accion(const char *pchrPtrAccion)
{
    ActualizaCampo("Accion",(const unsigned char *)pchrPtrAccion);
}

const char *zEstadoPedido::IdEstado()
{
  return CampoConstChar("IdEstado");
}
const char *zEstadoPedido::Descripcion()
{
  return CampoConstChar("Descripcion");
}

const char *zEstadoPedido::Fecha()
{
  return CampoConstChar("Fecha");
}
const char *zEstadoPedido::Accion()
{
  return CampoConstChar("Accion");
}
zEstadoPedido *zEstadoPedido::EstadoPedido(zSiscomRegistro *pzSisRegPedido)
{
  return new zEstadoPedido(pzSisRegPedido);
}
