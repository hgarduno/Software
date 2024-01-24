/****************************************************************************
** Form implementation generated from reading ui file 'UI/ListaPuntosEntrega.ui'
**
** Created: Thu Dec 21 12:53:46 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ListaPuntosEntrega.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ListaPuntosEntrega as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ListaPuntosEntrega::ListaPuntosEntrega( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ListaPuntosEntrega" );
    ListaPuntosEntregaLayout = new QGridLayout( this, 1, 1, 11, 6, "ListaPuntosEntregaLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout1->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout1->addWidget( QPBCancelar );

    ListaPuntosEntregaLayout->addLayout( layout1, 1, 0 );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout3->addWidget( textLabel1 );

    QTPuntosEntrega = new QTable( this, "QTPuntosEntrega" );
    QTPuntosEntrega->setNumCols( QTPuntosEntrega->numCols() + 1 );
    QTPuntosEntrega->horizontalHeader()->setLabel( QTPuntosEntrega->numCols() - 1, tr( "Punto de Entrega" ) );
    QTPuntosEntrega->setNumCols( QTPuntosEntrega->numCols() + 1 );
    QTPuntosEntrega->horizontalHeader()->setLabel( QTPuntosEntrega->numCols() - 1, tr( "Direccion" ) );
    QTPuntosEntrega->setNumRows( 0 );
    QTPuntosEntrega->setNumCols( 2 );
    layout3->addWidget( QTPuntosEntrega );
    layout5->addLayout( layout3 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    QTEReferencias = new QTextEdit( this, "QTEReferencias" );
    QTEReferencias->setReadOnly( TRUE );
    layout4->addWidget( QTEReferencias );
    layout5->addLayout( layout4 );

    ListaPuntosEntregaLayout->addLayout( layout5, 0, 0 );
    languageChange();
    resize( QSize(745, 393).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ListaPuntosEntrega::~ListaPuntosEntrega()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ListaPuntosEntrega::languageChange()
{
    setCaption( tr( "Puntos de entrega" ) );
    QPBAceptar->setText( tr( "&Aceptar" ) );
    QPBAceptar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QPBCancelar->setText( tr( "&Cancelar" ) );
    QPBCancelar->setAccel( QKeySequence( tr( "Alt+C" ) ) );
    textLabel1->setText( tr( "Puntos de Entrega Siscom" ) );
    QTPuntosEntrega->horizontalHeader()->setLabel( 0, tr( "Punto de Entrega" ) );
    QTPuntosEntrega->horizontalHeader()->setLabel( 1, tr( "Direccion" ) );
    textLabel2->setText( tr( "Referencias" ) );
}

