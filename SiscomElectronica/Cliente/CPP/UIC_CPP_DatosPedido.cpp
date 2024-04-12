/****************************************************************************
** Form implementation generated from reading ui file 'UI/DatosPedido.ui'
**
** Created: Thu Apr 11 21:39:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DatosPedido.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QCtrlFechaHora.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFechaHora.h"

/*
 *  Constructs a DatosPedido as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DatosPedido::DatosPedido( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "DatosPedido" );
    DatosPedidoLayout = new QGridLayout( this, 1, 1, 11, 6, "DatosPedidoLayout"); 

    layout37 = new QVBoxLayout( 0, 0, 6, "layout37"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout36->addWidget( textLabel1_2 );

    QLEPEntrega = new QLineEdit( this, "QLEPEntrega" );
    QLEPEntrega->setReadOnly( TRUE );
    layout36->addWidget( QLEPEntrega );
    layout37->addLayout( layout36 );

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    layout38 = new QVBoxLayout( 0, 0, 6, "layout38"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout38->addWidget( textLabel1 );

    QCtrFechaHora = new QCtrlFechaHora( this, "QCtrFechaHora" );
    QCtrFechaHora->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaHora->sizePolicy().hasHeightForWidth() ) );
    layout38->addWidget( QCtrFechaHora );
    layout35->addLayout( layout38 );

    layout39 = new QVBoxLayout( 0, 0, 6, "layout39"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout39->addWidget( textLabel2 );

    QLEPagaCon = new QLineEdit( this, "QLEPagaCon" );
    QLEPagaCon->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPagaCon->sizePolicy().hasHeightForWidth() ) );
    layout39->addWidget( QLEPagaCon );
    layout35->addLayout( layout39 );

    layout39_2 = new QVBoxLayout( 0, 0, 6, "layout39_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout39_2->addWidget( textLabel2_2 );

    QLECambio = new QLineEdit( this, "QLECambio" );
    QLECambio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECambio->sizePolicy().hasHeightForWidth() ) );
    QLECambio->setReadOnly( TRUE );
    layout39_2->addWidget( QLECambio );
    layout35->addLayout( layout39_2 );
    layout37->addLayout( layout35 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout42->addWidget( textLabel3 );

    QTEObservaciones = new QTextEdit( this, "QTEObservaciones" );
    layout42->addWidget( QTEObservaciones );
    layout37->addLayout( layout42 );

    layout43 = new QHBoxLayout( 0, 0, 6, "layout43"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout43->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setEnabled( TRUE );
    QPBCancelar->setAutoDefault( FALSE );
    layout43->addWidget( QPBCancelar );
    layout37->addLayout( layout43 );

    DatosPedidoLayout->addLayout( layout37, 0, 0 );
    languageChange();
    resize( QSize(408, 301).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DatosPedido::~DatosPedido()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DatosPedido::languageChange()
{
    setCaption( tr( "Datos del pedido" ) );
    textLabel1_2->setText( tr( "Punto de entrega" ) );
    textLabel1->setText( tr( "Fecha Hora Entrega" ) );
    textLabel2->setText( tr( "Se Paga Con" ) );
    textLabel2_2->setText( tr( "Cambio" ) );
    textLabel3->setText( tr( "Observaciones" ) );
    QPBAceptar->setText( tr( "&Aceptar" ) );
    QPBAceptar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QPBCancelar->setText( tr( "&Cancelar" ) );
    QPBCancelar->setAccel( QKeySequence( tr( "Alt+C" ) ) );
}

