#include <IMP_RegistroExpendios.h>


#include <SISCOMComunicaciones++.h>
#include <IniciaExpendio.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>


QRegistroExpendios *InstanciaRegistroExpendios(void *pSisDatCom,
					       char **pchrPtrArgumentos,
					       void *pQWParent,
					       const char *pchrPtrName,
					       int pintWFlags)
{

	return new QRegistroExpendios((SiscomDatCom *)pSisDatCom,
				      pchrPtrArgumentos,
				      (QWidget *)pQWParent,
				      pchrPtrName,
				      pintWFlags);
}
QRegistroExpendios::QRegistroExpendios(SiscomDatCom *pSisDatCom,
				       char **pchrPtrArgumentos,
					QWidget* parent, 
					const char* name,
					WFlags fl )
    : RegistroExpendios( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos)
{
	ConectaSlots();
}

QRegistroExpendios::~QRegistroExpendios()
{
}
void QRegistroExpendios::ConectaSlots()
{
	connect(QPBIniciaExpendio,
		SIGNAL(clicked()),
		SLOT(S_IniciaExpendio()));
}

void QRegistroExpendios::S_IniciaExpendio()
{
OpIniciaExpendios lOpIniExpendio(SisDatCom);

	lOpIniExpendio.IniciaBaseDatos(chrPtrArgumentos[0]);	

}
void QRegistroExpendios::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
