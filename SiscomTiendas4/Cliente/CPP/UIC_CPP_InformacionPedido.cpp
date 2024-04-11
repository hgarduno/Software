/****************************************************************************
** Form implementation generated from reading ui file 'UI/InformacionPedido.ui'
**
** Created: Thu Apr 11 20:30:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_InformacionPedido.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a InformacionPedido as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
InformacionPedido::InformacionPedido( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "InformacionPedido" );
    InformacionPedidoLayout = new QGridLayout( this, 1, 1, 11, 6, "InformacionPedidoLayout"); 

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setAutoDefault( FALSE );

    InformacionPedidoLayout->addWidget( QPBRegistra, 3, 0 );

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout18->addWidget( textLabel1 );

    QTEComentarios = new QTextEdit( this, "QTEComentarios" );
    layout18->addWidget( QTEComentarios );

    InformacionPedidoLayout->addLayout( layout18, 1, 0 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout19->addWidget( textLabel3 );

    QLENoPedido = new QLineEdit( this, "QLENoPedido" );
    QLENoPedido->setReadOnly( TRUE );
    layout19->addWidget( QLENoPedido );
    layout20->addLayout( layout19 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout20->addItem( spacer1 );

    InformacionPedidoLayout->addLayout( layout20, 0, 0 );

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout21->addWidget( textLabel2 );

    table3 = new QTable( this, "table3" );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Calle" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Numero" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Municipio" ) );
    table3->setNumRows( 0 );
    table3->setNumCols( 3 );
    layout21->addWidget( table3 );

    InformacionPedidoLayout->addLayout( layout21, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
InformacionPedido::~InformacionPedido()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void InformacionPedido::languageChange()
{
    setCaption( tr( "Informacion Del Pedido" ) );
    QPBRegistra->setText( tr( "Registrar Pedido" ) );
    textLabel1->setText( tr( "Comentario Del Pedido" ) );
    textLabel3->setText( tr( "Numero De Pedido" ) );
    textLabel2->setText( tr( "Direccion De Envio" ) );
    table3->horizontalHeader()->setLabel( 0, tr( "Calle" ) );
    table3->horizontalHeader()->setLabel( 1, tr( "Numero" ) );
    table3->horizontalHeader()->setLabel( 2, tr( "Municipio" ) );
}

