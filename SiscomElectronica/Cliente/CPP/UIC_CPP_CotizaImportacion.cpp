/****************************************************************************
** Form implementation generated from reading ui file 'UI/CotizaImportacion.ui'
**
** Created: Thu Dec 21 12:53:45 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CotizaImportacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QCtrlProveedoresSE.h>
#include <QCtrlProductosSE.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSE.h"
#include "QCtrlProductosSE.h"

/*
 *  Constructs a CotizaImportacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CotizaImportacion::CotizaImportacion( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CotizaImportacion" );
    CotizaImportacionLayout = new QGridLayout( this, 1, 1, 11, 6, "CotizaImportacionLayout"); 

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( groupBox1, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QLEPeso = new QLineEdit( groupBox1, "QLEPeso" );
    layout2->addWidget( QLEPeso );

    groupBox1Layout->addLayout( layout2, 0, 0 );

    CotizaImportacionLayout->addWidget( groupBox1, 1, 0 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( textLabel2_2 );

    QLECostoDolar = new QLineEdit( this, "QLECostoDolar" );
    QLECostoDolar->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoDolar->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( QLECostoDolar );
    layout14->addLayout( layout2_2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout3->addWidget( textLabel3 );

    QCtrProveedores = new QCtrlProveedoresSE( this, "QCtrProveedores" );
    QCtrProveedores->setEnabled( FALSE );
    layout3->addWidget( QCtrProveedores );
    layout14->addLayout( layout3 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setEnabled( FALSE );
    layout1->addWidget( QCtrProductos );
    layout14->addLayout( layout1 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( textLabel4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( QLECantidad );
    layout14->addLayout( layout4 );

    layout4_2 = new QVBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( textLabel4_2 );

    QLEPrecio = new QLineEdit( this, "QLEPrecio" );
    QLEPrecio->setEnabled( FALSE );
    QLEPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPrecio->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( QLEPrecio );
    layout14->addLayout( layout4_2 );

    CotizaImportacionLayout->addLayout( layout14, 0, 0 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout6->addWidget( textLabel5 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Peso" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Peso Total" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Precio" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Importe" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 6 );
    QTProductos->setReadOnly( TRUE );
    layout6->addWidget( QTProductos );
    layout16->addLayout( layout6 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel8 = new QLabel( this, "textLabel8" );
    layout15->addWidget( textLabel8 );

    QTEDatosCotizacion = new QTextEdit( this, "QTEDatosCotizacion" );
    QTEDatosCotizacion->setReadOnly( TRUE );
    layout15->addWidget( QTEDatosCotizacion );
    layout16->addLayout( layout15 );

    CotizaImportacionLayout->addLayout( layout16, 2, 0 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    QPBConsulta->setEnabled( TRUE );
    layout17->addWidget( QPBConsulta );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setEnabled( FALSE );
    layout17->addWidget( QPBRegistra );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout17->addWidget( QPBAnexar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setEnabled( FALSE );
    layout17->addWidget( QPBEliminar );

    CotizaImportacionLayout->addLayout( layout17, 3, 0 );
    languageChange();
    resize( QSize(766, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CotizaImportacion::~CotizaImportacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CotizaImportacion::languageChange()
{
    setCaption( tr( "Cotizacion Importacion" ) );
    groupBox1->setTitle( tr( "Datos Producto" ) );
    textLabel2->setText( tr( "Peso" ) );
    textLabel2_2->setText( tr( "Costo Dolar" ) );
    textLabel3->setText( tr( "Proveedores" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel4->setText( tr( "Cantidad" ) );
    textLabel4_2->setText( tr( "Precio" ) );
    textLabel5->setText( tr( "Productos" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Peso" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Peso Total" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "Precio" ) );
    QTProductos->horizontalHeader()->setLabel( 5, tr( "Importe" ) );
    textLabel8->setText( tr( "Datos Cotizacion" ) );
    QPBConsulta->setText( tr( "Consulta Cotizacion" ) );
    QPBRegistra->setText( tr( "Registra Cotizacion Importacion" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBEliminar->setText( tr( "Eliminar" ) );
}

