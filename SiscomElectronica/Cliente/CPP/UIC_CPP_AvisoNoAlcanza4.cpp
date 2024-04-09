/****************************************************************************
** Form implementation generated from reading ui file 'UI/AvisoNoAlcanza4.ui'
**
** Created: lun abr 1 18:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AvisoNoAlcanza4.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a AvisoNoAlcanza4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AvisoNoAlcanza4::AvisoNoAlcanza4( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "AvisoNoAlcanza4" );
    AvisoNoAlcanza4Layout = new QGridLayout( this, 1, 1, 11, 6, "AvisoNoAlcanza4Layout"); 

    layout19_3 = new QVBoxLayout( 0, 0, 6, "layout19_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    layout19_3->addWidget( textLabel2_3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setReadOnly( TRUE );
    layout19_3->addWidget( QLECantidad );

    AvisoNoAlcanza4Layout->addLayout( layout19_3, 0, 1 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout19->addWidget( textLabel2 );

    QLEProducto = new QLineEdit( this, "QLEProducto" );
    QLEProducto->setReadOnly( TRUE );
    layout19->addWidget( QLEProducto );

    AvisoNoAlcanza4Layout->addLayout( layout19, 0, 0 );

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

    AvisoNoAlcanza4Layout->addLayout( layout25, 2, 0 );

    QLCNExistencia = new QLCDNumber( this, "QLCNExistencia" );
    QLCNExistencia->setNumDigits( 8 );

    AvisoNoAlcanza4Layout->addWidget( QLCNExistencia, 2, 1 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout9->addWidget( textLabel2_2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setReadOnly( TRUE );
    layout9->addWidget( QTEDescripcion );

    AvisoNoAlcanza4Layout->addMultiCellLayout( layout9, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(372, 307).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AvisoNoAlcanza4::~AvisoNoAlcanza4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AvisoNoAlcanza4::languageChange()
{
    setCaption( tr( "Aviso del Sistema" ) );
    textLabel2_3->setText( tr( "Cantidad" ) );
    textLabel2->setText( tr( "Producto" ) );
    QPBEliminar->setText( tr( "Eliminar" ) );
    QPBVende->setText( tr( "Vender Lo Que Hay" ) );
    QPBCCantidad->setText( tr( "Cambiar Cantidad" ) );
    textLabel2_2->setText( tr( "Descripcion" ) );
}

