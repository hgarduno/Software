/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProgramacionPlacas.ui'
**
** Created: Fri Apr 12 21:26:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProgramacionPlacas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "IMP_QControlFecha.h"

/*
 *  Constructs a ProgramacionPlacas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ProgramacionPlacas::ProgramacionPlacas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ProgramacionPlacas" );
    ProgramacionPlacasLayout = new QGridLayout( this, 1, 1, 11, 6, "ProgramacionPlacasLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBPPendientes = new QPushButton( this, "QPBPPendientes" );
    layout1->addWidget( QPBPPendientes );

    QPBEntregar = new QPushButton( this, "QPBEntregar" );
    layout1->addWidget( QPBEntregar );

    ProgramacionPlacasLayout->addLayout( layout1, 3, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cliente" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Placa" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Hora" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Hora Entrega" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );
    QTDatos->setReadOnly( TRUE );

    ProgramacionPlacasLayout->addWidget( QTDatos, 2, 0 );

    textLabel1 = new QLabel( this, "textLabel1" );

    ProgramacionPlacasLayout->addWidget( textLabel1, 1, 0 );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    layout2->addWidget( QCtrFechaInicio );
    layout4->addLayout( layout2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout3->addWidget( textLabel3 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    layout3->addWidget( QCtrFechaFin );
    layout4->addLayout( layout3 );
    layout5->addLayout( layout4 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout5->addItem( spacer1 );

    ProgramacionPlacasLayout->addLayout( layout5, 0, 0 );
    languageChange();
    resize( QSize(732, 534).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProgramacionPlacas::~ProgramacionPlacas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProgramacionPlacas::languageChange()
{
    setCaption( tr( "Programacion de Placas" ) );
    QPBPPendientes->setText( tr( "Placas Pendientes" ) );
    QPBEntregar->setText( tr( "Entregar Placa" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Cliente" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Placa" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Hora" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Hora Entrega" ) );
    textLabel1->setText( tr( "Placas" ) );
    textLabel2->setText( tr( "Fecha Inicio" ) );
    textLabel3->setText( tr( "Fecha Fin" ) );
}

