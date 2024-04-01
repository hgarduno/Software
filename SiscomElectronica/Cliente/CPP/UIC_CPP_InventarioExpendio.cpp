/****************************************************************************
** Form implementation generated from reading ui file 'UI/InventarioExpendio.ui'
**
** Created: Wed Jan 31 10:48:12 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_InventarioExpendio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <QCtrlProductosSE.h>
#include <qlineedit.h>
#include <IMP_QControlFecha.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"
#include "IMP_QControlFecha.h"

/*
 *  Constructs a InventarioExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
InventarioExpendio::InventarioExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "InventarioExpendio" );
    InventarioExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "InventarioExpendioLayout"); 

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout8->addWidget( pushButton1 );

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout8->addWidget( pushButton2 );

    InventarioExpendioLayout->addLayout( layout8, 2, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout6->addWidget( textLabel1_2 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Producto" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Existencia" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Inventario" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Vendidos" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 4 );
    layout6->addWidget( table1 );

    InventarioExpendioLayout->addLayout( layout6, 1, 0 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrProductos );
    layout5->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    layout2->addWidget( lineEdit1 );
    layout5->addLayout( layout2 );
    layout9->addLayout( layout5 );

    layout8_2 = new QHBoxLayout( 0, 0, 6, "layout8_2"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel2_2 );

    cQControlFecha1 = new CQControlFecha( this, "cQControlFecha1" );
    cQControlFecha1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, cQControlFecha1->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( cQControlFecha1 );
    layout8_2->addLayout( layout7 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout8_2->addItem( spacer2 );
    layout9->addLayout( layout8_2 );
    layout10->addLayout( layout9 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel3 );

    textEdit1 = new QTextEdit( this, "textEdit1" );
    textEdit1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textEdit1->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textEdit1 );
    layout10->addLayout( layout3 );

    InventarioExpendioLayout->addLayout( layout10, 0, 0 );
    languageChange();
    resize( QSize(770, 523).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
InventarioExpendio::~InventarioExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void InventarioExpendio::languageChange()
{
    setCaption( tr( "Form1" ) );
    pushButton1->setText( tr( "pushButton1" ) );
    pushButton2->setText( tr( "pushButton2" ) );
    textLabel1_2->setText( tr( "textLabel1" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Existencia" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "Inventario" ) );
    table1->horizontalHeader()->setLabel( 3, tr( "Vendidos" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel2->setText( tr( "Cantidad" ) );
    textLabel2_2->setText( tr( "textLabel2" ) );
    textLabel3->setText( tr( "Descripcion" ) );
}

