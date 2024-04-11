/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ImpresionCodigoBarras.ui'
**
** Created: Thu Apr 11 21:07:14 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ImpresionCodigoBarras.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtabwidget.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a ImpresionCodigoBarras as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ImpresionCodigoBarras::ImpresionCodigoBarras( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ImpresionCodigoBarras" );
    ImpresionCodigoBarrasLayout = new QGridLayout( this, 1, 1, 11, 6, "ImpresionCodigoBarrasLayout"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Modelo" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Codigo Barras" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cant. Imp." ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 4 );
    layout2->addWidget( QTProductos );

    ImpresionCodigoBarrasLayout->addLayout( layout2, 1, 0 );

    tabWidget2 = new QTabWidget( this, "tabWidget2" );
    tabWidget2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, tabWidget2->sizePolicy().hasHeightForWidth() ) );

    tab = new QWidget( tabWidget2, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel2 = new QLabel( tab, "textLabel2" );
    layout7->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( tab, "QCtrProveedores" );
    layout7->addWidget( QCtrProveedores );

    tabLayout->addLayout( layout7, 0, 0 );
    tabWidget2->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget2, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( tab_2, "textLabel3" );
    layout5->addWidget( textLabel3 );

    QLEFechaCompra = new QLineEdit( tab_2, "QLEFechaCompra" );
    layout5->addWidget( QLEFechaCompra );
    layout6->addLayout( layout5 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout6->addItem( spacer2 );

    tabLayout_2->addLayout( layout6, 0, 0 );
    tabWidget2->insertTab( tab_2, QString::fromLatin1("") );

    ImpresionCodigoBarrasLayout->addWidget( tabWidget2, 0, 0 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QPBImpresionTodaHoja = new QPushButton( this, "QPBImpresionTodaHoja" );
    layout8->addWidget( QPBImpresionTodaHoja );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout8->addWidget( QPBImprimir );

    QPBImprimirTodo = new QPushButton( this, "QPBImprimirTodo" );
    layout8->addWidget( QPBImprimirTodo );

    QPBTodosProductos = new QPushButton( this, "QPBTodosProductos" );
    layout8->addWidget( QPBTodosProductos );

    ImpresionCodigoBarrasLayout->addLayout( layout8, 2, 0 );
    languageChange();
    resize( QSize(568, 546).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ImpresionCodigoBarras::~ImpresionCodigoBarras()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ImpresionCodigoBarras::languageChange()
{
    setCaption( tr( "Impresion de Codigo de Barras" ) );
    textLabel1->setText( tr( "Productos" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Codigo Barras" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Cant. Imp." ) );
    textLabel2->setText( tr( "Proveedores" ) );
    tabWidget2->changeTab( tab, tr( "Productos Proveedor" ) );
    textLabel3->setText( tr( "Fecha" ) );
    tabWidget2->changeTab( tab_2, tr( "Productos Por Fecha de Compra" ) );
    QPBImpresionTodaHoja->setText( tr( "Impresion Toda La Hoja" ) );
    QToolTip::add( QPBImpresionTodaHoja, tr( "Se realizara la impresion en toda la hoja del producto seleccionado en la tabla" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QToolTip::add( QPBImprimir, tr( "Se realizara la impresion de cada uno de los codigos mostrados en la hoja" ) );
    QPBImprimirTodo->setText( tr( "Imprimir Todo (x8)" ) );
    QToolTip::add( QPBImprimirTodo, tr( "Se realizara la impresion de los productos mostrados en tabla en grupos de (x8)" ) );
    QPBTodosProductos->setText( tr( "Todos Los Productos" ) );
}

