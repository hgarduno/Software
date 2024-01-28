#include <zGastos.h>
#include <zGasto.h>
zGastos::zGastos()
{

}
zGastos &zGastos::operator<<(zGasto *pzGasto)
{
   Agrega(pzGasto);
   return *this;
}
