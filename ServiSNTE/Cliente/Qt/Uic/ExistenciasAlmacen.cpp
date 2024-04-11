/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ExistenciasAlmacen.ui'
**
** Created: Thu Apr 11 21:07:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ExistenciasAlmacen.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a ExistenciasAlmacen as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ExistenciasAlmacen::ExistenciasAlmacen( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ExistenciasAlmacen" );
    ExistenciasAlmacenLayout = new QGridLayout( this, 1, 1, 11, 6, "ExistenciasAlmacenLayout"); 

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout33->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    layout33->addWidget( QCtrProveedores );
    layout10->addLayout( layout33 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QTExistencias = new QTable( this, "QTExistencias" );
    QTExistencias->setNumCols( QTExistencias->numCols() + 1 );
    QTExistencias->horizontalHeader()->setLabel( QTExistencias->numCols() - 1, tr( "Producto" ) );
    QTExistencias->setNumCols( QTExistencias->numCols() + 1 );
    QTExistencias->horizontalHeader()->setLabel( QTExistencias->numCols() - 1, tr( "Modelo" ) );
    QTExistencias->setNumCols( QTExistencias->numCols() + 1 );
    QTExistencias->horizontalHeader()->setLabel( QTExistencias->numCols() - 1, tr( "Num Proveedor" ) );
    QTExistencias->setNumCols( QTExistencias->numCols() + 1 );
    QTExistencias->horizontalHeader()->setLabel( QTExistencias->numCols() - 1, tr( "Existencia" ) );
    QTExistencias->setNumRows( 0 );
    QTExistencias->setNumCols( 4 );
    layout1->addWidget( QTExistencias );
    layout10->addLayout( layout1 );
    layout11->addLayout( layout10 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout13->addWidget( textLabel3 );

    QTEListaProductos = new QTextEdit( this, "QTEListaProductos" );
    QTEListaProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, QTEListaProductos->sizePolicy().hasHeightForWidth() ) );
    QTEListaProductos->setWordWrap( QTextEdit::WidgetWidth );
    QTEListaProductos->setReadOnly( FALSE );
    layout13->addWidget( QTEListaProductos );
    layout11->addLayout( layout13 );

    ExistenciasAlmacenLayout->addLayout( layout11, 0, 0 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    QPBExistenciasProveedor = new QPushButton( this, "QPBExistenciasProveedor" );
    layout12->addWidget( QPBExistenciasProveedor );

    QPBPorProducto = new QPushButton( this, "QPBPorProducto" );
    layout12->addWidget( QPBPorProducto );

    QPBExistenciasListaProductos = new QPushButton( this, "QPBExistenciasListaProductos" );
    layout12->addWidget( QPBExistenciasListaProductos );

    ExistenciasAlmacenLayout->addLayout( layout12, 1, 0 );
    languageChange();
    resize( QSize(807, 623).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ExistenciasAlmacen::~ExistenciasAlmacen()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ExistenciasAlmacen::languageChange()
{
    setCaption( tr( "Existencias Almacen" ) );
    textLabel2->setText( tr( "Clave Proveedor" ) );
    textLabel1->setText( tr( "Existencias" ) );
    QTExistencias->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTExistencias->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTExistencias->horizontalHeader()->setLabel( 2, tr( "Num Proveedor" ) );
    QTExistencias->horizontalHeader()->setLabel( 3, tr( "Existencia" ) );
    textLabel3->setText( tr( "Codigo Barras" ) );
    QTEListaProductos->setText( QString::null );
    QPBExistenciasProveedor->setText( tr( "Proveedor" ) );
    QPBExistenciasProveedor->setAccel( QKeySequence( QString::null ) );
    QPBPorProducto->setText( tr( "Por Producto" ) );
    QPBPorProducto->setAccel( QKeySequence( QString::null ) );
    QPBExistenciasListaProductos->setText( tr( "Existencias Lista Productos" ) );
    QPBExistenciasListaProductos->setAccel( QKeySequence( QString::null ) );
}

