/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaObservacionPedidoProducto.ui'
**
** Created: Wed Jan 31 10:48:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaObservacionPedidoProducto.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaObservacionPedidoProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaObservacionPedidoProducto::CapturaObservacionPedidoProducto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaObservacionPedidoProducto" );
    CapturaObservacionPedidoProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaObservacionPedidoProductoLayout"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout10->addWidget( textLabel1 );

    QTEObservaciones = new QTextEdit( this, "QTEObservaciones" );
    layout10->addWidget( QTEObservaciones );

    CapturaObservacionPedidoProductoLayout->addMultiCellLayout( layout10, 0, 0, 0, 1 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );

    CapturaObservacionPedidoProductoLayout->addWidget( QPBAceptar, 1, 0 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );

    CapturaObservacionPedidoProductoLayout->addWidget( QPBCancelar, 1, 1 );
    languageChange();
    resize( QSize(453, 164).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaObservacionPedidoProducto::~CapturaObservacionPedidoProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaObservacionPedidoProducto::languageChange()
{
    setCaption( tr( "Capturando Observaciones" ) );
    textLabel1->setText( tr( "Observaciones" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

