#ifndef __QTADMINISTRADORPEDIDOS_H__
#define __QTADMINISTRADORPEDIDOS_H__
#include <UIC_H_AdministradorPedidos.h>


class QPushButton;
class zOrdenVenta;
class zOrdenes;
class zSiscomConexion;
class zSiscomRegistro;
class zCondicionConsultaOrdenes;
class zCondicionConsultaHoraEntrega;

class QtAdministradorPedidos:public AdministradorPedidos
{
Q_OBJECT
public:
	QtAdministradorPedidos(zSiscomConexion *,
				QWidget *pQWParent,
			       const char *pchrPtrName,
			       WFlags pWFlags);
	void ConectaSlots();
	void IniciaVariables();
	void Iniciando();
	void Ordenes(zOrdenes *);
	zOrdenes *Ordenes();
	void MuestraOrdenes();
	zOrdenVenta *Orden();
	const char *IdNuevoEstado();
	zCondicionConsultaOrdenes *PedidosPorFechas();
	zCondicionConsultaOrdenes *PedidosPorHora();
	zCondicionConsultaOrdenes *Condicion();
	zCondicionConsultaOrdenes *ConsultaPedidosPorFechas();
	zCondicionConsultaHoraEntrega *ConsultaHoraEntrega(const char *,const char *);
private:
	void ConectaBotones();
	void ConectaTabla();
	void ConectaOtros();
	void Clicked(QPushButton *,const char *);
	const QString TextoOrden(zOrdenVenta *);
	const QString TextoCliente(zOrdenVenta *);
	const QString TextoPuntoEntrega(zOrdenVenta *);
	const QString TextoCostoCambio(zOrdenVenta *);
	const QString TextoHoraEntrega(zOrdenVenta *);
	const QString TextoDireccionCliente(zOrdenVenta *);
	const QString TextoEstadoPedido(zOrdenVenta *);
	const QString TextoBotonActualiza(zOrdenVenta *);
	void TextoABotonActualizaEstado(zOrdenVenta *);
	void MuestraOrden(int pintFila,zOrdenVenta *);
	void MuestraOrdenes(zOrdenes *);
	zOrdenVenta *Orden(int);
	void HabilitaImpresion();
	int CapturandoHoraEntrega(char *,char *);
	void IniciandoConsultas();


private:
	zOrdenes *zOrdsPedidos;
	zOrdenVenta *zOrdenV;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegEstado;
	zCondicionConsultaOrdenes *(QtAdministradorPedidos::*Consultas[100])();
	zCondicionConsultaOrdenes *zConConsOrdenes;

public slots:
	virtual void SlotConsultar();
	virtual void SlotActualizaEstado();
	virtual void SlotImprimir();


	void SlotSelecciona(int,int,int,const QPoint &);
	void SlotSelecciona(int,int);
	void SlotSeleccionoEstado(zSiscomRegistro *);
	void SlotFocoAFechaFin();
	void SlotFocoAConsultar();
	void SlotComoConsulto(int);
};
#endif
