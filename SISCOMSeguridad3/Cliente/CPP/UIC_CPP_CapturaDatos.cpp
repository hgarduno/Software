/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_CapturaDatos.ui'
**
** Created: Fri Apr 12 21:23:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaDatos.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDatos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDatos::CapturaDatos( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDatos" );
    CapturaDatosLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDatosLayout"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout21->addWidget( textLabel2 );

    QLEDatos = new QLineEdit( this, "QLEDatos" );
    layout21->addWidget( QLEDatos );

    CapturaDatosLayout->addLayout( layout21, 0, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout22->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout22->addWidget( QPBCancelar );

    CapturaDatosLayout->addLayout( layout22, 1, 0 );
    languageChange();
    resize( QSize(236, 96).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDatos::~CapturaDatos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDatos::languageChange()
{
    setCaption( tr( "Captura Datos" ) );
    textLabel2->setText( tr( "Cambia El Valor" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

