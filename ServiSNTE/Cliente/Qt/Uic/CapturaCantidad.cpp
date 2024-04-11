/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaCantidad.ui'
**
** Created: Thu Apr 11 21:07:13 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaCantidad.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaCantidad as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaCantidad::CapturaCantidad( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaCantidad" );
    CapturaCantidadLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaCantidadLayout"); 

    layout90 = new QVBoxLayout( 0, 0, 6, "layout90"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout90->addWidget( textLabel2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout90->addWidget( QLECantidad );

    CapturaCantidadLayout->addLayout( layout90, 0, 0 );

    layout89 = new QHBoxLayout( 0, 0, 6, "layout89"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout89->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout89->addWidget( QPBCancelar );

    CapturaCantidadLayout->addLayout( layout89, 1, 0 );
    languageChange();
    resize( QSize(437, 92).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaCantidad::~CapturaCantidad()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaCantidad::languageChange()
{
    setCaption( tr( "Captura Cantidad" ) );
    textLabel2->setText( tr( "Cantidad" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

