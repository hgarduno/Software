
#ifndef __IMP_COTIZACIONES_H__
#define __IMP_COTIZACIONES_H__
#include <QtCotizaciones.h>
class zSiscomConexion;
class zOrdenVenta;
class zOrdenes;
class zClienteSiscom;

class QCotizaciones:public QtCotizaciones
{
 Q_OBJECT
public:
	QCotizaciones(
	    zSiscomConexion *pzSiscomConexion,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCotizaciones();
	void Ejecutando();
	void HabilitaBotones(bool pbHabilita);
	void TipoOrden(int pintTipoOrden);
	int TipoOrden();
	void ConsultandoPorRangoFechas();
	void PonConsultaPorRangoFechas(int pintConsultaPorRangoFechas);
	zOrdenVenta *Orden();

	int Aceptar();
private:
	zSiscomConexion *zSisConexion;
	zOrdenVenta *zOrdVenta;
	zOrdenes *zOrdsVentas;
	int intConsultaPorRangoFechas;
	int intConsultaPorIdVenta;
	int intAceptar;
	int intTipoOrden;
	void (QCotizaciones::*MuestraPorTipoOrden[10])(int ,zOrdenVenta *);
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	int Consulta();
	int ConsultaPorRangoFechas();
	void Muestra();
	void MuestraConsultaPorRangoFechas();
	void MuestraOrdenesVendidas();
	void MuestraProductos();
	void MuestraDescripcion();
	void MuestraProductosOrden(int );

	int EsConsultaPorIdVenta();
	int EsConsultaPorRangoFechas();
	void HabilitandoConsulta();
	const char *ObtenIdTipoOrden();
	void MuestraCotizacion(int,zOrdenVenta *);
	void MuestraVenta(int,zOrdenVenta *);
	void MuestraCancelacion(int,zOrdenVenta *);
	void MuestraNoDefinida(int,zOrdenVenta *);
	void ActivaAceptar();
	void reject();
	void AsignandoMuestraOrdenes();
	/*void keyPressEvent(QKeyEvent *); */

	void VieneSoloUnaOrden();


private slots:
	void SlotFocoAFechaFin();
	void SlotFocoAConsultar();
	void SlotAceptar();
	void SlotCapturandoIdVenta(const QString &);
	void SlotCancelar();
	void SlotOrden(int,int,int,const QPoint &);
	void SlotOrden(int,int);
	void SlotSeleccionandoTipoOrden(int );
public slots:
	void SlotConsulta();
signals:
	void SignalVendeOrden(zOrdenVenta *pzOrdenVenta);
};
#endif
