
#ifndef __IMP_ORDENESDISPONIBLES_H__
#define __IMP_ORDENESDISPONIBLES_H__
#include <UIC_H_OrdenesDisponibles.h>
class zOrdenes;
class zOrdenVenta;
class QOrdenesDisponibles:public OrdenesDisponibles
{
 Q_OBJECT
public:
	QOrdenesDisponibles(zOrdenes *pzOrdenes,
			char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QOrdenesDisponibles();
	zOrdenVenta *Orden();
private:
	char **chrPtrArgumentos;
	zOrdenes *zOrdsVenta;
	zOrdenVenta *zOrVenta;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Muestra();
	void MuestraDetalle();
	void reject();
	void Mostrando(int pintOrden);
private slots:
	void SlotOrden(int,int,int,const QPoint &);
	void SlotSeleccionando(int,int,int,const QPoint &);
	void SlotSeleccionando(int,int);
	void SlotAceptar();
};
#endif
