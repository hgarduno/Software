/****************************************************************************
** Form implementation generated from reading ui file 'UI/FirmaTiendas.ui'
**
** Created: Fri Apr 12 21:34:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_FirmaTiendas.h"

#include <qvariant.h>
#include <qiconview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a FirmaTiendas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FirmaTiendas::FirmaTiendas( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "FirmaTiendas" );
    FirmaTiendasLayout = new QGridLayout( this, 1, 1, 11, 6, "FirmaTiendasLayout"); 

    QIVInforma = new QIconView( this, "QIVInforma" );

    FirmaTiendasLayout->addWidget( QIVInforma, 0, 0 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setMinimumSize( QSize( 0, 40 ) );
    QPBAnexar->setAutoDefault( FALSE );
    layout21->addWidget( QPBAnexar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setMinimumSize( QSize( 0, 40 ) );
    QPBEliminar->setAutoDefault( FALSE );
    layout21->addWidget( QPBEliminar );

    QPBSLetra = new QPushButton( this, "QPBSLetra" );
    QPBSLetra->setMinimumSize( QSize( 0, 40 ) );
    QPBSLetra->setAutoDefault( FALSE );
    layout21->addWidget( QPBSLetra );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setMinimumSize( QSize( 0, 40 ) );
    QPBAceptar->setAutoDefault( FALSE );
    layout21->addWidget( QPBAceptar );

    FirmaTiendasLayout->addLayout( layout21, 1, 0 );
    languageChange();
    resize( QSize(600, 566).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FirmaTiendas::~FirmaTiendas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FirmaTiendas::languageChange()
{
    setCaption( tr( "Acceso SISCOM Tiendas" ) );
    QPBAnexar->setText( tr( "Anexar\n"
"Servidor" ) );
    QPBEliminar->setText( tr( "Eliminar Servidor" ) );
    QPBSLetra->setText( tr( "Seleccionar \n"
"Tipo Letra" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
}

