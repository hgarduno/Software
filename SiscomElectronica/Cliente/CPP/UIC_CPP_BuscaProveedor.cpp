/****************************************************************************
** Form implementation generated from reading ui file 'UI/BuscaProveedor.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_BuscaProveedor.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a BuscaProveedor as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
BuscaProveedor::BuscaProveedor( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "BuscaProveedor" );
    BuscaProveedorLayout = new QGridLayout( this, 1, 1, 11, 6, "BuscaProveedorLayout"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout36->addWidget( textLabel1 );

    QCBRSocial = new QComboBox( FALSE, this, "QCBRSocial" );
    QCBRSocial->setEditable( TRUE );
    QCBRSocial->setInsertionPolicy( QComboBox::NoInsertion );
    QCBRSocial->setAutoCompletion( TRUE );
    QCBRSocial->setDuplicatesEnabled( FALSE );
    layout36->addWidget( QCBRSocial );

    BuscaProveedorLayout->addMultiCellLayout( layout36, 0, 0, 0, 1 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    layout40 = new QHBoxLayout( 0, 0, 6, "layout40"); 

    layout37 = new QVBoxLayout( 0, 0, 6, "layout37"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout37->addWidget( textLabel2 );

    lineEdit15 = new QLineEdit( this, "lineEdit15" );
    layout37->addWidget( lineEdit15 );
    layout40->addLayout( layout37 );

    layout37_2 = new QVBoxLayout( 0, 0, 6, "layout37_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout37_2->addWidget( textLabel2_2 );

    lineEdit15_2 = new QLineEdit( this, "lineEdit15_2" );
    layout37_2->addWidget( lineEdit15_2 );
    layout40->addLayout( layout37_2 );
    layout41->addLayout( layout40 );

    layout38 = new QVBoxLayout( 0, 0, 6, "layout38"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout38->addWidget( textLabel3 );

    QTEDireccion = new QTextEdit( this, "QTEDireccion" );
    layout38->addWidget( QTEDireccion );
    layout41->addLayout( layout38 );

    BuscaProveedorLayout->addMultiCellLayout( layout41, 1, 1, 0, 1 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    QPBAceptar->setDefault( FALSE );

    BuscaProveedorLayout->addWidget( QPBAceptar, 2, 0 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    QPBCancelar->setDefault( FALSE );

    BuscaProveedorLayout->addWidget( QPBCancelar, 2, 1 );
    languageChange();
    resize( QSize(600, 350).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
BuscaProveedor::~BuscaProveedor()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void BuscaProveedor::languageChange()
{
    setCaption( tr( "Proveedores" ) );
    textLabel1->setText( tr( "Proveedor" ) );
    textLabel2->setText( tr( "RFC" ) );
    textLabel2_2->setText( tr( "Razon Social" ) );
    textLabel3->setText( tr( "Direccion" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

