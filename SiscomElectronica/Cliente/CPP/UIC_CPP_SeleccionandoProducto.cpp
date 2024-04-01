/****************************************************************************
** Form implementation generated from reading ui file 'UI/SeleccionandoProducto.ui'
**
** Created: Wed Jan 31 10:48:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SeleccionandoProducto.h"

#include <qvariant.h>
#include <qlabel.h>
#include <QCtrlProductosSE.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"

/*
 *  Constructs a SeleccionandoProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SeleccionandoProducto::SeleccionandoProducto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SeleccionandoProducto" );
    SeleccionandoProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "SeleccionandoProductoLayout"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout22->addWidget( textLabel5 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    layout22->addWidget( QCtrProductos );

    SeleccionandoProductoLayout->addLayout( layout22, 0, 0 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setReadOnly( TRUE );

    SeleccionandoProductoLayout->addWidget( QTEDescripcion, 1, 0 );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout23->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout23->addWidget( QPBCancelar );

    SeleccionandoProductoLayout->addLayout( layout23, 2, 0 );
    languageChange();
    resize( QSize(542, 223).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SeleccionandoProducto::~SeleccionandoProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SeleccionandoProducto::languageChange()
{
    setCaption( tr( "Seleccionando Producto" ) );
    textLabel5->setText( tr( "Producto" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

