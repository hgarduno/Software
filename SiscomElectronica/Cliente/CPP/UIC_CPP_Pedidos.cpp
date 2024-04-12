/****************************************************************************
** Form implementation generated from reading ui file 'UI/Pedidos.ui'
**
** Created: Thu Apr 11 21:39:56 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Pedidos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QCtrlProductosSE.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"

/*
 *  Constructs a Pedidos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Pedidos::Pedidos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Pedidos" );
    PedidosLayout = new QGridLayout( this, 1, 1, 11, 6, "PedidosLayout"); 

    QPBDatosCliente = new QPushButton( this, "QPBDatosCliente" );
    QPBDatosCliente->setEnabled( TRUE );

    PedidosLayout->addWidget( QPBDatosCliente, 1, 0 );

    pushButton3_2 = new QPushButton( this, "pushButton3_2" );
    pushButton3_2->setEnabled( FALSE );

    PedidosLayout->addMultiCellWidget( pushButton3_2, 1, 1, 1, 2 );

    QPBAnexarOrden = new QPushButton( this, "QPBAnexarOrden" );
    QPBAnexarOrden->setEnabled( TRUE );

    PedidosLayout->addWidget( QPBAnexarOrden, 1, 3 );

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    layout24 = new QHBoxLayout( 0, 0, 6, "layout24"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout8->addWidget( QLECantidad );
    layout24->addLayout( layout8 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel4 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( QCtrProductos );
    layout24->addLayout( layout9 );

    layout8_3 = new QVBoxLayout( 0, 0, 6, "layout8_3"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    textLabel3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_3->sizePolicy().hasHeightForWidth() ) );
    layout8_3->addWidget( textLabel3_3 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    layout8_3->addWidget( QLEExistencia );
    layout24->addLayout( layout8_3 );

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout8_2->addWidget( textLabel3_2 );

    QLEExiBodega = new QLineEdit( this, "QLEExiBodega" );
    layout8_2->addWidget( QLEExiBodega );
    layout24->addLayout( layout8_2 );
    layout20->addLayout( layout24 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout7->addWidget( textLabel2 );

    QTOrden = new QTable( this, "QTOrden" );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Cantidad" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Producto" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Precio" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Importe" ) );
    QTOrden->setNumRows( 0 );
    QTOrden->setNumCols( 4 );
    QTOrden->setReadOnly( TRUE );
    layout7->addWidget( QTOrden );
    layout20->addLayout( layout7 );

    PedidosLayout->addMultiCellLayout( layout20, 0, 0, 0, 1 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );

    PedidosLayout->addWidget( QPBRegistrar, 1, 4 );

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout12->addWidget( textLabel5 );

    QLCDNumPrecio = new QLCDNumber( this, "QLCDNumPrecio" );
    QLCDNumPrecio->setNumDigits( 10 );
    layout12->addWidget( QLCDNumPrecio );
    layout16->addLayout( layout12 );

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout12_2->addWidget( textLabel5_2 );

    QLCDNumTotalOrden = new QLCDNumber( this, "QLCDNumTotalOrden" );
    QLCDNumTotalOrden->setNumDigits( 10 );
    layout12_2->addWidget( QLCDNumTotalOrden );
    layout16->addLayout( layout12_2 );
    layout22->addLayout( layout16 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( textLabel1 );

    QTECliente = new QTextEdit( this, "QTECliente" );
    QTECliente->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTECliente->sizePolicy().hasHeightForWidth() ) );
    QTECliente->setReadOnly( TRUE );
    layout19->addWidget( QTECliente );
    layout22->addLayout( layout19 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2->addWidget( textLabel1_2 );

    textEdit2_2 = new QTextEdit( this, "textEdit2_2" );
    textEdit2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textEdit2_2->sizePolicy().hasHeightForWidth() ) );
    textEdit2_2->setReadOnly( TRUE );
    layout5_2->addWidget( textEdit2_2 );
    layout22->addLayout( layout5_2 );

    layout5_3 = new QVBoxLayout( 0, 0, 6, "layout5_3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout5_3->addWidget( textLabel1_3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout5_3->addWidget( QTEDescripcion );
    layout22->addLayout( layout5_3 );

    PedidosLayout->addMultiCellLayout( layout22, 0, 0, 2, 4 );
    languageChange();
    resize( QSize(1013, 609).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Pedidos::~Pedidos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Pedidos::languageChange()
{
    setCaption( tr( "Pedidos Telefonicos" ) );
    QPBDatosCliente->setText( tr( "Datos Cliente" ) );
    pushButton3_2->setText( tr( "Datos Pedido" ) );
    QPBAnexarOrden->setText( tr( "Anexar Orden" ) );
    textLabel3->setText( tr( "Cantidad" ) );
    QLECantidad->setText( tr( "1" ) );
    textLabel4->setText( tr( "Productos" ) );
    textLabel3_3->setText( tr( "Existencia" ) );
    QLEExistencia->setText( tr( "0" ) );
    textLabel3_2->setText( tr( "Existencia Bodega" ) );
    QLEExiBodega->setText( tr( "0" ) );
    textLabel2->setText( tr( "Orden" ) );
    QTOrden->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTOrden->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTOrden->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTOrden->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    QPBRegistrar->setText( tr( "Registrar Pedido" ) );
    textLabel5->setText( tr( "Precio" ) );
    textLabel5_2->setText( tr( "Total" ) );
    textLabel1->setText( tr( "Datos Cliente" ) );
    textLabel1_2->setText( tr( "Datos Pedido" ) );
    textLabel1_3->setText( tr( "Informacion Producto" ) );
}

