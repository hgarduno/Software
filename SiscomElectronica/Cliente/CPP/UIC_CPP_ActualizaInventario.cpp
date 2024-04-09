/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaInventario.ui'
**
** Created: lun abr 1 19:06:39 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaInventario.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ActualizaInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ActualizaInventario::ActualizaInventario( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ActualizaInventario" );
    ActualizaInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaInventarioLayout"); 

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout10->addWidget( textLabel2 );

    lineEdit4 = new QLineEdit( this, "lineEdit4" );
    layout10->addWidget( lineEdit4 );
    layout18->addLayout( layout10 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLECantidad_2 = new QLineEdit( this, "QLECantidad_2" );
    layout1_2->addWidget( QLECantidad_2 );
    layout18->addLayout( layout1_2 );

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout1_2_2->addWidget( textLabel1_2_2 );

    QLECantidad_2_2 = new QLineEdit( this, "QLECantidad_2_2" );
    layout1_2_2->addWidget( QLECantidad_2_2 );
    layout18->addLayout( layout1_2_2 );
    layout20->addLayout( layout18 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout1->addWidget( QLECantidad );
    layout19->addLayout( layout1 );
    spacer3 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout19->addItem( spacer3 );
    layout20->addLayout( layout19 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    pushButton3 = new QPushButton( this, "pushButton3" );
    layout16->addWidget( pushButton3 );

    pushButton4 = new QPushButton( this, "pushButton4" );
    layout16->addWidget( pushButton4 );
    layout20->addLayout( layout16 );

    ActualizaInventarioLayout->addLayout( layout20, 0, 0 );
    languageChange();
    resize( QSize(368, 151).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaInventario::~ActualizaInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaInventario::languageChange()
{
    setCaption( tr( "Actualiza Inventario" ) );
    textLabel2->setText( tr( "Producto" ) );
    textLabel1_2->setText( tr( "Fecha De Registro" ) );
    textLabel1_2_2->setText( tr( "Hora Registro" ) );
    textLabel1->setText( tr( "Cantidad" ) );
    pushButton3->setText( tr( "pushButton3" ) );
    pushButton4->setText( tr( "pushButton4" ) );
}

