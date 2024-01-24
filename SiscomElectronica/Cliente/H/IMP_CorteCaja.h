
#ifndef __IMP_CORTECAJA_H__
#define __IMP_CORTECAJA_H__
#include <UIC_H_CorteCaja.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class CQSisCorteCaja;
class QCorteCaja:public CorteCaja
{
 Q_OBJECT
public:
	QCorteCaja(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCorteCaja();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	char chrArrFechaIni[25];
	char chrArrFechaFin[25];
	SiscomRegistro3Lst SisReg3LstCorteCaja;
	SiscomRegistro3Lst SisReg3VentasCaja;
	SiscomRegistro3 *SisReg3Denominacion;
	SiscomRegistro3 *SisReg3Caja;
private:
	void ConectaSlots();
	void IniciaVariables();
	void AgregaDenominacion(const char *pchrPtrDenominacion,
				const char *pchrPtrCantidad);
	void VentasPorCaja();
	CQSisCorteCaja *RegistroCorte(const char *pchrPtrDenominacion,
				      const char *pchrPtrCantidad);
	void CalculoImporte();
	void MuestraCalculoImporte();
	const char *TotalCorte();
	const char *TotalEnCaja();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotRangoFechas();
	void SlotAgregaDenominacion();
	void SlotSeleccionandoCaja(int,int,int,const QPoint &);
	void SlotEliminaDenominacion();
	void SlotSeleccionandoDenominacion(int,int,int,const QPoint &);
	void SlotRegistraCorteCaja();

	void SlotActualizar();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QCorteCaja *InstanciaCorteCaja(void *,char **,void *,const char *,int);
#endif
