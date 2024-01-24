/****************************************************************************
** Form implementation generated from reading ui file 'UI/ExpendioOrigen.ui'
**
** Created: Thu Dec 21 12:53:46 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ExpendioOrigen.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlExpendios.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlExpendios.h"

/*
 *  Constructs a ExpendioOrigen as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ExpendioOrigen::ExpendioOrigen( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ExpendioOrigen" );
    ExpendioOrigenLayout = new QGridLayout( this, 1, 1, 11, 6, "ExpendioOrigenLayout"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout5->addWidget( textLabel2 );

    QCtrExpendios = new QCtrlExpendios( this, "QCtrExpendios" );
    layout5->addWidget( QCtrExpendios );
    layout6->addLayout( layout5 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout4->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout4->addWidget( QPBCancelar );
    layout6->addLayout( layout4 );

    ExpendioOrigenLayout->addLayout( layout6, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ExpendioOrigen::~ExpendioOrigen()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ExpendioOrigen::languageChange()
{
    setCaption( tr( "Form2" ) );
    textLabel2->setText( tr( "Expendio Origen" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

