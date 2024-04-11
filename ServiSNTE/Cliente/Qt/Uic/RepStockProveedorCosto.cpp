/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepStockProveedorCosto.ui'
**
** Created: Thu Apr 11 21:07:43 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepStockProveedorCosto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a RepStockProveedorCosto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepStockProveedorCosto::RepStockProveedorCosto( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepStockProveedorCosto" );
    RepStockProveedorCostoLayout = new QGridLayout( this, 1, 1, 11, 6, "RepStockProveedorCostoLayout"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout5->addWidget( textLabel1 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout5->addWidget( QCtrProveedores );

    RepStockProveedorCostoLayout->addMultiCellLayout( layout5, 0, 0, 0, 1 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout6->addWidget( textLabel2 );

    QTExistenciaProveedor = new QTable( this, "QTExistenciaProveedor" );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "#Producto" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Producto" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Modelo" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Costo" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Total" ) );
    QTExistenciaProveedor->setNumRows( 0 );
    QTExistenciaProveedor->setNumCols( 5 );
    layout6->addWidget( QTExistenciaProveedor );

    RepStockProveedorCostoLayout->addMultiCellLayout( layout6, 1, 1, 0, 1 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );

    RepStockProveedorCostoLayout->addWidget( QPBImprimir, 2, 1 );

    QPBConsulta = new QPushButton( this, "QPBConsulta" );

    RepStockProveedorCostoLayout->addWidget( QPBConsulta, 2, 0 );
    languageChange();
    resize( QSize(1054, 403).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepStockProveedorCosto::~RepStockProveedorCosto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepStockProveedorCosto::languageChange()
{
    setCaption( tr( "Reporte De Stock Por Proveedor Con Costo ( 4 )" ) );
    textLabel1->setText( tr( "Proveedor" ) );
    textLabel2->setText( tr( "Productos" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 0, tr( "#Producto" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 2, tr( "Modelo" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 3, tr( "Costo" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 4, tr( "Total" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBConsulta->setText( tr( "Consulta" ) );
}

