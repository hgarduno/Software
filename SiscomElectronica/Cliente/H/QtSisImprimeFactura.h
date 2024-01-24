#ifndef __QTSISIMPRIMEFACTURA_H__
#define __QTSISIMPRIMEFACTURA_H__

#include <qscrollview.h>

class QtSisImprimeFacturaCliente;
class QtSisImprimeFacturaFecha;
class QtSisImprimeFacturaProductos;
class SiscomRegistro3;
class SiscomRegistro3Lst;
class QPaintDeviceMetrics;
class QPrinter;
class QtSisImprimeFactura:public QScrollView
{
public:
	QtSisImprimeFactura(SiscomRegistro3 *pSisReg3Cliente,
			    SiscomRegistro3Lst *pSisReg3LstProductos,
			    QWidget *pQWParent,const char *pchrPtrName);
	virtual void PosicionCliente();
	int PixelesAMM(int pintPixeles);
	int MMAPixeles(int pintMilimetros);
	void Dibujando(QPainter *,QPrinter *);
private:
	void drawContents(QPainter *,int,int,int,int);
	void MedidasDispositivo(QPainter *);
	void Dibujando(QPainter *);
	void DibujaDatosCliente(int pintPagina,
				int pintHoja,
				QPainter *pQPDibuja);
	void DibujaFecha(int pintPagina,
			 int pintHoja,
			 QPainter *pQPDibuja);
	SiscomRegistro3 *DibujaProductos(int pintPagina,
					 int pintHoja,
					SiscomRegistro3 *pSisReg3Producto,
			     		QPainter *pQPDibuja,
					QPrinter *pQPImpresora);
	void DibujaTotales(int pintPagina,int pintHoja,QPainter *pQPDibuja);
	int DesplazamientoYmmPorPagina(int pintPagina,int pintHoja);
private:
	QtSisImprimeFacturaCliente *QtSisImpFacCliente;	
	QtSisImprimeFacturaFecha *QtSisImpFacFecha;
	QtSisImprimeFacturaProductos *QtSisImpFacProductos;
private:
	QPaintDeviceMetrics *QPDMMedidas;
	int intYaMedidasDispositivo;
	SiscomRegistro3 *SisReg3Cliente;
	SiscomRegistro3Lst *SisReg3LstProductos;
	int intTamYmmPagina;

};

#endif
