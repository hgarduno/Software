/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaInventario.ui'
**
** Created: Sat Jan 27 16:37:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaInventario.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSS.h"
#include "QCtrlProductosSS.h"

/*
 *  Constructs a CapturaInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CapturaInventario::CapturaInventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CapturaInventario" );
    CapturaInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaInventarioLayout"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    QCtrProveedores->setEnabled( FALSE );
    layout2->addWidget( QCtrProveedores );
    layout3->addLayout( layout2 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSS( this, "QCtrProductos" );
    QCtrProductos->setEnabled( FALSE );
    layout1->addWidget( QCtrProductos );
    layout3->addLayout( layout1 );

    CapturaInventarioLayout->addLayout( layout3, 0, 0 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout4->addWidget( textLabel3 );

    QLECodigoBarras = new QLineEdit( this, "QLECodigoBarras" );
    QLECodigoBarras->setEnabled( FALSE );
    layout4->addWidget( QLECodigoBarras );

    CapturaInventarioLayout->addLayout( layout4, 1, 0 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout5->addWidget( textLabel4 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Modelo" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Codigo Barras" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setEnabled( TRUE );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 4 );
    layout5->addWidget( QTProductos );

    CapturaInventarioLayout->addLayout( layout5, 3, 0 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout7->addWidget( textLabel1_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    layout7->addWidget( QLECantidad );
    layout8->addLayout( layout7 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout8->addItem( spacer1 );

    CapturaInventarioLayout->addLayout( layout8, 2, 0 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    QPBProgramaInventario = new QPushButton( this, "QPBProgramaInventario" );
    layout10->addWidget( QPBProgramaInventario );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout10->addWidget( QPBAnexar );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    layout10->addWidget( QPBRegistrar );

    CapturaInventarioLayout->addLayout( layout10, 4, 0 );
    languageChange();
    resize( QSize(701, 647).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaInventario::~CapturaInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaInventario::languageChange()
{
    setCaption( tr( "Captura Inventario" ) );
    textLabel2->setText( tr( "Proveedores" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel3->setText( tr( "Codigo Barras" ) );
    textLabel4->setText( tr( "Productos" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Codigo Barras" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    textLabel1_2->setText( tr( "Cantidad" ) );
    QLECantidad->setText( tr( "1" ) );
    QPBProgramaInventario->setText( tr( "Programa Inventario" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBRegistrar->setText( tr( "Registrar Inventario" ) );
}

