/****************************************************************************
** Form implementation generated from reading ui file 'UI/ClientesRegistrados4.ui'
**
** Created: Fri Apr 12 21:26:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ClientesRegistrados4.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ClientesRegistrados4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ClientesRegistrados4::ClientesRegistrados4( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ClientesRegistrados4" );
    ClientesRegistrados4Layout = new QGridLayout( this, 1, 1, 11, 6, "ClientesRegistrados4Layout"); 

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout24->addWidget( textLabel1 );

    QTClientes = new QTable( this, "QTClientes" );
    QTClientes->setNumCols( QTClientes->numCols() + 1 );
    QTClientes->horizontalHeader()->setLabel( QTClientes->numCols() - 1, tr( "Nombre" ) );
    QTClientes->setNumCols( QTClientes->numCols() + 1 );
    QTClientes->horizontalHeader()->setLabel( QTClientes->numCols() - 1, tr( "Telefono" ) );
    QTClientes->setNumCols( QTClientes->numCols() + 1 );
    QTClientes->horizontalHeader()->setLabel( QTClientes->numCols() - 1, tr( "Correo" ) );
    QTClientes->setNumCols( QTClientes->numCols() + 1 );
    QTClientes->horizontalHeader()->setLabel( QTClientes->numCols() - 1, tr( "Escuela" ) );
    QTClientes->setNumCols( QTClientes->numCols() + 1 );
    QTClientes->horizontalHeader()->setLabel( QTClientes->numCols() - 1, tr( "Direccion" ) );
    QTClientes->setNumRows( 0 );
    QTClientes->setNumCols( 5 );
    QTClientes->setReadOnly( TRUE );
    layout24->addWidget( QTClientes );

    ClientesRegistrados4Layout->addLayout( layout24, 0, 0 );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout25->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout25->addWidget( QPBCancelar );

    ClientesRegistrados4Layout->addLayout( layout25, 1, 0 );
    languageChange();
    resize( QSize(732, 496).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ClientesRegistrados4::~ClientesRegistrados4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ClientesRegistrados4::languageChange()
{
    setCaption( tr( "Clientes Registrados" ) );
    textLabel1->setText( tr( "Clientes" ) );
    QTClientes->horizontalHeader()->setLabel( 0, tr( "Nombre" ) );
    QTClientes->horizontalHeader()->setLabel( 1, tr( "Telefono" ) );
    QTClientes->horizontalHeader()->setLabel( 2, tr( "Correo" ) );
    QTClientes->horizontalHeader()->setLabel( 3, tr( "Escuela" ) );
    QTClientes->horizontalHeader()->setLabel( 4, tr( "Direccion" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

