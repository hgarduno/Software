/****************************************************************************
** Form implementation generated from reading ui file 'UI/ReporteVentas4.ui'
**
** Created: Thu Apr 11 21:39:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ReporteVentas4.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qtable.h>
#include <qframe.h>
#include <IMP_QControlFecha.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a ReporteVentas4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ReporteVentas4::ReporteVentas4( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ReporteVentas4" );
    ReporteVentas4Layout = new QGridLayout( this, 1, 1, 11, 6, "ReporteVentas4Layout"); 

    layout14 = new QGridLayout( 0, 1, 1, 0, 6, "layout14"); 

    QPBSeleccionarExpendio = new QPushButton( this, "QPBSeleccionarExpendio" );

    layout14->addWidget( QPBSeleccionarExpendio, 0, 0 );

    QPBConsultar = new QPushButton( this, "QPBConsultar" );

    layout14->addWidget( QPBConsultar, 0, 1 );

    ReporteVentas4Layout->addLayout( layout14, 1, 0 );

    tabWidget2 = new QTabWidget( this, "tabWidget2" );

    tab = new QWidget( tabWidget2, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout8_3 = new QVBoxLayout( 0, 0, 6, "layout8_3"); 

    textLabel2_3 = new QLabel( tab, "textLabel2_3" );
    layout8_3->addWidget( textLabel2_3 );

    QTVentasTotales = new QTable( tab, "QTVentasTotales" );
    QTVentasTotales->setNumCols( QTVentasTotales->numCols() + 1 );
    QTVentasTotales->horizontalHeader()->setLabel( QTVentasTotales->numCols() - 1, tr( "Fecha" ) );
    QTVentasTotales->setNumCols( QTVentasTotales->numCols() + 1 );
    QTVentasTotales->horizontalHeader()->setLabel( QTVentasTotales->numCols() - 1, tr( "Ordenes" ) );
    QTVentasTotales->setNumCols( QTVentasTotales->numCols() + 1 );
    QTVentasTotales->horizontalHeader()->setLabel( QTVentasTotales->numCols() - 1, tr( "Importe" ) );
    QTVentasTotales->setNumRows( 0 );
    QTVentasTotales->setNumCols( 3 );
    layout8_3->addWidget( QTVentasTotales );
    layout18->addLayout( layout8_3 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel2 = new QLabel( tab, "textLabel2" );
    layout8->addWidget( textLabel2 );

    QTVentaEscuela = new QTable( tab, "QTVentaEscuela" );
    QTVentaEscuela->setNumCols( QTVentaEscuela->numCols() + 1 );
    QTVentaEscuela->horizontalHeader()->setLabel( QTVentaEscuela->numCols() - 1, tr( "Fecha" ) );
    QTVentaEscuela->setNumCols( QTVentaEscuela->numCols() + 1 );
    QTVentaEscuela->horizontalHeader()->setLabel( QTVentaEscuela->numCols() - 1, tr( "Escuela" ) );
    QTVentaEscuela->setNumCols( QTVentaEscuela->numCols() + 1 );
    QTVentaEscuela->horizontalHeader()->setLabel( QTVentaEscuela->numCols() - 1, tr( "Ordenes" ) );
    QTVentaEscuela->setNumCols( QTVentaEscuela->numCols() + 1 );
    QTVentaEscuela->horizontalHeader()->setLabel( QTVentaEscuela->numCols() - 1, tr( "Importe" ) );
    QTVentaEscuela->setNumRows( 0 );
    QTVentaEscuela->setNumCols( 4 );
    layout8->addWidget( QTVentaEscuela );
    layout18->addLayout( layout8 );

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    textLabel2_2 = new QLabel( tab, "textLabel2_2" );
    layout8_2->addWidget( textLabel2_2 );

    QTPedidosEscuela = new QTable( tab, "QTPedidosEscuela" );
    QTPedidosEscuela->setNumCols( QTPedidosEscuela->numCols() + 1 );
    QTPedidosEscuela->horizontalHeader()->setLabel( QTPedidosEscuela->numCols() - 1, tr( "Fecha" ) );
    QTPedidosEscuela->setNumCols( QTPedidosEscuela->numCols() + 1 );
    QTPedidosEscuela->horizontalHeader()->setLabel( QTPedidosEscuela->numCols() - 1, tr( "Escuela" ) );
    QTPedidosEscuela->setNumCols( QTPedidosEscuela->numCols() + 1 );
    QTPedidosEscuela->horizontalHeader()->setLabel( QTPedidosEscuela->numCols() - 1, tr( "Ordenes" ) );
    QTPedidosEscuela->setNumCols( QTPedidosEscuela->numCols() + 1 );
    QTPedidosEscuela->horizontalHeader()->setLabel( QTPedidosEscuela->numCols() - 1, tr( "Importe" ) );
    QTPedidosEscuela->setNumRows( 0 );
    QTPedidosEscuela->setNumCols( 4 );
    layout8_2->addWidget( QTPedidosEscuela );
    layout18->addLayout( layout8_2 );

    tabLayout->addLayout( layout18, 1, 0 );

    frame3 = new QFrame( tab, "frame3" );
    frame3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, frame3->sizePolicy().hasHeightForWidth() ) );
    frame3->setFrameShape( QFrame::StyledPanel );
    frame3->setFrameShadow( QFrame::Raised );
    frame3Layout = new QGridLayout( frame3, 1, 1, 11, 6, "frame3Layout"); 

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel3 = new QLabel( frame3, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel3 );

    QCtrFechaInicio = new CQControlFecha( frame3, "QCtrFechaInicio" );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( QCtrFechaInicio );
    layout12->addLayout( layout10 );

    layout10_2 = new QVBoxLayout( 0, 0, 6, "layout10_2"); 

    textLabel3_2 = new QLabel( frame3, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout10_2->addWidget( textLabel3_2 );

    QCtrFechaFin = new CQControlFecha( frame3, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout10_2->addWidget( QCtrFechaFin );
    layout12->addLayout( layout10_2 );
    layout13->addLayout( layout12 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout13->addItem( spacer1 );
    layout23->addLayout( layout13 );

    layout30 = new QHBoxLayout( 0, 0, 6, "layout30"); 

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel1 = new QLabel( frame3, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( textLabel1 );

    QLCDNVentasTotales = new QLCDNumber( frame3, "QLCDNVentasTotales" );
    QLCDNVentasTotales->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLCDNVentasTotales->sizePolicy().hasHeightForWidth() ) );
    QLCDNVentasTotales->setNumDigits( 9 );
    layout4->addWidget( QLCDNVentasTotales );
    layout30->addLayout( layout4 );

    layout4_2 = new QVBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel1_2 = new QLabel( frame3, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( textLabel1_2 );

    QLCDNVentasApartados = new QLCDNumber( frame3, "QLCDNVentasApartados" );
    QLCDNVentasApartados->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLCDNVentasApartados->sizePolicy().hasHeightForWidth() ) );
    QLCDNVentasApartados->setNumDigits( 9 );
    layout4_2->addWidget( QLCDNVentasApartados );
    layout30->addLayout( layout4_2 );

    layout4_2_2 = new QVBoxLayout( 0, 0, 6, "layout4_2_2"); 

    textLabel1_2_2 = new QLabel( frame3, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout4_2_2->addWidget( textLabel1_2_2 );

    QLCDNVentasPedidos = new QLCDNumber( frame3, "QLCDNVentasPedidos" );
    QLCDNVentasPedidos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLCDNVentasPedidos->sizePolicy().hasHeightForWidth() ) );
    QLCDNVentasPedidos->setNumDigits( 9 );
    layout4_2_2->addWidget( QLCDNVentasPedidos );
    layout30->addLayout( layout4_2_2 );

    layout4_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout4_2_2_2"); 

    textLabel1_2_2_2 = new QLabel( frame3, "textLabel1_2_2_2" );
    textLabel1_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout4_2_2_2->addWidget( textLabel1_2_2_2 );

    lCDNumber1_2_2_2 = new QLCDNumber( frame3, "lCDNumber1_2_2_2" );
    lCDNumber1_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lCDNumber1_2_2_2->sizePolicy().hasHeightForWidth() ) );
    lCDNumber1_2_2_2->setNumDigits( 9 );
    layout4_2_2_2->addWidget( lCDNumber1_2_2_2 );
    layout30->addLayout( layout4_2_2_2 );
    layout23->addLayout( layout30 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    QTTotales = new QTable( frame3, "QTTotales" );
    QTTotales->setNumCols( QTTotales->numCols() + 1 );
    QTTotales->horizontalHeader()->setLabel( QTTotales->numCols() - 1, tr( "Fecha" ) );
    QTTotales->setNumCols( QTTotales->numCols() + 1 );
    QTTotales->horizontalHeader()->setLabel( QTTotales->numCols() - 1, tr( "Escuela" ) );
    QTTotales->setNumCols( QTTotales->numCols() + 1 );
    QTTotales->horizontalHeader()->setLabel( QTTotales->numCols() - 1, tr( "Ordenes" ) );
    QTTotales->setNumCols( QTTotales->numCols() + 1 );
    QTTotales->horizontalHeader()->setLabel( QTTotales->numCols() - 1, tr( "Importe" ) );
    QTTotales->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTTotales->sizePolicy().hasHeightForWidth() ) );
    QTTotales->setNumRows( 0 );
    QTTotales->setNumCols( 4 );
    layout22->addWidget( QTTotales );

    QTMaterialEscuela = new QTable( frame3, "QTMaterialEscuela" );
    QTMaterialEscuela->setNumCols( QTMaterialEscuela->numCols() + 1 );
    QTMaterialEscuela->horizontalHeader()->setLabel( QTMaterialEscuela->numCols() - 1, tr( "Fecha" ) );
    QTMaterialEscuela->setNumCols( QTMaterialEscuela->numCols() + 1 );
    QTMaterialEscuela->horizontalHeader()->setLabel( QTMaterialEscuela->numCols() - 1, tr( "Escuela" ) );
    QTMaterialEscuela->setNumCols( QTMaterialEscuela->numCols() + 1 );
    QTMaterialEscuela->horizontalHeader()->setLabel( QTMaterialEscuela->numCols() - 1, tr( "Producto" ) );
    QTMaterialEscuela->setNumCols( QTMaterialEscuela->numCols() + 1 );
    QTMaterialEscuela->horizontalHeader()->setLabel( QTMaterialEscuela->numCols() - 1, tr( "Cantidad" ) );
    QTMaterialEscuela->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTMaterialEscuela->sizePolicy().hasHeightForWidth() ) );
    QTMaterialEscuela->setNumRows( 0 );
    QTMaterialEscuela->setNumCols( 4 );
    layout22->addWidget( QTMaterialEscuela );
    layout23->addLayout( layout22 );
    layout25->addLayout( layout23 );

    layout4_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout4_2_2_2_2"); 

    textLabel1_2_2_2_2 = new QLabel( frame3, "textLabel1_2_2_2_2" );
    textLabel1_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout4_2_2_2_2->addWidget( textLabel1_2_2_2_2 );

    QLCDNTotal = new QLCDNumber( frame3, "QLCDNTotal" );
    QLCDNTotal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLCDNTotal->sizePolicy().hasHeightForWidth() ) );
    QLCDNTotal->setNumDigits( 10 );
    layout4_2_2_2_2->addWidget( QLCDNTotal );
    layout25->addLayout( layout4_2_2_2_2 );

    frame3Layout->addLayout( layout25, 0, 0 );

    tabLayout->addWidget( frame3, 0, 0 );
    tabWidget2->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget2, "tab_2" );
    tabWidget2->insertTab( tab_2, QString::fromLatin1("") );

    ReporteVentas4Layout->addWidget( tabWidget2, 0, 0 );
    languageChange();
    resize( QSize(1052, 632).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReporteVentas4::~ReporteVentas4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReporteVentas4::languageChange()
{
    setCaption( tr( "Reporte Ventas" ) );
    QPBSeleccionarExpendio->setText( tr( "Seleccionar Exependio" ) );
    QPBConsultar->setText( tr( "&Consultar" ) );
    QPBConsultar->setAccel( QKeySequence( tr( "Alt+C" ) ) );
    textLabel2_3->setText( tr( "Total Por Fecha" ) );
    QTVentasTotales->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTVentasTotales->horizontalHeader()->setLabel( 1, tr( "Ordenes" ) );
    QTVentasTotales->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    textLabel2->setText( tr( "Ordenes Por Escuela" ) );
    QTVentaEscuela->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTVentaEscuela->horizontalHeader()->setLabel( 1, tr( "Escuela" ) );
    QTVentaEscuela->horizontalHeader()->setLabel( 2, tr( "Ordenes" ) );
    QTVentaEscuela->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    textLabel2_2->setText( tr( "Pedidos Por Escuela" ) );
    QTPedidosEscuela->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTPedidosEscuela->horizontalHeader()->setLabel( 1, tr( "Escuela" ) );
    QTPedidosEscuela->horizontalHeader()->setLabel( 2, tr( "Ordenes" ) );
    QTPedidosEscuela->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    textLabel3->setText( tr( "Fecha Inicio" ) );
    textLabel3_2->setText( tr( "Fecha Fin" ) );
    textLabel1->setText( tr( "Importe Ventas" ) );
    textLabel1_2->setText( tr( "Importe Apartados" ) );
    textLabel1_2_2->setText( tr( "Importe de Pedidos" ) );
    textLabel1_2_2_2->setText( tr( "Cancelaciones" ) );
    QTTotales->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTTotales->horizontalHeader()->setLabel( 1, tr( "Escuela" ) );
    QTTotales->horizontalHeader()->setLabel( 2, tr( "Ordenes" ) );
    QTTotales->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    QTMaterialEscuela->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTMaterialEscuela->horizontalHeader()->setLabel( 1, tr( "Escuela" ) );
    QTMaterialEscuela->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
    QTMaterialEscuela->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    textLabel1_2_2_2_2->setText( tr( "Total En Caja" ) );
    tabWidget2->changeTab( tab, tr( "Vista Rapida" ) );
    tabWidget2->changeTab( tab_2, tr( "Detalle Ventas" ) );
}

