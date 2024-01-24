/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaPago.ui'
**
** Created: Thu Dec 21 12:53:28 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaPago.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaPago as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaPago::CapturaPago( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaPago" );
    CapturaPagoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaPagoLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout4->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout4->addWidget( QPBCancelar );

    CapturaPagoLayout->addLayout( layout4, 2, 0 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QLERecibo = new QLineEdit( this, "QLERecibo" );
    layout1->addWidget( QLERecibo );

    CapturaPagoLayout->addLayout( layout1, 0, 0 );

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QLCDNImporte = new QLCDNumber( this, "QLCDNImporte" );
    QLCDNImporte->setNumDigits( 8 );
    QLCDNImporte->setProperty( "value", 0 );
    layout2->addWidget( QLCDNImporte );
    layout11->addLayout( layout2 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( textLabel2_2 );

    QLCDNCambio = new QLCDNumber( this, "QLCDNCambio" );
    QLCDNCambio->setNumDigits( 8 );
    layout2_2->addWidget( QLCDNCambio );
    layout11->addLayout( layout2_2 );

    CapturaPagoLayout->addLayout( layout11, 1, 0 );
    languageChange();
    resize( QSize(250, 201).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaPago::~CapturaPago()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaPago::languageChange()
{
    setCaption( tr( "Pago Cliente" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Recibo" ) );
    textLabel2->setText( tr( "Importe" ) );
    textLabel2_2->setText( tr( "Cambio" ) );
}

