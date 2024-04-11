/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepExistenciaTiendaProveedor.ui'
**
** Created: Sat Jan 27 16:38:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepExistenciaTiendaProveedor.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlProveedoresSS.h"
#include "QCtrlProductosSS.h"

/*
 *  Constructs a RepExistenciaTiendaProveedor as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepExistenciaTiendaProveedor::RepExistenciaTiendaProveedor( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepExistenciaTiendaProveedor" );
    RepExistenciaTiendaProveedorLayout = new QGridLayout( this, 1, 1, 11, 6, "RepExistenciaTiendaProveedorLayout"); 

    textLabel4 = new QLabel( this, "textLabel4" );

    RepExistenciaTiendaProveedorLayout->addWidget( textLabel4, 1, 0 );

    table4 = new QTable( this, "table4" );
    table4->setNumRows( 0 );
    table4->setNumCols( 3 );

    RepExistenciaTiendaProveedorLayout->addWidget( table4, 2, 0 );

    layout43 = new QHBoxLayout( 0, 0, 6, "layout43"); 

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout42->addWidget( textLabel3 );

    ctrlTiendasEntrega1 = new QCtrlTiendasEntrega( this, "ctrlTiendasEntrega1" );
    layout42->addWidget( ctrlTiendasEntrega1 );
    layout43->addLayout( layout42 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout3_2->addWidget( textLabel2_2 );

    ctrlProveedoresSS1_2 = new QCtrlProveedoresSS( this, "ctrlProveedoresSS1_2" );
    ctrlProveedoresSS1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, ctrlProveedoresSS1_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( ctrlProveedoresSS1_2 );
    layout43->addLayout( layout3_2 );

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout36->addWidget( textLabel1 );

    ctrlProductosSS1 = new QCtrlProductosSS( this, "ctrlProductosSS1" );
    layout36->addWidget( ctrlProductosSS1 );
    layout43->addLayout( layout36 );

    RepExistenciaTiendaProveedorLayout->addLayout( layout43, 0, 0 );

    layout38 = new QHBoxLayout( 0, 0, 6, "layout38"); 

    pushButton7 = new QPushButton( this, "pushButton7" );
    layout38->addWidget( pushButton7 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout38->addWidget( QPBImprimir );

    RepExistenciaTiendaProveedorLayout->addLayout( layout38, 3, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepExistenciaTiendaProveedor::~RepExistenciaTiendaProveedor()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepExistenciaTiendaProveedor::languageChange()
{
    setCaption( tr( "Form3" ) );
    textLabel4->setText( tr( "Reporte Existencias por tienda por proveedor" ) );
    textLabel3->setText( tr( "Tiendas" ) );
    textLabel2_2->setText( tr( "Proveedores" ) );
    textLabel1->setText( tr( "Productos" ) );
    pushButton7->setText( tr( "Consultar" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
}

