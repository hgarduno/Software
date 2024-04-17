/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroAlumnoCurso.ui'
**
** Created: Fri Apr 12 21:26:02 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroAlumnoCurso.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <QCtrlCursos.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlEscuelas.h"
#include "QCtrlCursos.h"

/*
 *  Constructs a RegistroAlumnoCurso as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroAlumnoCurso::RegistroAlumnoCurso( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroAlumnoCurso" );
    RegistroAlumnoCursoLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroAlumnoCursoLayout"); 

    QFDatosAlumno = new QFrame( this, "QFDatosAlumno" );
    QFDatosAlumno->setEnabled( TRUE );
    QFDatosAlumno->setFrameShape( QFrame::StyledPanel );
    QFDatosAlumno->setFrameShadow( QFrame::Raised );
    QFDatosAlumnoLayout = new QGridLayout( QFDatosAlumno, 1, 1, 11, 6, "QFDatosAlumnoLayout"); 

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( QFDatosAlumno, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel3 );

    QLENombre = new QLineEdit( QFDatosAlumno, "QLENombre" );
    layout5->addWidget( QLENombre );
    layout12->addLayout( layout5 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel3_2 = new QLabel( QFDatosAlumno, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2->addWidget( textLabel3_2 );

    QLEAPaterno = new QLineEdit( QFDatosAlumno, "QLEAPaterno" );
    layout5_2->addWidget( QLEAPaterno );
    layout12->addLayout( layout5_2 );

    layout5_2_2 = new QVBoxLayout( 0, 0, 6, "layout5_2_2"); 

    textLabel3_2_2 = new QLabel( QFDatosAlumno, "textLabel3_2_2" );
    textLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2_2->addWidget( textLabel3_2_2 );

    QLEAMaterno = new QLineEdit( QFDatosAlumno, "QLEAMaterno" );
    layout5_2_2->addWidget( QLEAMaterno );
    layout12->addLayout( layout5_2_2 );

    QFDatosAlumnoLayout->addLayout( layout12, 0, 0 );

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( QFDatosAlumno, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel1 );

    QCtrEscuelas = new QCtrlEscuelas( QFDatosAlumno, "QCtrEscuelas" );
    QCtrEscuelas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)5, 0, 0, QCtrEscuelas->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( QCtrEscuelas );
    layout37->addLayout( layout10 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel2 = new QLabel( QFDatosAlumno, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel2 );

    QLEGrupo = new QLineEdit( QFDatosAlumno, "QLEGrupo" );
    QLEGrupo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEGrupo->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( QLEGrupo );
    layout37->addLayout( layout11 );

    layout11_2 = new QVBoxLayout( 0, 0, 6, "layout11_2"); 

    textLabel2_2 = new QLabel( QFDatosAlumno, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( textLabel2_2 );

    QLEBoleta = new QLineEdit( QFDatosAlumno, "QLEBoleta" );
    QLEBoleta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEBoleta->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( QLEBoleta );
    layout37->addLayout( layout11_2 );

    QFDatosAlumnoLayout->addLayout( layout37, 1, 0 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout11_3 = new QVBoxLayout( 0, 0, 6, "layout11_3"); 

    textLabel2_3 = new QLabel( QFDatosAlumno, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout11_3->addWidget( textLabel2_3 );

    QLECorreo = new QLineEdit( QFDatosAlumno, "QLECorreo" );
    QLECorreo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECorreo->sizePolicy().hasHeightForWidth() ) );
    QLECorreo->setAcceptDrops( FALSE );
    QLECorreo->setDragEnabled( FALSE );
    layout11_3->addWidget( QLECorreo );
    layout17->addLayout( layout11_3 );

    layout11_3_3 = new QVBoxLayout( 0, 0, 6, "layout11_3_3"); 

    textLabel2_3_3 = new QLabel( QFDatosAlumno, "textLabel2_3_3" );
    textLabel2_3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_3->sizePolicy().hasHeightForWidth() ) );
    layout11_3_3->addWidget( textLabel2_3_3 );

    QLEReCorreo = new QLineEdit( QFDatosAlumno, "QLEReCorreo" );
    QLEReCorreo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEReCorreo->sizePolicy().hasHeightForWidth() ) );
    QLEReCorreo->setAcceptDrops( FALSE );
    QLEReCorreo->setEchoMode( QLineEdit::Normal );
    layout11_3_3->addWidget( QLEReCorreo );
    layout17->addLayout( layout11_3_3 );

    layout11_3_2 = new QVBoxLayout( 0, 0, 6, "layout11_3_2"); 

    textLabel2_3_2 = new QLabel( QFDatosAlumno, "textLabel2_3_2" );
    textLabel2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_2->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2->addWidget( textLabel2_3_2 );

    QLECelular = new QLineEdit( QFDatosAlumno, "QLECelular" );
    QLECelular->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECelular->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2->addWidget( QLECelular );
    layout17->addLayout( layout11_3_2 );

    layout11_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout11_3_2_2"); 

    textLabel2_3_2_2 = new QLabel( QFDatosAlumno, "textLabel2_3_2_2" );
    textLabel2_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2_2->addWidget( textLabel2_3_2_2 );

    QLETCasa = new QLineEdit( QFDatosAlumno, "QLETCasa" );
    QLETCasa->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLETCasa->sizePolicy().hasHeightForWidth() ) );
    layout11_3_2_2->addWidget( QLETCasa );
    layout17->addLayout( layout11_3_2_2 );

    QFDatosAlumnoLayout->addLayout( layout17, 2, 0 );

    RegistroAlumnoCursoLayout->addWidget( QFDatosAlumno, 3, 0 );

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

    RegistroAlumnoCursoLayout->addWidget( QTHorariosCurso, 1, 0 );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout24->addWidget( textLabel1_2 );

    QCtrCursos = new QCtrlCursos( this, "QCtrCursos" );
    layout24->addWidget( QCtrCursos );
    layout25->addLayout( layout24 );

    QPBDisponibilidadC = new QPushButton( this, "QPBDisponibilidadC" );
    QPBDisponibilidadC->setMinimumSize( QSize( 0, 43 ) );
    layout25->addWidget( QPBDisponibilidadC );

    RegistroAlumnoCursoLayout->addLayout( layout25, 0, 0 );

    QTCostos = new QTable( this, "QTCostos" );
    QTCostos->setNumCols( QTCostos->numCols() + 1 );
    QTCostos->horizontalHeader()->setLabel( QTCostos->numCols() - 1, tr( "Promocion" ) );
    QTCostos->setNumCols( QTCostos->numCols() + 1 );
    QTCostos->horizontalHeader()->setLabel( QTCostos->numCols() - 1, tr( "Costo" ) );
    QTCostos->setNumRows( 0 );
    QTCostos->setNumCols( 2 );
    QTCostos->setReadOnly( TRUE );

    RegistroAlumnoCursoLayout->addWidget( QTCostos, 2, 0 );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout23->addWidget( QPBRegistrar );

    QPBImpComprobante = new QPushButton( this, "QPBImpComprobante" );
    layout23->addWidget( QPBImpComprobante );

    QPBInscribeOAlumno = new QPushButton( this, "QPBInscribeOAlumno" );
    layout23->addWidget( QPBInscribeOAlumno );

    RegistroAlumnoCursoLayout->addLayout( layout23, 4, 0 );
    languageChange();
    resize( QSize(799, 711).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroAlumnoCurso::~RegistroAlumnoCurso()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroAlumnoCurso::languageChange()
{
    setCaption( tr( "Registros de Alumnos Al Curso" ) );
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
    QTHorariosCurso->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 1, tr( "Horario Inicio" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 2, tr( "Hora Fin" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 3, tr( "Cupo Disponible" ) );
    QTHorariosCurso->horizontalHeader()->setLabel( 4, tr( "Disponibilidad" ) );
    textLabel1_2->setText( tr( "Cursos" ) );
    QPBDisponibilidadC->setText( tr( "Disponibilidad\n"
"Cursos" ) );
    QTCostos->horizontalHeader()->setLabel( 0, tr( "Promocion" ) );
    QTCostos->horizontalHeader()->setLabel( 1, tr( "Costo" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBImpComprobante->setText( tr( "Imprime Comprobante" ) );
    QPBInscribeOAlumno->setText( tr( "Inscribe Otro Alumno" ) );
}

