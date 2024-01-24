#ifndef __QTPUNTOSENTREGA_H__
#define __QTPUNTOSENTREGA_H__
#include <UIC_H_PuntosEntrega.h>




class QtPuntosEntrega:public PuntosEntrega
{
Q_OBJECT
public:
	QtPuntosEntrega(QWidget *pQWParent,const char *pchrPtrName,WFlags );

	void IniciaVariables();
	void ConectaSlots();
	void ConectaEdits();
	void ConectaBotones();
private:
private slots:
	void SlotFocoACalle();
	void SlotFocoANumExterior();
	void SlotFocoANumInterior();
	void SlotFocoAMunicipio();
	void SlotFocoAColonia();
	void SlotFocoACP();
	void SlotFocoAEstado();
	void SlotFocoAReferencias();

};

#endif
