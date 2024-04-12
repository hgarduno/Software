/****************************************************************************
** Form implementation generated from reading ui file 'UI/VendiendoOrden.ui'
**
** Created: Thu Apr 11 21:39:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_VendiendoOrden.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a VendiendoOrden as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
VendiendoOrden::VendiendoOrden( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "VendiendoOrden" );
    VendiendoOrdenLayout = new QGridLayout( this, 1, 1, 11, 6, "VendiendoOrdenLayout"); 

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( TRUE );
    layout8->addWidget( QPBImprimir );

    QPBVender = new QPushButton( this, "QPBVender" );
    QPBVender->setEnabled( TRUE );
    layout8->addWidget( QPBVender );

    VendiendoOrdenLayout->addLayout( layout8, 0, 0 );
    languageChange();
    resize( QSize(518, 50).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
VendiendoOrden::~VendiendoOrden()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void VendiendoOrden::languageChange()
{
    setCaption( tr( "Form1" ) );
    QPBImprimir->setText( trUtf8( "\x26\x49\x6d\x70\x72\x65\x73\x69\xc3\xb3\x6e\x20\x54\x69\x63\x6b\x65\x74" ) );
    QPBImprimir->setAccel( QKeySequence( tr( "Alt+I" ) ) );
    QPBVender->setText( tr( "Vender" ) );
}

