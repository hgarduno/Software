/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ActualizandoSistema.ui'
**
** Created: Thu Apr 11 21:10:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ActualizandoSistema.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlabel.h>
#include <qprogressbar.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ActualizandoSistema as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ActualizandoSistema::ActualizandoSistema( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ActualizandoSistema" );
    ActualizandoSistemaLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizandoSistemaLayout"); 

    layout2 = new QGridLayout( 0, 1, 1, 0, 6, "layout2"); 

    textEdit1 = new QTextEdit( this, "textEdit1" );

    layout2->addWidget( textEdit1, 1, 0 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    progressBar1 = new QProgressBar( this, "progressBar1" );
    layout1->addWidget( progressBar1 );

    layout2->addLayout( layout1, 0, 0 );

    ActualizandoSistemaLayout->addLayout( layout2, 0, 0 );
    languageChange();
    resize( QSize(613, 380).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizandoSistema::~ActualizandoSistema()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizandoSistema::languageChange()
{
    setCaption( tr( "Actualizacion Disponible" ) );
    textLabel1->setText( tr( "Se a detectado una actualizacion disponible" ) );
}

