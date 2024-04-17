/****************************************************************************
** Form implementation generated from reading ui file 'UI/PedidoMaterial.ui'
**
** Created: Fri Apr 12 21:26:02 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PedidoMaterial.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a PedidoMaterial as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PedidoMaterial::PedidoMaterial( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PedidoMaterial" );
    PedidoMaterialLayout = new QGridLayout( this, 1, 1, 11, 6, "PedidoMaterialLayout"); 

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Observaciones" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 3 );
    QTProductos->setReadOnly( TRUE );

    PedidoMaterialLayout->addMultiCellWidget( QTProductos, 1, 1, 0, 3 );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout1->addWidget( QCBProductos );
    layout12->addLayout( layout1 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout8->addWidget( textLabel3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    layout8->addWidget( QLECantidad );
    layout12->addLayout( layout8 );
    layout13->addLayout( layout12 );

    PedidoMaterialLayout->addMultiCellLayout( layout13, 0, 0, 0, 3 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QTEDescripcion );
    layout15->addLayout( layout2 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( textLabel2_2 );

    QTEObservacionesPedido = new QTextEdit( this, "QTEObservacionesPedido" );
    QTEObservacionesPedido->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEObservacionesPedido->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( QTEObservacionesPedido );
    layout15->addLayout( layout2_2 );

    PedidoMaterialLayout->addMultiCellLayout( layout15, 2, 2, 0, 3 );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );

    PedidoMaterialLayout->addWidget( QPBAnexar, 3, 0 );

    QPBEliminaProducto = new QPushButton( this, "QPBEliminaProducto" );
    QPBEliminaProducto->setEnabled( FALSE );

    PedidoMaterialLayout->addWidget( QPBEliminaProducto, 3, 1 );

    QPBRegPedidoMaterial = new QPushButton( this, "QPBRegPedidoMaterial" );
    QPBRegPedidoMaterial->setEnabled( FALSE );

    PedidoMaterialLayout->addWidget( QPBRegPedidoMaterial, 3, 2 );

    QPBPedidosPendientes = new QPushButton( this, "QPBPedidosPendientes" );
    QPBPedidosPendientes->setEnabled( TRUE );

    PedidoMaterialLayout->addWidget( QPBPedidosPendientes, 3, 3 );
    languageChange();
    resize( QSize(563, 589).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PedidoMaterial::~PedidoMaterial()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PedidoMaterial::languageChange()
{
    setCaption( tr( "Pedido de Material Expendio " ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Observaciones" ) );
    textLabel1->setText( tr( "Producto" ) );
    textLabel3->setText( tr( "Cantidad" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    textLabel2_2->setText( tr( "Observaciones Pedido" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBEliminaProducto->setText( tr( "Eliminar Producto" ) );
    QPBRegPedidoMaterial->setText( tr( "Registra Pedido Material" ) );
    QPBPedidosPendientes->setText( tr( "Pedidos Pendientes" ) );
}

