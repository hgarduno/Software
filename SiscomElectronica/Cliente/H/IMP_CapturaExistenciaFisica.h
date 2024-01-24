
#ifndef __IMP_CAPTURAEXISTENCIAFISICA_H__
#define __IMP_CAPTURAEXISTENCIAFISICA_H__
#include <UIC_H_CapturaExistenciaFisica.h>
class SiscomDatCom;
class QCapturaExistenciaFisica:public CapturaExistenciaFisica
{
 Q_OBJECT
public:
	QCapturaExistenciaFisica(
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaExistenciaFisica();
	const char *ExistenciaFisica();
private:
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotPasaFocoAceptar();
	void SlotAceptar();
};
#endif
