/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/SeleccionaCredito.ui'
**
** Created: Thu Apr 11 21:07:23 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "SeleccionaCredito.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a SeleccionaCredito as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SeleccionaCredito::SeleccionaCredito( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SeleccionaCredito" );
    SeleccionaCreditoLayout = new QGridLayout( this, 1, 1, 11, 6, "SeleccionaCreditoLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    QLERFC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLERFC->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QLERFC );
    layout4->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLECliente = new QLineEdit( this, "QLECliente" );
    QLECliente->setReadOnly( TRUE );
    layout1_2->addWidget( QLECliente );
    layout4->addLayout( layout1_2 );

    SeleccionaCreditoLayout->addLayout( layout4, 0, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QTCreditos = new QTable( this, "QTCreditos" );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "Importe Credito" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "Total Compra" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "Pago Quincenal" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "Plazo" ) );
    QTCreditos->setNumCols( QTCreditos->numCols() + 1 );
    QTCreditos->horizontalHeader()->setLabel( QTCreditos->numCols() - 1, tr( "Numero Pagos" ) );
    QTCreditos->setNumRows( 0 );
    QTCreditos->setNumCols( 5 );
    QTCreditos->setReadOnly( TRUE );
    layout2->addWidget( QTCreditos );

    SeleccionaCreditoLayout->addLayout( layout2, 1, 0 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout6->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout6->addWidget( QPBCancelar );

    SeleccionaCreditoLayout->addLayout( layout6, 2, 0 );
    languageChange();
    resize( QSize(610, 532).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SeleccionaCredito::~SeleccionaCredito()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SeleccionaCredito::languageChange()
{
    setCaption( tr( "Abonos Apartado" ) );
    textLabel1->setText( tr( "RFC" ) );
    textLabel1_2->setText( tr( "Cliente" ) );
    textLabel2->setText( tr( "Apartados Cliente" ) );
    QTCreditos->horizontalHeader()->setLabel( 0, tr( "Importe Credito" ) );
    QTCreditos->horizontalHeader()->setLabel( 1, tr( "Total Compra" ) );
    QTCreditos->horizontalHeader()->setLabel( 2, tr( "Pago Quincenal" ) );
    QTCreditos->horizontalHeader()->setLabel( 3, tr( "Plazo" ) );
    QTCreditos->horizontalHeader()->setLabel( 4, tr( "Numero Pagos" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

