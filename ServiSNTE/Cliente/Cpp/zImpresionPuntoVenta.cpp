#include <zImpresionPuntoVenta.h>
#include <zSiscomDesarrollo4.h>
#include <zOrden.h>
#include <zVenta.h>
#include <zProductos.h>
#include <string.h>
#include <stdlib.h>
zImpresionPuntoVenta::zImpresionPuntoVenta()
{


}
const char *zImpresionPuntoVenta::Dato(const char *pchrPtrCampo)
{
const char *lchrPtrCampo;
   if((lchrPtrCampo=(const char *)zOrdenV->Campo(pchrPtrCampo)))
    return lchrPtrCampo;
    else
    if((lchrPtrCampo=(const char *)zVentaV->Campo(pchrPtrCampo)))
    return lchrPtrCampo;
    else
    if(!strcmp(pchrPtrCampo,"Suma"))
    return (const char *)zOrdenV->Campo("Total");
    if(!strcmp(pchrPtrCampo,"NombreCompleto"))
    return NombreCompleto();
    if(!strcmp(pchrPtrCampo,"CalleNo"))
    return CalleNo();
    else
    if(!strcmp(pchrPtrCampo,"Tienda"))
    return zVentaV->SiglasTienda();
    else
    if(!strcmp(pchrPtrCampo,"Telefono"))
    return (const char *)zVentaV->Campo("Telefono");
    else
    if(!strcmp(pchrPtrCampo,"Contado"))
    return TipoVentaContado();
    else
    if(!strcmp(pchrPtrCampo,"Credito"))
    return TipoVentaCredito();
    else
    if(!strcmp(pchrPtrCampo,"Apartado"))
    return TipoVentaApartado();
    else
    if(!strcmp(pchrPtrCampo,"Autorizo"))
    return "";
    else
    if(!strcmp(pchrPtrCampo,"EntregaTienda"))
    return EntregaTienda();
    else
    if(!strcmp(pchrPtrCampo,"BodegaGeneral"))
    return EntregaBodegaGeneral();
    else
    if(!strcmp(pchrPtrCampo,"TransporteCliente"))
    return EntregaTransporteCliente();
    else
    if(!strcmp(pchrPtrCampo,"Compania"))
    return EntregaCompania();
    else
    if(!strcmp(pchrPtrCampo,"InstruccionEntrega"))
    return InstruccionEntrega();
    else
    if(!strcmp(pchrPtrCampo,"Plazo"))
    return Plazo(); 
    else
    if(!strcmp(pchrPtrCampo,"DesQuincenal"))
    return DescuentoQuincenal();
    else
    if(!strcmp(pchrPtrCampo,"PagoTotal"))
    return PagoTotal();
    else
    if(!strcmp(pchrPtrCampo,"FormaEntregar"))
    return FormaEntrega();
    else
    if(!strcmp(pchrPtrCampo,"DigitoAnio"))
    return DigitoAnio();
    else
    if(!strcmp(pchrPtrCampo,"RFC"))
    return (const char *)zVentaV->Campo("RFC");
    return "";
}
const char *zImpresionPuntoVenta::DigitoAnio()
{
const char *lchrPtrFecha;
if((lchrPtrFecha=(const char *)(*zVentaV)["Anio"]))
return lchrPtrFecha+3;
else
return "";
}
const char *zImpresionPuntoVenta::Plazo()
{
char lchrArrPlazo[128];
const char *lchrPtrPlazo;
	if((lchrPtrPlazo=CampoCredito("Plazo")))
	{
	  sprintf(lchrArrPlazo,"Plazo:%s",lchrPtrPlazo);
	  return strdup(lchrArrPlazo);
	}
	else
	return "";
}
const char *zImpresionPuntoVenta::DescuentoQuincenal()
{
char lchrArrDesQuincenal[128];
const char *lchrPtrDesQuincenal;
	if((lchrPtrDesQuincenal=CampoCredito("DesQuincenal")))
	{
	  sprintf(lchrArrDesQuincenal,"Descuento Quincenal:%s",lchrPtrDesQuincenal);
	  return strdup(lchrArrDesQuincenal);
	}
	else
	return "";
}
const char *zImpresionPuntoVenta::PagoTotal()
{
char lchrArrPagoTotal[128];
const char *lchrPtrPagoTotal;
	if((lchrPtrPagoTotal=CampoCredito("PagoTotal")))
	{
	  sprintf(lchrArrPagoTotal,"Pago Total:%s",lchrPtrPagoTotal);
	  return strdup(lchrArrPagoTotal);
	}
	else
	return "";
}
const char *zImpresionPuntoVenta::CampoCredito(const char *pchrPtrCampo)
{
zSiscomRegistro *lzSisRegCredito=zOrdenV->Credito();
if(lzSisRegCredito)
return (const char *)(*lzSisRegCredito)[pchrPtrCampo];
else
return 0;
}
const char *zImpresionPuntoVenta::TipoVentaContado()
{
int lintTipoVenta=atoi((const char *)(*zVentaV)["IdTipoVenta"]);
LogSiscom("El tipo de venta:%d",lintTipoVenta);
if(lintTipoVenta==1)
return "X";
else
return "";
}

