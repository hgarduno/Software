/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaProductoImportado.ui'
**
** Created: Thu Dec 21 12:53:45 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaProductoImportado.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ActualizaProductoImportado as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ActualizaProductoImportado::ActualizaProductoImportado( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ActualizaProductoImportado" );
    ActualizaProductoImportadoLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaProductoImportadoLayout"); 

    layout28 = new QGridLayout( 0, 1, 1, 0, 6, "layout28"); 

    layout1_3_3 = new QVBoxLayout( 0, 0, 6, "layout1_3_3"); 

    textLabel1_4_3 = new QLabel( this, "textLabel1_4_3" );
    textLabel1_4_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_3->sizePolicy().hasHeightForWidth() ) );
    layout1_3_3->addWidget( textLabel1_4_3 );

    QLEProducto = new QLineEdit( this, "QLEProducto" );
    QLEProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEProducto->sizePolicy().hasHeightForWidth() ) );
    QLEProducto->setReadOnly( TRUE );
    layout1_3_3->addWidget( QLEProducto );

    layout28->addLayout( layout1_3_3, 0, 0 );

    layout27 = new QHBoxLayout( 0, 0, 6, "layout27"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout27->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout27->addWidget( QPBCancelar );

    layout28->addLayout( layout27, 2, 0 );

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    layout1_3 = new QVBoxLayout( 0, 0, 6, "layout1_3"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout1_3->addWidget( textLabel1_4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout1_3->addWidget( QLECantidad );
    layout26->addLayout( layout1_3 );

    layout1_3_2 = new QVBoxLayout( 0, 0, 6, "layout1_3_2"); 

    textLabel1_4_2 = new QLabel( this, "textLabel1_4_2" );
    textLabel1_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2->addWidget( textLabel1_4_2 );

    QLECostoUnitario = new QLineEdit( this, "QLECostoUnitario" );
    QLECostoUnitario->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoUnitario->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2->addWidget( QLECostoUnitario );
    layout26->addLayout( layout1_3_2 );

    layout1_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_3_2_2"); 

    textLabel1_4_2_2 = new QLabel( this, "textLabel1_4_2_2" );
    textLabel1_4_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2_2->addWidget( textLabel1_4_2_2 );

    QLEPeso = new QLineEdit( this, "QLEPeso" );
    QLEPeso->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPeso->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2_2->addWidget( QLEPeso );
    layout26->addLayout( layout1_3_2_2 );

    layout28->addLayout( layout26, 1, 0 );

    ActualizaProductoImportadoLayout->addLayout( layout28, 0, 0 );
    languageChange();
    resize( QSize(320, 141).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaProductoImportado::~ActualizaProductoImportado()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaProductoImportado::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_4_3->setText( tr( "Producto" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1_4->setText( tr( "Cantidad" ) );
    textLabel1_4_2->setText( tr( "Costo Unitario" ) );
    textLabel1_4_2_2->setText( tr( "Peso Unitario" ) );
}

