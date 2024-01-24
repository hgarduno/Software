#include <QtSisImprimeFacturaProductos.h>
#include <QtSisPuntoImpresion.h>
#include <SiscomRegistros3.h>
#include <qpainter.h>

QtSisImprimeFacturaProductos::QtSisImprimeFacturaProductos(QtSisImprimeFactura *pQtSisImpFactura):
	QtSisImpFactura(pQtSisImpFactura)
{


}
void QtSisImprimeFacturaProductos::Productos(SiscomRegistro3Lst *pSisReg3LstProductos)
{
	SisReg3LstProductos=pSisReg3LstProductos;
}
SiscomRegistro3 *QtSisImprimeFacturaProductos::DibujaProductos(
						   SiscomRegistro3 *pSisReg3Producto,
						   int pintXmm,
						   int pintYmm,
						   int pintX1mm,
						   int pintY1mm,
						   QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
int lintYmm=pintYmm;
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "Productos",
				     "Productos",
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
SiscomRegistro3 *lSisReg3Producto;
for(lSisReg3Producto=pSisReg3Producto;
    (lSisReg3Producto && 
    lintYmm<pintY1mm);
    lSisReg3Producto=SisReg3LstProductos->next(),
    lintYmm+=3)
{
   DibujaCantidad(lSisReg3Producto,
   		  13,
   		  lintYmm,
		  pintXmm,
		  lintYmm,
		  pQPDibuja);

   DibujaProducto(lSisReg3Producto,
   		  25,
   		  lintYmm,
		  pintXmm,
		  lintYmm,
		  pQPDibuja);
   DibujaPrecio(lSisReg3Producto,
   		  104,
   		  lintYmm,
		  pintXmm,
		  lintYmm,
		  pQPDibuja);
   DibujaImporte(lSisReg3Producto,
   		  114,
   		  lintYmm,
		  pintXmm,
		  lintYmm,
		  pQPDibuja);
}
return lSisReg3Producto;
}

void QtSisImprimeFacturaProductos::DibujaCantidad(
					  SiscomRegistro3 *pSisReg3Producto,
					  int pintXmm,
					  int pintYmm,
					  int pintX1mm,
					  int pintY1mm,
					  QPainter *pQPDibuja)
{
QtSisPuntoImpresion lQtSisPtoImp(QtSisImpFactura,
				 "Productos",
				 "Productos",
				 pintXmm,
				 pintYmm,
				 pintX1mm,
				 pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp.Xpx(),
		     lQtSisPtoImp.Ypx(),
		     (*pSisReg3Producto)["cantidad"]);
}

void QtSisImprimeFacturaProductos::DibujaProducto(
					  SiscomRegistro3 *pSisReg3Producto,
					 int pintXmm,
					  int pintYmm,
					  int pintX1mm,
					  int pintY1mm,
					  QPainter *pQPDibuja)
{

QtSisPuntoImpresion lQtSisPtoImp(QtSisImpFactura,
				 "Productos",
				 "Productos",
				 pintXmm,
				 pintYmm,
				 pintX1mm,
				 pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp.Xpx(),
		     lQtSisPtoImp.Ypx(),
		     (*pSisReg3Producto)["cveproducto"]);

}
void QtSisImprimeFacturaProductos::DibujaPrecio(
					  SiscomRegistro3 *pSisReg3Producto,
					int pintXmm,
					  int pintYmm,
					  int pintX1mm,
					  int pintY1mm,
					  QPainter *pQPDibuja)
{

QtSisPuntoImpresion lQtSisPtoImp(QtSisImpFactura,
				 "Productos",
				 "Productos",
				 pintXmm,
				 pintYmm,
				 pintX1mm,
				 pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp.Xpx(),
		     lQtSisPtoImp.Ypx(),
		     (*pSisReg3Producto)["precio"]);

}

void QtSisImprimeFacturaProductos::DibujaImporte(
					  SiscomRegistro3 *pSisReg3Producto,
					int pintXmm,
					  int pintYmm,
					  int pintX1mm,
					  int pintY1mm,
					  QPainter *pQPDibuja)
{

QtSisPuntoImpresion lQtSisPtoImp(QtSisImpFactura,
				 "Productos",
				 "Productos",
				 pintXmm,
				 pintYmm,
				 pintX1mm,
				 pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp.Xpx(),
		     lQtSisPtoImp.Ypx(),
		     (*pSisReg3Producto)["importe"]);

}
void QtSisImprimeFacturaProductos::DibujaSubTotal(
						  SiscomRegistro3 *pSisReg3Totales,
					 	  int pintXmm,
						  int pintYmm,
						  int pintX1mm,
						  int pintY1mm,
						  QPainter *pQPDibuja)
{

QtSisPuntoImpresion lQtSisPtoImp(QtSisImpFactura,
				 "Productos",
				 "Productos",
				 pintXmm,
				 pintYmm,
				 pintX1mm,
				 pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp.Xpx(),
		     lQtSisPtoImp.Ypx(),
		     (*pSisReg3Totales)["Total"]);
}


void QtSisImprimeFacturaProductos::DibujaIVA(SiscomRegistro3 *pSisReg3Totales,
					int pintXmm,
						  int pintYmm,
						  int pintX1mm,
						  int pintY1mm,
						  QPainter *pQPDibuja)
{

QtSisPuntoImpresion lQtSisPtoImp(QtSisImpFactura,
				 "Productos",
				 "Productos",
				 pintXmm,
				 pintYmm,
				 pintX1mm,
				 pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp.Xpx(),
		     lQtSisPtoImp.Ypx(),
		     (*pSisReg3Totales)["IVA"]);
}
void QtSisImprimeFacturaProductos::DibujaTotal(SiscomRegistro3 *pSisReg3Totales,
						 int pintXmm,
						  int pintYmm,
						  int pintX1mm,
						  int pintY1mm,
						  QPainter *pQPDibuja)
{

QtSisPuntoImpresion lQtSisPtoImp(QtSisImpFactura,
				 "Productos",
				 "Productos",
				 pintXmm,
				 pintYmm,
				 pintX1mm,
				 pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp.Xpx(),
		     lQtSisPtoImp.Ypx(),
		     (*pSisReg3Totales)["TotalMIVA"]);

}


void QtSisImprimeFacturaProductos::DibujaImporteConLetra(
				SiscomRegistro3 *pSisReg3Totales,
				int pintXmm,
				int pintYmm,
				int pintX1mm,
				int pintY1mm,
				QPainter *pQPDibuja)
{

QtSisPuntoImpresion lQtSisPtoImp(QtSisImpFactura,
				 "Productos",
				 "Productos",
				 pintXmm,
				 pintYmm,
				 pintX1mm,
				 pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp.Xpx(),
		     lQtSisPtoImp.Ypx(),
		     (*pSisReg3Totales)["ImporteConLetra"]);

}
