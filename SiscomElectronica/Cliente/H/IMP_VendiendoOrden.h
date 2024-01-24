#ifndef __IMP_VENDIENDOORDEN_H__
#define __IMP_VENDIENDOORDEN_H__
#include <UIC_H_VendiendoOrden.h>
class zOrdenVenta;
class zSiscomConexion;
class QVendiendoOrden:public VendiendoOrden
{
 Q_OBJECT
public:
	QVendiendoOrden(zSiscomConexion *,
		zOrdenVenta *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QVendiendoOrden();
private:
	char **chrPtrArgumentos;
	zOrdenVenta *zOrdVenta;
	char *chrPtrIdOrden;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Vende();
	void Imprime();
	void GeneraId();
private slots:
	void SlotImprimir();
	void SlotVender();
};
#endif
