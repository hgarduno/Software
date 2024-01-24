/****************************************************************************
** Form implementation generated from reading ui file 'UI/NoAlcanzaProducto.ui'
**
** Created: Thu Dec 21 12:53:45 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_NoAlcanzaProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a NoAlcanzaProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
NoAlcanzaProducto::NoAlcanzaProducto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "NoAlcanzaProducto" );
    NoAlcanzaProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "NoAlcanzaProductoLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout1->addWidget( QPBAceptar );

    NoAlcanzaProductoLayout->addLayout( layout1, 1, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Expendio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Bodega" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );
    QTDatos->setReadOnly( TRUE );
    layout2->addWidget( QTDatos );

    NoAlcanzaProductoLayout->addLayout( layout2, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
NoAlcanzaProducto::~NoAlcanzaProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void NoAlcanzaProducto::languageChange()
{
    setCaption( tr( "Form1" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    textLabel1->setText( tr( "Productos" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Expendio" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Bodega" ) );
}

