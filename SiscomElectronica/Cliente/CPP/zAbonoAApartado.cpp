#include <zAbonoAApartado.h>

#include <zSiscomCampo.h>

zAbonoAApartado::zAbonoAApartado(const char *pchrPtrIdVenta)
{
(*this)								   	<<
 new zSiscomCampo("IdVenta",(const unsigned char *)pchrPtrIdVenta) 	<<
 new zSiscomCampo("Fecha")						<<
 new zSiscomCampo("Importe");
}

zAbonoAApartado::zAbonoAApartado(zSiscomRegistro *pzSisRegAAA)
{
 (*this)					<<
 new zSiscomCampo("IdVenta") 			<<
 new zSiscomCampo("Fecha",(*pzSisRegAAA)["fecha"]) <<
 new zSiscomCampo("Importe",(*pzSisRegAAA)["importe"]);
}

void zAbonoAApartado::Fecha(const char *pchrPtrFecha)
{
  ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}


void zAbonoAApartado::Importe(const char *pchrPtrImporte)
{
 ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}

