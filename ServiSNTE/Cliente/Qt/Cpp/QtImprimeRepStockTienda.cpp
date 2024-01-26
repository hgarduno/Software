#include <QtImprimeRepStockTienda.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionStockTienda.h>
#include <zStockTienda.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepStockTienda::QtImprimeRepStockTienda(zSiscomConexion *pzSisConexion,
							 zImpresionStockTienda *pzImpStockTienda,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpStockTienda,
									pQWParent,
									pchrPtrName),
							zImpStockTienda(pzImpStockTienda),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeRepStockTienda::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepStockTienda::Reporte()
{
zStockTienda *lzStockTienda=zImpStockTienda->StockTienda();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProveedor);
int lintDesplazamientoY=0;
if(lzStockTienda->PrimerProveedor())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzStockTienda->Proveedor()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzStockTienda);
    lintDesplazamientoY+=2*intIncrementoY;
  }while(lzStockTienda->SiguienteProveedor());

}
}
int QtImprimeRepStockTienda::SeImprimeElCampo(zSiscomRegistro *pzSisRegPosicion)
{
   if(pzSisRegPosicion->EsElValorCampo("campo","preciogeneral"))
   	  return zImpStockTienda->ImprimePrecio();
    if(pzSisRegPosicion->EsElValorCampo("campo","importeventa"))
         return zImpStockTienda->ImprimeImporteVenta();
    else
    return 1;

}
int QtImprimeRepStockTienda::Producto(int pintDesplazamiento,
				       zSiscomRegistros *pzSisRegsCampos,
				       zSiscomRegistro *pzSisRegProducto)
{
zSiscomRegistro *lzSisRegPosicion;
int lintRegreso;
for(lzSisRegPosicion=pzSisRegsCampos->Primer();
    lzSisRegPosicion;
    lzSisRegPosicion=pzSisRegsCampos->Siguiente())
   if(SeImprimeElCampo(lzSisRegPosicion))
   lintRegreso=Texto(lzSisRegPosicion->CampoInt("x"),
    		     lzSisRegPosicion->CampoInt("y")+pintDesplazamiento,
		     lzSisRegPosicion->CampoInt("anchox"),
		     lzSisRegPosicion->CampoInt("anchoy"),
		     (const char *)(*pzSisRegProducto)[(const char *)lzSisRegPosicion->Campo("campo")]);

return lintRegreso;
}
int QtImprimeRepStockTienda::MuestraProductos(int pintDesplazamiento,
						  zStockTienda *pzStockTienda)
{
int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[14];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzStockTienda->PrimerProducto())
 {
	do
	{
	   if(SeAgregaALaLista(pzStockTienda))
	   {
	   if(Producto(lintDesplazamientoY,lzSisRegsProductos,pzStockTienda->Producto()))
	   {
		NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   } 
	   lintDesplazamientoY+=intIncrementoY;
	   }
		
	}while(pzStockTienda->SiguienteProducto());

 }
 lintDesplazamientoY=MuestraTotalProveedor(lintDesplazamientoY,lzSisRegsProductos,pzStockTienda);
return lintDesplazamientoY;
}
int QtImprimeRepStockTienda::MuestraTotalProveedor(int pintDesplazamiento,
						   zSiscomRegistros *pzSisRegsPosiciones,	
						    zStockTienda *pzStockTienda)
{
int lintDesplazamientoY=pintDesplazamiento;
    Texto(lintDesplazamientoY,
    	  pzSisRegsPosiciones,
	  "campo",
	  "stock",
	  "Total Proveedor");

    Texto(lintDesplazamientoY,
    	  pzSisRegsPosiciones,
	  "campo",
	  "importecosto",
	  pzStockTienda->TotalProveedor());
return lintDesplazamientoY+intIncrementoY;
}
void QtImprimeRepStockTienda::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesStockTienda");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionStockTienda();
}
void QtImprimeRepStockTienda::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpStockTienda);

}

int QtImprimeRepStockTienda::SeAgregaALaLista(zStockTienda *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}
