/****************************************************************************
** Form implementation generated from reading ui file 'UI/Pruebas.ui'
**
** Created: Mon May 24 15:01:06 2021
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Pruebas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Pruebas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Pruebas::Pruebas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Pruebas" );
    PruebasLayout = new QGridLayout( this, 1, 1, 11, 6, "PruebasLayout"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    layout1->addWidget( lineEdit1 );
    layout3->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    lineEdit2 = new QLineEdit( this, "lineEdit2" );
    layout2->addWidget( lineEdit2 );
    layout3->addLayout( layout2 );

    PruebasLayout->addLayout( layout3, 0, 0 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout4->addWidget( textLabel3 );

    table1 = new QTable( this, "table1" );
    table1->setNumRows( 3 );
    table1->setNumCols( 3 );
    layout4->addWidget( table1 );

    PruebasLayout->addLayout( layout4, 1, 0 );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout5->addWidget( pushButton1 );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout5->addWidget( pushButton1_2 );

    pushButton1_3 = new QPushButton( this, "pushButton1_3" );
    layout5->addWidget( pushButton1_3 );

    PruebasLayout->addLayout( layout5, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Pruebas::~Pruebas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Pruebas::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "textLabel1" ) );
    textLabel2->setText( tr( "textLabel2" ) );
    textLabel3->setText( tr( "textLabel3" ) );
    pushButton1->setText( tr( "pushButton1" ) );
    pushButton1_2->setText( tr( "pushButton1" ) );
    pushButton1_3->setText( tr( "pushButton1" ) );
}