const char *zImpresionPuntoVenta::TipoVentaCredito()
{
int lintTipoVenta=atoi((const char *)(*zVentaV)["IdTipoVenta"]);
LogSiscom("El tipo de venta:%d",lintTipoVenta);
if(lintTipoVenta==2)
return "X";
else
return "";
}
const char *zImpresionPuntoVenta::TipoVentaApartado()
{
int lintTipoVenta=atoi((const char *)(*zVentaV)["IdTipoVenta"]);
LogSiscom("El tipo de venta:%d",lintTipoVenta);
if(lintTipoVenta==3)
return "X";
else
return "";
}
const char *zImpresionPuntoVenta::NombreCompleto()
{
char lchrArrNombreCompleto[128];
sprintf(lchrArrNombreCompleto,
	"%s %s %s",
	(*zVentaV)["Nombre"],
	(*zVentaV)["APaterno"],
	(*zVentaV)["AMaterno"]);
return strdup(lchrArrNombreCompleto);
}
const char *zImpresionPuntoVenta::CalleNo()
{
char lchrArrCalleNo[256];
if((*zVentaV)["NumInterior"] &&
   (*zVentaV)["NumExterior"])
sprintf(lchrArrCalleNo,
	"%s No:%s Interior:%s",
	(*zVentaV)["Calle"],
	(*zVentaV)["NumExterior"],
	(*zVentaV)["NumInterior"]);
if((*zVentaV)["NumExterior"] &&
   !(*zVentaV)["NumInterior"])
sprintf(lchrArrCalleNo,
	"%s No:%s",
	(*zVentaV)["Calle"],
	(*zVentaV)["NumExterior"]);

return strdup(lchrArrCalleNo);
}
const char *zImpresionPuntoVenta::Referencias()
{
  return (const char *)(*zVentaV)["Referencias"];
}
void zImpresionPuntoVenta::Orden(zOrden *pzOrdenVenta)
{
	zOrdenV=pzOrdenVenta;
}

void zImpresionPuntoVenta::Venta(zVenta *pzVenta)
{
	zVentaV=pzVenta;
}
const char *zImpresionPuntoVenta::CampoProducto(const char *pchrPtrCampo)
{
    if(!strcmp(pchrPtrCampo,"Codigo"))
    return NumProductoModelo(zSisRegProducto);
    else
    if(!strcmp(pchrPtrCampo,"Cantidad"))
    return (const char *)(*zSisRegProducto)["Cantidad"];
    else
    if(!strcmp(pchrPtrCampo,"Descripcion"))
    return DescripcionProducto(zSisRegProducto);

    else
    if(!strcmp(pchrPtrCampo,"Precio"))
    return (const char *)(*zSisRegProducto)["preciogeneral"];
    else
    if(!strcmp(pchrPtrCampo,"Total"))
    return (const char *)(*zSisRegProducto)["Importe"];
    else
    return 0;
}
int zImpresionPuntoVenta::SiguienteProducto()
{
    if((zSisRegProducto=zOrdenV->Productos()->Siguiente())) 
    return 1;
    else
    return 0;
}
void zImpresionPuntoVenta::PrimerProducto()
{
     zSisRegProducto=zOrdenV->Productos()->Primer();
}

const char *zImpresionPuntoVenta::EntregaTienda()
{
int lintIdFormaEntrega=zVentaV->CampoAsociadoInt("FormaEntrega","idformaentrega");
LogSiscom("%d",lintIdFormaEntrega);
if(lintIdFormaEntrega==1)
return "X";
else
return "";
}
const char *zImpresionPuntoVenta::EntregaBodegaGeneral()
{
int lintIdFormaEntrega=zVentaV->CampoAsociadoInt("FormaEntrega","idformaentrega");
LogSiscom("%d",lintIdFormaEntrega);
if(lintIdFormaEntrega==2)
return "X";
else
return "";
}
const char *zImpresionPuntoVenta::EntregaTransporteCliente()
{
int lintIdFormaEntrega=zVentaV->CampoAsociadoInt("FormaEntrega","idformaentrega");
LogSiscom("%d",lintIdFormaEntrega);
if(lintIdFormaEntrega==3)
return "X";
else
return "";
}

const char *zImpresionPuntoVenta::EntregaCompania()
{
int lintIdFormaEntrega=zVentaV->CampoAsociadoInt("FormaEntrega","idformaentrega");
LogSiscom("%d",lintIdFormaEntrega);
if(lintIdFormaEntrega==4)
return "X";
else
return "";
}
const char *zImpresionPuntoVenta::FormaEntrega()
{
char lchrArrRegreso[128];
sprintf(lchrArrRegreso,
	"Inmediata-%s",
	(const char *)zVentaV->CampoAsociado("FormaEntrega","nombre"));
strdup(lchrArrRegreso);
}
const char *zImpresionPuntoVenta::InstruccionEntrega()
{
 const char *lchrPtrInstruccionEntrega;
 if((lchrPtrInstruccionEntrega=(const char *)(*zVentaV)["InstruccionesE"]))
 return lchrPtrInstruccionEntrega;
 else
 return "";
}

const char *zImpresionPuntoVenta::NumProductoModelo(zSiscomRegistro *pzSisRegProducto)
{
 char lchrArrRegreso[128];
 sprintf(lchrArrRegreso,
 	 "%s %s",
	 (*pzSisRegProducto)["idempresa"],
	 (*pzSisRegProducto)["numproducto"]);
return strdup(lchrArrRegreso);
}

const char *zImpresionPuntoVenta::DescripcionProducto(zSiscomRegistro *pzSisRegProducto)
{
 char lchrArrRegreso[128];
 int lintTamano;
 if(strlen((const char *)(*pzSisRegProducto)["nombreproducto"])>20)
 {
 strncpy(lchrArrRegreso,(const char *)(*pzSisRegProducto)["nombreproducto"],20);
 lchrArrRegreso[20]=0;
 strcat(lchrArrRegreso,"-");
 strcat(lchrArrRegreso,(const char *)(*pzSisRegProducto)["modelo"]);
 }
 else
 sprintf(lchrArrRegreso,
 	 "%s-%s",
	 (const char *)(*pzSisRegProducto)["nombreproducto"],
	 (const char *)(*pzSisRegProducto)["modelo"]);
return strdup(lchrArrRegreso);
}

