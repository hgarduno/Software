
#ifndef __IMP_FACTURAS_H__
#define __IMP_FACTURAS_H__
#include <UIC_H_Facturas.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QFacturas:public Facturas
{
 Q_OBJECT
public:
	QFacturas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QFacturas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	char chrArrFechaIni[25];
	char chrArrFechaFin[25];
	SiscomRegistro3 *SisReg3Proveedor;
	SiscomRegistro3Lst SisReg3LstFacturas;
	SiscomRegistro3 *SisReg3Factura;
	SiscomRegistro3Lst SisReg3LstDFactura;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoFacturas();
	void ConsultaFacturas();
	void MuestraFacturas();
	void ConsultandoDetalleFactura();
	void ConsultaDetalleFactura();
	void MuestraDetalleFactura();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotRangoFechas();
	void SlotActualiza();
	void SlotFiltroProveedor();
	void SlotSeleccionandoFactura(int,int,int,const QPoint &);
	void SlotActualizaNumFactura();
	void SlotCopiar();
	void SlotAnexarFactura();
	void SlotAnexarFacturasPeriodoContable();
	void SlotCambiandoFactura(int,int);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QFacturas *InstanciaFacturas(void *,char **,void *,const char *,int);
#endif
