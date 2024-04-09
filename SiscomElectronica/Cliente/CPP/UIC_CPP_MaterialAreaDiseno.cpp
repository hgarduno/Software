/****************************************************************************
** Form implementation generated from reading ui file 'UI/MaterialAreaDiseno.ui'
**
** Created: lun abr 1 18:57:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_MaterialAreaDiseno.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a MaterialAreaDiseno as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
MaterialAreaDiseno::MaterialAreaDiseno( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "MaterialAreaDiseno" );
    MaterialAreaDisenoLayout = new QGridLayout( this, 1, 1, 11, 6, "MaterialAreaDisenoLayout"); 

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setDefault( TRUE );
    layout6->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout6->addWidget( QPBCancelar );

    MaterialAreaDisenoLayout->addLayout( layout6, 1, 0 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout7->addWidget( textLabel1 );

    QTEExplicacion = new QTextEdit( this, "QTEExplicacion" );
    layout7->addWidget( QTEExplicacion );

    MaterialAreaDisenoLayout->addLayout( layout7, 0, 0 );
    languageChange();
    resize( QSize(366, 352).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MaterialAreaDiseno::~MaterialAreaDiseno()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MaterialAreaDiseno::languageChange()
{
    setCaption( tr( "Material Area Diseno" ) );
    QPBAceptar->setText( tr( "Registrar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Proyecto" ) );
}

