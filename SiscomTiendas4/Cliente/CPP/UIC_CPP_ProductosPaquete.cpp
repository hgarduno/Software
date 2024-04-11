/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductosPaquete.ui'
**
** Created: Thu Apr 11 20:30:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductosPaquete.h"

#include <qvariant.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ProductosPaquete as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ProductosPaquete::ProductosPaquete( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ProductosPaquete" );
    ProductosPaqueteLayout = new QGridLayout( this, 1, 1, 11, 6, "ProductosPaqueteLayout"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );

    ProductosPaqueteLayout->addWidget( QTDatos, 0, 0 );

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    layout1->addWidget( QPBAnexar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    layout1->addWidget( QPBEliminar );

    QPBCCantidad = new QPushButton( this, "QPBCCantidad" );
    layout1->addWidget( QPBCCantidad );

    ProductosPaqueteLayout->addLayout( layout1, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductosPaquete::~ProductosPaquete()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductosPaquete::languageChange()
{
    setCaption( tr( "Productos del Paquete" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBEliminar->setText( tr( "Eliminar Producto" ) );
    QPBCCantidad->setText( tr( "Cambiar Cantidad" ) );
}

