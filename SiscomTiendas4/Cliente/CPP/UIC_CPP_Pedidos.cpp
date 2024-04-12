/****************************************************************************
** Form implementation generated from reading ui file 'UI/Pedidos.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Pedidos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <QCtrlCotizas.h>
#include <qlabel.h>
#include <qtable.h>
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qtabwidget.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlCotizas.h"
#include "QCtrlOrdenes.h"
#include "QCtrlFormaPago.h"
#include "QCtrlClientes.h"
#include "QCtrlPrecios.h"
#include "QCtrlProductos.h"
#include "QSisDirecciones.h"
#include "QSisSepomex.h"

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

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QCCotizando = new QCtrlCotizas( this, "QCCotizando" );
    layout8->addWidget( QCCotizando );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout7->addWidget( textLabel2 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Importe" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Total" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 4 );
    layout7->addWidget( QTProductos );
    layout8->addLayout( layout7 );

    PedidosLayout->addLayout( layout8, 0, 0 );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    QSDirecciones = new QSisDirecciones( this, "QSDirecciones" );
    QSDirecciones->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QSDirecciones->sizePolicy().hasHeightForWidth() ) );
    layout13->addWidget( QSDirecciones );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel4 = new QLabel( groupBox1, "textLabel4" );
    layout10->addWidget( textLabel4 );

    QLEFecha = new QLineEdit( groupBox1, "QLEFecha" );
    QLEFecha->setReadOnly( TRUE );
    layout10->addWidget( QLEFecha );

    groupBox1Layout->addLayout( layout10, 0, 0 );

    layout10_2 = new QVBoxLayout( 0, 0, 6, "layout10_2"); 

    textLabel4_2 = new QLabel( groupBox1, "textLabel4_2" );
    layout10_2->addWidget( textLabel4_2 );

    lineEdit5_2 = new QLineEdit( groupBox1, "lineEdit5_2" );
    lineEdit5_2->setReadOnly( TRUE );
    layout10_2->addWidget( lineEdit5_2 );

    groupBox1Layout->addLayout( layout10_2, 1, 0 );

    tabWidget3 = new QTabWidget( groupBox1, "tabWidget3" );

    TabPage = new QWidget( tabWidget3, "TabPage" );
    TabPageLayout = new QGridLayout( TabPage, 1, 1, 11, 6, "TabPageLayout"); 

    layout7_2 = new QVBoxLayout( 0, 0, 6, "layout7_2"); 

    textLabel2_2 = new QLabel( TabPage, "textLabel2_2" );
    layout7_2->addWidget( textLabel2_2 );

    QTPedidoAnterior = new QTable( TabPage, "QTPedidoAnterior" );
    QTPedidoAnterior->setNumCols( QTPedidoAnterior->numCols() + 1 );
    QTPedidoAnterior->horizontalHeader()->setLabel( QTPedidoAnterior->numCols() - 1, tr( "Producto" ) );
    QTPedidoAnterior->setNumCols( QTPedidoAnterior->numCols() + 1 );
    QTPedidoAnterior->horizontalHeader()->setLabel( QTPedidoAnterior->numCols() - 1, tr( "Cantidad" ) );
    QTPedidoAnterior->setNumCols( QTPedidoAnterior->numCols() + 1 );
    QTPedidoAnterior->horizontalHeader()->setLabel( QTPedidoAnterior->numCols() - 1, tr( "Importe" ) );
    QTPedidoAnterior->setNumCols( QTPedidoAnterior->numCols() + 1 );
    QTPedidoAnterior->horizontalHeader()->setLabel( QTPedidoAnterior->numCols() - 1, tr( "Total" ) );
    QTPedidoAnterior->setNumRows( 0 );
    QTPedidoAnterior->setNumCols( 4 );
    layout7_2->addWidget( QTPedidoAnterior );

    TabPageLayout->addLayout( layout7_2, 0, 0 );
    tabWidget3->insertTab( TabPage, QString::fromLatin1("") );

    tab = new QWidget( tabWidget3, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel3 = new QLabel( tab, "textLabel3" );
    layout9->addWidget( textLabel3 );

    QTEComentario = new QTextEdit( tab, "QTEComentario" );
    QTEComentario->setReadOnly( TRUE );
    layout9->addWidget( QTEComentario );

    tabLayout->addLayout( layout9, 0, 0 );
    tabWidget3->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget3, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout9_2 = new QVBoxLayout( 0, 0, 6, "layout9_2"); 

    textLabel3_2 = new QLabel( tab_2, "textLabel3_2" );
    layout9_2->addWidget( textLabel3_2 );

    textEdit1_2 = new QTextEdit( tab_2, "textEdit1_2" );
    layout9_2->addWidget( textEdit1_2 );

    tabLayout_2->addLayout( layout9_2, 0, 0 );
    tabWidget3->insertTab( tab_2, QString::fromLatin1("") );

    groupBox1Layout->addWidget( tabWidget3, 2, 0 );
    layout13->addWidget( groupBox1 );

    PedidosLayout->addLayout( layout13, 1, 0 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    layout14->addWidget( QPBAnexar );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout14->addWidget( QPBRegistrar );

    PedidosLayout->addLayout( layout14, 2, 0 );
    languageChange();
    resize( QSize(1133, 632).expandedTo(minimumSizeHint()) );
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
    setCaption( tr( "Registro De Pedidos" ) );
    textLabel2->setText( tr( "Productos Del Pedido" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Total" ) );
    groupBox1->setTitle( tr( "Ultimo Pedido" ) );
    textLabel4->setText( tr( "Fecha De Entrega" ) );
    textLabel4_2->setText( tr( "Empleado Que Entrego" ) );
    textLabel2_2->setText( tr( "Productos Del Pedido" ) );
    QTPedidoAnterior->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTPedidoAnterior->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTPedidoAnterior->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    QTPedidoAnterior->horizontalHeader()->setLabel( 3, tr( "Total" ) );
    tabWidget3->changeTab( TabPage, tr( "Productos" ) );
    textLabel3->setText( tr( "Comentarios Del\n"
"Ultimo Pedido" ) );
    tabWidget3->changeTab( tab, tr( "Comentario Del Pedido" ) );
    textLabel3_2->setText( tr( "Comentarios Del\n"
"Adicionales" ) );
    tabWidget3->changeTab( tab_2, tr( "Comentarios Adicionales" ) );
    QPBAnexar->setText( tr( "Anexar Al Pedido" ) );
    QPBRegistrar->setText( tr( "Registrar Pedido" ) );
}

