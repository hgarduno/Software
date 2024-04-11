/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/AccesoServiSNTE.ui'
**
** Created: Sat Jan 27 16:41:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "AccesoServiSNTE.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a AccesoServiSNTE as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AccesoServiSNTE::AccesoServiSNTE( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "AccesoServiSNTE" );
    AccesoServiSNTELayout = new QGridLayout( this, 1, 1, 11, 6, "AccesoServiSNTELayout"); 

    layout59 = new QVBoxLayout( 0, 0, 6, "layout59"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout59->addWidget( textLabel2 );

    QLEUsuario = new QLineEdit( this, "QLEUsuario" );
    layout59->addWidget( QLEUsuario );

    AccesoServiSNTELayout->addLayout( layout59, 0, 0 );

    layout60 = new QVBoxLayout( 0, 0, 6, "layout60"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout60->addWidget( textLabel3 );

    QLEPassword = new QLineEdit( this, "QLEPassword" );
    QLEPassword->setEchoMode( QLineEdit::Password );
    layout60->addWidget( QLEPassword );

    AccesoServiSNTELayout->addLayout( layout60, 1, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout4->addWidget( QPBAceptar );

    QPBTipoLetra = new QPushButton( this, "QPBTipoLetra" );
    QPBTipoLetra->setEnabled( FALSE );
    QPBTipoLetra->setAutoDefault( FALSE );
    layout4->addWidget( QPBTipoLetra );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout4->addWidget( QPBCancelar );

    AccesoServiSNTELayout->addLayout( layout4, 2, 0 );
    languageChange();
    resize( QSize(388, 141).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AccesoServiSNTE::~AccesoServiSNTE()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AccesoServiSNTE::languageChange()
{
    setCaption( tr( "Acceso ServiSNTE" ) );
    textLabel2->setText( tr( "Usuario" ) );
    textLabel3->setText( tr( "Password" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBTipoLetra->setText( tr( "Tipo Letra" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

