#ifndef __QTSISIMPRIMEPROTOCOLO_H__
#define __QTSISIMPRIMEPROTOCOLO_H__
#include <QtSisImprime.h>
class SiscomRegistro3Lst;
class QWidget;
class QtSisImprimeProtocolo:public QtSisImprime
{
public:
	QtSisImprimeProtocolo(
		SiscomRegistro3Lst *pSisReg3LstDatos,
		QWidget *pQWParent,
		const char *pchrPtrName);
	

};

#endif
