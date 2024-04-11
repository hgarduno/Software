/****************************************************************************
** Form implementation generated from reading ui file 'UI/PedidosExpendios.ui'
**
** Created: Wed Apr 10 20:52:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PedidosExpendios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a PedidosExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PedidosExpendios::PedidosExpendios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PedidosExpendios" );
    PedidosExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "PedidosExpendiosLayout"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( textLabel1 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( QCtrFechaInicio );
    layout25->addLayout( layout23 );

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout24->addWidget( textLabel2_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout24->addWidget( QCtrFechaFin );
    layout25->addLayout( layout24 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout25->addItem( spacer1 );
    layout9->addLayout( layout25 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout12->addWidget( textLabel3 );

    QTPedidos = new QTable( this, "QTPedidos" );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Expendio" ) );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Fecha" ) );
    QTPedidos->setNumCols( QTPedidos->numCols() + 1 );
    QTPedidos->horizontalHeader()->setLabel( QTPedidos->numCols() - 1, tr( "Estado Pedido" ) );
    QTPedidos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QTPedidos->sizePolicy().hasHeightForWidth() ) );
    QTPedidos->setMinimumSize( QSize( 0, 200 ) );
    QTPedidos->setNumRows( 0 );
    QTPedidos->setNumCols( 3 );
    QTPedidos->setReadOnly( TRUE );
    layout12->addWidget( QTPedidos );
    layout15->addLayout( layout12 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout14->addWidget( textLabel3_2 );

    QTEObservaciones = new QTextEdit( this, "QTEObservaciones" );
    QTEObservaciones->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QTEObservaciones->sizePolicy().hasHeightForWidth() ) );
    QTEObservaciones->setReadOnly( TRUE );
    layout14->addWidget( QTEObservaciones );
    layout15->addLayout( layout14 );
    layout9->addLayout( layout15 );

    PedidosExpendiosLayout->addLayout( layout9, 0, 0 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout11->addWidget( textLabel2 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Existencia" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Bodegas" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Observaciones" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 5 );
    QTProductos->setReadOnly( TRUE );
    layout11->addWidget( QTProductos );

    PedidosExpendiosLayout->addLayout( layout11, 1, 0 );

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    QPBDesactivaValCantidad = new QPushButton( this, "QPBDesactivaValCantidad" );
    QPBDesactivaValCantidad->setEnabled( TRUE );
    QPBDesactivaValCantidad->setMinimumSize( QSize( 0, 30 ) );
    layout28->addWidget( QPBDesactivaValCantidad );

    QPBImprime = new QPushButton( this, "QPBImprime" );
    QPBImprime->setEnabled( FALSE );
    QPBImprime->setMinimumSize( QSize( 0, 30 ) );
    layout28->addWidget( QPBImprime );

    QPBConsultaPedidos = new QPushButton( this, "QPBConsultaPedidos" );
    QPBConsultaPedidos->setMinimumSize( QSize( 0, 30 ) );
    layout28->addWidget( QPBConsultaPedidos );

    QPBValidaExistencia = new QPushButton( this, "QPBValidaExistencia" );
    QPBValidaExistencia->setEnabled( FALSE );
    QPBValidaExistencia->setMinimumSize( QSize( 0, 30 ) );
    layout28->addWidget( QPBValidaExistencia );

    QPBAInventario = new QPushButton( this, "QPBAInventario" );
    QPBAInventario->setEnabled( FALSE );
    QPBAInventario->setMinimumSize( QSize( 0, 30 ) );
    layout28->addWidget( QPBAInventario );

    QPBTranBodegaExp = new QPushButton( this, "QPBTranBodegaExp" );
    QPBTranBodegaExp->setEnabled( FALSE );
    QPBTranBodegaExp->setMinimumSize( QSize( 0, 30 ) );
    layout28->addWidget( QPBTranBodegaExp );

    QPBTransfiere = new QPushButton( this, "QPBTransfiere" );
    QPBTransfiere->setEnabled( FALSE );
    QPBTransfiere->setMinimumSize( QSize( 0, 30 ) );
    layout28->addWidget( QPBTransfiere );

    PedidosExpendiosLayout->addLayout( layout28, 2, 0 );
    languageChange();
    resize( QSize(640, 638).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PedidosExpendios::~PedidosExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PedidosExpendios::languageChange()
{
    setCaption( tr( "Pedidos Expendios" ) );
    textLabel1->setText( tr( "Fecha Inicio" ) );
    textLabel2_2->setText( tr( "Fecha Fin" ) );
    textLabel3->setText( tr( "Pedidos" ) );
    QTPedidos->horizontalHeader()->setLabel( 0, tr( "Expendio" ) );
    QTPedidos->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTPedidos->horizontalHeader()->setLabel( 2, tr( "Estado Pedido" ) );
    textLabel3_2->setText( tr( "Observaciones" ) );
    textLabel2->setText( tr( "Detalle Pedido" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Existencia" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Bodegas" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "Observaciones" ) );
    QPBDesactivaValCantidad->setText( tr( "Desactiva \n"
"Validacion Cantidad" ) );
    QPBImprime->setText( tr( "Imprime\n"
"Pedido" ) );
    QPBConsultaPedidos->setText( tr( "Consulta \n"
"Pedidos" ) );
    QPBValidaExistencia->setText( tr( "Valida \n"
"Existencia" ) );
    QPBAInventario->setText( tr( "Ajusta \n"
"Inventario" ) );
    QPBTranBodegaExp->setText( tr( "Transfiere Bodega\n"
"Expendio" ) );
    QPBTransfiere->setText( tr( "Ejecuta \n"
"Transferencia" ) );
}

