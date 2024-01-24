/****************************************************************************
** Form implementation generated from reading ui file 'UI/ComoPago.ui'
**
** Created: Thu Dec 21 12:53:47 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ComoPago.h"

#include <qvariant.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ComoPago as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ComoPago::ComoPago( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ComoPago" );
    ComoPagoLayout = new QGridLayout( this, 1, 1, 11, 6, "ComoPagoLayout"); 

    QBGComoPago = new QButtonGroup( this, "QBGComoPago" );

    QREfectivo = new QRadioButton( QBGComoPago, "QREfectivo" );
    QREfectivo->setGeometry( QRect( 10, 10, 82, 20 ) );

    QRTransferencia = new QRadioButton( QBGComoPago, "QRTransferencia" );
    QRTransferencia->setGeometry( QRect( 10, 30, 82, 20 ) );

    QRTarjeta = new QRadioButton( QBGComoPago, "QRTarjeta" );
    QRTarjeta->setGeometry( QRect( 10, 50, 82, 20 ) );
    QBGComoPago->insert( QRTarjeta, 2 );

    ComoPagoLayout->addWidget( QBGComoPago, 0, 0 );

    layout43 = new QHBoxLayout( 0, 0, 6, "layout43"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout43->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout43->addWidget( QPBCancelar );

    ComoPagoLayout->addLayout( layout43, 1, 0 );
    languageChange();
    resize( QSize(252, 120).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ComoPago::~ComoPago()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ComoPago::languageChange()
{
    setCaption( tr( "Como Pago" ) );
    QBGComoPago->setTitle( tr( "Como Pago" ) );
    QREfectivo->setText( tr( "&Efectivo" ) );
    QREfectivo->setAccel( QKeySequence( tr( "Alt+E" ) ) );
    QRTransferencia->setText( tr( "&Transferencia" ) );
    QRTransferencia->setAccel( QKeySequence( tr( "Alt+T" ) ) );
    QRTarjeta->setText( tr( "Tar&jeta" ) );
    QRTarjeta->setAccel( QKeySequence( tr( "Alt+J" ) ) );
    QPBAceptar->setText( tr( "&Aceptar" ) );
    QPBAceptar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QPBCancelar->setText( tr( "Cancela&r" ) );
    QPBCancelar->setAccel( QKeySequence( tr( "Alt+R" ) ) );
}

