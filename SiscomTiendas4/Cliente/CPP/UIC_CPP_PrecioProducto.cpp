/****************************************************************************
** Form implementation generated from reading ui file 'UI/PrecioProducto.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PrecioProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlPrecios.h>
#include <QCtrlProductos.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlPrecios.h"
#include "QCtrlProductos.h"

/*
 *  Constructs a PrecioProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PrecioProducto::PrecioProducto( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PrecioProducto" );
    PrecioProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "PrecioProductoLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrPrecios = new QCtrlPrecios( this, "QCtrPrecios" );
    QCtrPrecios->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrPrecios->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrPrecios );

    PrecioProductoLayout->addLayout( layout1, 0, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProductos( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCtrProductos );

    PrecioProductoLayout->addLayout( layout2, 0, 1 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    QPBActualiza = new QPushButton( this, "QPBActualiza" );
    layout15->addWidget( QPBActualiza );

    QPBIniciaPrecios = new QPushButton( this, "QPBIniciaPrecios" );
    layout15->addWidget( QPBIniciaPrecios );

    pushButton4 = new QPushButton( this, "pushButton4" );
    layout15->addWidget( pushButton4 );

    PrecioProductoLayout->addMultiCellLayout( layout15, 5, 5, 0, 1 );

    textLabel4_2 = new QLabel( this, "textLabel4_2" );

    PrecioProductoLayout->addWidget( textLabel4_2, 3, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Valor" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );

    PrecioProductoLayout->addMultiCellWidget( QTDatos, 4, 4, 0, 1 );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout17->addWidget( textLabel4 );

    QTEDscProducto = new QTextEdit( this, "QTEDscProducto" );
    QTEDscProducto->setReadOnly( TRUE );
    layout17->addWidget( QTEDscProducto );

    PrecioProductoLayout->addLayout( layout17, 1, 1 );

    layout17_2 = new QVBoxLayout( 0, 0, 6, "layout17_2"); 

    textLabel4_3 = new QLabel( this, "textLabel4_3" );
    layout17_2->addWidget( textLabel4_3 );

    QTEDscPrecio = new QTextEdit( this, "QTEDscPrecio" );
    QTEDscPrecio->setReadOnly( TRUE );
    layout17_2->addWidget( QTEDscPrecio );

    PrecioProductoLayout->addLayout( layout17_2, 1, 0 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel3 );

    QLEPrecio = new QLineEdit( this, "QLEPrecio" );
    layout3->addWidget( QLEPrecio );
    layout9->addLayout( layout3 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( textLabel3_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout3_2->addWidget( QLECantidad );
    layout9->addLayout( layout3_2 );
    spacer2 = new QSpacerItem( 123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout9->addItem( spacer2 );

    PrecioProductoLayout->addMultiCellLayout( layout9, 2, 2, 0, 1 );
    languageChange();
    resize( QSize(536, 481).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PrecioProducto::~PrecioProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PrecioProducto::languageChange()
{
    setCaption( tr( "Asigna Precio Al Producto" ) );
    textLabel1->setText( tr( "Precios" ) );
    textLabel2->setText( tr( "Productos" ) );
    QPBActualiza->setText( tr( "Actualiza Precio" ) );
    QPBIniciaPrecios->setText( tr( "Inicia Precios De Los Productos" ) );
    pushButton4->setText( tr( "pushButton4" ) );
    textLabel4_2->setText( tr( "Precios Del Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Valor" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    textLabel4->setText( tr( "Descripcion Producto" ) );
    textLabel4_3->setText( tr( "Descripcion Precio" ) );
    textLabel3->setText( tr( "Precio" ) );
    textLabel3_2->setText( tr( "Cantidad" ) );
}

