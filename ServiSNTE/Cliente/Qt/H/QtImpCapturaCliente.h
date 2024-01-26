#ifndef __QTIMPCAPTURACLIENTE_H__
#define __QTIMPCAPTURACLIENTE_H__
#include <cstddef>
#include <CapturaCliente.h>

class zSiscomConexion;
class zSiscomRegistro;
class zPersona;
class QTable;
class zCliente;
class QtImpCapturaCliente:public CapturaCliente
{
Q_OBJECT
public:
	QtImpCapturaCliente(zSiscomConexion *pzSisConexion,
			    zSiscomRegistro *pzSisTipoVenta,
			   QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	void Conexion(zSiscomConexion *pzSisConexion);
	void ReCapturaAlgunDato();
	zCliente *Cliente();
	int Aceptar();
	int ClienteRegistrado();
	int EsVentaContado();
private:
	void ConectaSlots();
	zCliente *FormaCliente();
	int RegistraCliente(char **pchrPtrRegreso);

	void ConsultaCliente();
	void ConsultandoCliente();
	void MuestraCliente();
	void MuestraComprasCliente(zSiscomRegistro *);
	void SePuedeVenderOtraVez(zSiscomRegistro *);
	void ConectaEditValidacionAgregar(QLineEdit *pQLETexto);
	int LineEditValido(QLineEdit *);
	int DatosMinimosNombre();
	void CondicionesClienteRegistrado();
	void CondicionesClienteNuevo();
	int ValidaRFCClienteRegistrado();
	int RFCRegistradoBaseDatos();
	int EstaRFCRegistradoBaseDatos();
	void ActualizaRFCCliente();
	void HabilitaDesHabilitaDatosPersonales(bool pbHabilita);
	int EsVentaCredito();
private:
	zSiscomConexion *zSisConexion;
	zCliente *zPerCliente;
	zSiscomRegistro *zSisRegTipoVenta;
	QTable *QTCompras;
	int intAceptar;
	int intClienteRegistrado;
private slots:
	void reject();
	void SlotCrear();
	void SlotAceptar();
	void SlotCancelar();
	void SlotFocoARFC();
	void SlotFocoAApellidoPaterno();
	void SlotFocoAApellidoMaterno();
	void SlotFocoANombres();
	void SlotFocoACrear();
	void SlotCambioTexto(const QString &);
};



#endif
