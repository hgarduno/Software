#ifndef __QTSISBOTONORDEN_H__
#define __QTSISBOTONORDEN_H__
#include <qpushbutton.h>
class zOrdenVenta;
class zOrdenFavorita;
class QtSisBotonOrden:public QPushButton 
{
Q_OBJECT
public:
	QtSisBotonOrden(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Orden(zOrdenVenta *);
	void OrdenFavorita(zOrdenFavorita *);

	void Texto(const char *pchrPtrTexto);
	void IdOrden(const char *pchrPtrIdOrden);

	const char *Texto();
	const char *IdOrden();
	zOrdenVenta *Orden();
	zOrdenFavorita *OrdenFavorita();
private:
	zOrdenVenta *zOrdVenta;
	zOrdenFavorita *zOrdFavorita;
	const char *chrPtrIdOrden;
};
#endif
