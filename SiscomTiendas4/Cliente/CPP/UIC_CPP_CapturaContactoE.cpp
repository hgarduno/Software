/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaContactoE.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaContactoE.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaContactoE as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaContactoE::CapturaContactoE( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaContactoE" );
    CapturaContactoELayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaContactoELayout"); 

    layout49 = new QVBoxLayout( 0, 0, 6, "layout49"); 

    layout48 = new QHBoxLayout( 0, 0, 6, "layout48"); 

    layout45 = new QVBoxLayout( 0, 0, 6, "layout45"); 

    textLabel11 = new QLabel( this, "textLabel11" );
    layout45->addWidget( textLabel11 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout45->addWidget( QLENombre );
    layout48->addLayout( layout45 );

    layout45_2 = new QVBoxLayout( 0, 0, 6, "layout45_2"); 

    textLabel11_2 = new QLabel( this, "textLabel11_2" );
    layout45_2->addWidget( textLabel11_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout45_2->addWidget( QLEAPaterno );
    layout48->addLayout( layout45_2 );

    layout45_3 = new QVBoxLayout( 0, 0, 6, "layout45_3"); 

    textLabel11_3 = new QLabel( this, "textLabel11_3" );
    layout45_3->addWidget( textLabel11_3 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout45_3->addWidget( QLEAMaterno );
    layout48->addLayout( layout45_3 );
    layout49->addLayout( layout48 );

    textLabel12 = new QLabel( this, "textLabel12" );
    layout49->addWidget( textLabel12 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout49->addWidget( QTEDescripcion );

    CapturaContactoELayout->addLayout( layout49, 0, 0 );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout25->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout25->addWidget( QPBCancelar );

    CapturaContactoELayout->addLayout( layout25, 1, 0 );
    languageChange();
    resize( QSize(600, 179).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaContactoE::~CapturaContactoE()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaContactoE::languageChange()
{
    setCaption( tr( "Form7" ) );
    textLabel11->setText( tr( "Nombre" ) );
    textLabel11_2->setText( tr( "Apellido Paterno" ) );
    textLabel11_3->setText( tr( "Apellido Materno" ) );
    textLabel12->setText( tr( "Descripcion" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

