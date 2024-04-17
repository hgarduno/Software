/****************************************************************************
** Form implementation generated from reading ui file 'UI/SelOrden.ui'
**
** Created: Fri Apr 12 21:34:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SelOrden.h"

#include <qvariant.h>
#include <qiconview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a SelOrden as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SelOrden::SelOrden( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SelOrden" );
    SelOrdenLayout = new QGridLayout( this, 1, 1, 11, 6, "SelOrdenLayout"); 

    QIVIOrdenes = new QIconView( this, "QIVIOrdenes" );

    SelOrdenLayout->addWidget( QIVIOrdenes, 0, 0 );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout36->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout36->addWidget( QPBCancelar );

    SelOrdenLayout->addLayout( layout36, 1, 0 );
    languageChange();
    resize( QSize(600, 291).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SelOrden::~SelOrden()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SelOrden::languageChange()
{
    setCaption( tr( "Ordenes Disponibles" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

