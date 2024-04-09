/****************************************************************************
** Form implementation generated from reading ui file 'UI/ControladorReportesVentasExpendios.ui'
**
** Created: lun abr 1 18:57:50 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ControladorReportesVentasExpendios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a ControladorReportesVentasExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ControladorReportesVentasExpendios::ControladorReportesVentasExpendios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ControladorReportesVentasExpendios" );
    ControladorReportesVentasExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "ControladorReportesVentasExpendiosLayout"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout10->addWidget( textLabel1 );

    QTExpendios = new QTable( this, "QTExpendios" );
    QTExpendios->setNumCols( QTExpendios->numCols() + 1 );
    QTExpendios->horizontalHeader()->setLabel( QTExpendios->numCols() - 1, tr( "Expendio" ) );
    QTExpendios->setNumCols( QTExpendios->numCols() + 1 );
    QTExpendios->horizontalHeader()->setLabel( QTExpendios->numCols() - 1, tr( "Fecha" ) );
    QTExpendios->setNumRows( 0 );
    QTExpendios->setNumCols( 2 );
    QTExpendios->setReadOnly( TRUE );
    layout10->addWidget( QTExpendios );

    ControladorReportesVentasExpendiosLayout->addLayout( layout10, 0, 0 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout11->addWidget( textLabel2 );

    QLEPeriodo = new QLineEdit( this, "QLEPeriodo" );
    layout11->addWidget( QLEPeriodo );
    layout15->addLayout( layout11 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout12->addWidget( textLabel3 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    layout12->addWidget( QCtrFechaIni );
    layout15->addLayout( layout12 );

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout12_2->addWidget( textLabel3_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    layout12_2->addWidget( QCtrFechaFin );
    layout15->addLayout( layout12_2 );

    ControladorReportesVentasExpendiosLayout->addLayout( layout15, 1, 0 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    QPBIniMuestreo = new QPushButton( this, "QPBIniMuestreo" );
    layout16->addWidget( QPBIniMuestreo );

    QPBDetenMuestreo = new QPushButton( this, "QPBDetenMuestreo" );
    layout16->addWidget( QPBDetenMuestreo );

    ControladorReportesVentasExpendiosLayout->addLayout( layout16, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ControladorReportesVentasExpendios::~ControladorReportesVentasExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ControladorReportesVentasExpendios::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Expendios" ) );
    QTExpendios->horizontalHeader()->setLabel( 0, tr( "Expendio" ) );
    QTExpendios->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    textLabel2->setText( tr( "Tiempo Consulta" ) );
    QLEPeriodo->setText( tr( "180" ) );
    textLabel3->setText( tr( "Fecha Inicio" ) );
    textLabel3_2->setText( tr( "Fecha Fin" ) );
    QPBIniMuestreo->setText( tr( "Iniciar Muestreo" ) );
    QPBDetenMuestreo->setText( tr( "Detener Muestreo" ) );
}

