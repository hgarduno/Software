/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenCompras.ui'
**
** Created: Thu Apr 11 21:39:56 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenCompras.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qgroupbox.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a OrdenCompras as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
OrdenCompras::OrdenCompras( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "OrdenCompras" );
    OrdenComprasLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenComprasLayout"); 

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    layout1->addWidget( QCBProductos );
    layout29->addLayout( layout1 );

    layout3_2_3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2_3_2"); 

    textLabel4_2_3_2 = new QLabel( this, "textLabel4_2_3_2" );
    textLabel4_2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_2_3_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2_3_2->addWidget( textLabel4_2_3_2 );

    QLEPrecioVenta = new QLineEdit( this, "QLEPrecioVenta" );
    QLEPrecioVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPrecioVenta->sizePolicy().hasHeightForWidth() ) );
    layout3_2_3_2->addWidget( QLEPrecioVenta );
    layout29->addLayout( layout3_2_3_2 );

    OrdenComprasLayout->addMultiCellLayout( layout29, 0, 0, 0, 2 );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel4 = new QLabel( groupBox1, "textLabel4" );
    layout3->addWidget( textLabel4 );

    QLEComSemAnterior = new QLineEdit( groupBox1, "QLEComSemAnterior" );
    layout3->addWidget( QLEComSemAnterior );
    layout5->addLayout( layout3 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel4_2 = new QLabel( groupBox1, "textLabel4_2" );
    layout3_2->addWidget( textLabel4_2 );

    QLEVenSemAnterior = new QLineEdit( groupBox1, "QLEVenSemAnterior" );
    layout3_2->addWidget( QLEVenSemAnterior );
    layout5->addLayout( layout3_2 );

    groupBox1Layout->addLayout( layout5, 0, 0 );

    OrdenComprasLayout->addWidget( groupBox1, 1, 0 );

    groupBox1_2 = new QGroupBox( this, "groupBox1_2" );
    groupBox1_2->setColumnLayout(0, Qt::Vertical );
    groupBox1_2->layout()->setSpacing( 6 );
    groupBox1_2->layout()->setMargin( 11 );
    groupBox1_2Layout = new QGridLayout( groupBox1_2->layout() );
    groupBox1_2Layout->setAlignment( Qt::AlignTop );

    layout5_2 = new QHBoxLayout( 0, 0, 6, "layout5_2"); 

    layout3_3 = new QVBoxLayout( 0, 0, 6, "layout3_3"); 

    textLabel4_3 = new QLabel( groupBox1_2, "textLabel4_3" );
    layout3_3->addWidget( textLabel4_3 );

    QLEComSemActual = new QLineEdit( groupBox1_2, "QLEComSemActual" );
    layout3_3->addWidget( QLEComSemActual );
    layout5_2->addLayout( layout3_3 );

    layout3_2_2 = new QVBoxLayout( 0, 0, 6, "layout3_2_2"); 

    textLabel4_2_2 = new QLabel( groupBox1_2, "textLabel4_2_2" );
    layout3_2_2->addWidget( textLabel4_2_2 );

    QLEVenSemActual = new QLineEdit( groupBox1_2, "QLEVenSemActual" );
    layout3_2_2->addWidget( QLEVenSemActual );
    layout5_2->addLayout( layout3_2_2 );

    groupBox1_2Layout->addLayout( layout5_2, 0, 0 );

    OrdenComprasLayout->addWidget( groupBox1_2, 1, 1 );

    groupBox1_3 = new QGroupBox( this, "groupBox1_3" );
    groupBox1_3->setColumnLayout(0, Qt::Vertical );
    groupBox1_3->layout()->setSpacing( 6 );
    groupBox1_3->layout()->setMargin( 11 );
    groupBox1_3Layout = new QGridLayout( groupBox1_3->layout() );
    groupBox1_3Layout->setAlignment( Qt::AlignTop );

    layout3_4 = new QVBoxLayout( 0, 0, 6, "layout3_4"); 

    textLabel4_4 = new QLabel( groupBox1_3, "textLabel4_4" );
    layout3_4->addWidget( textLabel4_4 );

    QLEExistencia = new QLineEdit( groupBox1_3, "QLEExistencia" );
    layout3_4->addWidget( QLEExistencia );

    groupBox1_3Layout->addLayout( layout3_4, 0, 0 );

    layout3_2_3 = new QVBoxLayout( 0, 0, 6, "layout3_2_3"); 

    textLabel4_2_3 = new QLabel( groupBox1_3, "textLabel4_2_3" );
    layout3_2_3->addWidget( textLabel4_2_3 );

    QLEExBodega = new QLineEdit( groupBox1_3, "QLEExBodega" );
    layout3_2_3->addWidget( QLEExBodega );

    groupBox1_3Layout->addLayout( layout3_2_3, 0, 1 );

    layout3_2_3_3 = new QVBoxLayout( 0, 0, 6, "layout3_2_3_3"); 

    textLabel4_2_3_3 = new QLabel( groupBox1_3, "textLabel4_2_3_3" );
    layout3_2_3_3->addWidget( textLabel4_2_3_3 );

    QLETransferencias = new QLineEdit( groupBox1_3, "QLETransferencias" );
    layout3_2_3_3->addWidget( QLETransferencias );

    groupBox1_3Layout->addLayout( layout3_2_3_3, 0, 2 );

    OrdenComprasLayout->addWidget( groupBox1_3, 1, 2 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    QPBProductosFaltantes = new QPushButton( this, "QPBProductosFaltantes" );
    layout19->addWidget( QPBProductosFaltantes );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout19->addWidget( pushButton1_2 );

    OrdenComprasLayout->addMultiCellLayout( layout19, 5, 5, 0, 2 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QTEDescripcion );

    OrdenComprasLayout->addMultiCellLayout( layout2, 4, 4, 0, 2 );

    layout32 = new QVBoxLayout( 0, 0, 6, "layout32"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout32->addWidget( textLabel5 );

    QTOrdenCompra = new QTable( this, "QTOrdenCompra" );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Clave Producto" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Clave Provedor" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Cantidad" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Precio Sin Iva" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Precio Compra" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Proveedor" ) );
    QTOrdenCompra->setNumCols( QTOrdenCompra->numCols() + 1 );
    QTOrdenCompra->horizontalHeader()->setLabel( QTOrdenCompra->numCols() - 1, tr( "Cantidad Adquirir" ) );
    QTOrdenCompra->setNumRows( 0 );
    QTOrdenCompra->setNumCols( 7 );
    QTOrdenCompra->setReadOnly( TRUE );
    layout32->addWidget( QTOrdenCompra );

    OrdenComprasLayout->addMultiCellLayout( layout32, 3, 3, 0, 2 );

    layout34 = new QHBoxLayout( 0, 0, 6, "layout34"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout12->addWidget( textLabel3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha Compra" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "P Compra" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "P Sin Iva" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Factura" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Proveedor" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Clave Proveedor" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 7 );
    QTDatos->setReadOnly( TRUE );
    layout12->addWidget( QTDatos );
    layout34->addLayout( layout12 );

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout12_2->addWidget( textLabel3_2 );

    QTTransferencias = new QTable( this, "QTTransferencias" );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Cantidad" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Expendio" ) );
    QTTransferencias->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, QTTransferencias->sizePolicy().hasHeightForWidth() ) );
    QTTransferencias->setNumRows( 0 );
    QTTransferencias->setNumCols( 2 );
    layout12_2->addWidget( QTTransferencias );
    layout34->addLayout( layout12_2 );

    OrdenComprasLayout->addMultiCellLayout( layout34, 2, 2, 0, 2 );
    languageChange();
    resize( QSize(1018, 791).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenCompras::~OrdenCompras()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenCompras::languageChange()
{
    setCaption( tr( "Orden De Compra" ) );
    textLabel1->setText( tr( "Producto" ) );
    textLabel4_2_3_2->setText( tr( "Precio Venta" ) );
    groupBox1->setTitle( tr( "Semestre Anterior" ) );
    textLabel4->setText( tr( "Compras" ) );
    textLabel4_2->setText( tr( "Ventas" ) );
    groupBox1_2->setTitle( tr( "Semestre Actual" ) );
    textLabel4_3->setText( tr( "Compras" ) );
    textLabel4_2_2->setText( tr( "Ventas" ) );
    groupBox1_3->setTitle( tr( "Existencias" ) );
    textLabel4_4->setText( tr( "Expendio" ) );
    textLabel4_2_3->setText( tr( "Bodega" ) );
    textLabel4_2_3_3->setText( tr( "Transferencias" ) );
    QPBProductosFaltantes->setText( tr( "Productos Faltantes" ) );
    pushButton1_2->setText( tr( "pushButton1" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    textLabel5->setText( tr( "Orden de Compras" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 0, tr( "Clave Producto" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 1, tr( "Clave Provedor" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 3, tr( "Precio Sin Iva" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 4, tr( "Precio Compra" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 5, tr( "Proveedor" ) );
    QTOrdenCompra->horizontalHeader()->setLabel( 6, tr( "Cantidad Adquirir" ) );
    textLabel3->setText( tr( "Historico Compras" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Fecha Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "P Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "P Sin Iva" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Factura" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Proveedor" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Clave Proveedor" ) );
    textLabel3_2->setText( tr( "Transferencias" ) );
    QTTransferencias->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTTransferencias->horizontalHeader()->setLabel( 1, tr( "Expendio" ) );
}

