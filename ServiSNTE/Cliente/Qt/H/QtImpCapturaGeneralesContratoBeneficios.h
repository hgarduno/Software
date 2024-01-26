#ifndef __QTIMPCAPTURAGENERALESCONTRATOBENEFICIOS_H__
#define __QTIMPCAPTURAGENERALESCONTRATOBENEFICIOS_H__
#include <CapturaGeneralesContratoBeneficios.h>


class zGeneralesBeneficios;
class zContratoBeneficios;
class zSiscomConexion;
class QtImpCapturaGeneralesContratoBeneficios:public CapturaGeneralesContratoBeneficios
{
Q_OBJECT 
	public:
		QtImpCapturaGeneralesContratoBeneficios(
					zContratoBeneficios *pzConBeneficios,
					QWidget *pQWParent=0,
					const char *pchrPtrName=0);
	int Aceptar();
    void MuestraDatos();
private:
	zContratoBeneficios *zConBeneficios;
	zSiscomConexion *zSisConexion;
	zGeneralesBeneficios *zGenBeneficios;
	int intAceptar;
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void AnexaDatos();
	int Registra();
	int Registrando();
	int SeHabilitaRegistro();
	void reject();
private slots:
	void SlotFocoAFecha();
	void SlotFocoARegistrar();
	void SlotRegistrar();
	void SlotAceptar();
	void SlotCancelar();
};

#endif
