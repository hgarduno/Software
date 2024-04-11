/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepPreciosProducto.ui'
**
** Created: Thu Apr 11 21:07:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepPreciosProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlTiendasEntrega.h"
#include "QCtrlProveedoresSS.h"
#include "QCtrlDepartamentosSS.h"

/*
 *  Constructs a RepPreciosProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepPreciosProducto::RepPreciosProducto( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepPreciosProducto" );
    RepPreciosProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "RepPreciosProductoLayout"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    layout2->addWidget( QCtrTiendas );

    RepPreciosProductoLayout->addLayout( layout2, 0, 0 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout3->addWidget( textLabel1_2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout3->addWidget( QCtrProveedores );

    RepPreciosProductoLayout->addLayout( layout3, 0, 2 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout5->addWidget( textLabel1_3 );

    QCtrDepartamentos = new QCtrlDepartamentosSS( this, "QCtrDepartamentos" );
    layout5->addWidget( QCtrDepartamentos );

    RepPreciosProductoLayout->addLayout( layout5, 0, 1 );

    QTListaPrecios = new QTable( this, "QTListaPrecios" );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "#Proveedor" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Proveedor" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Num Producto" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Producto" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Modelo" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Stock" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Precio Unitario" ) );
    QTListaPrecios->setNumRows( 0 );
    QTListaPrecios->setNumCols( 7 );

    RepPreciosProductoLayout->addMultiCellWidget( QTListaPrecios, 1, 1, 0, 2 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );

    RepPreciosProductoLayout->addMultiCellWidget( QPBImprimir, 2, 2, 1, 2 );

    QPBConsulta = new QPushButton( this, "QPBConsulta" );

    RepPreciosProductoLayout->addWidget( QPBConsulta, 2, 0 );
    languageChange();
    resize( QSize(835, 487).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepPreciosProducto::~RepPreciosProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepPreciosProducto::languageChange()
{
    setCaption( tr( "Biblia Por Tienda ( 2 )" ) );
    textLabel1->setText( tr( "Tiendas" ) );
    textLabel1_2->setText( tr( "Proveedor" ) );
    textLabel1_3->setText( tr( "Departamento" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 0, tr( "#Proveedor" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 1, tr( "Proveedor" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 2, tr( "Num Producto" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 3, tr( "Producto" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 4, tr( "Modelo" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 5, tr( "Stock" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 6, tr( "Precio Unitario" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBConsulta->setText( tr( "Consulta" ) );
}

