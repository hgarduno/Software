#ifndef __IMP_CAMBIOENCAJA_H__
#define __IMP_CAMBIOENCAJA_H__
#include <UIC_H_CambioEnCaja.h>
#include <zCambiosCaja.h>
class SiscomDatCom;

class zSiscomConexion;
class zSiscomElectronica;
class QCambioEnCaja:public CambioEnCaja
{
 Q_OBJECT
public:
	QCambioEnCaja(QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCambioEnCaja();
	zCambioCaja *CambioCaja();
private:
	zCambiosCaja zCambiosC;
	zCambioCaja *zCambioC;
private:
	void ConectaSlots();
	void IniciaVariables();

	void Consultando();
	void Consulta();
	void Muestra();
	zSiscomConexion *Conexion();
private slots:
	void SlotSeleccionoCambioCaja(int,int,int,const QPoint &);
	void SlotAceptar();
};
#endif
