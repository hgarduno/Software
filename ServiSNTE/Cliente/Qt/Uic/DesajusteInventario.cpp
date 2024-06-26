/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/DesajusteInventario.ui'
**
** Created: Thu Apr 11 21:07:55 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DesajusteInventario.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"

/*
 *  Constructs a DesajusteInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
DesajusteInventario::DesajusteInventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "DesajusteInventario" );
    DesajusteInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "DesajusteInventarioLayout"); 

    layout71 = new QVBoxLayout( 0, 0, 6, "layout71"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout71->addWidget( textLabel4 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    layout71->addWidget( QCtrTiendas );

    DesajusteInventarioLayout->addLayout( layout71, 0, 0 );

    layout72 = new QVBoxLayout( 0, 0, 6, "layout72"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout72->addWidget( textLabel5 );

    table5 = new QTable( this, "table5" );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "Folio" ) );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "Responsable" ) );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "Fecha" ) );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "Status" ) );
    table5->setNumRows( 0 );
    table5->setNumCols( 4 );
    layout72->addWidget( table5 );

    DesajusteInventarioLayout->addLayout( layout72, 1, 0 );

    layout73 = new QVBoxLayout( 0, 0, 6, "layout73"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout73->addWidget( textLabel6 );

    table6 = new QTable( this, "table6" );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "#Proveedor" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Proveedor" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Producto" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Modelo" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Cantidad" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Exis" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Dif" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Elim" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Sts" ) );
    table6->setNumRows( 0 );
    table6->setNumCols( 9 );
    layout73->addWidget( table6 );

    DesajusteInventarioLayout->addLayout( layout73, 2, 0 );

    layout74 = new QHBoxLayout( 0, 0, 6, "layout74"); 

    pushButton17 = new QPushButton( this, "pushButton17" );
    layout74->addWidget( pushButton17 );

    pushButton17_2 = new QPushButton( this, "pushButton17_2" );
    layout74->addWidget( pushButton17_2 );

    pushButton17_2_2 = new QPushButton( this, "pushButton17_2_2" );
    layout74->addWidget( pushButton17_2_2 );

    DesajusteInventarioLayout->addLayout( layout74, 3, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DesajusteInventario::~DesajusteInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DesajusteInventario::languageChange()
{
    setCaption( tr( "Desajuste Inventarios" ) );
    textLabel4->setText( tr( "Tiendas" ) );
    textLabel5->setText( tr( "textLabel5" ) );
    table5->horizontalHeader()->setLabel( 0, tr( "Folio" ) );
    table5->horizontalHeader()->setLabel( 1, tr( "Responsable" ) );
    table5->horizontalHeader()->setLabel( 2, tr( "Fecha" ) );
    table5->horizontalHeader()->setLabel( 3, tr( "Status" ) );
    textLabel6->setText( tr( "textLabel6" ) );
    table6->horizontalHeader()->setLabel( 0, tr( "#Proveedor" ) );
    table6->horizontalHeader()->setLabel( 1, tr( "Proveedor" ) );
    table6->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
    table6->horizontalHeader()->setLabel( 3, tr( "Modelo" ) );
    table6->horizontalHeader()->setLabel( 4, tr( "Cantidad" ) );
    table6->horizontalHeader()->setLabel( 5, tr( "Exis" ) );
    table6->horizontalHeader()->setLabel( 6, tr( "Dif" ) );
    table6->horizontalHeader()->setLabel( 7, tr( "Elim" ) );
    table6->horizontalHeader()->setLabel( 8, tr( "Sts" ) );
    pushButton17->setText( tr( "pushButton17" ) );
    pushButton17_2->setText( tr( "pushButton17" ) );
    pushButton17_2_2->setText( tr( "pushButton17" ) );
}

