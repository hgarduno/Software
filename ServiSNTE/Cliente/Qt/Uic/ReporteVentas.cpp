/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ReporteVentas.ui'
**
** Created: Sat Jan 27 16:37:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ReporteVentas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlTipoVentas.h"

/*
 *  Constructs a ReporteVentas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ReporteVentas::ReporteVentas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ReporteVentas" );
    ReporteVentasLayout = new QGridLayout( this, 1, 1, 11, 6, "ReporteVentasLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLERangoFechas = new QLineEdit( this, "QLERangoFechas" );
    layout1->addWidget( QLERangoFechas );
    layout4->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    QCtrTiendas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrTiendas->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCtrTiendas );
    layout4->addLayout( layout2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout3->addWidget( textLabel3 );

    QCtrTipoVentas = new QCtrlTipoVentas( this, "QCtrTipoVentas" );
    QCtrTipoVentas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrTipoVentas->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrTipoVentas );
    layout4->addLayout( layout3 );

    ReporteVentasLayout->addLayout( layout4, 0, 0 );

    textLabel4 = new QLabel( this, "textLabel4" );

    ReporteVentasLayout->addWidget( textLabel4, 1, 0 );

    QTVentas = new QTable( this, "QTVentas" );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Fecha" ) );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Total Ventas" ) );
    QTVentas->setNumRows( 0 );
    QTVentas->setNumCols( 2 );

    ReporteVentasLayout->addWidget( QTVentas, 2, 0 );

    QPBConsultando = new QPushButton( this, "QPBConsultando" );

    ReporteVentasLayout->addWidget( QPBConsultando, 3, 0 );
    languageChange();
    resize( QSize(727, 513).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReporteVentas::~ReporteVentas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReporteVentas::languageChange()
{
    setCaption( tr( "Ventas Tienda" ) );
    textLabel1->setText( tr( "Fechas" ) );
    QLERangoFechas->setInputMask( tr( "0000-00-00 0000-00-00; " ) );
    textLabel2->setText( tr( "Tienda" ) );
    textLabel3->setText( tr( "Tipo Venta" ) );
    textLabel4->setText( tr( "textLabel4" ) );
    QTVentas->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTVentas->horizontalHeader()->setLabel( 1, tr( "Total Ventas" ) );
    QPBConsultando->setText( tr( "Consulta Ventas" ) );
}

