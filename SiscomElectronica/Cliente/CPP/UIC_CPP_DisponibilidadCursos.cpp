/****************************************************************************
** Form implementation generated from reading ui file 'UI/DisponibilidadCursos.ui'
**
** Created: Fri Apr 12 21:26:02 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DisponibilidadCursos.h"

#include <qvariant.h>
#include <qlabel.h>
#include <QCtrlFechasCursos.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFechasCursos.h"

/*
 *  Constructs a DisponibilidadCursos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DisponibilidadCursos::DisponibilidadCursos( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "DisponibilidadCursos" );
    DisponibilidadCursosLayout = new QGridLayout( this, 1, 1, 11, 6, "DisponibilidadCursosLayout"); 

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout18->addWidget( textLabel1 );

    QCtrFechasCurso = new QCtrlFechasCursos( this, "QCtrFechasCurso" );
    layout18->addWidget( QCtrFechasCurso );

    DisponibilidadCursosLayout->addLayout( layout18, 0, 0 );

    QTHorariosCurso = new QTable( this, "QTHorariosCurso" );
    QTHorariosCurso->setNumCols( QTHorariosCurso->numCols() + 1 );
    QTHorariosCurso->horizontalHeader()->setLabel( QTHorariosCurso->numCols() - 1, tr( "Fecha" ) );
    QTHorariosCurso->setNumCols( QTHorariosCurso->numCols() + 1 );
    QTHorariosCurso->horizontalHeader()->setLabel( QTHorariosCurso->numCols() - 1, tr( "Horario Inicio" ) );
    QTHorariosCurso->setNumCols( QTHorariosCurso->numCols() + 1 );
    QTHorariosCurso->horizontalHeader()->setLabel( QTHorariosCurso->numCols() - 1, tr( "Hora Fin" ) );
    QTHorariosCurso->setNumCols( QTHorariosCurso->numCols() + 1 );
    QTHorariosCurso->horizontalHeader()->setLabel( QTHorariosCurso->numCols() - 1, tr( "Cupo Disponible" ) );
    QTHorariosCurso->setNumCols( QTHorariosCurso->numCols() + 1 );
    QTHorariosCurso->horizontalHeader()->setLabel( QTHorariosCurso->numCols() - 1, tr( "Disponibilidad" ) );
    QTHorariosCurso->setNumRows( 0 );
    QTHorariosCurso->setNumCols( 5 );
    QTHorariosCurso->setReadOnly( TRUE );

    DisponibilidadCursosLayout->addWidget( QTHorariosCurso, 1, 0 );

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    pushButton5 = new QPushButton( this, "pushButton5" );
    layout28->addWidget( pushButton5 );

    pushButton5_2 = new QPushButton( this, "pushButton5_2" );
    layout28->addWidget( pushButton5_2 );

    DisponibilidadCursosLayout->addLayout( layout28, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DisponibilidadCursos::~DisponibilidadCursos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DisponibilidadCursos::languageChange()
{
    setCaption( tr( "Disponibilidad de Cursos" ) );
    textLabel1->setText( tr( "Fechas Cursos" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 1, tr( "Horario Inicio" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 2, tr( "Hora Fin" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 3, tr( "Cupo Disponible" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 4, tr( "Disponibilidad" ) );
    pushButton5->setText( tr( "pushButton5" ) );
    pushButton5_2->setText( tr( "pushButton5" ) );
}

