/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProgramandoCurso.ui'
**
** Created: Fri Apr 12 21:26:02 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProgramandoCurso.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <QCtrlProgramacionCursos.h>
#include <QCtrlCursos.h>
#include <IMP_QControlFecha.h>
#include <QCtrlRangoHora.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProgramacionCursos.h"
#include "QCtrlCursos.h"
#include "IMP_QControlFecha.h"
#include "QCtrlRangoHora.h"

/*
 *  Constructs a ProgramandoCurso as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ProgramandoCurso::ProgramandoCurso( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ProgramandoCurso" );
    ProgramandoCursoLayout = new QGridLayout( this, 1, 1, 11, 6, "ProgramandoCursoLayout"); 

    QTCursos = new QTable( this, "QTCursos" );
    QTCursos->setNumCols( QTCursos->numCols() + 1 );
    QTCursos->horizontalHeader()->setLabel( QTCursos->numCols() - 1, tr( "Lunes" ) );
    QTCursos->setNumCols( QTCursos->numCols() + 1 );
    QTCursos->horizontalHeader()->setLabel( QTCursos->numCols() - 1, tr( "Martes" ) );
    QTCursos->setNumCols( QTCursos->numCols() + 1 );
    QTCursos->horizontalHeader()->setLabel( QTCursos->numCols() - 1, tr( "Miercoles" ) );
    QTCursos->setNumCols( QTCursos->numCols() + 1 );
    QTCursos->horizontalHeader()->setLabel( QTCursos->numCols() - 1, tr( "Jueves" ) );
    QTCursos->setNumCols( QTCursos->numCols() + 1 );
    QTCursos->horizontalHeader()->setLabel( QTCursos->numCols() - 1, tr( "Viernes" ) );
    QTCursos->setNumCols( QTCursos->numCols() + 1 );
    QTCursos->horizontalHeader()->setLabel( QTCursos->numCols() - 1, tr( "Sabado" ) );
    QTCursos->setNumCols( QTCursos->numCols() + 1 );
    QTCursos->horizontalHeader()->setLabel( QTCursos->numCols() - 1, tr( "Domingo" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "8:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "8:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "9:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "9:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "10:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "10:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "11:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "11:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "12:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "12:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "13:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "13:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "14:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "14:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "15:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "15:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "16:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "16:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "17:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "17:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "18:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "18:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "19:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "19:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "20:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "20:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "21:00" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "21:30" ) );
    QTCursos->setNumRows( QTCursos->numRows() + 1 );
    QTCursos->verticalHeader()->setLabel( QTCursos->numRows() - 1, tr( "22:00" ) );
    QTCursos->setNumRows( 29 );
    QTCursos->setNumCols( 7 );
    QTCursos->setReadOnly( TRUE );

    ProgramandoCursoLayout->addMultiCellWidget( QTCursos, 1, 1, 0, 2 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel1_2 );

    table2 = new QTable( this, "table2" );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Promocion" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Costo" ) );
    table2->setMaximumSize( QSize( 32767, 100 ) );
    table2->setNumRows( 0 );
    table2->setNumCols( 2 );
    layout11->addWidget( table2 );

    ProgramandoCursoLayout->addMultiCellLayout( layout11, 2, 2, 0, 2 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    QPBHabilitaProgCursos = new QPushButton( this, "QPBHabilitaProgCursos" );
    layout19->addWidget( QPBHabilitaProgCursos );

    QPBHabilitaCursos = new QPushButton( this, "QPBHabilitaCursos" );
    layout19->addWidget( QPBHabilitaCursos );

    ProgramandoCursoLayout->addLayout( layout19, 3, 0 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    QPBRegistraProgCursos = new QPushButton( this, "QPBRegistraProgCursos" );
    QPBRegistraProgCursos->setEnabled( FALSE );
    layout14->addWidget( QPBRegistraProgCursos );

    QPRegistraFecha = new QPushButton( this, "QPRegistraFecha" );
    QPRegistraFecha->setEnabled( FALSE );
    layout14->addWidget( QPRegistraFecha );
    layout16->addLayout( layout14 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    QPEliminaHorariosSeleccionados = new QPushButton( this, "QPEliminaHorariosSeleccionados" );
    QPEliminaHorariosSeleccionados->setEnabled( FALSE );
    layout15->addWidget( QPEliminaHorariosSeleccionados );

    QPRegistraFecha_2_2 = new QPushButton( this, "QPRegistraFecha_2_2" );
    QPRegistraFecha_2_2->setEnabled( TRUE );
    layout15->addWidget( QPRegistraFecha_2_2 );
    layout16->addLayout( layout15 );

    ProgramandoCursoLayout->addLayout( layout16, 3, 1 );

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    QPBCCPorFecha = new QPushButton( this, "QPBCCPorFecha" );
    QPBCCPorFecha->setEnabled( TRUE );
    layout20->addWidget( QPBCCPorFecha );

    QPRegistraFecha_2_2_2 = new QPushButton( this, "QPRegistraFecha_2_2_2" );
    QPRegistraFecha_2_2_2->setEnabled( TRUE );
    layout20->addWidget( QPRegistraFecha_2_2_2 );

    ProgramandoCursoLayout->addLayout( layout20, 3, 2 );

    layout40 = new QHBoxLayout( 0, 0, 6, "layout40"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1 );

    QCtrProgramacionC = new QCtrlProgramacionCursos( this, "QCtrProgramacionC" );
    QCtrProgramacionC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrProgramacionC->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( QCtrProgramacionC );
    layout8->addLayout( layout7 );

    QPBAgregaProgramacion = new QPushButton( this, "QPBAgregaProgramacion" );
    QPBAgregaProgramacion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, QPBAgregaProgramacion->sizePolicy().hasHeightForWidth() ) );
    QPBAgregaProgramacion->setMinimumSize( QSize( 0, 40 ) );
    layout8->addWidget( QPBAgregaProgramacion );
    layout36->addLayout( layout8 );

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    QCtrCursos = new QCtrlCursos( this, "QCtrCursos" );
    layout4->addWidget( QCtrCursos );
    layout33->addLayout( layout4 );

    pushButton1 = new QPushButton( this, "pushButton1" );
    pushButton1->setMinimumSize( QSize( 0, 40 ) );
    layout33->addWidget( pushButton1 );
    layout36->addLayout( layout33 );

    layout34 = new QHBoxLayout( 0, 0, 6, "layout34"); 

    layout11_2 = new QHBoxLayout( 0, 0, 6, "layout11_2"); 

    layout11_3 = new QVBoxLayout( 0, 0, 6, "layout11_3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout11_3->addWidget( textLabel3 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    QCtrFechaInicio->setEnabled( TRUE );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout11_3->addWidget( QCtrFechaInicio );
    layout11_2->addLayout( layout11_3 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel1_3 );

    QCtrRangoHora = new QCtrlRangoHora( this, "QCtrRangoHora" );
    QCtrRangoHora->setEnabled( TRUE );
    QCtrRangoHora->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrRangoHora->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( QCtrRangoHora );
    layout11_2->addLayout( layout10 );
    layout34->addLayout( layout11_2 );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    pushButton1_2->setMinimumSize( QSize( 0, 40 ) );
    layout34->addWidget( pushButton1_2 );
    layout36->addLayout( layout34 );
    layout40->addLayout( layout36 );

    layout38 = new QVBoxLayout( 0, 0, 6, "layout38"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout38->addWidget( textLabel1_4 );

    textEdit2 = new QTextEdit( this, "textEdit2" );
    textEdit2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textEdit2->sizePolicy().hasHeightForWidth() ) );
    textEdit2->setMinimumSize( QSize( 0, 0 ) );
    textEdit2->setMaximumSize( QSize( 32767, 32767 ) );
    textEdit2->setWordWrap( QTextEdit::WidgetWidth );
    layout38->addWidget( textEdit2 );
    layout40->addLayout( layout38 );

    ProgramandoCursoLayout->addMultiCellLayout( layout40, 0, 0, 0, 2 );
    languageChange();
    resize( QSize(818, 662).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProgramandoCurso::~ProgramandoCurso()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProgramandoCurso::languageChange()
{
    setCaption( tr( "Form1" ) );
    QTCursos->horizontalHeader()->setLabel( 0, tr( "Lunes" ) );
    QTCursos->horizontalHeader()->setLabel( 1, tr( "Martes" ) );
    QTCursos->horizontalHeader()->setLabel( 2, tr( "Miercoles" ) );
    QTCursos->horizontalHeader()->setLabel( 3, tr( "Jueves" ) );
    QTCursos->horizontalHeader()->setLabel( 4, tr( "Viernes" ) );
    QTCursos->horizontalHeader()->setLabel( 5, tr( "Sabado" ) );
    QTCursos->horizontalHeader()->setLabel( 6, tr( "Domingo" ) );
    QTCursos->verticalHeader()->setLabel( 0, tr( "8:00" ) );
    QTCursos->verticalHeader()->setLabel( 1, tr( "8:30" ) );
    QTCursos->verticalHeader()->setLabel( 2, tr( "9:00" ) );
    QTCursos->verticalHeader()->setLabel( 3, tr( "9:30" ) );
    QTCursos->verticalHeader()->setLabel( 4, tr( "10:00" ) );
    QTCursos->verticalHeader()->setLabel( 5, tr( "10:30" ) );
    QTCursos->verticalHeader()->setLabel( 6, tr( "11:00" ) );
    QTCursos->verticalHeader()->setLabel( 7, tr( "11:30" ) );
    QTCursos->verticalHeader()->setLabel( 8, tr( "12:00" ) );
    QTCursos->verticalHeader()->setLabel( 9, tr( "12:30" ) );
    QTCursos->verticalHeader()->setLabel( 10, tr( "13:00" ) );
    QTCursos->verticalHeader()->setLabel( 11, tr( "13:30" ) );
    QTCursos->verticalHeader()->setLabel( 12, tr( "14:00" ) );
    QTCursos->verticalHeader()->setLabel( 13, tr( "14:30" ) );
    QTCursos->verticalHeader()->setLabel( 14, tr( "15:00" ) );
    QTCursos->verticalHeader()->setLabel( 15, tr( "15:30" ) );
    QTCursos->verticalHeader()->setLabel( 16, tr( "16:00" ) );
    QTCursos->verticalHeader()->setLabel( 17, tr( "16:30" ) );
    QTCursos->verticalHeader()->setLabel( 18, tr( "17:00" ) );
    QTCursos->verticalHeader()->setLabel( 19, tr( "17:30" ) );
    QTCursos->verticalHeader()->setLabel( 20, tr( "18:00" ) );
    QTCursos->verticalHeader()->setLabel( 21, tr( "18:30" ) );
    QTCursos->verticalHeader()->setLabel( 22, tr( "19:00" ) );
    QTCursos->verticalHeader()->setLabel( 23, tr( "19:30" ) );
    QTCursos->verticalHeader()->setLabel( 24, tr( "20:00" ) );
    QTCursos->verticalHeader()->setLabel( 25, tr( "20:30" ) );
    QTCursos->verticalHeader()->setLabel( 26, tr( "21:00" ) );
    QTCursos->verticalHeader()->setLabel( 27, tr( "21:30" ) );
    QTCursos->verticalHeader()->setLabel( 28, tr( "22:00" ) );
    textLabel1_2->setText( tr( "textLabel1" ) );
    table2->horizontalHeader()->setLabel( 0, tr( "Promocion" ) );
    table2->horizontalHeader()->setLabel( 1, tr( "Costo" ) );
    QPBHabilitaProgCursos->setText( tr( "Habilita Programacion Cursos" ) );
    QPBHabilitaCursos->setText( tr( "Habilita Cursos" ) );
    QPBRegistraProgCursos->setText( tr( "Registra Programacion Curso" ) );
    QPRegistraFecha->setText( tr( "Registra Fecha" ) );
    QPEliminaHorariosSeleccionados->setText( tr( "Elimina Horarios Seleccionados" ) );
    QPRegistraFecha_2_2->setText( tr( "Alguna Cosa Mas" ) );
    QPBCCPorFecha->setText( tr( "Consulta Cursos Por Fecha" ) );
    QPRegistraFecha_2_2_2->setText( tr( "Registra Fecha" ) );
    textLabel1->setText( tr( "Programacion Curso" ) );
    QPBAgregaProgramacion->setText( tr( "Agregar \n"
"Programacion" ) );
    textLabel2->setText( tr( "Cursos" ) );
    pushButton1->setText( tr( "Agregar \n"
"Curso" ) );
    textLabel3->setText( tr( "Fecha Inicio" ) );
    textLabel1_3->setText( tr( "Hora Inicio / Hora Termino" ) );
    pushButton1_2->setText( tr( "Registra Fecha \n"
"De \n"
"Inicio del Curso" ) );
    textLabel1_4->setText( tr( "Instrucciones de registro" ) );
    textEdit2->setText( tr( "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\"font-size:5pt;font-family:Fixed\">\n"
"<p><span style=\"font-weight:600\">Fecha de Inicio</span> <br /><br />Se debe colocar la fecha del inicio de la semana en la que Iniciara el curso.</p>\n"
"</body></html>\n"
"" ) );
}

