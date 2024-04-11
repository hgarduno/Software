/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaSueldo.ui'
**
** Created: Wed Jan 31 10:47:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaSueldo.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaSueldo as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaSueldo::CapturaSueldo( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaSueldo" );
    CapturaSueldoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaSueldoLayout"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout13->addWidget( textLabel4 );

    QLEEmpleado = new QLineEdit( this, "QLEEmpleado" );
    layout13->addWidget( QLEEmpleado );
    layout17->addLayout( layout13 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout14->addWidget( textLabel6 );

    QLESueldo = new QLineEdit( this, "QLESueldo" );
    layout14->addWidget( QLESueldo );
    layout15->addLayout( layout14 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout15->addItem( spacer1 );
    layout17->addLayout( layout15 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setAutoDefault( FALSE );
    layout16->addWidget( QPBRegistra );

    QPBCancela = new QPushButton( this, "QPBCancela" );
    QPBCancela->setAutoDefault( FALSE );
    layout16->addWidget( QPBCancela );
    layout17->addLayout( layout16 );

    CapturaSueldoLayout->addLayout( layout17, 0, 0 );
    languageChange();
    resize( QSize(396, 149).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaSueldo::~CapturaSueldo()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaSueldo::languageChange()
{
    setCaption( tr( "Captura Sueldo" ) );
    textLabel4->setText( tr( "Empleado" ) );
    textLabel6->setText( tr( "Sueldo" ) );
    QPBRegistra->setText( tr( "Registrar" ) );
    QPBCancela->setText( tr( "Cancelar" ) );
}

