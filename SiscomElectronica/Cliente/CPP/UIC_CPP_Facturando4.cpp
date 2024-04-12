/****************************************************************************
** Form implementation generated from reading ui file 'UI/Facturando4.ui'
**
** Created: Thu Apr 11 21:39:56 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Facturando4.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Facturando4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Facturando4::Facturando4( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Facturando4" );
    Facturando4Layout = new QGridLayout( this, 1, 1, 11, 6, "Facturando4Layout"); 

    QPBOrdenesFecha = new QPushButton( this, "QPBOrdenesFecha" );

    Facturando4Layout->addWidget( QPBOrdenesFecha, 3, 0 );

    QPBDatosFacturacion = new QPushButton( this, "QPBDatosFacturacion" );
    QPBDatosFacturacion->setEnabled( FALSE );

    Facturando4Layout->addWidget( QPBDatosFacturacion, 3, 1 );

    QPBRealizaFactura = new QPushButton( this, "QPBRealizaFactura" );
    QPBRealizaFactura->setEnabled( FALSE );

    Facturando4Layout->addWidget( QPBRealizaFactura, 3, 2 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QTFactura = new QTable( this, "QTFactura" );
    QTFactura->setNumCols( QTFactura->numCols() + 1 );
    QTFactura->horizontalHeader()->setLabel( QTFactura->numCols() - 1, tr( "Producto" ) );
    QTFactura->setNumCols( QTFactura->numCols() + 1 );
    QTFactura->horizontalHeader()->setLabel( QTFactura->numCols() - 1, tr( "Cantidad" ) );
    QTFactura->setNumCols( QTFactura->numCols() + 1 );
    QTFactura->horizontalHeader()->setLabel( QTFactura->numCols() - 1, tr( "Precio" ) );
    QTFactura->setNumCols( QTFactura->numCols() + 1 );
    QTFactura->horizontalHeader()->setLabel( QTFactura->numCols() - 1, tr( "Importe" ) );
    QTFactura->setNumRows( 0 );
    QTFactura->setNumCols( 4 );
    layout2->addWidget( QTFactura );

    Facturando4Layout->addMultiCellLayout( layout2, 1, 1, 0, 2 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout15_2_2 = new QVBoxLayout( 0, 0, 6, "layout15_2_2"); 

    textLabel5_2_2 = new QLabel( this, "textLabel5_2_2" );
    textLabel5_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2_2->sizePolicy().hasHeightForWidth() ) );
    layout15_2_2->addWidget( textLabel5_2_2 );

    QLCDNImporte = new QLCDNumber( this, "QLCDNImporte" );
    QLCDNImporte->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, QLCDNImporte->sizePolicy().hasHeightForWidth() ) );
    QLCDNImporte->setSmallDecimalPoint( TRUE );
    QLCDNImporte->setNumDigits( 8 );
    layout15_2_2->addWidget( QLCDNImporte );
    layout18->addLayout( layout15_2_2 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout15->addWidget( textLabel5 );

    QLCDNTotal = new QLCDNumber( this, "QLCDNTotal" );
    QLCDNTotal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, QLCDNTotal->sizePolicy().hasHeightForWidth() ) );
    QLCDNTotal->setSmallDecimalPoint( TRUE );
    QLCDNTotal->setNumDigits( 8 );
    layout15->addWidget( QLCDNTotal );
    layout18->addLayout( layout15 );

    layout15_2 = new QVBoxLayout( 0, 0, 6, "layout15_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout15_2->addWidget( textLabel5_2 );

    QLCDNIva = new QLCDNumber( this, "QLCDNIva" );
    QLCDNIva->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, QLCDNIva->sizePolicy().hasHeightForWidth() ) );
    QLCDNIva->setSmallDecimalPoint( TRUE );
    QLCDNIva->setNumDigits( 8 );
    layout15_2->addWidget( QLCDNIva );
    layout18->addLayout( layout15_2 );

    Facturando4Layout->addMultiCellLayout( layout18, 2, 2, 0, 2 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( textLabel4 );

    QTEDatos = new QTextEdit( this, "QTEDatos" );
    QTEDatos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QTEDatos->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( QTEDatos );

    Facturando4Layout->addMultiCellLayout( layout6, 0, 0, 0, 2 );
    languageChange();
    resize( QSize(488, 459).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Facturando4::~Facturando4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Facturando4::languageChange()
{
    setCaption( tr( "Sistema de Facturacion" ) );
    QPBOrdenesFecha->setText( tr( "Ordenes Por Fecha" ) );
    QPBDatosFacturacion->setText( tr( "Datos Facturacion" ) );
    QPBRealizaFactura->setText( tr( "Realiza Factura" ) );
    textLabel1->setText( tr( "Detalle Factura" ) );
    QTFactura->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTFactura->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTFactura->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTFactura->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    textLabel5_2_2->setText( tr( "Importe" ) );
    textLabel5->setText( tr( "Total" ) );
    textLabel5_2->setText( tr( "IVA" ) );
    textLabel4->setText( tr( "Datos Facturacion" ) );
}

