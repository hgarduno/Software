#include <IMP_EsEntrenadorContacto.h>
#include<SISCOMComunicaciones++.h>
#include <qlineedit.h>
#include <qpushbutton.h>

QEsEntrenadorContacto::QEsEntrenadorContacto(
				    const char *pchrPtrNombre,
				    const char *pchrPtrAPaterno,
				    const char *pchrPtrAMaterno,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				EsEntrenadorContacto(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrNombre(pchrPtrNombre),
				chrPtrAPaterno(pchrPtrAPaterno),
				chrPtrAMaterno(pchrPtrAMaterno)
{
IniciaVariables();
ConectaSlots();
exec();
}

QEsEntrenadorContacto::~QEsEntrenadorContacto()
{

}

void QEsEntrenadorContacto::ConectaSlots()
{
	connect(QPBEsEntrenador,
		SIGNAL(clicked()),
		SLOT(SlotSiEntrenador()));
	connect(QPBNoEntrenador,
		SIGNAL(clicked()),
		SLOT(SlotNoEntrenador()));

}
void QEsEntrenadorContacto::SlotNoEntrenador()
{
	chrPtrSiEntrenador="No";
	done(1);
}
void QEsEntrenadorContacto::SlotSiEntrenador()
{
	chrPtrSiEntrenador="Si";
	done(1);
}
const char *QEsEntrenadorContacto::ObtenSiEntrenador()
{
	return chrPtrSiEntrenador;
}
void QEsEntrenadorContacto::IniciaVariables()
{
	QLENombre->setText(chrPtrNombre);
	QLEAPaterno->setText(chrPtrAPaterno);
	QLEAMaterno->setText(chrPtrAMaterno);
}
