/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductosSimilares.ui'
**
** Created: Thu Dec 21 12:53:44 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductosSimilares.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ProductosSimilares as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ProductosSimilares::ProductosSimilares( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ProductosSimilares" );
    ProductosSimilaresLayout = new QGridLayout( this, 1, 1, 11, 6, "ProductosSimilaresLayout"); 

    layout5_3 = new QVBoxLayout( 0, 0, 6, "layout5_3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout5_3->addWidget( textLabel1_3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout5_3->addWidget( QTEDescripcion );

    ProductosSimilaresLayout->addLayout( layout5_3, 1, 0 );

    layout45 = new QVBoxLayout( 0, 0, 6, "layout45"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout45->addWidget( textLabel1 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Descripcion" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Exis" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Bodega" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Precio" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Estante" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Caja" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Persona" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 8 );
    QTProductos->setReadOnly( TRUE );
    layout45->addWidget( QTProductos );

    ProductosSimilaresLayout->addLayout( layout45, 0, 0 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );

    ProductosSimilaresLayout->addWidget( QPBAceptar, 2, 0 );
    languageChange();
    resize( QSize(872, 541).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductosSimilares::~ProductosSimilares()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductosSimilares::languageChange()
{
    setCaption( tr( "Productos" ) );
    textLabel1_3->setText( tr( "Informacion Producto" ) );
    textLabel1->setText( tr( "Productos" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Exis" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Bodega" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "Precio" ) );
    QTProductos->horizontalHeader()->setLabel( 5, tr( "Estante" ) );
    QTProductos->horizontalHeader()->setLabel( 6, tr( "Caja" ) );
    QTProductos->horizontalHeader()->setLabel( 7, tr( "Persona" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
}

