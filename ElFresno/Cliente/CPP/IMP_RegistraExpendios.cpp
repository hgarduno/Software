#include <IMP_RegistraExpendios.h>
#include <CQSiscomCom.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
QRegistraExpendios *InstanciaRegistraExpendios(void *pCSisDatCom,
						     void *pQWParent,
						     const char *pchrPtrName,
						     int pintWFlags)
{
	return new QRegistraExpendios((CSISCOMDatComunicaciones *)pCSisDatCom,
					 (QWidget *)pQWParent,
					 pchrPtrName,
					 pintWFlags);
}

QRegistraExpendios::QRegistraExpendios(CSISCOMDatComunicaciones *pCSisDatCom,
				QWidget* parent, const char* name, WFlags fl )
    : QManejadorProveedores(pCSisDatCom, parent, name, fl ),
    CSisDatCom(pCSisDatCom)
{
}

QRegistraExpendios::~QRegistraExpendios()
{
}
