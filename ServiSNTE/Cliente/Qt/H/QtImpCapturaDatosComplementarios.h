#ifndef __QTIMPCAPTURADATOSCOMPLEMENTARIOS_H__
#define __QTIMPCAPTURADATOSCOMPLEMENTARIOS_H__
#include <cstddef>
#include <CapturaDatosComplementarios.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class zCargoPublico;
class zContratoBeneficios;
class zReferenciasPersonales;
class zPersona;
class zDireccion;
class zParentesco;
class zTelefonos;
class QtImpCapturaDatosComplementarios:public CapturaDatosComplementarios
{
Q_OBJECT
public:
	QtImpCapturaDatosComplementarios(zContratoBeneficios *pzContratoBeneficios,	
				QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar();
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void ConectaSlotsReferencias();
	void IniciaControles();
	void IniciaVariables();
	void HabilitaCargoPublico(int );
	void HabilitaBeneficios(int);
	void HabilitaAportacionTercero(int);
	void CargoPublico();

	void AgregaDatos();
	int Registra();
	int Registrando();
	int RegistrandoReferenciasPersonales();
	int RegistraReferenciasPersonales();
	void AgregaDireccion();
	void AgregaPersona();
	void AgregaParentesco();
	void AgregaTelefono();

	void AgregaReferenciaPersonal();
	void MuestraReferencias(); void MuestraDireccion(int pintFila,zDireccion *pzDireccion);
	void MuestraPersona(int pintFila,zPersona *pzPersona);
	void MuestraParentesco(int pintFila,zParentesco *pzParentesco);
	void MuestraTelefonos(int pintFila,zTelefonos *pzTelefono);

	void MuestraDireccionPersonaRegistrada();
	void MuestraDatosPersonaRegistrada();
	void MuestraDatosTelefonoPersonaRegistrada();
	int ValidaPersonaRegistrada();


	void HabilitaDesHabilita(int pintEstado);
	void HabilitaControlesPersonaRegistrada();
	int DatosMinimosReferencia();
	int LineEditValido(QLineEdit *);
	void ConectaEditValidacionAgregar(QLineEdit *pQLETexto);
private:
	zSiscomRegistros *zSisRegsDirecciones;
	zSiscomConexion *zSisConexion;
	zContratoBeneficios *zConBeneficios;
	zCargoPublico *zCarPublico;
	zReferenciasPersonales *zRefsPersonales;
	zPersona *zPerReferencia;
	int intAceptar;
	int intPaginaActiva;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotFocoAEspecificar();
	void SlotFocoADependencia();
	void SlotFocoAPuesto();
	void SlotFocoAFunciones();
	void SlotFocoAPeriodo();
	void SlotFocoAAceptar();
	void SlotFocoARegistrar();
	void SlotCargoPublico(int pintBoton);
	void SlotBeneficios(int pintBeneficios);
	void SlotAportaTercero(int pintSiNo);
	void SlotRegistrar();
	void SlotCambioPagina(QWidget *);

	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoANombre();
	void SlotFocoACalle();
	void SlotFocoANoExterior();
	void SlotFocoANoInterior();
	void SlotFocoAColonia();
	void SlotFocoADelegacion();
	void SlotFocoAEstado();
	void SlotFocoACodigoPostal();
	void SlotFocoAAgregarReferencia();
	void SlotAgregarReferencia();
	void SlotFocoATelefono();
	void SlotFocoAParentesco();

	void SlotCambioTextoEdit(const QString &);
};



#endif
