/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroApartado.ui'
**
** Created: lun abr 1 18:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroApartado.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QCtrlFechaHora.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFechaHora.h"

/*
 *  Constructs a RegistroApartado as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RegistroApartado::RegistroApartado( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RegistroApartado" );
    setMinimumSize( QSize( 0, 0 ) );
    RegistroApartadoLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroApartadoLayout"); 

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout2->addWidget( QLENombre );
    layout5->addLayout( layout2 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( textLabel2_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout2_2->addWidget( QLEAPaterno );
    layout5->addLayout( layout2_2 );

    layout2_3 = new QVBoxLayout( 0, 0, 6, "layout2_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout2_3->addWidget( textLabel2_3 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout2_3->addWidget( QLEAMaterno );
    layout5->addLayout( layout2_3 );

    RegistroApartadoLayout->addLayout( layout5, 0, 0 );

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout2_4 = new QVBoxLayout( 0, 0, 6, "layout2_4"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout2_4->addWidget( textLabel2_4 );

    QLECelular = new QLineEdit( this, "QLECelular" );
    layout2_4->addWidget( QLECelular );
    layout10->addLayout( layout2_4 );

    layout2_4_2 = new QVBoxLayout( 0, 0, 6, "layout2_4_2"); 

    textLabel2_4_2 = new QLabel( this, "textLabel2_4_2" );
    textLabel2_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4_2->sizePolicy().hasHeightForWidth() ) );
    layout2_4_2->addWidget( textLabel2_4_2 );

    QLEReCelular = new QLineEdit( this, "QLEReCelular" );
    layout2_4_2->addWidget( QLEReCelular );
    layout10->addLayout( layout2_4_2 );
    layout35->addLayout( layout10 );

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    layout2_4_3 = new QVBoxLayout( 0, 0, 6, "layout2_4_3"); 

    textLabel2_4_3 = new QLabel( this, "textLabel2_4_3" );
    textLabel2_4_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4_3->sizePolicy().hasHeightForWidth() ) );
    layout2_4_3->addWidget( textLabel2_4_3 );

    QLECorreo = new QLineEdit( this, "QLECorreo" );
    layout2_4_3->addWidget( QLECorreo );
    layout11->addLayout( layout2_4_3 );

    layout2_4_3_2 = new QVBoxLayout( 0, 0, 6, "layout2_4_3_2"); 

    textLabel2_4_3_2 = new QLabel( this, "textLabel2_4_3_2" );
    textLabel2_4_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4_3_2->sizePolicy().hasHeightForWidth() ) );
    layout2_4_3_2->addWidget( textLabel2_4_3_2 );

    QLEReCorreo = new QLineEdit( this, "QLEReCorreo" );
    layout2_4_3_2->addWidget( QLEReCorreo );
    layout11->addLayout( layout2_4_3_2 );
    layout35->addLayout( layout11 );

    RegistroApartadoLayout->addLayout( layout35, 1, 0 );

    layout44 = new QHBoxLayout( 0, 0, 6, "layout44"); 

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    textLabel2_5 = new QLabel( this, "textLabel2_5" );
    layout43->addWidget( textLabel2_5 );

    QLEACuenta = new QLineEdit( this, "QLEACuenta" );
    layout43->addWidget( QLEACuenta );
    layout44->addLayout( layout43 );

    layout41_2 = new QVBoxLayout( 0, 0, 6, "layout41_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout41_2->addWidget( textLabel3_2 );

    QCtrFechaEntrega = new QCtrlFechaHora( this, "QCtrFechaEntrega" );
    QCtrFechaEntrega->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaEntrega->sizePolicy().hasHeightForWidth() ) );
    layout41_2->addWidget( QCtrFechaEntrega );
    layout44->addLayout( layout41_2 );

    RegistroApartadoLayout->addLayout( layout44, 2, 0 );

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout36->addWidget( textLabel1 );

    QTEObservaciones = new QTextEdit( this, "QTEObservaciones" );
    layout36->addWidget( QTEObservaciones );

    RegistroApartadoLayout->addLayout( layout36, 3, 0 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    QPBRegistraPersonales = new QPushButton( this, "QPBRegistraPersonales" );
    QPBRegistraPersonales->setAutoDefault( FALSE );
    layout18->addWidget( QPBRegistraPersonales );

    QPBRegistraCelular = new QPushButton( this, "QPBRegistraCelular" );
    QPBRegistraCelular->setEnabled( FALSE );
    QPBRegistraCelular->setAutoDefault( FALSE );
    layout18->addWidget( QPBRegistraCelular );

    QPBRegistraCorreo = new QPushButton( this, "QPBRegistraCorreo" );
    QPBRegistraCorreo->setEnabled( FALSE );
    QPBRegistraCorreo->setAutoDefault( FALSE );
    layout18->addWidget( QPBRegistraCorreo );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout18->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout18->addWidget( QPBCancelar );

    RegistroApartadoLayout->addLayout( layout18, 4, 0 );
    languageChange();
    resize( QSize(756, 298).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroApartado::~RegistroApartado()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroApartado::languageChange()
{
    setCaption( tr( "Registro de Apartado" ) );
    textLabel2->setText( tr( "Nombre" ) );
    textLabel2_2->setText( tr( "Apellido Paterno" ) );
    textLabel2_3->setText( tr( "Apellido Materno" ) );
    textLabel2_4->setText( tr( "Celular" ) );
    textLabel2_4_2->setText( tr( "Re Celular" ) );
    textLabel2_4_3->setText( tr( "Correo Electronico" ) );
    textLabel2_4_3_2->setText( tr( "Re Correo Electronico" ) );
    textLabel2_5->setText( tr( "A Cuenta" ) );
    textLabel3_2->setText( tr( "Hora de Entrega" ) );
    textLabel1->setText( tr( "Observaciones" ) );
    QPBRegistraPersonales->setText( tr( "Registra Datos Personales" ) );
    QPBRegistraCelular->setText( tr( "Registra Celular" ) );
    QPBRegistraCorreo->setText( tr( "Registra Correo" ) );
    QPBAceptar->setText( tr( "&Aceptar" ) );
    QPBAceptar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

