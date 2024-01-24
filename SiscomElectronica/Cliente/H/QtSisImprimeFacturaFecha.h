#ifndef __QTSISIMPRIMEFACTURAFECHA_H__
#define __QTSISIMPRIMEFACTURAFECHA_H__
#include <QtSisImprimeFactura.h>

class QPainter;
class QtSisImprimeFacturaFecha
{
public:
	QtSisImprimeFacturaFecha(QtSisImprimeFactura *);	
	void DibujaDia( int pintXmm,
		       int pintYmm,
		       int pintX1mm,
		       int pintY1mm,
		       QPainter *pQPDibuja);

	void DibujaMes(int pintXmm,
		       int pintYmm,
		       int pintX1mm,
		       int pintY1mm,
		       QPainter *pQPDibuja);
	void DibujaA_o(int pintXmm,
		       int pintYmm,
		       int pintX1mm,
		       int pintY1mm,
		       QPainter *pQPDibuja);
	void ObtenFechaHoy();
private:
	QtSisImprimeFactura *QtSisImpFactura;
	char chrArrDia[3];
	char chrArrMes[3];
	char chrArrA_o[5];
};
#endif
