
#ifndef __IMP_AVISONOALCANZA4_H__
#define __IMP_AVISONOALCANZA4_H__
#include <UIC_H_AvisoNoAlcanza4.h>

class zProductoCotizar;

class QAvisoNoAlcanza4:public AvisoNoAlcanza4
{
 Q_OBJECT
public:
	QAvisoNoAlcanza4(
	    zProductoCotizar *pzProdCotizar,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QAvisoNoAlcanza4();
	int SeElimino();
private:
	zProductoCotizar *zProdCotizar;
	void Muestra();
	void CambiaCantidad(char *pchrPtrCantidad);
	void CambiandoCantidad();
	void ConectaSlots();
	void IniciaVariables();
	void VendeLoQueHay();
	void reject();

private:
	int intSeElimino;
private:
private slots:
	void SlotCambiaCantidad();
	void SlotEliminar();
	void SlotVende();
};
#endif
