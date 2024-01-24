/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenElectronica.ui'
**
** Created: Thu Dec 21 12:53:28 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenElectronica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qtabwidget.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a OrdenElectronica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
OrdenElectronica::OrdenElectronica( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "OrdenElectronica" );
    OrdenElectronicaLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenElectronicaLayout"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "# Juegos" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Total" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descuento" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 6 );
    QTDatos->setReadOnly( TRUE );

    OrdenElectronicaLayout->addWidget( QTDatos, 0, 0 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    tabWidget6 = new QTabWidget( this, "tabWidget6" );
    tabWidget6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, tabWidget6->sizePolicy().hasHeightForWidth() ) );

    tab = new QWidget( tabWidget6, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 0, 0, "tabLayout"); 

    layout6 = new QVBoxLayout( 0, 0, 0, "layout6"); 

    QPBRealizaVenta = new QPushButton( tab, "QPBRealizaVenta" );
    QPBRealizaVenta->setMinimumSize( QSize( 0, 15 ) );
    QPBRealizaVenta->setMaximumSize( QSize( 32767, 20 ) );
    layout6->addWidget( QPBRealizaVenta );

    QPBOrdenCaja = new QPushButton( tab, "QPBOrdenCaja" );
    QPBOrdenCaja->setEnabled( TRUE );
    QPBOrdenCaja->setMinimumSize( QSize( 0, 15 ) );
    QPBOrdenCaja->setMaximumSize( QSize( 32767, 20 ) );
    layout6->addWidget( QPBOrdenCaja );

    QPBImprimeTicket = new QPushButton( tab, "QPBImprimeTicket" );
    QPBImprimeTicket->setMinimumSize( QSize( 0, 15 ) );
    QPBImprimeTicket->setMaximumSize( QSize( 32767, 20 ) );
    layout6->addWidget( QPBImprimeTicket );

    tabLayout->addLayout( layout6, 0, 0 );
    tabWidget6->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget6, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout47 = new QVBoxLayout( 0, 0, 0, "layout47"); 

    QPBImprimeCotizacion = new QPushButton( tab_2, "QPBImprimeCotizacion" );
    QPBImprimeCotizacion->setMinimumSize( QSize( 0, 15 ) );
    QPBImprimeCotizacion->setMaximumSize( QSize( 32767, 20 ) );
    layout47->addWidget( QPBImprimeCotizacion );

    QPBRCotizacion = new QPushButton( tab_2, "QPBRCotizacion" );
    QPBRCotizacion->setMinimumSize( QSize( 0, 15 ) );
    QPBRCotizacion->setMaximumSize( QSize( 32767, 20 ) );
    layout47->addWidget( QPBRCotizacion );

    tabLayout_2->addLayout( layout47, 0, 0 );
    tabWidget6->insertTab( tab_2, QString::fromLatin1("") );

    TabPage = new QWidget( tabWidget6, "TabPage" );
    TabPageLayout = new QGridLayout( TabPage, 1, 1, 11, 6, "TabPageLayout"); 

    layout48 = new QVBoxLayout( 0, 0, 0, "layout48"); 

    QPBVOrden = new QPushButton( TabPage, "QPBVOrden" );
    QPBVOrden->setMinimumSize( QSize( 0, 15 ) );
    QPBVOrden->setMaximumSize( QSize( 32767, 20 ) );
    layout48->addWidget( QPBVOrden );

    QPBVCotizacion = new QPushButton( TabPage, "QPBVCotizacion" );
    QPBVCotizacion->setMinimumSize( QSize( 0, 15 ) );
    QPBVCotizacion->setMaximumSize( QSize( 32767, 20 ) );
    layout48->addWidget( QPBVCotizacion );

    TabPageLayout->addLayout( layout48, 0, 0 );
    tabWidget6->insertTab( TabPage, QString::fromLatin1("") );
    layout7->addWidget( tabWidget6 );

    pushButton11 = new QPushButton( this, "pushButton11" );
    layout7->addWidget( pushButton11 );
    layout8->addLayout( layout7 );

    QLCNTotal = new QLCDNumber( this, "QLCNTotal" );
    QLCNTotal->setNumDigits( 8 );
    layout8->addWidget( QLCNTotal );

    OrdenElectronicaLayout->addLayout( layout8, 1, 0 );
    languageChange();
    resize( QSize(448, 504).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenElectronica::~OrdenElectronica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenElectronica::languageChange()
{
    setCaption( tr( "Form2" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "# Juegos" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Total" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Descuento" ) );
    QPBRealizaVenta->setText( tr( "Realizar Venta" ) );
    QPBOrdenCaja->setText( tr( "Orden Caja" ) );
    QPBImprimeTicket->setText( tr( "Imp. Ticket" ) );
    tabWidget6->changeTab( tab, tr( "Ventas" ) );
    QPBImprimeCotizacion->setText( tr( "Imp. Cotizacion" ) );
    QPBRCotizacion->setText( tr( "Reg. Cotizacion" ) );
    tabWidget6->changeTab( tab_2, tr( "Cotizacion" ) );
    QPBVOrden->setText( tr( "Vende Orden" ) );
    QPBVCotizacion->setText( tr( "Vende Cotizacion" ) );
    tabWidget6->changeTab( TabPage, tr( "Ordenes" ) );
    pushButton11->setText( tr( "Activa Botones" ) );
}

