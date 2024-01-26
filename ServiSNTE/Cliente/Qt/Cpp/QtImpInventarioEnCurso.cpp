#include <QtImpInventarioEnCurso.h>
#include <qpushbutton.h>

QtImpInventarioEnCurso::QtImpInventarioEnCurso(QWidget *parent,
					const char *name,
					bool modal,
					WFlags flags):
					InventarioEnCurso(parent,name,modal,flags)
{
	ConectaSlots();
    exec();
}
void QtImpInventarioEnCurso::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
}

void QtImpInventarioEnCurso::SlotAceptar()
{
	pintAceptar=1;
    done(1);
}
void QtImpInventarioEnCurso::SlotCancelar()
{
	pintAceptar=0;
    done(1);
}
void QtImpInventarioEnCurso::reject()
{

}

int QtImpInventarioEnCurso::Aceptar()
{
	return pintAceptar;
}

