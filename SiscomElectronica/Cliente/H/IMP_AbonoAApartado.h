
#ifndef __IMP_ABONOAAPARTADO_H__
#define __IMP_ABONOAAPARTADO_H__
#include <QtAbonoAApartado.h>


class zOrdenVenta;
class QAbonoAApartado:public QtAbonoAApartado
{
 Q_OBJECT
public:
	QAbonoAApartado(zOrdenVenta *,
			QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QAbonoAApartado();
private:
private:
	void Registrar();
private slots:
};
#endif
