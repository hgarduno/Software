/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductosInventariar.ui'
**
** Created: Wed Apr 10 21:12:25 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductosInventariar.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ProductosInventariar as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ProductosInventariar::ProductosInventariar( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ProductosInventariar" );
    ProductosInventariarLayout = new QGridLayout( this, 1, 1, 11, 6, "ProductosInventariarLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    comboBox1 = new QComboBox( FALSE, this, "comboBox1" );
    comboBox1->setEditable( TRUE );
    comboBox1->setInsertionPolicy( QComboBox::NoInsertion );
    comboBox1->setAutoCompletion( TRUE );
    comboBox1->setDuplicatesEnabled( FALSE );
    layout1->addWidget( comboBox1 );

    ProductosInventariarLayout->addMultiCellLayout( layout1, 0, 0, 0, 2 );

    pushButton3 = new QPushButton( this, "pushButton3" );

    ProductosInventariarLayout->addWidget( pushButton3, 5, 0 );

    pushButton3_2 = new QPushButton( this, "pushButton3_2" );

    ProductosInventariarLayout->addWidget( pushButton3_2, 5, 1 );

    pushButton2 = new QPushButton( this, "pushButton2" );

    ProductosInventariarLayout->addWidget( pushButton2, 5, 2 );

    table2_2 = new QTable( this, "table2_2" );
    table2_2->setNumCols( table2_2->numCols() + 1 );
    table2_2->horizontalHeader()->setLabel( table2_2->numCols() - 1, tr( "Producto" ) );
    table2_2->setNumCols( table2_2->numCols() + 1 );
    table2_2->horizontalHeader()->setLabel( table2_2->numCols() - 1, tr( "Descripcion" ) );
    table2_2->setNumCols( table2_2->numCols() + 1 );
    table2_2->horizontalHeader()->setLabel( table2_2->numCols() - 1, tr( "Estado Producto" ) );
    table2_2->setNumCols( table2_2->numCols() + 1 );
    table2_2->horizontalHeader()->setLabel( table2_2->numCols() - 1, tr( "Estado Registro" ) );
    table2_2->setNumRows( 0 );
    table2_2->setNumCols( 4 );

    ProductosInventariarLayout->addMultiCellWidget( table2_2, 4, 4, 0, 2 );

    textLabel2 = new QLabel( this, "textLabel2" );

    ProductosInventariarLayout->addMultiCellWidget( textLabel2, 3, 3, 0, 2 );

    table2 = new QTable( this, "table2" );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Producto" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Descripcion" ) );
    table2->setNumRows( 0 );
    table2->setNumCols( 2 );

    ProductosInventariarLayout->addMultiCellWidget( table2, 1, 1, 0, 2 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout2->addWidget( textLabel3 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    layout2->addWidget( lineEdit1 );

    ProductosInventariarLayout->addMultiCellLayout( layout2, 2, 2, 0, 2 );
    languageChange();
    resize( QSize(632, 470).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductosInventariar::~ProductosInventariar()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductosInventariar::languageChange()
{
    setCaption( tr( "Productos A Inventariar" ) );
    textLabel1->setText( tr( "Productos" ) );
    pushButton3->setText( tr( "Anexar" ) );
    pushButton3_2->setText( tr( "Eliminar" ) );
    pushButton2->setText( tr( "Registrar" ) );
    table2_2->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    table2_2->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    table2_2->horizontalHeader()->setLabel( 2, tr( "Estado Producto" ) );
    table2_2->horizontalHeader()->setLabel( 3, tr( "Estado Registro" ) );
    textLabel2->setText( tr( "Productos A Inventariar" ) );
    table2->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    table2->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    textLabel3->setText( tr( "Descripcion" ) );
}

