/****************************************************************************
** Form implementation generated from reading ui file 'UI/AnexarProducto.ui'
**
** Created: Thu Apr 11 20:30:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AnexarProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlProductos3Qt.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductos3Qt.h"

/*
 *  Constructs a AnexarProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AnexarProducto::AnexarProducto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "AnexarProducto" );
    AnexarProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "AnexarProductoLayout"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductos3Qt( this, "QCtrProductos" );
    QCtrProductos->setEnabled( TRUE );
    layout1->addWidget( QCtrProductos );
    layout19->addLayout( layout1 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout17->addWidget( textLabel4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout17->addWidget( QLECantidad );
    layout18->addLayout( layout17 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout18->addItem( spacer1 );
    layout19->addLayout( layout18 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout3_2->addWidget( textLabel2_2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout3_2->addWidget( QTEDescripcion );
    layout19->addLayout( layout3_2 );

    AnexarProductoLayout->addLayout( layout19, 0, 0 );

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setAutoDefault( FALSE );
    layout26->addWidget( QPBAnexar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout26->addWidget( QPBCancelar );

    AnexarProductoLayout->addLayout( layout26, 1, 0 );
    languageChange();
    resize( QSize(320, 271).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AnexarProducto::~AnexarProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AnexarProducto::languageChange()
{
    setCaption( tr( "Anexar Producto" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel4->setText( tr( "Cantidad" ) );
    textLabel2_2->setText( tr( "Descripcion" ) );
    QPBAnexar->setText( tr( "Anexa Producto" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

