/****************************************************************************
** Form implementation generated from reading ui file 'UI/SincronizaProductos.ui'
**
** Created: Wed Apr 10 20:52:38 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SincronizaProductos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a SincronizaProductos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SincronizaProductos::SincronizaProductos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SincronizaProductos" );
    SincronizaProductosLayout = new QGridLayout( this, 1, 1, 11, 6, "SincronizaProductosLayout"); 

    pushButton1 = new QPushButton( this, "pushButton1" );

    SincronizaProductosLayout->addWidget( pushButton1, 2, 0 );

    textLabel1 = new QLabel( this, "textLabel1" );

    SincronizaProductosLayout->addWidget( textLabel1, 0, 0 );

    table1 = new QTable( this, "table1" );
    table1->setNumRows( 3 );
    table1->setNumCols( 3 );

    SincronizaProductosLayout->addWidget( table1, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SincronizaProductos::~SincronizaProductos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SincronizaProductos::languageChange()
{
    setCaption( tr( "Form1" ) );
    pushButton1->setText( tr( "Sincroniza Productos \n"
"Siscom Expendios" ) );
    textLabel1->setText( tr( "textLabel1" ) );
}

