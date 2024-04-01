/****************************************************************************
** Form implementation generated from reading ui file 'UI/ImprimeFactura.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ImprimeFactura.h"

#include <qvariant.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ImprimeFactura as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ImprimeFactura::ImprimeFactura( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ImprimeFactura" );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ImprimeFactura::~ImprimeFactura()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ImprimeFactura::languageChange()
{
    setCaption( tr( "Form1" ) );
}

