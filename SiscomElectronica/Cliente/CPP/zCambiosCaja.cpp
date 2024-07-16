#include <zCambiosCaja.h>
#include <zCambioCaja.h>


zCambiosCaja::zCambiosCaja()
{

}
void zCambiosCaja::CambiosCaja(zSiscomRegistros *pzSisRegsRegreso)
{
zSiscomRegistro *lzSisRegCambioCaja;
for(lzSisRegCambioCaja=pzSisRegsRegreso->Primer();
    lzSisRegCambioCaja;
    lzSisRegCambioCaja=pzSisRegsRegreso->Siguiente())
  Agrega(new zCambioCaja(lzSisRegCambioCaja));
}

zCambioCaja *zCambiosCaja::CambioCaja(int pintNCambio)
{
    return (zCambioCaja *)(*this)[pintNCambio];
}
