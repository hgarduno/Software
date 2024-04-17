/****************************************************************************
** Form implementation generated from reading ui file 'UI/SelExpendios.ui'
**
** Created: Fri Apr 12 21:25:49 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SelExpendios.h"

#include <qvariant.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a SelExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SelExpendios::SelExpendios( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SelExpendios" );
    SelExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "SelExpendiosLayout"); 

    QIVExpendios = new QIconView( this, "QIVExpendios" );

    SelExpendiosLayout->addWidget( QIVExpendios, 0, 0 );
    languageChange();
    resize( QSize(600, 435).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SelExpendios::~SelExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SelExpendios::languageChange()
{
    setCaption( tr( "Form1" ) );
}

