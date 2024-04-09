/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenesRegistradas.ui'
**
** Created: lun abr 1 18:57:55 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenesRegistradas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qtable.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a OrdenesRegistradas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
OrdenesRegistradas::OrdenesRegistradas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "OrdenesRegistradas" );
    OrdenesRegistradasLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenesRegistradasLayout"); 

    QTLPrincipal = new QHBoxLayout( 0, 0, 6, "QTLPrincipal"); 

    QBGTipoOrden = new QButtonGroup( this, "QBGTipoOrden" );
    QBGTipoOrden->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QBGTipoOrden->sizePolicy().hasHeightForWidth() ) );
    QBGTipoOrden->setColumnLayout(0, Qt::Vertical );
    QBGTipoOrden->layout()->setSpacing( 6 );
    QBGTipoOrden->layout()->setMargin( 11 );
    QBGTipoOrdenLayout = new QVBoxLayout( QBGTipoOrden->layout() );
    QBGTipoOrdenLayout->setAlignment( Qt::AlignTop );

    QRBVentas = new QRadioButton( QBGTipoOrden, "QRBVentas" );
    QBGTipoOrden->insert( QRBVentas, 0 );
    QBGTipoOrdenLayout->addWidget( QRBVentas );

    QRBCotizaciones = new QRadioButton( QBGTipoOrden, "QRBCotizaciones" );
    QBGTipoOrden->insert( QRBCotizaciones, 1 );
    QBGTipoOrdenLayout->addWidget( QRBCotizaciones );

    QRBPedidos = new QRadioButton( QBGTipoOrden, "QRBPedidos" );
    QBGTipoOrden->insert( QRBPedidos, 4 );
    QBGTipoOrdenLayout->addWidget( QRBPedidos );

    radioButton15 = new QRadioButton( QBGTipoOrden, "radioButton15" );
    QBGTipoOrden->insert( radioButton15, 5 );
    QBGTipoOrdenLayout->addWidget( radioButton15 );

    radioButton5 = new QRadioButton( QBGTipoOrden, "radioButton5" );
    QBGTipoOrden->insert( radioButton5, 11 );
    QBGTipoOrdenLayout->addWidget( radioButton5 );
    QTLPrincipal->addWidget( QBGTipoOrden );

    QTOrdenes = new QTable( this, "QTOrdenes" );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Importe" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Descripcion" ) );
    QTOrdenes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, QTOrdenes->sizePolicy().hasHeightForWidth() ) );
    QTOrdenes->setNumRows( 0 );
    QTOrdenes->setNumCols( 2 );
    QTOrdenes->setReadOnly( TRUE );
    QTLPrincipal->addWidget( QTOrdenes );

    QTWDatosOrden = new QTabWidget( this, "QTWDatosOrden" );
    QTWDatosOrden->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTWDatosOrden->sizePolicy().hasHeightForWidth() ) );

    tab = new QWidget( QTWDatosOrden, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    QTOrden = new QTable( tab, "QTOrden" );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Cantidad" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Producto" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Precio" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Importe" ) );
    QTOrden->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTOrden->sizePolicy().hasHeightForWidth() ) );
    QTOrden->setNumRows( 0 );
    QTOrden->setNumCols( 4 );
    QTOrden->setReadOnly( TRUE );

    tabLayout->addWidget( QTOrden, 0, 0 );
    QTWDatosOrden->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( QTWDatosOrden, "tab_2" );
    QTWDatosOrden->insertTab( tab_2, QString::fromLatin1("") );
    QTLPrincipal->addWidget( QTWDatosOrden );

    OrdenesRegistradasLayout->addLayout( QTLPrincipal, 1, 0 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( textLabel2 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( textLabel4 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    QCtrFechaIni->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaIni->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( QCtrFechaIni );
    layout6->addLayout( layout17 );

    layout17_2 = new QHBoxLayout( 0, 0, 6, "layout17_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout17_2->addWidget( textLabel4_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout17_2->addWidget( QCtrFechaFin );
    layout6->addLayout( layout17_2 );
    layout7->addLayout( layout6 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout7->addItem( spacer1 );

    OrdenesRegistradasLayout->addLayout( layout7, 0, 0 );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    QPBDetalleOrden = new QPushButton( this, "QPBDetalleOrden" );
    QPBDetalleOrden->setEnabled( TRUE );
    QPBDetalleOrden->setMinimumSize( QSize( 0, 40 ) );
    layout13->addWidget( QPBDetalleOrden );

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    QPBConsultar->setMinimumSize( QSize( 0, 40 ) );
    layout13->addWidget( QPBConsultar );

    QPBVender = new QPushButton( this, "QPBVender" );
    QPBVender->setEnabled( FALSE );
    QPBVender->setMinimumSize( QSize( 0, 40 ) );
    layout13->addWidget( QPBVender );

    QPBSeReflejo = new QPushButton( this, "QPBSeReflejo" );
    QPBSeReflejo->setEnabled( FALSE );
    QPBSeReflejo->setMinimumSize( QSize( 0, 40 ) );
    layout13->addWidget( QPBSeReflejo );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );
    QPBImprimir->setMinimumSize( QSize( 0, 40 ) );
    layout13->addWidget( QPBImprimir );

    QPBDevolucion = new QPushButton( this, "QPBDevolucion" );
    QPBDevolucion->setEnabled( FALSE );
    QPBDevolucion->setMinimumSize( QSize( 0, 40 ) );
    layout13->addWidget( QPBDevolucion );

    OrdenesRegistradasLayout->addLayout( layout13, 2, 0 );
    languageChange();
    resize( QSize(877, 540).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenesRegistradas::~OrdenesRegistradas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenesRegistradas::languageChange()
{
    setCaption( tr( "Form1" ) );
    QBGTipoOrden->setTitle( tr( "Tipo Orden" ) );
    QRBVentas->setText( tr( "Ventas" ) );
    QRBCotizaciones->setText( tr( "Cotizaciones" ) );
    QRBPedidos->setText( tr( "Pedidos" ) );
    radioButton15->setText( tr( "Circuitos Impresos" ) );
    radioButton5->setText( tr( "Transferencias" ) );
    QTOrdenes->horizontalHeader()->setLabel( 0, tr( "Importe" ) );
    QTOrdenes->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTOrden->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTOrden->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTOrden->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTOrden->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    QTWDatosOrden->changeTab( tab, tr( "Orden" ) );
    QTWDatosOrden->changeTab( tab_2, tr( "Datos Orden" ) );
    textLabel2->setText( tr( "Ordenes" ) );
    textLabel4->setText( tr( "Fecha Inicio" ) );
    textLabel4_2->setText( tr( "Fecha Fin" ) );
    QPBDetalleOrden->setText( tr( "Detalle De La\n"
"   Orden" ) );
    QPBDetalleOrden->setAccel( QKeySequence( QString::null ) );
    QPBConsultar->setText( tr( "&Consultar" ) );
    QPBConsultar->setAccel( QKeySequence( tr( "Alt+C" ) ) );
    QPBVender->setText( tr( "Vender" ) );
    QPBSeReflejo->setText( tr( "Transferencia\n"
"Reflejada" ) );
    QPBImprimir->setText( tr( "Impresion" ) );
    QPBDevolucion->setText( tr( "Devolucion" ) );
}

