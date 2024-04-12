/****************************************************************************
** Form implementation generated from reading ui file 'UI/SueldosEmpleados.ui'
**
** Created: Thu Apr 11 21:39:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SueldosEmpleados.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlEmpleados.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlEmpleados.h"

/*
 *  Constructs a SueldosEmpleados as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SueldosEmpleados::SueldosEmpleados( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SueldosEmpleados" );
    SueldosEmpleadosLayout = new QGridLayout( this, 1, 1, 11, 6, "SueldosEmpleadosLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrEmpleados = new QCtrlEmpleados( this, "QCtrEmpleados" );
    layout1->addWidget( QCtrEmpleados );

    SueldosEmpleadosLayout->addLayout( layout1, 0, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    layout2->addWidget( lineEdit1 );
    layout4->addLayout( layout2 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout2_2->addWidget( textLabel2_2 );

    lineEdit1_2 = new QLineEdit( this, "lineEdit1_2" );
    layout2_2->addWidget( lineEdit1_2 );
    layout4->addLayout( layout2_2 );

    pushButton2 = new QPushButton( this, "pushButton2" );
    pushButton2->setMinimumSize( QSize( 0, 47 ) );
    layout4->addWidget( pushButton2 );

    SueldosEmpleadosLayout->addLayout( layout4, 1, 0 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout5->addWidget( textLabel3 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Fecha" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Pago" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 2 );
    layout5->addWidget( table1 );

    SueldosEmpleadosLayout->addLayout( layout5, 2, 0 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    QPBCambia = new QPushButton( this, "QPBCambia" );
    layout6->addWidget( QPBCambia );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout6->addWidget( pushButton1_2 );

    SueldosEmpleadosLayout->addLayout( layout6, 3, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SueldosEmpleados::~SueldosEmpleados()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SueldosEmpleados::languageChange()
{
    setCaption( tr( "Sueldos Empleados" ) );
    textLabel1->setText( tr( "Empleados" ) );
    textLabel2->setText( tr( "Fecha De Ingreso" ) );
    textLabel2_2->setText( tr( "Sueldo" ) );
    pushButton2->setText( tr( "Datos\n"
"Personales" ) );
    textLabel3->setText( tr( "Historial Pagos" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Pago" ) );
    QPBCambia->setText( tr( "Cambia Sueldo" ) );
    pushButton1_2->setText( tr( "Registra Pago" ) );
}

