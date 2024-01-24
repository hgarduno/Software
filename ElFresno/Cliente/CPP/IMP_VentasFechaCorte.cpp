#include <IMP_VentasFechaCorte.h>
#include <IMP_FechasCorteExpendio.h>

#include <Empresas.h>

#include <qvariant.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qpushbutton.h>
QVentasFechaCorte::QVentasFechaCorte(CSISCOMDatComunicaciones *pSisDatCom,
				     Empresa *pExpendio,
				    QWidget* parent,
				    const char* name,
				    WFlags fl )
    : VentasFechaCorte( parent, name, fl ),
    CSisDatCom(pSisDatCom),
    E_Expendio(pExpendio)
{
	ConectaSlots();
	setCaption(QString("Verificando Existencias:") +
		   pExpendio->ObtenRazonSocial());
	show();
}

QVentasFechaCorte::~QVentasFechaCorte()
{
}
void QVentasFechaCorte::ConectaSlots()
{
	connect(QPBFechaCorte,
		SIGNAL(clicked()),
		SLOT(S_FechaCorte()));
}
void QVentasFechaCorte::S_FechaCorte()
{
QFechasCorteExpendio lQFsCorte(CSisDatCom);

}
