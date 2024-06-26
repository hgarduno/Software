/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CatalogoStock.ui'
**
** Created: Thu Apr 11 21:07:28 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CatalogoStock.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtabwidget.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlTiendasEntrega.h"

/*
 *  Constructs a CatalogoStock as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CatalogoStock::CatalogoStock( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CatalogoStock" );

    QWidget* privateLayoutWidget = new QWidget( this, "layout2" );
    privateLayoutWidget->setGeometry( QRect( 11, 105, 639, 401 ) );
    layout2 = new QVBoxLayout( privateLayoutWidget, 11, 6, "layout2"); 

    textLabel1 = new QLabel( privateLayoutWidget, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QTProductos = new QTable( privateLayoutWidget, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Proveedor" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Modelo" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Codigo Barras" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Stock" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 5 );
    layout2->addWidget( QTProductos );

    QWidget* privateLayoutWidget_2 = new QWidget( this, "layout8" );
    privateLayoutWidget_2->setGeometry( QRect( 11, 512, 639, 23 ) );
    layout8 = new QHBoxLayout( privateLayoutWidget_2, 11, 6, "layout8"); 

    PushButton1 = new QPushButton( privateLayoutWidget_2, "PushButton1" );
    layout8->addWidget( PushButton1 );

    PushButton2 = new QPushButton( privateLayoutWidget_2, "PushButton2" );
    layout8->addWidget( PushButton2 );

    PushButton3 = new QPushButton( privateLayoutWidget_2, "PushButton3" );
    layout8->addWidget( PushButton3 );

    PushButton4 = new QPushButton( privateLayoutWidget_2, "PushButton4" );
    layout8->addWidget( PushButton4 );

    tabWidget2 = new QTabWidget( this, "tabWidget2" );
    tabWidget2->setGeometry( QRect( 11, 11, 639, 88 ) );
    tabWidget2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, tabWidget2->sizePolicy().hasHeightForWidth() ) );

    tab = new QWidget( tabWidget2, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2 = new QLabel( tab, "textLabel2" );
    layout6->addWidget( textLabel2 );

    CtrTiendas = new QCtrlTiendasEntrega( tab, "CtrTiendas" );
    layout6->addWidget( CtrTiendas );

    tabLayout->addLayout( layout6, 0, 0 );
    tabWidget2->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget2, "tab_2" );
    tabWidget2->insertTab( tab_2, QString::fromLatin1("") );
    languageChange();
    resize( QSize(661, 546).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CatalogoStock::~CatalogoStock()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CatalogoStock::languageChange()
{
    setCaption( tr( "Catalogo Stock " ) );
    textLabel1->setText( tr( "Productos" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Proveedor" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Modelo" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Codigo Barras" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "Stock" ) );
    PushButton1->setText( tr( "PushButton1" ) );
    QToolTip::add( PushButton1, tr( "Se realizara la impresion en toda la hoja del producto seleccionado en la tabla" ) );
    PushButton2->setText( tr( "PushButton2" ) );
    QToolTip::add( PushButton2, tr( "Se realizara la impresion de cada uno de los codigos mostrados en la hoja" ) );
    PushButton3->setText( tr( "PushButton3" ) );
    QToolTip::add( PushButton3, tr( "Se realizara la impresion de los productos mostrados en tabla en grupos de (x8)" ) );
    PushButton4->setText( tr( "PushButton4" ) );
    textLabel2->setText( tr( "Tiendas" ) );
    tabWidget2->changeTab( tab, tr( "Stock Por  Tienda" ) );
    tabWidget2->changeTab( tab_2, tr( "Stock Por Producto" ) );
}

