#ifndef __QTCONTABILIDADSISCOM_H__
#define __QTCONTABILIDADSISCOM_H__
#include <UIC_H_ContabilidadSiscom.h>


class QtContabilidadSiscom:public ContabilidadSiscom
{
Q_OBJECT
public:
	QtContabilidadSiscom(QWidget *,const char *,WFlags );
	~QtContabilidadSiscom();
	virtual void  OrdenesPagoElectronico();
	virtual void  FacturaPublicoEnGeneralPE();
private:
	void ConectaSlots();
	void IniciaVariables();

private slots:
	void SlotOrdenesPagoElectronico();
	void SlotFacturaPGPE();

};


#endif
