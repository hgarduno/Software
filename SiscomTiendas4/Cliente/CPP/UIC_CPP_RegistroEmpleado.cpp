/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroEmpleado.ui'
**
** Created: Fri Apr 12 21:36:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroEmpleado.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlPerfiles.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlPerfiles.h"

/*
 *  Constructs a RegistroEmpleado as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroEmpleado::RegistroEmpleado( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroEmpleado" );
    RegistroEmpleadoLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroEmpleadoLayout"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout10->addWidget( textLabel2 );

    QCtrPerfiles = new QCtrlPerfiles( this, "QCtrPerfiles" );
    layout10->addWidget( QCtrPerfiles );

    RegistroEmpleadoLayout->addLayout( layout10, 0, 0 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );

    RegistroEmpleadoLayout->addWidget( QPBRegistrar, 3, 0 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel3 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    QLENombre->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENombre->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( QLENombre );
    layout14->addLayout( layout11 );

    layout11_2 = new QVBoxLayout( 0, 0, 6, "layout11_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( textLabel3_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    QLEAPaterno->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEAPaterno->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( QLEAPaterno );
    layout14->addLayout( layout11_2 );

    layout11_2_2 = new QVBoxLayout( 0, 0, 6, "layout11_2_2"); 

    textLabel3_2_2 = new QLabel( this, "textLabel3_2_2" );
    textLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2_2->addWidget( textLabel3_2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    QLEAMaterno->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEAMaterno->sizePolicy().hasHeightForWidth() ) );
    layout11_2_2->addWidget( QLEAMaterno );
    layout14->addLayout( layout11_2_2 );
    layout19->addLayout( layout14 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout19->addItem( spacer1 );

    RegistroEmpleadoLayout->addLayout( layout19, 1, 0 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout11_3 = new QVBoxLayout( 0, 0, 6, "layout11_3"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    textLabel3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_3->sizePolicy().hasHeightForWidth() ) );
    layout11_3->addWidget( textLabel3_3 );

    QLEFirma = new QLineEdit( this, "QLEFirma" );
    QLEFirma->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFirma->sizePolicy().hasHeightForWidth() ) );
    layout11_3->addWidget( QLEFirma );
    layout18->addLayout( layout11_3 );

    layout11_3_2 = new QVBoxLayout( 0, 0, 6, "layout11_3_2"); 

    textLabel3_3_2 = new QLabel( this, "textLabel3_3_2" );
    textLabel3_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_3_2->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2->addWidget( textLabel3_3_2 );

    QLEPassword = new QLineEdit( this, "QLEPassword" );
    QLEPassword->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPassword->sizePolicy().hasHeightForWidth() ) );
    QLEPassword->setEchoMode( QLineEdit::Password );
    layout11_3_2->addWidget( QLEPassword );
    layout18->addLayout( layout11_3_2 );

    layout11_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout11_3_2_2"); 

    textLabel3_3_2_2 = new QLabel( this, "textLabel3_3_2_2" );
    textLabel3_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2_2->addWidget( textLabel3_3_2_2 );

    QLENPassword = new QLineEdit( this, "QLENPassword" );
    QLENPassword->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENPassword->sizePolicy().hasHeightForWidth() ) );
    QLENPassword->setEchoMode( QLineEdit::Password );
    layout11_3_2_2->addWidget( QLENPassword );
    layout18->addLayout( layout11_3_2_2 );
    layout20->addLayout( layout18 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout20->addItem( spacer2 );

    RegistroEmpleadoLayout->addLayout( layout20, 2, 0 );
    languageChange();
    resize( QSize(600, 310).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroEmpleado::~RegistroEmpleado()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroEmpleado::languageChange()
{
    setCaption( tr( "Registro De Empleado" ) );
    textLabel2->setText( tr( "Perfiles Disponibles" ) );
    QPBRegistrar->setText( tr( "Registrar Empleado" ) );
    textLabel3->setText( tr( "Nombre" ) );
    textLabel3_2->setText( tr( "Apellido Paterno" ) );
    textLabel3_2_2->setText( tr( "Apellido Materno" ) );
    textLabel3_3->setText( tr( "Firma" ) );
    textLabel3_3_2->setText( tr( "Password" ) );
    textLabel3_3_2_2->setText( tr( "Nuevamente El Password" ) );
}

