/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaIva.ui'
**
** Created: Wed Apr 10 21:10:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaIva.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaIva as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaIva::CapturaIva( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaIva" );
    CapturaIvaLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaIvaLayout"); 

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    QPBMasIva = new QPushButton( this, "QPBMasIva" );
    QPBMasIva->setMinimumSize( QSize( 0, 50 ) );
    QPBMasIva->setAutoDefault( FALSE );
    layout22->addWidget( QPBMasIva );

    QPBConIva = new QPushButton( this, "QPBConIva" );
    QPBConIva->setMinimumSize( QSize( 0, 50 ) );
    QPBConIva->setAutoDefault( FALSE );
    layout22->addWidget( QPBConIva );

    CapturaIvaLayout->addLayout( layout22, 0, 0 );
    languageChange();
    resize( QSize(185, 74).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaIva::~CapturaIva()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaIva::languageChange()
{
    setCaption( tr( "Captura IVA" ) );
    QPBMasIva->setText( tr( "Mas IVA" ) );
    QPBConIva->setText( tr( "Con IVA" ) );
}

