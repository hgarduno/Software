/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/TransferenciaAlmacen.ui'
**
** Created: Thu Apr 11 21:07:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "TransferenciaAlmacen.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qgroupbox.h>
#include <qtable.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlVendedores.h"
#include "QCtrlTiendasEntrega.h"
#include "QCtrlCamiones.h"
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a TransferenciaAlmacen as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
TransferenciaAlmacen::TransferenciaAlmacen( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TransferenciaAlmacen" );
    TransferenciaAlmacenLayout = new QGridLayout( this, 1, 1, 11, 6, "TransferenciaAlmacenLayout"); 

    frame7 = new QFrame( this, "frame7" );
    frame7->setFrameShape( QFrame::StyledPanel );
    frame7->setFrameShadow( QFrame::Raised );
    frame7Layout = new QGridLayout( frame7, 1, 1, 11, 6, "frame7Layout"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_2 = new QLabel( frame7, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel1_2 );

    QCtrAlmacenistas = new QCtrlVendedores( frame7, "QCtrAlmacenistas" );
    QCtrAlmacenistas->setEnabled( FALSE );
    layout3->addWidget( QCtrAlmacenistas );

    frame7Layout->addLayout( layout3, 1, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    textLabel1 = new QLabel( frame7, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( textLabel1 );

    QCtrTiendasEntrega = new QCtrlTiendasEntrega( frame7, "QCtrTiendasEntrega" );
    layout4->addWidget( QCtrTiendasEntrega );

    frame7Layout->addLayout( layout4, 0, 0 );

    TransferenciaAlmacenLayout->addWidget( frame7, 0, 0 );

    frame7_2 = new QFrame( this, "frame7_2" );
    frame7_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, frame7_2->sizePolicy().hasHeightForWidth() ) );
    frame7_2->setFrameShape( QFrame::StyledPanel );
    frame7_2->setFrameShadow( QFrame::Raised );
    frame7_2Layout = new QGridLayout( frame7_2, 1, 1, 11, 6, "frame7_2Layout"); 

    textLabel1_3_2_3 = new QLabel( frame7_2, "textLabel1_3_2_3" );
    textLabel1_3_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3_2_3->sizePolicy().hasHeightForWidth() ) );

    frame7_2Layout->addWidget( textLabel1_3_2_3, 0, 0 );

    QTEObservacionGeneral = new QTextEdit( frame7_2, "QTEObservacionGeneral" );

    frame7_2Layout->addMultiCellWidget( QTEObservacionGeneral, 0, 1, 1, 1 );
    spacer2 = new QSpacerItem( 20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding );
    frame7_2Layout->addItem( spacer2, 1, 0 );

    TransferenciaAlmacenLayout->addWidget( frame7_2, 3, 0 );

    frame6 = new QFrame( this, "frame6" );
    frame6->setFrameShape( QFrame::StyledPanel );
    frame6->setFrameShadow( QFrame::Raised );
    frame6Layout = new QGridLayout( frame6, 1, 1, 11, 6, "frame6Layout"); 

    layout4_2 = new QHBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel1_3 = new QLabel( frame6, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( textLabel1_3 );

    QCtrChoferes = new QCtrlVendedores( frame6, "QCtrChoferes" );
    QCtrChoferes->setEnabled( FALSE );
    layout4_2->addWidget( QCtrChoferes );

    frame6Layout->addMultiCellLayout( layout4_2, 0, 0, 0, 1 );

    layout4_3 = new QHBoxLayout( 0, 0, 6, "layout4_3"); 

    textLabel1_3_2_2 = new QLabel( frame6, "textLabel1_3_2_2" );
    textLabel1_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout4_3->addWidget( textLabel1_3_2_2 );

    QLEPlacas = new QLineEdit( frame6, "QLEPlacas" );
    QLEPlacas->setEnabled( FALSE );
    QLEPlacas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPlacas->sizePolicy().hasHeightForWidth() ) );
    layout4_3->addWidget( QLEPlacas );

    frame6Layout->addLayout( layout4_3, 1, 1 );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1_3_2 = new QLabel( frame6, "textLabel1_3_2" );
    textLabel1_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3_2->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel1_3_2 );

    QCtrCamiones = new QCtrlCamiones( frame6, "QCtrCamiones" );
    QCtrCamiones->setEnabled( FALSE );
    QCtrCamiones->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrCamiones->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( QCtrCamiones );

    frame6Layout->addLayout( layout5, 1, 0 );

    TransferenciaAlmacenLayout->addWidget( frame6, 1, 0 );

    frame23 = new QFrame( this, "frame23" );
    frame23->setFrameShape( QFrame::StyledPanel );
    frame23->setFrameShadow( QFrame::Raised );
    frame23Layout = new QGridLayout( frame23, 1, 1, 11, 6, "frame23Layout"); 

    QPBTransfiereAPiso = new QPushButton( frame23, "QPBTransfiereAPiso" );
    QPBTransfiereAPiso->setEnabled( TRUE );

    frame23Layout->addWidget( QPBTransfiereAPiso, 0, 0 );

    QPBTransferir = new QPushButton( frame23, "QPBTransferir" );
    QPBTransferir->setEnabled( FALSE );

    frame23Layout->addWidget( QPBTransferir, 0, 1 );

    QPBEliminar = new QPushButton( frame23, "QPBEliminar" );
    QPBEliminar->setEnabled( FALSE );

    frame23Layout->addWidget( QPBEliminar, 0, 2 );

    QPBImprimir = new QPushButton( frame23, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );

    frame23Layout->addWidget( QPBImprimir, 0, 3 );

    QPBCopiar = new QPushButton( frame23, "QPBCopiar" );

    frame23Layout->addWidget( QPBCopiar, 0, 4 );

    TransferenciaAlmacenLayout->addWidget( frame23, 4, 0 );

    frame8 = new QFrame( this, "frame8" );
    frame8->setFrameShape( QFrame::StyledPanel );
    frame8->setFrameShadow( QFrame::Raised );
    frame8Layout = new QGridLayout( frame8, 1, 1, 11, 6, "frame8Layout"); 

    GBProductos = new QGroupBox( frame8, "GBProductos" );
    GBProductos->setColumnLayout(0, Qt::Vertical );
    GBProductos->layout()->setSpacing( 6 );
    GBProductos->layout()->setMargin( 11 );
    GBProductosLayout = new QGridLayout( GBProductos->layout() );
    GBProductosLayout->setAlignment( Qt::AlignTop );

    QTProductos = new QTable( GBProductos, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Modelo" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Codigo de Barras" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Observacion" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto Stock" ) );
    QTProductos->setVScrollBarMode( QTable::AlwaysOff );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 6 );
    QTProductos->setReadOnly( TRUE );

    GBProductosLayout->addWidget( QTProductos, 0, 0 );

    frame8Layout->addMultiCellWidget( GBProductos, 1, 1, 0, 2 );

    layout64 = new QHBoxLayout( 0, 0, 6, "layout64"); 

    textLabel2_2 = new QLabel( frame8, "textLabel2_2" );
    layout64->addWidget( textLabel2_2 );

    QCtrProveedores = new QCtrlProveedoresSS( frame8, "QCtrProveedores" );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    layout64->addWidget( QCtrProveedores );

    frame8Layout->addLayout( layout64, 0, 1 );

    QRBEsStock = new QRadioButton( frame8, "QRBEsStock" );

    frame8Layout->addWidget( QRBEsStock, 0, 2 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    textLabel2 = new QLabel( frame8, "textLabel2" );
    layout8->addWidget( textLabel2 );

    QLECodigoBarras = new QLineEdit( frame8, "QLECodigoBarras" );
    QLECodigoBarras->setEnabled( FALSE );
    layout8->addWidget( QLECodigoBarras );

    frame8Layout->addLayout( layout8, 0, 0 );

    TransferenciaAlmacenLayout->addWidget( frame8, 2, 0 );
    languageChange();
    resize( QSize(839, 656).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
TransferenciaAlmacen::~TransferenciaAlmacen()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TransferenciaAlmacen::languageChange()
{
    setCaption( tr( "Transferencia Almacen" ) );
    textLabel1_2->setText( tr( "Almacenista:" ) );
    textLabel1->setText( tr( "Tienda a transferir:" ) );
    textLabel1_3_2_3->setText( tr( "Observacion General:" ) );
    textLabel1_3->setText( tr( "Chofer:" ) );
    textLabel1_3_2_2->setText( tr( "Placas:" ) );
    textLabel1_3_2->setText( tr( "Camion:" ) );
    QPBTransfiereAPiso->setText( tr( "Transferencia A Piso" ) );
    QPBTransferir->setText( tr( "Transferir Productos" ) );
    QPBEliminar->setText( tr( "Eliminar Producto" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBCopiar->setText( tr( "Copiar" ) );
    GBProductos->setTitle( tr( "Productos" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Codigo de Barras" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "Observacion" ) );
    QTProductos->horizontalHeader()->setLabel( 5, tr( "Producto Stock" ) );
    textLabel2_2->setText( tr( "Clave Proveedor" ) );
    QRBEsStock->setText( tr( "Stock" ) );
    textLabel2->setText( tr( "Codigo de producto:" ) );
}

