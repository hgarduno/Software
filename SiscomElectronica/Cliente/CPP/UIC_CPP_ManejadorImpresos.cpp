/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorImpresos.ui'
**
** Created: Fri Apr 12 21:26:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorImpresos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <IMP_QControlFecha.h>
#include <QCtrlEstadosImpresosSE.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "IMP_QControlFecha.h"
#include "QCtrlEstadosImpresosSE.h"

/*
 *  Constructs a ManejadorImpresos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorImpresos::ManejadorImpresos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorImpresos" );
    ManejadorImpresosLayout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorImpresosLayout"); 

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel2_5 = new QLabel( this, "textLabel2_5" );
    layout42->addWidget( textLabel2_5 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Alumno" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Celular" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Hora de Entrega" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Clave" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Memoria" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Archivo" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 7 );
    layout42->addWidget( QTDatos );

    ManejadorImpresosLayout->addMultiCellLayout( layout42, 1, 1, 0, 3 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    layout8->addWidget( QPBConsultar );

    QPBActualiza = new QPushButton( this, "QPBActualiza" );
    layout8->addWidget( QPBActualiza );

    ManejadorImpresosLayout->addMultiCellLayout( layout8, 2, 2, 0, 3 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel2 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrFechaInicio );

    ManejadorImpresosLayout->addLayout( layout3, 0, 0 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( textLabel2_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( QCtrFechaFin );

    ManejadorImpresosLayout->addLayout( layout3_2, 0, 1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QCtrEdosImpresos = new QCtrlEstadosImpresosSE( this, "QCtrEdosImpresos" );
    QCtrEdosImpresos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrEdosImpresos->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCtrEdosImpresos );

    ManejadorImpresosLayout->addLayout( layout2, 0, 2 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ManejadorImpresosLayout->addItem( spacer1, 0, 3 );
    languageChange();
    resize( QSize(853, 508).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorImpresos::~ManejadorImpresos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorImpresos::languageChange()
{
    setCaption( tr( "Manejador de Estados Circuitos Impresos" ) );
    textLabel2_5->setText( tr( "Placas Pendientes" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Alumno" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Celular" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Fecha" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Hora de Entrega" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Clave" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Memoria" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Archivo" ) );
    QPBConsultar->setText( tr( "Consulta" ) );
    QPBActualiza->setText( tr( "Actualiza Estado" ) );
    textLabel2->setText( tr( "Fecha Inicio" ) );
    textLabel2_2->setText( tr( "Fecha Fin" ) );
    textLabel1->setText( tr( "Estados Impresos" ) );
}

