/****************************************************************************
** Form implementation generated from reading ui file 'UI/ReporteVentasCursos.ui'
**
** Created: Thu Dec 21 12:53:42 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ReporteVentasCursos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <QCtrlProgramacionCursos.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProgramacionCursos.h"

/*
 *  Constructs a ReporteVentasCursos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ReporteVentasCursos::ReporteVentasCursos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ReporteVentasCursos" );
    ReporteVentasCursosLayout = new QGridLayout( this, 1, 1, 11, 6, "ReporteVentasCursosLayout"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QLCDNVTotales = new QLCDNumber( this, "QLCDNVTotales" );
    QLCDNVTotales->setMinimumSize( QSize( 0, 80 ) );
    QLCDNVTotales->setNumDigits( 8 );
    layout2->addWidget( QLCDNVTotales );

    ReporteVentasCursosLayout->addLayout( layout2, 2, 0 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( textLabel2_2 );

    QLCDNPSiscom = new QLCDNumber( this, "QLCDNPSiscom" );
    QLCDNPSiscom->setNumDigits( 8 );
    QLCDNPSiscom->setMode( QLCDNumber::Dec );
    layout2_2->addWidget( QLCDNPSiscom );

    ReporteVentasCursosLayout->addLayout( layout2_2, 2, 1 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout4->addWidget( pushButton1 );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout4->addWidget( pushButton1_2 );

    ReporteVentasCursosLayout->addMultiCellLayout( layout4, 3, 3, 0, 1 );

    QTVentasCursos = new QTable( this, "QTVentasCursos" );
    QTVentasCursos->setNumCols( QTVentasCursos->numCols() + 1 );
    QTVentasCursos->horizontalHeader()->setLabel( QTVentasCursos->numCols() - 1, tr( "Curso" ) );
    QTVentasCursos->setNumCols( QTVentasCursos->numCols() + 1 );
    QTVentasCursos->horizontalHeader()->setLabel( QTVentasCursos->numCols() - 1, tr( "Cantidad" ) );
    QTVentasCursos->setNumCols( QTVentasCursos->numCols() + 1 );
    QTVentasCursos->horizontalHeader()->setLabel( QTVentasCursos->numCols() - 1, tr( "Precio" ) );
    QTVentasCursos->setNumCols( QTVentasCursos->numCols() + 1 );
    QTVentasCursos->horizontalHeader()->setLabel( QTVentasCursos->numCols() - 1, tr( "Importe" ) );
    QTVentasCursos->setNumRows( 0 );
    QTVentasCursos->setNumCols( 4 );
    QTVentasCursos->setReadOnly( TRUE );

    ReporteVentasCursosLayout->addMultiCellWidget( QTVentasCursos, 1, 1, 0, 1 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout5->addWidget( textLabel1 );

    QCtrProgramacionCursos = new QCtrlProgramacionCursos( this, "QCtrProgramacionCursos" );
    layout5->addWidget( QCtrProgramacionCursos );

    ReporteVentasCursosLayout->addMultiCellLayout( layout5, 0, 0, 0, 1 );
    languageChange();
    resize( QSize(613, 564).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReporteVentasCursos::~ReporteVentasCursos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReporteVentasCursos::languageChange()
{
    setCaption( tr( "Reportes De Ventas Cursos" ) );
    textLabel2->setText( tr( "Ventas Totales" ) );
    textLabel2_2->setText( tr( "Participacion Siscom" ) );
    pushButton1->setText( tr( "Ejecutar Reporte" ) );
    pushButton1_2->setText( tr( "pushButton1" ) );
    QTVentasCursos->horizontalHeader()->setLabel( 0, tr( "Curso" ) );
    QTVentasCursos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTVentasCursos->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTVentasCursos->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    textLabel1->setText( tr( "Programacion Cursos" ) );
}

