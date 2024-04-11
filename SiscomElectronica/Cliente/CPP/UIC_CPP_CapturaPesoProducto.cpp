/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaPesoProducto.ui'
**
** Created: Wed Apr 10 20:52:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaPesoProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaPesoProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaPesoProducto::CapturaPesoProducto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaPesoProducto" );
    CapturaPesoProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaPesoProductoLayout"); 

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );
    layout20->addWidget( QPBRegistrar );

    QPBTerminar = new QPushButton( this, "QPBTerminar" );
    QPBTerminar->setAutoDefault( FALSE );
    layout20->addWidget( QPBTerminar );

    CapturaPesoProductoLayout->addLayout( layout20, 1, 0 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    layout1_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_3_2_2"); 

    textLabel1_4_2_2 = new QLabel( this, "textLabel1_4_2_2" );
    textLabel1_4_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2_2->addWidget( textLabel1_4_2_2 );

    QLEProducto = new QLineEdit( this, "QLEProducto" );
    QLEProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEProducto->sizePolicy().hasHeightForWidth() ) );
    QLEProducto->setReadOnly( TRUE );
    layout1_3_2_2->addWidget( QLEProducto );
    layout21->addLayout( layout1_3_2_2 );

    layout1_3_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_3_2_2_2"); 

    textLabel1_4_2_2_2 = new QLabel( this, "textLabel1_4_2_2_2" );
    textLabel1_4_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2_2_2->addWidget( textLabel1_4_2_2_2 );

    QLEPeso = new QLineEdit( this, "QLEPeso" );
    QLEPeso->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPeso->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2_2_2->addWidget( QLEPeso );
    layout21->addLayout( layout1_3_2_2_2 );

    CapturaPesoProductoLayout->addLayout( layout21, 0, 0 );
    languageChange();
    resize( QSize(543, 96).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaPesoProducto::~CapturaPesoProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaPesoProducto::languageChange()
{
    setCaption( tr( "Form1" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBTerminar->setText( tr( "Terminar" ) );
    textLabel1_4_2_2->setText( tr( "Producto" ) );
    textLabel1_4_2_2_2->setText( tr( "Peso Unitario" ) );
}

