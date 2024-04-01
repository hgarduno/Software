/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenesFavoritas.ui'
**
** Created: Wed Jan 31 10:48:13 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenesFavoritas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <QCtrlOrdenesFavoritas.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlOrdenesFavoritas.h"

/*
 *  Constructs a OrdenesFavoritas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
OrdenesFavoritas::OrdenesFavoritas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "OrdenesFavoritas" );
    OrdenesFavoritasLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenesFavoritasLayout"); 

    layout61 = new QVBoxLayout( 0, 0, 6, "layout61"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout61->addWidget( textLabel1 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Precio" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Importe" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 4 );
    QTProductos->setReadOnly( TRUE );
    layout61->addWidget( QTProductos );

    OrdenesFavoritasLayout->addLayout( layout61, 2, 0 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    layout11->addWidget( textLabel1_4 );

    QTEDesVenta = new QTextEdit( this, "QTEDesVenta" );
    QTEDesVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDesVenta->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( QTEDesVenta );
    layout6->addLayout( layout11 );

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout12_2->addWidget( textLabel5_2 );

    QLCDNImporte = new QLCDNumber( this, "QLCDNImporte" );
    QLCDNImporte->setMaximumSize( QSize( 32767, 150 ) );
    QLCDNImporte->setNumDigits( 10 );
    layout12_2->addWidget( QLCDNImporte );
    layout6->addLayout( layout12_2 );

    OrdenesFavoritasLayout->addLayout( layout6, 1, 0 );

    layout24 = new QHBoxLayout( 0, 0, 6, "layout24"); 

    QPBSelOrden = new QPushButton( this, "QPBSelOrden" );
    layout24->addWidget( QPBSelOrden );

    QPBAsignaOrdenFavorita = new QPushButton( this, "QPBAsignaOrdenFavorita" );
    QPBAsignaOrdenFavorita->setEnabled( FALSE );
    layout24->addWidget( QPBAsignaOrdenFavorita );

    QPBAgregarOrdenFavorita = new QPushButton( this, "QPBAgregarOrdenFavorita" );
    layout24->addWidget( QPBAgregarOrdenFavorita );

    QPBEliminaOrden = new QPushButton( this, "QPBEliminaOrden" );
    layout24->addWidget( QPBEliminaOrden );

    QPBRegistraFavoritas = new QPushButton( this, "QPBRegistraFavoritas" );
    QPBRegistraFavoritas->setEnabled( TRUE );
    layout24->addWidget( QPBRegistraFavoritas );

    OrdenesFavoritasLayout->addLayout( layout24, 3, 0 );

    QCtrOrdenesFavoritas = new QCtrlOrdenesFavoritas( this, "QCtrOrdenesFavoritas" );
    QCtrOrdenesFavoritas->setMinimumSize( QSize( 0, 65 ) );

    OrdenesFavoritasLayout->addWidget( QCtrOrdenesFavoritas, 0, 0 );
    languageChange();
    resize( QSize(747, 548).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenesFavoritas::~OrdenesFavoritas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenesFavoritas::languageChange()
{
    setCaption( tr( "Ordenes Favoritas" ) );
    textLabel1->setText( tr( "Orden" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    textLabel1_4->setText( tr( "Descripcion Venta" ) );
    textLabel5_2->setText( tr( "Total" ) );
    QPBSelOrden->setText( tr( "Selecciona Orden" ) );
    QPBAsignaOrdenFavorita->setText( tr( "Asigna Orden Favorita" ) );
    QPBAgregarOrdenFavorita->setText( tr( "Agrega Orden" ) );
    QPBEliminaOrden->setText( tr( "Elimina Orden" ) );
    QPBRegistraFavoritas->setText( tr( "Registra Ordenes Favoritas" ) );
    QCtrOrdenesFavoritas->setTitle( tr( "Ordenes Favoritas" ) );
}

