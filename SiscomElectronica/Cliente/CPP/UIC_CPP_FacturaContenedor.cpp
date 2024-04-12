/****************************************************************************
** Form implementation generated from reading ui file 'UI/FacturaContenedor.ui'
**
** Created: Thu Apr 11 21:39:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_FacturaContenedor.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlProveedoresSE.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSE.h"

/*
 *  Constructs a FacturaContenedor as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FacturaContenedor::FacturaContenedor( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "FacturaContenedor" );
    FacturaContenedorLayout = new QGridLayout( this, 1, 1, 11, 6, "FacturaContenedorLayout"); 

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout25->addWidget( textLabel1_3 );

    QCtrProveedores = new QCtrlProveedoresSE( this, "QCtrProveedores" );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    QCtrProveedores->setMinimumSize( QSize( 250, 0 ) );
    QCtrProveedores->setMaximumSize( QSize( 1000, 32767 ) );
    layout25->addWidget( QCtrProveedores );

    FacturaContenedorLayout->addLayout( layout25, 0, 0 );

    layout1_4 = new QVBoxLayout( 0, 0, 6, "layout1_4"); 

    textLabel1_6 = new QLabel( this, "textLabel1_6" );
    textLabel1_6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_6->sizePolicy().hasHeightForWidth() ) );
    layout1_4->addWidget( textLabel1_6 );

    QLENumFactura = new QLineEdit( this, "QLENumFactura" );
    QLENumFactura->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumFactura->sizePolicy().hasHeightForWidth() ) );
    layout1_4->addWidget( QLENumFactura );

    FacturaContenedorLayout->addLayout( layout1_4, 0, 1 );

    layout1_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2"); 

    textLabel1_2_2_2 = new QLabel( this, "textLabel1_2_2_2" );
    textLabel1_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2->addWidget( textLabel1_2_2_2 );

    QLENumPartidas = new QLineEdit( this, "QLENumPartidas" );
    QLENumPartidas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumPartidas->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2->addWidget( QLENumPartidas );

    FacturaContenedorLayout->addLayout( layout1_2_2_2, 0, 2 );

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    textLabel1_8 = new QLabel( this, "textLabel1_8" );
    layout27->addWidget( textLabel1_8 );

    QLEDscCompra = new QLineEdit( this, "QLEDscCompra" );
    layout27->addWidget( QLEDscCompra );

    FacturaContenedorLayout->addMultiCellLayout( layout27, 1, 1, 0, 2 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );

    FacturaContenedorLayout->addMultiCellWidget( QPBAceptar, 2, 2, 0, 2 );
    languageChange();
    resize( QSize(535, 155).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FacturaContenedor::~FacturaContenedor()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FacturaContenedor::languageChange()
{
    setCaption( tr( "Form2" ) );
    textLabel1_3->setText( tr( "Proveedores\n"
"Siscom" ) );
    textLabel1_6->setText( tr( "Factura" ) );
    textLabel1_2_2_2->setText( tr( "Numero\n"
"Partidas" ) );
    textLabel1_8->setText( tr( "Descripcion Compra" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
}

