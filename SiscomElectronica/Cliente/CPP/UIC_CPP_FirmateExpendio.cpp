/****************************************************************************
** Form implementation generated from reading ui file 'UI/FirmateExpendio.ui'
**
** Created: Fri Apr 12 21:34:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_FirmateExpendio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a FirmateExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FirmateExpendio::FirmateExpendio( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "FirmateExpendio" );
    FirmateExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "FirmateExpendioLayout"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout23->addWidget( textLabel2 );

    QLEFirma = new QLineEdit( this, "QLEFirma" );
    QLEFirma->setReadOnly( TRUE );
    layout23->addWidget( QLEFirma );

    FirmateExpendioLayout->addLayout( layout23, 0, 0 );

    layout23_2 = new QVBoxLayout( 0, 0, 6, "layout23_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout23_2->addWidget( textLabel2_2 );

    QLEPassword = new QLineEdit( this, "QLEPassword" );
    QLEPassword->setEchoMode( QLineEdit::Password );
    layout23_2->addWidget( QLEPassword );

    FirmateExpendioLayout->addLayout( layout23_2, 1, 0 );
    languageChange();
    resize( QSize(274, 126).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FirmateExpendio::~FirmateExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FirmateExpendio::languageChange()
{
    setCaption( tr( "Introduce El Password" ) );
    textLabel2->setText( tr( "Usuario" ) );
    textLabel2_2->setText( tr( "Password" ) );
}

