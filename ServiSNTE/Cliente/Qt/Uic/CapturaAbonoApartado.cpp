/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaAbonoApartado.ui'
**
** Created: Sat Jan 27 16:38:09 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaAbonoApartado.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaAbonoApartado as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaAbonoApartado::CapturaAbonoApartado( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaAbonoApartado" );
    CapturaAbonoApartadoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaAbonoApartadoLayout"); 

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout12_2->addWidget( textLabel4_2 );

    QLEFolio = new QLineEdit( this, "QLEFolio" );
    QLEFolio->setEnabled( TRUE );
    QLEFolio->setReadOnly( TRUE );
    layout12_2->addWidget( QLEFolio );
    layout14->addLayout( layout12_2 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout12->addWidget( textLabel4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout12->addWidget( QLECantidad );
    layout14->addLayout( layout12 );

    CapturaAbonoApartadoLayout->addLayout( layout14, 0, 0 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout15->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout15->addWidget( QPBCancelar );

    CapturaAbonoApartadoLayout->addLayout( layout15, 1, 0 );
    languageChange();
    resize( QSize(352, 122).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaAbonoApartado::~CapturaAbonoApartado()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaAbonoApartado::languageChange()
{
    setCaption( tr( "Captura Abono Apartado" ) );
    textLabel4_2->setText( tr( "Folio" ) );
    textLabel4->setText( tr( "Abono" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

