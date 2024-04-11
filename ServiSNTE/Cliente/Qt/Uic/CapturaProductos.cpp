/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaProductos.ui'
**
** Created: Sat Jan 27 16:37:24 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaProductos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProveedoresSS.h"
#include "QCtrlDepartamentosSS.h"

/*
 *  Constructs a CapturaProductos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CapturaProductos::CapturaProductos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CapturaProductos" );
    CapturaProductosLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaProductosLayout"); 

    frame20 = new QFrame( this, "frame20" );
    frame20->setFrameShape( QFrame::StyledPanel );
    frame20->setFrameShadow( QFrame::Raised );
    frame20Layout = new QGridLayout( frame20, 1, 1, 11, 6, "frame20Layout"); 

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel2 = new QLabel( frame20, "textLabel2" );
    layout26->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( frame20, "QCtrProveedores" );
    QCtrProveedores->setEnabled( FALSE );
    layout26->addWidget( QCtrProveedores );
    layout27->addLayout( layout26 );

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    layout38 = new QVBoxLayout( 0, 0, 6, "layout38"); 

    textLabel3 = new QLabel( frame20, "textLabel3" );
    layout38->addWidget( textLabel3 );

    lineEdit83 = new QLineEdit( frame20, "lineEdit83" );
    lineEdit83->setEnabled( FALSE );
    lineEdit83->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit83->sizePolicy().hasHeightForWidth() ) );
    layout38->addWidget( lineEdit83 );
    layout47->addLayout( layout38 );

    layout39 = new QVBoxLayout( 0, 0, 6, "layout39"); 

    textLabel8 = new QLabel( frame20, "textLabel8" );
    layout39->addWidget( textLabel8 );

    lineEdit84 = new QLineEdit( frame20, "lineEdit84" );
    lineEdit84->setEnabled( FALSE );
    layout39->addWidget( lineEdit84 );
    layout47->addLayout( layout39 );
    layout27->addLayout( layout47 );

    frame20Layout->addLayout( layout27, 0, 0 );

    CapturaProductosLayout->addMultiCellWidget( frame20, 0, 0, 0, 1 );

    layout176 = new QHBoxLayout( 0, 0, 6, "layout176"); 

    QPBCrear = new QPushButton( this, "QPBCrear" );
    QPBCrear->setEnabled( TRUE );
    layout176->addWidget( QPBCrear );

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    QPBConsultar->setEnabled( TRUE );
    layout176->addWidget( QPBConsultar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( FALSE );
    layout176->addWidget( QPBActualizar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setEnabled( FALSE );
    layout176->addWidget( QPBCancelar );

    CapturaProductosLayout->addMultiCellLayout( layout176, 5, 5, 0, 1 );

    frame21 = new QFrame( this, "frame21" );
    frame21->setFrameShape( QFrame::StyledPanel );
    frame21->setFrameShadow( QFrame::Raised );
    frame21Layout = new QGridLayout( frame21, 1, 1, 11, 6, "frame21Layout"); 

    layout49 = new QHBoxLayout( 0, 0, 6, "layout49"); 

    layout40 = new QVBoxLayout( 0, 0, 6, "layout40"); 

    textLabel1 = new QLabel( frame21, "textLabel1" );
    layout40->addWidget( textLabel1 );

    QLENumeroProducto = new QLineEdit( frame21, "QLENumeroProducto" );
    QLENumeroProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumeroProducto->sizePolicy().hasHeightForWidth() ) );
    QLENumeroProducto->setReadOnly( FALSE );
    layout40->addWidget( QLENumeroProducto );
    layout49->addLayout( layout40 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel4 = new QLabel( frame21, "textLabel4" );
    layout41->addWidget( textLabel4 );

    QLENombre = new QLineEdit( frame21, "QLENombre" );
    layout41->addWidget( QLENombre );
    layout49->addLayout( layout41 );

    frame21Layout->addMultiCellLayout( layout49, 0, 0, 0, 1 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel5 = new QLabel( frame21, "textLabel5" );
    layout42->addWidget( textLabel5 );

    QLEModelo = new QLineEdit( frame21, "QLEModelo" );
    QLEModelo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEModelo->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( QLEModelo );

    frame21Layout->addLayout( layout42, 1, 0 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel7 = new QLabel( frame21, "textLabel7" );
    layout25->addWidget( textLabel7 );

    QCtrDepartamentos = new QCtrlDepartamentosSS( frame21, "QCtrDepartamentos" );
    QCtrDepartamentos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrDepartamentos->sizePolicy().hasHeightForWidth() ) );
    layout25->addWidget( QCtrDepartamentos );

    frame21Layout->addLayout( layout25, 1, 1 );

    CapturaProductosLayout->addMultiCellWidget( frame21, 1, 1, 0, 1 );

    layout59 = new QVBoxLayout( 0, 0, 6, "layout59"); 

    layout96 = new QVBoxLayout( 0, 0, 6, "layout96"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout96->addWidget( textLabel1_2 );

    QTCostoBruto = new QTable( this, "QTCostoBruto" );
    QTCostoBruto->setNumCols( QTCostoBruto->numCols() + 1 );
    QTCostoBruto->horizontalHeader()->setLabel( QTCostoBruto->numCols() - 1, tr( "Costo Bruto" ) );
    QTCostoBruto->setNumCols( QTCostoBruto->numCols() + 1 );
    QTCostoBruto->horizontalHeader()->setLabel( QTCostoBruto->numCols() - 1, tr( "Costo Sin Iva" ) );
    QTCostoBruto->setNumCols( QTCostoBruto->numCols() + 1 );
    QTCostoBruto->horizontalHeader()->setLabel( QTCostoBruto->numCols() - 1, tr( "IVA" ) );
    QTCostoBruto->setNumCols( QTCostoBruto->numCols() + 1 );
    QTCostoBruto->horizontalHeader()->setLabel( QTCostoBruto->numCols() - 1, tr( "Fecha" ) );
    QTCostoBruto->setNumRows( 0 );
    QTCostoBruto->setNumCols( 4 );
    QTCostoBruto->setReadOnly( TRUE );
    layout96->addWidget( QTCostoBruto );
    layout59->addLayout( layout96 );

    layout98 = new QVBoxLayout( 0, 0, 6, "layout98"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout98->addWidget( textLabel2_2 );

    QTPrecioGeneral = new QTable( this, "QTPrecioGeneral" );
    QTPrecioGeneral->setNumCols( QTPrecioGeneral->numCols() + 1 );
    QTPrecioGeneral->horizontalHeader()->setLabel( QTPrecioGeneral->numCols() - 1, tr( "Precio General" ) );
    QTPrecioGeneral->setNumCols( QTPrecioGeneral->numCols() + 1 );
    QTPrecioGeneral->horizontalHeader()->setLabel( QTPrecioGeneral->numCols() - 1, tr( "Fecha" ) );
    QTPrecioGeneral->setNumRows( 0 );
    QTPrecioGeneral->setNumCols( 2 );
    QTPrecioGeneral->setReadOnly( TRUE );
    layout98->addWidget( QTPrecioGeneral );
    layout59->addLayout( layout98 );

    layout97 = new QVBoxLayout( 0, 0, 6, "layout97"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout97->addWidget( textLabel3_2 );

    QTPrecioForaneo = new QTable( this, "QTPrecioForaneo" );
    QTPrecioForaneo->setNumCols( QTPrecioForaneo->numCols() + 1 );
    QTPrecioForaneo->horizontalHeader()->setLabel( QTPrecioForaneo->numCols() - 1, tr( "Precio Foraneo" ) );
    QTPrecioForaneo->setNumCols( QTPrecioForaneo->numCols() + 1 );
    QTPrecioForaneo->horizontalHeader()->setLabel( QTPrecioForaneo->numCols() - 1, tr( "Fecha" ) );
    QTPrecioForaneo->setNumRows( 0 );
    QTPrecioForaneo->setNumCols( 2 );
    QTPrecioForaneo->setReadOnly( TRUE );
    layout97->addWidget( QTPrecioForaneo );
    layout59->addLayout( layout97 );

    CapturaProductosLayout->addMultiCellLayout( layout59, 2, 4, 0, 0 );

    layout35 = new QVBoxLayout( 0, 0, 6, "layout35"); 

    QPBCCBruto = new QPushButton( this, "QPBCCBruto" );
    QPBCCBruto->setEnabled( TRUE );
    layout35->addWidget( QPBCCBruto );

    QPBCPGeneral = new QPushButton( this, "QPBCPGeneral" );
    layout35->addWidget( QPBCPGeneral );

    QPBCPForaneo = new QPushButton( this, "QPBCPForaneo" );
    layout35->addWidget( QPBCPForaneo );

    QPBCDescuento = new QPushButton( this, "QPBCDescuento" );
    QPBCDescuento->setEnabled( TRUE );
    layout35->addWidget( QPBCDescuento );

    CapturaProductosLayout->addLayout( layout35, 4, 1 );

    textLabel9 = new QLabel( this, "textLabel9" );

    CapturaProductosLayout->addWidget( textLabel9, 2, 1 );

    QTDescuento = new QTable( this, "QTDescuento" );
    QTDescuento->setNumCols( QTDescuento->numCols() + 1 );
    QTDescuento->horizontalHeader()->setLabel( QTDescuento->numCols() - 1, tr( "Fecha" ) );
    QTDescuento->setNumCols( QTDescuento->numCols() + 1 );
    QTDescuento->horizontalHeader()->setLabel( QTDescuento->numCols() - 1, tr( "D1" ) );
    QTDescuento->setNumCols( QTDescuento->numCols() + 1 );
    QTDescuento->horizontalHeader()->setLabel( QTDescuento->numCols() - 1, tr( "D2" ) );
    QTDescuento->setNumCols( QTDescuento->numCols() + 1 );
    QTDescuento->horizontalHeader()->setLabel( QTDescuento->numCols() - 1, tr( "D3" ) );
    QTDescuento->setNumCols( QTDescuento->numCols() + 1 );
    QTDescuento->horizontalHeader()->setLabel( QTDescuento->numCols() - 1, tr( "D4" ) );
    QTDescuento->setNumRows( 0 );
    QTDescuento->setNumCols( 5 );

    CapturaProductosLayout->addWidget( QTDescuento, 3, 1 );
    languageChange();
    resize( QSize(799, 663).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaProductos::~CapturaProductos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaProductos::languageChange()
{
    setCaption( tr( "Manejador de Productos" ) );
    textLabel2->setText( tr( "Proveedor:" ) );
    textLabel3->setText( tr( "Clave:" ) );
    textLabel8->setText( tr( "Razon Social:" ) );
    QPBCrear->setText( tr( "Crear" ) );
    QPBConsultar->setText( tr( "Consultar" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Numero Producto" ) );
    textLabel4->setText( tr( "Nombre Producto:" ) );
    textLabel5->setText( tr( "Modelo:" ) );
    textLabel7->setText( tr( "Departamento:" ) );
    textLabel1_2->setText( tr( "Costo Bruto:" ) );
    QTCostoBruto->horizontalHeader()->setLabel( 0, tr( "Costo Bruto" ) );
    QTCostoBruto->horizontalHeader()->setLabel( 1, tr( "Costo Sin Iva" ) );
    QTCostoBruto->horizontalHeader()->setLabel( 2, tr( "IVA" ) );
    QTCostoBruto->horizontalHeader()->setLabel( 3, tr( "Fecha" ) );
    textLabel2_2->setText( tr( "Precio General:" ) );
    QTPrecioGeneral->horizontalHeader()->setLabel( 0, tr( "Precio General" ) );
    QTPrecioGeneral->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    textLabel3_2->setText( trUtf8( "\x50\x72\x65\x63\x69\x6f\x20\x46\x6f\x72\xc3\xa1\x6e\x65\x6f\x3a" ) );
    QTPrecioForaneo->horizontalHeader()->setLabel( 0, tr( "Precio Foraneo" ) );
    QTPrecioForaneo->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QPBCCBruto->setText( tr( "Captura Costo Bruto" ) );
    QPBCPGeneral->setText( tr( "Captura Precio General" ) );
    QPBCPForaneo->setText( trUtf8( "\x43\x61\x70\x74\x75\x72\x61\x20\x50\x72\x65\x63\x69\x6f\x20\x46\x6f\x72\xc3\xa1\x6e"
    "\x65\x6f" ) );
    QPBCDescuento->setText( tr( "Captura Descuento" ) );
    textLabel9->setText( tr( "Descuentos:" ) );
    QTDescuento->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTDescuento->horizontalHeader()->setLabel( 1, tr( "D1" ) );
    QTDescuento->horizontalHeader()->setLabel( 2, tr( "D2" ) );
    QTDescuento->horizontalHeader()->setLabel( 3, tr( "D3" ) );
    QTDescuento->horizontalHeader()->setLabel( 4, tr( "D4" ) );
}

