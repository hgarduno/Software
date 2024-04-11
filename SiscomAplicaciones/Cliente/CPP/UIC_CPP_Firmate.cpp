/****************************************************************************
** Form implementation generated from reading ui file 'UI/Firmate.ui'
**
** Created: Sat Jan 27 17:40:28 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Firmate.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Firmate as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Firmate::Firmate( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "Firmate" );
    FirmateLayout = new QGridLayout( this, 1, 1, 11, 6, "FirmateLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QLEFirma = new QLineEdit( this, "QLEFirma" );
    QLEFirma->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFirma->sizePolicy().hasHeightForWidth() ) );
    QLEFirma->setReadOnly( TRUE );
    layout1->addWidget( QLEFirma );
    layout4->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( textLabel1_2 );

    QLEPassword = new QLineEdit( this, "QLEPassword" );
    QLEPassword->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEPassword->sizePolicy().hasHeightForWidth() ) );
    QLEPassword->setEchoMode( QLineEdit::Password );
    layout1_2->addWidget( QLEPassword );
    layout4->addLayout( layout1_2 );

    FirmateLayout->addLayout( layout4, 0, 0 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout3->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout3->addWidget( QPBCancelar );

    FirmateLayout->addLayout( layout3, 1, 0 );
    languageChange();
    resize( QSize(471, 99).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Firmate::~Firmate()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Firmate::languageChange()
{
    setCaption( tr( "Acceso Al Sistema" ) );
    textLabel1->setText( tr( "Usuario" ) );
    textLabel1_2->setText( tr( "Password" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

