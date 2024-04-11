/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/InventarioEnCurso.ui'
**
** Created: Sat Jan 27 16:37:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "InventarioEnCurso.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a InventarioEnCurso as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
InventarioEnCurso::InventarioEnCurso( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "InventarioEnCurso" );
    InventarioEnCursoLayout = new QGridLayout( this, 1, 1, 11, 6, "InventarioEnCursoLayout"); 

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout12->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout12->addWidget( QPBCancelar );

    InventarioEnCursoLayout->addLayout( layout12, 1, 0 );

    textLabel1 = new QLabel( this, "textLabel1" );

    InventarioEnCursoLayout->addWidget( textLabel1, 0, 0 );
    languageChange();
    resize( QSize(363, 86).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
InventarioEnCurso::~InventarioEnCurso()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void InventarioEnCurso::languageChange()
{
    setCaption( tr( "Inventario en curso" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Se encuentra un inventario en curso ! ..." ) );
}

