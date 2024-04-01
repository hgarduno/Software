/****************************************************************************
** Form implementation generated from reading ui file 'UI/EjecutaInventario.ui'
**
** Created: Wed Jan 31 10:59:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_EjecutaInventario.h"

#include <qvariant.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a EjecutaInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EjecutaInventario::EjecutaInventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "EjecutaInventario" );
    EjecutaInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "EjecutaInventarioLayout"); 

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Producto" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Cantidad" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Estado Registro" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 3 );

    EjecutaInventarioLayout->addWidget( table1, 0, 0 );

    pushButton1 = new QPushButton( this, "pushButton1" );

    EjecutaInventarioLayout->addWidget( pushButton1, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EjecutaInventario::~EjecutaInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EjecutaInventario::languageChange()
{
    setCaption( tr( "Ejecucion Del Inventario" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "Estado Registro" ) );
    pushButton1->setText( tr( "Registrar Inventario" ) );
}

