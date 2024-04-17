/****************************************************************************
** Form implementation generated from reading ui file 'UI/ReportesVentas.ui'
**
** Created: Fri Apr 12 21:25:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ReportesVentas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ReportesVentas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ReportesVentas::ReportesVentas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ReportesVentas" );
    ReportesVentasLayout = new QGridLayout( this, 1, 1, 11, 6, "ReportesVentasLayout"); 

    QTWDatos = new QTabWidget( this, "QTWDatos" );

    tab = new QWidget( QTWDatos, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout92 = new QHBoxLayout( 0, 0, 6, "layout92"); 

    layout90 = new QVBoxLayout( 0, 0, 6, "layout90"); 

    textLabel2 = new QLabel( tab, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout90->addWidget( textLabel2 );

    QTVentas = new QTable( tab, "QTVentas" );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Fecha" ) );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Importe" ) );
    QTVentas->setNumRows( 0 );
    QTVentas->setNumCols( 2 );
    QTVentas->setReadOnly( TRUE );
    layout90->addWidget( QTVentas );
    layout92->addLayout( layout90 );

    layout90_2 = new QVBoxLayout( 0, 0, 6, "layout90_2"); 

    textLabel2_2 = new QLabel( tab, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout90_2->addWidget( textLabel2_2 );

    QTOrdenes = new QTable( tab, "QTOrdenes" );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Fecha" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Num Ordenes" ) );
    QTOrdenes->setNumRows( 0 );
    QTOrdenes->setNumCols( 2 );
    QTOrdenes->setReadOnly( TRUE );
    layout90_2->addWidget( QTOrdenes );
    layout92->addLayout( layout90_2 );

    tabLayout->addMultiCellLayout( layout92, 1, 1, 0, 1 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout93 = new QVBoxLayout( 0, 0, 6, "layout93"); 

    textLabel1 = new QLabel( tab, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout93->addWidget( textLabel1 );

    QTDatos = new QTable( tab, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setMaximumSize( QSize( 32767, 200 ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout93->addWidget( QTDatos );
    layout9->addLayout( layout93 );

    layout93_2 = new QVBoxLayout( 0, 0, 6, "layout93_2"); 

    textLabel1_2 = new QLabel( tab, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout93_2->addWidget( textLabel1_2 );

    QTOrdenesE = new QTable( tab, "QTOrdenesE" );
    QTOrdenesE->setNumCols( QTOrdenesE->numCols() + 1 );
    QTOrdenesE->horizontalHeader()->setLabel( QTOrdenesE->numCols() - 1, tr( "Fecha" ) );
    QTOrdenesE->setNumCols( QTOrdenesE->numCols() + 1 );
    QTOrdenesE->horizontalHeader()->setLabel( QTOrdenesE->numCols() - 1, tr( "Escuela" ) );
    QTOrdenesE->setNumCols( QTOrdenesE->numCols() + 1 );
    QTOrdenesE->horizontalHeader()->setLabel( QTOrdenesE->numCols() - 1, tr( "Ordenes" ) );
    QTOrdenesE->setMaximumSize( QSize( 32767, 200 ) );
    QTOrdenesE->setNumRows( 0 );
    QTOrdenesE->setNumCols( 3 );
    QTOrdenesE->setReadOnly( TRUE );
    layout93_2->addWidget( QTOrdenesE );
    layout9->addLayout( layout93_2 );

    layout93_2_2 = new QVBoxLayout( 0, 0, 6, "layout93_2_2"); 

    textLabel1_2_2 = new QLabel( tab, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout93_2_2->addWidget( textLabel1_2_2 );

    QTOrdenesETotales = new QTable( tab, "QTOrdenesETotales" );
    QTOrdenesETotales->setNumCols( QTOrdenesETotales->numCols() + 1 );
    QTOrdenesETotales->horizontalHeader()->setLabel( QTOrdenesETotales->numCols() - 1, tr( "Escuela" ) );
    QTOrdenesETotales->setNumCols( QTOrdenesETotales->numCols() + 1 );
    QTOrdenesETotales->horizontalHeader()->setLabel( QTOrdenesETotales->numCols() - 1, tr( "Ordenes" ) );
    QTOrdenesETotales->setMaximumSize( QSize( 32767, 200 ) );
    QTOrdenesETotales->setNumRows( 0 );
    QTOrdenesETotales->setNumCols( 2 );
    QTOrdenesETotales->setReadOnly( TRUE );
    layout93_2_2->addWidget( QTOrdenesETotales );
    layout9->addLayout( layout93_2_2 );

    tabLayout->addMultiCellLayout( layout9, 0, 0, 0, 1 );

    QLCDNTotal = new QLCDNumber( tab, "QLCDNTotal" );
    QLCDNTotal->setFrameShape( QLCDNumber::Box );
    QLCDNTotal->setFrameShadow( QLCDNumber::Raised );
    QLCDNTotal->setNumDigits( 12 );

    tabLayout->addMultiCellWidget( QLCDNTotal, 2, 3, 1, 1 );

    QPBRefrescar = new QPushButton( tab, "QPBRefrescar" );
    QPBRefrescar->setMinimumSize( QSize( 0, 35 ) );

    tabLayout->addWidget( QPBRefrescar, 3, 0 );

    QPBFReporte = new QPushButton( tab, "QPBFReporte" );
    QPBFReporte->setMinimumSize( QSize( 0, 35 ) );

    tabLayout->addWidget( QPBFReporte, 2, 0 );
    QTWDatos->insertTab( tab, QString::fromLatin1("") );

    ReportesVentasLayout->addWidget( QTWDatos, 0, 0 );

    QPBSExpendio = new QPushButton( this, "QPBSExpendio" );
    QPBSExpendio->setMinimumSize( QSize( 0, 35 ) );

    ReportesVentasLayout->addWidget( QPBSExpendio, 1, 0 );
    languageChange();
    resize( QSize(947, 647).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReportesVentas::~ReportesVentas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReportesVentas::languageChange()
{
    setCaption( tr( "Reporte De Ventas" ) );
    textLabel2->setText( tr( "Ventas X Dia" ) );
    QTVentas->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTVentas->horizontalHeader()->setLabel( 1, tr( "Importe" ) );
    textLabel2_2->setText( tr( "Ordenes Por Dia" ) );
    QTOrdenes->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTOrdenes->horizontalHeader()->setLabel( 1, tr( "Num Ordenes" ) );
    textLabel1->setText( tr( "Detalle Ventas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    textLabel1_2->setText( tr( "Ordenes Por Escuela" ) );
    QTOrdenesE->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTOrdenesE->horizontalHeader()->setLabel( 1, tr( "Escuela" ) );
    QTOrdenesE->horizontalHeader()->setLabel( 2, tr( "Ordenes" ) );
    textLabel1_2_2->setText( tr( "Ordenes Totales Por Escuela En El Periodo" ) );
    QTOrdenesETotales->horizontalHeader()->setLabel( 0, tr( "Escuela" ) );
    QTOrdenesETotales->horizontalHeader()->setLabel( 1, tr( "Ordenes" ) );
    QPBRefrescar->setText( tr( "Actualizar \n"
"Datos" ) );
    QPBFReporte->setText( tr( "Fecha \n"
"Reporte" ) );
    QTWDatos->changeTab( tab, tr( "Ventas " ) );
    QPBSExpendio->setText( tr( "Selecciona Expendio\n"
"SISCOM" ) );
}

