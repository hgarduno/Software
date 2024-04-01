/****************************************************************************
** Form implementation generated from reading ui file 'UI/PedidosPendientes.ui'
**
** Created: Wed Jan 31 10:48:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PedidosPendientes.h"

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
 *  Constructs a PedidosPendientes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
PedidosPendientes::PedidosPendientes( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "PedidosPendientes" );
    PedidosPendientesLayout = new QGridLayout( this, 1, 1, 11, 6, "PedidosPendientesLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QTDetallePedido = new QTable( this, "QTDetallePedido" );
    QTDetallePedido->setNumCols( QTDetallePedido->numCols() + 1 );
    QTDetallePedido->horizontalHeader()->setLabel( QTDetallePedido->numCols() - 1, tr( "Cantidad" ) );
    QTDetallePedido->setNumCols( QTDetallePedido->numCols() + 1 );
    QTDetallePedido->horizontalHeader()->setLabel( QTDetallePedido->numCols() - 1, tr( "Producto" ) );
    QTDetallePedido->setNumCols( QTDetallePedido->numCols() + 1 );
    QTDetallePedido->horizontalHeader()->setLabel( QTDetallePedido->numCols() - 1, tr( "Observaciones" ) );
    QTDetallePedido->setNumRows( 0 );
    QTDetallePedido->setNumCols( 3 );
    layout1->addWidget( QTDetallePedido );

    PedidosPendientesLayout->addLayout( layout1, 1, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QTPedidos = new QTable( this, "QTPedidos" );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Fecha" ) );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Observaciones" ) );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "IdPedido" ) );
    QTPedidos->setNumRows( 0 );
    QTPedidos->setNumCols( 3 );
    layout2->addWidget( QTPedidos );

    PedidosPendientesLayout->addLayout( layout2, 0, 0 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout3->addWidget( pushButton1 );

    QPBEnviarAMatriz = new QPushButton( this, "QPBEnviarAMatriz" );
    layout3->addWidget( QPBEnviarAMatriz );

    pushButton1_2_2 = new QPushButton( this, "pushButton1_2_2" );
    layout3->addWidget( pushButton1_2_2 );

    PedidosPendientesLayout->addLayout( layout3, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PedidosPendientes::~PedidosPendientes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PedidosPendientes::languageChange()
{
    setCaption( tr( "Pedidos Pendientes" ) );
    textLabel1->setText( tr( "Detalle del Pedido" ) );
    QTDetallePedido->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTDetallePedido->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTDetallePedido->horizontalHeader()->setLabel( 2, tr( "Observaciones" ) );
    textLabel2->setText( tr( "Pedidos Pendientes" ) );
    QTPedidos->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTPedidos->horizontalHeader()->setLabel( 1, tr( "Observaciones" ) );
    QTPedidos->horizontalHeader()->setLabel( 2, tr( "IdPedido" ) );
    pushButton1->setText( tr( "Aceptar" ) );
    QPBEnviarAMatriz->setText( tr( "Enviar Pedido Matriz" ) );
    pushButton1_2_2->setText( tr( "Cancelar" ) );
}

