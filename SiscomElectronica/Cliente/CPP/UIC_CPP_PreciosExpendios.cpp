/****************************************************************************
** Form implementation generated from reading ui file 'UI/PreciosExpendios.ui'
**
** Created: Thu Apr 11 21:39:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PreciosExpendios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a PreciosExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PreciosExpendios::PreciosExpendios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PreciosExpendios" );
    PreciosExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "PreciosExpendiosLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QTPreciosE = new QTable( this, "QTPreciosE" );
    QTPreciosE->setNumCols( QTPreciosE->numCols() + 1 );
    QTPreciosE->horizontalHeader()->setLabel( QTPreciosE->numCols() - 1, tr( "1" ) );
    QTPreciosE->setNumCols( QTPreciosE->numCols() + 1 );
    QTPreciosE->horizontalHeader()->setLabel( QTPreciosE->numCols() - 1, tr( "2" ) );
    QTPreciosE->setNumCols( QTPreciosE->numCols() + 1 );
    QTPreciosE->horizontalHeader()->setLabel( QTPreciosE->numCols() - 1, tr( "3" ) );
    QTPreciosE->setNumCols( QTPreciosE->numCols() + 1 );
    QTPreciosE->horizontalHeader()->setLabel( QTPreciosE->numCols() - 1, tr( "4" ) );
    QTPreciosE->setNumRows( 0 );
    QTPreciosE->setNumCols( 4 );
    layout1->addWidget( QTPreciosE );

    PreciosExpendiosLayout->addMultiCellLayout( layout1, 1, 1, 0, 3 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout3->addWidget( textLabel1_2 );

    QLEExpendioO = new QLineEdit( this, "QLEExpendioO" );
    QLEExpendioO->setReadOnly( TRUE );
    layout3->addWidget( QLEExpendioO );

    PreciosExpendiosLayout->addMultiCellLayout( layout3, 0, 0, 0, 1 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout3_2->addWidget( textLabel1_2_2 );

    QLEExpendioD = new QLineEdit( this, "QLEExpendioD" );
    QLEExpendioD->setReadOnly( TRUE );
    layout3_2->addWidget( QLEExpendioD );

    PreciosExpendiosLayout->addMultiCellLayout( layout3_2, 0, 0, 2, 3 );

    QPBExpendioO = new QPushButton( this, "QPBExpendioO" );

    PreciosExpendiosLayout->addWidget( QPBExpendioO, 2, 0 );

    QPBExpendioD = new QPushButton( this, "QPBExpendioD" );

    PreciosExpendiosLayout->addMultiCellWidget( QPBExpendioD, 2, 2, 1, 2 );

    QPBConsultaPrecios = new QPushButton( this, "QPBConsultaPrecios" );

    PreciosExpendiosLayout->addWidget( QPBConsultaPrecios, 2, 3 );
    languageChange();
    resize( QSize(807, 494).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PreciosExpendios::~PreciosExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PreciosExpendios::languageChange()
{
    setCaption( tr( "Precios Expendios" ) );
    textLabel1->setText( tr( "Precios Expendios" ) );
    QTPreciosE->horizontalHeader()->setLabel( 0, tr( "1" ) );
    QTPreciosE->horizontalHeader()->setLabel( 1, tr( "2" ) );
    QTPreciosE->horizontalHeader()->setLabel( 2, tr( "3" ) );
    QTPreciosE->horizontalHeader()->setLabel( 3, tr( "4" ) );
    textLabel1_2->setText( tr( "Expendio Orgen" ) );
    textLabel1_2_2->setText( tr( "Expendio Destino" ) );
    QPBExpendioO->setText( tr( "Expendio Origen" ) );
    QPBExpendioD->setText( tr( "Expendio Destino" ) );
    QPBConsultaPrecios->setText( tr( "Consulta Precios" ) );
}

