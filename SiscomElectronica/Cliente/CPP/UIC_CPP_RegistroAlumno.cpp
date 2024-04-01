/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroAlumno.ui'
**
** Created: Wed Jan 31 10:48:09 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroAlumno.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlEscuelas.h"

/*
 *  Constructs a RegistroAlumno as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroAlumno::RegistroAlumno( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroAlumno" );
    RegistroAlumnoLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroAlumnoLayout"); 

    layout63 = new QHBoxLayout( 0, 0, 6, "layout63"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout63->addWidget( QPBRegistrar );

    pushButton6_2 = new QPushButton( this, "pushButton6_2" );
    layout63->addWidget( pushButton6_2 );

    RegistroAlumnoLayout->addLayout( layout63, 4, 0 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel3 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout5->addWidget( QLENombre );
    layout12->addLayout( layout5 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2->addWidget( textLabel3_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout5_2->addWidget( QLEAPaterno );
    layout12->addLayout( layout5_2 );

    layout5_2_2 = new QVBoxLayout( 0, 0, 6, "layout5_2_2"); 

    textLabel3_2_2 = new QLabel( this, "textLabel3_2_2" );
    textLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2_2->addWidget( textLabel3_2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout5_2_2->addWidget( QLEAMaterno );
    layout12->addLayout( layout5_2_2 );

    RegistroAlumnoLayout->addLayout( layout12, 0, 0 );

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel1 );

    QCtrEscuelas = new QCtrlEscuelas( this, "QCtrEscuelas" );
    QCtrEscuelas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)5, 0, 0, QCtrEscuelas->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( QCtrEscuelas );
    layout37->addLayout( layout10 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel2 );

    QLEGrupo = new QLineEdit( this, "QLEGrupo" );
    QLEGrupo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEGrupo->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( QLEGrupo );
    layout37->addLayout( layout11 );

    layout11_2 = new QVBoxLayout( 0, 0, 6, "layout11_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( textLabel2_2 );

    QLEBoleta = new QLineEdit( this, "QLEBoleta" );
    QLEBoleta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEBoleta->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( QLEBoleta );
    layout37->addLayout( layout11_2 );

    RegistroAlumnoLayout->addLayout( layout37, 1, 0 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout11_3 = new QVBoxLayout( 0, 0, 6, "layout11_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout11_3->addWidget( textLabel2_3 );

    QLECorreo = new QLineEdit( this, "QLECorreo" );
    QLECorreo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECorreo->sizePolicy().hasHeightForWidth() ) );
    QLECorreo->setAcceptDrops( FALSE );
    QLECorreo->setDragEnabled( FALSE );
    layout11_3->addWidget( QLECorreo );
    layout17->addLayout( layout11_3 );

    layout11_3_3 = new QVBoxLayout( 0, 0, 6, "layout11_3_3"); 

    textLabel2_3_3 = new QLabel( this, "textLabel2_3_3" );
    textLabel2_3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_3->sizePolicy().hasHeightForWidth() ) );
    layout11_3_3->addWidget( textLabel2_3_3 );

    QLEReCorreo = new QLineEdit( this, "QLEReCorreo" );
    QLEReCorreo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEReCorreo->sizePolicy().hasHeightForWidth() ) );
    QLEReCorreo->setAcceptDrops( FALSE );
    QLEReCorreo->setEchoMode( QLineEdit::Password );
    layout11_3_3->addWidget( QLEReCorreo );
    layout17->addLayout( layout11_3_3 );

    layout11_3_2 = new QVBoxLayout( 0, 0, 6, "layout11_3_2"); 

    textLabel2_3_2 = new QLabel( this, "textLabel2_3_2" );
    textLabel2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_2->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2->addWidget( textLabel2_3_2 );

    QLECelular = new QLineEdit( this, "QLECelular" );
    QLECelular->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECelular->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2->addWidget( QLECelular );
    layout17->addLayout( layout11_3_2 );

    layout11_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout11_3_2_2"); 

    textLabel2_3_2_2 = new QLabel( this, "textLabel2_3_2_2" );
    textLabel2_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2_2->addWidget( textLabel2_3_2_2 );

    QLETCasa = new QLineEdit( this, "QLETCasa" );
    QLETCasa->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLETCasa->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2_2->addWidget( QLETCasa );
    layout17->addLayout( layout11_3_2_2 );

    RegistroAlumnoLayout->addLayout( layout17, 2, 0 );

    layout30 = new QVBoxLayout( 0, 0, 6, "layout30"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout30->addWidget( textLabel1_2 );

    QLENoCredencial = new QLineEdit( this, "QLENoCredencial" );
    layout30->addWidget( QLENoCredencial );

    RegistroAlumnoLayout->addLayout( layout30, 3, 0 );
    languageChange();
    resize( QSize(803, 279).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroAlumno::~RegistroAlumno()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroAlumno::languageChange()
{
    setCaption( tr( "Registro Alumno" ) );
    QPBRegistrar->setText( tr( "Registra Alumno" ) );
    pushButton6_2->setText( tr( "pushButton6" ) );
    textLabel3->setText( tr( "Nombre" ) );
    textLabel3_2->setText( tr( "Apellido Paterno" ) );
    textLabel3_2_2->setText( tr( "Apellido Materno" ) );
    textLabel1->setText( tr( "Escuela" ) );
    textLabel2->setText( tr( "Grupo" ) );
    textLabel2_2->setText( tr( "Boleta" ) );
    textLabel2_3->setText( tr( "Correo Electronico" ) );
    textLabel2_3_3->setText( tr( "Re Captura Correo Electronico" ) );
    textLabel2_3_2->setText( tr( "Celular" ) );
    textLabel2_3_2_2->setText( tr( "Casa" ) );
    textLabel1_2->setText( tr( "Numero De Credencial" ) );
}

