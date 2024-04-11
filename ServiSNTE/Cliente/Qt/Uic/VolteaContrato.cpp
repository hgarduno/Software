/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/VolteaContrato.ui'
**
** Created: Thu Apr 11 21:07:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "VolteaContrato.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a VolteaContrato as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
VolteaContrato::VolteaContrato( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "VolteaContrato" );
    VolteaContratoLayout = new QGridLayout( this, 1, 1, 11, 6, "VolteaContratoLayout"); 

    QPBSeVolteoElContrato = new QPushButton( this, "QPBSeVolteoElContrato" );

    VolteaContratoLayout->addWidget( QPBSeVolteoElContrato, 0, 0 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );

    VolteaContratoLayout->addWidget( QPBImprimir, 0, 1 );

    QPBTerminar = new QPushButton( this, "QPBTerminar" );
    QPBTerminar->setEnabled( FALSE );

    VolteaContratoLayout->addWidget( QPBTerminar, 0, 2 );
    languageChange();
    resize( QSize(750, 53).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
VolteaContrato::~VolteaContrato()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void VolteaContrato::languageChange()
{
    setCaption( tr( "Voltea Contrato" ) );
    QPBSeVolteoElContrato->setText( tr( "Se Volteo el contrato" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBTerminar->setText( tr( "Terminar" ) );
}

