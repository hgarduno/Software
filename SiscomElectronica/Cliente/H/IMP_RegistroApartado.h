#ifndef __IMP_REGISTROAPARTADO_H__
#define __IMP_REGISTROAPARTADO_H__
#include <UIC_H_RegistroApartado.h>
class zSiscomConexion;
class zClienteSiscom;
class zCorreo;
class zTelefono;
class zSiscomRegistro;
class zSiscomRegistros;
class zApartado;
class zClientesSiscom;
class QRegistroApartado:public RegistroApartado
{
 Q_OBJECT
public:
	QRegistroApartado(QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRegistroApartado();
	void Escuela(zSiscomRegistro *pzSisRegEscuela);
	zClienteSiscom *Cliente();
	zApartado *Apartado();
	void setFocus();
	void Ejecutando();
private:
	zSiscomConexion *zSisConexion;
	zClienteSiscom *zCliSiscom;
	zSiscomRegistro *zSisRegEscuela;
	/* 21 de diciembre 2023 -> Ecatepec 
	 *
	zSiscomRegistros *zSisRegsClientes;
	*/

	zClientesSiscom *zClisSiscom;
	
	int intRegistroCelular;
	int intRegistroCorreo;

private:
	
	zClienteSiscom *ClienteSiscom();
	zTelefono *FormaCelular();
	zCorreo *FormaCorreo();
	void ConectaSlots();
	void IniciaVariables();
	void ValidandoTelefono();
	void ValidandoCorreo();

	int RegistraCliente();
	int RegistraCelular();
	int RegistraCorreo();

	int RegistrandoCelular();
	int RegistrandoCorreo();
	int RegistrandoPersonales();

	void HabilitaDesHabilita(bool pbDato);

	void MuestraClientesSimilares();
	void MuestraCliente();
	void MuestraDatosComunicacion();
	void ConsultandoSimilares();
	void HabilitandoAceptar();
	void VeADondePasaFocoComunicaciones();
	void ControlesDespuesRegistrarPersonales();
	void HabilitaDesHabilitaRegistraCelular();
	void HabilitaDesHabilitaRegistraCorreo();

	int SeCapturoCorreo();
	void reject();
private slots:
	void SlotAceptar();

	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoARegistraPersonales();
	void SlotFocoACelular();
	void SlotFocoAReCelular();
	void SlotFocoARegistraCelular();
	void SlotFocoACorreo();
	void SlotFocoAReCorreo();
	void SlotFocoARegistraCorreo();
	void SlotFocoACuenta();
	void SlotFocoAFechaEntrega();
	void SlotFocoAObservaciones();
	
	void SlotRegistraPersonales();
	void SlotRegistraCelular();
	void SlotRegistraCorreo();

	void SlotCapturandoCelular(const QString &pQStrCelular);
	void SlotCapturandoCorreo(const QString &pQStrCorreo);
	void SlotCapturandoACuenta(const QString &);
	void SlotCancelar();

signals:
	void SignalAceptar();
	void SignalCancelar();
};
#endif
