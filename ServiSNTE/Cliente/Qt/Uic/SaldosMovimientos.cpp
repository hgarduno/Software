/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/SaldosMovimientos.ui'
**
** Created: Sat Jan 27 16:38:28 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "SaldosMovimientos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtabwidget.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlProveedoresSS.h"
#include "QCtrlProductosSS.h"
#include "QCtrlStock.h"
#include "QCtrlExistenciaProveedor.h"
#include "QCtrlSaldosMovimientosMes.h"
#include "QCtrlConceptosSaldosMovimientos.h"

/*
 *  Constructs a SaldosMovimientos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SaldosMovimientos::SaldosMovimientos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SaldosMovimientos" );
    SaldosMovimientosLayout = new QGridLayout( this, 1, 1, 11, 6, "SaldosMovimientosLayout"); 

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout56 = new QVBoxLayout( 0, 0, 6, "layout56"); 

    Tienda = new QLabel( this, "Tienda" );
    layout56->addWidget( Tienda );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    layout56->addWidget( QCtrTiendas );
    layout8->addLayout( layout56 );

    layout57 = new QVBoxLayout( 0, 0, 6, "layout57"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout57->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout57->addWidget( QCtrProveedores );
    layout8->addLayout( layout57 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_2_3 = new QLabel( this, "textLabel1_2_3" );
    textLabel1_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_3->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1_2_3 );

    QCtrProductos = new QCtrlProductosSS( this, "QCtrProductos" );
    layout7->addWidget( QCtrProductos );
    layout8->addLayout( layout7 );

    SaldosMovimientosLayout->addMultiCellLayout( layout8, 0, 0, 0, 1 );

    pushButton4 = new QPushButton( this, "pushButton4" );

    SaldosMovimientosLayout->addMultiCellWidget( pushButton4, 3, 3, 0, 1 );

    QTWInformacion = new QTabWidget( this, "QTWInformacion" );

    tab = new QWidget( QTWInformacion, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    QCtrStock = new QCtrlStock( tab, "QCtrStock" );
    QCtrStock->setNumRows( 0 );
    QCtrStock->setNumCols( 0 );

    tabLayout->addWidget( QCtrStock, 0, 0 );
    QTWInformacion->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( QTWInformacion, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    textLabel2_3 = new QLabel( tab_2, "textLabel2_3" );
    layout9->addWidget( textLabel2_3 );

    QLEStockTotal = new QLineEdit( tab_2, "QLEStockTotal" );
    QLEStockTotal->setReadOnly( TRUE );
    layout9->addWidget( QLEStockTotal );

    tabLayout_2->addLayout( layout9, 1, 0 );

    layout9_2 = new QHBoxLayout( 0, 0, 6, "layout9_2"); 

    textLabel2_3_2 = new QLabel( tab_2, "textLabel2_3_2" );
    layout9_2->addWidget( textLabel2_3_2 );

    QLEExistenciaTotal = new QLineEdit( tab_2, "QLEExistenciaTotal" );
    QLEExistenciaTotal->setReadOnly( TRUE );
    layout9_2->addWidget( QLEExistenciaTotal );

    tabLayout_2->addLayout( layout9_2, 1, 1 );

    QCtrExistenciaProveedor = new QCtrlExistenciaProveedor( tab_2, "QCtrExistenciaProveedor" );
    QCtrExistenciaProveedor->setNumRows( 0 );
    QCtrExistenciaProveedor->setNumCols( 0 );

    tabLayout_2->addMultiCellWidget( QCtrExistenciaProveedor, 0, 0, 0, 1 );
    QTWInformacion->insertTab( tab_2, QString::fromLatin1("") );

    SaldosMovimientosLayout->addWidget( QTWInformacion, 1, 0 );

    QCtrSaldosMovimientosMes = new QCtrlSaldosMovimientosMes( this, "QCtrSaldosMovimientosMes" );
    QCtrSaldosMovimientosMes->setNumRows( 0 );
    QCtrSaldosMovimientosMes->setNumCols( 0 );

    SaldosMovimientosLayout->addWidget( QCtrSaldosMovimientosMes, 1, 1 );

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout8_2->addWidget( textLabel1 );

    QCtrConceptosSaldosMovimientos = new QCtrlConceptosSaldosMovimientos( this, "QCtrConceptosSaldosMovimientos" );
    QCtrConceptosSaldosMovimientos->setNumRows( 0 );
    QCtrConceptosSaldosMovimientos->setNumCols( 0 );
    layout8_2->addWidget( QCtrConceptosSaldosMovimientos );

    SaldosMovimientosLayout->addMultiCellLayout( layout8_2, 2, 2, 0, 1 );
    languageChange();
    resize( QSize(962, 532).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SaldosMovimientos::~SaldosMovimientos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SaldosMovimientos::languageChange()
{
    setCaption( tr( "Form1" ) );
    Tienda->setText( tr( "Tiendas" ) );
    textLabel2->setText( tr( "Proveedor" ) );
    textLabel1_2_3->setText( tr( "Numero Producto" ) );
    pushButton4->setText( tr( "pushButton4" ) );
    QTWInformacion->changeTab( tab, tr( "Saldos Proveedor" ) );
    textLabel2_3->setText( tr( "Stock Total" ) );
    textLabel2_3_2->setText( tr( "Existencia Total" ) );
    QTWInformacion->changeTab( tab_2, tr( "Saldos En Tiendas" ) );
    textLabel1->setText( tr( "textLabel1" ) );
}

