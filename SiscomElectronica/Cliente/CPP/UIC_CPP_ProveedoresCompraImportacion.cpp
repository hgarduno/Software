/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProveedoresCompraImportacion.ui'
**
** Created: lun abr 1 18:57:56 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProveedoresCompraImportacion.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ProveedoresCompraImportacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ProveedoresCompraImportacion::ProveedoresCompraImportacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ProveedoresCompraImportacion" );
    ProveedoresCompraImportacionLayout = new QGridLayout( this, 1, 1, 11, 6, "ProveedoresCompraImportacionLayout"); 

    layout63 = new QVBoxLayout( 0, 0, 6, "layout63"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout63->addWidget( textLabel1 );

    QTProveedores = new QTable( this, "QTProveedores" );
    QTProveedores->setNumCols( QTProveedores->numCols() + 1 );
    QTProveedores->horizontalHeader()->setLabel( QTProveedores->numCols() - 1, tr( "Empresa" ) );
    QTProveedores->setNumRows( 0 );
    QTProveedores->setNumCols( 1 );
    layout63->addWidget( QTProveedores );

    ProveedoresCompraImportacionLayout->addLayout( layout63, 0, 0 );
    languageChange();
    resize( QSize(530, 218).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProveedoresCompraImportacion::~ProveedoresCompraImportacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProveedoresCompraImportacion::languageChange()
{
    setCaption( tr( "Proveedores en la compra" ) );
    textLabel1->setText( tr( "Empresas" ) );
    QTProveedores->horizontalHeader()->setLabel( 0, tr( "Empresa" ) );
}

