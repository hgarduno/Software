#include <QtSisImprimeFactura.h>
#include <QtSisImprimeFacturaCliente.h>
#include <QtSisImprimeFacturaFecha.h>
#include <QtSisImprimeFacturaProductos.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpaintdevicemetrics.h>
#include <qpainter.h>
#include <qprinter.h>
QtSisImprimeFactura::QtSisImprimeFactura(SiscomRegistro3 *pSisReg3Cliente,
					 SiscomRegistro3Lst *pSisReg3LstProductos,
					 QWidget *pQWParent,
					 const char *pchrPtrName):
				QScrollView(pQWParent,pchrPtrName),
				intYaMedidasDispositivo(0),
				SisReg3Cliente(pSisReg3Cliente),
				SisReg3LstProductos(pSisReg3LstProductos),
				intTamYmmPagina(208)
{
setResizePolicy(Default);
resizeContents(1920,4000);
viewport()->setBackgroundMode( PaletteBase );
setVScrollBarMode(QScrollView::AlwaysOn);
}
void QtSisImprimeFactura::drawContents(QPainter *pQPDibuja,
				       int,
				       int,
				       int,
				       int)
{
	MedidasDispositivo(pQPDibuja);
	Dibujando(pQPDibuja);

}
void QtSisImprimeFactura::Dibujando(QPainter *pQPDibuja)
{
	Dibujando(pQPDibuja,0);
}
/*
 * La impresora inicia es escritura a 12 mm de la hoja y 12 mm
 *
 */
void QtSisImprimeFactura::Dibujando(QPainter *pQPDibuja,
				    QPrinter *pQPImpresora)
{
SiscomRegistro3 *lSisReg3Producto=SisReg3LstProductos->first();
int lintPagina=0;
int lintHoja=0;
     while(lSisReg3Producto)
     {
     DibujaDatosCliente(lintPagina,lintHoja,pQPDibuja);
     DibujaFecha(lintPagina,lintHoja,pQPDibuja);
     lSisReg3Producto=DibujaProductos(lintPagina,
     		     lintHoja,
     		     lSisReg3Producto,
     		     pQPDibuja,
		     pQPImpresora);
     if(pQPImpresora  &&
        lSisReg3Producto)
     pQPImpresora->newPage();
     if(!pQPImpresora &&
        lSisReg3Producto)
     lintPagina++;
     lintHoja++;
     }
     DibujaTotales(lintPagina,lintHoja,pQPDibuja);
}

void QtSisImprimeFactura::DibujaDatosCliente(int pintPagina,
					     int pintHoja,
					     QPainter *pQPDibuja)
{

	QtSisImpFacCliente->DibujaNombre(
				13,
				32+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				130,
				110+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
	QtSisImpFacCliente->DibujaCalle(
				13,
				41+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				130,
				110+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
	QtSisImpFacCliente->DibujaColoniaCP(
				13,
				43+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				130,
				110+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
	QtSisImpFacCliente->DibujaMunicipioEstado(
				13,
				47+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				130,
				110+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
	QtSisImpFacCliente->DibujaRFC(
				23,
				54+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				130,
				110+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
	QtSisImpFacCliente->DibujaTelefono(
				75,
				54+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				130,
				110+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
}
void QtSisImprimeFactura::DibujaFecha(int pintPagina,
				int pintHoja,
				QPainter *pQPDibuja)
{
QtSisImpFacFecha->DibujaDia(109,
			    47+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
			    109,
			    47+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
			    pQPDibuja);
QtSisImpFacFecha->DibujaMes(117,
			    47+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
			    109,
			    47+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
			    pQPDibuja);
QtSisImpFacFecha->DibujaA_o(127,
			    47+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
			    109,
			    47+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
			    pQPDibuja);
}
SiscomRegistro3 *QtSisImprimeFactura::DibujaProductos(int pintPagina,
						      int pintHoja,
						      SiscomRegistro3 *pSisReg3Producto,
						      QPainter *pQPDibuja,
					              QPrinter *pQPImpresora)
{
     return QtSisImpFacProductos->DibujaProductos(
     				pSisReg3Producto,
     				13,
     				64+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				134,
				152+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
     				pQPDibuja); 
}
void QtSisImprimeFactura::DibujaTotales(int pintPagina,
					int pintHoja,
					QPainter *pQPDibuja)
{
SiscomRegistro3 *lSisReg3Totales=(*SisReg3LstProductos)[0];
	QtSisImpFacProductos->DibujaSubTotal(
				lSisReg3Totales,
				105,
				165+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				105,
				165+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);

	
	QtSisImpFacProductos->DibujaIVA(
				lSisReg3Totales,
				105,
				171+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				105,
				171+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
	QtSisImpFacProductos->DibujaTotal(
				lSisReg3Totales,
				105,
				176+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				105,
				176+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
	QtSisImpFacProductos->DibujaImporteConLetra(
				lSisReg3Totales,
				13,
				155+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				133,
				164+DesplazamientoYmmPorPagina(pintPagina,pintHoja),
				pQPDibuja);
}
void QtSisImprimeFactura::MedidasDispositivo(QPainter *pQPDDibuja)
{

if(!intYaMedidasDispositivo)
{
	QPDMMedidas=new QPaintDeviceMetrics(pQPDDibuja->device());
	QtSisImpFacCliente=new QtSisImprimeFacturaCliente(this);
	QtSisImpFacFecha=new QtSisImprimeFacturaFecha(this);
	QtSisImpFacProductos=new QtSisImprimeFacturaProductos(this);
	QtSisImpFacProductos->Productos(SisReg3LstProductos);
	PosicionCliente();
	QtSisImpFacCliente->Cliente(SisReg3Cliente);
	intYaMedidasDispositivo=0;
}
}
void QtSisImprimeFactura::PosicionCliente()
{
	QtSisImpFacCliente->PuntoInicio(30,30);
	QtSisImpFacCliente->PuntoFin(50,110);
}
int QtSisImprimeFactura::PixelesAMM(int pintPixeles)
{
   return pintPixeles/MMAPixeles(1);
}
int QtSisImprimeFactura::MMAPixeles(int pintMilimetros)
{
return (int )((pintMilimetros/25.4)*QPDMMedidas->logicalDpiX());
}
int QtSisImprimeFactura::DesplazamientoYmmPorPagina(int pintPagina,
						    int pintHoja)
{
int lintAjusteYmm=0;
  if(pintHoja)
   lintAjusteYmm=6;
  return (pintPagina*intTamYmmPagina)-lintAjusteYmm;
}
