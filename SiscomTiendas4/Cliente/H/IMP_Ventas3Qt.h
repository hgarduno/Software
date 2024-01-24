
#ifndef __IMP_VENTAS3QT_H__
#define __IMP_VENTAS3QT_H__
#include <UIC_H_Ventas3Qt.h>
#include <CQSisProdCotiza3Qt.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisProdCotiza3Qt;
class CQSisPreciosTabla3Qt;

class QVentas3Qt:public Ventas3Qt
{
 Q_OBJECT
public:
	QVentas3Qt(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QVentas3Qt();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SReg3Cliente;
	SiscomRegistro3 *SReg3Contacto;
	SiscomRegistro3 *SReg3FPago;
	SiscomRegistro3 *SReg3Precio;
	SiscomRegistro3 *SReg3Producto;
	CQSisProdCotiza3Qt *CQSProd3QtCotiza;
	CQSisProdCotiza3QtLst CQSProd3QtLstCotiza;
	CQSisPreciosTabla3Qt *CQSPTabla3Qt;
	SiscomRegistro3Lst SReg3TiposPrecios;
	 void (QVentas3Qt::*CambiaDatos[10])(SiscomRegistro3 *,int,int);
	 int intSeElimina;
	 const char *chrPtrTipoOrden;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraContactos();
	CQSisProdCotiza3Qt *Producto();
	void CotizaProducto();
	void CotizandoProducto();
	void MuestraProductoCotizado();
	void ActivaAnexarALaOrden();

	void CotizandoProductos();
	void CotizaProductos();
	void MuestraProductos();

	void GeneraIdentificador();
	void IniciaOtraOrden();

	void CambiaCantidad(SiscomRegistro3 *,int,int);
	void CambiaTipoPrecio(SiscomRegistro3 *,int,int);
	void OpcionInvalida(SiscomRegistro3 *,int,int);
	void keyPressEvent(QKeyEvent *);
	void ReInicia();
	void closeEvent(QCloseEvent *);
	void EliminaSeleccionados();

	void MuestraPreciosProducto();
	void ActualizaTipoOrden();
	int CapturaRemFactura(char *pchrPtrNoRemFactura);
	void ColocaNoRemisionFactura(const char *pchrPtrNoRemFactura);
private slots:
	void SlotMoral(SiscomRegistro3 *);
	void SlotFisica(SiscomRegistro3 *);
	void SlotContacto(SiscomRegistro3 *);
	void SlotFormaPago(SiscomRegistro3 *);
	void SlotPrecio(SiscomRegistro3 *);
	void SlotProducto(SiscomRegistro3 *);
	void SlotSeleccionandoProducto(SiscomRegistro3 *);
	void SlotCotiza();
	void SlotAnexarProducto();
	void SlotRegistra();
	void SlotImprime();

	void SlotCambiaDato(int,int,int,const QPoint &);
	void SlotCambioTipoPrecio(SiscomRegistro3 *,int,int);

	void SlotCambioSeleccion();
	void SlotElimina();
	void SlotTipoOrden(int);
	void SlotProductoNoEstaEnLaLista(const char *pchrPtrTexto);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QVentas3Qt *InstanciaVentas3Qt(void *,char **,void *,const char *,int);
#endif
