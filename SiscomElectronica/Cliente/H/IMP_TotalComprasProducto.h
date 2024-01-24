
#ifndef __IMP_TOTALCOMPRASPRODUCTO_H__
#define __IMP_TOTALCOMPRASPRODUCTO_H__
#include <UIC_H_TotalComprasProducto.h>
class SiscomDatCom;
class CQSisRastreoProducto;
class QTotalComprasProducto:public TotalComprasProducto
{
 Q_OBJECT
public:
	QTotalComprasProducto(
	    CQSisRastreoProducto *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QTotalComprasProducto();
private:
	CQSisRastreoProducto *CQSRastreoProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
