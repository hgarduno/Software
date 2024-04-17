/****************************************************************************
** Form implementation generated from reading ui file 'UI/RangoPorcentajes3.ui'
**
** Created: Fri Apr 12 21:25:15 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RangoPorcentajes3.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RangoPorcentajes3 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RangoPorcentajes3::RangoPorcentajes3( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RangoPorcentajes3" );
    RangoPorcentajes3Layout = new QGridLayout( this, 1, 1, 11, 6, "RangoPorcentajes3Layout"); 

    layout36_2 = new QVBoxLayout( 0, 0, 6, "layout36_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout36_2->addWidget( textLabel4_2 );

    QLEAlto = new QLineEdit( this, "QLEAlto" );
    layout36_2->addWidget( QLEAlto );

    RangoPorcentajes3Layout->addLayout( layout36_2, 0, 1 );

    layout38 = new QHBoxLayout( 0, 0, 6, "layout38"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout38->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout38->addWidget( QPBCancelar );

    RangoPorcentajes3Layout->addMultiCellLayout( layout38, 1, 1, 0, 1 );

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout36->addWidget( textLabel4 );

    QLEBajo = new QLineEdit( this, "QLEBajo" );
    layout36->addWidget( QLEBajo );

    RangoPorcentajes3Layout->addLayout( layout36, 0, 0 );
    languageChange();
    resize( QSize(413, 96).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RangoPorcentajes3::~RangoPorcentajes3()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RangoPorcentajes3::languageChange()
{
    setCaption( tr( "Rango de Porcentaje" ) );
    textLabel4_2->setText( tr( "Porcentaje Alto" ) );
    QLEAlto->setText( tr( "100" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel4->setText( tr( "Porcentaje Bajo" ) );
    QLEBajo->setText( tr( "1.0" ) );
}

