/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroAlumnoServicio.ui'
**
** Created: Thu Apr 11 21:39:55 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroAlumnoServicio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlServiciosSiscom.h>
#include <QCtrlAlumnos.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlServiciosSiscom.h"
#include "QCtrlAlumnos.h"

/*
 *  Constructs a RegistroAlumnoServicio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroAlumnoServicio::RegistroAlumnoServicio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroAlumnoServicio" );
    RegistroAlumnoServicioLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroAlumnoServicioLayout"); 

    layout11 = new QHBoxLayout( 0, 0, 0, "layout11"); 

    QPBRegHEntrada = new QPushButton( this, "QPBRegHEntrada" );
    QPBRegHEntrada->setMinimumSize( QSize( 0, 42 ) );
    layout11->addWidget( QPBRegHEntrada );

    QPBRHSalida = new QPushButton( this, "QPBRHSalida" );
    QPBRHSalida->setMinimumSize( QSize( 0, 42 ) );
    layout11->addWidget( QPBRHSalida );

    pushButton1_3 = new QPushButton( this, "pushButton1_3" );
    pushButton1_3->setMinimumSize( QSize( 0, 42 ) );
    layout11->addWidget( pushButton1_3 );

    RegistroAlumnoServicioLayout->addLayout( layout11, 3, 0 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrServicios = new QCtrlServiciosSiscom( this, "QCtrServicios" );
    QCtrServicios->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrServicios->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrServicios );
    layout4->addLayout( layout1 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout3->addWidget( textLabel3 );

    QCtrAlumnos = new QCtrlAlumnos( this, "QCtrAlumnos" );
    QCtrAlumnos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrAlumnos->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrAlumnos );
    layout4->addLayout( layout3 );
    layout17->addLayout( layout4 );

    RegistroAlumnoServicioLayout->addLayout( layout17, 0, 0 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( textLabel5 );

    QTEComentarios = new QTextEdit( this, "QTEComentarios" );
    QTEComentarios->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEComentarios->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( QTEComentarios );

    RegistroAlumnoServicioLayout->addLayout( layout19, 1, 0 );

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout20->addWidget( textLabel6 );

    QTAlumnosEnTaller = new QTable( this, "QTAlumnosEnTaller" );
    QTAlumnosEnTaller->setNumCols( QTAlumnosEnTaller->numCols() + 1 );
    QTAlumnosEnTaller->horizontalHeader()->setLabel( QTAlumnosEnTaller->numCols() - 1, tr( "Alumno" ) );
    QTAlumnosEnTaller->setNumCols( QTAlumnosEnTaller->numCols() + 1 );
    QTAlumnosEnTaller->horizontalHeader()->setLabel( QTAlumnosEnTaller->numCols() - 1, tr( "Hora Entrada" ) );
    QTAlumnosEnTaller->setNumCols( QTAlumnosEnTaller->numCols() + 1 );
    QTAlumnosEnTaller->horizontalHeader()->setLabel( QTAlumnosEnTaller->numCols() - 1, tr( "Hora Salida" ) );
    QTAlumnosEnTaller->setNumRows( 0 );
    QTAlumnosEnTaller->setNumCols( 3 );
    QTAlumnosEnTaller->setReadOnly( TRUE );
    layout20->addWidget( QTAlumnosEnTaller );

    RegistroAlumnoServicioLayout->addLayout( layout20, 2, 0 );
    languageChange();
    resize( QSize(718, 592).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroAlumnoServicio::~RegistroAlumnoServicio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroAlumnoServicio::languageChange()
{
    setCaption( tr( "Registro Alumno Servicio" ) );
    QPBRegHEntrada->setText( tr( "Registra Hora\n"
"Entrada" ) );
    QPBRHSalida->setText( tr( "Registro Hora\n"
"Salida" ) );
    pushButton1_3->setText( tr( "pushButton1" ) );
    textLabel1->setText( tr( "Servicios" ) );
    textLabel3->setText( tr( "Alumno" ) );
    textLabel5->setText( tr( "Comentarios" ) );
    textLabel6->setText( tr( "Alumnos En Laboratorio" ) );
    QTAlumnosEnTaller->horizontalHeader()->setLabel( 0, tr( "Alumno" ) );
    QTAlumnosEnTaller->horizontalHeader()->setLabel( 1, tr( "Hora Entrada" ) );
    QTAlumnosEnTaller->horizontalHeader()->setLabel( 2, tr( "Hora Salida" ) );
}

