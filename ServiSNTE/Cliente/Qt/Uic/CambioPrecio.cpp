/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CambioPrecio.ui'
**
** Created: Thu Apr 11 21:07:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CambioPrecio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CambioPrecio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CambioPrecio::CambioPrecio( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CambioPrecio" );
    CambioPrecioLayout = new QGridLayout( this, 1, 1, 11, 6, "CambioPrecioLayout"); 

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    layout30 = new QVBoxLayout( 0, 0, 6, "layout30"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout30->addWidget( textLabel1 );

    QLEPrecioAnterior = new QLineEdit( this, "QLEPrecioAnterior" );
    QLEPrecioAnterior->setReadOnly( TRUE );
    layout30->addWidget( QLEPrecioAnterior );
    layout32->addLayout( layout30 );

    layout30_2 = new QVBoxLayout( 0, 0, 6, "layout30_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout30_2->addWidget( textLabel1_2 );

    QLENvoPrecio = new QLineEdit( this, "QLENvoPrecio" );
    layout30_2->addWidget( QLENvoPrecio );
    layout32->addLayout( layout30_2 );

    CambioPrecioLayout->addLayout( layout32, 0, 0 );

    layout34 = new QVBoxLayout( 0, 0, 6, "layout34"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout34->addWidget( textLabel2 );

    QTEMotivoCambioPrecio = new QTextEdit( this, "QTEMotivoCambioPrecio" );
    layout34->addWidget( QTEMotivoCambioPrecio );

    CambioPrecioLayout->addLayout( layout34, 1, 0 );

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout35->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout35->addWidget( QPBCancelar );

    CambioPrecioLayout->addLayout( layout35, 2, 0 );
    languageChange();
    resize( QSize(231, 220).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CambioPrecio::~CambioPrecio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CambioPrecio::languageChange()
{
    setCaption( tr( "Cambio de Precio" ) );
    textLabel1->setText( tr( "Precio Anterior" ) );
    textLabel1_2->setText( tr( "Precio De Venta" ) );
    textLabel2->setText( tr( "Motivo del Cambio De Precio" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

