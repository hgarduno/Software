/****************************************************************************
** Form implementation generated from reading ui file 'UI/BodegasSiscom.ui'
**
** Created: Wed Jan 31 10:48:13 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_BodegasSiscom.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlCmbBodegas.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlCmbBodegas.h"

/*
 *  Constructs a BodegasSiscom as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
BodegasSiscom::BodegasSiscom( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "BodegasSiscom" );
    BodegasSiscomLayout = new QGridLayout( this, 1, 1, 11, 6, "BodegasSiscomLayout"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    layout35 = new QVBoxLayout( 0, 0, 6, "layout35"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout35->addWidget( textLabel2 );

    QCtrBodegas = new QCtrlCmbBodegas( this, "QCtrBodegas" );
    layout35->addWidget( QCtrBodegas );
    layout36->addLayout( layout35 );

    layout34 = new QHBoxLayout( 0, 0, 6, "layout34"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    QPBAceptar->setDefault( FALSE );
    layout34->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    QPBCancelar->setDefault( FALSE );
    layout34->addWidget( QPBCancelar );
    layout36->addLayout( layout34 );

    BodegasSiscomLayout->addLayout( layout36, 0, 0 );
    languageChange();
    resize( QSize(319, 86).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
BodegasSiscom::~BodegasSiscom()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void BodegasSiscom::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel2->setText( tr( "Bodegas Siscom" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

