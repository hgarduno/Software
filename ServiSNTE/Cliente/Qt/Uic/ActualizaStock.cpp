/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ActualizaStock.ui'
**
** Created: Thu Apr 11 21:07:39 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ActualizaStock.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlProveedoresSS.h"
#include "QCtrlProductosSS.h"
#include "QCtrlStock.h"

/*
 *  Constructs a ActualizaStock as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActualizaStock::ActualizaStock( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActualizaStock" );
    ActualizaStockLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaStockLayout"); 

    layout59 = new QVBoxLayout( 0, 0, 6, "layout59"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout59->addWidget( textLabel3 );

    QLEStock = new QLineEdit( this, "QLEStock" );
    QLEStock->setEnabled( FALSE );
    layout59->addWidget( QLEStock );

    ActualizaStockLayout->addLayout( layout59, 1, 0 );

    layout61 = new QHBoxLayout( 0, 0, 6, "layout61"); 

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    layout61->addWidget( QPBConsulta );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( FALSE );
    layout61->addWidget( QPBActualizar );

    ActualizaStockLayout->addLayout( layout61, 3, 0 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout56 = new QVBoxLayout( 0, 0, 6, "layout56"); 

    Tienda = new QLabel( this, "Tienda" );
    layout56->addWidget( Tienda );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    layout56->addWidget( QCtrTiendas );
    layout8->addLayout( layout56 );

    layout57 = new QVBoxLayout( 0, 0, 6, "layout57"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout57->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    QCtrProveedores->setEnabled( FALSE );
    layout57->addWidget( QCtrProveedores );
    layout8->addLayout( layout57 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_2_3 = new QLabel( this, "textLabel1_2_3" );
    textLabel1_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_3->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1_2_3 );

    QCtrProductos = new QCtrlProductosSS( this, "QCtrProductos" );
    QCtrProductos->setEnabled( FALSE );
    layout7->addWidget( QCtrProductos );
    layout8->addLayout( layout7 );

    ActualizaStockLayout->addLayout( layout8, 0, 0 );

    layout7_2 = new QVBoxLayout( 0, 0, 6, "layout7_2"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout7_2->addWidget( textLabel4 );

    QCtrStock = new QCtrlStock( this, "QCtrStock" );
    QCtrStock->setNumRows( 0 );
    QCtrStock->setNumCols( 0 );
    layout7_2->addWidget( QCtrStock );

    ActualizaStockLayout->addLayout( layout7_2, 2, 0 );
    languageChange();
    resize( QSize(828, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaStock::~ActualizaStock()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaStock::languageChange()
{
    setCaption( tr( "Actualiza Stock" ) );
    textLabel3->setText( tr( "Stock" ) );
    QPBConsulta->setText( tr( "Consultando" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    Tienda->setText( tr( "Tiendas" ) );
    textLabel2->setText( tr( "Proveedor" ) );
    textLabel1_2_3->setText( tr( "Numero Producto" ) );
    textLabel4->setText( tr( "Stock" ) );
}

