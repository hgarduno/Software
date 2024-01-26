#ifndef __QTIMPCAPTURADATOSGENERALES_H__
#define __QTIMPCAPTURADATOSGENERALES_H__
#include <cstddef>
#include <CapturaDatosGenerales.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class zDireccion;
class zPersona;
class zContratoBeneficios;
class zDatosGenerales;
class QtImpCapturaDatosGenerales:public CapturaDatosGenerales
{
Q_OBJECT
public:
	QtImpCapturaDatosGenerales(zContratoBeneficios *pzConBeneficios,
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
	int Actualizando();
	int Registra();
	int Actualiza();
	void AsignaPersonales();
	const char *Sexo();
	const char *EstadoCivil();
	void IniciaVariables();
	void MuestraDatos();
	void HabilitaRegistrar();
private:
	zSiscomRegistros *zSisRegsDirecciones;
	zSiscomConexion *zSisConexion;
	zDireccion *zPerDireccion;
	zPersona *zCliente;
	zContratoBeneficios *zConBeneficios;
	zDatosGenerales *zDatGenerales;
	int intAceptar;
	int intClienteRegistrado;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotRegistrar();

	void SlotFocoACurp();
	void SlotFocoAEstadoNacimiento();
	void SlotFocoAPaisNacimiento();
	void SlotFocoAMasculino();
	void SlotFocoAFechaNacimiento();
	void SlotFocoAIdentificacion();
	void SlotFocoANoIdentificacion();
	void SlotFocoAOcupacion();
	void SlotFocoANacionalidad();
	void SlotFocoARegistrar();
	void SlotSeleccionaSexo(int);
	void SlotActualizaGenerales();

};

#endif
