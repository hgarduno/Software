/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ExistenciasTienda.ui'
**
** Created: Thu Apr 11 21:07:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ExistenciasTienda.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a ExistenciasTienda as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ExistenciasTienda::ExistenciasTienda( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ExistenciasTienda" );
    ExistenciasTiendaLayout = new QGridLayout( this, 1, 1, 11, 6, "ExistenciasTiendaLayout"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout2->addWidget( textLabel2_2 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    QCtrTiendas->setEnabled( TRUE );
    QCtrTiendas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrTiendas->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCtrTiendas );
    layout16->addLayout( layout2 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout14->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    layout14->addWidget( QCtrProveedores );
    layout16->addLayout( layout14 );
    layout17->addLayout( layout16 );

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
    QTExistencias->setNumCols( QTExistencias->numCols() + 1 );
    QTExistencias->horizontalHeader()->setLabel( QTExistencias->numCols() - 1, tr( "Stock" ) );
    QTExistencias->setNumRows( 0 );
    QTExistencias->setNumCols( 5 );
    layout1->addWidget( QTExistencias );
    layout17->addLayout( layout1 );
    layout13->addLayout( layout17 );

    layout13_2 = new QVBoxLayout( 0, 0, 6, "layout13_2"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout13_2->addWidget( textLabel3 );

    QTEListaProductos = new QTextEdit( this, "QTEListaProductos" );
    QTEListaProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, QTEListaProductos->sizePolicy().hasHeightForWidth() ) );
    QTEListaProductos->setWordWrap( QTextEdit::WidgetWidth );
    QTEListaProductos->setReadOnly( FALSE );
    layout13_2->addWidget( QTEListaProductos );
    layout13->addLayout( layout13_2 );

    ExistenciasTiendaLayout->addLayout( layout13, 0, 0 );

    layout17_2 = new QHBoxLayout( 0, 0, 6, "layout17_2"); 

    QPBTodosLosProductos = new QPushButton( this, "QPBTodosLosProductos" );
    layout17_2->addWidget( QPBTodosLosProductos );

    QPBExistenciasProveedor = new QPushButton( this, "QPBExistenciasProveedor" );
    layout17_2->addWidget( QPBExistenciasProveedor );

    QPBExistenciasProducto = new QPushButton( this, "QPBExistenciasProducto" );
    layout17_2->addWidget( QPBExistenciasProducto );

    QPBExistenciasListaProductos = new QPushButton( this, "QPBExistenciasListaProductos" );
    layout17_2->addWidget( QPBExistenciasListaProductos );

    ExistenciasTiendaLayout->addLayout( layout17_2, 1, 0 );
    languageChange();
    resize( QSize(876, 493).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ExistenciasTienda::~ExistenciasTienda()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ExistenciasTienda::languageChange()
{
    setCaption( tr( "Existencias Piso" ) );
    textLabel2_2->setText( tr( "Tienda" ) );
    textLabel2->setText( tr( "Clave Proveedor" ) );
    textLabel1->setText( tr( "Existencias" ) );
    QTExistencias->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTExistencias->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTExistencias->horizontalHeader()->setLabel( 2, tr( "Num Proveedor" ) );
    QTExistencias->horizontalHeader()->setLabel( 3, tr( "Existencia" ) );
    QTExistencias->horizontalHeader()->setLabel( 4, tr( "Stock" ) );
    textLabel3->setText( tr( "Codigo Barras" ) );
    QTEListaProductos->setText( QString::null );
    QPBTodosLosProductos->setText( tr( "Todos Los Productos" ) );
    QPBExistenciasProveedor->setText( tr( "Proveedor" ) );
    QPBExistenciasProducto->setText( tr( "Por Producto" ) );
    QPBExistenciasListaProductos->setText( tr( "Existencias Lista Productos" ) );
    QPBExistenciasListaProductos->setAccel( QKeySequence( QString::null ) );
}

