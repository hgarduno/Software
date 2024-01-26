#include <QtImprimeSoporteCompras.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionSoporteCompras.h>
#include <zSoporteCompras.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeSoporteCompras::QtImprimeSoporteCompras(zSiscomConexion *pzSisConexion,
							 zImpresionSoporteCompras *pzImpSoporteCompras,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpSoporteCompras,
									pQWParent,
									pchrPtrName),
							zImpSoporteCompras(pzImpSoporteCompras),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeSoporteCompras::Imprimiendo()
{
Cabecera();
//Reporte();
}
void QtImprimeSoporteCompras::Reporte()
{
/*zSoporteCompras *lzSoporteCompras=zImpSoporteCompras->SoporteCompras();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProveedor);
int lintDesplazamientoY=0;
if(lzSoporteCompras->PrimerProveedor())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzSoporteCompras->Proveedor()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzSoporteCompras);
    lintDesplazamientoY=MuestraTotalProveedor(lintDesplazamientoY,
	   					     lzSisRegsProveedor,
						     lzSoporteCompras);
    lintDesplazamientoY+=2*intIncrementoY;
  }while(lzSoporteCompras->SiguienteProveedor());

}*/
}
/*int QtImprimeSoporteCompras::MuestraProductos(int pintDesplazamiento,
						  zSoporteCompras *pzSoporteCompras)
{
int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzSoporteCompras->PrimerProducto())
 {
	do
	{
	   if(SeAgregaALaLista(pzSoporteCompras))
	   {
	   if(Texto(lintDesplazamientoY,lzSisRegsProductos,pzSoporteCompras->Producto()))
	   {
		NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   }
	   lintDesplazamientoY+=intIncrementoY;
	   }
		
	}while(pzSoporteCompras->SiguienteProducto());

 }
return lintDesplazamientoY;
}
*/
/*int QtImprimeSoporteCompras::MuestraTotalProveedor(int pintDesplazamiento,
						   zSiscomRegistros *pzSisRegsPosiciones,	
						    zSoporteCompras *pzSoporteCompras)
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
	  pzSoporteCompras->TotalProveedor());
return lintDesplazamientoY+intIncrementoY;
}*/
void QtImprimeSoporteCompras::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesSoporteCompras");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionSoporteCompras();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeSoporteCompras::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpSoporteCompras);

}

/*int QtImprimeSoporteCompras::SeAgregaALaLista(zSoporteCompras *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}*/
