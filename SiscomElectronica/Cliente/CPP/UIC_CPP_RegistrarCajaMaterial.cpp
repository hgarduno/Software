/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistrarCajaMaterial.ui'
**
** Created: Thu Dec 21 12:53:46 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistrarCajaMaterial.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RegistrarCajaMaterial as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RegistrarCajaMaterial::RegistrarCajaMaterial( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RegistrarCajaMaterial" );
    RegistrarCajaMaterialLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistrarCajaMaterialLayout"); 

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout13->addWidget( textLabel3 );

    QLECaja = new QLineEdit( this, "QLECaja" );
    layout13->addWidget( QLECaja );
    layout15->addLayout( layout13 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout14->addWidget( textLabel4 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout14->addWidget( QTEDescripcion );
    layout15->addLayout( layout14 );

    RegistrarCajaMaterialLayout->addLayout( layout15, 0, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    layout4->addWidget( QPBRegistrar );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    layout4->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout4->addWidget( QPBCancelar );

    RegistrarCajaMaterialLayout->addLayout( layout4, 1, 0 );
    languageChange();
    resize( QSize(396, 202).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistrarCajaMaterial::~RegistrarCajaMaterial()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistrarCajaMaterial::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel3->setText( tr( "Caja" ) );
    textLabel4->setText( tr( "Descripcion" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

