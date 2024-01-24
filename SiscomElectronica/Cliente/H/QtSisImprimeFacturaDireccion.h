#ifndef __QTSISIMPRIMEFACTURADIRECCION_H__
#define __QTSISIMPRIMEFACTURADIRECCION_H__

#include <QtSisImprimeFactura.h>

class QtSisImprimeFacturaDireccion
{
public:
	QtSisImprimeFacturaDireccion(QtSisImprimeFactura *pQtSisImpFac);


private:
	int intXmm;
	int intYmm;
	int intY1mm;
	int intX1mm;

	int intXpx;
	int intYpx;
	int intX1px;
	int intY1px;

	SiscomRegistro3 *SisReg3Cliente;

	QtSisImprimeFactura *QtSisImpFactura;

};

#endif
