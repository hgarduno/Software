#ifndef __QTSISIMPRIMEFACTURAPRODUCTOS_H__
#define __QTSISIMPRIMEFACTURAPRODUCTOS_H__

#include <QtSisImprimeFactura.h>

class QPainter;
class SiscomRegistro3;

class QtSisImprimeFacturaProductos
{

public:
	QtSisImprimeFacturaProductos(QtSisImprimeFactura *pQtSisImpFac);
	void Productos(SiscomRegistro3Lst *pSisReg3LstProductos);
	SiscomRegistro3 *DibujaProductos(
			     SiscomRegistro3 *pSisReg3Producto, 
			     int pintXmm,
			     int pintYmm,
			     int pintX1mm,
			     int pintY1mm,
			     QPainter *pQPDibuja);
	void DibujaCantidad(
			    SiscomRegistro3 *pSisReg3Producto,
			    int pintXmm,
			    int pintYmm,
			    int pintX1mm,
			    int pintY1mm,
			    QPainter *pQPDibuja);
	void DibujaProducto(SiscomRegistro3 *pSisReg3Producto,
			    int pintXmm,
			    int pintYmm,
			    int pintX1mm,
			    int pintY1mm,
			    QPainter *pQPDibuja);
	void DibujaPrecio(
			    SiscomRegistro3 *pSisReg3Producto,
			int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);
	void DibujaImporte(
			    SiscomRegistro3 *pSisReg3Producto,
			int pintXmm,
			   int pintYmm,
			   int pintX1mm,
			   int pintY1mm,
			   QPainter *pQPDibuja);
	void DibujaSubTotal(SiscomRegistro3 *pSisReg3Totales,
			int pintXmm,
			    int pintYmm,
			    int pintX1mm,
			    int pintY1mm,
			    QPainter *pQPDibuja);
	void DibujaIVA(SiscomRegistro3 *pSisReg3Totales,
			int pintXmm,
		       int pintYmm,
		       int pintX1mm,
		       int pintY1mm,
		       QPainter *pQPDibuja);
	void DibujaTotal(SiscomRegistro3 *pSisReg3Totales,
			int pintXmm,
			 int pintYmm,
			 int pintX1mm,
			 int pintY1mm,
			 QPainter *pQPDibuja);
	void DibujaImporteConLetra(SiscomRegistro3 *pSisReg3Totales,
			 int pintXmm,
			 int pintYmm,
			 int pintX1mm,
			 int pintY1mm,
			 QPainter *pQPDibuja);
private:
	QtSisImprimeFactura *QtSisImpFactura;
	SiscomRegistro3Lst *SisReg3LstProductos;
};
#endif
