#ifndef __IMP_DATOSFACTURACION_H__
#define __IMP_DATOSFACTURACION_H__
#include <UIC_H_DatosFacturacion.h>
#include <zCorreos.h>
#include <zTelefonos.h>

class SiscomDatCom;
class zSiscomConexion;
class zPersona;
class zEmpresa;
class zDireccion;
class zCorreo;
class zTelefono;
class zCliente;

class QDatosFacturacion:public DatosFacturacion
{
 Q_OBJECT
public:
//{{ Funciones publicas
	QDatosFacturacion(SiscomDatCom *,
	    char **,
	    zCliente *pzCliente,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QDatosFacturacion();
	zCliente *Cliente();
	zCorreo *CorreoActivo();
	zSiscomRegistro *FormaPago();
	zSiscomRegistro *MetodoPago();
	zSiscomRegistro *UsoFactura();
	int Aceptar();
//}
private:
	// {Variables privadas
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zPersona *zPersonaC;
	zEmpresa *zEmpresaC;
	zDireccion *zDireccionC;
	zCorreo *zCorreoC;
	zCorreo *zCorreoActivo;
	zTelefono *zTelefonoC;
	zCorreos zCorreosC;
	zTelefonos zTelefonosC;
	zCliente *zClienteC;
	int intAceptar;
	int intEdoRegistro;
	int intAgregandoCorreo;
	int intEmpresaRegistrada;
	zSiscomRegistro *zSisRegFormaPago;
	zSiscomRegistro *zSisRegMetodoPago;
	zSiscomRegistro *zSisRegUsoFactura;
	zSiscomRegistro *zSisRegRegimenFiscal;
	//}
private:
 	//{{ funciones privadas
	
	void ConectaSlots();
	void IniciaVariables();
	void ClienteEmpresa();
	void ClientePersona();
	void FormaEmpresa();
	void FormaPersona();
	void FormaDireccion();
	void FormaCorreo();
	void FormaTelefono();
	void Registrando();
	void FormaCliente();
	void DatosCliente();
	int ValidaRFCRegistrado();
	void ClienteRegistrado();
	void MuestraClienteRegistrado();
	void MuestraDireccion();
	void MuestraNombre();
	void MuestraEmpresa();
	void MuestraTelefonos();
	void MuestraCorreos();
	void ConectaSlotsAgregaCorreo();
	void AgregandoNuevoCorreo();
	void RegistraNuevoCorreo();
	void AsignaClienteRegistrado();
	void ReConsultaCliente();
	void SeEstaFacturando();
	void IniciaControles();
	void PasandoRazonSocial();
	void PasandoRegimenFiscal();

	void ActivaRegistrarDatos();
	int ValidaRegimenFiscal();
	void RegistraRegimenFiscal();
	void RegistrandoRegimenFiscal();
	//}}
private slots:
	//{ Slots Foco A Capturando 
	void SlotFocoARazonSocial(zSiscomRegistro *);
	void SlotFocoANombre();
	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoARegimenFiscal();
	void SlotFocoACalle();
	void SlotFocoANumero();
	void SlotFocoANumeroInt();
	void SlotFocoADelegacion();
	void SlotFocoAColonia();
	void SlotFocoAEstado();
	void SlotFocoACP();
	void SlotFocoACorreo();
	void SlotFocoACorreoOtraVez();
	//void SlotFocoACodigoPostal();
	void SlotFocoAAceptar();
	void SlotFocoATelefono();
	void SlotFocoAAgregarCorreo();
	void SlotFocoARegistrarDatos();

	void SlotCapturandoRazonSocial(const QString &);
	void SlotCapturandoRegimenFiscal(const QString &);
	void SlotCapturandoNombre(const QString &);
	void SlotCapturandoAPaterno(const QString &);
	void SlotCapturandoAMaterno(const QString &);
	void SlotCapturandoRFC(const QString &);
	void SlotCapturandoCalle(const QString &);
	void SlotCapturandoNumero(const QString &);
	void SlotCapturandoNumeroInt(const QString &);
	void SlotCapturandoDelegacion(const QString &);
	void SlotCapturandoColonia(const QString &);
	void SlotCapturandoEstado(const QString &);
	void SlotCapturandoCP(const QString &);
	void SlotCapturandoCorreo(const QString &);
	void SlotCapturandoCorreoOtraVez(const QString &);
	//void SlotCapturandoTelefono(const QString &);
	//}
	void SlotAceptar();
	void SlotCancelar();
	void SlotRegistrar();
	void SlotAgregarCorreo();
	void SlotSeleccionoCorreo(int pintCorreo,int,int,const QPoint &);
	void SlotFormaPago(zSiscomRegistro *);
	void SlotMetodoPago(zSiscomRegistro *);
	void SlotUsoCFDI(zSiscomRegistro *);
	void SlotRegimenFiscal(zSiscomRegistro *);
};
#endif
