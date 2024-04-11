/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductosFaltantes.ui'
**
** Created: Wed Apr 10 20:52:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductosFaltantes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ProductosFaltantes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ProductosFaltantes::ProductosFaltantes( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ProductosFaltantes" );
    ProductosFaltantesLayout = new QGridLayout( this, 1, 1, 11, 6, "ProductosFaltantesLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBFaltantes = new QPushButton( this, "QPBFaltantes" );
    layout1->addWidget( QPBFaltantes );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout1->addWidget( pushButton1_2 );

    ProductosFaltantesLayout->addLayout( layout1, 1, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Veces Pedido" ) );
    QTDatos->setEnabled( TRUE );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 2 );
    QTDatos->setReadOnly( TRUE );
    layout2->addWidget( QTDatos );

    ProductosFaltantesLayout->addLayout( layout2, 0, 0 );
    languageChange();
    resize( QSize(537, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductosFaltantes::~ProductosFaltantes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductosFaltantes::languageChange()
{
    setCaption( tr( "Faltante de Productos" ) );
    QPBFaltantes->setText( tr( "Faltantes" ) );
    pushButton1_2->setText( tr( "pushButton1" ) );
    textLabel1->setText( tr( "Productos" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Veces Pedido" ) );
}

