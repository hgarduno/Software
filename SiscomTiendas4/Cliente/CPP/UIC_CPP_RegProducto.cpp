/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegProducto.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlFamilias.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFamilias.h"

/*
 *  Constructs a RegProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegProducto::RegProducto( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegProducto" );
    RegProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "RegProductoLayout"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout3->addWidget( textLabel2_2 );

    QCtrFamilias = new QCtrlFamilias( this, "QCtrFamilias" );
    QCtrFamilias->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrFamilias->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrFamilias );
    layout4->addLayout( layout3 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout14->addWidget( textLabel2 );

    QLEClave = new QLineEdit( this, "QLEClave" );
    QLEClave->setEnabled( FALSE );
    layout14->addWidget( QLEClave );
    layout4->addLayout( layout14 );
    layout5->addLayout( layout4 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout15->addWidget( textLabel3 );

    QTEDsc = new QTextEdit( this, "QTEDsc" );
    QTEDsc->setEnabled( FALSE );
    layout15->addWidget( QTEDsc );
    layout5->addLayout( layout15 );

    RegProductoLayout->addLayout( layout5, 0, 0 );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setEnabled( FALSE );

    RegProductoLayout->addWidget( QPBRegistra, 1, 0 );
    languageChange();
    resize( QSize(600, 306).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegProducto::~RegProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegProducto::languageChange()
{
    setCaption( tr( "Registro De Productos" ) );
    textLabel2_2->setText( tr( "Familias" ) );
    textLabel2->setText( tr( "Clave Del Producto" ) );
    textLabel3->setText( tr( "Descripcion" ) );
    QPBRegistra->setText( tr( "Registra Producto" ) );
}

