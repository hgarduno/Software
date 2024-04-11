/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RegistroCompras.ui'
**
** Created: Sat Jan 27 16:38:40 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RegistroCompras.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qframe.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSS.h"
#include "QCtrlTipoDocumentos.h"
#include "QCtrlConceptosExistencias.h"
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a RegistroCompras as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroCompras::RegistroCompras( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroCompras" );
    RegistroComprasLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroComprasLayout"); 

    textLabel7 = new QLabel( this, "textLabel7" );

    RegistroComprasLayout->addWidget( textLabel7, 0, 0 );

    groupBox3 = new QGroupBox( this, "groupBox3" );
    groupBox3->setColumnLayout(0, Qt::Vertical );
    groupBox3->layout()->setSpacing( 6 );
    groupBox3->layout()->setMargin( 11 );
    groupBox3Layout = new QGridLayout( groupBox3->layout() );
    groupBox3Layout->setAlignment( Qt::AlignTop );

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    textLabel8 = new QLabel( groupBox3, "textLabel8" );
    textLabel8->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel8->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( textLabel8 );

    QCtrProducto = new QCtrlProductosSS( groupBox3, "QCtrProducto" );
    QCtrProducto->setEnabled( FALSE );
    QCtrProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProducto->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( QCtrProducto );

    groupBox3Layout->addLayout( layout48, 0, 0 );

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    textLabel1_2 = new QLabel( groupBox3, "textLabel1_2" );
    layout33->addWidget( textLabel1_2 );

    QLEModelo = new QLineEdit( groupBox3, "QLEModelo" );
    QLEModelo->setEnabled( TRUE );
    QLEModelo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEModelo->sizePolicy().hasHeightForWidth() ) );
    QLEModelo->setReadOnly( TRUE );
    layout33->addWidget( QLEModelo );

    groupBox3Layout->addLayout( layout33, 0, 1 );

    layout50 = new QVBoxLayout( 0, 0, 6, "layout50"); 

    textLabel11 = new QLabel( groupBox3, "textLabel11" );
    layout50->addWidget( textLabel11 );

    QLESerieProducto = new QLineEdit( groupBox3, "QLESerieProducto" );
    QLESerieProducto->setEnabled( FALSE );
    QLESerieProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLESerieProducto->sizePolicy().hasHeightForWidth() ) );
    layout50->addWidget( QLESerieProducto );

    groupBox3Layout->addLayout( layout50, 0, 2 );

    layout50_2 = new QVBoxLayout( 0, 0, 6, "layout50_2"); 

    textLabel11_2 = new QLabel( groupBox3, "textLabel11_2" );
    layout50_2->addWidget( textLabel11_2 );

    QLECantidad = new QLineEdit( groupBox3, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout50_2->addWidget( QLECantidad );

    groupBox3Layout->addLayout( layout50_2, 0, 3 );

    RegistroComprasLayout->addWidget( groupBox3, 2, 0 );

    frame4 = new QFrame( this, "frame4" );
    frame4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, frame4->sizePolicy().hasHeightForWidth() ) );
    frame4->setFrameShape( QFrame::StyledPanel );
    frame4->setFrameShadow( QFrame::Sunken );
    frame4Layout = new QGridLayout( frame4, 1, 1, 11, 6, "frame4Layout"); 

    groupBox1 = new QGroupBox( frame4, "groupBox1" );
    groupBox1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, groupBox1->sizePolicy().hasHeightForWidth() ) );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    QTDetalleCompra = new QTable( groupBox1, "QTDetalleCompra" );
    QTDetalleCompra->setNumCols( QTDetalleCompra->numCols() + 1 );
    QTDetalleCompra->horizontalHeader()->setLabel( QTDetalleCompra->numCols() - 1, tr( "Producto" ) );
    QTDetalleCompra->setNumCols( QTDetalleCompra->numCols() + 1 );
    QTDetalleCompra->horizontalHeader()->setLabel( QTDetalleCompra->numCols() - 1, tr( "Modelo" ) );
    QTDetalleCompra->setNumCols( QTDetalleCompra->numCols() + 1 );
    QTDetalleCompra->horizontalHeader()->setLabel( QTDetalleCompra->numCols() - 1, tr( "Cantidad" ) );
    QTDetalleCompra->setNumRows( 0 );
    QTDetalleCompra->setNumCols( 3 );
    QTDetalleCompra->setReadOnly( TRUE );

    groupBox1Layout->addWidget( QTDetalleCompra, 0, 0 );

    frame4Layout->addWidget( groupBox1, 0, 0 );

    RegistroComprasLayout->addWidget( frame4, 3, 0 );

    frame3 = new QFrame( this, "frame3" );
    frame3->setEnabled( TRUE );
    frame3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, frame3->sizePolicy().hasHeightForWidth() ) );
    frame3->setFrameShape( QFrame::StyledPanel );
    frame3->setFrameShadow( QFrame::Raised );
    frame3Layout = new QGridLayout( frame3, 1, 1, 11, 6, "frame3Layout"); 

    layout46 = new QHBoxLayout( 0, 0, 6, "layout46"); 

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel2 = new QLabel( frame3, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout41->addWidget( textLabel2 );

    QCtrTipoDocumento = new QCtrlTipoDocumentos( frame3, "QCtrTipoDocumento" );
    QCtrTipoDocumento->setEnabled( FALSE );
    layout41->addWidget( QCtrTipoDocumento );
    layout46->addLayout( layout41 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel4 = new QLabel( frame3, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( textLabel4 );

    QLESerieFactura = new QLineEdit( frame3, "QLESerieFactura" );
    QLESerieFactura->setEnabled( FALSE );
    QLESerieFactura->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLESerieFactura->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( QLESerieFactura );
    layout46->addLayout( layout42 );

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    textLabel5 = new QLabel( frame3, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout43->addWidget( textLabel5 );

    QLEFolio = new QLineEdit( frame3, "QLEFolio" );
    QLEFolio->setEnabled( FALSE );
    QLEFolio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFolio->sizePolicy().hasHeightForWidth() ) );
    layout43->addWidget( QLEFolio );
    layout46->addLayout( layout43 );

    frame3Layout->addMultiCellLayout( layout46, 1, 1, 0, 1 );

    layout45 = new QHBoxLayout( 0, 0, 6, "layout45"); 

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    textLabel6 = new QLabel( frame3, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout44->addWidget( textLabel6 );

    QCtrConcepto = new QCtrlConceptosExistencias( frame3, "QCtrConcepto" );
    QCtrConcepto->setEnabled( FALSE );
    layout44->addWidget( QCtrConcepto );
    layout45->addLayout( layout44 );

    frame3Layout->addMultiCellLayout( layout45, 2, 2, 0, 1 );

    layout38 = new QVBoxLayout( 0, 0, 6, "layout38"); 

    textLabel1 = new QLabel( frame3, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout38->addWidget( textLabel1 );

    QCtrProveedor = new QCtrlProveedoresSS( frame3, "QCtrProveedor" );
    layout38->addWidget( QCtrProveedor );

    frame3Layout->addLayout( layout38, 0, 0 );

    layout70 = new QVBoxLayout( 0, 0, 6, "layout70"); 

    textLabel3 = new QLabel( frame3, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout70->addWidget( textLabel3 );

    QLEFecha = new QLineEdit( frame3, "QLEFecha" );
    QLEFecha->setEnabled( FALSE );
    QLEFecha->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFecha->sizePolicy().hasHeightForWidth() ) );
    QLEFecha->setReadOnly( FALSE );
    layout70->addWidget( QLEFecha );

    frame3Layout->addLayout( layout70, 0, 1 );

    RegistroComprasLayout->addWidget( frame3, 1, 0 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    layout14->addWidget( QPBRegistrar );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );
    layout14->addWidget( QPBImprimir );

    QPBAgregar = new QPushButton( this, "QPBAgregar" );
    QPBAgregar->setEnabled( FALSE );
    layout14->addWidget( QPBAgregar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setEnabled( FALSE );
    layout14->addWidget( QPBEliminar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setEnabled( FALSE );
    layout14->addWidget( QPBCancelar );

    QPBCopiar = new QPushButton( this, "QPBCopiar" );
    QPBCopiar->setEnabled( TRUE );
    layout14->addWidget( QPBCopiar );

    RegistroComprasLayout->addLayout( layout14, 4, 0 );
    languageChange();
    resize( QSize(711, 705).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroCompras::~RegistroCompras()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroCompras::languageChange()
{
    setCaption( tr( "Registro de Compras" ) );
    textLabel7->setText( tr( "Introduzca los datos solicitados para registrar la compra" ) );
    groupBox3->setTitle( tr( "Introduce todos los datos del producto" ) );
    textLabel8->setText( tr( "Seleccione Producto:" ) );
    textLabel1_2->setText( tr( "Modelo Producto" ) );
    textLabel11->setText( tr( "Serie Producto:" ) );
    textLabel11_2->setText( tr( "Cantidad" ) );
    QLECantidad->setText( QString::null );
    groupBox1->setTitle( trUtf8( "\x44\x65\x74\x61\x6c\x6c\x65\x20\x46\x61\x63\x74\x75\x72\x61\x20\x6f\x20\x52\x65\x6d"
    "\x69\x73\x69\xc3\xb3\x6e" ) );
    QTDetalleCompra->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDetalleCompra->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTDetalleCompra->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    textLabel2->setText( tr( "Tipo de Documento:" ) );
    textLabel4->setText( tr( "Serie Factura:" ) );
    textLabel5->setText( tr( "Folio" ) );
    textLabel6->setText( tr( "Concepto:" ) );
    textLabel1->setText( tr( "Proveedor:" ) );
    textLabel3->setText( tr( "Fecha:" ) );
    QLEFecha->setInputMask( tr( "0000-00-00; " ) );
    QPBRegistrar->setText( tr( "Registrar Compra" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBAgregar->setText( tr( "Agrega Producto" ) );
    QPBEliminar->setText( tr( "Elimina Producto" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBCopiar->setText( tr( "Copiar" ) );
}

