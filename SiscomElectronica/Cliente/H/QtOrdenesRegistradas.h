#ifndef __QTORDENESREGISTRADAS_H__
#define __QTORDENESREGISTRADAS_H__
#include <UIC_H_OrdenesRegistradas.h>

class zOrdenVenta;
class zOrdenes;
class zExpendio;
class QConExpendiosVenta;
class zSiscomConexion;


#define TIPOS_ORDEN 15
class QtOrdenesRegistradas:public OrdenesRegistradas
{
Q_OBJECT
public:
	QtOrdenesRegistradas(zSiscomConexion *pzSisConexion,
			     char **pchrPtrArgumentos,
			     QWidget *pQWParent,
			     const char *pchrPtrName,
			     WFlags pWFlags);
	void ConectaSlots();
	void IniciaTiempo();
	const char *IdTipoOrden();
	void IniciaIdsTiposOrdenes();
	void IniciaTiposOrdenes();
	void IniciaDescripcionOrdenes();
	void IniciaTipoEntrega();
	void IniciaVariables();
	void Ordenes(zOrdenes *);
	zOrdenes *Ordenes();
	void Muestra();
	void MuestraOrden(int);
	void MostrandoLaOrden(zOrdenVenta *);
	void ActivaBotones(bool);
	void ActivandoBotones(bool);
	void ActivaBotonSeReflejo();
	zOrdenVenta *Orden();
	zSiscomConexion *Conexion();
	const char *IdExpendio();
	 void MarcaCotizacionComoVendida();
	 zOrdenVenta *Orden(int);

	 void Parent(QWidget *);
	 QWidget *Parent();
	
private slots:
	void SlotTipoOrden(int);
private:
	const char *(QtOrdenesRegistradas::*IdsTiposOrden[TIPOS_ORDEN])();
	const char *(QtOrdenesRegistradas::*TipoOrden[TIPOS_ORDEN])();
	const char *(QtOrdenesRegistradas::*Descripcion[TIPOS_ORDEN])(zOrdenVenta *);
	const char *(QtOrdenesRegistradas::*TipoEntrega[TIPOS_ORDEN])(zOrdenVenta *);
	const char *chrPtrIdTipoOrden;
	zOrdenes *zOrdsRegistradas;
	zOrdenVenta *zOrdVenta;
	QConExpendiosVenta *QConExpsV;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConOExpendio;
	zSiscomConexion *zSisConexion;
	int intOrdenSeleccionada[120];
	QWidget *QWParent;	
private:
	const char *IdVenta();
	const char *IdCotizacion();
	const char *IdCircuitoImpreso();
	const char *IdPedido();
	const char *IdSinAsignar();
	const char *IdTransferencia();
	const char *IdApartado();

	 const char *Cotizacion();
         const char *Venta();
	 const char *Cancelacion();
	 const char *Pedido();
	 const char *SinAsignar();
	 const char *Apartado();
	 const char *Transferencia();

	 const char *DescripcionCotizacion(zOrdenVenta *);
	 const char *DescripcionVenta(zOrdenVenta *);
	 const char *DescripcionApartado(zOrdenVenta *);
	 const char *DescripcionPedido(zOrdenVenta *);
	 const char *DescripcionSinAsignar(zOrdenVenta *);
	 const char *DescripcionCancelacion(zOrdenVenta *);
	 const char *DescripcionTransferencia(zOrdenVenta *);
	


	 const char *EntregaPedido(zOrdenVenta *);
	 const char *EntregaPuntoSiscom(zOrdenVenta *);
	 const char *EntregaDireccionCliente(zOrdenVenta *);

	 void CapturandoDescripcionCotizacion();
	 void keyPressEvent(QKeyEvent *);
	 void TeclasEspeciales(QKeyEvent*);
	 int CambiandoExpendio();
	 int CambiaExpendio();
	 void ConexionExpendio();
	 void MuestraExpendio();
	 void ActualizaDescripcion();

	 void CopiandoPortaPapeles();
	 void CopiandoPortaPapelesOrden();
	 void MarcaOrden();

private slots:
	void SlotFocoAConsulta();
	void SlotFocoAFechaFin();
	void SlotOrden(int,int,int,const QPoint &);
	void SlotDescripcion(int,int,int,const QPoint &);
	void SlotCambiandoOrden(int,int);
public slots:
	virtual void SlotConsulta();
	virtual void SlotImprimir();
	virtual void SlotVender();
	virtual void SlotDevolucion();
	virtual void SlotSeReflejo();
};
#endif
