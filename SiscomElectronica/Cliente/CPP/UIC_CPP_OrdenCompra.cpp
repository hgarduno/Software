/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenCompra.ui'
**
** Created: Wed Jan 31 10:59:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenCompra.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a OrdenCompra as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
OrdenCompra::OrdenCompra( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "OrdenCompra" );
    OrdenCompraLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenCompraLayout"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout10->addWidget( textLabel2 );

    table2 = new QTable( this, "table2" );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Fecha" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Producto" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Proveedor" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Cantidad" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Importe" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Precio" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Existencia" ) );
    table2->setNumRows( 0 );
    table2->setNumCols( 7 );
    layout10->addWidget( table2 );

    OrdenCompraLayout->addLayout( layout10, 0, 0 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout11->addWidget( textLabel3 );

    table2_2 = new QTable( this, "table2_2" );
    table2_2->setNumCols( table2_2->numCols() + 1 );
    table2_2->horizontalHeader()->setLabel( table2_2->numCols() - 1, tr( "Fecha" ) );
    table2_2->setNumCols( table2_2->numCols() + 1 );
    table2_2->horizontalHeader()->setLabel( table2_2->numCols() - 1, tr( "Producto" ) );
    table2_2->setNumCols( table2_2->numCols() + 1 );
    table2_2->horizontalHeader()->setLabel( table2_2->numCols() - 1, tr( "Proveedor" ) );
    table2_2->setNumCols( table2_2->numCols() + 1 );
    table2_2->horizontalHeader()->setLabel( table2_2->numCols() - 1, tr( "Cantidad" ) );
    table2_2->setNumRows( 0 );
    table2_2->setNumCols( 4 );
    layout11->addWidget( table2_2 );

    OrdenCompraLayout->addLayout( layout11, 1, 0 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    pushButton6 = new QPushButton( this, "pushButton6" );
    pushButton6->setMinimumSize( QSize( 0, 16 ) );
    pushButton6->setMaximumSize( QSize( 32767, 16 ) );
    layout14->addWidget( pushButton6 );

    pushButton6_2 = new QPushButton( this, "pushButton6_2" );
    pushButton6_2->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2->setMaximumSize( QSize( 32767, 16 ) );
    layout14->addWidget( pushButton6_2 );

    pushButton6_2_2 = new QPushButton( this, "pushButton6_2_2" );
    pushButton6_2_2->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2_2->setMaximumSize( QSize( 32767, 16 ) );
    layout14->addWidget( pushButton6_2_2 );

    pushButton6_2_2_2 = new QPushButton( this, "pushButton6_2_2_2" );
    pushButton6_2_2_2->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2_2_2->setMaximumSize( QSize( 32767, 16 ) );
    layout14->addWidget( pushButton6_2_2_2 );

    OrdenCompraLayout->addLayout( layout14, 2, 0 );

    layout14_2 = new QHBoxLayout( 0, 0, 6, "layout14_2"); 

    pushButton6_3 = new QPushButton( this, "pushButton6_3" );
    pushButton6_3->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_3->setMaximumSize( QSize( 32767, 16 ) );
    layout14_2->addWidget( pushButton6_3 );

    pushButton6_2_3 = new QPushButton( this, "pushButton6_2_3" );
    pushButton6_2_3->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2_3->setMaximumSize( QSize( 32767, 16 ) );
    layout14_2->addWidget( pushButton6_2_3 );

    pushButton6_2_2_3 = new QPushButton( this, "pushButton6_2_2_3" );
    pushButton6_2_2_3->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2_2_3->setMaximumSize( QSize( 32767, 16 ) );
    layout14_2->addWidget( pushButton6_2_2_3 );

    pushButton6_2_2_2_2 = new QPushButton( this, "pushButton6_2_2_2_2" );
    pushButton6_2_2_2_2->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2_2_2_2->setMaximumSize( QSize( 32767, 16 ) );
    layout14_2->addWidget( pushButton6_2_2_2_2 );

    OrdenCompraLayout->addLayout( layout14_2, 3, 0 );

    layout14_2_2 = new QHBoxLayout( 0, 0, 6, "layout14_2_2"); 

    pushButton6_3_2 = new QPushButton( this, "pushButton6_3_2" );
    pushButton6_3_2->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_3_2->setMaximumSize( QSize( 32767, 16 ) );
    layout14_2_2->addWidget( pushButton6_3_2 );

    pushButton6_2_3_2 = new QPushButton( this, "pushButton6_2_3_2" );
    pushButton6_2_3_2->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2_3_2->setMaximumSize( QSize( 32767, 16 ) );
    layout14_2_2->addWidget( pushButton6_2_3_2 );

    pushButton6_2_2_3_2 = new QPushButton( this, "pushButton6_2_2_3_2" );
    pushButton6_2_2_3_2->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2_2_3_2->setMaximumSize( QSize( 32767, 16 ) );
    layout14_2_2->addWidget( pushButton6_2_2_3_2 );

    pushButton6_2_2_2_2_2 = new QPushButton( this, "pushButton6_2_2_2_2_2" );
    pushButton6_2_2_2_2_2->setMinimumSize( QSize( 0, 16 ) );
    pushButton6_2_2_2_2_2->setMaximumSize( QSize( 32767, 16 ) );
    layout14_2_2->addWidget( pushButton6_2_2_2_2_2 );

    OrdenCompraLayout->addLayout( layout14_2_2, 4, 0 );
    languageChange();
    resize( QSize(823, 705).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenCompra::~OrdenCompra()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenCompra::languageChange()
{
    setCaption( tr( "Orden De Compra" ) );
    textLabel2->setText( tr( "Ultima Compra" ) );
    table2->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    table2->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    table2->horizontalHeader()->setLabel( 2, tr( "Proveedor" ) );
    table2->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    table2->horizontalHeader()->setLabel( 4, tr( "Importe" ) );
    table2->horizontalHeader()->setLabel( 5, tr( "Precio" ) );
    table2->horizontalHeader()->setLabel( 6, tr( "Existencia" ) );
    textLabel3->setText( tr( "Compra" ) );
    table2_2->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    table2_2->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    table2_2->horizontalHeader()->setLabel( 2, tr( "Proveedor" ) );
    table2_2->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    pushButton6->setText( tr( "% Existencia Minima" ) );
    pushButton6_2->setText( tr( "Anexar Ultima Compra" ) );
    pushButton6_2_2->setText( tr( "Anexar Producto" ) );
    pushButton6_2_2_2->setText( tr( "Registrar Ultima Compra" ) );
    pushButton6_3->setText( tr( "% Existencia Minima" ) );
    pushButton6_2_3->setText( tr( "Anexar Ultima Compra" ) );
    pushButton6_2_2_3->setText( tr( "Anexar Producto" ) );
    pushButton6_2_2_2_2->setText( tr( "Registrar Ultima Compra" ) );
    pushButton6_3_2->setText( tr( "% Existencia Minima" ) );
    pushButton6_2_3_2->setText( tr( "Anexar Ultima Compra" ) );
    pushButton6_2_2_3_2->setText( tr( "Anexar Producto" ) );
    pushButton6_2_2_2_2_2->setText( tr( "Registrar Ultima Compra" ) );
}

