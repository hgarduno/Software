
#ifndef __IMP_ORDENESREGISTRADAS_H__
#define __IMP_ORDENESREGISTRADAS_H__
#include <QtOrdenesRegistradas.h>
#include <zDevolucion.h>
class SiscomDatCom;
class zSiscomConexion;
class zOrdenes;
class zOrdenVenta;
class zExpendio;
class zPedidoPorCotizacion;
class QOrdenesRegistradas:public QtOrdenesRegistradas
{
 Q_OBJECT
public:
	QOrdenesRegistradas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenesRegistradas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zOrdenes *zOrdsRegistradas;
	zDevolucion zDevOrden;
	zPedidoPorCotizacion *zPedidoPC;
private:

	void Consultando();
	void Consulta();
	

	 void ImprimeTicketOrden();
	 void VendeOrden();

	 void Devolucion();
	 void Devuelve(); 
	 void ActivaBotones(bool pbModal);
	 void YaSeReflejoTransferencia();
	 void EnviaPedidoPorCotizacion();
	 void EnviandoPedidoPorCotizacion();

	 void AsignaPedidoPorCotizacion();
	 zPedidoPorCotizacion *PedidoPorCotizacion();
	 void DatosPedidoCotizacion();

	 void ConsultandoPorFiltro();
	 void ConsultaPorFiltro();

private slots:
	 void SlotConsulta();
	void SlotImprimir();
	void SlotVender();
	void SlotDevolucion();
	void SlotSeReflejo();
	void SlotPedidoPorCotizacion();
	void SlotConsultaPorFiltro();
};
extern "C" QOrdenesRegistradas *InstanciaOrdenesRegistradas(void *,char **,void *,const char *,int);
#endif
