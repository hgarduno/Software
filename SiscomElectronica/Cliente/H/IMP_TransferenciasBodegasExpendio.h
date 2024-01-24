
#ifndef __IMP_TRANSFERENCIASBODEGASEXPENDIO_H__
#define __IMP_TRANSFERENCIASBODEGASEXPENDIO_H__
#include <UIC_H_TransferenciasBodegasExpendio.h>
class SiscomDatCom;
class CQSisRastreoProducto;
class QTransferenciasBodegasExpendio:public TransferenciasBodegasExpendio
{
 Q_OBJECT
public:
	QTransferenciasBodegasExpendio(
	    CQSisRastreoProducto *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QTransferenciasBodegasExpendio();
private:
	CQSisRastreoProducto *CQSRastreoProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
