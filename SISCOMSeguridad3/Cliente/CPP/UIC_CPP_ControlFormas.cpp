/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_ControlFormas.ui'
**
** Created: Thu Apr 11 21:35:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ControlFormas.h"

#include <qvariant.h>
#include <qheader.h>
#include <qlistview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ControlFormas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ControlFormas::ControlFormas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ControlFormas" );
    ControlFormasLayout = new QGridLayout( this, 1, 1, 11, 6, "ControlFormasLayout"); 

    QLVLista = new QListView( this, "QLVLista" );
    QLVLista->addColumn( tr( "Column 1" ) );
    QLVLista->setSelectionMode( QListView::Single );
    QLVLista->setRootIsDecorated( TRUE );

    ControlFormasLayout->addWidget( QLVLista, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ControlFormas::~ControlFormas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ControlFormas::languageChange()
{
    setCaption( tr( "Controlador De Formas" ) );
    QLVLista->header()->setLabel( 0, tr( "Column 1" ) );
}

