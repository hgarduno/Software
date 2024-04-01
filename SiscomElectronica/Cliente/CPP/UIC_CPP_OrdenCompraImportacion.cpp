/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenCompraImportacion.ui'
**
** Created: Wed Jan 31 10:48:13 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenCompraImportacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <QCtrlProveedoresSE.h>
#include <QCtrlProductosSE.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProveedoresSE.h"
#include "QCtrlProductosSE.h"

/*
 *  Constructs a OrdenCompraImportacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
OrdenCompraImportacion::OrdenCompraImportacion( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "OrdenCompraImportacion" );
    OrdenCompraImportacionLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenCompraImportacionLayout"); 

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)1, 0, 0, groupBox1->sizePolicy().hasHeightForWidth() ) );
    groupBox1->setMinimumSize( QSize( 0, 118 ) );
    groupBox1->setMaximumSize( QSize( 32767, 250 ) );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout55 = new QVBoxLayout( 0, 0, 6, "layout55"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel1 = new QLabel( groupBox1, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel1 );

    QCtrProveedores = new QCtrlProveedoresSE( groupBox1, "QCtrProveedores" );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)0, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( QCtrProveedores );
    layout55->addLayout( layout9 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel2 = new QLabel( groupBox1, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout15->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProductosSE( groupBox1, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout15->addWidget( QCtrProductos );
    layout55->addLayout( layout15 );

    layout54 = new QHBoxLayout( 0, 0, 6, "layout54"); 

    layout19_2_3_3_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_3_3_2"); 

    textLabel1_2_2_3_3_2 = new QLabel( groupBox1, "textLabel1_2_2_3_3_2" );
    layout19_2_3_3_2->addWidget( textLabel1_2_2_3_3_2 );

    QLECantidadC = new QLineEdit( groupBox1, "QLECantidadC" );
    QLECantidadC->setReadOnly( FALSE );
    layout19_2_3_3_2->addWidget( QLECantidadC );
    layout54->addLayout( layout19_2_3_3_2 );

    layout19_2_3_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_3_3_2_2"); 

    textLabel1_2_2_3_3_2_2 = new QLabel( groupBox1, "textLabel1_2_2_3_3_2_2" );
    layout19_2_3_3_2_2->addWidget( textLabel1_2_2_3_3_2_2 );

    QLEPrecio = new QLineEdit( groupBox1, "QLEPrecio" );
    QLEPrecio->setReadOnly( FALSE );
    layout19_2_3_3_2_2->addWidget( QLEPrecio );
    layout54->addLayout( layout19_2_3_3_2_2 );
    layout55->addLayout( layout54 );

    layout53 = new QHBoxLayout( 0, 0, 6, "layout53"); 

    layout19_2_3_3 = new QVBoxLayout( 0, 0, 6, "layout19_2_3_3"); 

    textLabel1_2_2_3_3 = new QLabel( groupBox1, "textLabel1_2_2_3_3" );
    layout19_2_3_3->addWidget( textLabel1_2_2_3_3 );

    QLECveProductoProveedor = new QLineEdit( groupBox1, "QLECveProductoProveedor" );
    QLECveProductoProveedor->setReadOnly( TRUE );
    layout19_2_3_3->addWidget( QLECveProductoProveedor );
    layout53->addLayout( layout19_2_3_3 );

    layout19_2_3_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_3_2"); 

    textLabel1_2_2_3_2 = new QLabel( groupBox1, "textLabel1_2_2_3_2" );
    layout19_2_3_2->addWidget( textLabel1_2_2_3_2 );

    QLEPeso = new QLineEdit( groupBox1, "QLEPeso" );
    layout19_2_3_2->addWidget( QLEPeso );
    layout53->addLayout( layout19_2_3_2 );
    layout55->addLayout( layout53 );

    QTEDescripcionP = new QTextEdit( groupBox1, "QTEDescripcionP" );
    QTEDescripcionP->setMinimumSize( QSize( 0, 45 ) );
    QTEDescripcionP->setMaximumSize( QSize( 32767, 45 ) );
    layout55->addWidget( QTEDescripcionP );

    groupBox1Layout->addLayout( layout55, 0, 0 );

    layout58 = new QVBoxLayout( 0, 0, 6, "layout58"); 

    layout56_2 = new QVBoxLayout( 0, 0, 6, "layout56_2"); 

    textLabel4_3_2 = new QLabel( groupBox1, "textLabel4_3_2" );
    textLabel4_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4_3_2->sizePolicy().hasHeightForWidth() ) );
    layout56_2->addWidget( textLabel4_3_2 );

    QLCDImporte = new QLCDNumber( groupBox1, "QLCDImporte" );
    QLCDImporte->setMinimumSize( QSize( 200, 0 ) );
    QLCDImporte->setNumDigits( 10 );
    layout56_2->addWidget( QLCDImporte );
    layout58->addLayout( layout56_2 );

    layout56 = new QVBoxLayout( 0, 0, 6, "layout56"); 

    textLabel4_3 = new QLabel( groupBox1, "textLabel4_3" );
    textLabel4_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4_3->sizePolicy().hasHeightForWidth() ) );
    layout56->addWidget( textLabel4_3 );

    QLCDPeso = new QLCDNumber( groupBox1, "QLCDPeso" );
    QLCDPeso->setNumDigits( 10 );
    layout56->addWidget( QLCDPeso );
    layout58->addLayout( layout56 );

    groupBox1Layout->addLayout( layout58, 0, 1 );

    OrdenCompraImportacionLayout->addWidget( groupBox1, 0, 0 );

    groupBox2 = new QGroupBox( this, "groupBox2" );
    groupBox2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)1, 0, 0, groupBox2->sizePolicy().hasHeightForWidth() ) );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    pushButton4 = new QPushButton( groupBox2, "pushButton4" );
    pushButton4->setMinimumSize( QSize( 0, 50 ) );

    groupBox2Layout->addWidget( pushButton4, 1, 0 );

    layout34 = new QHBoxLayout( 0, 0, 6, "layout34"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel1_2 = new QLabel( groupBox2, "textLabel1_2" );
    layout19->addWidget( textLabel1_2 );

    QLEFecha = new QLineEdit( groupBox2, "QLEFecha" );
    layout19->addWidget( QLEFecha );
    layout34->addLayout( layout19 );

    layout19_2 = new QVBoxLayout( 0, 0, 6, "layout19_2"); 

    textLabel1_2_2 = new QLabel( groupBox2, "textLabel1_2_2" );
    layout19_2->addWidget( textLabel1_2_2 );

    QLECantidad = new QLineEdit( groupBox2, "QLECantidad" );
    layout19_2->addWidget( QLECantidad );
    layout34->addLayout( layout19_2 );

    layout19_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_2"); 

    textLabel1_2_2_2 = new QLabel( groupBox2, "textLabel1_2_2_2" );
    layout19_2_2->addWidget( textLabel1_2_2_2 );

    QLECosto = new QLineEdit( groupBox2, "QLECosto" );
    layout19_2_2->addWidget( QLECosto );
    layout34->addLayout( layout19_2_2 );

    layout19_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_2_2"); 

    textLabel1_2_2_2_2 = new QLabel( groupBox2, "textLabel1_2_2_2_2" );
    layout19_2_2_2->addWidget( textLabel1_2_2_2_2 );

    QLECostoTotal = new QLineEdit( groupBox2, "QLECostoTotal" );
    layout19_2_2_2->addWidget( QLECostoTotal );
    layout34->addLayout( layout19_2_2_2 );

    groupBox2Layout->addLayout( layout34, 0, 0 );

    table4 = new QTable( groupBox2, "table4" );
    table4->setNumRows( 3 );
    table4->setNumCols( 3 );

    groupBox2Layout->addWidget( table4, 2, 0 );

    OrdenCompraImportacionLayout->addWidget( groupBox2, 0, 1 );

    layout30 = new QHBoxLayout( 0, 0, 6, "layout30"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout30->addWidget( QPBAnexar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setEnabled( FALSE );
    layout30->addWidget( QPBEliminar );

    pushButton5_2_2 = new QPushButton( this, "pushButton5_2_2" );
    pushButton5_2_2->setEnabled( FALSE );
    layout30->addWidget( pushButton5_2_2 );

    pushButton5_2_3 = new QPushButton( this, "pushButton5_2_3" );
    layout30->addWidget( pushButton5_2_3 );

    pushButton5_2_3_2 = new QPushButton( this, "pushButton5_2_3_2" );
    layout30->addWidget( pushButton5_2_3_2 );

    OrdenCompraImportacionLayout->addMultiCellLayout( layout30, 2, 2, 0, 1 );

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout27->addWidget( textLabel3 );

    table2 = new QTable( this, "table2" );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Clave P" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Clave S" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Descripcion" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Cantidad" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Precio" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Peso" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Importe" ) );
    table2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)7, 0, 0, table2->sizePolicy().hasHeightForWidth() ) );
    table2->setNumRows( 0 );
    table2->setNumCols( 7 );
    layout27->addWidget( table2 );
    layout32->addLayout( layout27 );

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    layout31_2 = new QVBoxLayout( 0, 0, 6, "layout31_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    textLabel4_2->setMinimumSize( QSize( 200, 0 ) );
    layout31_2->addWidget( textLabel4_2 );

    QLCDImportTotal = new QLCDNumber( this, "QLCDImportTotal" );
    QLCDImportTotal->setNumDigits( 8 );
    layout31_2->addWidget( QLCDImportTotal );
    layout33->addLayout( layout31_2 );

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout31->addWidget( textLabel4 );

    QLCDPesoTotal = new QLCDNumber( this, "QLCDPesoTotal" );
    QLCDPesoTotal->setNumDigits( 8 );
    layout31->addWidget( QLCDPesoTotal );
    layout33->addLayout( layout31 );
    layout32->addLayout( layout33 );

    OrdenCompraImportacionLayout->addMultiCellLayout( layout32, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(931, 529).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenCompraImportacion::~OrdenCompraImportacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenCompraImportacion::languageChange()
{
    setCaption( tr( "Form1" ) );
    groupBox1->setTitle( tr( "Datos Compra" ) );
    textLabel1->setText( tr( "Proveedores" ) );
    textLabel2->setText( tr( "Productos Siscom" ) );
    textLabel1_2_2_3_3_2->setText( tr( "Cantidad" ) );
    textLabel1_2_2_3_3_2_2->setText( tr( "Precio" ) );
    textLabel1_2_2_3_3->setText( tr( "Proveedor" ) );
    textLabel1_2_2_3_2->setText( tr( "Peso" ) );
    textLabel4_3_2->setText( tr( "Importe" ) );
    textLabel4_3->setText( tr( "Peso" ) );
    groupBox2->setTitle( tr( "Ultima Compra" ) );
    pushButton4->setText( tr( "Historial De\n"
"Compras" ) );
    textLabel1_2->setText( tr( "Fecha" ) );
    textLabel1_2_2->setText( tr( "Cantidad" ) );
    textLabel1_2_2_2->setText( tr( "Precio $" ) );
    textLabel1_2_2_2_2->setText( tr( "Importe Total" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBEliminar->setText( tr( "Eliminar" ) );
    pushButton5_2_2->setText( tr( "Guardar" ) );
    pushButton5_2_3->setText( tr( "Cargar" ) );
    pushButton5_2_3_2->setText( tr( "Registrar" ) );
    textLabel3->setText( tr( "Lista de Compra" ) );
    table2->horizontalHeader()->setLabel( 0, tr( "Clave P" ) );
    table2->horizontalHeader()->setLabel( 1, tr( "Clave S" ) );
    table2->horizontalHeader()->setLabel( 2, tr( "Descripcion" ) );
    table2->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    table2->horizontalHeader()->setLabel( 4, tr( "Precio" ) );
    table2->horizontalHeader()->setLabel( 5, tr( "Peso" ) );
    table2->horizontalHeader()->setLabel( 6, tr( "Importe" ) );
    textLabel4_2->setText( tr( "Importe Total" ) );
    textLabel4->setText( tr( "Peso Total" ) );
}

