/****************************************************************************
** Form implementation generated from reading ui file 'UI/Ventas3Qt.ui'
**
** Created: Fri Apr 12 21:36:42 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Ventas3Qt.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlPrecios3Qt.h>
#include <QCtrlProductos3Qt.h>
#include <qlineedit.h>
#include <QCtrlClientes3Qt.h>
#include <QCtrlContactos3Qt.h>
#include <QCtrlFormaPago3Qt.h>
#include <qtable.h>
#include <qgroupbox.h>
#include <qlcdnumber.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <QCtrlPreciosProductos.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlPrecios3Qt.h"
#include "QCtrlProductos3Qt.h"
#include "QCtrlClientes3Qt.h"
#include "QCtrlContactos3Qt.h"
#include "QCtrlFormaPago3Qt.h"
#include "QCtrlPreciosProductos.h"

/*
 *  Constructs a Ventas3Qt as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Ventas3Qt::Ventas3Qt( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Ventas3Qt" );
    Ventas3QtLayout = new QGridLayout( this, 1, 1, 11, 6, "Ventas3QtLayout"); 

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1_5 = new QLabel( this, "textLabel1_5" );
    layout5->addWidget( textLabel1_5 );

    QCtrPrecios = new QCtrlPrecios3Qt( this, "QCtrPrecios" );
    layout5->addWidget( QCtrPrecios );
    layout26->addLayout( layout5 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout19->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductos3Qt( this, "QCtrProductos" );
    layout19->addWidget( QCtrProductos );
    layout26->addLayout( layout19 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( textLabel2_2_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( QLECantidad );
    layout26->addLayout( layout42 );

    layout42_2 = new QVBoxLayout( 0, 0, 6, "layout42_2"); 

    textLabel2_2_2_2 = new QLabel( this, "textLabel2_2_2_2" );
    textLabel2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout42_2->addWidget( textLabel2_2_2_2 );

    QLEImporte = new QLineEdit( this, "QLEImporte" );
    QLEImporte->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEImporte->sizePolicy().hasHeightForWidth() ) );
    layout42_2->addWidget( QLEImporte );
    layout26->addLayout( layout42_2 );

    Ventas3QtLayout->addLayout( layout26, 1, 0 );

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout2->addWidget( textLabel1_2 );

    QCtrClientes = new QCtrlClientes3Qt( this, "QCtrClientes" );
    layout2->addWidget( QCtrClientes );
    layout28->addLayout( layout2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout3->addWidget( textLabel1_3 );

    QCtrContactos = new QCtrlContactos3Qt( this, "QCtrContactos" );
    layout3->addWidget( QCtrContactos );
    layout28->addLayout( layout3 );

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    layout22->addWidget( textLabel1_4 );

    QCtrFPago = new QCtrlFormaPago3Qt( this, "QCtrFPago" );
    layout22->addWidget( QCtrFPago );
    layout28->addLayout( layout22 );

    Ventas3QtLayout->addLayout( layout28, 0, 0 );

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout44->addWidget( textLabel2_4 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Escala" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Tipo Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 7 );
    QTDatos->setReadOnly( TRUE );
    layout44->addWidget( QTDatos );

    Ventas3QtLayout->addLayout( layout44, 3, 0 );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    QPBAnexar->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPBAnexar->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( QPBAnexar );

    pushButton5_2 = new QPushButton( this, "pushButton5_2" );
    pushButton5_2->setEnabled( FALSE );
    pushButton5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, pushButton5_2->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( pushButton5_2 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );
    QPBImprimir->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPBImprimir->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( QPBImprimir );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setEnabled( FALSE );
    QPBRegistra->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPBRegistra->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( QPBRegistra );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setEnabled( FALSE );
    layout23->addWidget( QPBEliminar );

    Ventas3QtLayout->addLayout( layout23, 4, 0 );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, groupBox1->sizePolicy().hasHeightForWidth() ) );
    groupBox1->setMinimumSize( QSize( 0, 250 ) );
    groupBox1->setMaximumSize( QSize( 32767, 250 ) );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    layout50_2_3 = new QVBoxLayout( 0, 0, 6, "layout50_2_3"); 

    textLabel2_6_2_3 = new QLabel( groupBox1, "textLabel2_6_2_3" );
    textLabel2_6_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6_2_3->sizePolicy().hasHeightForWidth() ) );
    layout50_2_3->addWidget( textLabel2_6_2_3 );

    QLCDNExistencia = new QLCDNumber( groupBox1, "QLCDNExistencia" );
    QLCDNExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDNExistencia->sizePolicy().hasHeightForWidth() ) );
    QLCDNExistencia->setNumDigits( 8 );
    layout50_2_3->addWidget( QLCDNExistencia );
    layout32->addLayout( layout50_2_3 );

    QBGTOrden = new QButtonGroup( groupBox1, "QBGTOrden" );
    QBGTOrden->setColumnLayout(0, Qt::Vertical );
    QBGTOrden->layout()->setSpacing( 6 );
    QBGTOrden->layout()->setMargin( 11 );
    QBGTOrdenLayout = new QGridLayout( QBGTOrden->layout() );
    QBGTOrdenLayout->setAlignment( Qt::AlignTop );

    layout26_2 = new QVBoxLayout( 0, 0, 6, "layout26_2"); 

    QRBRemision = new QRadioButton( QBGTOrden, "QRBRemision" );
    layout26_2->addWidget( QRBRemision );

    QRBFactura = new QRadioButton( QBGTOrden, "QRBFactura" );
    layout26_2->addWidget( QRBFactura );

    QRBCotizacion = new QRadioButton( QBGTOrden, "QRBCotizacion" );
    layout26_2->addWidget( QRBCotizacion );

    QBGTOrdenLayout->addLayout( layout26_2, 0, 0 );
    layout32->addWidget( QBGTOrden );

    groupBox1Layout->addLayout( layout32, 0, 2 );

    layout27 = new QHBoxLayout( 0, 0, 6, "layout27"); 

    layout50_2 = new QVBoxLayout( 0, 0, 6, "layout50_2"); 

    textLabel2_6_2 = new QLabel( groupBox1, "textLabel2_6_2" );
    textLabel2_6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6_2->sizePolicy().hasHeightForWidth() ) );
    layout50_2->addWidget( textLabel2_6_2 );

    QLCDNPrecio = new QLCDNumber( groupBox1, "QLCDNPrecio" );
    QLCDNPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDNPrecio->sizePolicy().hasHeightForWidth() ) );
    QLCDNPrecio->setNumDigits( 8 );
    layout50_2->addWidget( QLCDNPrecio );
    layout27->addLayout( layout50_2 );

    layout50_2_2 = new QVBoxLayout( 0, 0, 6, "layout50_2_2"); 

    textLabel2_6_2_2 = new QLabel( groupBox1, "textLabel2_6_2_2" );
    textLabel2_6_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6_2_2->sizePolicy().hasHeightForWidth() ) );
    layout50_2_2->addWidget( textLabel2_6_2_2 );

    QLCDNImporte = new QLCDNumber( groupBox1, "QLCDNImporte" );
    QLCDNImporte->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDNImporte->sizePolicy().hasHeightForWidth() ) );
    QLCDNImporte->setNumDigits( 8 );
    layout50_2_2->addWidget( QLCDNImporte );
    layout27->addLayout( layout50_2_2 );

    groupBox1Layout->addLayout( layout27, 1, 2 );

    layout28_2 = new QVBoxLayout( 0, 0, 6, "layout28_2"); 

    layout50_3_2 = new QVBoxLayout( 0, 0, 6, "layout50_3_2"); 

    textLabel2_6_3_2 = new QLabel( groupBox1, "textLabel2_6_3_2" );
    textLabel2_6_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6_3_2->sizePolicy().hasHeightForWidth() ) );
    layout50_3_2->addWidget( textLabel2_6_3_2 );

    QLCDTotalOrdenSinIva = new QLCDNumber( groupBox1, "QLCDTotalOrdenSinIva" );
    QLCDTotalOrdenSinIva->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDTotalOrdenSinIva->sizePolicy().hasHeightForWidth() ) );
    QLCDTotalOrdenSinIva->setNumDigits( 8 );
    layout50_3_2->addWidget( QLCDTotalOrdenSinIva );
    layout28_2->addLayout( layout50_3_2 );

    layout50_3 = new QVBoxLayout( 0, 0, 6, "layout50_3"); 

    textLabel2_6_3 = new QLabel( groupBox1, "textLabel2_6_3" );
    textLabel2_6_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6_3->sizePolicy().hasHeightForWidth() ) );
    layout50_3->addWidget( textLabel2_6_3 );

    QLCDIva = new QLCDNumber( groupBox1, "QLCDIva" );
    QLCDIva->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDIva->sizePolicy().hasHeightForWidth() ) );
    QLCDIva->setNumDigits( 8 );
    layout50_3->addWidget( QLCDIva );
    layout28_2->addLayout( layout50_3 );

    layout50 = new QVBoxLayout( 0, 0, 6, "layout50"); 

    textLabel2_6 = new QLabel( groupBox1, "textLabel2_6" );
    textLabel2_6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6->sizePolicy().hasHeightForWidth() ) );
    layout50->addWidget( textLabel2_6 );

    QLCDTotalOrden = new QLCDNumber( groupBox1, "QLCDTotalOrden" );
    QLCDTotalOrden->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDTotalOrden->sizePolicy().hasHeightForWidth() ) );
    QLCDTotalOrden->setNumDigits( 8 );
    layout50->addWidget( QLCDTotalOrden );
    layout28_2->addLayout( layout50 );

    groupBox1Layout->addMultiCellLayout( layout28_2, 0, 1, 3, 3 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel1_6 = new QLabel( groupBox1, "textLabel1_6" );
    layout25->addWidget( textLabel1_6 );

    QCtrPProducto = new QCtrlPreciosProductos( groupBox1, "QCtrPProducto" );
    layout25->addWidget( QCtrPProducto );

    groupBox1Layout->addMultiCellLayout( layout25, 0, 1, 1, 1 );

    layout23_2 = new QVBoxLayout( 0, 0, 6, "layout23_2"); 

    layout61 = new QVBoxLayout( 0, 0, 6, "layout61"); 

    textLabel2_5 = new QLabel( groupBox1, "textLabel2_5" );
    textLabel2_5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5->sizePolicy().hasHeightForWidth() ) );
    layout61->addWidget( textLabel2_5 );

    QLECliente = new QLineEdit( groupBox1, "QLECliente" );
    QLECliente->setReadOnly( TRUE );
    layout61->addWidget( QLECliente );
    layout23_2->addLayout( layout61 );

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    textLabel2_3 = new QLabel( groupBox1, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout43->addWidget( textLabel2_3 );

    QTEDescripcion = new QTextEdit( groupBox1, "QTEDescripcion" );
    QTEDescripcion->setMaximumSize( QSize( 32767, 150 ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout43->addWidget( QTEDescripcion );
    layout23_2->addLayout( layout43 );

    groupBox1Layout->addMultiCellLayout( layout23_2, 0, 1, 0, 0 );

    Ventas3QtLayout->addWidget( groupBox1, 2, 0 );
    languageChange();
    resize( QSize(973, 619).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Ventas3Qt::~Ventas3Qt()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Ventas3Qt::languageChange()
{
    setCaption( tr( "Ventas..." ) );
    textLabel1_5->setText( tr( "Tipo Precio" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel2_2_2->setText( tr( "Cantidad" ) );
    QLECantidad->setText( tr( "1" ) );
    textLabel2_2_2_2->setText( tr( "Por Importe" ) );
    textLabel1_2->setText( tr( "Clientes" ) );
    textLabel1_3->setText( tr( "Contactos" ) );
    textLabel1_4->setText( tr( "Forma De Pago" ) );
    textLabel2_4->setText( tr( "Detalle Orden" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Escala" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Tipo Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Importe" ) );
    QPBAnexar->setText( tr( "Anexar A La Orden" ) );
    pushButton5_2->setText( tr( "Realizar Venta" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBRegistra->setText( tr( "Realizar Ventas" ) );
    QPBEliminar->setText( tr( "Eliminar Productos" ) );
    groupBox1->setTitle( tr( "Datos Orden" ) );
    textLabel2_6_2_3->setText( tr( "Existencia" ) );
    QBGTOrden->setTitle( tr( "Tipo De Venta" ) );
    QRBRemision->setText( trUtf8( "\x52\x65\x6d\x69\x73\x69\xc3\xb3\x6e" ) );
    QRBFactura->setText( tr( "Factura" ) );
    QRBCotizacion->setText( tr( "Cotizacion" ) );
    textLabel2_6_2->setText( tr( "Precio Producto" ) );
    textLabel2_6_2_2->setText( tr( "Importe Producto" ) );
    textLabel2_6_3_2->setText( tr( "Total De La Orden Sin IVA" ) );
    textLabel2_6_3->setText( tr( "IVA" ) );
    textLabel2_6->setText( tr( "Total De La Orden" ) );
    textLabel1_6->setText( tr( "Escalas Del Producto" ) );
    textLabel2_5->setText( tr( "Cliente" ) );
    textLabel2_3->setText( tr( "Descripcion Producto" ) );
}

