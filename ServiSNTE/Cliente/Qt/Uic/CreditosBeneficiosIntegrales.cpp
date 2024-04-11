/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CreditosBeneficiosIntegrales.ui'
**
** Created: Thu Apr 11 21:07:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CreditosBeneficiosIntegrales.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CreditosBeneficiosIntegrales as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CreditosBeneficiosIntegrales::CreditosBeneficiosIntegrales( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CreditosBeneficiosIntegrales" );
    CreditosBeneficiosIntegralesLayout = new QGridLayout( this, 1, 1, 11, 6, "CreditosBeneficiosIntegralesLayout"); 

    layout48 = new QHBoxLayout( 0, 0, 6, "layout48"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout48->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout48->addWidget( QPBCancelar );

    CreditosBeneficiosIntegralesLayout->addLayout( layout48, 1, 0 );

    layout49 = new QVBoxLayout( 0, 0, 6, "layout49"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout49->addWidget( textLabel1 );

    QTCreditos = new QTable( this, "QTCreditos" );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "T. Factura" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "Pago Total" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "P. Quincenal" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "Plazo" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "% Tasa" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "Cliente" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "RFC" ) );
    QTCreditos->setNumRows( 0 );
    QTCreditos->setNumCols( 7 );
    QTCreditos->setReadOnly( TRUE );
    layout49->addWidget( QTCreditos );

    CreditosBeneficiosIntegralesLayout->addLayout( layout49, 0, 0 );
    languageChange();
    resize( QSize(856, 365).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CreditosBeneficiosIntegrales::~CreditosBeneficiosIntegrales()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CreditosBeneficiosIntegrales::languageChange()
{
    setCaption( tr( "Form1" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Creditos" ) );
    QTCreditos->horizontalHeader()->setLabel( 0, tr( "T. Factura" ) );
    QTCreditos->horizontalHeader()->setLabel( 1, tr( "Pago Total" ) );
    QTCreditos->horizontalHeader()->setLabel( 2, tr( "P. Quincenal" ) );
    QTCreditos->horizontalHeader()->setLabel( 3, tr( "Plazo" ) );
    QTCreditos->horizontalHeader()->setLabel( 4, tr( "% Tasa" ) );
    QTCreditos->horizontalHeader()->setLabel( 5, tr( "Cliente" ) );
    QTCreditos->horizontalHeader()->setLabel( 6, tr( "RFC" ) );
}

