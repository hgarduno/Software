/****************************************************************************
** Form implementation generated from reading ui file 'UI/DonacionMaterial.ui'
**
** Created: Thu Dec 21 12:53:45 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DonacionMaterial.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a DonacionMaterial as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DonacionMaterial::DonacionMaterial( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "DonacionMaterial" );
    DonacionMaterialLayout = new QGridLayout( this, 1, 1, 11, 6, "DonacionMaterialLayout"); 

    Explicacion = new QLabel( this, "Explicacion" );

    DonacionMaterialLayout->addWidget( Explicacion, 0, 0 );

    QTEExplicacion = new QTextEdit( this, "QTEExplicacion" );

    DonacionMaterialLayout->addWidget( QTEExplicacion, 1, 0 );

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout1->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout1->addWidget( QPBCancelar );

    DonacionMaterialLayout->addLayout( layout1, 2, 0 );
    languageChange();
    resize( QSize(630, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DonacionMaterial::~DonacionMaterial()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DonacionMaterial::languageChange()
{
    setCaption( tr( "Donacion Material" ) );
    Explicacion->setText( tr( "textLabel1" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

