/****************************************************************************
** Form implementation generated from reading ui file 'UI/CQControlFecha2.ui'
**
** Created: Wed May 31 17:48:48 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include <IMP_QControlFecha2.h>

#include <qvariant.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CQControlFecha2 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CQControlFecha2::CQControlFecha2( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CQControlFecha2" );
    setEnabled( TRUE );
    CQControlFecha2Layout = new QGridLayout( this, 1, 1, 11, 6, "CQControlFecha2Layout"); 

    QLEAno = new QLineEdit( this, "QLEAno" );
    QLEAno->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLEAno->sizePolicy().hasHeightForWidth() ) );
    QLEAno->setMinimumSize( QSize( 40, 0 ) );
    QLEAno->setMaximumSize( QSize( 40, 32767 ) );
    QLEAno->setEchoMode( QLineEdit::Normal );

    CQControlFecha2Layout->addWidget( QLEAno, 0, 0 );

    QLEDia = new QLineEdit( this, "QLEDia" );
    QLEDia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLEDia->sizePolicy().hasHeightForWidth() ) );
    QLEDia->setMinimumSize( QSize( 20, 0 ) );
    QLEDia->setMaximumSize( QSize( 20, 32767 ) );

    CQControlFecha2Layout->addWidget( QLEDia, 0, 1 );

    QLEMes = new QLineEdit( this, "QLEMes" );
    QLEMes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLEMes->sizePolicy().hasHeightForWidth() ) );
    QLEMes->setMinimumSize( QSize( 20, 0 ) );
    QLEMes->setMaximumSize( QSize( 20, 32767 ) );

    CQControlFecha2Layout->addWidget( QLEMes, 0, 2 );
    languageChange();
    resize( QSize(124, 42).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CQControlFecha2::~CQControlFecha2()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CQControlFecha2::languageChange()
{
    setCaption( tr( "Control Fecha" ) );
}

