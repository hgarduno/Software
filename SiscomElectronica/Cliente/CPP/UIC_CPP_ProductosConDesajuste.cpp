/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductosConDesajuste.ui'
**
** Created: Wed Jan 31 10:48:09 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductosConDesajuste.h"

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
 *  Constructs a ProductosConDesajuste as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ProductosConDesajuste::ProductosConDesajuste( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ProductosConDesajuste" );
    ProductosConDesajusteLayout = new QGridLayout( this, 1, 1, 11, 6, "ProductosConDesajusteLayout"); 

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout22->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout22->addWidget( QPBCancelar );

    ProductosConDesajusteLayout->addLayout( layout22, 1, 0 );

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout23->addWidget( textLabel2 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha Registro" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Ultima Compra" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    layout23->addWidget( QTDatos );

    ProductosConDesajusteLayout->addLayout( layout23, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductosConDesajuste::~ProductosConDesajuste()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductosConDesajuste::languageChange()
{
    setCaption( tr( "Productos Con Desajuste" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel2->setText( tr( "Productos Con Desajuste" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Fecha Registro" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Ultima Compra" ) );
}

