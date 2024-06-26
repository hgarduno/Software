/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepExistenciaProveedor.ui'
**
** Created: Thu Apr 11 21:07:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepExistenciaProveedor.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a RepExistenciaProveedor as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepExistenciaProveedor::RepExistenciaProveedor( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepExistenciaProveedor" );
    RepExistenciaProveedorLayout = new QGridLayout( this, 1, 1, 11, 6, "RepExistenciaProveedorLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout1->addWidget( QCtrProveedores );

    RepExistenciaProveedorLayout->addLayout( layout1, 0, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    layout4->addWidget( QPBConsulta );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout4->addWidget( QPBImprimir );

    RepExistenciaProveedorLayout->addLayout( layout4, 2, 0 );

    QTExistenciaProveedor = new QTable( this, "QTExistenciaProveedor" );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "#Producto" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Producto" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Modelo" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Tda" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Nombre de la Tienda" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Stk" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Exist" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Imp. Costo" ) );
    QTExistenciaProveedor->setNumCols( QTExistenciaProveedor->numCols() + 1 );
    QTExistenciaProveedor->horizontalHeader()->setLabel( QTExistenciaProveedor->numCols() - 1, tr( "Imp. Venta" ) );
    QTExistenciaProveedor->setNumRows( 0 );
    QTExistenciaProveedor->setNumCols( 9 );

    RepExistenciaProveedorLayout->addWidget( QTExistenciaProveedor, 1, 0 );
    languageChange();
    resize( QSize(732, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepExistenciaProveedor::~RepExistenciaProveedor()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepExistenciaProveedor::languageChange()
{
    setCaption( tr( "Reporte Existencia Por Proveedor ( 1 )" ) );
    textLabel1->setText( tr( "Proveedores" ) );
    QPBConsulta->setText( tr( "Consulta" ) );
    QPBImprimir->setText( tr( "Imprime" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 0, tr( "#Producto" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 2, tr( "Modelo" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 3, tr( "Tda" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 4, tr( "Nombre de la Tienda" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 5, tr( "Stk" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 6, tr( "Exist" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 7, tr( "Imp. Costo" ) );
    QTExistenciaProveedor->horizontalHeader()->setLabel( 8, tr( "Imp. Venta" ) );
}

