/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaDenominacion.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaDenominacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDenominacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDenominacion::CapturaDenominacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDenominacion" );
    CapturaDenominacionLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDenominacionLayout"); 

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( textLabel3 );

    QLEDenominacion = new QLineEdit( this, "QLEDenominacion" );
    layout4->addWidget( QLEDenominacion );

    CapturaDenominacionLayout->addLayout( layout4, 0, 0 );

    layout4_2 = new QVBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( textLabel3_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout4_2->addWidget( QLECantidad );

    CapturaDenominacionLayout->addLayout( layout4_2, 0, 1 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout6->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout6->addWidget( QPBCancelar );

    CapturaDenominacionLayout->addMultiCellLayout( layout6, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(344, 103).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDenominacion::~CapturaDenominacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDenominacion::languageChange()
{
    setCaption( tr( "Captura Denominacion" ) );
    textLabel3->setText( tr( "Denominacion" ) );
    textLabel3_2->setText( tr( "Cantidad" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

