#include <zPreciosExpendios.h>
#include <zPreciosExpendio.h>
#include <zEmpresa.h>
#include <string.h>
zPreciosExpendios::zPreciosExpendios()
{
 
}
void zPreciosExpendios::AgregaExpendio(zPreciosExpendio *pzPreciosE)
{
    (*this)  << pzPreciosE; 
}
zPreciosExpendio *zPreciosExpendios::Empresa(const char *pchrPtrIdExpendio)
{
zPreciosExpendio *lzPreciosExp;
for(lzPreciosExp=(zPreciosExpendio *)Primer();
    lzPreciosExp;
    lzPreciosExp=(zPreciosExpendio *)Siguiente())
{
    if(!strcmp(lzPreciosExp->Expendio()->IdEmpresa(),pchrPtrIdExpendio))
    return lzPreciosExp;
}
return 0;
}

zPreciosExpendio *zPreciosExpendios::Precios(const char *pchrPtrIdExpendio)
{
zPreciosExpendio *lzPresExp=Empresa(pchrPtrIdExpendio);
return lzPresExp;
}
void zPreciosExpendios::Precios(const char *pchrPtrIdExpendio,
					zSiscomRegistros *pzSisRegsProdsPrec)
{
zPreciosExpendio *lzPresExp=Empresa(pchrPtrIdExpendio);
  if(lzPresExp)
     lzPresExp->ProductosPrecio(pzSisRegsProdsPrec);
}
