#ifndef __QTIMPCAPTURADIRECCION_H__
#define __QTIMPCAPTURADIRECCION_H__
#include <cstddef>
#include <CapturaDireccion.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class zDireccion;
class zPersona;
class QtImpCapturaDireccion:public CapturaDireccion
{
Q_OBJECT
public:
	QtImpCapturaDireccion(int pintClienteRegistrado,	
				QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	zDireccion *Direccion();
	int Aceptar();
	void Persona(zPersona *pzPersona);
	void CapturandoDireccion();
	
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	zDireccion *FormaDireccion();
	zDireccion *ActualizaDireccion();
	void DireccionesPersona();
	void MuestraDireccion();
	void ConsultaDirecciones();
	void ConsultandoDirecciones();
	void CreaDireccion();
private:
	zSiscomRegistros *zSisRegsDirecciones;
	zSiscomConexion *zSisConexion;
	zDireccion *zPerDireccion;
	zPersona *zCliente;
	int intAceptar;
	int intClienteRegistrado;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotFocoANoExterior();
	void SlotFocoANoInterior();
	void SlotFocoAColonia();
	void SlotFocoADelegacionMunicipio();
	void SlotFocoAEstado();
	void SlotFocoACodigoPostal();
	void SlotFocoAReferencias();

};



#endif
