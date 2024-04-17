/****************************************************************************
** Form implementation generated from reading ui file 'UI/GastosExpendio.ui'
**
** Created: Fri Apr 12 21:26:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_GastosExpendio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlGastosSE.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlGastosSE.h"

/*
 *  Constructs a GastosExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
GastosExpendio::GastosExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "GastosExpendio" );
    GastosExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "GastosExpendioLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrGastos = new QCtrlGastosSE( this, "QCtrGastos" );
    layout1->addWidget( QCtrGastos );

    GastosExpendioLayout->addLayout( layout1, 0, 0 );

    pushButton1 = new QPushButton( this, "pushButton1" );

    GastosExpendioLayout->addWidget( pushButton1, 2, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Fecha" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Gasto" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Observaciones" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Importe" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 4 );
    layout2->addWidget( table1 );

    GastosExpendioLayout->addLayout( layout2, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
GastosExpendio::~GastosExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void GastosExpendio::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Gasto" ) );
    pushButton1->setText( tr( "pushButton1" ) );
    textLabel2->setText( tr( "Gastos" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Gasto" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "Observaciones" ) );
    table1->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
}

