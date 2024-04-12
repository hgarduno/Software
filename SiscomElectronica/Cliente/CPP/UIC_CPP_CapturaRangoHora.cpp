/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaRangoHora.ui'
**
** Created: Thu Apr 11 21:39:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaRangoHora.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaRangoHora as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaRangoHora::CapturaRangoHora( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaRangoHora" );
    CapturaRangoHoraLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaRangoHoraLayout"); 

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel1 );

    QLEHoraInicio = new QLineEdit( this, "QLEHoraInicio" );
    layout10->addWidget( QLEHoraInicio );
    layout12->addLayout( layout10 );

    layout10_2 = new QVBoxLayout( 0, 0, 6, "layout10_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout10_2->addWidget( textLabel1_2 );

    QLEHoraFin = new QLineEdit( this, "QLEHoraFin" );
    layout10_2->addWidget( QLEHoraFin );
    layout12->addLayout( layout10_2 );

    CapturaRangoHoraLayout->addLayout( layout12, 0, 0 );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout13->addWidget( QPBAceptar );

    pushButton6_2 = new QPushButton( this, "pushButton6_2" );
    pushButton6_2->setAutoDefault( FALSE );
    layout13->addWidget( pushButton6_2 );

    CapturaRangoHoraLayout->addLayout( layout13, 1, 0 );
    languageChange();
    resize( QSize(205, 90).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaRangoHora::~CapturaRangoHora()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaRangoHora::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Hora Inicio" ) );
    QLEHoraInicio->setInputMask( tr( "##:## ; " ) );
    textLabel1_2->setText( tr( "Hora Fin" ) );
    QLEHoraFin->setInputMask( tr( "##:## ; " ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    pushButton6_2->setText( tr( "pushButton6" ) );
}

