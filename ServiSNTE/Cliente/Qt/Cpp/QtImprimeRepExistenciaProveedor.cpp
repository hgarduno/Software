#include <QtImprimeRepExistenciaProveedor.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionExistenciaProveedor.h>
#include <zExistenciaProveedor.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepExistenciaProveedor::QtImprimeRepExistenciaProveedor(zSiscomConexion *pzSisConexion,
							 zImpresionExistenciaProveedor *pzImpExistenciaProveedor,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpExistenciaProveedor,
									pQWParent,
									pchrPtrName),
							zImpExistenciaProveedor(pzImpExistenciaProveedor),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeRepExistenciaProveedor::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepExistenciaProveedor::Empresa()
{
zSiscomRegistro *lzSisRegProveedor=zImpExistenciaProveedor->ExistenciaProveedor()->Proveedor(); 
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[11];
zSiscomRegistros *lzSisRegsProducto=lzSisRegProducto->AsociadosDelCampo("registrocampo");
Texto(0,lzSisRegsProducto,lzSisRegProveedor);
}
void QtImprimeRepExistenciaProveedor::Reporte()
{
zExistenciaProveedor *lzExistenciaProveedor=zImpExistenciaProveedor->ExistenciaProveedor();
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[12];
zSiscomRegistros *lzSisRegsProducto=lzSisRegProducto->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProducto);
int lintDesplazamientoY=0;
Empresa();
lintDesplazamientoY+=intIncrementoY;
if(lzExistenciaProveedor->PrimerProducto())
{
 
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProducto,lzExistenciaProveedor->Producto()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraExistenciaTiendas(lintDesplazamientoY,lzExistenciaProveedor);
    lintDesplazamientoY=MuestraTotalExistencia(lintDesplazamientoY,lzExistenciaProveedor);
    lintDesplazamientoY+=intIncrementoY;

  }while(lzExistenciaProveedor->SiguienteProducto());

}
}
int QtImprimeRepExistenciaProveedor::MuestraTotalExistencia(int pintDesplazamientoY,
							    zExistenciaProveedor *pzExProveedor)
{
int lintDesplazamientoY=pintDesplazamientoY;
zSiscomRegistro *lzSisRegProducto;
zSiscomRegistros *lzSisRegsProducto;
lzSisRegProducto=(*zSisRegsPosiciones)[13];
lzSisRegsProducto=lzSisRegProducto->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProducto);
Texto(lintDesplazamientoY,
	lzSisRegsProducto,
	"campo",
	"stock",
	pzExProveedor->TotalStock());

Texto(lintDesplazamientoY,
	lzSisRegsProducto,
	"campo",
	"existencia",
	pzExProveedor->TotalExistencia());
return lintDesplazamientoY+intIncrementoY;
}
int QtImprimeRepExistenciaProveedor::MuestraExistenciaTiendas(int pintDesplazamiento,
						  zExistenciaProveedor *pzExistenciaProveedor)
{

int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzExistenciaProveedor->PrimerTienda())
 {
	do
	{
	   if(Texto(lintDesplazamientoY,lzSisRegsProductos,pzExistenciaProveedor->Tienda()))
	   {
	 	NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   }
	   lintDesplazamientoY+=intIncrementoY;
	   	
	}while(pzExistenciaProveedor->SiguienteTienda());
 }
return lintDesplazamientoY;
}
void QtImprimeRepExistenciaProveedor::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesExistenciaProveedor");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionExistenciaProveedor();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeRepExistenciaProveedor::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpExistenciaProveedor);

}
