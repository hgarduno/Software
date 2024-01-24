/****************************************************************************
** Form implementation generated from reading ui file 'UI/EstadoInventario.ui'
**
** Created: Thu Dec 21 13:56:53 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_EstadoInventario.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a EstadoInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EstadoInventario::EstadoInventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "EstadoInventario" );
    EstadoInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "EstadoInventarioLayout"); 

    textLabel4 = new QLabel( this, "textLabel4" );

    EstadoInventarioLayout->addWidget( textLabel4, 0, 0 );

    table6 = new QTable( this, "table6" );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Producto" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Descripcion" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Inventario" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Existencia" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Ventas" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Costo Unitario" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Importe Diferencia" ) );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Empleado" ) );
    table6->setNumRows( 0 );
    table6->setNumCols( 8 );

    EstadoInventarioLayout->addWidget( table6, 1, 0 );
    languageChange();
    resize( QSize(710, 479).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EstadoInventario::~EstadoInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EstadoInventario::languageChange()
{
    setCaption( tr( "Estado Del Inentario" ) );
    textLabel4->setText( tr( "Estado Inventario" ) );
    table6->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    table6->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    table6->horizontalHeader()->setLabel( 2, tr( "Inventario" ) );
    table6->horizontalHeader()->setLabel( 3, tr( "Existencia" ) );
    table6->horizontalHeader()->setLabel( 4, tr( "Ventas" ) );
    table6->horizontalHeader()->setLabel( 5, tr( "Costo Unitario" ) );
    table6->horizontalHeader()->setLabel( 6, tr( "Importe Diferencia" ) );
    table6->horizontalHeader()->setLabel( 7, tr( "Empleado" ) );
}

