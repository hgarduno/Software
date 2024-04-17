/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaProductoCotizacionImportacion.ui'
**
** Created: Fri Apr 12 21:26:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaProductoCotizacionImportacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ActualizaProductoCotizacionImportacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ActualizaProductoCotizacionImportacion::ActualizaProductoCotizacionImportacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ActualizaProductoCotizacionImportacion" );
    ActualizaProductoCotizacionImportacionLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaProductoCotizacionImportacionLayout"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel9 = new QLabel( this, "textLabel9" );
    layout18->addWidget( textLabel9 );

    QLEClave = new QLineEdit( this, "QLEClave" );
    QLEClave->setReadOnly( TRUE );
    layout18->addWidget( QLEClave );
    layout22->addLayout( layout18 );

    layout18_3 = new QVBoxLayout( 0, 0, 6, "layout18_3"); 

    textLabel9_3 = new QLabel( this, "textLabel9_3" );
    textLabel9_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel9_3->sizePolicy().hasHeightForWidth() ) );
    layout18_3->addWidget( textLabel9_3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout18_3->addWidget( QLECantidad );
    layout22->addLayout( layout18_3 );

    layout18_2 = new QVBoxLayout( 0, 0, 6, "layout18_2"); 

    textLabel9_2 = new QLabel( this, "textLabel9_2" );
    textLabel9_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel9_2->sizePolicy().hasHeightForWidth() ) );
    layout18_2->addWidget( textLabel9_2 );

    QLEPrecio = new QLineEdit( this, "QLEPrecio" );
    QLEPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPrecio->sizePolicy().hasHeightForWidth() ) );
    layout18_2->addWidget( QLEPrecio );
    layout22->addLayout( layout18_2 );
    layout23->addLayout( layout22 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout21->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout21->addWidget( QPBCancelar );
    layout23->addLayout( layout21 );

    ActualizaProductoCotizacionImportacionLayout->addLayout( layout23, 0, 0 );
    languageChange();
    resize( QSize(489, 98).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaProductoCotizacionImportacion::~ActualizaProductoCotizacionImportacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaProductoCotizacionImportacion::languageChange()
{
    setCaption( tr( "Form3" ) );
    textLabel9->setText( tr( "Producto" ) );
    textLabel9_3->setText( tr( "Cantidad" ) );
    textLabel9_2->setText( tr( "Precio" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

