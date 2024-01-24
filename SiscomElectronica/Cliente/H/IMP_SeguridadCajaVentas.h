
#ifndef __IMP_SEGURIDADCAJAVENTAS_H__
#define __IMP_SEGURIDADCAJAVENTAS_H__
#include <UIC_H_SeguridadCajaVentas.h>
#include <CQSisSeguridadCajaVentas.h>
class SiscomDatCom;
class QtListViewItemCaja;
class QSeguridadCajaVentas:public SeguridadCajaVentas
{
 Q_OBJECT
public:
	QSeguridadCajaVentas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QSeguridadCajaVentas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisCajasSeguridad CQSCajasSeguridad;
private:
	void ConectaSlots();
	void IniciaVariables();

	void ConsultandoCajas();
	void MuestraCajas();
	void MuestraControlesCaja(SiscomRegistro3Lst &,
				  QtListViewItemCaja *);
	void ConsultaCajas();
	void closeEvent(QCloseEvent *);

private slots:
	void SlotActualizar();
	void SlotRegistrar();
	void SlotSeleccionoCaja(QListViewItem *);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QSeguridadCajaVentas *InstanciaSeguridadCajaVentas(void *,char **,void *,const char *,int);
#endif
