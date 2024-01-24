
#ifndef __IMP_VENTASPORCAJA_H__
#define __IMP_VENTASPORCAJA_H__
#include <UIC_H_VentasPorCaja.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QVentasPorCaja:public VentasPorCaja
{
 Q_OBJECT
public:
	QVentasPorCaja(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QVentasPorCaja();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3VentasCaja;
	char chrArrFechaIni[20];
	char chrArrFechaFin[20];
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void MuestraTotalVentas();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotCapturaRangoFechas();
	void SlotActualiza();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QVentasPorCaja *InstanciaVentasPorCaja(void *,char **,void *,const char *,int);
#endif
