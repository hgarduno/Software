#ifndef __QTIMPCAPTURADIRECCIONPARTICULAR_H__
#define __QTIMPCAPTURADIRECCIONPARTICULAR_H__
#include <cstddef>
#include <CapturaDireccionParticular.h>
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class zDireccion;
class zPersona;
class zContratoBeneficios;
class zTelefonos;
class QtImpCapturaDireccionParticular:public CapturaDireccionParticular
{
Q_OBJECT
public:
	QtImpCapturaDireccionParticular(zContratoBeneficios *pzContratoBeneficios,
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
	void DireccionesPersona();
	void MuestraDireccion();
	void ConsultaDirecciones();
	void ConsultandoDirecciones();
	void CreaDireccion();
	void IniciaControles();
	void InicioDireccionRegistrada();
	void InicioDireccionSinRegistrar();
	void Iniciando();
	void AnexaOtrosDatos();
	int RegistrandoDatosCasa();
	int RegistraDatosCasa();
	void HabilitaRegistrar();
	
private:
	zSiscomRegistros *zSisRegsDirecciones;
	zSiscomConexion *zSisConexion;
	zDireccion *zPerDireccion;
	zPersona *zCliente;
	zSiscomRegistro *zSisRegTipoVivienda;
	int intAceptar;
	/*
	zTelefonos *zTelsCliente;
	*/
	zContratoBeneficios *zConBeneficios;
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
	void SlotTipoVivienda(zSiscomRegistro *pzSisRegTVivienda);
	void SlotFocoATiempoResidir();
	void SlotFocoAAceptar();
	void SlotFocoARegistrar();
	void SlotRegistrar();
	void SlotCambiaTiempoResidir(const QString &);
};



#endif
