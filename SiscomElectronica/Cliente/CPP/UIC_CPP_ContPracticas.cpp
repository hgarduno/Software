/****************************************************************************
** Form implementation generated from reading ui file 'UI/ContPracticas.ui'
**
** Created: Thu Dec 21 13:56:06 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ContPracticas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ContPracticas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ContPracticas::ContPracticas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ContPracticas" );
    ContPracticasLayout = new QGridLayout( this, 1, 1, 11, 6, "ContPracticasLayout"); 

    QPBConMaterias = new QPushButton( this, "QPBConMaterias" );
    QPBConMaterias->setMinimumSize( QSize( 200, 100 ) );

    ContPracticasLayout->addWidget( QPBConMaterias, 0, 1 );

    QPBContPracticas = new QPushButton( this, "QPBContPracticas" );
    QPBContPracticas->setMinimumSize( QSize( 200, 100 ) );

    ContPracticasLayout->addWidget( QPBContPracticas, 1, 0 );

    QPBMatPracticas = new QPushButton( this, "QPBMatPracticas" );
    QPBMatPracticas->setMinimumSize( QSize( 200, 100 ) );

    ContPracticasLayout->addWidget( QPBMatPracticas, 1, 1 );

    QPBCEscuelas = new QPushButton( this, "QPBCEscuelas" );
    QPBCEscuelas->setMinimumSize( QSize( 200, 100 ) );

    ContPracticasLayout->addWidget( QPBCEscuelas, 0, 0 );

    pushButton21_3_2 = new QPushButton( this, "pushButton21_3_2" );
    pushButton21_3_2->setMinimumSize( QSize( 200, 100 ) );

    ContPracticasLayout->addWidget( pushButton21_3_2, 2, 0 );

    pushButton21_3_2_2 = new QPushButton( this, "pushButton21_3_2_2" );
    pushButton21_3_2_2->setMinimumSize( QSize( 200, 100 ) );

    ContPracticasLayout->addWidget( pushButton21_3_2_2, 2, 1 );
    languageChange();
    resize( QSize(600, 348).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ContPracticas::~ContPracticas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ContPracticas::languageChange()
{
    setCaption( tr( "Controlador De Practicas" ) );
    QPBConMaterias->setText( tr( "Controlador \n"
"De\n"
"Materias" ) );
    QPBContPracticas->setText( tr( "Controlador \n"
"De \n"
"Practicas" ) );
    QPBMatPracticas->setText( tr( "Material\n"
"A La\n"
"Practica" ) );
    QPBCEscuelas->setText( tr( "Controlador \n"
"De\n"
"Escuelas" ) );
    pushButton21_3_2->setText( tr( "pushButton21" ) );
    pushButton21_3_2_2->setText( tr( "pushButton21" ) );
}

