#include <zOrdenesFavoritas.h>
#include <zOrdenFavorita.h>
#include <zSiscomDesarrollo4.h>
zOrdenesFavoritas::zOrdenesFavoritas()
{


}

void zOrdenesFavoritas::OrdenesFavoritas(zSiscomRegistros *pzSisRegsOrdsFavoritas)
{
zSiscomRegistro *lzSisRegOrdenFavorita;
zOrdenFavorita *lzOrdFavorita;
for(lzSisRegOrdenFavorita=pzSisRegsOrdsFavoritas->Primer();
    lzSisRegOrdenFavorita;
    lzSisRegOrdenFavorita=pzSisRegsOrdsFavoritas->Siguiente())
{
  lzOrdFavorita=new zOrdenFavorita;
  lzOrdFavorita->IdOrden((const char *)(*lzSisRegOrdenFavorita)["idventa"]);
  lzOrdFavorita->Texto((const char *)(*lzSisRegOrdenFavorita)["texto"]);
   Agrega(lzOrdFavorita);
}

}
zOrdenesFavoritas &zOrdenesFavoritas::operator<<(zOrdenFavorita *pzOFavorita)
{
   Agrega(pzOFavorita);
   return *this;
}
