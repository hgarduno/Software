/****************************************************************************
** Form implementation generated from reading ui file 'UI/Compras.ui'
**
** Created: Thu Apr 11 20:30:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Compras.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <QCtrlProductos.h>
#include <QCtrlContactos.h>
#include <QCtrlFormaPago.h>
#include <QCtrlClientes.h>
#include <qgroupbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProductos.h"
#include "QCtrlEmpresas.h"
#include "QCtrlContactos.h"
#include "QCtrlFormaPago.h"

/*
 *  Constructs a Compras as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Compras::Compras( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Compras" );
    ComprasLayout = new QGridLayout( this, 1, 1, 11, 6, "ComprasLayout"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( textLabel2_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( QLECantidad );
    layout13->addLayout( layout6 );

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout6_2->addWidget( textLabel2_2_2 );

    QLEPrecio = new QLineEdit( this, "QLEPrecio" );
    QLEPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPrecio->sizePolicy().hasHeightForWidth() ) );
    layout6_2->addWidget( QLEPrecio );
    layout13->addLayout( layout6_2 );

    layout6_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_2_2"); 

    textLabel2_2_2_2 = new QLabel( this, "textLabel2_2_2_2" );
    textLabel2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout6_2_2->addWidget( textLabel2_2_2_2 );

    QLENFactura = new QLineEdit( this, "QLENFactura" );
    layout6_2_2->addWidget( QLENFactura );
    layout13->addLayout( layout6_2_2 );

    ComprasLayout->addLayout( layout13, 1, 0 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout14->addWidget( textLabel5 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio Compra" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Factura" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Proveedor" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Contacto" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 6 );
    QTDatos->setReadOnly( TRUE );
    layout14->addWidget( QTDatos );

    ComprasLayout->addLayout( layout14, 3, 0 );

    layout24 = new QHBoxLayout( 0, 0, 6, "layout24"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    layout24->addWidget( QPBAnexar );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setEnabled( FALSE );
    layout24->addWidget( QPBRegistra );

    pushButton1_2_2 = new QPushButton( this, "pushButton1_2_2" );
    layout24->addWidget( pushButton1_2_2 );

    ComprasLayout->addLayout( layout24, 4, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductos( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrProductos );
    layout22->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlEmpresas( this, "QCtrProveedores" );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCtrProveedores );
    layout22->addLayout( layout2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel1_2 );

    QCtrContactos = new QCtrlContactos( this, "QCtrContactos" );
    QCtrContactos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrContactos->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrContactos );
    layout22->addLayout( layout3 );

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout21->addWidget( textLabel1_3 );

    QCtrFPago = new QCtrlFormaPago( this, "QCtrFPago" );
    QCtrFPago->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrFPago->sizePolicy().hasHeightForWidth() ) );
    layout21->addWidget( QCtrFPago );
    layout22->addLayout( layout21 );

    ComprasLayout->addLayout( layout22, 0, 0 );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel4 = new QLabel( groupBox1, "textLabel4" );
    layout8->addWidget( textLabel4 );

    QLEUCProducto = new QLineEdit( groupBox1, "QLEUCProducto" );
    QLEUCProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEUCProducto->sizePolicy().hasHeightForWidth() ) );
    QLEUCProducto->setReadOnly( TRUE );
    layout8->addWidget( QLEUCProducto );
    layout35->addLayout( layout8 );

    layout8_3 = new QVBoxLayout( 0, 0, 6, "layout8_3"); 

    textLabel4_3 = new QLabel( groupBox1, "textLabel4_3" );
    textLabel4_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_3->sizePolicy().hasHeightForWidth() ) );
    layout8_3->addWidget( textLabel4_3 );

    QLEUCCantidad = new QLineEdit( groupBox1, "QLEUCCantidad" );
    QLEUCCantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEUCCantidad->sizePolicy().hasHeightForWidth() ) );
    QLEUCCantidad->setReadOnly( TRUE );
    layout8_3->addWidget( QLEUCCantidad );
    layout35->addLayout( layout8_3 );

    layout8_4 = new QVBoxLayout( 0, 0, 6, "layout8_4"); 

    textLabel4_4 = new QLabel( groupBox1, "textLabel4_4" );
    textLabel4_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_4->sizePolicy().hasHeightForWidth() ) );
    layout8_4->addWidget( textLabel4_4 );

    QLEUCPrecio = new QLineEdit( groupBox1, "QLEUCPrecio" );
    QLEUCPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEUCPrecio->sizePolicy().hasHeightForWidth() ) );
    QLEUCPrecio->setReadOnly( TRUE );
    layout8_4->addWidget( QLEUCPrecio );
    layout35->addLayout( layout8_4 );
    layout36->addLayout( layout35 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout36->addItem( spacer1 );

    groupBox1Layout->addLayout( layout36, 0, 0 );

    layout38 = new QHBoxLayout( 0, 0, 6, "layout38"); 

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    textLabel4_2 = new QLabel( groupBox1, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout8_2->addWidget( textLabel4_2 );

    QLEUCProveedor = new QLineEdit( groupBox1, "QLEUCProveedor" );
    QLEUCProveedor->setReadOnly( TRUE );
    layout8_2->addWidget( QLEUCProveedor );
    layout37->addLayout( layout8_2 );

    layout8_3_2 = new QVBoxLayout( 0, 0, 6, "layout8_3_2"); 

    textLabel4_3_2 = new QLabel( groupBox1, "textLabel4_3_2" );
    textLabel4_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4_3_2->sizePolicy().hasHeightForWidth() ) );
    layout8_3_2->addWidget( textLabel4_3_2 );

    QLEUCContacto = new QLineEdit( groupBox1, "QLEUCContacto" );
    QLEUCContacto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEUCContacto->sizePolicy().hasHeightForWidth() ) );
    QLEUCContacto->setReadOnly( TRUE );
    layout8_3_2->addWidget( QLEUCContacto );
    layout37->addLayout( layout8_3_2 );
    layout38->addLayout( layout37 );

    layout8_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout8_3_2_2"); 

    textLabel4_3_2_2 = new QLabel( groupBox1, "textLabel4_3_2_2" );
    textLabel4_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout8_3_2_2->addWidget( textLabel4_3_2_2 );

    QLEUCFactura = new QLineEdit( groupBox1, "QLEUCFactura" );
    QLEUCFactura->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEUCFactura->sizePolicy().hasHeightForWidth() ) );
    QLEUCFactura->setReadOnly( TRUE );
    layout8_3_2_2->addWidget( QLEUCFactura );
    layout38->addLayout( layout8_3_2_2 );

    layout8_3_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout8_3_2_2_2"); 

    textLabel4_3_2_2_2 = new QLabel( groupBox1, "textLabel4_3_2_2_2" );
    textLabel4_3_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4_3_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout8_3_2_2_2->addWidget( textLabel4_3_2_2_2 );

    QLEUCFecha = new QLineEdit( groupBox1, "QLEUCFecha" );
    QLEUCFecha->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEUCFecha->sizePolicy().hasHeightForWidth() ) );
    QLEUCFecha->setReadOnly( TRUE );
    layout8_3_2_2_2->addWidget( QLEUCFecha );
    layout38->addLayout( layout8_3_2_2_2 );

    groupBox1Layout->addLayout( layout38, 1, 0 );

    ComprasLayout->addWidget( groupBox1, 2, 0 );
    languageChange();
    resize( QSize(789, 543).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Compras::~Compras()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Compras::languageChange()
{
    setCaption( tr( "Registro De Compras" ) );
    textLabel2_2->setText( tr( "Cantidad" ) );
    textLabel2_2_2->setText( tr( "Precio Compra" ) );
    textLabel2_2_2_2->setText( tr( "No Factura" ) );
    textLabel5->setText( tr( "Detalle Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Precio Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Factura" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Proveedor" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Contacto" ) );
    QPBAnexar->setText( tr( "Anexar Compra" ) );
    QPBRegistra->setText( tr( "Registra Compra" ) );
    pushButton1_2_2->setText( tr( "pushButton1" ) );
    textLabel1->setText( tr( "Producto" ) );
    textLabel2->setText( tr( "Proveedor" ) );
    textLabel1_2->setText( tr( "Contacto Proveedor" ) );
    textLabel1_3->setText( tr( "Forma De Pago" ) );
    groupBox1->setTitle( tr( "Datos Ultima Compra" ) );
    textLabel4->setText( tr( "Producto" ) );
    textLabel4_3->setText( tr( "Cantidad" ) );
    textLabel4_4->setText( tr( "Precio Compra" ) );
    textLabel4_2->setText( tr( "Proveedor" ) );
    textLabel4_3_2->setText( tr( "Contacto" ) );
    textLabel4_3_2_2->setText( tr( "# Factura" ) );
    textLabel4_3_2_2_2->setText( tr( "Fecha" ) );
}

