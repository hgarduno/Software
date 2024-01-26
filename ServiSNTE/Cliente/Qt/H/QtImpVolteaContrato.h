#ifndef __QTIMPVOLTEACONTRATO_H__
#define __QTIMPVOLTEACONTRATO_H__

#include <VolteaContrato.h>


class QtImprimeBeneficiosIntegrales;
class zContratoBeneficios;
class QtImpVolteaContrato:public VolteaContrato
{
Q_OBJECT
public:
	QtImpVolteaContrato(QtImprimeBeneficiosIntegrales *pQtImpBenIntegrales,
			    zContratoBeneficios *pzConBeneficios,
			     QWidget *pQWParent=0,
			    const char *pchrPtrName=0,
			    bool pbModal=0,
			    WFlags pWFlags=0);
	int Ejecuta();
private:
	void ConectaSlots();
	void IniciaVariables();
private:
	QtImprimeBeneficiosIntegrales *QtImpBenIntegrales;
	zContratoBeneficios *zConBeneficios;
	void reject();
private slots:
	void SlotSeVolteoElContrato();
	void SlotImprimir();
	void SlotTerminar();
};

#endif
