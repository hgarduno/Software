#ifndef __PEDIDOS_H__
#define __PEDIDOS_H__
#include <qptrlist.h>
#include <qstringlist.h>
class CQ_Persona;
class CQProductosCotizacion;
class ProductoCotizacion;
class Vehiculo;
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class Pedido
{
public:
	Pedido(CQ_Persona *,
	       CQProductosCotizacion *,
	       const char *);
	Pedido(CQ_Persona *,
		const char *,
		const char *,
		const char *,
		const char *);
	

	void PonChofer(CQ_Persona *);
	void PonAutorizo(CQ_Persona *);
	void PonVehiculo(Vehiculo *);
	void PonRevPedChofer(CQ_Persona *);
	void PonVendedor(CQ_Persona *);
	void PonNumPedido(const char *);	
	void PonEdoRegistro(const char *);
	void PonProductos(CQProductosCotizacion *);
	void PonFechaEntrega(const char *);
	void PonImportePedido(const char *);
	void PonFormaPago(const char *);
	void PonContactoCliente(const char *);
	CQ_Persona *ObtenCliente();
	CQ_Persona *ObtenChofer();
	CQ_Persona *ObtenAutorizo();
	CQ_Persona *ObtenRevPedChofer();
	CQ_Persona *ObtenVendedor();
	Vehiculo *ObtenVehiculo();
	const char *ObtenNumPedido();
	const char *ObtenEdoRegistro();
	const char *ObtenImporteDelPedido();
	const char *ObtenFechaRegistro();
	const char *ObtenTipoPrecio();
	const char *ObtenFormaPago();
	const char *ObtenFechaEntrega();
	const char *ObtenIdVendedor();
	const char *ObtenContactoCliente();
	CQProductosCotizacion *ObtenProductos();
	
	

private:
	CQ_Persona *CQPCliente;
	CQ_Persona *CQChofer;
	CQ_Persona *CQAutorizo;
	CQ_Persona *CQRevPedChofer;
	CQ_Persona *CQVendedor;
	Vehiculo *VVehiculo;
	const char *chrPtrNumPedido;
	const char *chrPtrVendedor;
	const char *chrPtrEdoRegistro;
	const char *chrPtrFechaRegistro;
	const char *chrPtrImportePedido;
	const char *chrPtrTipoPrecio;
	const char *chrPtrFormaPago;
	const char *chrPtrFechaEntrega;
	const char *chrPtrContactoCliente;
	CQProductosCotizacion *CQPCotizacion;
	       	
	

};
class CQPedidos:public QPtrList<Pedido>
{
	public:
		CQPedidos();

};
class CQCtrPedidos
{

	public:
		enum CtrPedidos
		{
		   Registrar,
		   PedidosSinAutorizarDelDia,
		   PedidosDelVehiculo,
		   AsignaVehiculo,
		   DetallePedido,
		   ActualizaPedido,
		   ActualizaFechaEntrega,
		   OperacionPedidos
		};
		CQCtrPedidos(CSISCOMDatComunicaciones *,
			     CtrPedidos ,
			     CQPedidos *);
		CQCtrPedidos(CSISCOMDatComunicaciones *,
			     CtrPedidos,
			     QStringList ,
			     CQPedidos *);
private:
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	const char *chrPtrParametrosEnvio;
	int intParametrosEnvio;
private:
		void RegistrarLosPedidos(CQPedidos *);
		void RegistroGeneralPedido(Pedido *);
		void EnviaRegistroVacio();
		void DetalleDelPedido(CQProductosCotizacion *);
		void ConsultarLosPedidos(QStringList ,CQPedidos *);
		void AnalizaRespuestaConsulta(CQPedidos *);
		void AsignaRespuestaVehiculo(CQPedidos *);
		void AnalizaRespuestaDetallePedido(CQPedidos *);
		void EnviaActualizaPedido(CQPedidos *);
		void EnviaActualizacionPedido();
		void EnviaRegistroFechaEntrega(CQPedidos *);
		void OperacionDeLosPedidos(QStringList, CQPedidos *);
};

#endif
