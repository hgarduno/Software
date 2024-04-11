/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductosFaltantes4.ui'
**
** Created: Wed Apr 10 20:52:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductosFaltantes4.h"

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
 *  Constructs a ProductosFaltantes4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ProductosFaltantes4::ProductosFaltantes4( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ProductosFaltantes4" );
    ProductosFaltantes4Layout = new QGridLayout( this, 1, 1, 11, 6, "ProductosFaltantes4Layout"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout21->addWidget( textLabel1 );

    table6 = new QTable( this, "table6" );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Producto" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Compras Sem/Ant" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Ventas Sem/Ant" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Compras Act." ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Ventas Act" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Existencias" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Bodegas" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Trasferencias" ) );
    table6->setNumRows( 0 );
    table6->setNumCols( 8 );
    layout21->addWidget( table6 );

    ProductosFaltantes4Layout->addLayout( layout21, 0, 0 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout12->addWidget( textLabel3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha Compra" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "P Compra" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "P Sin Iva" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Factura" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Proveedor" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Clave Proveedor" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 7 );
    QTDatos->setReadOnly( TRUE );
    layout12->addWidget( QTDatos );

    ProductosFaltantes4Layout->addLayout( layout12, 1, 0 );

    layout32 = new QVBoxLayout( 0, 0, 6, "layout32"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout32->addWidget( textLabel5 );

    QTOrdenCompra = new QTable( this, "QTOrdenCompra" );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Clave Producto" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Clave Provedor" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Cantidad" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Precio Sin Iva" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Precio Compra" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Proveedor" ) );
    QTOrdenCompra->setNumRows( 0 );
    QTOrdenCompra->setNumCols( 6 );
    QTOrdenCompra->setReadOnly( TRUE );
    layout32->addWidget( QTOrdenCompra );

    ProductosFaltantes4Layout->addLayout( layout32, 2, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    pushButton3 = new QPushButton( this, "pushButton3" );
    layout22->addWidget( pushButton3 );

    pushButton4 = new QPushButton( this, "pushButton4" );
    layout22->addWidget( pushButton4 );

    ProductosFaltantes4Layout->addLayout( layout22, 3, 0 );
    languageChange();
    resize( QSize(1063, 802).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductosFaltantes4::~ProductosFaltantes4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductosFaltantes4::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Productos Faltantes" ) );
    table6->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    table6->horizontalHeader()->setLabel( 1, tr( "Compras Sem/Ant" ) );
    table6->horizontalHeader()->setLabel( 2, tr( "Ventas Sem/Ant" ) );
    table6->horizontalHeader()->setLabel( 3, tr( "Compras Act." ) );
    table6->horizontalHeader()->setLabel( 4, tr( "Ventas Act" ) );
    table6->horizontalHeader()->setLabel( 5, tr( "Existencias" ) );
    table6->horizontalHeader()->setLabel( 6, tr( "Bodegas" ) );
    table6->horizontalHeader()->setLabel( 7, tr( "Trasferencias" ) );
    textLabel3->setText( tr( "Historico Compras" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Fecha Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "P Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "P Sin Iva" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Factura" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Proveedor" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Clave Proveedor" ) );
    textLabel5->setText( tr( "Orden de Compras" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 0, tr( "Clave Producto" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 1, tr( "Clave Provedor" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 3, tr( "Precio Sin Iva" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 4, tr( "Precio Compra" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 5, tr( "Proveedor" ) );
    pushButton3->setText( tr( "pushButton3" ) );
    pushButton4->setText( tr( "pushButton4" ) );
}

