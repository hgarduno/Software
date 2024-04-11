/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaContacto.ui'
**
** Created: Wed Apr 10 21:11:55 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaContacto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaContacto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaContacto::CapturaContacto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaContacto" );
    CapturaContactoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaContactoLayout"); 

    layout50 = new QHBoxLayout( 0, 0, 6, "layout50"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout50->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout50->addWidget( QPBCancelar );

    CapturaContactoLayout->addLayout( layout50, 1, 0 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout6->addWidget( textLabel3 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    QLENombre->setMinimumSize( QSize( 150, 0 ) );
    QLENombre->setMaximumSize( QSize( 150, 32767 ) );
    layout6->addWidget( QLENombre );
    layout33->addLayout( layout6 );

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout6_2->addWidget( textLabel3_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    QLEAPaterno->setMinimumSize( QSize( 150, 0 ) );
    QLEAPaterno->setMaximumSize( QSize( 150, 32767 ) );
    layout6_2->addWidget( QLEAPaterno );
    layout33->addLayout( layout6_2 );

    layout6_3 = new QVBoxLayout( 0, 0, 6, "layout6_3"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    layout6_3->addWidget( textLabel3_3 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    QLEAMaterno->setMinimumSize( QSize( 150, 0 ) );
    QLEAMaterno->setMaximumSize( QSize( 150, 32767 ) );
    layout6_3->addWidget( QLEAMaterno );
    layout33->addLayout( layout6_3 );
    layout42->addLayout( layout33 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout41->addWidget( textLabel1 );

    QLEDescripcion = new QLineEdit( this, "QLEDescripcion" );
    layout41->addWidget( QLEDescripcion );
    layout42->addLayout( layout41 );

    CapturaContactoLayout->addLayout( layout42, 0, 0 );
    languageChange();
    resize( QSize(522, 144).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaContacto::~CapturaContacto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaContacto::languageChange()
{
    setCaption( tr( "Captura Contacto" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel3->setText( tr( "Nombre" ) );
    textLabel3_2->setText( tr( "Apellido Paterno" ) );
    textLabel3_3->setText( tr( "Apellido Materno" ) );
    textLabel1->setText( tr( "Descripcion" ) );
}

