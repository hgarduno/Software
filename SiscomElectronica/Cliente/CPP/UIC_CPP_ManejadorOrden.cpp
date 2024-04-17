/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorOrden.ui'
**
** Created: Fri Apr 12 21:26:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorOrden.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlcdnumber.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <QCtrlProductosSE.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"

/*
 *  Constructs a ManejadorOrden as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorOrden::ManejadorOrden( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorOrden" );
    setFocusPolicy( QWidget::ClickFocus );
    ManejadorOrdenLayout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorOrdenLayout"); 

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout12->addWidget( textLabel5 );

    QLCDNumPrecio = new QLCDNumber( this, "QLCDNumPrecio" );
    QLCDNumPrecio->setMinimumSize( QSize( 0, 50 ) );
    QLCDNumPrecio->setMaximumSize( QSize( 500, 150 ) );
    QLCDNumPrecio->setNumDigits( 10 );
    layout12->addWidget( QLCDNumPrecio );
    layout16->addLayout( layout12 );

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout12_2->addWidget( textLabel5_2 );

    QLCDNumTotalOrden = new QLCDNumber( this, "QLCDNumTotalOrden" );
    QLCDNumTotalOrden->setMaximumSize( QSize( 32767, 150 ) );
    QLCDNumTotalOrden->setNumDigits( 10 );
    layout12_2->addWidget( QLCDNumTotalOrden );
    layout16->addLayout( layout12_2 );
    layout26->addLayout( layout16 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( textLabel1 );

    QTECliente = new QTextEdit( this, "QTECliente" );
    QTECliente->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTECliente->sizePolicy().hasHeightForWidth() ) );
    QTECliente->setReadOnly( TRUE );
    layout19->addWidget( QTECliente );
    layout25->addLayout( layout19 );

    layout5_3 = new QVBoxLayout( 0, 0, 6, "layout5_3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout5_3->addWidget( textLabel1_3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout5_3->addWidget( QTEDescripcion );
    layout25->addLayout( layout5_3 );
    layout26->addLayout( layout25 );

    ManejadorOrdenLayout->addMultiCellLayout( layout26, 0, 2, 1, 1 );

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    QLECantidad->setMinimumSize( QSize( 60, 0 ) );
    layout8->addWidget( QLECantidad );
    layout28->addLayout( layout8 );

    layout26_2 = new QVBoxLayout( 0, 0, 6, "layout26_2"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout26_2->addWidget( textLabel4 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setEnabled( FALSE );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    QCtrProductos->setMinimumSize( QSize( 250, 0 ) );
    QCtrProductos->setMaximumSize( QSize( 1000, 32767 ) );
    layout26_2->addWidget( QCtrProductos );
    layout28->addLayout( layout26_2 );

    layout8_3 = new QVBoxLayout( 0, 0, 6, "layout8_3"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    textLabel3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_3->sizePolicy().hasHeightForWidth() ) );
    layout8_3->addWidget( textLabel3_3 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    QLEExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLEExistencia->sizePolicy().hasHeightForWidth() ) );
    QLEExistencia->setMinimumSize( QSize( 50, 0 ) );
    QLEExistencia->setReadOnly( TRUE );
    layout8_3->addWidget( QLEExistencia );
    layout28->addLayout( layout8_3 );

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout8_2->addWidget( textLabel3_2 );

    QLEExiBodega = new QLineEdit( this, "QLEExiBodega" );
    QLEExiBodega->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLEExiBodega->sizePolicy().hasHeightForWidth() ) );
    QLEExiBodega->setMinimumSize( QSize( 50, 0 ) );
    QLEExiBodega->setReadOnly( TRUE );
    layout8_2->addWidget( QLEExiBodega );
    layout28->addLayout( layout8_2 );

    ManejadorOrdenLayout->addLayout( layout28, 0, 0 );

    QTOrden = new QTable( this, "QTOrden" );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Cant" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Exis" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Bod" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Juegos" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Clave" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Precio" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Importe" ) );
    QTOrden->setNumRows( 0 );
    QTOrden->setNumCols( 7 );
    QTOrden->setReadOnly( TRUE );

    ManejadorOrdenLayout->addWidget( QTOrden, 2, 0 );

    layout31 = new QHBoxLayout( 0, 0, 6, "layout31"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout31->addWidget( textLabel2 );

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout31->addWidget( textLabel2_2 );

    QLEUbicacion = new QLineEdit( this, "QLEUbicacion" );
    layout31->addWidget( QLEUbicacion );

    ManejadorOrdenLayout->addLayout( layout31, 1, 0 );

    LayoutBotones = new QHBoxLayout( 0, 0, 6, "LayoutBotones"); 

    QPBNuevaOrden = new QPushButton( this, "QPBNuevaOrden" );
    QPBNuevaOrden->setEnabled( TRUE );
    LayoutBotones->addWidget( QPBNuevaOrden );

    QPBCargaCotizacion = new QPushButton( this, "QPBCargaCotizacion" );
    QPBCargaCotizacion->setEnabled( TRUE );
    LayoutBotones->addWidget( QPBCargaCotizacion );

    QPBExExpendios = new QPushButton( this, "QPBExExpendios" );
    QPBExExpendios->setEnabled( FALSE );
    LayoutBotones->addWidget( QPBExExpendios );

    QPBDatosPedido = new QPushButton( this, "QPBDatosPedido" );
    QPBDatosPedido->setEnabled( FALSE );
    LayoutBotones->addWidget( QPBDatosPedido );

    QPBAnexarOrden = new QPushButton( this, "QPBAnexarOrden" );
    QPBAnexarOrden->setEnabled( FALSE );
    LayoutBotones->addWidget( QPBAnexarOrden );

    QPBFaltante = new QPushButton( this, "QPBFaltante" );
    LayoutBotones->addWidget( QPBFaltante );

    QPBImprimePdf = new QPushButton( this, "QPBImprimePdf" );
    QPBImprimePdf->setEnabled( TRUE );
    LayoutBotones->addWidget( QPBImprimePdf );

    QPBImprime = new QPushButton( this, "QPBImprime" );
    QPBImprime->setEnabled( FALSE );
    LayoutBotones->addWidget( QPBImprime );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    LayoutBotones->addWidget( QPBRegistrar );

    ManejadorOrdenLayout->addMultiCellLayout( LayoutBotones, 3, 3, 0, 1 );
    languageChange();
    resize( QSize(859, 436).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorOrden::~ManejadorOrden()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorOrden::languageChange()
{
    setCaption( tr( "Pedidos Telefonicos" ) );
    textLabel5->setText( tr( "Precio" ) );
    textLabel5_2->setText( tr( "Total" ) );
    textLabel1->setText( tr( "Datos Cliente" ) );
    textLabel1_3->setText( tr( "Informacion Producto" ) );
    textLabel3->setText( tr( "Cantidad" ) );
    QLECantidad->setText( tr( "1" ) );
    textLabel4->setText( tr( "Productos" ) );
    textLabel3_3->setText( tr( "Existencia" ) );
    QLEExistencia->setText( tr( "0" ) );
    textLabel3_2->setText( tr( "Bodega" ) );
    QLEExiBodega->setText( tr( "0" ) );
    QTOrden->horizontalHeader()->setLabel( 0, tr( "Cant" ) );
    QTOrden->horizontalHeader()->setLabel( 1, tr( "Exis" ) );
    QTOrden->horizontalHeader()->setLabel( 2, tr( "Bod" ) );
    QTOrden->horizontalHeader()->setLabel( 3, tr( "Juegos" ) );
    QTOrden->horizontalHeader()->setLabel( 4, tr( "Clave" ) );
    QTOrden->horizontalHeader()->setLabel( 5, tr( "Precio" ) );
    QTOrden->horizontalHeader()->setLabel( 6, tr( "Importe" ) );
    textLabel2->setText( tr( "Orden" ) );
    textLabel2_2->setText( tr( "Ubicacion" ) );
    QPBNuevaOrden->setText( tr( "Nueva Orden" ) );
    QPBNuevaOrden->setAccel( QKeySequence( QString::null ) );
    QPBCargaCotizacion->setText( tr( "Carga &Cotizacion" ) );
    QPBCargaCotizacion->setAccel( QKeySequence( tr( "Alt+C" ) ) );
    QPBExExpendios->setText( tr( "Existencia &Expendios" ) );
    QPBExExpendios->setAccel( QKeySequence( tr( "Alt+E" ) ) );
    QPBDatosPedido->setText( tr( "&Datos Pedido" ) );
    QPBDatosPedido->setAccel( QKeySequence( tr( "Alt+D" ) ) );
    QPBAnexarOrden->setText( tr( "Anexar Orden" ) );
    QPBAnexarOrden->setAccel( QKeySequence( QString::null ) );
    QPBFaltante->setText( tr( "&Faltante" ) );
    QPBFaltante->setAccel( QKeySequence( tr( "Alt+F" ) ) );
    QPBImprimePdf->setText( tr( "Imprime &Pdf" ) );
    QPBImprimePdf->setAccel( QKeySequence( tr( "Alt+P" ) ) );
    QPBImprime->setText( tr( "&Imprime" ) );
    QPBImprime->setAccel( QKeySequence( tr( "Alt+I" ) ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBRegistrar->setAccel( QKeySequence( QString::null ) );
}

