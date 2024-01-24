
#ifndef __IMP_TOTALVENTASPRODUCTO_H__
#define __IMP_TOTALVENTASPRODUCTO_H__
#include <UIC_H_TotalVentasProducto.h>
class SiscomDatCom;
class CQSisRastreoProducto;
class QTotalVentasProducto:public TotalVentasProducto
{
 Q_OBJECT
public:
	QTotalVentasProducto(
	    CQSisRastreoProducto *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QTotalVentasProducto();
private:
	CQSisRastreoProducto *CQSRastreoProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
