/****************************************************************************
** Form implementation generated from reading ui file 'UI/RemisionFactura.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RemisionFactura.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RemisionFactura as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RemisionFactura::RemisionFactura( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RemisionFactura" );
    RemisionFacturaLayout = new QGridLayout( this, 1, 1, 11, 6, "RemisionFacturaLayout"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLERemFactura = new QLineEdit( this, "QLERemFactura" );
    layout1->addWidget( QLERemFactura );
    layout3->addLayout( layout1 );

    layout2 = new QHBoxLayout( 0, 0, 6, "layout2"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout2->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout2->addWidget( QPBCancelar );
    layout3->addLayout( layout2 );

    RemisionFacturaLayout->addLayout( layout3, 0, 0 );
    languageChange();
    resize( QSize(349, 107).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RemisionFactura::~RemisionFactura()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RemisionFactura::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "No Remision / No Factura" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

