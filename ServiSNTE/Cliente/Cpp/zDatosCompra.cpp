#include <zDatosCompra.h>

zDatosCompra::zDatosCompra()
{

}

void zDatosCompra::IniciaDatos()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;

if((lzSisRegRegreso=Primer()))
{
  if((zSisRegsDatCompra=lzSisRegRegreso->AsociadosDelCampo("DatosCompra")))
    SiscomRegistrosLog(zSisRegsDatCompra); 
  if((zSisRegProveedor=lzSisRegRegreso->AsociadoDelCampo("Proveedor")))
    SiscomRegistroLog2(zSisRegProveedor);
  if((zSisRegsTelefonos=lzSisRegRegreso->AsociadosDelCampo("Telefonos")))
    SiscomRegistrosLog(zSisRegsTelefonos); 
}

}
zSiscomRegistro *zDatosCompra::Proveedor()
{
  return zSisRegProveedor;
}
zSiscomRegistros *zDatosCompra::Productos()
{
   return zSisRegsDatCompra;
}


zSiscomRegistros *zDatosCompra::Telefonos()
{
 return zSisRegsTelefonos;
}

