/****************************************************************************
** Form implementation generated from reading ui file 'UI/AdministracionVentas.ui'
**
** Created: Wed Apr 10 20:52:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AdministracionVentas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QCtrlProductosSE.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"

/*
 *  Constructs a AdministracionVentas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
AdministracionVentas::AdministracionVentas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "AdministracionVentas" );
    AdministracionVentasLayout = new QGridLayout( this, 1, 1, 11, 6, "AdministracionVentasLayout"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QLECantidad );
    layout4->addLayout( layout2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout3->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrProductos );
    layout4->addLayout( layout3 );
    layout36->addLayout( layout4 );

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    layout25_2 = new QVBoxLayout( 0, 0, 6, "layout25_2"); 

    textLabel1_3_2 = new QLabel( this, "textLabel1_3_2" );
    layout25_2->addWidget( textLabel1_3_2 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    layout25_2->addWidget( QLEExistencia );
    layout28->addLayout( layout25_2 );

    layout25_2_2 = new QVBoxLayout( 0, 0, 6, "layout25_2_2"); 

    textLabel1_3_2_2 = new QLabel( this, "textLabel1_3_2_2" );
    layout25_2_2->addWidget( textLabel1_3_2_2 );

    QLEExistenciaBodega = new QLineEdit( this, "QLEExistenciaBodega" );
    layout25_2_2->addWidget( QLEExistenciaBodega );
    layout28->addLayout( layout25_2_2 );
    layout36->addLayout( layout28 );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( textLabel3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( QTEDescripcion );
    layout36->addLayout( layout17 );

    AdministracionVentasLayout->addMultiCellLayout( layout36, 0, 1, 0, 0 );

    layout35 = new QVBoxLayout( 0, 0, 6, "layout35"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout35->addWidget( textLabel2_3 );

    QLCDPrecio = new QLCDNumber( this, "QLCDPrecio" );
    QLCDPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QLCDPrecio->sizePolicy().hasHeightForWidth() ) );
    QLCDPrecio->setNumDigits( 10 );
    layout35->addWidget( QLCDPrecio );

    AdministracionVentasLayout->addLayout( layout35, 0, 1 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    QPBNuevaOrden = new QPushButton( this, "QPBNuevaOrden" );
    QPBNuevaOrden->setMinimumSize( QSize( 0, 60 ) );
    layout19->addWidget( QPBNuevaOrden );

    QPBNuevaOrden_2 = new QPushButton( this, "QPBNuevaOrden_2" );
    QPBNuevaOrden_2->setMinimumSize( QSize( 0, 60 ) );
    layout19->addWidget( QPBNuevaOrden_2 );

    AdministracionVentasLayout->addLayout( layout19, 1, 1 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout7->addWidget( textLabel1_2 );

    QTOrden = new QTable( this, "QTOrden" );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Cantidad" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Producto" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Precio" ) );
    QTOrden->setNumCols( QTOrden->numCols() + 1 );
    QTOrden->horizontalHeader()->setLabel( QTOrden->numCols() - 1, tr( "Importe" ) );
    QTOrden->setEnabled( FALSE );
    QTOrden->setNumRows( 0 );
    QTOrden->setNumCols( 4 );
    layout7->addWidget( QTOrden );
    layout21->addLayout( layout7 );

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout14->addWidget( textLabel2_2 );

    QLCNImporteOrden = new QLCDNumber( this, "QLCNImporteOrden" );
    QLCNImporteOrden->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QLCNImporteOrden->sizePolicy().hasHeightForWidth() ) );
    QLCNImporteOrden->setNumDigits( 10 );
    layout14->addWidget( QLCNImporteOrden );
    layout20->addLayout( layout14 );

    layout34 = new QVBoxLayout( 0, 0, 0, "layout34"); 

    layout33 = new QHBoxLayout( 0, 0, 0, "layout33"); 

    QPBAnexarOrden = new QPushButton( this, "QPBAnexarOrden" );
    QPBAnexarOrden->setEnabled( FALSE );
    layout33->addWidget( QPBAnexarOrden );

    QPBAnexarOrden_2 = new QPushButton( this, "QPBAnexarOrden_2" );
    QPBAnexarOrden_2->setEnabled( FALSE );
    layout33->addWidget( QPBAnexarOrden_2 );
    layout34->addLayout( layout33 );

    QPBAnexarOrden_3 = new QPushButton( this, "QPBAnexarOrden_3" );
    QPBAnexarOrden_3->setEnabled( FALSE );
    layout34->addWidget( QPBAnexarOrden_3 );
    layout20->addLayout( layout34 );
    layout21->addLayout( layout20 );

    AdministracionVentasLayout->addMultiCellLayout( layout21, 2, 2, 0, 1 );
    languageChange();
    resize( QSize(921, 571).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AdministracionVentas::~AdministracionVentas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AdministracionVentas::languageChange()
{
    setCaption( tr( "Administracion Ventas" ) );
    textLabel1->setText( tr( "Cantidad" ) );
    QLECantidad->setText( tr( "1" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel1_3_2->setText( tr( "Existencia" ) );
    textLabel1_3_2_2->setText( tr( "Existencia Bodega" ) );
    textLabel3->setText( tr( "Descripcion Producto" ) );
    textLabel2_3->setText( tr( "Precio" ) );
    QPBNuevaOrden->setText( tr( "Nueva Orden" ) );
    QPBNuevaOrden_2->setText( tr( "Cotizacion" ) );
    textLabel1_2->setText( tr( "Orden De Venta" ) );
    QTOrden->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTOrden->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTOrden->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTOrden->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    textLabel2_2->setText( tr( "Importe" ) );
    QPBAnexarOrden->setText( tr( "Anexar A La Orden" ) );
    QPBAnexarOrden_2->setText( tr( "Vende Pedido" ) );
    QPBAnexarOrden_3->setText( tr( "Imprimir" ) );
}

