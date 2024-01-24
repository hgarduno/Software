/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductosSinSincronizar.ui'
**
** Created: Thu Dec 21 12:53:42 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductosSinSincronizar.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ProductosSinSincronizar as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ProductosSinSincronizar::ProductosSinSincronizar( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ProductosSinSincronizar" );
    ProductosSinSincronizarLayout = new QGridLayout( this, 1, 1, 11, 6, "ProductosSinSincronizarLayout"); 

    textLabel1 = new QLabel( this, "textLabel1" );

    ProductosSinSincronizarLayout->addWidget( textLabel1, 0, 0 );

    QTProdNoSincronizados = new QTable( this, "QTProdNoSincronizados" );
    QTProdNoSincronizados->setNumCols( QTProdNoSincronizados->numCols() + 1 );
    QTProdNoSincronizados->horizontalHeader()->setLabel( QTProdNoSincronizados->numCols() - 1, tr( "Expendio" ) );
    QTProdNoSincronizados->setNumCols( QTProdNoSincronizados->numCols() + 1 );
    QTProdNoSincronizados->horizontalHeader()->setLabel( QTProdNoSincronizados->numCols() - 1, tr( "Producto" ) );
    QTProdNoSincronizados->setNumRows( 0 );
    QTProdNoSincronizados->setNumCols( 2 );
    QTProdNoSincronizados->setReadOnly( TRUE );

    ProductosSinSincronizarLayout->addWidget( QTProdNoSincronizados, 1, 0 );

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    layout1->addWidget( QPBRegistra );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout1->addWidget( pushButton1_2 );

    ProductosSinSincronizarLayout->addLayout( layout1, 2, 0 );
    languageChange();
    resize( QSize(650, 351).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductosSinSincronizar::~ProductosSinSincronizar()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductosSinSincronizar::languageChange()
{
    setCaption( tr( "Productos Sin Sincronizar" ) );
    textLabel1->setText( tr( "Productos Sin Registrar" ) );
    QTProdNoSincronizados->horizontalHeader()->setLabel( 0, tr( "Expendio" ) );
    QTProdNoSincronizados->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QPBRegistra->setText( tr( "Registra Productos" ) );
    pushButton1_2->setText( tr( "Elimina Productos Para Sincronizacion" ) );
}

