/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroProductosSiscom.ui'
**
** Created: Fri Apr 12 21:26:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroProductosSiscom.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <QCtrlProductosSE.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"

/*
 *  Constructs a RegistroProductosSiscom as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroProductosSiscom::RegistroProductosSiscom( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroProductosSiscom" );
    RegistroProductosSiscomLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroProductosSiscomLayout"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout2->addWidget( textLabel3 );

    QTDefProducto = new QTable( this, "QTDefProducto" );
    QTDefProducto->setNumCols( QTDefProducto->numCols() + 1 );
    QTDefProducto->horizontalHeader()->setLabel( QTDefProducto->numCols() - 1, tr( "Clave" ) );
    QTDefProducto->setNumCols( QTDefProducto->numCols() + 1 );
    QTDefProducto->horizontalHeader()->setLabel( QTDefProducto->numCols() - 1, tr( "Cantidad" ) );
    QTDefProducto->setNumCols( QTDefProducto->numCols() + 1 );
    QTDefProducto->horizontalHeader()->setLabel( QTDefProducto->numCols() - 1, tr( "Expendio" ) );
    QTDefProducto->setNumCols( QTDefProducto->numCols() + 1 );
    QTDefProducto->horizontalHeader()->setLabel( QTDefProducto->numCols() - 1, tr( "Bodega" ) );
    QTDefProducto->setNumCols( QTDefProducto->numCols() + 1 );
    QTDefProducto->horizontalHeader()->setLabel( QTDefProducto->numCols() - 1, tr( "Origen" ) );
    QTDefProducto->setNumCols( QTDefProducto->numCols() + 1 );
    QTDefProducto->horizontalHeader()->setLabel( QTDefProducto->numCols() - 1, tr( "Comprar" ) );
    QTDefProducto->setNumRows( 0 );
    QTDefProducto->setNumCols( 6 );
    layout2->addWidget( QTDefProducto );

    RegistroProductosSiscomLayout->addMultiCellLayout( layout2, 1, 1, 0, 1 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrProductos );

    RegistroProductosSiscomLayout->addLayout( layout1, 0, 0 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QLECantidad );

    RegistroProductosSiscomLayout->addLayout( layout3, 0, 1 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    QPBBodega = new QPushButton( this, "QPBBodega" );
    QPBBodega->setEnabled( FALSE );
    layout18->addWidget( QPBBodega );

    QPBExpendio = new QPushButton( this, "QPBExpendio" );
    QPBExpendio->setEnabled( FALSE );
    layout18->addWidget( QPBExpendio );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    layout18->addWidget( QPBRegistrar );

    RegistroProductosSiscomLayout->addMultiCellLayout( layout18, 2, 2, 0, 1 );
    languageChange();
    resize( QSize(692, 516).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroProductosSiscom::~RegistroProductosSiscom()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroProductosSiscom::languageChange()
{
    setCaption( tr( "Registrando Productos" ) );
    textLabel3->setText( tr( "Definicion Producto" ) );
    QTDefProducto->horizontalHeader()->setLabel( 0, tr( "Clave" ) );
    QTDefProducto->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDefProducto->horizontalHeader()->setLabel( 2, tr( "Expendio" ) );
    QTDefProducto->horizontalHeader()->setLabel( 3, tr( "Bodega" ) );
    QTDefProducto->horizontalHeader()->setLabel( 4, tr( "Origen" ) );
    QTDefProducto->horizontalHeader()->setLabel( 5, tr( "Comprar" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel4->setText( tr( "Cantidad" ) );
    QPBBodega->setText( tr( "Bodega" ) );
    QPBExpendio->setText( tr( "Expendio" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
}

