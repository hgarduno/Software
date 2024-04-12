/****************************************************************************
** Form implementation generated from reading ui file 'UI/ReporteVentas.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ReporteVentas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qlcdnumber.h>
#include <qtabwidget.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

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

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    QCtrFechaIni->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaIni->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrFechaIni );
    layout6->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( textLabel1_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( QCtrFechaFin );
    layout6->addLayout( layout1_2 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout6->addItem( spacer1 );

    ReporteVentasLayout->addLayout( layout6, 0, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBEjecuta = new QPushButton( this, "QPBEjecuta" );
    QPBEjecuta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)7, 0, 0, QPBEjecuta->sizePolicy().hasHeightForWidth() ) );
    QPBEjecuta->setMinimumSize( QSize( 0, 50 ) );
    QPBEjecuta->setMaximumSize( QSize( 32767, 50 ) );
    layout4->addWidget( QPBEjecuta );

    QLCDNTotal = new QLCDNumber( this, "QLCDNTotal" );
    QLCDNTotal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)7, 0, 0, QLCDNTotal->sizePolicy().hasHeightForWidth() ) );
    QLCDNTotal->setMinimumSize( QSize( 0, 60 ) );
    QLCDNTotal->setMaximumSize( QSize( 32767, 60 ) );
    QLCDNTotal->setNumDigits( 10 );
    layout4->addWidget( QLCDNTotal );

    ReporteVentasLayout->addLayout( layout4, 2, 0 );

    tabWidget7 = new QTabWidget( this, "tabWidget7" );

    tab = new QWidget( tabWidget7, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( tab, "textLabel2" );
    layout3->addWidget( textLabel2 );

    QTDatos = new QTable( tab, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "# Ordenes" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe Total" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout3->addWidget( QTDatos );

    tabLayout->addLayout( layout3, 0, 0 );
    tabWidget7->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget7, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    QTDetalle = new QTable( tab_2, "QTDetalle" );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Clave " ) );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Descripcion" ) );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Cantidad" ) );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Precio" ) );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Importe" ) );
    QTDetalle->setNumRows( 0 );
    QTDetalle->setNumCols( 5 );
    QTDetalle->setReadOnly( TRUE );

    tabLayout_2->addWidget( QTDetalle, 0, 0 );
    tabWidget7->insertTab( tab_2, QString::fromLatin1("") );

    ReporteVentasLayout->addWidget( tabWidget7, 1, 0 );
    languageChange();
    resize( QSize(578, 490).expandedTo(minimumSizeHint()) );
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
    setCaption( tr( "Reporte De Ventas" ) );
    textLabel1->setText( tr( "Fecha De Inicio" ) );
    textLabel1_2->setText( tr( "Fecha Fin" ) );
    QPBEjecuta->setText( tr( "Ejecutar Reporte" ) );
    textLabel2->setText( tr( "Reporte Ventas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "# Ordenes" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Importe Total" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Fecha" ) );
    tabWidget7->changeTab( tab, tr( "Ordenes Vendidas" ) );
    QTDetalle->horizontalHeader()->setLabel( 0, tr( "Clave " ) );
    QTDetalle->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDetalle->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QTDetalle->horizontalHeader()->setLabel( 3, tr( "Precio" ) );
    QTDetalle->horizontalHeader()->setLabel( 4, tr( "Importe" ) );
    tabWidget7->changeTab( tab_2, tr( "Detalle De Productos" ) );
}

