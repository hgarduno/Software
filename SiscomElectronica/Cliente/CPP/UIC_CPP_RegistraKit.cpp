/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistraKit.ui'
**
** Created: Wed Apr 10 20:52:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistraKit.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RegistraKit as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RegistraKit::RegistraKit( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RegistraKit" );
    RegistraKitLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistraKitLayout"); 

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( textLabel1_2 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    layout1_2->addWidget( QCBProductos );

    RegistraKitLayout->addLayout( layout1_2, 0, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QTEDescripcion );

    RegistraKitLayout->addLayout( layout2, 1, 0 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout12->addWidget( QPBAceptar );

    pushButton5_2 = new QPushButton( this, "pushButton5_2" );
    pushButton5_2->setAutoDefault( FALSE );
    layout12->addWidget( pushButton5_2 );

    RegistraKitLayout->addLayout( layout12, 2, 0 );
    languageChange();
    resize( QSize(612, 238).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistraKit::~RegistraKit()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistraKit::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_2->setText( tr( "Producto" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    pushButton5_2->setText( tr( "pushButton5" ) );
}

