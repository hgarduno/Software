#include <zAbonos.h>
#include <zAbonoAApartado.h>



zAbonos::zAbonos()
{

}

void zAbonos::Agrega(zAbonoAApartado *pzAbonoAA)
{
  zSiscomRegistros::Agrega(pzAbonoAA);
}
void zAbonos::Abonos(zSiscomRegistros *pzSisRegsAbonos)
{
zSiscomRegistro *lzSisRegAbono;
SiscomRegistrosLog(pzSisRegsAbonos);
for(lzSisRegAbono=pzSisRegsAbonos->Primer();
    lzSisRegAbono;
    lzSisRegAbono=pzSisRegsAbonos->Siguiente())
{
    AgregaAbonos(lzSisRegAbono); 
}
}

void zAbonos::AgregaAbonos(zSiscomRegistro *pzSisRegAbono)
{
zAbonoAApartado *lzAbonoAA;
zSiscomRegistro *lzSisRegAbono;
if(pzSisRegAbono->AsociadosDelCampo("AbonosApartado"))
{
lzAbonoAA=new zAbonoAApartado((const char *)(*pzSisRegAbono)["idventa"]);
SiscomRegistrosLog(pzSisRegAbono->AsociadosDelCampo("AbonosApartado"));
for(lzSisRegAbono=pzSisRegAbono->AsociadosDelCampo("AbonosApartado")->Primer();
    lzSisRegAbono;
    lzSisRegAbono=pzSisRegAbono->AsociadosDelCampo("AbonosApartado")->Siguiente())
{
    lzAbonoAA->Fecha((const char *)(*lzSisRegAbono)["fecha"]);
    lzAbonoAA->Importe((const char *)(*lzSisRegAbono)["importe"]);
    zAbonos::Agrega(lzAbonoAA);
}
}
}

