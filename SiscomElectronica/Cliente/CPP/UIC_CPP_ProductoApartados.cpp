/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductoApartados.ui'
**
** Created: lun abr 1 18:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductoApartados.h"

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
 *  Constructs a ProductoApartados as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ProductoApartados::ProductoApartados( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ProductoApartados" );
    ProductoApartadosLayout = new QGridLayout( this, 1, 1, 11, 6, "ProductoApartadosLayout"); 

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout8->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout8->addWidget( QPBCancelar );

    ProductoApartadosLayout->addLayout( layout8, 1, 0 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout9->addWidget( textLabel1 );

    QTApartados = new QTable( this, "QTApartados" );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Fecha Ent" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Hora Ent." ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Cliente" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Cantidad" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "P. Venta" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Importe" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "A Cuenta" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Por Pagar" ) );
    QTApartados->setNumRows( 0 );
    QTApartados->setNumCols( 8 );
    layout9->addWidget( QTApartados );

    ProductoApartadosLayout->addLayout( layout9, 0, 0 );
    languageChange();
    resize( QSize(876, 386).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductoApartados::~ProductoApartados()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductoApartados::languageChange()
{
    setCaption( tr( "Producto En Apartados" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Producto En Apartados" ) );
    QTApartados->horizontalHeader()->setLabel( 0, tr( "Fecha Ent" ) );
    QTApartados->horizontalHeader()->setLabel( 1, tr( "Hora Ent." ) );
    QTApartados->horizontalHeader()->setLabel( 2, tr( "Cliente" ) );
    QTApartados->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTApartados->horizontalHeader()->setLabel( 4, tr( "P. Venta" ) );
    QTApartados->horizontalHeader()->setLabel( 5, tr( "Importe" ) );
    QTApartados->horizontalHeader()->setLabel( 6, tr( "A Cuenta" ) );
    QTApartados->horizontalHeader()->setLabel( 7, tr( "Por Pagar" ) );
}

