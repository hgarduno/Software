#ifndef __QTIMPINVENTARIOENCURSO_H__
#define __QTIMPINVENTARIOENCURSO_H__

#include <InventarioEnCurso.h>

class QtImpInventarioEnCurso:public InventarioEnCurso
{
Q_OBJECT
public:
	QtImpInventarioEnCurso(QWidget *parent=0,
                          const char *name=0,
                          bool modal=false,
                          WFlags flags=0);
	int Aceptar();
private:
	int pintAceptar;
	void ConectaSlots();
	void reject();
private slots:
	void SlotAceptar();
	void SlotCancelar();	
};

#endif

