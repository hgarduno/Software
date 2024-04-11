/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaPrecioIva.ui'
**
** Created: Sat Jan 27 16:37:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaPrecioIva.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaPrecioIva as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaPrecioIva::CapturaPrecioIva( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaPrecioIva" );
    CapturaPrecioIvaLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaPrecioIvaLayout"); 

    layout89 = new QHBoxLayout( 0, 0, 6, "layout89"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout89->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout89->addWidget( QPBCancelar );

    CapturaPrecioIvaLayout->addMultiCellLayout( layout89, 1, 1, 0, 1 );

    layout90 = new QVBoxLayout( 0, 0, 6, "layout90"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout90->addWidget( textLabel2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout90->addWidget( QLECantidad );

    CapturaPrecioIvaLayout->addLayout( layout90, 0, 0 );

    layout90_2 = new QVBoxLayout( 0, 0, 6, "layout90_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout90_2->addWidget( textLabel2_2 );

    QLEIva = new QLineEdit( this, "QLEIva" );
    layout90_2->addWidget( QLEIva );

    CapturaPrecioIvaLayout->addLayout( layout90_2, 0, 1 );
    languageChange();
    resize( QSize(437, 92).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaPrecioIva::~CapturaPrecioIva()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaPrecioIva::languageChange()
{
    setCaption( tr( "Captura Cantidad" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel2->setText( tr( "Precio" ) );
    textLabel2_2->setText( tr( "IVA" ) );
}

