#ifndef __QTIMPCAPTURADATOSEMPLEO_H__
#define __QTIMPCAPTURADATOSEMPLEO_H__
#include <cstddef>
#include <CapturaDatosEmpleo.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class zDireccion;
class zContratoBeneficios;
class zEmpresa;
class zEmpleo;
class zPersona;
class QtImpCapturaDatosEmpleo:public CapturaDatosEmpleo
{
Q_OBJECT
public:
	QtImpCapturaDatosEmpleo(zContratoBeneficios *pzContratoBeneficios,
				QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar();
	
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void IniciaVariables();
	void AnexaDatosGenerales();
	int Registrando();
	int Registra();
	int Actualiza();
	int Actualizando();
	void OtrosIngresos();
	void Direccion(zEmpresa *pzEmpresa);
	void Empleo();
	void Jefe(zEmpresa *pzEmpresa);
	void DatosEmpresa(zEmpresa *pzEmpresa);
    	void MuestraDatos();
	int ValidaEmpresaRegistrada();
	int ValidaJefeRegistrado();
	void MuestraDatosEmpresaRegistrada();
	void MuestraDireccionEmpresaRegistrada();
	void MuestraTelefonoEmpresaRegistrada();
	void MuestraCorreosEmpresaRegistrada();
	void MuestraGiroEmpresaRegistrada();

	void ActualizaJefe();
	void ActualizaEmpleo();
	void ActualizaEmpresa();
	void ActualizaComunicacion();
private:
	zSiscomRegistros *zSisRegsDirecciones;
	zSiscomRegistro *zSisRegFrecPago;
	zSiscomConexion *zSisConexion;
	zContratoBeneficios *zConBeneficios;
	zEmpleo *zEmpActual;
	zEmpresa *zEmpresaA;
	zPersona *zPerJefe;
	int intAceptar;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotRegistrar();

	void SlotFocoAAntiguedad();
	void SlotFocoAPuestoActual();
	void SlotFocoAActividadGiro();
	void SlotFocoANombre();
	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoACalle();
	void SlotFocoANoExterior();
	void SlotFocoANoInterior();
	void SlotFocoAColonia();
	void SlotFocoADelegacion();
	void SlotFocoAEstado();
	void SlotFocoACodigoPostal();
	void SlotFocoAPais();
	void SlotFocoATelefono();
	void SlotFocoAExtension();
	void SlotFocoACorreoElectronico();
	void SlotFocoASueldo();
	void SlotFocoAOtrosIngresos();
	void SlotFocoAEspecificaOIngresos();
	void SlotFocoATotalIngresos();
	void SlotFocoAFrecuenciaPago();
	void SlotFrecuenciaPago(zSiscomRegistro *pzSisRegFrecPago);
	void SlotFocoAAceptar();
	void SlotFocoARegistrar();
	void SlotActualizar();
};



#endif
