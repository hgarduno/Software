/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaNumFactura.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaNumFactura.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaNumFactura as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaNumFactura::CapturaNumFactura( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaNumFactura" );
    CapturaNumFacturaLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaNumFacturaLayout"); 

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    layout46 = new QVBoxLayout( 0, 0, 6, "layout46"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout46->addWidget( textLabel4 );

    QLENumFactura = new QLineEdit( this, "QLENumFactura" );
    layout46->addWidget( QLENumFactura );
    layout48->addLayout( layout46 );

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout47->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout47->addWidget( QPBCancelar );
    layout48->addLayout( layout47 );

    CapturaNumFacturaLayout->addLayout( layout48, 0, 0 );
    languageChange();
    resize( QSize(344, 102).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaNumFactura::~CapturaNumFactura()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaNumFactura::languageChange()
{
    setCaption( tr( "Actualiza # Factura" ) );
    textLabel4->setText( tr( "Numero De Factura" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

