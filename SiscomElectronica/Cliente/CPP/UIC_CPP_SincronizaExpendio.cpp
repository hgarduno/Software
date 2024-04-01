/****************************************************************************
** Form implementation generated from reading ui file 'UI/SincronizaExpendio.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SincronizaExpendio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlExpendios.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlExpendios.h"

/*
 *  Constructs a SincronizaExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SincronizaExpendio::SincronizaExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SincronizaExpendio" );
    SincronizaExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "SincronizaExpendioLayout"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( textLabel1_2 );

    QCtrExpendiosO = new QCtrlExpendios( this, "QCtrExpendiosO" );
    QCtrExpendiosO->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)7, 0, 0, QCtrExpendiosO->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( QCtrExpendiosO );

    SincronizaExpendioLayout->addLayout( layout6, 0, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBSincronizaProd = new QPushButton( this, "QPBSincronizaProd" );
    QPBSincronizaProd->setMinimumSize( QSize( 0, 80 ) );
    layout4->addWidget( QPBSincronizaProd );

    QPBSincronizaPrec = new QPushButton( this, "QPBSincronizaPrec" );
    QPBSincronizaPrec->setMinimumSize( QSize( 0, 80 ) );
    layout4->addWidget( QPBSincronizaPrec );

    QPBSincronizaCli = new QPushButton( this, "QPBSincronizaCli" );
    QPBSincronizaCli->setMinimumSize( QSize( 0, 80 ) );
    layout4->addWidget( QPBSincronizaCli );

    QPBSincronizaTodo = new QPushButton( this, "QPBSincronizaTodo" );
    QPBSincronizaTodo->setMinimumSize( QSize( 0, 80 ) );
    layout4->addWidget( QPBSincronizaTodo );

    SincronizaExpendioLayout->addLayout( layout4, 2, 0 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout3->addWidget( textLabel1 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "1" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "2" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "3" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 3 );
    layout3->addWidget( table1 );

    SincronizaExpendioLayout->addLayout( layout3, 1, 0 );
    languageChange();
    resize( QSize(637, 699).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SincronizaExpendio::~SincronizaExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SincronizaExpendio::languageChange()
{
    setCaption( tr( "Sincroniza Expendio" ) );
    textLabel1_2->setText( tr( "Expendio A Sincronizar" ) );
    QPBSincronizaProd->setText( tr( "Sincroniza\n"
"Productos" ) );
    QPBSincronizaPrec->setText( tr( "Sincroniza\n"
"Precios" ) );
    QPBSincronizaCli->setText( tr( "Sincroniza\n"
"Clientes" ) );
    QPBSincronizaTodo->setText( tr( "Sincroniza\n"
"Todo" ) );
    textLabel1->setText( tr( "Estado Sincronizacion" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "1" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "2" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "3" ) );
}

