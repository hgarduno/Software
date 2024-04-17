/****************************************************************************
** Form implementation generated from reading ui file 'UI/SePagaOrdenImpreso.ui'
**
** Created: Fri Apr 12 21:26:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SePagaOrdenImpreso.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlcdnumber.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a SePagaOrdenImpreso as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SePagaOrdenImpreso::SePagaOrdenImpreso( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SePagaOrdenImpreso" );
    SePagaOrdenImpresoLayout = new QGridLayout( this, 1, 1, 11, 6, "SePagaOrdenImpresoLayout"); 

    layout85 = new QVBoxLayout( 0, 0, 6, "layout85"); 

    layout65 = new QVBoxLayout( 0, 0, 6, "layout65"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout65->addWidget( textLabel1_4 );

    QLCDNNImpresos = new QLCDNumber( this, "QLCDNNImpresos" );
    QLCDNNImpresos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLCDNNImpresos->sizePolicy().hasHeightForWidth() ) );
    layout65->addWidget( QLCDNNImpresos );
    layout85->addLayout( layout65 );

    layout65_2 = new QVBoxLayout( 0, 0, 6, "layout65_2"); 

    textLabel1_4_2 = new QLabel( this, "textLabel1_4_2" );
    textLabel1_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4_2->sizePolicy().hasHeightForWidth() ) );
    layout65_2->addWidget( textLabel1_4_2 );

    QLCDNumImporte = new QLCDNumber( this, "QLCDNumImporte" );
    QLCDNumImporte->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLCDNumImporte->sizePolicy().hasHeightForWidth() ) );
    QLCDNumImporte->setNumDigits( 8 );
    layout65_2->addWidget( QLCDNumImporte );
    layout85->addLayout( layout65_2 );

    SePagaOrdenImpresoLayout->addLayout( layout85, 0, 0 );

    layout86 = new QVBoxLayout( 0, 0, 6, "layout86"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout86->addWidget( textLabel2 );

    QLEAdelanto = new QLineEdit( this, "QLEAdelanto" );
    QLEAdelanto->setEnabled( FALSE );
    layout86->addWidget( QLEAdelanto );

    SePagaOrdenImpresoLayout->addLayout( layout86, 1, 0 );

    layout88 = new QHBoxLayout( 0, 0, 6, "layout88"); 

    QPBSePagaCompleto = new QPushButton( this, "QPBSePagaCompleto" );
    QPBSePagaCompleto->setAutoDefault( FALSE );
    layout88->addWidget( QPBSePagaCompleto );

    QPBSeDaAdelanto = new QPushButton( this, "QPBSeDaAdelanto" );
    QPBSeDaAdelanto->setDefault( TRUE );
    layout88->addWidget( QPBSeDaAdelanto );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout88->addWidget( QPBAceptar );

    SePagaOrdenImpresoLayout->addLayout( layout88, 2, 0 );
    languageChange();
    resize( QSize(401, 247).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SePagaOrdenImpreso::~SePagaOrdenImpreso()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SePagaOrdenImpreso::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_4->setText( tr( "Circuitos Impresos Orden" ) );
    textLabel1_4_2->setText( tr( "Importe" ) );
    textLabel2->setText( tr( "A Cuenta" ) );
    QLEAdelanto->setText( QString::null );
    QPBSePagaCompleto->setText( tr( "Se Paga Completo" ) );
    QPBSeDaAdelanto->setText( tr( "Se Deja A Cuenta" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
}

