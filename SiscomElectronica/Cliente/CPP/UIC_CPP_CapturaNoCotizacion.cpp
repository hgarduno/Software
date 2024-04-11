/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaNoCotizacion.ui'
**
** Created: Wed Apr 10 20:52:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaNoCotizacion.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaNoCotizacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaNoCotizacion::CapturaNoCotizacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaNoCotizacion" );
    CapturaNoCotizacionLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaNoCotizacionLayout"); 

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout31->addWidget( textLabel4 );

    QLENoCtizacion = new QLineEdit( this, "QLENoCtizacion" );
    layout31->addWidget( QLENoCtizacion );

    CapturaNoCotizacionLayout->addMultiCellLayout( layout31, 0, 0, 0, 1 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );

    CapturaNoCotizacionLayout->addWidget( QPBAceptar, 1, 0 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );

    CapturaNoCotizacionLayout->addWidget( QPBCancelar, 1, 1 );
    languageChange();
    resize( QSize(295, 94).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaNoCotizacion::~CapturaNoCotizacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaNoCotizacion::languageChange()
{
    setCaption( tr( "Introduce el numero de cotizacion" ) );
    textLabel4->setText( tr( "Numero Cotizacion" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

