/****************************************************************************
** Form implementation generated from reading ui file 'UI/Caja2.ui'
**
** Created: Fri Apr 12 21:26:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Caja2.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a Caja2 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Caja2::Caja2( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Caja2" );
    Caja2Layout = new QGridLayout( this, 1, 1, 11, 6, "Caja2Layout"); 

    QPBOrdenesPendientes = new QPushButton( this, "QPBOrdenesPendientes" );

    Caja2Layout->addWidget( QPBOrdenesPendientes, 1, 0 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "1" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "2" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "3" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 3 );

    Caja2Layout->addWidget( table1, 0, 0 );
    languageChange();
    resize( QSize(782, 632).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Caja2::~Caja2()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Caja2::languageChange()
{
    setCaption( tr( "Caja Version 2" ) );
    QPBOrdenesPendientes->setText( tr( "Ordenes Pendientes" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "1" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "2" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "3" ) );
}

