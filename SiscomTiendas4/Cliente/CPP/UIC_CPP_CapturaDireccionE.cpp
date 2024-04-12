/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaDireccionE.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaDireccionE.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDireccionE as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDireccionE::CapturaDireccionE( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDireccionE" );
    CapturaDireccionELayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDireccionELayout"); 

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout21->addWidget( textLabel5 );

    QLELinea1 = new QLineEdit( this, "QLELinea1" );
    layout21->addWidget( QLELinea1 );
    layout24->addLayout( layout21 );

    layout21_2 = new QVBoxLayout( 0, 0, 6, "layout21_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    layout21_2->addWidget( textLabel5_2 );

    QLELinea2 = new QLineEdit( this, "QLELinea2" );
    layout21_2->addWidget( QLELinea2 );
    layout24->addLayout( layout21_2 );

    layout21_3 = new QVBoxLayout( 0, 0, 6, "layout21_3"); 

    textLabel5_3 = new QLabel( this, "textLabel5_3" );
    layout21_3->addWidget( textLabel5_3 );

    QLELinea3 = new QLineEdit( this, "QLELinea3" );
    layout21_3->addWidget( QLELinea3 );
    layout24->addLayout( layout21_3 );

    CapturaDireccionELayout->addLayout( layout24, 0, 0 );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout25->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout25->addWidget( QPBCancelar );

    CapturaDireccionELayout->addLayout( layout25, 1, 0 );
    languageChange();
    resize( QSize(600, 196).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDireccionE::~CapturaDireccionE()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDireccionE::languageChange()
{
    setCaption( tr( "Form4" ) );
    textLabel5->setText( tr( "Linea 1" ) );
    textLabel5_2->setText( tr( "Linea 2" ) );
    textLabel5_3->setText( tr( "Linea 3" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

