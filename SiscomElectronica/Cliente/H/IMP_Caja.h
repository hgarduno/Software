
#ifndef __IMP_CAJA_H__
#define __IMP_CAJA_H__
#include <UIC_H_Caja.h>
#include <CQSisOrdenCaja.h>
#include <ProductosE.h>
#include <Personas.h>
#include <qdockwindow.h>
class SiscomDatCom;
class QToolTip;
class QCaja:public Caja
{
 Q_OBJECT
public:
	QCaja(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCaja();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisOrdenCaja CQSOCaja;
	SiscomRegistro3 *SisReg3Orden;
	SiscomRegistro3 *SisReg3Cliente;
	char chrArrPago[12];
	const char *chrPtrCambio;
	QWidget *QWParent;

	ProductosE *PProductos;
	Persona PCliente;
private:
	void ConectaSlots();
	void IniciaVariables();
	void OrdenesPendientes();
	void ConsultaOrdenesPendientes();
	void MuestraOrdenesPendientes();
	int CapturaPago();
	void EnviaVenta();
	void VendeOrden();
	void ProductosOrden();
	void MensajeSeleccionarOrden();
	void CargaLaOrden();
	void CopiaDatosOrden();
	void CopiaDatosCliente();
	void ModificandoOrden();
private slots:
	void SlotActualizaOrdenes();
	void SlotSobreLaOrden(QIconViewItem *);
	void SlotVendeOrden(QIconViewItem *);
	void SlotCargaOrden(QIconViewItem *);
	void SlotModificaOrden();
	void SlotOtraOrdenSeleccionada(QIconViewItem *);
signals:
	void SignalModificaOrdenCaja(const char *,
				    ProductosE *,
				    Persona *);
};
extern "C" QCaja *InstanciaCaja(void *,char **,void *,const char *,int);
#endif
