#ifndef __QTCLIENTEPEDIDO_H__
#define __QTCLIENTEPEDIDO_H__
#include <UIC_H_ClientePedido.h>
class zSiscomRegistro;
class zSiscomRegistros;
class zOrdenVenta;
class zDireccion;
class zTelefono;
class zCobertura;
class zClientesSiscom;

class QtClientePedido:public ClientePedido
{
Q_OBJECT
public:
	QtClientePedido(zOrdenVenta *pzOrdenVenta,
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags);
	~QtClientePedido();
	void YaTengoAlCliente();
	void HabilitaDesHabilitaDatos(bool pbEstado);
	void HabilitaDesHabilitaNombre(bool pbModal);
	void SoloLecturaDatos(bool pbEstado);
	int VerificandoCliente();
	void MostrandoCliente();
	zOrdenVenta *Orden();
	void ConectaSlots();

	void HabilitaDesHabilitaRegistraPersonales();
	void HabilitaDesHabilitaRegistraCelular();
	void HabilitaDesHabilitaRegistraDireccion();
	void HabilitaDesHabilitaAceptar();
	void HabilitaAceptarEleccionDireccion();
	void HabilitaDesHabilitaRegistraDireccion(bool);
	void MuestraDireccion();
	void MuestraDireccion(zDireccion *);
	void MuestraDatosComunicacion();
	void ControlesClienteRegistrado();
	void FocoADondeFalta();

	void IniciaVariables();

	void RegistraCelular(int);
	void RegistraPersonales(int);
	void Cliente();

	void MuestraGenerales();
	void MuestraEscuela();
	void MuestraCliente();
	void MuestraDirecciones();
	const QString ColumnaDireccion(zDireccion*);

	void MuestraClientes(zClientesSiscom *);
	void VeSiFaltaAlgunDato();
	zTelefono *FormaCelular();
	zSiscomRegistro *Escuela();
	
	int Aceptar();
	void Aceptar(int pintAceptar);

	void Cobertura(zCobertura *);
	zCobertura *Cobertura();

	void MuestraCobertura();
	void MensajeNoHayCobertura();
	void DireccionCliente();
	const char *Telefono();
private:
	int YaEstaElCliente();
	void MuestraPuntoEntrega();

	int RegistrandoPersonales();
	int RegistrandoCelular();
	int RegistrandoDireccion();

	void VeSiFaltaCelular();
	void FormaCliente();
	void FormandoCliente();

	void HabilitaDesHabilitaDireccion(bool );
	void MostrandoEntreCalles();
	zDireccion *FormaDireccion();
	void reject();
private:

	zOrdenVenta *zOrdVenta;
	zCobertura *zCoEnvio;
	zDireccion *zDirEnvio;

	int intRegistroPersonales;
	int intRegistroCelular;
	int intRegistroDireccion;
	int intSePuedeRegistrarPersonales;
	int intAceptar;

private slots:
	void SlotPuntoEntrega();

	void SlotEscuela(zSiscomRegistro *pzSisRegEscuela);
	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoARegistraPersonales();
	void SlotFocoACelular();
	void SlotFocoAReCelular();
	void SlotFocoARegistraCelular();
	void SlotFocoACalle();
	void SlotFocoANumero();
	void SlotFocoADelegacion();
	void SlotFocoAColonia();
	void SlotFocoAEstado();
	void SlotFocoACP();
	void SlotFocoAReferencias();

	void SlotFocoAEscuela();


	void SlotRegistraDireccion();

	void SlotCapturandoNombre(const QString &);
	void SlotCapturandoAPaterno(const QString &);
	void SlotCapturandoAMaterno(const QString &);

	void SlotCapturandoCelular(const QString &);
	void SlotCapturandoReCelular(const QString &);


	void SlotCapturandoCalle(const QString &);
	void SlotCapturandoNumero(const QString &);
	void SlotCapturandoDelegacion(const QString &);
	void SlotCapturandoColonia(const QString &);
	void SlotCapturandoEstado(const QString &);
	void SlotCapturandoCP(const QString &);
	void SlotCapturandoCalle1(const QString &);
	void SlotCapturandoCalle2(const QString &);

	void SlotDireccionCliente();
	void SlotFocoACalle1();
	void SlotFocoACalle2();
/*
	void SlotAlgunaOrden(zOrdenVenta *);
*/
public slots:
	virtual void SlotRegistraPersonales();
	virtual void SlotRegistraCelular();
	virtual void SlotAceptar();
	virtual void SlotCancelar();
	virtual void SlotCoberturaJTExpress();
	virtual void SlotDireccionEnvio(int,int,int,const QPoint &);
};

#endif
