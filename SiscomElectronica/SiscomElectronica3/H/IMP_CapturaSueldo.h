
#ifndef __IMP_CAPTURASUELDO_H__
#define __IMP_CAPTURASUELDO_H__
#include <UIC_H_CapturaSueldo.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisSueldo;
class QCapturaSueldo:public CapturaSueldo
{
 Q_OBJECT
public:
	QCapturaSueldo(
	    SiscomRegistro3 *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaSueldo();
	CQSisSueldo *Sueldo();
	int Opcion();
private:
	SiscomRegistro3 *SReg3Empleado;
	int intOpcion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotPasaFocoRegistra();
	void SlotRegistra();
	void SlotCancela();
};
#endif
