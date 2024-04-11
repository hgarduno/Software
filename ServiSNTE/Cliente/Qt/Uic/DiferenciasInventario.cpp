/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/DiferenciasInventario.ui'
**
** Created: Sat Jan 27 16:38:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "DiferenciasInventario.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"

/*
 *  Constructs a DiferenciasInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
DiferenciasInventario::DiferenciasInventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "DiferenciasInventario" );
    DiferenciasInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "DiferenciasInventarioLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    ctrlTiendasEntrega1 = new QCtrlTiendasEntrega( this, "ctrlTiendasEntrega1" );
    layout1->addWidget( ctrlTiendasEntrega1 );

    DiferenciasInventarioLayout->addMultiCellLayout( layout1, 0, 0, 0, 4 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Folio" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Responsable" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Fecha" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Status" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 4 );

    DiferenciasInventarioLayout->addMultiCellWidget( table1, 1, 1, 0, 4 );

    table2 = new QTable( this, "table2" );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "#Proveedor" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Razon Social" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Producto" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Modelo" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Cantidad" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Exis" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Dif" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Elim" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Status" ) );
    table2->setNumRows( 0 );
    table2->setNumCols( 9 );

    DiferenciasInventarioLayout->addMultiCellWidget( table2, 2, 2, 0, 4 );

    pushButton1 = new QPushButton( this, "pushButton1" );

    DiferenciasInventarioLayout->addWidget( pushButton1, 3, 0 );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );

    DiferenciasInventarioLayout->addWidget( pushButton1_2, 3, 1 );

    pushButton1_2_2 = new QPushButton( this, "pushButton1_2_2" );

    DiferenciasInventarioLayout->addWidget( pushButton1_2_2, 3, 2 );

    pushButton1_2_2_2 = new QPushButton( this, "pushButton1_2_2_2" );

    DiferenciasInventarioLayout->addWidget( pushButton1_2_2_2, 3, 3 );

    pushButton1_2_2_2_2 = new QPushButton( this, "pushButton1_2_2_2_2" );

    DiferenciasInventarioLayout->addWidget( pushButton1_2_2_2_2, 3, 4 );
    languageChange();
    resize( QSize(681, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DiferenciasInventario::~DiferenciasInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DiferenciasInventario::languageChange()
{
    setCaption( tr( "Diferencias de inventario" ) );
    textLabel1->setText( tr( "Tienda" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Folio" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Responsable" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "Fecha" ) );
    table1->horizontalHeader()->setLabel( 3, tr( "Status" ) );
    table2->horizontalHeader()->setLabel( 0, tr( "#Proveedor" ) );
    table2->horizontalHeader()->setLabel( 1, tr( "Razon Social" ) );
    table2->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
    table2->horizontalHeader()->setLabel( 3, tr( "Modelo" ) );
    table2->horizontalHeader()->setLabel( 4, tr( "Cantidad" ) );
    table2->horizontalHeader()->setLabel( 5, tr( "Exis" ) );
    table2->horizontalHeader()->setLabel( 6, tr( "Dif" ) );
    table2->horizontalHeader()->setLabel( 7, tr( "Elim" ) );
    table2->horizontalHeader()->setLabel( 8, tr( "Status" ) );
    pushButton1->setText( tr( "Calcula Diferencias" ) );
    pushButton1_2->setText( tr( "Ver diferencias" ) );
    pushButton1_2_2->setText( tr( "Imprimir diferencias" ) );
    pushButton1_2_2_2->setText( tr( "Impresion Captura Inventario" ) );
    pushButton1_2_2_2_2->setText( tr( "Impresion de Sabana" ) );
}

