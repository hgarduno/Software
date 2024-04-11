/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProdSimilares.ui'
**
** Created: Wed Apr 10 21:10:21 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProdSimilares.h"

#include <qvariant.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ProdSimilares as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ProdSimilares::ProdSimilares( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ProdSimilares" );
    ProdSimilaresLayout = new QGridLayout( this, 1, 1, 11, 6, "ProdSimilaresLayout"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Familia" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 5 );
    QTDatos->setReadOnly( TRUE );

    ProdSimilaresLayout->addWidget( QTDatos, 0, 0 );
    languageChange();
    resize( QSize(819, 257).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProdSimilares::~ProdSimilares()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProdSimilares::languageChange()
{
    setCaption( tr( "Productos Similares" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Existencia" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Familia" ) );
}

