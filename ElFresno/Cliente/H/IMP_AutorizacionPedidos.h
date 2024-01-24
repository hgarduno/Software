#ifndef __IMP_AUTORIZACIONPEDIDOS_H__
#define __IMP_AUTORIZACIONPEDIDOS_H__

#include <UIC_H_AutorizacionPedidos.h>
#include <Pedidos.h>
#include <GeneralBibliotecaSeguridad3.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QPushButton;
class QTable;
class CSISCOMDatComunicaciones;
class Vehiculo;
class Chofer;
class QModificaPedido;
class Empresa;
class SiscomDatCom;

class QAutorizacionPedidos : public AutorizacionPedidos,
			     private QSiscomSeguridad3
{
    Q_OBJECT

public:
    QAutorizacionPedidos(CSISCOMDatComunicaciones *,
    			 QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QAutorizacionPedidos();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
    CQPedidos CQPPedidos;
    Vehiculo *V_Vehiculo;
    Pedido *P_Pedido;
    Chofer *C_Chofer;
    const char *chrPtrIdPerfilChoferes;
    QWidget *QWParent;
    char *chrPtrFechaTrabajoIni;
    char *chrPtrFechaTrabajoFin;
    char *chrPtrFechaTrabajoIniSinAuto;
    char *chrPtrFechaTrabajoFinSinAuto;
    Empresa *E_Matriz;
    CQ_Persona *CQPUFirmado;
    int intEnRuta; 
private:
	void ConectaSlots();
	void IniciaVariables();
	void CargaPedidosPendientesDeAutorizar();
	void MuestraPedidos();
	void MuestraDatosChoferEtc();
	void ObtenIdChoferes();
	void CargaPedidosAutorizados();
	void CargaPedidosCargandose();
	void CargaPedidosEnRuta();
	void CargaPedidosEntregados();
	void CargaPedidosRevisadosALosChoferes();
	void ObtenDatosMatriz();
	void ObtenDatosUsuarioFirmado();

private slots:
	void S_AsignaChoferYVehiculo();
	void S_SeleccionoPedido(int,int,int,const QPoint &);
	void S_ActualizaInformacion();
	void S_ModificaPedido(int,int,int,const QPoint &);
	void S_FechaEntrega();
	void S_AutorizoPedido();
	void S_FFechaTrabajo();
	void S_PedidosAutorizados();
	void S_SeCargaElPedido();
	void S_PedidosCargandose();
	void S_SalioElPedido();
	void S_PedidosEnRuta();
	void S_PedidosEntregados();
	void S_PedidoEntregado();
	void S_PedidoRevisadoAlChofer();
	void S_PedidosRevisadosALosChoferes();
	void S_ModificoPedido();
	void S_CapturaFormaPago();
	void S_SeleccionandoPedidos(int,int);
	void S_FijaFechaTrabajoPedSinAutorizar();
};
extern "C" QAutorizacionPedidos *InstanciaAutorizacionPedidos(void *,void *,const char *,int );
#endif 
