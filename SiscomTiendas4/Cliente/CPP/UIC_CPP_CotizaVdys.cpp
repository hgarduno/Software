/****************************************************************************
** Form implementation generated from reading ui file 'UI/CotizaVdys.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CotizaVdys.h"

#include <qvariant.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a CotizaVdys as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CotizaVdys::CotizaVdys( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CotizaVdys" );
    CotizaVdysLayout = new QGridLayout( this, 1, 1, 11, 6, "CotizaVdysLayout"); 

    table3 = new QTable( this, "table3" );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "1" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "2" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "3" ) );
    table3->setNumRows( 0 );
    table3->setNumCols( 3 );

    CotizaVdysLayout->addWidget( table3, 1, 0 );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout22->addWidget( textLabel1 );

    QLECliente = new QLineEdit( this, "QLECliente" );
    layout22->addWidget( QLECliente );
    layout23->addLayout( layout22 );

    QPBSCliente = new QPushButton( this, "QPBSCliente" );
    QPBSCliente->setMinimumSize( QSize( 0, 40 ) );
    layout23->addWidget( QPBSCliente );

    CotizaVdysLayout->addLayout( layout23, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CotizaVdys::~CotizaVdys()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CotizaVdys::languageChange()
{
    setCaption( tr( "Form1" ) );
    table3->horizontalHeader()->setLabel( 0, tr( "1" ) );
    table3->horizontalHeader()->setLabel( 1, tr( "2" ) );
    table3->horizontalHeader()->setLabel( 2, tr( "3" ) );
    textLabel1->setText( tr( "Cliente" ) );
    QPBSCliente->setText( tr( "Cliente" ) );
}

