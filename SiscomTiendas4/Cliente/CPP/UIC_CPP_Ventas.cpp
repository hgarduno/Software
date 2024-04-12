/****************************************************************************
** Form implementation generated from reading ui file 'UI/Ventas.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Ventas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <QCtrlPrecios.h>
#include <QCtrlProductos.h>
#include <qlineedit.h>
#include <QCtrlClientes.h>
#include <QCtrlFormaPago.h>
#include <qgroupbox.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlPrecios.h"
#include "QCtrlProductos.h"
#include "QCtrlClientes.h"
#include "QCtrlContactos.h"
#include "QCtrlFormaPago.h"

/*
 *  Constructs a Ventas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Ventas::Ventas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Ventas" );
    VentasLayout = new QGridLayout( this, 1, 1, 11, 6, "VentasLayout"); 

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout44->addWidget( textLabel2_4 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Tipo Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 5 );
    QTDatos->setReadOnly( TRUE );
    layout44->addWidget( QTDatos );

    VentasLayout->addMultiCellLayout( layout44, 3, 3, 0, 2 );

    layout24 = new QHBoxLayout( 0, 0, 6, "layout24"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel2_7 = new QLabel( this, "textLabel2_7" );
    textLabel2_7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_7->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( textLabel2_7 );

    QCtrPrecios = new QCtrlPrecios( this, "QCtrPrecios" );
    QCtrPrecios->setEnabled( TRUE );
    QCtrPrecios->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrPrecios->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( QCtrPrecios );
    layout24->addLayout( layout19 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout41->addWidget( textLabel2_2 );

    QCtrProductos = new QCtrlProductos( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout41->addWidget( QCtrProductos );
    layout24->addLayout( layout41 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( textLabel2_2_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( QLECantidad );
    layout24->addLayout( layout42 );

    layout42_2 = new QVBoxLayout( 0, 0, 6, "layout42_2"); 

    textLabel2_2_2_2 = new QLabel( this, "textLabel2_2_2_2" );
    textLabel2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout42_2->addWidget( textLabel2_2_2_2 );

    QLEImporte = new QLineEdit( this, "QLEImporte" );
    QLEImporte->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEImporte->sizePolicy().hasHeightForWidth() ) );
    layout42_2->addWidget( QLEImporte );
    layout24->addLayout( layout42_2 );

    VentasLayout->addMultiCellLayout( layout24, 1, 1, 0, 2 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout14->addWidget( textLabel2 );

    QCtrClientes = new QCtrlClientes( this, "QCtrClientes" );
    QCtrClientes->setEnabled( TRUE );
    QCtrClientes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrClientes->sizePolicy().hasHeightForWidth() ) );
    layout14->addWidget( QCtrClientes );

    VentasLayout->addLayout( layout14, 0, 0 );

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel2_8 = new QLabel( this, "textLabel2_8" );
    textLabel2_8->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_8->sizePolicy().hasHeightForWidth() ) );
    layout21->addWidget( textLabel2_8 );

    QCtrContactos = new QCtrlContactos( this, "QCtrContactos" );
    QCtrContactos->setEnabled( TRUE );
    QCtrContactos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrContactos->sizePolicy().hasHeightForWidth() ) );
    layout21->addWidget( QCtrContactos );

    VentasLayout->addLayout( layout21, 0, 1 );

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel2_9 = new QLabel( this, "textLabel2_9" );
    textLabel2_9->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_9->sizePolicy().hasHeightForWidth() ) );
    layout22->addWidget( textLabel2_9 );

    QCtrFPago = new QCtrlFormaPago( this, "QCtrFPago" );
    QCtrFPago->setEnabled( TRUE );
    QCtrFPago->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrFPago->sizePolicy().hasHeightForWidth() ) );
    layout22->addWidget( QCtrFPago );

    VentasLayout->addLayout( layout22, 0, 2 );

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

    VentasLayout->addMultiCellLayout( layout23, 4, 4, 0, 2 );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, groupBox1->sizePolicy().hasHeightForWidth() ) );
    groupBox1->setMinimumSize( QSize( 0, 250 ) );
    groupBox1->setMaximumSize( QSize( 32767, 250 ) );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout61 = new QVBoxLayout( 0, 0, 6, "layout61"); 

    textLabel2_5 = new QLabel( groupBox1, "textLabel2_5" );
    textLabel2_5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5->sizePolicy().hasHeightForWidth() ) );
    layout61->addWidget( textLabel2_5 );

    QLECliente = new QLineEdit( groupBox1, "QLECliente" );
    QLECliente->setReadOnly( TRUE );
    layout61->addWidget( QLECliente );

    groupBox1Layout->addLayout( layout61, 0, 0 );

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    textLabel2_3 = new QLabel( groupBox1, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout43->addWidget( textLabel2_3 );

    QTEDescripcion = new QTextEdit( groupBox1, "QTEDescripcion" );
    QTEDescripcion->setMaximumSize( QSize( 32767, 150 ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout43->addWidget( QTEDescripcion );

    groupBox1Layout->addLayout( layout43, 1, 0 );

    layout22_2 = new QVBoxLayout( 0, 0, 6, "layout22_2"); 

    layout50_2_3 = new QVBoxLayout( 0, 0, 6, "layout50_2_3"); 

    textLabel2_6_2_3 = new QLabel( groupBox1, "textLabel2_6_2_3" );
    textLabel2_6_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6_2_3->sizePolicy().hasHeightForWidth() ) );
    layout50_2_3->addWidget( textLabel2_6_2_3 );

    QLCDNExistencia = new QLCDNumber( groupBox1, "QLCDNExistencia" );
    QLCDNExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDNExistencia->sizePolicy().hasHeightForWidth() ) );
    QLCDNExistencia->setNumDigits( 8 );
    layout50_2_3->addWidget( QLCDNExistencia );
    layout22_2->addLayout( layout50_2_3 );

    layout21_2 = new QHBoxLayout( 0, 0, 6, "layout21_2"); 

    layout50_2 = new QVBoxLayout( 0, 0, 6, "layout50_2"); 

    textLabel2_6_2 = new QLabel( groupBox1, "textLabel2_6_2" );
    textLabel2_6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6_2->sizePolicy().hasHeightForWidth() ) );
    layout50_2->addWidget( textLabel2_6_2 );

    QLCDNPrecio = new QLCDNumber( groupBox1, "QLCDNPrecio" );
    QLCDNPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDNPrecio->sizePolicy().hasHeightForWidth() ) );
    QLCDNPrecio->setNumDigits( 8 );
    layout50_2->addWidget( QLCDNPrecio );
    layout21_2->addLayout( layout50_2 );

    layout50_2_2 = new QVBoxLayout( 0, 0, 6, "layout50_2_2"); 

    textLabel2_6_2_2 = new QLabel( groupBox1, "textLabel2_6_2_2" );
    textLabel2_6_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6_2_2->sizePolicy().hasHeightForWidth() ) );
    layout50_2_2->addWidget( textLabel2_6_2_2 );

    QLCDNImporte = new QLCDNumber( groupBox1, "QLCDNImporte" );
    QLCDNImporte->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDNImporte->sizePolicy().hasHeightForWidth() ) );
    QLCDNImporte->setNumDigits( 8 );
    layout50_2_2->addWidget( QLCDNImporte );
    layout21_2->addLayout( layout50_2_2 );
    layout22_2->addLayout( layout21_2 );

    layout50 = new QVBoxLayout( 0, 0, 6, "layout50"); 

    textLabel2_6 = new QLabel( groupBox1, "textLabel2_6" );
    textLabel2_6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_6->sizePolicy().hasHeightForWidth() ) );
    layout50->addWidget( textLabel2_6 );

    QLCDTotalOrden = new QLCDNumber( groupBox1, "QLCDTotalOrden" );
    QLCDTotalOrden->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDTotalOrden->sizePolicy().hasHeightForWidth() ) );
    QLCDTotalOrden->setNumDigits( 8 );
    layout50->addWidget( QLCDTotalOrden );
    layout22_2->addLayout( layout50 );

    groupBox1Layout->addMultiCellLayout( layout22_2, 0, 1, 1, 1 );

    VentasLayout->addMultiCellWidget( groupBox1, 2, 2, 0, 2 );
    languageChange();
    resize( QSize(669, 651).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Ventas::~Ventas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Ventas::languageChange()
{
    setCaption( tr( "Ventas" ) );
    textLabel2_4->setText( tr( "Detalle Orden" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Tipo Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Importe" ) );
    textLabel2_7->setText( tr( "Precios" ) );
    textLabel2_2->setText( tr( "Productos" ) );
    textLabel2_2_2->setText( tr( "Cantidad" ) );
    QLECantidad->setText( tr( "1" ) );
    textLabel2_2_2_2->setText( tr( "Por Importe" ) );
    textLabel2->setText( tr( "Clientes" ) );
    textLabel2_8->setText( tr( "Contactos" ) );
    textLabel2_9->setText( tr( "Forma De Pago" ) );
    QPBAnexar->setText( tr( "Anexar A La Orden" ) );
    pushButton5_2->setText( tr( "Realizar Venta" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBRegistra->setText( tr( "Realizar Ventas" ) );
    QPBEliminar->setText( tr( "Eliminar Productos" ) );
    groupBox1->setTitle( tr( "Datos Orden" ) );
    textLabel2_5->setText( tr( "Cliente" ) );
    textLabel2_3->setText( tr( "Descripcion Producto" ) );
    textLabel2_6_2_3->setText( tr( "Existencia" ) );
    textLabel2_6_2->setText( tr( "Precio Producto" ) );
    textLabel2_6_2_2->setText( tr( "Importe Producto" ) );
    textLabel2_6->setText( tr( "Total De La Orden" ) );
}

