/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaPesosPPunto.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaPesosPPunto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ActualizaPesosPPunto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActualizaPesosPPunto::ActualizaPesosPPunto( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActualizaPesosPPunto" );
    ActualizaPesosPPuntoLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaPesosPPuntoLayout"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel3 );

    QLEPesosPPunto = new QLineEdit( this, "QLEPesosPPunto" );
    QLEPesosPPunto->setReadOnly( TRUE );
    layout5->addWidget( QLEPesosPPunto );

    ActualizaPesosPPuntoLayout->addLayout( layout5, 0, 0 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2->addWidget( textLabel3_2 );

    QLEPesosPPuntoM = new QLineEdit( this, "QLEPesosPPuntoM" );
    layout5_2->addWidget( QLEPesosPPuntoM );

    ActualizaPesosPPuntoLayout->addLayout( layout5_2, 0, 1 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    pushButton6 = new QPushButton( this, "pushButton6" );
    layout22->addWidget( pushButton6 );

    pushButton7 = new QPushButton( this, "pushButton7" );
    layout22->addWidget( pushButton7 );

    ActualizaPesosPPuntoLayout->addMultiCellLayout( layout22, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(331, 94).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaPesosPPunto::~ActualizaPesosPPunto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaPesosPPunto::languageChange()
{
    setCaption( tr( "Actualiza Pesos Por Punto" ) );
    textLabel3->setText( tr( "Pesos Por Punto Actual" ) );
    textLabel3_2->setText( tr( "Pesos Por Punto" ) );
    pushButton6->setText( tr( "Actualiza" ) );
    pushButton7->setText( tr( "pushButton7" ) );
}

