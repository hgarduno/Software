
#ifndef __IMP_CIERRAAPARTADO_H__
#define __IMP_CIERRAAPARTADO_H__
#include <UIC_H_CierraApartado.h>
class zSiscomConexion;

class zSiscomRegistros;
class zSiscomRegistro;
class zOrdenVenta;

class zOrdenes;
class QCierraApartado:public CierraApartado
{
 Q_OBJECT
public:
	QCierraApartado(
	    zSiscomConexion *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCierraApartado();
	void setFocus();
private:
	zSiscomConexion *zSisConexion;
	zOrdenes *zOrdsRegistradas;
	zOrdenVenta *zOrden;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void HabilitaDesHabilitaPagar();
	void closeEvent(QCloseEvent *);
	void AbonoAApartado();
	void MuestraApartado(int,zOrdenVenta *);
	int ComoPago();
	int TraeDatosApartado(zOrdenVenta *);
private slots:
	void SlotConsulta();
	void SlotSeleccionaApartado(int,int,int ,const QPoint &);
	void SlotPagar();
	void SlotCancelar();
	void SlotFocoAFechaFin();
	void SlotFocoAConsulta();
	void SlotAbonoAApartado();
signals:
	void SignalPagar(zOrdenVenta *);
	void SignalCancelar();
};
#endif
