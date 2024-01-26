#include <zImpresionTransferencia.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zTransferencia.h>
#include <zProductos.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

zImpresionTransferencia::zImpresionTransferencia()
{
}
void zImpresionTransferencia::Transferencia(zTransferencia *pzTransferencia)
{
	zTranDat=pzTransferencia;
}
const char *zImpresionTransferencia::Dato(const char *pchrPtrCampo)
{
   if(!strcmp("TiendaOrigen",pchrPtrCampo))
   return TiendaOrigen();
   else
   if(!strcmp("TiendaDestino",pchrPtrCampo))
   return TiendaDestino();
   else
   if(!strcmp("Dia",pchrPtrCampo))
   return zTranDat->Dia();
   else
   if(!strcmp("Mes",pchrPtrCampo))
   return zTranDat->Mes();
   if(!strcmp("Anio",pchrPtrCampo))
   return zTranDat->Anio();
   else
   if(!strcmp("Chofer",pchrPtrCampo))
   return zTranDat->Chofer();
   else
   if(!strcmp("Camion",pchrPtrCampo))
   return zTranDat->Camion();
   else
   if(!strcmp("Placas",pchrPtrCampo))
   return zTranDat->Placas();
   else
   if(!strcmp("TransferenciaA",pchrPtrCampo))
   return "3205 - TRANSFERENCIA A TIENDAS";
   else
   return "";

}


void zImpresionTransferencia::PrimerProducto()
{
 zSisRegProducto=zTranDat->Productos()->Primer();
 SiscomRegistroLog2(zSisRegProducto);
}
int zImpresionTransferencia::SiguienteProducto()
{
 if((zSisRegProducto=zTranDat->Productos()->Siguiente()))
 {
 SiscomRegistroLog2(zSisRegProducto);
  return 1;
  }
  else
  return 0;
}
const char *zImpresionTransferencia::TiendaOrigen()
{
char lchrArrTienda[128];
sprintf(lchrArrTienda,
	"%s - %s",
	zTranDat->TiendaOrigen()->Campo("idtienda"),
	zTranDat->TiendaOrigen()->Campo("nombre"));
return strdup(lchrArrTienda);
}
const char *zImpresionTransferencia::TiendaDestino()
{
char lchrArrTienda[128];
sprintf(lchrArrTienda,
	"%s - %s",
	zTranDat->TiendaDestino()->Campo("idtienda"),
	zTranDat->TiendaDestino()->Campo("nombre"));
return strdup(lchrArrTienda);
}

const char *zImpresionTransferencia::CampoProducto(const char *pchrPtrCampo)
{
   if(!strcmp("Modelo",pchrPtrCampo))
   return (const char *)(*zSisRegProducto)["modelo"];
   else
   if(!strcmp("Descripcion",pchrPtrCampo))
   return (const char *)(*zSisRegProducto)["nombreproducto"];
   else
   if(!strcmp("Cantidad",pchrPtrCampo))
   return (const char *)(*zSisRegProducto)["Cantidad"];
   else
   if(!strcmp("PrecioVenta",pchrPtrCampo))
   return (const char *)(*zSisRegProducto)["Importe"];
   else
   return "";
}
