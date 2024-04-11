/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaExpendio.ui'
**
** Created: Wed Apr 10 20:52:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaExpendio.h"

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
 *  Constructs a ActualizaExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActualizaExpendio::ActualizaExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActualizaExpendio" );
    ActualizaExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaExpendioLayout"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout10->addWidget( textLabel1 );

    QTExpendios = new QTable( this, "QTExpendios" );
    QTExpendios->setNumCols( QTExpendios->numCols() + 1 );
    QTExpendios->horizontalHeader()->setLabel( QTExpendios->numCols() - 1, tr( "Expendio" ) );
    QTExpendios->setNumCols( QTExpendios->numCols() + 1 );
    QTExpendios->horizontalHeader()->setLabel( QTExpendios->numCols() - 1, tr( "Fecha" ) );
    QTExpendios->setNumRows( 0 );
    QTExpendios->setNumCols( 2 );
    QTExpendios->setReadOnly( TRUE );
    layout10->addWidget( QTExpendios );

    ActualizaExpendioLayout->addLayout( layout10, 0, 0 );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout17->addWidget( textLabel1_2 );

    QTProdsNoExpendio = new QTable( this, "QTProdsNoExpendio" );
    QTProdsNoExpendio->setNumCols( QTProdsNoExpendio->numCols() + 1 );
    QTProdsNoExpendio->horizontalHeader()->setLabel( QTProdsNoExpendio->numCols() - 1, tr( "Productos" ) );
    QTProdsNoExpendio->setNumCols( QTProdsNoExpendio->numCols() + 1 );
    QTProdsNoExpendio->horizontalHeader()->setLabel( QTProdsNoExpendio->numCols() - 1, tr( "Precio" ) );
    QTProdsNoExpendio->setNumRows( 0 );
    QTProdsNoExpendio->setNumCols( 2 );
    layout17->addWidget( QTProdsNoExpendio );

    ActualizaExpendioLayout->addLayout( layout17, 1, 0 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    QPBProductos = new QPushButton( this, "QPBProductos" );
    layout19->addWidget( QPBProductos );

    pushButton6_2 = new QPushButton( this, "pushButton6_2" );
    layout19->addWidget( pushButton6_2 );

    ActualizaExpendioLayout->addLayout( layout19, 2, 0 );
    languageChange();
    resize( QSize(1010, 636).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaExpendio::~ActualizaExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaExpendio::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Expendios" ) );
    QTExpendios->horizontalHeader()->setLabel( 0, tr( "Expendio" ) );
    QTExpendios->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    textLabel1_2->setText( tr( "Productos En La Matriz y no estan en expendio" ) );
    QTProdsNoExpendio->horizontalHeader()->setLabel( 0, tr( "Productos" ) );
    QTProdsNoExpendio->horizontalHeader()->setLabel( 1, tr( "Precio" ) );
    QPBProductos->setText( tr( "Productos" ) );
    pushButton6_2->setText( tr( "Precios" ) );
}

