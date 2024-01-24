#ifndef __IMP_SELECCIONAORDEN_H__
#define __IMP_SELECCIONAORDEN_H__
#include <IMP_Cotizaciones.h>

class zOrdenVenta;
class QSeleccionaOrden:public QCotizaciones
{

Q_OBJECT
	public:
		QSeleccionaOrden(zSiscomConexion *,
				QWidget *pQWParent=0,
				const char *pchrPtrName=0,
				bool pbModal=false,
				WFlags pWFlags=0);
		~QSeleccionaOrden();

private:
	void IniciaVariables();
};

#endif
