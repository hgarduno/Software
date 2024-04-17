/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaDato.ui'
**
** Created: Fri Apr 12 21:25:29 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaDato.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDato as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDato::CapturaDato( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDato" );
    CapturaDatoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDatoLayout"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    QLEtiqueta = new QLabel( this, "QLEtiqueta" );
    QLEtiqueta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QLEtiqueta->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( QLEtiqueta );

    QLEDato = new QLineEdit( this, "QLEDato" );
    layout19->addWidget( QLEDato );

    CapturaDatoLayout->addLayout( layout19, 0, 0 );
    languageChange();
    resize( QSize(162, 63).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDato::~CapturaDato()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDato::languageChange()
{
    setCaption( tr( "Form2" ) );
    QLEtiqueta->setText( tr( "textLabel1" ) );
}

