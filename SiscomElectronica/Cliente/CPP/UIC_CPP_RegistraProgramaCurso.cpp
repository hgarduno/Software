/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistraProgramaCurso.ui'
**
** Created: lun abr 1 18:57:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistraProgramaCurso.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RegistraProgramaCurso as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RegistraProgramaCurso::RegistraProgramaCurso( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RegistraProgramaCurso" );
    RegistraProgramaCursoLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistraProgramaCursoLayout"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout6->addWidget( textLabel1 );

    QLEDscProgramacion = new QLineEdit( this, "QLEDscProgramacion" );
    layout6->addWidget( QLEDscProgramacion );
    layout8->addLayout( layout6 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout7->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout7->addWidget( QPBCancelar );
    layout8->addLayout( layout7 );

    RegistraProgramaCursoLayout->addLayout( layout8, 0, 0 );
    languageChange();
    resize( QSize(548, 100).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistraProgramaCurso::~RegistraProgramaCurso()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistraProgramaCurso::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Registra Programacion Cursos" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

