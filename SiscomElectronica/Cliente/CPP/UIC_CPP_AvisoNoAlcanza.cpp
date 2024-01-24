/****************************************************************************
** Form implementation generated from reading ui file 'UI/AvisoNoAlcanza.ui'
**
** Created: Thu Dec 21 12:53:21 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AvisoNoAlcanza.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a AvisoNoAlcanza as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AvisoNoAlcanza::AvisoNoAlcanza( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "AvisoNoAlcanza" );
    AvisoNoAlcanzaLayout = new QGridLayout( this, 1, 1, 11, 6, "AvisoNoAlcanzaLayout"); 

    layout19_2 = new QVBoxLayout( 0, 0, 6, "layout19_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout19_2->addWidget( textLabel2_2 );

    QLEDescripcion = new QLineEdit( this, "QLEDescripcion" );
    QLEDescripcion->setReadOnly( TRUE );
    layout19_2->addWidget( QLEDescripcion );

    AvisoNoAlcanzaLayout->addMultiCellLayout( layout19_2, 1, 1, 0, 2 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setAutoDefault( FALSE );
    layout25->addWidget( QPBEliminar );

    QPBVende = new QPushButton( this, "QPBVende" );
    QPBVende->setAutoDefault( FALSE );
    layout25->addWidget( QPBVende );

    QPBCCantidad = new QPushButton( this, "QPBCCantidad" );
    QPBCCantidad->setAutoDefault( FALSE );
    layout25->addWidget( QPBCCantidad );

    AvisoNoAlcanzaLayout->addMultiCellLayout( layout25, 2, 2, 0, 1 );

    QLCNExistencia = new QLCDNumber( this, "QLCNExistencia" );
    QLCNExistencia->setNumDigits( 8 );

    AvisoNoAlcanzaLayout->addWidget( QLCNExistencia, 2, 2 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout19->addWidget( textLabel2 );

    QLEProducto = new QLineEdit( this, "QLEProducto" );
    QLEProducto->setReadOnly( TRUE );
    layout19->addWidget( QLEProducto );

    AvisoNoAlcanzaLayout->addLayout( layout19, 0, 0 );

    layout19_3 = new QVBoxLayout( 0, 0, 6, "layout19_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    layout19_3->addWidget( textLabel2_3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setReadOnly( TRUE );
    layout19_3->addWidget( QLECantidad );

    AvisoNoAlcanzaLayout->addMultiCellLayout( layout19_3, 0, 0, 1, 2 );
    languageChange();
    resize( QSize(288, 206).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AvisoNoAlcanza::~AvisoNoAlcanza()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AvisoNoAlcanza::languageChange()
{
    setCaption( tr( "Form2" ) );
    textLabel2_2->setText( tr( "Descripcion" ) );
    QPBEliminar->setText( tr( "Eliminar" ) );
    QPBVende->setText( tr( "Vender Lo Que Hay" ) );
    QPBCCantidad->setText( tr( "Cambiar Cantidad" ) );
    textLabel2->setText( tr( "Producto" ) );
    textLabel2_3->setText( tr( "Cantidad" ) );
}

