/****************************************************************************
** Form implementation generated from reading ui file 'UI/RecibePedido.ui'
**
** Created: Fri Apr 12 21:26:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RecibePedido.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a RecibePedido as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RecibePedido::RecibePedido( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RecibePedido" );
    RecibePedidoLayout = new QGridLayout( this, 1, 1, 11, 6, "RecibePedidoLayout"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout12->addWidget( textLabel3 );

    QTPedidos = new QTable( this, "QTPedidos" );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Expendio" ) );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Fecha" ) );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Observaciones" ) );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Estado Pedido" ) );
    QTPedidos->setNumRows( 0 );
    QTPedidos->setNumCols( 4 );
    QTPedidos->setReadOnly( TRUE );
    layout12->addWidget( QTPedidos );

    RecibePedidoLayout->addMultiCellLayout( layout12, 1, 1, 0, 1 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout11->addWidget( textLabel2 );

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
    layout11->addWidget( QTProductos );

    RecibePedidoLayout->addMultiCellLayout( layout11, 2, 2, 0, 1 );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    QPBImprime = new QPushButton( this, "QPBImprime" );
    QPBImprime->setEnabled( FALSE );
    layout5->addWidget( QPBImprime );

    QPBConsultaPedidos = new QPushButton( this, "QPBConsultaPedidos" );
    layout5->addWidget( QPBConsultaPedidos );

    QPBConsultaPedidos_2 = new QPushButton( this, "QPBConsultaPedidos_2" );
    layout5->addWidget( QPBConsultaPedidos_2 );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setEnabled( TRUE );
    layout5->addWidget( QPBRegistra );

    RecibePedidoLayout->addMultiCellLayout( layout5, 3, 3, 0, 1 );
    spacer1_2 = new QSpacerItem( 583, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    RecibePedidoLayout->addItem( spacer1_2, 0, 1 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout15->addWidget( textLabel1_2 );

    QCFInicio = new CQControlFecha( this, "QCFInicio" );
    QCFInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCFInicio->sizePolicy().hasHeightForWidth() ) );
    layout15->addWidget( QCFInicio );
    layout17->addLayout( layout15 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( textLabel2_2_2 );

    QCFFin = new CQControlFecha( this, "QCFFin" );
    QCFFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCFFin->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( QCFFin );
    layout17->addLayout( layout16 );

    RecibePedidoLayout->addLayout( layout17, 0, 0 );
    languageChange();
    resize( QSize(720, 633).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RecibePedido::~RecibePedido()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RecibePedido::languageChange()
{
    setCaption( tr( "Recibiendo Pedido" ) );
    textLabel3->setText( tr( "Pedidos" ) );
    QTPedidos->horizontalHeader()->setLabel( 0, tr( "Expendio" ) );
    QTPedidos->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTPedidos->horizontalHeader()->setLabel( 2, tr( "Observaciones" ) );
    QTPedidos->horizontalHeader()->setLabel( 3, tr( "Estado Pedido" ) );
    textLabel2->setText( tr( "Detalle Pedido" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Observaciones" ) );
    QPBImprime->setText( tr( "Imprime Pedido" ) );
    QPBConsultaPedidos->setText( tr( "Consulta Pedidos" ) );
    QPBConsultaPedidos_2->setText( tr( "Pedido Por Entrega" ) );
    QPBRegistra->setText( tr( "Registra" ) );
    textLabel1_2->setText( tr( "Fecha Inicio" ) );
    textLabel2_2_2->setText( tr( "Fecha Fin" ) );
}

