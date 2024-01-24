
#ifndef __IMP_RANGOPORCENTAJES3_H__
#define __IMP_RANGOPORCENTAJES3_H__
#include <UIC_H_RangoPorcentajes3.h>
class QRangoPorcentajes3:public RangoPorcentajes3
{
 Q_OBJECT
public:
	QRangoPorcentajes3(
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=0,
	    WFlags pWFlags=0);
	~QRangoPorcentajes3();
	int OpcionSeleccionada(char *,char *);
private:
	char chrArrPAlto[12];
	char chrArrPBajo[12];
	int intRegreso;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotPasaFocoAlto();
	void SlotPasaFocoAceptar();
	void SlotAceptar();
	void SlotCancelar();
};
#endif
