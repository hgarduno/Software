#include <QtImprimeSoporteVentas.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionSoporteVentas.h>
#include <zSoporteVentas.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeSoporteVentas::QtImprimeSoporteVentas(zSiscomConexion *pzSisConexion,
							 zImpresionSoporteVentas *pzImpSoporteVentas,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpSoporteVentas,
									pQWParent,
									pchrPtrName),
							zImpSoporteVentas(pzImpSoporteVentas),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeSoporteVentas::Imprimiendo()
{
Cabecera();
//Reporte();
}
void QtImprimeSoporteVentas::Reporte()
{
/*zSoporteVentas *lzSoporteVentas=zImpSoporteVentas->SoporteVentas();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProveedor);
int lintDesplazamientoY=0;
if(lzSoporteVentas->PrimerProveedor())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzSoporteVentas->Proveedor()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzSoporteVentas);
    lintDesplazamientoY=MuestraTotalProveedor(lintDesplazamientoY,
	   					     lzSisRegsProveedor,
						     lzSoporteVentas);
    lintDesplazamientoY+=2*intIncrementoY;
  }while(lzSoporteVentas->SiguienteProveedor());

}*/
}
/*int QtImprimeSoporteVentas::MuestraProductos(int pintDesplazamiento,
						  zSoporteVentas *pzSoporteVentas)
{
int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzSoporteVentas->PrimerProducto())
 {
	do
	{
	   if(SeAgregaALaLista(pzSoporteVentas))
	   {
	   if(Texto(lintDesplazamientoY,lzSisRegsProductos,pzSoporteVentas->Producto()))
	   {
		NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   }
	   lintDesplazamientoY+=intIncrementoY;
	   }
		
	}while(pzSoporteVentas->SiguienteProducto());

 }
return lintDesplazamientoY;
}
*/
/*int QtImprimeSoporteVentas::MuestraTotalProveedor(int pintDesplazamiento,
						   zSiscomRegistros *pzSisRegsPosiciones,	
						    zSoporteVentas *pzSoporteVentas)
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
	  pzSoporteVentas->TotalProveedor());
return lintDesplazamientoY+intIncrementoY;
}*/
void QtImprimeSoporteVentas::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesSoporteVentas");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionSoporteVentas();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeSoporteVentas::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpSoporteVentas);

}

/*int QtImprimeSoporteVentas::SeAgregaALaLista(zSoporteVentas *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}*/
