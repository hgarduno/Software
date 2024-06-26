/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ConsultaVentas.ui'
**
** Created: Thu Apr 11 21:07:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ConsultaVentas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ConsultaVentas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ConsultaVentas::ConsultaVentas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ConsultaVentas" );
    ConsultaVentasLayout = new QGridLayout( this, 1, 1, 11, 6, "ConsultaVentasLayout"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    layout1->addWidget( QLERFC );
    layout3->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLEFolio = new QLineEdit( this, "QLEFolio" );
    layout1_2->addWidget( QLEFolio );
    layout3->addLayout( layout1_2 );

    ConsultaVentasLayout->addLayout( layout3, 0, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBConsultaVentas = new QPushButton( this, "QPBConsultaVentas" );
    layout4->addWidget( QPBConsultaVentas );

    ConsultaVentasLayout->addLayout( layout4, 4, 0 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout5->addWidget( textLabel2 );

    QTEDatosCliente = new QTextEdit( this, "QTEDatosCliente" );
    QTEDatosCliente->setReadOnly( TRUE );
    layout5->addWidget( QTEDatosCliente );

    ConsultaVentasLayout->addLayout( layout5, 1, 0 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout7->addWidget( textLabel4 );

    QTDetalleVenta = new QTable( this, "QTDetalleVenta" );
    QTDetalleVenta->setNumCols( QTDetalleVenta->numCols() + 1 );
    QTDetalleVenta->horizontalHeader()->setLabel( QTDetalleVenta->numCols() - 1, tr( "Producto" ) );
    QTDetalleVenta->setNumCols( QTDetalleVenta->numCols() + 1 );
    QTDetalleVenta->horizontalHeader()->setLabel( QTDetalleVenta->numCols() - 1, tr( "Proveedor" ) );
    QTDetalleVenta->setNumCols( QTDetalleVenta->numCols() + 1 );
    QTDetalleVenta->horizontalHeader()->setLabel( QTDetalleVenta->numCols() - 1, tr( "Importe" ) );
    QTDetalleVenta->setNumRows( 0 );
    QTDetalleVenta->setNumCols( 3 );
    layout7->addWidget( QTDetalleVenta );

    ConsultaVentasLayout->addLayout( layout7, 3, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout6->addWidget( textLabel3 );

    QTVentas = new QTable( this, "QTVentas" );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Fecha" ) );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Folio" ) );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Tipo Venta" ) );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Plazo" ) );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Financiadora" ) );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Vencimiento" ) );
    QTVentas->setNumCols( QTVentas->numCols() + 1 );
    QTVentas->horizontalHeader()->setLabel( QTVentas->numCols() - 1, tr( "Importe" ) );
    QTVentas->setNumRows( 0 );
    QTVentas->setNumCols( 7 );
    QTVentas->setReadOnly( TRUE );
    layout6->addWidget( QTVentas );

    ConsultaVentasLayout->addLayout( layout6, 2, 0 );
    languageChange();
    resize( QSize(776, 545).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ConsultaVentas::~ConsultaVentas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ConsultaVentas::languageChange()
{
    setCaption( tr( "Consulta Ventas" ) );
    textLabel1->setText( tr( "RFC" ) );
    textLabel1_2->setText( tr( "Folio Factura" ) );
    QPBConsultaVentas->setText( tr( "Consulta Ventas" ) );
    textLabel2->setText( tr( "Datos Cliente" ) );
    textLabel4->setText( tr( "Detalle Venta" ) );
    QTDetalleVenta->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDetalleVenta->horizontalHeader()->setLabel( 1, tr( "Proveedor" ) );
    QTDetalleVenta->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    textLabel3->setText( tr( "Ventas Cliente" ) );
    QTVentas->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTVentas->horizontalHeader()->setLabel( 1, tr( "Folio" ) );
    QTVentas->horizontalHeader()->setLabel( 2, tr( "Tipo Venta" ) );
    QTVentas->horizontalHeader()->setLabel( 3, tr( "Plazo" ) );
    QTVentas->horizontalHeader()->setLabel( 4, tr( "Financiadora" ) );
    QTVentas->horizontalHeader()->setLabel( 5, tr( "Vencimiento" ) );
    QTVentas->horizontalHeader()->setLabel( 6, tr( "Importe" ) );
}

