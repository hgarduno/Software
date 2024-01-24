#include <IMP_CargaPedido.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

QCargaPedido *InstanciaCargaPedido(void *pCSisDatCom,
				    void *pQWParent,
				    const char *pchrPtrName,
				    int pintWFlags)
{
	return new QCargaPedido((CSISCOMDatComunicaciones *)pCSisDatCom,
			         (QWidget *)pQWParent,
				 pchrPtrName,
				 pintWFlags);
}
QCargaPedido::QCargaPedido(CSISCOMDatComunicaciones *pCSisDatCom,
			   QWidget* parent, const char* name, WFlags fl )
    : CargaPedido( parent, name, fl ),
    CSisDatCom(pCSisDatCom)
{
}

QCargaPedido::~QCargaPedido()
{
}

