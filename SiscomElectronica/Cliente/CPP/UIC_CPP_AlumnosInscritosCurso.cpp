/****************************************************************************
** Form implementation generated from reading ui file 'UI/AlumnosInscritosCurso.ui'
**
** Created: Wed Jan 31 10:48:09 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AlumnosInscritosCurso.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlCursos.h>
#include <QCtrlFechasCursos.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlCursos.h"
#include "QCtrlFechasCursos.h"

/*
 *  Constructs a AlumnosInscritosCurso as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
AlumnosInscritosCurso::AlumnosInscritosCurso( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "AlumnosInscritosCurso" );
    AlumnosInscritosCursoLayout = new QGridLayout( this, 1, 1, 11, 6, "AlumnosInscritosCursoLayout"); 

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout12->addWidget( textLabel1_2 );

    QCtrCursos = new QCtrlCursos( this, "QCtrCursos" );
    layout12->addWidget( QCtrCursos );
    layout19->addLayout( layout12 );

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout18->addWidget( textLabel1 );

    QCtrFechasCurso = new QCtrlFechasCursos( this, "QCtrFechasCurso" );
    layout18->addWidget( QCtrFechasCurso );
    layout19->addLayout( layout18 );

    AlumnosInscritosCursoLayout->addLayout( layout19, 0, 0 );

    QTAlumnos = new QTable( this, "QTAlumnos" );
    QTAlumnos->setNumCols( QTAlumnos->numCols() + 1 );
    QTAlumnos->horizontalHeader()->setLabel( QTAlumnos->numCols() - 1, tr( "Alumno" ) );
    QTAlumnos->setNumCols( QTAlumnos->numCols() + 1 );
    QTAlumnos->horizontalHeader()->setLabel( QTAlumnos->numCols() - 1, tr( "Telefono" ) );
    QTAlumnos->setNumCols( QTAlumnos->numCols() + 1 );
    QTAlumnos->horizontalHeader()->setLabel( QTAlumnos->numCols() - 1, tr( "Correo" ) );
    QTAlumnos->setNumCols( QTAlumnos->numCols() + 1 );
    QTAlumnos->horizontalHeader()->setLabel( QTAlumnos->numCols() - 1, tr( "Precio" ) );
    QTAlumnos->setNumCols( QTAlumnos->numCols() + 1 );
    QTAlumnos->horizontalHeader()->setLabel( QTAlumnos->numCols() - 1, tr( "Explicacion" ) );
    QTAlumnos->setNumRows( 0 );
    QTAlumnos->setNumCols( 5 );
    QTAlumnos->setReadOnly( TRUE );

    AlumnosInscritosCursoLayout->addWidget( QTAlumnos, 1, 0 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout20->addWidget( pushButton2 );

    pushButton3 = new QPushButton( this, "pushButton3" );
    layout20->addWidget( pushButton3 );

    AlumnosInscritosCursoLayout->addLayout( layout20, 2, 0 );
    languageChange();
    resize( QSize(942, 531).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AlumnosInscritosCurso::~AlumnosInscritosCurso()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AlumnosInscritosCurso::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_2->setText( tr( "Cursos" ) );
    textLabel1->setText( tr( "Fechas Cursos" ) );
    QTAlumnos->horizontalHeader()->setLabel( 0, tr( "Alumno" ) );
    QTAlumnos->horizontalHeader()->setLabel( 1, tr( "Telefono" ) );
    QTAlumnos->horizontalHeader()->setLabel( 2, tr( "Correo" ) );
    QTAlumnos->horizontalHeader()->setLabel( 3, tr( "Precio" ) );
    QTAlumnos->horizontalHeader()->setLabel( 4, tr( "Explicacion" ) );
    pushButton2->setText( tr( "pushButton2" ) );
    pushButton3->setText( tr( "pushButton3" ) );
}

