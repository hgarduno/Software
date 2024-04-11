/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaTelefono.ui'
**
** Created: Wed Apr 10 21:11:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaTelefono.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaTelefono as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaTelefono::CapturaTelefono( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaTelefono" );
    CapturaTelefonoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaTelefonoLayout"); 

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );

    CapturaTelefonoLayout->addWidget( QPBCancelar, 1, 1 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );

    CapturaTelefonoLayout->addWidget( QPBAceptar, 1, 0 );

    layout159 = new QVBoxLayout( 0, 0, 6, "layout159"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout159->addWidget( textLabel2 );

    QLETelefono = new QLineEdit( this, "QLETelefono" );
    QLETelefono->setMinimumSize( QSize( 150, 0 ) );
    QLETelefono->setMaximumSize( QSize( 150, 32767 ) );
    layout159->addWidget( QLETelefono );

    CapturaTelefonoLayout->addLayout( layout159, 0, 0 );

    layout159_2 = new QVBoxLayout( 0, 0, 6, "layout159_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout159_2->addWidget( textLabel2_2 );

    QLEDescripcion = new QLineEdit( this, "QLEDescripcion" );
    QLEDescripcion->setMinimumSize( QSize( 150, 0 ) );
    layout159_2->addWidget( QLEDescripcion );

    CapturaTelefonoLayout->addLayout( layout159_2, 0, 1 );
    languageChange();
    resize( QSize(410, 94).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaTelefono::~CapturaTelefono()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaTelefono::languageChange()
{
    setCaption( tr( "Form3" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    textLabel2->setText( tr( "Telefono" ) );
    textLabel2_2->setText( tr( "Descripcion" ) );
}

