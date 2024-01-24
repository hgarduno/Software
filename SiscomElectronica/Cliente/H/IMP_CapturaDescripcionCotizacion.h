#ifndef __IMP_CAPTURADESCRIPCIONCOTIZACION_H__
#define __IMP_CAPTURADESCRIPCIONCOTIZACION_H__
#include <QtCapturaDescripcionCotizacion.h>
class zSiscomConexion;
class zOrdenVenta;
class zCotizacionMediaCenter;
class zEscuela;
class QCapturaDescripcionCotizacion:public QtCapturaDescripcionCotizacion
{
 Q_OBJECT
public:
	QCapturaDescripcionCotizacion(
	   int pintSoloDescripcion,
	   const char *pchrPtrModo,
	   zOrdenVenta *,
	   zSiscomConexion *,
	   QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaDescripcionCotizacion();
private:
	const char *chrPtrModo;
private:
	void IniciandoCotizacion();
private slots:
};
#endif
