/****************************************************************************
** Form implementation generated from reading ui file 'UI/AccesoSiscomElectronica.ui'
**
** Created: Wed Apr 10 21:10:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AccesoSiscomElectronica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a AccesoSiscomElectronica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AccesoSiscomElectronica::AccesoSiscomElectronica( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "AccesoSiscomElectronica" );
    AccesoSiscomElectronicaLayout = new QGridLayout( this, 1, 1, 11, 6, "AccesoSiscomElectronicaLayout"); 

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    QPBSLetra = new QPushButton( this, "QPBSLetra" );
    QPBSLetra->setMinimumSize( QSize( 0, 40 ) );
    QPBSLetra->setAutoDefault( FALSE );
    layout21->addWidget( QPBSLetra );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setMinimumSize( QSize( 0, 40 ) );
    QPBAceptar->setAutoDefault( FALSE );
    layout21->addWidget( QPBAceptar );

    AccesoSiscomElectronicaLayout->addLayout( layout21, 1, 0 );

    QIconViewInforma = new QIconView( this, "QIconViewInforma" );

    AccesoSiscomElectronicaLayout->addWidget( QIconViewInforma, 0, 0 );
    languageChange();
    resize( QSize(694, 574).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AccesoSiscomElectronica::~AccesoSiscomElectronica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AccesoSiscomElectronica::languageChange()
{
    setCaption( tr( "Form2" ) );
    QPBSLetra->setText( tr( "Seleccionar \n"
"Tipo Letra" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
}

