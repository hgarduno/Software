
#ifndef __IMP_REGISTROPLACA_H__
#define __IMP_REGISTROPLACA_H__
#include <UIC_H_RegistroPlaca.h>
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zOrdenVenta;
class zClienteSiscom;
class zTelefono;
class zCircuitoImpreso;
class zProductoCotizar;
class zClientesSiscom;
class QRegistroPlaca:public RegistroPlaca
{
 Q_OBJECT
public:
	QRegistroPlaca(zSiscomConexion *,
		QWidget *pQWParent=0,
	    		const char *pchrPtrName=0,
	    		bool pbModal=false,
	    		WFlags pWFlags=0);
	~QRegistroPlaca();
	void Ejecutando();
	void Escuela(zSiscomRegistro *pzSisRegEscuela);
	void Orden(zOrdenVenta *pzOrden);
	int Aceptar();
	int SeImprimioComprobante();
	int SePuedeCerrarLaVentana();
	int Pagado();

private:
	zSiscomConexion *zSisConexion;
	zClienteSiscom *zCliSiscom;
	/* 21 de diciembre 2023
	 * 	zSiscomRegistros *zSisRegsClientes;
	 * Siscom Ecatepec
	 */
	zClientesSiscom *zClisSiscom;
	zOrdenVenta *zOrdVenta;
	int intRegistroPersonales;
	zSiscomRegistro *zSisRegEscuela;
	int intClaveImpreso;
	zCircuitoImpreso *zCirImpreso;
	zSiscomRegistros *zSisRegsCircuitosPendientes;
	int intAceptar;
	int intImprimioComprobante;
	int intNImpresosRegistrados;

	int intPuedeCerrarVentana;

	int intRegistrando;
	int intPagado;
private:
	void ConectaSlots();
	void IniciaVariables();
	int RegistrandoPersonales();
	int RegistraCliente();
	int MuestraClientesSimilares();
	void MuestraCliente();
	void ControlesARegistroCelular();
	int ValidandoTelefono();
	int RegistrandoCelular();
	zTelefono *FormaCelular();
	int RegistraCelular();
	void ControlesAFechaHoraEntrega();
	void MuestraProductos();
	int RegistraImpreso();
	int RegistrandoImpreso();
	zCircuitoImpreso *FormaCircuitoImpreso(zOrdenVenta *);
	zClienteSiscom *Cliente();

	void ConsultandoImpresosPendientes();
	void ConsultaImpresosPendientes();
	void MuestraImpresosPendientes();
	void Imprimiendo(zOrdenVenta *);
	void AgregandoDatosOrden(zOrdenVenta *);
	void ValidandoDatosMinimosNombre();
	void ValidandoDatosParaImpreso();
	void ValidandoDatosCelular();

	void OrdenParaImprimirTicket(zOrdenVenta *);

	void ImprimeUnaPlaca(zOrdenVenta *);
	zOrdenVenta *ImprimeVariasPlacas(zProductoCotizar *);
	int SeImprimeUnaPlaca();
	zOrdenVenta *OrdenImpreso();

	void SigueRegistrando();

	void reject();
	int CuantosImpresosHayEnLaOrden();
	void HabilitaDesHabilitaDatos(bool);
	int EsCircuitoImpreso(zProductoCotizar *);
	void AsignaOrdenComoApartado();
	void CargandoSePagaOrdenImpreso();
	void FormaRegistroApartado(const char *);
private slots:
	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoACelular();
	void SlotFocoAReCelular();
	void SlotFocoARegistraPersonales();
	void SlotFocoAArchivo();

	void SlotRegistraPersonales();
	void SlotRegistraCelular();
	void SlotValidandoCapturaCelular();

	void SlotProducto(int pintNProducto);
	void SlotImprimeComprobante();
	void SlotRegistra();
	void SlotAceptar();
	void SlotCancelar();

	void SlotCapturandoNombre(const QString &);

	void SlotCapturandoDatosParaImpreso();
	void SlotCapturandoDatosParaImpreso(const QString &);
	void SlotCapturandoCelular(const QString &);

};
#endif
