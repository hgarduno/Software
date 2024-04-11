/****************************************************************************
** Form implementation generated from reading ui file 'UI/AdministradorPedidos.ui'
**
** Created: Wed Apr 10 20:52:38 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AdministradorPedidos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <QCtrlEstadosPedidosClienteSE.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qtable.h>
#include <qtoolbox.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"
#include "QCtrlEstadosPedidosClienteSE.h"

/*
 *  Constructs a AdministradorPedidos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
AdministradorPedidos::AdministradorPedidos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "AdministradorPedidos" );
    AdministradorPedidosLayout = new QGridLayout( this, 1, 1, 11, 6, "AdministradorPedidosLayout"); 

    layout8 = new QHBoxLayout( 0, 0, 0, "layout8"); 

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    QPBConsultar->setEnabled( FALSE );
    QPBConsultar->setMinimumSize( QSize( 0, 40 ) );
    layout8->addWidget( QPBConsultar );

    QPBActualizaEstado = new QPushButton( this, "QPBActualizaEstado" );
    QPBActualizaEstado->setEnabled( FALSE );
    QPBActualizaEstado->setMinimumSize( QSize( 240, 40 ) );
    layout8->addWidget( QPBActualizaEstado );

    QPBVender = new QPushButton( this, "QPBVender" );
    QPBVender->setEnabled( FALSE );
    QPBVender->setMinimumSize( QSize( 0, 40 ) );
    layout8->addWidget( QPBVender );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );
    QPBImprimir->setMinimumSize( QSize( 0, 40 ) );
    layout8->addWidget( QPBImprimir );

    QPBDevolucion = new QPushButton( this, "QPBDevolucion" );
    QPBDevolucion->setEnabled( FALSE );
    QPBDevolucion->setMinimumSize( QSize( 0, 40 ) );
    layout8->addWidget( QPBDevolucion );

    AdministradorPedidosLayout->addMultiCellLayout( layout8, 1, 1, 0, 1 );

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( textLabel4 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    QCtrFechaIni->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaIni->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( QCtrFechaIni );
    layout7->addLayout( layout17 );

    layout17_2 = new QHBoxLayout( 0, 0, 6, "layout17_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout17_2->addWidget( textLabel4_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout17_2->addWidget( QCtrFechaFin );
    layout7->addLayout( layout17_2 );

    layout7_2 = new QHBoxLayout( 0, 0, 6, "layout7_2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout7_2->addWidget( textLabel1 );

    QCtrEstadosPedido = new QCtrlEstadosPedidosClienteSE( this, "QCtrEstadosPedido" );
    layout7_2->addWidget( QCtrEstadosPedido );
    layout7->addLayout( layout7_2 );
    layout8_2->addLayout( layout7 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    QBGTipoOrden = new QButtonGroup( this, "QBGTipoOrden" );
    QBGTipoOrden->setColumnLayout(0, Qt::Vertical );
    QBGTipoOrden->layout()->setSpacing( 6 );
    QBGTipoOrden->layout()->setMargin( 11 );
    QBGTipoOrdenLayout = new QGridLayout( QBGTipoOrden->layout() );
    QBGTipoOrdenLayout->setAlignment( Qt::AlignTop );

    QRBVentas = new QRadioButton( QBGTipoOrden, "QRBVentas" );
    QBGTipoOrden->insert( QRBVentas, 0 );

    QBGTipoOrdenLayout->addWidget( QRBVentas, 0, 0 );

    QRBCotizaciones = new QRadioButton( QBGTipoOrden, "QRBCotizaciones" );
    QBGTipoOrden->insert( QRBCotizaciones, 10 );

    QBGTipoOrdenLayout->addWidget( QRBCotizaciones, 1, 0 );

    QRBPedidos = new QRadioButton( QBGTipoOrden, "QRBPedidos" );
    QBGTipoOrden->insert( QRBPedidos, 11 );

    QBGTipoOrdenLayout->addWidget( QRBPedidos, 2, 0 );

    QRBPedidosPorHora = new QRadioButton( QBGTipoOrden, "QRBPedidosPorHora" );
    QBGTipoOrden->insert( QRBPedidosPorHora, 12 );

    QBGTipoOrdenLayout->addWidget( QRBPedidosPorHora, 3, 0 );
    layout22->addWidget( QBGTipoOrden );

    QTOrdenes = new QTable( this, "QTOrdenes" );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Descripcion" ) );
    QTOrdenes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTOrdenes->sizePolicy().hasHeightForWidth() ) );
    QTOrdenes->setNumRows( 0 );
    QTOrdenes->setNumCols( 1 );
    QTOrdenes->setReadOnly( TRUE );
    layout22->addWidget( QTOrdenes );
    layout8_2->addLayout( layout22 );

    AdministradorPedidosLayout->addLayout( layout8_2, 0, 0 );

    toolBox1 = new QToolBox( this, "toolBox1" );
    toolBox1->setCurrentIndex( 0 );

    page1 = new QWidget( toolBox1, "page1" );
    page1->setBackgroundMode( QWidget::PaletteBackground );

    QWidget* privateLayoutWidget = new QWidget( page1, "layout9" );
    privateLayoutWidget->setGeometry( QRect( 10, 10, 180, 90 ) );
    layout9 = new QVBoxLayout( privateLayoutWidget, 11, 6, "layout9"); 

    textLabel1_2 = new QLabel( privateLayoutWidget, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel1_2 );

    lCDNumber1 = new QLCDNumber( privateLayoutWidget, "lCDNumber1" );
    layout9->addWidget( lCDNumber1 );

    QWidget* privateLayoutWidget_2 = new QWidget( page1, "layout9_2" );
    privateLayoutWidget_2->setGeometry( QRect( 200, 10, 180, 90 ) );
    layout9_2 = new QVBoxLayout( privateLayoutWidget_2, 11, 6, "layout9_2"); 

    textLabel1_2_2 = new QLabel( privateLayoutWidget_2, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout9_2->addWidget( textLabel1_2_2 );

    lCDNumber1_2 = new QLCDNumber( privateLayoutWidget_2, "lCDNumber1_2" );
    layout9_2->addWidget( lCDNumber1_2 );
    toolBox1->addItem( page1, QString::fromLatin1("") );

    page2 = new QWidget( toolBox1, "page2" );
    page2->setBackgroundMode( QWidget::PaletteBackground );
    page2Layout = new QGridLayout( page2, 1, 1, 11, 6, "page2Layout"); 

    table3 = new QTable( page2, "table3" );
    table3->setNumRows( 3 );
    table3->setNumCols( 3 );

    page2Layout->addWidget( table3, 0, 0 );
    toolBox1->addItem( page2, QString::fromLatin1("") );

    AdministradorPedidosLayout->addWidget( toolBox1, 0, 1 );
    languageChange();
    resize( QSize(1204, 651).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AdministradorPedidos::~AdministradorPedidos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AdministradorPedidos::languageChange()
{
    setCaption( tr( "Administrador Pedidos" ) );
    QPBConsultar->setText( tr( "C&onsultar" ) );
    QPBConsultar->setAccel( QKeySequence( tr( "Alt+O" ) ) );
    QPBActualizaEstado->setText( tr( "Actualiza Estado Pedido" ) );
    QPBActualizaEstado->setAccel( QKeySequence( QString::null ) );
    QPBVender->setText( tr( "Vender" ) );
    QPBImprimir->setText( tr( "Impresion" ) );
    QPBDevolucion->setText( tr( "Cancelar Pedido" ) );
    textLabel4->setText( tr( "Fecha Inicio" ) );
    textLabel4_2->setText( tr( "Fecha Fin" ) );
    textLabel1->setText( tr( "Estados Pedido" ) );
    QBGTipoOrden->setTitle( tr( "Tipo Orden" ) );
    QRBVentas->setText( tr( "Pedidos Registrados" ) );
    QRBCotizaciones->setText( tr( "Pedidos Por Punto \n"
"de Entrega" ) );
    QRBPedidos->setText( tr( "Pedios Por Paqueteria" ) );
    QRBPedidosPorHora->setText( tr( "Pedios Por &Hora" ) );
    QRBPedidosPorHora->setAccel( QKeySequence( tr( "Alt+H" ) ) );
    QTOrdenes->horizontalHeader()->setLabel( 0, tr( "Descripcion" ) );
    textLabel1_2->setText( tr( "Importe Pedidos" ) );
    textLabel1_2_2->setText( tr( "Numoero de Pedidos" ) );
    toolBox1->setItemLabel( toolBox1->indexOf(page1), tr( "Resumen Pedidos" ) );
    toolBox1->setItemLabel( toolBox1->indexOf(page2), tr( "Detalle del Pedido" ) );
}

