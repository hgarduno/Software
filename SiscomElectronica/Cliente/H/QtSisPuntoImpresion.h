#ifndef __QTSISPUNTOIMPRESION_H__
#define __QTSISPUNTOIMPRESION_H__
#include <qptrlist.h>
class QtSisImprimeFactura;

class QtSisPuntoImpresion
{
public:
	QtSisPuntoImpresion(QtSisImprimeFactura *pQtSisImpFact,
			    const char *pchrPtrNombre,
			    const char *pchrPtrDato,
			    int pintXmm,
			    int pintYmm,
			    int pintX1mm,
			    int pintY1mm);

	int Xmm();
	int Ymm();
	int X1mm();
	int Y1mm();

	int Xpx();
	int Ypx();
	int X1px();
	int Y1px();

private:
	int intXmm;
	int intYmm;
	int intX1mm;
	int intY1mm;

	int intXpx;
	int intYpx;
	int intX1px;
	int intY1px;

	QtSisImprimeFactura *QtSisImpFactura;
	char chrArrNombre[256];
	char chrArrDato[256];
};

class QtSisPuntosImpresion:public QPtrList<QtSisPuntoImpresion>
{
public:
	QtSisPuntosImpresion();

};

#endif
