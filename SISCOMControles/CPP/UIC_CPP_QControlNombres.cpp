/****************************************************************************
** Form implementation generated from reading ui file 'UI/QControlNombres.ui'
**
** Created: Fri Apr 12 21:24:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_QControlNombres.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a QControlNombres as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
QControlNombres::QControlNombres( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "QControlNombres" );
    QControlNombresLayout = new QGridLayout( this, 1, 1, 11, 6, "QControlNombresLayout"); 

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout1_2_2->addWidget( textLabel1_2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    QLEAMaterno->setMinimumSize( QSize( 120, 0 ) );
    layout1_2_2->addWidget( QLEAMaterno );

    QControlNombresLayout->addLayout( layout1_2_2, 0, 2 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    QLENombre->setMinimumSize( QSize( 120, 0 ) );
    layout1->addWidget( QLENombre );

    QControlNombresLayout->addLayout( layout1, 0, 0 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    QLEAPaterno->setMinimumSize( QSize( 120, 0 ) );
    layout1_2->addWidget( QLEAPaterno );

    QControlNombresLayout->addLayout( layout1_2, 0, 1 );
    languageChange();
    resize( QSize(486, 71).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
QControlNombres::~QControlNombres()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void QControlNombres::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_2_2->setText( tr( "Apellido Materno" ) );
    textLabel1->setText( tr( "Nombre" ) );
    textLabel1_2->setText( tr( "Apellido Paterno" ) );
}

