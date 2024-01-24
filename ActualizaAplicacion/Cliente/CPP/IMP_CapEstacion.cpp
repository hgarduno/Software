#include <IMP_CapEstacion.h>


#include <Estaciones.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QCapEstacion::QCapEstacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : CapEstacion( parent, name, modal, fl )
{

	ConectaSlots();
	exec();
}

QCapEstacion::~QCapEstacion()
{
}

void QCapEstacion::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));

}
void QCapEstacion::S_Aceptar()
{
    AsignaEstacion();
	intBoton=1;
    done(1);
}

void QCapEstacion::S_Cancelar()
{
	intBoton=0;	
	done(1);
}
void QCapEstacion::AsignaEstacion()
{
	EEstacion=new Estacion((const char *)QLEDirIp->text(),
			       (const char *)QLEPtoCom->text(),
			       (const char *)QLEDirTrabajo->text(),
			       (const char *)QLEHome->text(),
				"",
				"");
}
Estacion *QCapEstacion::ObtenEstacion()
{
	return EEstacion;
}
int QCapEstacion::ObtenBoton()
{
	return intBoton;
}
