/****************************************************************************
** Form implementation generated from reading ui file 'UI/Compras.ui'
**
** Created: Fri Apr 12 21:35:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Compras.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <QCtrlOrigenCompra.h>
#include <IMP_QControlFecha.h>
#include <qcombobox.h>
#include <QCtrlCmbBodegas.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlOrigenCompra.h"
#include "IMP_QControlFecha.h"
#include "QCtrlCmbBodegas.h"

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

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    QPBAnexar->setMinimumSize( QSize( 0, 0 ) );
    QPBAnexar->setMaximumSize( QSize( 32767, 70 ) );
    layout29->addWidget( QPBAnexar );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    QPBRegistrar->setMinimumSize( QSize( 0, 0 ) );
    QPBRegistrar->setMaximumSize( QSize( 32767, 70 ) );
    layout29->addWidget( QPBRegistrar );

    QPBECompra = new QPushButton( this, "QPBECompra" );
    QPBECompra->setMinimumSize( QSize( 0, 0 ) );
    QPBECompra->setMaximumSize( QSize( 32767, 70 ) );
    layout29->addWidget( QPBECompra );

    ComprasLayout->addLayout( layout29, 4, 0 );

    QGBUCompra = new QGroupBox( this, "QGBUCompra" );
    QGBUCompra->setColumnLayout(0, Qt::Vertical );
    QGBUCompra->layout()->setSpacing( 6 );
    QGBUCompra->layout()->setMargin( 11 );
    QGBUCompraLayout = new QGridLayout( QGBUCompra->layout() );
    QGBUCompraLayout->setAlignment( Qt::AlignTop );

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel2_2 = new QLabel( QGBUCompra, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout18->addWidget( textLabel2_2 );

    QLEFechaCompra = new QLineEdit( QGBUCompra, "QLEFechaCompra" );
    QLEFechaCompra->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFechaCompra->sizePolicy().hasHeightForWidth() ) );
    QLEFechaCompra->setReadOnly( TRUE );
    layout18->addWidget( QLEFechaCompra );

    QGBUCompraLayout->addLayout( layout18, 0, 0 );

    layout110_2_3 = new QVBoxLayout( 0, 0, 6, "layout110_2_3"); 

    textLabel17_2_3 = new QLabel( QGBUCompra, "textLabel17_2_3" );
    textLabel17_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel17_2_3->sizePolicy().hasHeightForWidth() ) );
    layout110_2_3->addWidget( textLabel17_2_3 );

    QLECantidadUC = new QLineEdit( QGBUCompra, "QLECantidadUC" );
    QLECantidadUC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidadUC->sizePolicy().hasHeightForWidth() ) );
    QLECantidadUC->setReadOnly( TRUE );
    layout110_2_3->addWidget( QLECantidadUC );

    QGBUCompraLayout->addLayout( layout110_2_3, 0, 1 );

    layout110_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout110_2_2_2"); 

    textLabel17_2_2_2 = new QLabel( QGBUCompra, "textLabel17_2_2_2" );
    textLabel17_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel17_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout110_2_2_2->addWidget( textLabel17_2_2_2 );

    QLEPCompraUC = new QLineEdit( QGBUCompra, "QLEPCompraUC" );
    QLEPCompraUC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPCompraUC->sizePolicy().hasHeightForWidth() ) );
    QLEPCompraUC->setReadOnly( TRUE );
    layout110_2_2_2->addWidget( QLEPCompraUC );

    QGBUCompraLayout->addLayout( layout110_2_2_2, 0, 2 );

    layout110_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout110_2_2_2_2"); 

    textLabel17_2_2_2_2 = new QLabel( QGBUCompra, "textLabel17_2_2_2_2" );
    textLabel17_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel17_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout110_2_2_2_2->addWidget( textLabel17_2_2_2_2 );

    QLEPCompraUC_2 = new QLineEdit( QGBUCompra, "QLEPCompraUC_2" );
    QLEPCompraUC_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPCompraUC_2->sizePolicy().hasHeightForWidth() ) );
    QLEPCompraUC_2->setReadOnly( TRUE );
    layout110_2_2_2_2->addWidget( QLEPCompraUC_2 );

    QGBUCompraLayout->addLayout( layout110_2_2_2_2, 0, 3 );

    layout110_3_3 = new QVBoxLayout( 0, 0, 6, "layout110_3_3"); 

    textLabel17_3_4 = new QLabel( QGBUCompra, "textLabel17_3_4" );
    textLabel17_3_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel17_3_4->sizePolicy().hasHeightForWidth() ) );
    layout110_3_3->addWidget( textLabel17_3_4 );

    QLENumFacturaUC = new QLineEdit( QGBUCompra, "QLENumFacturaUC" );
    QLENumFacturaUC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumFacturaUC->sizePolicy().hasHeightForWidth() ) );
    QLENumFacturaUC->setReadOnly( TRUE );
    layout110_3_3->addWidget( QLENumFacturaUC );

    QGBUCompraLayout->addLayout( layout110_3_3, 0, 4 );

    layout83 = new QHBoxLayout( 0, 0, 6, "layout83"); 

    layout48_2 = new QVBoxLayout( 0, 0, 6, "layout48_2"); 

    textLabel6_2 = new QLabel( QGBUCompra, "textLabel6_2" );
    textLabel6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel6_2->sizePolicy().hasHeightForWidth() ) );
    layout48_2->addWidget( textLabel6_2 );

    QLERSUltimaCompra = new QLineEdit( QGBUCompra, "QLERSUltimaCompra" );
    QLERSUltimaCompra->setMinimumSize( QSize( 300, 0 ) );
    QLERSUltimaCompra->setReadOnly( TRUE );
    layout48_2->addWidget( QLERSUltimaCompra );
    layout83->addLayout( layout48_2 );

    layout110_3_2 = new QVBoxLayout( 0, 0, 6, "layout110_3_2"); 

    textLabel17_3_3 = new QLabel( QGBUCompra, "textLabel17_3_3" );
    textLabel17_3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel17_3_3->sizePolicy().hasHeightForWidth() ) );
    layout110_3_2->addWidget( textLabel17_3_3 );

    QLEUnidades = new QLineEdit( QGBUCompra, "QLEUnidades" );
    QLEUnidades->setReadOnly( TRUE );
    layout110_3_2->addWidget( QLEUnidades );
    layout83->addLayout( layout110_3_2 );

    QGBUCompraLayout->addLayout( layout83, 0, 5 );

    ComprasLayout->addWidget( QGBUCompra, 1, 0 );

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout24->addWidget( textLabel6 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout24->addWidget( QLEDescripcion );

    ComprasLayout->addLayout( layout24, 3, 0 );

    groupBox2 = new QGroupBox( this, "groupBox2" );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    layout28_2_2 = new QVBoxLayout( 0, 0, 6, "layout28_2_2"); 

    textLabel1_3_2_2 = new QLabel( groupBox2, "textLabel1_3_2_2" );
    textLabel1_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout28_2_2->addWidget( textLabel1_3_2_2 );

    QCtrOrigenCompra = new QCtrlOrigenCompra( groupBox2, "QCtrOrigenCompra" );
    QCtrOrigenCompra->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrOrigenCompra->sizePolicy().hasHeightForWidth() ) );
    layout28_2_2->addWidget( QCtrOrigenCompra );
    layout36->addLayout( layout28_2_2 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel17 = new QLabel( groupBox2, "textLabel17" );
    textLabel17->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel17->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel17 );

    QCFCompra = new CQControlFecha( groupBox2, "QCFCompra" );
    QCFCompra->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCFCompra->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( QCFCompra );
    layout36->addLayout( layout10 );

    layout46 = new QVBoxLayout( 0, 0, 6, "layout46"); 

    textLabel5 = new QLabel( groupBox2, "textLabel5" );
    layout46->addWidget( textLabel5 );

    QCBProductos = new QComboBox( FALSE, groupBox2, "QCBProductos" );
    QCBProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCBProductos->sizePolicy().hasHeightForWidth() ) );
    QCBProductos->setMinimumSize( QSize( 200, 0 ) );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout46->addWidget( QCBProductos );
    layout36->addLayout( layout46 );

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel1_2 = new QLabel( groupBox2, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( textLabel1_2 );

    QCtrCmbBodegas = new QCtrlCmbBodegas( groupBox2, "QCtrCmbBodegas" );
    QCtrCmbBodegas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrCmbBodegas->sizePolicy().hasHeightForWidth() ) );
    QCtrCmbBodegas->setMinimumSize( QSize( 150, 0 ) );
    layout26->addWidget( QCtrCmbBodegas );
    layout36->addLayout( layout26 );

    layout46_2 = new QVBoxLayout( 0, 0, 6, "layout46_2"); 

    textLabel5_2 = new QLabel( groupBox2, "textLabel5_2" );
    layout46_2->addWidget( textLabel5_2 );

    QCBProveedores = new QComboBox( FALSE, groupBox2, "QCBProveedores" );
    QCBProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCBProveedores->sizePolicy().hasHeightForWidth() ) );
    QCBProveedores->setMinimumSize( QSize( 200, 0 ) );
    QCBProveedores->setEditable( TRUE );
    QCBProveedores->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProveedores->setAutoCompletion( TRUE );
    QCBProveedores->setDuplicatesEnabled( FALSE );
    layout46_2->addWidget( QCBProveedores );
    layout36->addLayout( layout46_2 );

    layout46_2_2 = new QVBoxLayout( 0, 0, 6, "layout46_2_2"); 

    textLabel5_2_2 = new QLabel( groupBox2, "textLabel5_2_2" );
    layout46_2_2->addWidget( textLabel5_2_2 );

    QCBFormaPago = new QComboBox( FALSE, groupBox2, "QCBFormaPago" );
    QCBFormaPago->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCBFormaPago->sizePolicy().hasHeightForWidth() ) );
    QCBFormaPago->setMinimumSize( QSize( 200, 0 ) );
    QCBFormaPago->setEditable( TRUE );
    QCBFormaPago->setInsertionPolicy( QComboBox::NoInsertion );
    QCBFormaPago->setAutoCompletion( TRUE );
    QCBFormaPago->setDuplicatesEnabled( FALSE );
    layout46_2_2->addWidget( QCBFormaPago );
    layout36->addLayout( layout46_2_2 );

    groupBox2Layout->addLayout( layout36, 0, 0 );

    layout27 = new QHBoxLayout( 0, 0, 6, "layout27"); 

    layout110_2 = new QVBoxLayout( 0, 0, 6, "layout110_2"); 

    textLabel17_2 = new QLabel( groupBox2, "textLabel17_2" );
    layout110_2->addWidget( textLabel17_2 );

    QLECantidad = new QLineEdit( groupBox2, "QLECantidad" );
    layout110_2->addWidget( QLECantidad );
    layout27->addLayout( layout110_2 );

    layout110_2_4 = new QVBoxLayout( 0, 0, 6, "layout110_2_4"); 

    textLabel17_2_4 = new QLabel( groupBox2, "textLabel17_2_4" );
    layout110_2_4->addWidget( textLabel17_2_4 );

    QLECantidadATransferirZacatenco = new QLineEdit( groupBox2, "QLECantidadATransferirZacatenco" );
    layout110_2_4->addWidget( QLECantidadATransferirZacatenco );
    layout27->addLayout( layout110_2_4 );

    layout110_2_2 = new QVBoxLayout( 0, 0, 6, "layout110_2_2"); 

    textLabel17_2_2 = new QLabel( groupBox2, "textLabel17_2_2" );
    layout110_2_2->addWidget( textLabel17_2_2 );

    QLEPCompra = new QLineEdit( groupBox2, "QLEPCompra" );
    layout110_2_2->addWidget( QLEPCompra );
    layout27->addLayout( layout110_2_2 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel1 = new QLabel( groupBox2, "textLabel1" );
    layout14->addWidget( textLabel1 );

    QLEPVenta = new QLineEdit( groupBox2, "QLEPVenta" );
    layout14->addWidget( QLEPVenta );
    layout27->addLayout( layout14 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel2 = new QLabel( groupBox2, "textLabel2" );
    layout16->addWidget( textLabel2 );

    QCBTipoPrecio = new QComboBox( FALSE, groupBox2, "QCBTipoPrecio" );
    QCBTipoPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCBTipoPrecio->sizePolicy().hasHeightForWidth() ) );
    QCBTipoPrecio->setMinimumSize( QSize( 150, 0 ) );
    QCBTipoPrecio->setEditable( TRUE );
    QCBTipoPrecio->setInsertionPolicy( QComboBox::NoInsertion );
    QCBTipoPrecio->setAutoCompletion( TRUE );
    QCBTipoPrecio->setDuplicatesEnabled( FALSE );
    layout16->addWidget( QCBTipoPrecio );
    layout27->addLayout( layout16 );

    layout110_3 = new QVBoxLayout( 0, 0, 6, "layout110_3"); 

    textLabel17_3 = new QLabel( groupBox2, "textLabel17_3" );
    layout110_3->addWidget( textLabel17_3 );

    QLENumFactura = new QLineEdit( groupBox2, "QLENumFactura" );
    layout110_3->addWidget( QLENumFactura );
    layout27->addLayout( layout110_3 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel17_3_2 = new QLabel( groupBox2, "textLabel17_3_2" );
    layout11->addWidget( textLabel17_3_2 );

    QCFPago = new CQControlFecha( groupBox2, "QCFPago" );
    QCFPago->setEnabled( FALSE );
    layout11->addWidget( QCFPago );
    layout27->addLayout( layout11 );
    spacer1 = new QSpacerItem( 130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout27->addItem( spacer1 );

    groupBox2Layout->addLayout( layout27, 1, 0 );

    ComprasLayout->addWidget( groupBox2, 0, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cant. A Zacatenco" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio Compra" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "IVA" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Proveedor" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Forma De Pago" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha De Pago" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Numero Factura" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 9 );
    QTDatos->setReadOnly( TRUE );

    ComprasLayout->addWidget( QTDatos, 2, 0 );
    languageChange();
    resize( QSize(1038, 539).expandedTo(minimumSizeHint()) );
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
    setCaption( tr( "Form1" ) );
    QPBAnexar->setText( tr( "Anexar \n"
"Compra" ) );
    QPBRegistrar->setText( tr( "Registrar \n"
"Compras" ) );
    QPBECompra->setText( tr( "Eliminar \n"
"Compra" ) );
    QGBUCompra->setTitle( tr( "Ultima Compra" ) );
    textLabel2_2->setText( tr( "Fecha Compra" ) );
    textLabel17_2_3->setText( tr( "Cantidad" ) );
    textLabel17_2_2_2->setText( tr( "Precio De Compra" ) );
    textLabel17_2_2_2_2->setText( tr( "Precio De Compra" ) );
    textLabel17_3_4->setText( tr( "Numero De Factura" ) );
    textLabel6_2->setText( tr( "Proveedor Ultima Compra" ) );
    textLabel17_3_3->setText( tr( "Unidades" ) );
    textLabel6->setText( tr( "Descripcion" ) );
    groupBox2->setTitle( tr( "Compra Actual" ) );
    textLabel1_3_2_2->setText( tr( "Origen Compra" ) );
    textLabel17->setText( tr( "Fecha" ) );
    textLabel5->setText( tr( "Productos" ) );
    textLabel1_2->setText( tr( "Bodegas" ) );
    textLabel5_2->setText( tr( "Proveedor" ) );
    textLabel5_2_2->setText( tr( "Forma De Pago" ) );
    QCBFormaPago->clear();
    QCBFormaPago->insertItem( tr( "Contado" ) );
    QCBFormaPago->insertItem( tr( "Credito" ) );
    textLabel17_2->setText( tr( "Cantidad" ) );
    textLabel17_2_4->setText( tr( "Cantidad A Transferir" ) );
    QLECantidadATransferirZacatenco->setText( tr( "1" ) );
    textLabel17_2_2->setText( tr( "P. Compra" ) );
    textLabel1->setText( tr( "P. Venta" ) );
    textLabel2->setText( tr( "Tipo Precio" ) );
    textLabel17_3->setText( tr( "Numero De Factura" ) );
    textLabel17_3_2->setText( tr( "Fecha De Pago" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Cant. A Zacatenco" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Precio Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "IVA" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Proveedor" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Forma De Pago" ) );
    QTDatos->horizontalHeader()->setLabel( 7, tr( "Fecha De Pago" ) );
    QTDatos->horizontalHeader()->setLabel( 8, tr( "Numero Factura" ) );
}

