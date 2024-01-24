#include <IMP_FechasCorteExpendio.h>
#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QFechasCorteExpendio::QFechasCorteExpendio(CSISCOMDatComunicaciones *pSisDatCom,
					   QWidget* parent,
					   const char* name,
					   bool modal, 
					   WFlags fl )
    : FechasCorteExpendio( parent, name, modal, fl )
{
	exec();
}
QFechasCorteExpendio::~QFechasCorteExpendio()
{
}

