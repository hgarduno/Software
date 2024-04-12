/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistrarEntrega.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistrarEntrega.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RegistrarEntrega as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistrarEntrega::RegistrarEntrega( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistrarEntrega" );
    RegistrarEntregaLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistrarEntregaLayout"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout23->addWidget( textLabel5 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "No Pedido" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    layout23->addWidget( QTDatos );

    RegistrarEntregaLayout->addLayout( layout23, 1, 0 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout25->addWidget( textLabel6 );

    QTEComentario = new QTextEdit( this, "QTEComentario" );
    layout25->addWidget( QTEComentario );

    RegistrarEntregaLayout->addLayout( layout25, 2, 0 );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );

    RegistrarEntregaLayout->addWidget( QPBRegistra, 3, 0 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout4->addWidget( textLabel4 );

    RegistrarEntregaLayout->addLayout( layout4, 0, 0 );
    languageChange();
    resize( QSize(571, 544).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistrarEntrega::~RegistrarEntrega()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistrarEntrega::languageChange()
{
    setCaption( tr( "Registrar Entrega Del Pedido" ) );
    textLabel5->setText( tr( "Pedidos Del Cliente" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Importe" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "No Pedido" ) );
    textLabel6->setText( tr( "Comentario" ) );
    QPBRegistra->setText( tr( "Registrar Entrega" ) );
    textLabel4->setText( tr( "Clientes Registrados" ) );
}

