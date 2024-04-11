/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_PerfilReferencia.ui'
**
** Created: Sat Jan 27 16:42:29 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PerfilReferencia.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a PerfilReferencia as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
PerfilReferencia::PerfilReferencia( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "PerfilReferencia" );
    PerfilReferenciaLayout = new QGridLayout( this, 1, 1, 11, 6, "PerfilReferenciaLayout"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );

    PerfilReferenciaLayout->addWidget( QPBAceptar, 2, 0 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout14->addWidget( textLabel1 );

    QLEPerfil = new QLineEdit( this, "QLEPerfil" );
    QLEPerfil->setReadOnly( TRUE );
    layout14->addWidget( QLEPerfil );
    layout15->addLayout( layout14 );

    textLabel2 = new QLabel( this, "textLabel2" );
    layout15->addWidget( textLabel2 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Perfil" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 1 );
    layout15->addWidget( QTDatos );

    PerfilReferenciaLayout->addLayout( layout15, 0, 0 );

    layout14_2 = new QVBoxLayout( 0, 0, 6, "layout14_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout14_2->addWidget( textLabel1_2 );

    QLEPerfileRef = new QLineEdit( this, "QLEPerfileRef" );
    QLEPerfileRef->setReadOnly( TRUE );
    layout14_2->addWidget( QLEPerfileRef );

    PerfilReferenciaLayout->addLayout( layout14_2, 1, 0 );
    languageChange();
    resize( QSize(294, 387).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PerfilReferencia::~PerfilReferencia()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PerfilReferencia::languageChange()
{
    setCaption( tr( "Perfiles" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    textLabel1->setText( tr( "Perfil A Registrar" ) );
    textLabel2->setText( tr( "Perfiles Referencia" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Perfil" ) );
    textLabel1_2->setText( tr( "Perfil Referencia" ) );
}

