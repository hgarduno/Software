#include <QtImprimeRepStockProveedorCosto.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionStockProveedorCosto.h>
#include <zStockProveedorCosto.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepStockProveedorCosto::QtImprimeRepStockProveedorCosto(zSiscomConexion *pzSisConexion,
							 zImpresionStockProveedorCosto *pzImpStockProveedorCosto,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpStockProveedorCosto,
									pQWParent,
									pchrPtrName),
							zImpStockProveedorCosto(pzImpStockProveedorCosto),
							intIncrementoY(13)
{
ConsultaPosiciones();

}
void QtImprimeRepStockProveedorCosto::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepStockProveedorCosto::Reporte()
{
zStockProveedorCosto *lzStkProveedorCosto;
lzStkProveedorCosto=zImpStockProveedorCosto->StockProveedorCosto();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[9];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
int lintDesplazamientoY=0;
SiscomRegistrosLog(lzSisRegsProveedor);
if(lzStkProveedorCosto->PrimerProducto())
{
AgregaColumnasTiendas(lzStkProveedorCosto);
do
{
   if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzStkProveedorCosto->Producto()))
   {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
   }
   MuestraStockTienda(lintDesplazamientoY,lzStkProveedorCosto);
   lintDesplazamientoY+=intIncrementoY;

}while(lzStkProveedorCosto->SiguienteProducto());
}
}
int QtImprimeRepStockProveedorCosto::AgregaColumnasTiendas(zStockProveedorCosto *pzStockProveedorCosto)
{
int lintDesplazamiento=5;
if(pzStockProveedorCosto->PrimerTienda())
{
	do
	{
		Texto(95+lintDesplazamiento,15,10,30,pzStockProveedorCosto->Siglas());
		lintDesplazamiento+=10;
	}while(pzStockProveedorCosto->SiguienteTienda());
}
}
int QtImprimeRepStockProveedorCosto::MuestraStockTienda(int pintDesplazamiento,
						  zStockProveedorCosto *pzStockProveedorCosto)
{
zSiscomRegistro *lzSisRegTienda=(*zSisRegsPosiciones)[9];
zSiscomRegistros *lzSisRegsTiendas=lzSisRegTienda->AsociadosDelCampo("registrocampo");
int lintDesplazamientoX=0;
  if(pzStockProveedorCosto->PrimerTienda())
  {
	do
	{
	  TextoXY(lintDesplazamientoX,pintDesplazamiento,lzSisRegsTiendas,pzStockProveedorCosto->Tienda());
	  lintDesplazamientoX+=10;
	}while(pzStockProveedorCosto->SiguienteTienda());

  }
  
}
void QtImprimeRepStockProveedorCosto::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesStockProveedorCosto");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionStockProveedorCosto();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeRepStockProveedorCosto::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpStockProveedorCosto);

}

