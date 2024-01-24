
#ifndef __IMP_CAPTURACONTACTOE_H__
#define __IMP_CAPTURACONTACTOE_H__
#include <UIC_H_CapturaContactoE.h>
class SiscomDatCom;
class CQSisContactoE;
class QCapturaContactoE:public CapturaContactoE
{
 Q_OBJECT
public:
	QCapturaContactoE(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=0,
	    WFlags pWFlags=0);
	~QCapturaContactoE();
	CQSisContactoE *ContactoE();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotPasaFocoNombre();
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoDescripcion();
	void SlotAceptar();
};
#endif
