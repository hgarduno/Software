#ifndef __QTIMPCAPTURACENTROTRABAJO_H__
#define __QTIMPCAPTURACENTROTRABAJO_H__
#include <CapturaCentroTrabajo.h>



class zContratoBeneficios;
class zCentroTrabajo;


class zSiscomConexion;

class QtImpCapturaCentroTrabajo:public CapturaCentroTrabajo
{
Q_OBJECT
public:

	QtImpCapturaCentroTrabajo(zContratoBeneficios *pzConBeneficios,
				   QWidget *pQWParent=0, 
				  const char *pchrPtrName=0,
				  bool pbModal=false,
				  WFlags pWFlags=0);
	int Aceptar();
private:
	void IniciaVariables();
	void ConectaSlots();
	void reject();
	void Conexion(zSiscomConexion *pzSiscomConexion);
	int Registrando();
	int Registra();
	void Asigna();
	void Muestra();	
private:
	zSiscomConexion *zSisConexion;
	zContratoBeneficios *zConBeneficios;
	zCentroTrabajo *zCenTrabajo;
	int intAceptar;
private slots:
	void SlotFocoAClavePresupuestal();
	void SlotFocoARegistrar();
	void SlotRegistrar();
	void SlotAceptar();
};


#endif
