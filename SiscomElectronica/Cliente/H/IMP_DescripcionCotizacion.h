
#ifndef __IMP_DESCRIPCIONCOTIZACION_H__
#define __IMP_DESCRIPCIONCOTIZACION_H__
#include <UIC_H_DescripcionCotizacion.h>
class zCotizacion;
class QDescripcionCotizacion:public DescripcionCotizacion
{
 Q_OBJECT
public:
	QDescripcionCotizacion(
	   zCotizacion *pzCotizacion,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QDescripcionCotizacion();
	void setFocus();
	void Cierra();
	void Ejecutando();
	int Aceptar();
private:
	zCotizacion *zCotOrden;	
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
	void FormaCotizacion();
	void reject();
private slots:
	void SlotAceptar();
	void Descripcion();
signals:
	void SignalCotizacion(zCotizacion *);

};
#endif
