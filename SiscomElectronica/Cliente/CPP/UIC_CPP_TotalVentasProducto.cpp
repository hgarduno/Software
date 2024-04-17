/****************************************************************************
** Form implementation generated from reading ui file 'UI/TotalVentasProducto.ui'
**
** Created: Fri Apr 12 21:26:01 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_TotalVentasProducto.h"

#include <qvariant.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a TotalVentasProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
TotalVentasProducto::TotalVentasProducto( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TotalVentasProducto" );
    TotalVentasProductoLayout = new QGridLayout( this, 1, 1, 0, 0, "TotalVentasProductoLayout"); 

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cliente" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    layout32->addWidget( QTDatos );

    layout30 = new QVBoxLayout( 0, 0, 6, "layout30"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout30->addWidget( textLabel1 );

    QLCDNCantidad = new QLCDNumber( this, "QLCDNCantidad" );
    layout30->addWidget( QLCDNCantidad );
    layout32->addLayout( layout30 );

    TotalVentasProductoLayout->addLayout( layout32, 0, 0 );
    languageChange();
    resize( QSize(600, 178).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
TotalVentasProducto::~TotalVentasProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TotalVentasProducto::languageChange()
{
    setCaption( tr( "Form1" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Cliente" ) );
    textLabel1->setText( tr( "Total" ) );
}

