/****************************************************************************
** Form implementation generated from reading ui file 'UI/TransferenciasExpendioExpendio.ui'
**
** Created: Wed Jan 31 10:48:09 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_TransferenciasExpendioExpendio.h"

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
 *  Constructs a TransferenciasExpendioExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
TransferenciasExpendioExpendio::TransferenciasExpendioExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TransferenciasExpendioExpendio" );
    TransferenciasExpendioExpendioLayout = new QGridLayout( this, 1, 1, 0, 0, "TransferenciasExpendioExpendioLayout"); 

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Expendio Origen" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Expendio Destino" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );
    layout32->addWidget( QTDatos );

    layout30 = new QVBoxLayout( 0, 0, 6, "layout30"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout30->addWidget( textLabel1 );

    QLCDNCantidad = new QLCDNumber( this, "QLCDNCantidad" );
    layout30->addWidget( QLCDNCantidad );
    layout32->addLayout( layout30 );

    TransferenciasExpendioExpendioLayout->addLayout( layout32, 0, 0 );
    languageChange();
    resize( QSize(693, 144).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
TransferenciasExpendioExpendio::~TransferenciasExpendioExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TransferenciasExpendioExpendio::languageChange()
{
    setCaption( tr( "Form4" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Expendio Origen" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Expendio Destino" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    textLabel1->setText( tr( "Total" ) );
}

