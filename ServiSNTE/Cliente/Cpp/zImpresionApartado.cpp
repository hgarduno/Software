#include <zImpresionApartado.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <zReciboApartado.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

zImpresionApartado::zImpresionApartado()
{


}

void zImpresionApartado::Tienda(zSiscomRegistro *pzSisRegTienda)
{
  zSisRegTienda=pzSisRegTienda;
}

void zImpresionApartado::Cliente(zSiscomRegistro *pzSisRegCliente)
{
	zSisRegCliente=pzSisRegCliente;
}
void zImpresionApartado::Venta(zSiscomRegistro *pzSisRegVenta)
{
    zSisRegVenta=pzSisRegVenta;
}
void zImpresionApartado::Recibo(zReciboApartado *pzRecibo)
{
  zRecibo=pzRecibo;
}
const char *zImpresionApartado::Dato(const char *pchrPtrCampo)
{
     if(!strcmp("Fecha",pchrPtrCampo))
     return (const char *)(*zRecibo)["Fecha"];
     else
     if(!strcmp("Folio",pchrPtrCampo))
     return (const char *)(*zSisRegVenta)["folio"];
     else
     if(!strcmp("Tienda",pchrPtrCampo))
     return (const char *)(*zSisRegTienda)["nombre"];
     else
     if(!strcmp("ApartadoFactura",pchrPtrCampo))
     return "Apartado Factura";
     else
     if(!strcmp("Cliente",pchrPtrCampo))
     return Cliente();
     else
     if(!strcmp("Importe",pchrPtrCampo))
     return (const char *)(*zRecibo)["Importe"];
     else
     if(!strcmp("ImporteLetra",pchrPtrCampo))
     return ImporteLetra();
     else
     if(!strcmp("Concepto",pchrPtrCampo))
     return "Abono a apartado";
     else
     if(!strcmp("Elaboro",pchrPtrCampo))
     return (const char *)(*zSisRegVenta)["nombrevendedor"];
     else
     if(!strcmp("FolioApartado",pchrPtrCampo))
     return (const char *)(*zRecibo)["FolioApartado"];
    else 
     return "Nada";
}
const char *zImpresionApartado::Cliente()
{
char lchrArrCliente[128];
sprintf(lchrArrCliente,
	"%s %s %s",
	(*zSisRegCliente)["nombre"],
	(*zSisRegCliente)["apaterno"],
	(*zSisRegCliente)["amaterno"]);
return strdup(lchrArrCliente);
}
const char *zImpresionApartado::ImporteLetra()
{
float lfltAbono=atof((const char *)(*zRecibo)["Importe"]);
char *lchrPtrImporteLetra;
zSiscomQt3::SiscomALetra(lfltAbono,&lchrPtrImporteLetra);
return (const char *)lchrPtrImporteLetra;
}
