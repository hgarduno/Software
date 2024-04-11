/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepStockTienda.ui'
**
** Created: Sat Jan 27 16:38:18 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepStockTienda.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a RepStockTienda as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepStockTienda::RepStockTienda( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepStockTienda" );
    RepStockTiendaLayout = new QGridLayout( this, 1, 1, 11, 6, "RepStockTiendaLayout"); 

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    QTListaStock = new QTable( this, "QTListaStock" );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "# Proveedor" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Proveedor" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Producto" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Descripcion del producto" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Modelo" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Stock" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Costo" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Imp. Costo" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Venta" ) );
    QTListaStock->setNumCols( QTListaStock->numCols() + 1 );
    QTListaStock->horizontalHeader()->setLabel( QTListaStock->numCols() - 1, tr( "Imp. Venta" ) );
    QTListaStock->setNumRows( 0 );
    QTListaStock->setNumCols( 10 );
    layout4->addWidget( QTListaStock );

    RepStockTiendaLayout->addMultiCellLayout( layout4, 2, 2, 0, 2 );

    QPBConsulta = new QPushButton( this, "QPBConsulta" );

    RepStockTiendaLayout->addMultiCellWidget( QPBConsulta, 3, 3, 0, 1 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );

    RepStockTiendaLayout->addWidget( QPBImprimir, 3, 2 );

    layout48 = new QHBoxLayout( 0, 0, 6, "layout48"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1->addWidget( textLabel1_2 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    layout1->addWidget( QCtrTiendas );
    layout48->addLayout( layout1 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout3->addWidget( textLabel2_2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout3->addWidget( QCtrProveedores );
    layout48->addLayout( layout3 );

    RepStockTiendaLayout->addMultiCellLayout( layout48, 0, 0, 0, 2 );

    QRBPrecio = new QRadioButton( this, "QRBPrecio" );

    RepStockTiendaLayout->addWidget( QRBPrecio, 1, 0 );

    QRBImporteVenta = new QRadioButton( this, "QRBImporteVenta" );

    RepStockTiendaLayout->addWidget( QRBImporteVenta, 1, 1 );
    languageChange();
    resize( QSize(985, 566).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepStockTienda::~RepStockTienda()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepStockTienda::languageChange()
{
    setCaption( tr( "Reporte de Stock Por Tienda ( 5 )" ) );
    textLabel2->setText( tr( "Tabla" ) );
    QTListaStock->horizontalHeader()->setLabel( 0, tr( "# Proveedor" ) );
    QTListaStock->horizontalHeader()->setLabel( 1, tr( "Proveedor" ) );
    QTListaStock->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
    QTListaStock->horizontalHeader()->setLabel( 3, tr( "Descripcion del producto" ) );
    QTListaStock->horizontalHeader()->setLabel( 4, tr( "Modelo" ) );
    QTListaStock->horizontalHeader()->setLabel( 5, tr( "Stock" ) );
    QTListaStock->horizontalHeader()->setLabel( 6, tr( "Costo" ) );
    QTListaStock->horizontalHeader()->setLabel( 7, tr( "Imp. Costo" ) );
    QTListaStock->horizontalHeader()->setLabel( 8, tr( "Venta" ) );
    QTListaStock->horizontalHeader()->setLabel( 9, tr( "Imp. Venta" ) );
    QPBConsulta->setText( tr( "Consulta" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    textLabel1_2->setText( tr( "Tiendas" ) );
    textLabel2_2->setText( tr( "Proveedor" ) );
    QRBPrecio->setText( tr( "Venta" ) );
    QRBImporteVenta->setText( tr( "Importe Venta" ) );
}

