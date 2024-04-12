/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroRapidoAlumno.ui'
**
** Created: Thu Apr 11 21:39:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroRapidoAlumno.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlEscuelas.h"

/*
 *  Constructs a RegistroRapidoAlumno as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroRapidoAlumno::RegistroRapidoAlumno( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroRapidoAlumno" );
    RegistroRapidoAlumnoLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroRapidoAlumnoLayout"); 

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

    RegistroRapidoAlumnoLayout->addMultiCellLayout( layout12, 0, 0, 0, 2 );

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

    RegistroRapidoAlumnoLayout->addMultiCellLayout( layout37, 1, 1, 0, 2 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );

    RegistroRapidoAlumnoLayout->addMultiCellWidget( QPBRegistrar, 3, 3, 0, 2 );

    layout11_3 = new QVBoxLayout( 0, 0, 6, "layout11_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout11_3->addWidget( textLabel2_3 );

    QLECorreo = new QLineEdit( this, "QLECorreo" );
    QLECorreo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECorreo->sizePolicy().hasHeightForWidth() ) );
    layout11_3->addWidget( QLECorreo );

    RegistroRapidoAlumnoLayout->addLayout( layout11_3, 2, 0 );

    layout11_3_2 = new QVBoxLayout( 0, 0, 6, "layout11_3_2"); 

    textLabel2_3_2 = new QLabel( this, "textLabel2_3_2" );
    textLabel2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_2->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2->addWidget( textLabel2_3_2 );

    QLECelular = new QLineEdit( this, "QLECelular" );
    QLECelular->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECelular->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2->addWidget( QLECelular );

    RegistroRapidoAlumnoLayout->addLayout( layout11_3_2, 2, 1 );

    layout11_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout11_3_2_2"); 

    textLabel2_3_2_2 = new QLabel( this, "textLabel2_3_2_2" );
    textLabel2_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2_2->addWidget( textLabel2_3_2_2 );

    QLETCasa = new QLineEdit( this, "QLETCasa" );
    QLETCasa->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLETCasa->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2_2->addWidget( QLETCasa );

    RegistroRapidoAlumnoLayout->addLayout( layout11_3_2_2, 2, 2 );
    languageChange();
    resize( QSize(507, 206).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroRapidoAlumno::~RegistroRapidoAlumno()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroRapidoAlumno::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel3->setText( tr( "Nombre" ) );
    textLabel3_2->setText( tr( "Apellido Paterno" ) );
    textLabel3_2_2->setText( tr( "Apellido Materno" ) );
    textLabel1->setText( tr( "Escuela" ) );
    textLabel2->setText( tr( "Grupo" ) );
    textLabel2_2->setText( tr( "Boleta" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    textLabel2_3->setText( tr( "Correo Electronico" ) );
    textLabel2_3_2->setText( tr( "Celular" ) );
    textLabel2_3_2_2->setText( tr( "Casa" ) );
}

