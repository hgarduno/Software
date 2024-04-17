/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorKits.ui'
**
** Created: Fri Apr 12 21:26:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorKits.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <QCtrlTiposProductoSE.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiposProductoSE.h"

/*
 *  Constructs a ManejadorKits as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorKits::ManejadorKits( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorKits" );
    ManejadorKitsLayout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorKitsLayout"); 

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    QPBRegistraKit = new QPushButton( this, "QPBRegistraKit" );
    QPBRegistraKit->setEnabled( FALSE );
    layout33->addWidget( QPBRegistraKit );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout33->addWidget( QPBAnexar );

    QPBEliminaProducto = new QPushButton( this, "QPBEliminaProducto" );
    QPBEliminaProducto->setEnabled( FALSE );
    layout33->addWidget( QPBEliminaProducto );

    QPBRegistraProductos = new QPushButton( this, "QPBRegistraProductos" );
    QPBRegistraProductos->setEnabled( FALSE );
    layout33->addWidget( QPBRegistraProductos );

    ManejadorKitsLayout->addLayout( layout33, 5, 0 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QTEDescripcion );
    layout15->addLayout( layout2 );

    ManejadorKitsLayout->addLayout( layout15, 4, 0 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Observaciones" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 3 );
    QTProductos->setReadOnly( TRUE );

    ManejadorKitsLayout->addWidget( QTProductos, 3, 0 );

    layout24 = new QHBoxLayout( 0, 0, 6, "layout24"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel1 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEnabled( FALSE );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout9->addWidget( QCBProductos );
    layout24->addLayout( layout9 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    layout8->addWidget( QLECantidad );
    layout24->addLayout( layout8 );

    ManejadorKitsLayout->addLayout( layout24, 2, 0 );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout23->addWidget( textLabel1_2 );

    QCtrTiposProducto = new QCtrlTiposProductoSE( this, "QCtrTiposProducto" );
    QCtrTiposProducto->setEnabled( TRUE );
    QCtrTiposProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrTiposProducto->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( QCtrTiposProducto );
    layout25->addLayout( layout23 );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( textLabel2_2 );

    QLEProductoTipoProducto = new QLineEdit( this, "QLEProductoTipoProducto" );
    QLEProductoTipoProducto->setReadOnly( TRUE );
    layout17->addWidget( QLEProductoTipoProducto );
    layout25->addLayout( layout17 );

    ManejadorKitsLayout->addLayout( layout25, 1, 0 );

    textLabel2_3 = new QLabel( this, "textLabel2_3" );

    ManejadorKitsLayout->addWidget( textLabel2_3, 0, 0 );
    languageChange();
    resize( QSize(628, 589).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorKits::~ManejadorKits()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorKits::languageChange()
{
    setCaption( tr( "Manejador de Kits" ) );
    QPBRegistraKit->setText( tr( "Registra Kit" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBEliminaProducto->setText( tr( "Eliminar Producto" ) );
    QPBRegistraProductos->setText( tr( "Registra Productos" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Observaciones" ) );
    textLabel1->setText( tr( "Producto" ) );
    textLabel3->setText( tr( "Cantidad" ) );
    textLabel1_2->setText( tr( "Tipo Producto" ) );
    textLabel2_2->setText( tr( "Kit" ) );
    textLabel2_3->setText( tr( "Algo" ) );
}

