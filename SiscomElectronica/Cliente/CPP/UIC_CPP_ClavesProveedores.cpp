/****************************************************************************
** Form implementation generated from reading ui file 'UI/ClavesProveedores.ui'
**
** Created: Thu Apr 11 21:39:56 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ClavesProveedores.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ClavesProveedores as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ClavesProveedores::ClavesProveedores( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ClavesProveedores" );
    ClavesProveedoresLayout = new QGridLayout( this, 1, 1, 11, 6, "ClavesProveedoresLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    layout1->addWidget( QCBProductos );

    ClavesProveedoresLayout->addLayout( layout1, 0, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout2->addWidget( textLabel3 );

    QTClavesProveedor = new QTable( this, "QTClavesProveedor" );
    QTClavesProveedor->setNumCols( QTClavesProveedor->numCols() + 1 );
    QTClavesProveedor->horizontalHeader()->setLabel( QTClavesProveedor->numCols() - 1, tr( "Proveedor" ) );
    QTClavesProveedor->setNumCols( QTClavesProveedor->numCols() + 1 );
    QTClavesProveedor->horizontalHeader()->setLabel( QTClavesProveedor->numCols() - 1, tr( "Clave Proveedor" ) );
    QTClavesProveedor->setNumRows( 0 );
    QTClavesProveedor->setNumCols( 2 );
    QTClavesProveedor->setReadOnly( TRUE );
    layout2->addWidget( QTClavesProveedor );

    ClavesProveedoresLayout->addLayout( layout2, 1, 0 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout3->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout3->addWidget( QTEDescripcion );

    ClavesProveedoresLayout->addLayout( layout3, 2, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout4->addWidget( pushButton1 );

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout4->addWidget( pushButton2 );

    ClavesProveedoresLayout->addLayout( layout4, 3, 0 );
    languageChange();
    resize( QSize(594, 510).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ClavesProveedores::~ClavesProveedores()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ClavesProveedores::languageChange()
{
    setCaption( tr( "Administracion de Claves de Proveedores" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel3->setText( tr( "Proveedores" ) );
    QTClavesProveedor->horizontalHeader()->setLabel( 0, tr( "Proveedor" ) );
    QTClavesProveedor->horizontalHeader()->setLabel( 1, tr( "Clave Proveedor" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    pushButton1->setText( tr( "Consultar" ) );
    pushButton2->setText( tr( "Asignar Clave Proveedor" ) );
}

