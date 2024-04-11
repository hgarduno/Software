/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaDescuentos.ui'
**
** Created: Thu Apr 11 21:07:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaDescuentos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDescuentos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDescuentos::CapturaDescuentos( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDescuentos" );
    CapturaDescuentosLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDescuentosLayout"); 

    layout34 = new QVBoxLayout( 0, 0, 6, "layout34"); 

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    layout28 = new QVBoxLayout( 0, 0, 6, "layout28"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout28->addWidget( textLabel1 );

    QLEDescuento1 = new QLineEdit( this, "QLEDescuento1" );
    layout28->addWidget( QLEDescuento1 );
    layout33->addLayout( layout28 );

    layout28_2 = new QVBoxLayout( 0, 0, 6, "layout28_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout28_2->addWidget( textLabel1_2 );

    QLEDescuento2 = new QLineEdit( this, "QLEDescuento2" );
    layout28_2->addWidget( QLEDescuento2 );
    layout33->addLayout( layout28_2 );

    layout28_3 = new QVBoxLayout( 0, 0, 6, "layout28_3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout28_3->addWidget( textLabel1_3 );

    QLEDescuento3 = new QLineEdit( this, "QLEDescuento3" );
    layout28_3->addWidget( QLEDescuento3 );
    layout33->addLayout( layout28_3 );

    layout28_2_2 = new QVBoxLayout( 0, 0, 6, "layout28_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout28_2_2->addWidget( textLabel1_2_2 );

    QLEDescuento4 = new QLineEdit( this, "QLEDescuento4" );
    layout28_2_2->addWidget( QLEDescuento4 );
    layout33->addLayout( layout28_2_2 );
    layout34->addLayout( layout33 );

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout32->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout32->addWidget( QPBCancelar );
    layout34->addLayout( layout32 );

    CapturaDescuentosLayout->addLayout( layout34, 0, 0 );
    languageChange();
    resize( QSize(600, 101).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDescuentos::~CapturaDescuentos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDescuentos::languageChange()
{
    setCaption( tr( "Capturando Descuentos" ) );
    textLabel1->setText( tr( "Descuento 1" ) );
    textLabel1_2->setText( tr( "Descuento 1" ) );
    textLabel1_3->setText( tr( "Descuento 1" ) );
    textLabel1_2_2->setText( tr( "Descuento 1" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

