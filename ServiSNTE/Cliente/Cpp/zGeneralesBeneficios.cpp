#include <zGeneralesBeneficios.h>
#include <zSiscomCampo.h>

zGeneralesBeneficios::zGeneralesBeneficios(const char *pchrPtrIdVenta)
{
  (*this)		<<
  new zSiscomCampo("IdVenta",(const unsigned char *)pchrPtrIdVenta) <<
  new zSiscomCampo("Lugar")						<<
  new zSiscomCampo("Fecha");
}

zGeneralesBeneficios::zGeneralesBeneficios(zSiscomRegistro *pzSisRegRegreso)
{
  (*this)								<<
  new zSiscomCampo("IdVenta",(*pzSisRegRegreso)["idventa"]) 		<<
  new zSiscomCampo("Lugar",(*pzSisRegRegreso)["lugar"])			<<
  new zSiscomCampo("Fecha",(*pzSisRegRegreso)["fecha"]);
}

void zGeneralesBeneficios::Lugar(const char *pchrPtrLugar)
{
  ActualizaCampo("Lugar",(const unsigned char *)pchrPtrLugar);

}


void zGeneralesBeneficios::Fecha(const char *pchrPtrFecha)
{
  ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);

}
