#include <zDevolucion.h>
#include <zSiscomCampo.h>
zDevolucion::zDevolucion()
{
  (*this) << 
  new zSiscomCampo("IdVenta") <<
  new zSiscomCampo("Productos");
}

void zDevolucion::IdVenta(const char *pchrPtrIdVenta)
{
   ActualizaCampo("IdVenta",(const unsigned char *)pchrPtrIdVenta);
}

void zDevolucion::Productos(zSiscomRegistros *pzSisRegsProductos)
{
  AsociadosAlCampo("Productos",pzSisRegsProductos);
}
