/****************************************************************************
** Form implementation generated from reading ui file 'UI/AnexaDireccion.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AnexaDireccion.h"

#include <qvariant.h>
#include <QSisSepomex.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QSisSepomex.h"

/*
 *  Constructs a AnexaDireccion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AnexaDireccion::AnexaDireccion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "AnexaDireccion" );
    AnexaDireccionLayout = new QGridLayout( this, 1, 1, 11, 6, "AnexaDireccionLayout"); 

    QCtrSepomex = new QSisSepomex( this, "QCtrSepomex" );

    AnexaDireccionLayout->addWidget( QCtrSepomex, 0, 0 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );
    layout19->addWidget( QPBRegistrar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setDefault( TRUE );
    layout19->addWidget( QPBCancelar );

    AnexaDireccionLayout->addLayout( layout19, 1, 0 );
    languageChange();
    resize( QSize(600, 225).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AnexaDireccion::~AnexaDireccion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AnexaDireccion::languageChange()
{
    setCaption( tr( "Agrega Direccion" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

