
#ifndef __IMP_CAMBIAEDOCONTROLCAJA_H__
#define __IMP_CAMBIAEDOCONTROLCAJA_H__
#include <UIC_H_CambiaEdoControlCaja.h>
class SiscomDatCom;
class QtListViewItemEstadoControl;
class QCambiaEdoControlCaja:public CambiaEdoControlCaja
{
 Q_OBJECT
public:
	QCambiaEdoControlCaja(
	    QtListViewItemEstadoControl *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCambiaEdoControlCaja();
	int Opcion();
private:
	QtListViewItemEstadoControl *QtLstViewItemEdoControl;
	int intOpcion;
	const char *chrPtrEstadoInicial;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDatosControl();
	void AsignaEstadoControl(int);
	void AsignaEstadoControl(const char *);
	void closeEvent(QCloseEvent *);
	void ObtenEstadoInicial();
private slots:
	void SlotAceptar();
	void SlotCancelar();
	void SlotEstado(int);
};
#endif
