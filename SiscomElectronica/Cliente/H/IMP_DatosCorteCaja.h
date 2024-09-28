#ifndef __IMP_CAMBIOENCAJA_H__
#define __IMP_CAMBIOENCAJA_H__
#include <UIC_H_DatosCorteCaja.h>
#include <zCambiosCaja.h>
class SiscomDatCom;

class zSiscomConexion;
class zSiscomElectronica;
class QDatosCorteCaja:public DatosCorteCaja
{
 Q_OBJECT
public:
	QDatosCorteCaja(QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QDatosCorteCaja();
	zCambioCaja *CambioCaja();
	const char *FechaInicio();
	const char *FechaFin();
private:
	zCambiosCaja zCambiosC;
	zCambioCaja *zCambioC;
private:
	void ConectaSlots();
	void IniciaVariables();
	void IniciandoFechas();

	void Consultando();
	void Consulta();
	void Muestra();
	zSiscomConexion *Conexion();
private slots:
	void SlotSeleccionoCambioCaja(int,int,int,const QPoint &);
	void SlotAceptar();
	void SlotFocoAFechaFin();
};
#endif
