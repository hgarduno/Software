#include <zBodegas.h>
#include <zBodega.h>
#include <zSiscomDesarrollo4.h>
zBodegas::zBodegas()
{

}
void zBodegas::Agrega(zBodega *pzBodega)
{
	(*this) << pzBodega;     
}
void zBodegas::BodegasExpendios(zSiscomRegistros *pzSisRegsBoExps)
{
zSiscomRegistro *lzSisRegBodega;
zBodega *lzBodega;
for(lzSisRegBodega=pzSisRegsBoExps->Primer();
    lzSisRegBodega;
    lzSisRegBodega=pzSisRegsBoExps->Siguiente())
    Agrega(new zBodega(lzSisRegBodega));
}

void zBodegas::ObtenBodegasExpendios(zSiscomRegistros *pzSisRegsBoExps)
{
  BodegasExpendios(pzSisRegsBoExps);
}
