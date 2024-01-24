/****************************************************************************
** Form implementation generated from reading ui file 'UI/CierreCaja.ui'
**
** Created: Thu Dec 21 12:53:45 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CierreCaja.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a CierreCaja as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CierreCaja::CierreCaja( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CierreCaja" );
    CierreCajaLayout = new QGridLayout( this, 1, 1, 11, 6, "CierreCajaLayout"); 

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout5->addWidget( textLabel1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, QString::null );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, QString::null );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, QString::null );
    table1->setNumRows( 0 );
    table1->setNumCols( 3 );
    layout2->addWidget( table1 );

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout1->addItem( spacer1 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    layout1->addWidget( lineEdit1 );
    layout2->addLayout( layout1 );
    layout5->addLayout( layout2 );
    layout10->addLayout( layout5 );

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout6_2->addWidget( textLabel2_2 );

    layout2_2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2_2"); 

    table1_2_2 = new QTable( this, "table1_2_2" );
    table1_2_2->setNumCols( table1_2_2->numCols() + 1 );
    table1_2_2->horizontalHeader()->setLabel( table1_2_2->numCols() - 1, QString::null );
    table1_2_2->setNumCols( table1_2_2->numCols() + 1 );
    table1_2_2->horizontalHeader()->setLabel( table1_2_2->numCols() - 1, QString::null );
    table1_2_2->setNumCols( table1_2_2->numCols() + 1 );
    table1_2_2->horizontalHeader()->setLabel( table1_2_2->numCols() - 1, QString::null );
    table1_2_2->setNumRows( 0 );
    table1_2_2->setNumCols( 3 );
    layout2_2_2->addWidget( table1_2_2 );

    layout1_2_2 = new QHBoxLayout( 0, 0, 6, "layout1_2_2"); 
    spacer1_2_2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout1_2_2->addItem( spacer1_2_2 );

    lineEdit1_2_2 = new QLineEdit( this, "lineEdit1_2_2" );
    layout1_2_2->addWidget( lineEdit1_2_2 );
    layout2_2_2->addLayout( layout1_2_2 );
    layout6_2->addLayout( layout2_2_2 );
    layout10->addLayout( layout6_2 );

    CierreCajaLayout->addLayout( layout10, 0, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout6->addWidget( textLabel2 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    table1_2 = new QTable( this, "table1_2" );
    table1_2->setNumCols( table1_2->numCols() + 1 );
    table1_2->horizontalHeader()->setLabel( table1_2->numCols() - 1, QString::null );
    table1_2->setNumCols( table1_2->numCols() + 1 );
    table1_2->horizontalHeader()->setLabel( table1_2->numCols() - 1, QString::null );
    table1_2->setNumCols( table1_2->numCols() + 1 );
    table1_2->horizontalHeader()->setLabel( table1_2->numCols() - 1, QString::null );
    table1_2->setNumRows( 0 );
    table1_2->setNumCols( 3 );
    layout2_2->addWidget( table1_2 );

    layout1_2 = new QHBoxLayout( 0, 0, 6, "layout1_2"); 
    spacer1_2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout1_2->addItem( spacer1_2 );

    lineEdit1_2 = new QLineEdit( this, "lineEdit1_2" );
    layout1_2->addWidget( lineEdit1_2 );
    layout2_2->addLayout( layout1_2 );
    layout6->addLayout( layout2_2 );

    CierreCajaLayout->addLayout( layout6, 1, 0 );

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout11->addWidget( pushButton1 );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout11->addWidget( pushButton1_2 );

    CierreCajaLayout->addLayout( layout11, 2, 0 );
    languageChange();
    resize( QSize(736, 659).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CierreCaja::~CierreCaja()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CierreCaja::languageChange()
{
    setCaption( tr( "Cierre Caja" ) );
    textLabel1->setText( tr( "Efectivo en Caja" ) );
    table1->horizontalHeader()->setLabel( 0, QString::null );
    table1->horizontalHeader()->setLabel( 1, QString::null );
    table1->horizontalHeader()->setLabel( 2, QString::null );
    textLabel2_2->setText( tr( "Total En Bolsa" ) );
    table1_2_2->horizontalHeader()->setLabel( 0, QString::null );
    table1_2_2->horizontalHeader()->setLabel( 1, QString::null );
    table1_2_2->horizontalHeader()->setLabel( 2, QString::null );
    textLabel2->setText( tr( "Cambio" ) );
    table1_2->horizontalHeader()->setLabel( 0, QString::null );
    table1_2->horizontalHeader()->setLabel( 1, QString::null );
    table1_2->horizontalHeader()->setLabel( 2, QString::null );
    pushButton1->setText( tr( "Registrar Cierre" ) );
    pushButton1_2->setText( tr( "Imprime Ticket Cierre" ) );
}

