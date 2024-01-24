
#ifndef __IMP_CAPTURAPAGO_H__
#define __IMP_CAPTURAPAGO_H__
#include <UIC_H_CapturaPago.h>
class SiscomDatCom;
class QCapturaPago:public CapturaPago
{
 Q_OBJECT
public:
	QCapturaPago(SiscomDatCom *,
	    const char *pchrPtrImporte,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaPago();
	const char *Cambio();
	void Recibi(char *pchrPtrRecibi);
	int ImporteValido();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrImporte;
	const char *chrPtrCambio;
	const char *chrPtrRecibi;
	int intImporteValido;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void reject();
private slots:

	void SlotAceptar();
	void SlotCancelar();
	void SlotCalculaCambio();
};
#endif
