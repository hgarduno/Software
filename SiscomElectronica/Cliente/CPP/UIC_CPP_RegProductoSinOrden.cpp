/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegProductoSinOrden.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegProductoSinOrden.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <QCtrlProdSiscomElectronica.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProdSiscomElectronica.h"

/*
 *  Constructs a RegProductoSinOrden as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RegProductoSinOrden::RegProductoSinOrden( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RegProductoSinOrden" );
    RegProductoSinOrdenLayout = new QGridLayout( this, 1, 1, 11, 6, "RegProductoSinOrdenLayout"); 

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout18->addWidget( textLabel3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout18->addWidget( QTEDescripcion );

    RegProductoSinOrdenLayout->addMultiCellLayout( layout18, 0, 3, 1, 1 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout14->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProdSiscomElectronica( this, "QCtrProductos" );
    layout14->addWidget( QCtrProductos );

    RegProductoSinOrdenLayout->addLayout( layout14, 0, 0 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout15->addWidget( textLabel4 );

    QLEProducto = new QLineEdit( this, "QLEProducto" );
    layout15->addWidget( QLEProducto );

    RegProductoSinOrdenLayout->addLayout( layout15, 1, 0 );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout23->addWidget( QPBRegistrar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout23->addWidget( QPBCancelar );

    RegProductoSinOrdenLayout->addLayout( layout23, 3, 0 );
    spacer1 = new QSpacerItem( 20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding );
    RegProductoSinOrdenLayout->addItem( spacer1, 2, 0 );
    languageChange();
    resize( QSize(484, 169).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegProductoSinOrden::~RegProductoSinOrden()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegProductoSinOrden::languageChange()
{
    setCaption( tr( "Productos Sin Orden" ) );
    textLabel3->setText( tr( "Descripcion" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel4->setText( tr( "Producto A Registrar" ) );
    QPBRegistrar->setText( tr( "Registrar Producto" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

