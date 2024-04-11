/****************************************************************************
** Form implementation generated from reading ui file 'UI/ImprimeReporteSemestral.ui'
**
** Created: Wed Apr 10 20:52:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ImprimeReporteSemestral.h"

#include <qvariant.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ImprimeReporteSemestral as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ImprimeReporteSemestral::ImprimeReporteSemestral( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ImprimeReporteSemestral" );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ImprimeReporteSemestral::~ImprimeReporteSemestral()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ImprimeReporteSemestral::languageChange()
{
    setCaption( tr( "Form1" ) );
}

