/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_Usuarios.ui'
**
** Created: Fri Apr 12 21:23:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Usuarios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Usuarios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Usuarios::Usuarios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Usuarios" );
    UsuariosLayout = new QGridLayout( this, 1, 1, 11, 6, "UsuariosLayout"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout33->addWidget( textLabel5 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout33->addWidget( QLENombre );
    layout36->addLayout( layout33 );

    layout33_2 = new QVBoxLayout( 0, 0, 6, "layout33_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    layout33_2->addWidget( textLabel5_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout33_2->addWidget( QLEAPaterno );
    layout36->addLayout( layout33_2 );

    layout33_2_2 = new QVBoxLayout( 0, 0, 6, "layout33_2_2"); 

    textLabel5_2_2 = new QLabel( this, "textLabel5_2_2" );
    layout33_2_2->addWidget( textLabel5_2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout33_2_2->addWidget( QLEAMaterno );
    layout36->addLayout( layout33_2_2 );

    UsuariosLayout->addLayout( layout36, 0, 0 );

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    QPBRUsuario = new QPushButton( this, "QPBRUsuario" );
    layout37->addWidget( QPBRUsuario );

    pushButton22_2 = new QPushButton( this, "pushButton22_2" );
    layout37->addWidget( pushButton22_2 );

    UsuariosLayout->addLayout( layout37, 1, 0 );

    pushButton24 = new QPushButton( this, "pushButton24" );

    UsuariosLayout->addWidget( pushButton24, 2, 0 );
    languageChange();
    resize( QSize(307, 225).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Usuarios::~Usuarios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Usuarios::languageChange()
{
    setCaption( tr( "Form3" ) );
    textLabel5->setText( tr( "Nombre" ) );
    textLabel5_2->setText( tr( "Apellido Paterno" ) );
    textLabel5_2_2->setText( tr( "Apellido Materno" ) );
    QPBRUsuario->setText( tr( "Registra Usuario" ) );
    pushButton22_2->setText( tr( "Consulta Usuario" ) );
    pushButton24->setText( tr( "Elimina Usuario" ) );
}

