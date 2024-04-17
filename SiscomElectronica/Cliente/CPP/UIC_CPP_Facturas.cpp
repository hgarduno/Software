/****************************************************************************
** Form implementation generated from reading ui file 'UI/Facturas.ui'
**
** Created: Fri Apr 12 21:26:00 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Facturas.h"

#include <qvariant.h>
#include <qtable.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Facturas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Facturas::Facturas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Facturas" );
    FacturasLayout = new QGridLayout( this, 1, 1, 11, 6, "FacturasLayout"); 

    QTFacturas = new QTable( this, "QTFacturas" );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "# Factura" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Fecha" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Proveedor" ) );
    QTFacturas->setMinimumSize( QSize( 0, 200 ) );
    QTFacturas->setMaximumSize( QSize( 32767, 200 ) );
    QTFacturas->setAcceptDrops( TRUE );
    QTFacturas->setDragAutoScroll( TRUE );
    QTFacturas->setNumRows( 0 );
    QTFacturas->setNumCols( 3 );
    QTFacturas->setReadOnly( TRUE );

    FacturasLayout->addWidget( QTFacturas, 0, 0 );

    textLabel1 = new QLabel( this, "textLabel1" );

    FacturasLayout->addWidget( textLabel1, 1, 0 );

    QTDFactura = new QTable( this, "QTDFactura" );
    QTDFactura->setNumCols( QTDFactura->numCols() + 1 );
    QTDFactura->horizontalHeader()->setLabel( QTDFactura->numCols() - 1, tr( "Producto" ) );
    QTDFactura->setNumCols( QTDFactura->numCols() + 1 );
    QTDFactura->horizontalHeader()->setLabel( QTDFactura->numCols() - 1, tr( "Precio Compra" ) );
    QTDFactura->setNumCols( QTDFactura->numCols() + 1 );
    QTDFactura->horizontalHeader()->setLabel( QTDFactura->numCols() - 1, tr( "Cantidad" ) );
    QTDFactura->setNumRows( 0 );
    QTDFactura->setNumCols( 3 );
    QTDFactura->setReadOnly( TRUE );

    FacturasLayout->addWidget( QTDFactura, 2, 0 );

    QPBFProveedor = new QPushButton( this, "QPBFProveedor" );
    QPBFProveedor->setMinimumSize( QSize( 0, 0 ) );
    QPBFProveedor->setMaximumSize( QSize( 32767, 20 ) );

    FacturasLayout->addWidget( QPBFProveedor, 4, 0 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    QPBRangoFechas = new QPushButton( this, "QPBRangoFechas" );
    QPBRangoFechas->setMinimumSize( QSize( 0, 50 ) );
    layout20->addWidget( QPBRangoFechas );

    QPBADatos = new QPushButton( this, "QPBADatos" );
    QPBADatos->setMinimumSize( QSize( 0, 50 ) );
    layout20->addWidget( QPBADatos );

    QPBANumFactura = new QPushButton( this, "QPBANumFactura" );
    QPBANumFactura->setMinimumSize( QSize( 0, 50 ) );
    layout20->addWidget( QPBANumFactura );

    QPBAnexarFactura = new QPushButton( this, "QPBAnexarFactura" );
    QPBAnexarFactura->setMinimumSize( QSize( 0, 50 ) );
    layout20->addWidget( QPBAnexarFactura );

    QPBAContabilidad = new QPushButton( this, "QPBAContabilidad" );
    QPBAContabilidad->setMinimumSize( QSize( 0, 50 ) );
    layout20->addWidget( QPBAContabilidad );

    QPBCopiar = new QPushButton( this, "QPBCopiar" );
    QPBCopiar->setMinimumSize( QSize( 0, 50 ) );
    layout20->addWidget( QPBCopiar );

    FacturasLayout->addLayout( layout20, 3, 0 );
    languageChange();
    resize( QSize(631, 561).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Facturas::~Facturas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Facturas::languageChange()
{
    setCaption( tr( "Controlador De Facturas" ) );
    QTFacturas->horizontalHeader()->setLabel( 0, tr( "# Factura" ) );
    QTFacturas->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTFacturas->horizontalHeader()->setLabel( 2, tr( "Proveedor" ) );
    textLabel1->setText( tr( "Detalle Factura" ) );
    QTDFactura->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDFactura->horizontalHeader()->setLabel( 1, tr( "Precio Compra" ) );
    QTDFactura->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QPBFProveedor->setText( tr( "Filtro Por Proveedor" ) );
    QPBRangoFechas->setText( tr( "Rango \n"
"De \n"
"Fechas" ) );
    QPBADatos->setText( tr( "Actualiza\n"
"Datos" ) );
    QPBANumFactura->setText( tr( "Actualiza\n"
"Numero De\n"
"Factura" ) );
    QPBAnexarFactura->setText( tr( "Anexa Factura\n"
"Por Numero" ) );
    QPBAContabilidad->setText( tr( "Anexar Facturas \n"
"Al Periodo Contable" ) );
    QPBCopiar->setText( tr( "Copiar" ) );
}

