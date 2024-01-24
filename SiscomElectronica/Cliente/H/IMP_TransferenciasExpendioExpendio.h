
#ifndef __IMP_TRANSFERENCIASEXPENDIOEXPENDIO_H__
#define __IMP_TRANSFERENCIASEXPENDIOEXPENDIO_H__
#include <UIC_H_TransferenciasExpendioExpendio.h>
class SiscomDatCom;
class CQSisRastreoProducto;
class QTransferenciasExpendioExpendio:public TransferenciasExpendioExpendio
{
 Q_OBJECT
public:
	QTransferenciasExpendioExpendio(
	    CQSisRastreoProducto *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QTransferenciasExpendioExpendio();
private:
	CQSisRastreoProducto *CQSRastreoProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
