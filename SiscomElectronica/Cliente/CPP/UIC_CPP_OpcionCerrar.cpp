/****************************************************************************
** Form implementation generated from reading ui file 'UI/OpcionCerrar.ui'
**
** Created: Thu Dec 21 12:53:23 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OpcionCerrar.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a OpcionCerrar as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
OpcionCerrar::OpcionCerrar( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "OpcionCerrar" );
    OpcionCerrarLayout = new QGridLayout( this, 1, 1, 11, 6, "OpcionCerrarLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBRealizarVenta = new QPushButton( this, "QPBRealizarVenta" );
    layout1->addWidget( QPBRealizarVenta );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout1->addWidget( QPBCancelar );

    OpcionCerrarLayout->addLayout( layout1, 1, 0 );

    textLabel2 = new QLabel( this, "textLabel2" );

    OpcionCerrarLayout->addWidget( textLabel2, 0, 0 );
    languageChange();
    resize( QSize(562, 121).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OpcionCerrar::~OpcionCerrar()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OpcionCerrar::languageChange()
{
    setCaption( tr( "No Se Puede Cerrar La Cotizacion" ) );
    QPBRealizarVenta->setText( tr( "Realizar Venta" ) );
    QPBCancelar->setText( tr( "Cancelar Venta" ) );
    textLabel2->setText( tr( "No Se puede cerrar la venta\n"
"De Cotizacion" ) );
}

