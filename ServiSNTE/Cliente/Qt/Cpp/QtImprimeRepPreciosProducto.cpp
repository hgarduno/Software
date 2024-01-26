#include <QtImprimeRepPreciosProducto.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionListaPrecios.h>
#include <zListaPrecios.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepPreciosProducto::QtImprimeRepPreciosProducto(zSiscomConexion *pzSisConexion,
							 zImpresionListaPrecios *pzImpListaPrecios,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpListaPrecios,
									pQWParent,
									pchrPtrName),
							zImpListaPrecios(pzImpListaPrecios),
							intIncrementoY(4)
{
ConsultaPosiciones();
}
void QtImprimeRepPreciosProducto::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepPreciosProducto::Reporte()
{
zListaPrecios *lzLstPrecios=zImpListaPrecios->ListaPrecios();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[10];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
int lintDesplazamientoY=0;
int lintPaginas=0;
int lintDesplazamientoPaginaY=0;
SiscomRegistrosLog(lzSisRegsProveedor);
if(lzLstPrecios->PrimerDepartamento())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzLstPrecios->Departamento()))
    {
    NumeroPagina(&lintDesplazamientoY);
    lintDesplazamientoY=0;
    lintDesplazamientoPaginaY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzLstPrecios);
    lintDesplazamientoY+=2*intIncrementoY;
    lintDesplazamientoPaginaY+=2*intIncrementoY;
  }while(lzLstPrecios->SiguienteDepartamento());
}
}
int QtImprimeRepPreciosProducto::MuestraProductos(int pintDesplazamiento,
						  zListaPrecios *pzLstPrecios)
{
int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[11];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");

 if(pzLstPrecios->PrimerProducto())
 {
	do
	{
	   if(SeAgregaALaLista(pzLstPrecios))
	   {
	   if(Texto(lintDesplazamientoY,lzSisRegsProductos,pzLstPrecios->Producto()))
	   {
	    NumeroPagina(&lintDesplazamientoY);
	    lintDesplazamientoY=-intIncrementoY;
	   }
	   lintDesplazamientoY+=intIncrementoY;
	   }
	}while(pzLstPrecios->SiguienteProducto());

 }
return lintDesplazamientoY;

}
void QtImprimeRepPreciosProducto::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesListaPrecios");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionListaPrecios();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeRepPreciosProducto::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;
LogSiscom("Imprimiendo %s",Nombre());
for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpListaPrecios);

}

int QtImprimeRepPreciosProducto::SeAgregaALaLista(zListaPrecios *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}
