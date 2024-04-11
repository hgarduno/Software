/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepStockDepartamentoProveedor.ui'
**
** Created: Thu Apr 11 21:07:40 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepStockDepartamentoProveedor.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a RepStockDepartamentoProveedor as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepStockDepartamentoProveedor::RepStockDepartamentoProveedor( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepStockDepartamentoProveedor" );
    RepStockDepartamentoProveedorLayout = new QGridLayout( this, 1, 1, 11, 6, "RepStockDepartamentoProveedorLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    layout1->addWidget( QCtrTiendas );

    RepStockDepartamentoProveedorLayout->addMultiCellLayout( layout1, 0, 0, 0, 1 );

    QTReporte = new QTable( this, "QTReporte" );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "# Producto" ) );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "Producto" ) );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "Modelo" ) );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "Stock" ) );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "Costo Unitario" ) );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "Costo Total" ) );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "Precio Venta" ) );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "Total Venta" ) );
    QTReporte->setNumCols( QTReporte->numCols() + 1 );
    QTReporte->horizontalHeader()->setLabel( QTReporte->numCols() - 1, tr( "Margen" ) );
    QTReporte->setNumRows( 0 );
    QTReporte->setNumCols( 9 );
    QTReporte->setReadOnly( TRUE );

    RepStockDepartamentoProveedorLayout->addMultiCellWidget( QTReporte, 2, 2, 0, 1 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    QCtrProveedor = new QCtrlProveedoresSS( this, "QCtrProveedor" );
    layout4->addWidget( QCtrProveedor );

    RepStockDepartamentoProveedorLayout->addMultiCellLayout( layout4, 1, 1, 0, 1 );

    QPBConsulta = new QPushButton( this, "QPBConsulta" );

    RepStockDepartamentoProveedorLayout->addWidget( QPBConsulta, 3, 0 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );

    RepStockDepartamentoProveedorLayout->addWidget( QPBImprimir, 3, 1 );
    languageChange();
    resize( QSize(965, 493).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepStockDepartamentoProveedor::~RepStockDepartamentoProveedor()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepStockDepartamentoProveedor::languageChange()
{
    setCaption( tr( "Reporte Por Departamento Proveedor" ) );
    textLabel1->setText( tr( "Tiendas" ) );
    QTReporte->horizontalHeader()->setLabel( 0, tr( "# Producto" ) );
    QTReporte->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTReporte->horizontalHeader()->setLabel( 2, tr( "Modelo" ) );
    QTReporte->horizontalHeader()->setLabel( 3, tr( "Stock" ) );
    QTReporte->horizontalHeader()->setLabel( 4, tr( "Costo Unitario" ) );
    QTReporte->horizontalHeader()->setLabel( 5, tr( "Costo Total" ) );
    QTReporte->horizontalHeader()->setLabel( 6, tr( "Precio Venta" ) );
    QTReporte->horizontalHeader()->setLabel( 7, tr( "Total Venta" ) );
    QTReporte->horizontalHeader()->setLabel( 8, tr( "Margen" ) );
    textLabel2->setText( tr( "Proveedor" ) );
    QPBConsulta->setText( tr( "Consulta" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
}

