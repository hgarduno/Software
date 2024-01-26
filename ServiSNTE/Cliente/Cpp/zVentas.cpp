#include <zVentas.h>
#include <zSiscomRegistros.h>
zVentas::zVentas()
{
}
zVentas::zVentas(zSiscomRegistro *pzSisRegRegreso)
{
  OrdenesVendidas(pzSisRegRegreso);
}
void zVentas::OrdenesVendidas(zSiscomRegistro *pzSisRegRegreso)
{
    zSisRegsVentas=pzSisRegRegreso->AsociadosDelCampo("VentasCliente"); 
    zSisRegCliente=pzSisRegRegreso->AsociadoDelCampo("Cliente");
    zSisRegVenta=zSisRegsVentas->Primer();
}

int zVentas::Siguiente()
{
    if((zSisRegVenta=zSisRegsVentas->Siguiente()))
     return 1;
     else
     return 0;
}
const char *zVentas::Importe()
{
    return (const char *)(*zSisRegVenta)["total"];
}
const char *zVentas::Folio()
{
    return (const char *)(*zSisRegVenta)["folio"];

}
const char *zVentas::Fecha()
{
    return (const char *)(*zSisRegVenta)["fecha"];

}
const char *zVentas::TipoVenta()
{
    return (const char *)(*zSisRegVenta)["nomtipoventa"];

}

const char *zVentas::Nombre()
{
    return (const char *)(*zSisRegCliente)["nombre"];

}

const char *zVentas::APaterno()
{
    return (const char *)(*zSisRegCliente)["apaterno"];

}
const char *zVentas::AMaterno()
{
    return (const char *)(*zSisRegCliente)["amaterno"];

}
const char *zVentas::Financiadora()
{
    return (const char *)(*zSisRegVenta)["financiadora"];
}
const char *zVentas::Plazo()
{
    return (const char *)(*zSisRegVenta)["plazo"];
}
const char *zVentas::Vencimiento()
{
    return (const char *)(*zSisRegVenta)["vencimiento"];
}
int zVentas::NoVentas()
{
   return zSisRegsVentas->NNodos();
}
