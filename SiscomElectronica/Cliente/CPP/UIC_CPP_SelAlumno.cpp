/****************************************************************************
** Form implementation generated from reading ui file 'UI/SelAlumno.ui'
**
** Created: Fri Apr 12 21:26:00 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SelAlumno.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlEscuelas.h"

/*
 *  Constructs a SelAlumno as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SelAlumno::SelAlumno( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SelAlumno" );
    SelAlumnoLayout = new QGridLayout( this, 1, 1, 11, 6, "SelAlumnoLayout"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCBAlumnos = new QComboBox( FALSE, this, "QCBAlumnos" );
    QCBAlumnos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCBAlumnos->sizePolicy().hasHeightForWidth() ) );
    QCBAlumnos->setEditable( TRUE );
    QCBAlumnos->setAutoCompletion( TRUE );
    QCBAlumnos->setDuplicatesEnabled( FALSE );
    layout1->addWidget( QCBAlumnos );
    layout12->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QCBEscuelas = new QCtrlEscuelas( this, "QCBEscuelas" );
    QCBEscuelas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCBEscuelas->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCBEscuelas );
    layout12->addLayout( layout2 );
    spacer1 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout12->addItem( spacer1 );
    layout13->addLayout( layout12 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout9->addWidget( textLabel4 );

    QTEAlumno = new QTextEdit( this, "QTEAlumno" );
    layout9->addWidget( QTEAlumno );
    layout13->addLayout( layout9 );

    SelAlumnoLayout->addLayout( layout13, 0, 0 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout8->addWidget( QPBAceptar );

    QPBRegistrarA = new QPushButton( this, "QPBRegistrarA" );
    QPBRegistrarA->setAutoDefault( FALSE );
    layout8->addWidget( QPBRegistrarA );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout8->addWidget( QPBCancelar );

    QPBCancelarRegRap = new QPushButton( this, "QPBCancelarRegRap" );
    QPBCancelarRegRap->setAutoDefault( FALSE );
    layout8->addWidget( QPBCancelarRegRap );

    SelAlumnoLayout->addLayout( layout8, 1, 0 );
    languageChange();
    resize( QSize(507, 188).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SelAlumno::~SelAlumno()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SelAlumno::languageChange()
{
    setCaption( tr( "Selecciona Alumno" ) );
    textLabel1->setText( tr( "Alumnos" ) );
    textLabel2->setText( tr( "Escuelas" ) );
    textLabel4->setText( tr( "Alumno" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBRegistrarA->setText( tr( "Registrar Alumno" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBCancelarRegRap->setText( tr( "Cancelar Reg Rapido" ) );
}

