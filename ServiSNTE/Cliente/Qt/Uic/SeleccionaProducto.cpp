/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/SeleccionaProducto.ui'
**
** Created: Thu Apr 11 21:07:12 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "SeleccionaProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProductosSS.h"

/*
 *  Constructs a SeleccionaProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SeleccionaProducto::SeleccionaProducto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SeleccionaProducto" );
    SeleccionaProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "SeleccionaProductoLayout"); 

    layout54 = new QVBoxLayout( 0, 0, 6, "layout54"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout54->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSS( this, "QCtrProductos" );
    layout54->addWidget( QCtrProductos );

    SeleccionaProductoLayout->addLayout( layout54, 0, 0 );

    layout49 = new QHBoxLayout( 0, 0, 6, "layout49"); 

    layout40 = new QVBoxLayout( 0, 0, 6, "layout40"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout40->addWidget( textLabel1_2 );

    lineEdit79 = new QLineEdit( this, "lineEdit79" );
    lineEdit79->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit79->sizePolicy().hasHeightForWidth() ) );
    layout40->addWidget( lineEdit79 );
    layout49->addLayout( layout40 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout41->addWidget( textLabel4 );

    lineEdit80 = new QLineEdit( this, "lineEdit80" );
    layout41->addWidget( lineEdit80 );
    layout49->addLayout( layout41 );

    SeleccionaProductoLayout->addLayout( layout49, 1, 0 );

    layout356 = new QHBoxLayout( 0, 0, 6, "layout356"); 

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout42->addWidget( textLabel5 );

    lineEdit81 = new QLineEdit( this, "lineEdit81" );
    lineEdit81->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, lineEdit81->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( lineEdit81 );
    layout356->addLayout( layout42 );

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout43->addWidget( textLabel6 );

    lineEdit82 = new QLineEdit( this, "lineEdit82" );
    layout43->addWidget( lineEdit82 );
    layout356->addLayout( layout43 );

    SeleccionaProductoLayout->addLayout( layout356, 2, 0 );

    layout89 = new QHBoxLayout( 0, 0, 6, "layout89"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout89->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout89->addWidget( QPBCancelar );

    SeleccionaProductoLayout->addLayout( layout89, 4, 0 );

    layout76 = new QVBoxLayout( 0, 0, 6, "layout76"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout76->addWidget( textLabel3 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Numero Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Modelo" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 3 );
    layout76->addWidget( QTProductos );

    SeleccionaProductoLayout->addLayout( layout76, 3, 0 );
    languageChange();
    resize( QSize(594, 520).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SeleccionaProducto::~SeleccionaProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SeleccionaProducto::languageChange()
{
    setCaption( tr( "Form2" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel1_2->setText( tr( "Clave Producto:" ) );
    textLabel4->setText( tr( "Nombre Producto:" ) );
    textLabel5->setText( tr( "Modelo:" ) );
    textLabel6->setText( tr( "Serie:" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel3->setText( tr( "Lista Productos" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Numero Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
}

