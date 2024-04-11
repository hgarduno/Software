/****************************************************************************
** Form implementation generated from reading ui file 'UI/ExtNoAlcanzan.ui'
**
** Created: Wed Apr 10 21:10:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ExtNoAlcanzan.h"

#include <qvariant.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ExtNoAlcanzan as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ExtNoAlcanzan::ExtNoAlcanzan( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ExtNoAlcanzan" );
    ExtNoAlcanzanLayout = new QGridLayout( this, 1, 1, 11, 6, "ExtNoAlcanzanLayout"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );

    ExtNoAlcanzanLayout->addWidget( QTDatos, 0, 0 );
    languageChange();
    resize( QSize(477, 390).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ExtNoAlcanzan::~ExtNoAlcanzan()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ExtNoAlcanzan::languageChange()
{
    setCaption( tr( "Form1" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Existencia" ) );
}

