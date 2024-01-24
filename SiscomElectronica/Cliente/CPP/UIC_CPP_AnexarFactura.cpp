/****************************************************************************
** Form implementation generated from reading ui file 'UI/AnexarFactura.ui'
**
** Created: Thu Dec 21 12:53:41 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AnexarFactura.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a AnexarFactura as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AnexarFactura::AnexarFactura( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "AnexarFactura" );
    AnexarFacturaLayout = new QGridLayout( this, 1, 1, 11, 6, "AnexarFacturaLayout"); 

    layout46 = new QVBoxLayout( 0, 0, 6, "layout46"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout46->addWidget( textLabel4 );

    QLENumFactura = new QLineEdit( this, "QLENumFactura" );
    layout46->addWidget( QLENumFactura );

    AnexarFacturaLayout->addLayout( layout46, 0, 0 );

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout47->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout47->addWidget( QPBCancelar );

    AnexarFacturaLayout->addLayout( layout47, 2, 0 );

    QTFacturas = new QTable( this, "QTFacturas" );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "# Factura" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Fecha" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Proveedor" ) );
    QTFacturas->setAcceptDrops( TRUE );
    QTFacturas->setDragAutoScroll( TRUE );
    QTFacturas->setNumRows( 0 );
    QTFacturas->setNumCols( 3 );
    QTFacturas->setReadOnly( TRUE );

    AnexarFacturaLayout->addWidget( QTFacturas, 1, 0 );
    languageChange();
    resize( QSize(594, 249).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AnexarFactura::~AnexarFactura()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AnexarFactura::languageChange()
{
    setCaption( tr( "Anexar Factura" ) );
    textLabel4->setText( tr( "Numero De Factura" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QTFacturas->horizontalHeader()->setLabel( 0, tr( "# Factura" ) );
    QTFacturas->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTFacturas->horizontalHeader()->setLabel( 2, tr( "Proveedor" ) );
}

