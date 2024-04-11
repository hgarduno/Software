/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RegistroUsuarios.ui'
**
** Created: Thu Apr 11 21:07:45 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RegistroUsuarios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlPerfilesSS.h"

/*
 *  Constructs a RegistroUsuarios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroUsuarios::RegistroUsuarios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroUsuarios" );
    RegistroUsuariosLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroUsuariosLayout"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    layout74 = new QHBoxLayout( 0, 0, 6, "layout74"); 

    layout73 = new QHBoxLayout( 0, 0, 6, "layout73"); 

    layout64 = new QVBoxLayout( 0, 0, 6, "layout64"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout64->addWidget( textLabel1 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout64->addWidget( QLENombre );
    layout73->addLayout( layout64 );

    layout72 = new QVBoxLayout( 0, 0, 6, "layout72"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout72->addWidget( textLabel1_2 );

    QLEApellidoPaterno = new QLineEdit( this, "QLEApellidoPaterno" );
    layout72->addWidget( QLEApellidoPaterno );
    layout73->addLayout( layout72 );
    layout74->addLayout( layout73 );

    layout66 = new QVBoxLayout( 0, 0, 6, "layout66"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout66->addWidget( textLabel1_2_2 );

    QLEApellidoMaterno = new QLineEdit( this, "QLEApellidoMaterno" );
    layout66->addWidget( QLEApellidoMaterno );
    layout74->addLayout( layout66 );
    layout17->addLayout( layout74 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout11->addWidget( textLabel2 );

    QCtrPerfiles = new QCtrlPerfilesSS( this, "QCtrPerfiles" );
    layout11->addWidget( QCtrPerfiles );
    layout16->addLayout( layout11 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel3_2_2 = new QLabel( this, "textLabel3_2_2" );
    layout13->addWidget( textLabel3_2_2 );

    QLEFirma = new QLineEdit( this, "QLEFirma" );
    QLEFirma->setEchoMode( QLineEdit::Normal );
    layout13->addWidget( QLEFirma );
    layout16->addLayout( layout13 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout14->addWidget( textLabel3 );

    QLEContrasena = new QLineEdit( this, "QLEContrasena" );
    QLEContrasena->setEchoMode( QLineEdit::Password );
    layout14->addWidget( QLEContrasena );
    layout16->addLayout( layout14 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout15->addWidget( textLabel3_2 );

    QLERepetirContrasena = new QLineEdit( this, "QLERepetirContrasena" );
    QLERepetirContrasena->setEchoMode( QLineEdit::Password );
    layout15->addWidget( QLERepetirContrasena );
    layout16->addLayout( layout15 );
    layout17->addLayout( layout16 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    layout17->addWidget( QPBRegistrar );

    RegistroUsuariosLayout->addLayout( layout17, 0, 0 );
    languageChange();
    resize( QSize(529, 191).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroUsuarios::~RegistroUsuarios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroUsuarios::languageChange()
{
    setCaption( tr( "Registro" ) );
    textLabel1->setText( tr( "Nombre:" ) );
    textLabel1_2->setText( tr( "Apellido Paterno:" ) );
    textLabel1_2_2->setText( tr( "Apellido Materno:" ) );
    textLabel2->setText( tr( "Tipo de Usuario" ) );
    textLabel3_2_2->setText( tr( "Firma" ) );
    textLabel3->setText( trUtf8( "\x43\x6f\x6e\x74\x72\x61\x73\x65\xc3\xb1\x61" ) );
    textLabel3_2->setText( trUtf8( "\x52\x65\x70\x65\x74\x69\x72\x20\x43\x6f\x6e\x74\x72\x61\x73\x65\xc3\xb1\x61" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
}

