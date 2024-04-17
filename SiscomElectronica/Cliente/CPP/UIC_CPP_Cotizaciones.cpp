/****************************************************************************
** Form implementation generated from reading ui file 'UI/Cotizaciones.ui'
**
** Created: Fri Apr 12 21:26:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Cotizaciones.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a Cotizaciones as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Cotizaciones::Cotizaciones( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "Cotizaciones" );
    CotizacionesLayout = new QGridLayout( this, 1, 1, 11, 6, "CotizacionesLayout"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    QBGTipoOrden = new QButtonGroup( this, "QBGTipoOrden" );
    QBGTipoOrden->setColumnLayout(0, Qt::Vertical );
    QBGTipoOrden->layout()->setSpacing( 6 );
    QBGTipoOrden->layout()->setMargin( 11 );
    QBGTipoOrdenLayout = new QGridLayout( QBGTipoOrden->layout() );
    QBGTipoOrdenLayout->setAlignment( Qt::AlignTop );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    QRBVentas = new QRadioButton( QBGTipoOrden, "QRBVentas" );
    layout13->addWidget( QRBVentas );

    QRBCotizaciones = new QRadioButton( QBGTipoOrden, "QRBCotizaciones" );
    layout13->addWidget( QRBCotizaciones );

    QRBPedidos = new QRadioButton( QBGTipoOrden, "QRBPedidos" );
    QBGTipoOrden->insert( QRBPedidos, -1 );
    layout13->addWidget( QRBPedidos );

    QBGTipoOrdenLayout->addLayout( layout13, 0, 0 );
    layout20->addWidget( QBGTipoOrden );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( textLabel3 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    QCtrFechaInicio->setEnabled( FALSE );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( QCtrFechaInicio );
    layout20->addLayout( layout4 );

    layout4_2 = new QVBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( textLabel3_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setEnabled( FALSE );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( QCtrFechaFin );
    layout20->addLayout( layout4_2 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel4 );

    QLEIdOrden = new QLineEdit( this, "QLEIdOrden" );
    QLEIdOrden->setEnabled( TRUE );
    layout5->addWidget( QLEIdOrden );
    layout20->addLayout( layout5 );
    layout21->addLayout( layout20 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel1 );

    QTOrdenes = new QTable( this, "QTOrdenes" );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "# Orden" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Importe" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Descripcion" ) );
    QTOrdenes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, QTOrdenes->sizePolicy().hasHeightForWidth() ) );
    QTOrdenes->setMinimumSize( QSize( 0, 200 ) );
    QTOrdenes->setMaximumSize( QSize( 32767, 200 ) );
    QTOrdenes->setNumRows( 0 );
    QTOrdenes->setNumCols( 3 );
    QTOrdenes->setReadOnly( TRUE );
    layout3->addWidget( QTOrdenes );
    layout21->addLayout( layout3 );

    CotizacionesLayout->addLayout( layout21, 0, 0 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    QPBConsultar->setEnabled( FALSE );
    QPBConsultar->setAutoDefault( FALSE );
    layout19->addWidget( QPBConsultar );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout19->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout19->addWidget( QPBCancelar );

    CotizacionesLayout->addLayout( layout19, 3, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout6->addWidget( textLabel2 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Precio" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Importe" ) );
    QTProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTProductos->sizePolicy().hasHeightForWidth() ) );
    QTProductos->setMinimumSize( QSize( 0, 200 ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 4 );
    layout6->addWidget( QTProductos );

    CotizacionesLayout->addLayout( layout6, 2, 0 );

    layout19_2 = new QHBoxLayout( 0, 0, 6, "layout19_2"); 

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout18->addWidget( textLabel6 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setMinimumSize( QSize( 0, 50 ) );
    QTEDescripcion->setMaximumSize( QSize( 32767, 50 ) );
    layout18->addWidget( QTEDescripcion );
    layout19_2->addLayout( layout18 );

    layout13_2 = new QVBoxLayout( 0, 0, 6, "layout13_2"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout13_2->addWidget( textLabel5 );

    QLCDNImporte = new QLCDNumber( this, "QLCDNImporte" );
    QLCDNImporte->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QLCDNImporte->sizePolicy().hasHeightForWidth() ) );
    QLCDNImporte->setNumDigits( 10 );
    layout13_2->addWidget( QLCDNImporte );
    layout19_2->addLayout( layout13_2 );

    CotizacionesLayout->addLayout( layout19_2, 1, 0 );
    languageChange();
    resize( QSize(633, 606).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Cotizaciones::~Cotizaciones()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Cotizaciones::languageChange()
{
    setCaption( tr( "Ordenes Vendidas" ) );
    QBGTipoOrden->setTitle( tr( "Tipo Orden" ) );
    QRBVentas->setText( tr( "Ventas" ) );
    QRBCotizaciones->setText( tr( "Cotizaciones" ) );
    QRBPedidos->setText( tr( "Pedidos" ) );
    textLabel3->setText( tr( "Fecha Inicio" ) );
    textLabel3_2->setText( tr( "Fecha Fin" ) );
    textLabel4->setText( tr( "# Orden" ) );
    textLabel1->setText( tr( "Cotizaciones" ) );
    QTOrdenes->horizontalHeader()->setLabel( 0, tr( "# Orden" ) );
    QTOrdenes->horizontalHeader()->setLabel( 1, tr( "Importe" ) );
    QTOrdenes->horizontalHeader()->setLabel( 2, tr( "Descripcion" ) );
    QPBConsultar->setText( tr( "Consultar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel2->setText( tr( "Material" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    textLabel6->setText( tr( "Descripcion" ) );
    textLabel5->setText( tr( "Importe" ) );
}

