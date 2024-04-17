/****************************************************************************
** Form implementation generated from reading ui file 'UI/RangoPorcentaje.ui'
**
** Created: Fri Apr 12 21:35:56 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RangoPorcentaje.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RangoPorcentaje as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RangoPorcentaje::RangoPorcentaje( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RangoPorcentaje" );
    RangoPorcentajeLayout = new QGridLayout( this, 1, 1, 11, 6, "RangoPorcentajeLayout"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout36->addWidget( textLabel4 );

    QLEBajo = new QLineEdit( this, "QLEBajo" );
    layout36->addWidget( QLEBajo );

    RangoPorcentajeLayout->addLayout( layout36, 0, 0 );

    layout36_2 = new QVBoxLayout( 0, 0, 6, "layout36_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout36_2->addWidget( textLabel4_2 );

    QLEAlto = new QLineEdit( this, "QLEAlto" );
    layout36_2->addWidget( QLEAlto );

    RangoPorcentajeLayout->addLayout( layout36_2, 0, 1 );

    layout38 = new QHBoxLayout( 0, 0, 6, "layout38"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout38->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( TRUE );
    layout38->addWidget( QPBCancelar );

    RangoPorcentajeLayout->addMultiCellLayout( layout38, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(251, 96).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RangoPorcentaje::~RangoPorcentaje()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RangoPorcentaje::languageChange()
{
    setCaption( tr( "Capturar Rango Porcentajes" ) );
    textLabel4->setText( tr( "Porcentaje Bajo" ) );
    textLabel4_2->setText( tr( "Porcentaje Alto" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

