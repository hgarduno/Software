#ifndef __QTIMPCAPTURADATOSCOMUNICACION_H__
#define __QTIMPCAPTURADATOSCOMUNICACION_H__
#include <cstddef>
#include <CapturaDatosComunicacion.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class zDireccion;
class zPersona;
class zContratoBeneficios;
class zDatosComunicacion;
class zCorreo;
class QtImpCapturaDatosComunicacion:public CapturaDatosComunicacion
{
Q_OBJECT
public:
	QtImpCapturaDatosComunicacion(zContratoBeneficios *pzConBeneficios,
				QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	zDireccion *Direccion();
	int Aceptar();
	
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	int Registrando();
	int Registra();
	void AsignaComunicacion();
	void IniciaVariables();
    	void MuestraDatos();
    	void HabilitaRegistrar();
    	int Actualizando();
    	int Actualiza();
private:
	zSiscomRegistros *zSisRegsDirecciones;
	zSiscomConexion *zSisConexion;
	zContratoBeneficios *zConBeneficios;
	zDatosComunicacion *zDatComunicacion;
	int intAceptar;
	int intClienteRegistrado;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotRegistrar();
	void SlotFocoARegistrar();
	void SlotFocoATelefonoCelular();
	void SlotFocoATelefonoRecado();
	void SlotFocoACorreoElectronico();
	void SlotActualiza();


};



#endif
