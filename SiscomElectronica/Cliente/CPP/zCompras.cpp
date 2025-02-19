#include <zCompras.h>
#include <zCompra.h>

zCompras::zCompras()
{

}

void zCompras::Compras(zSiscomRegistros *pzSisRegsCompras)
{
zCompra *lzCompra;
zSiscomRegistro *lzSisRegCompra;

for(lzSisRegCompra=pzSisRegsCompras->Primer();
    lzSisRegCompra;
    lzSisRegCompra=pzSisRegsCompras->Siguiente())
    (*this) << new zCompra(lzSisRegCompra); 
}
