/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaDatosAlumno.ui'
**
** Created: Thu Dec 21 12:53:42 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaDatosAlumno.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlAlumnos.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlAlumnos.h"
#include "QCtrlEscuelas.h"

/*
 *  Constructs a ActualizaDatosAlumno as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActualizaDatosAlumno::ActualizaDatosAlumno( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActualizaDatosAlumno" );
    ActualizaDatosAlumnoLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaDatosAlumnoLayout"); 
    ActualizaDatosAlumnoLayout->setResizeMode( QLayout::Minimum );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrAlumnos = new QCtrlAlumnos( this, "QCtrAlumnos" );
    layout1->addWidget( QCtrAlumnos );
    layout17->addLayout( layout1 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout2->addWidget( QLENombre );
    layout8->addLayout( layout2 );

    layout2_3 = new QVBoxLayout( 0, 0, 6, "layout2_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    layout2_3->addWidget( textLabel2_3 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout2_3->addWidget( QLEAPaterno );
    layout8->addLayout( layout2_3 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout2_2->addWidget( textLabel2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout2_2->addWidget( QLEAMaterno );
    layout8->addLayout( layout2_2 );
    layout17->addLayout( layout8 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout9->addWidget( textLabel3 );

    QCtrEscuelas = new QCtrlEscuelas( this, "QCtrEscuelas" );
    QCtrEscuelas->setEnabled( FALSE );
    QCtrEscuelas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrEscuelas->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( QCtrEscuelas );
    layout16->addLayout( layout9 );

    layout2_4 = new QVBoxLayout( 0, 0, 6, "layout2_4"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    layout2_4->addWidget( textLabel2_4 );

    QLEGrupo = new QLineEdit( this, "QLEGrupo" );
    layout2_4->addWidget( QLEGrupo );
    layout16->addLayout( layout2_4 );

    layout2_5 = new QVBoxLayout( 0, 0, 6, "layout2_5"); 

    textLabel2_5 = new QLabel( this, "textLabel2_5" );
    layout2_5->addWidget( textLabel2_5 );

    QLEBoleta = new QLineEdit( this, "QLEBoleta" );
    layout2_5->addWidget( QLEBoleta );
    layout16->addLayout( layout2_5 );
    layout17->addLayout( layout16 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout2_4_4 = new QVBoxLayout( 0, 0, 6, "layout2_4_4"); 

    textLabel2_4_4 = new QLabel( this, "textLabel2_4_4" );
    layout2_4_4->addWidget( textLabel2_4_4 );

    QLECorreoE = new QLineEdit( this, "QLECorreoE" );
    layout2_4_4->addWidget( QLECorreoE );
    layout15->addLayout( layout2_4_4 );

    layout2_4_3 = new QVBoxLayout( 0, 0, 6, "layout2_4_3"); 

    textLabel2_4_3 = new QLabel( this, "textLabel2_4_3" );
    layout2_4_3->addWidget( textLabel2_4_3 );

    QLECelular = new QLineEdit( this, "QLECelular" );
    layout2_4_3->addWidget( QLECelular );
    layout15->addLayout( layout2_4_3 );

    layout2_4_2 = new QVBoxLayout( 0, 0, 6, "layout2_4_2"); 

    textLabel2_4_2 = new QLabel( this, "textLabel2_4_2" );
    layout2_4_2->addWidget( textLabel2_4_2 );

    QLETelefonoCasa = new QLineEdit( this, "QLETelefonoCasa" );
    layout2_4_2->addWidget( QLETelefonoCasa );
    layout15->addLayout( layout2_4_2 );
    layout17->addLayout( layout15 );

    ActualizaDatosAlumnoLayout->addLayout( layout17, 0, 0 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    QPBActualiza = new QPushButton( this, "QPBActualiza" );
    layout20->addWidget( QPBActualiza );

    QPBCambiaEscuela = new QPushButton( this, "QPBCambiaEscuela" );
    layout20->addWidget( QPBCambiaEscuela );

    QPBSelAlumno = new QPushButton( this, "QPBSelAlumno" );
    layout20->addWidget( QPBSelAlumno );

    ActualizaDatosAlumnoLayout->addLayout( layout20, 1, 0 );
    languageChange();
    resize( QSize(578, 239).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaDatosAlumno::~ActualizaDatosAlumno()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaDatosAlumno::languageChange()
{
    setCaption( tr( "Actualiza Datos De Los Alumnos" ) );
    textLabel1->setText( tr( "Alumnos" ) );
    textLabel2->setText( tr( "Nombre" ) );
    textLabel2_3->setText( tr( "Apellido Paterno" ) );
    textLabel2_2->setText( tr( "Apellido Materno" ) );
    textLabel3->setText( tr( "Escuelas" ) );
    textLabel2_4->setText( tr( "Grupo" ) );
    textLabel2_5->setText( tr( "Boleta" ) );
    textLabel2_4_4->setText( tr( "Correo Electronico" ) );
    textLabel2_4_3->setText( tr( "Celular" ) );
    textLabel2_4_2->setText( tr( "Casa" ) );
    QPBActualiza->setText( tr( "Actualizar" ) );
    QPBCambiaEscuela->setText( tr( "Cambiar Escuela" ) );
    QPBSelAlumno->setText( tr( "Selecciona Alumno" ) );
}

