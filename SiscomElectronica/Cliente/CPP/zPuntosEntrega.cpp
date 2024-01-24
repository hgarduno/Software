#include <zPuntosEntrega.h>
#include <zPuntoEntrega.h>
#include <zSiscomRegistro.h>

zPuntosEntrega::zPuntosEntrega()
{

}
zPuntosEntrega *zPuntosEntrega::DeConsulta(zSiscomRegistros *pzSisRegsConsulta)
{
zSiscomRegistro *lzSisRegDato;
zPuntosEntrega *lzPsEntrega;
lzPsEntrega=new zPuntosEntrega;
for(lzSisRegDato=pzSisRegsConsulta->Primer();
    lzSisRegDato;
    lzSisRegDato=pzSisRegsConsulta->Siguiente())
    (*lzPsEntrega) << zPuntoEntrega::PuntoEntrega(lzSisRegDato);
return lzPsEntrega;
}
zPuntoEntrega *zPuntosEntrega::PuntoEntrega(int pintNPEntrega)
{
  return (zPuntoEntrega *)(*this)[pintNPEntrega];
}
zDireccion *zPuntosEntrega::Direccion(int pintNPEntrega)
{
  return PuntoEntrega(pintNPEntrega)->Direccion();
}
