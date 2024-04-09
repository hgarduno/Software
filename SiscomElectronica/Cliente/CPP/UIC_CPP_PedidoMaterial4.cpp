/****************************************************************************
** Form implementation generated from reading ui file 'UI/PedidoMaterial4.ui'
**
** Created: lun abr 1 18:57:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PedidoMaterial4.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <QCtrlProductosSE.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProductosSE.h"

/*
 *  Constructs a PedidoMaterial4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PedidoMaterial4::PedidoMaterial4( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PedidoMaterial4" );
    PedidoMaterial4Layout = new QGridLayout( this, 1, 1, 11, 6, "PedidoMaterial4Layout"); 

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

    PedidoMaterial4Layout->addLayout( layout15, 4, 0 );

    layout15_2 = new QVBoxLayout( 0, 0, 6, "layout15_2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout15_2->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    layout15_2->addWidget( QCtrProductos );

    PedidoMaterial4Layout->addLayout( layout15_2, 0, 0 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Estado" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Observaciones" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 4 );
    QTProductos->setReadOnly( TRUE );

    PedidoMaterial4Layout->addWidget( QTProductos, 3, 0 );

    layout15_3 = new QHBoxLayout( 0, 0, 6, "layout15_3"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout8->addWidget( textLabel3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    layout8->addWidget( QLECantidad );
    layout15_3->addLayout( layout8 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout15_3->addItem( spacer2 );

    PedidoMaterial4Layout->addLayout( layout15_3, 1, 0 );

    layout2_2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2_2->addWidget( textLabel2_2_2 );

    QTEObsProducto = new QTextEdit( this, "QTEObsProducto" );
    QTEObsProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEObsProducto->sizePolicy().hasHeightForWidth() ) );
    layout2_2_2->addWidget( QTEObsProducto );

    PedidoMaterial4Layout->addLayout( layout2_2_2, 2, 0 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout9->addWidget( QPBAnexar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( FALSE );
    layout9->addWidget( QPBActualizar );

    QPBActualizaObsPedido = new QPushButton( this, "QPBActualizaObsPedido" );
    QPBActualizaObsPedido->setEnabled( FALSE );
    layout9->addWidget( QPBActualizaObsPedido );

    QPBEliminaProducto = new QPushButton( this, "QPBEliminaProducto" );
    QPBEliminaProducto->setEnabled( FALSE );
    layout9->addWidget( QPBEliminaProducto );

    QPBRegistraPedido = new QPushButton( this, "QPBRegistraPedido" );
    QPBRegistraPedido->setEnabled( TRUE );
    layout9->addWidget( QPBRegistraPedido );

    PedidoMaterial4Layout->addLayout( layout9, 5, 0 );
    languageChange();
    resize( QSize(774, 633).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PedidoMaterial4::~PedidoMaterial4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PedidoMaterial4::languageChange()
{
    setCaption( tr( "Pedido de Material Expendio " ) );
    textLabel2->setText( tr( "Descripcion" ) );
    textLabel2_2->setText( tr( "Observaciones Pedido" ) );
    textLabel1->setText( tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Estado" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Observaciones" ) );
    textLabel3->setText( tr( "Cantidad" ) );
    textLabel2_2_2->setText( tr( "Observaciones Producto" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBActualizar->setText( tr( "Actualiza Datos Producto" ) );
    QPBActualizaObsPedido->setText( tr( "Actualiza Observaciones Pedido" ) );
    QPBEliminaProducto->setText( tr( "Eliminar Producto" ) );
    QPBRegistraPedido->setText( tr( "Registra Pedido" ) );
}

