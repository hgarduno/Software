/****************************************************************************
** Form implementation generated from reading ui file 'UI/ExpendiosSE.ui'
**
** Created: Thu Apr 11 21:39:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ExpendiosSE.h"

#include <qvariant.h>
#include <QCtrlExpendiosSE.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlExpendiosSE.h"

/*
 *  Constructs a ExpendiosSE as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ExpendiosSE::ExpendiosSE( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ExpendiosSE" );
    ExpendiosSELayout = new QGridLayout( this, 1, 1, 11, 6, "ExpendiosSELayout"); 

    ctrlExpendiosSE1 = new QCtrlExpendiosSE( this, "ctrlExpendiosSE1" );

    ExpendiosSELayout->addWidget( ctrlExpendiosSE1, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ExpendiosSE::~ExpendiosSE()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ExpendiosSE::languageChange()
{
    setCaption( tr( "Selecciona Expenido" ) );
}

