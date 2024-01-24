/****************************************************************************
** Form implementation generated from reading ui file 'UI/BalanceFinanciero.ui'
**
** Created: Thu Dec 21 12:53:43 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_BalanceFinanciero.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtextbrowser.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a BalanceFinanciero as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
BalanceFinanciero::BalanceFinanciero( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "BalanceFinanciero" );
    BalanceFinancieroLayout = new QGridLayout( this, 1, 1, 11, 6, "BalanceFinancieroLayout"); 

    QTBBalanceFinanciero = new QTextBrowser( this, "QTBBalanceFinanciero" );

    BalanceFinancieroLayout->addWidget( QTBBalanceFinanciero, 1, 0 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    QPBCargaArchivoHtml = new QPushButton( this, "QPBCargaArchivoHtml" );
    layout7->addWidget( QPBCargaArchivoHtml );

    pushButton5_2 = new QPushButton( this, "pushButton5_2" );
    layout7->addWidget( pushButton5_2 );

    BalanceFinancieroLayout->addLayout( layout7, 2, 0 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    cQControlFecha1 = new CQControlFecha( this, "cQControlFecha1" );
    layout1->addWidget( cQControlFecha1 );
    layout3->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    cQControlFecha1_2 = new CQControlFecha( this, "cQControlFecha1_2" );
    layout1_2->addWidget( cQControlFecha1_2 );
    layout3->addLayout( layout1_2 );
    layout8->addLayout( layout3 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout8->addItem( spacer1 );

    BalanceFinancieroLayout->addLayout( layout8, 0, 0 );
    languageChange();
    resize( QSize(607, 506).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
BalanceFinanciero::~BalanceFinanciero()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void BalanceFinanciero::languageChange()
{
    setCaption( tr( "Balance Financiero" ) );
    QPBCargaArchivoHtml->setText( tr( "Carga Archivo HTML" ) );
    pushButton5_2->setText( tr( "Ejecuta Consulta" ) );
    textLabel1->setText( tr( "Fecha Inicial" ) );
    textLabel1_2->setText( tr( "Fecha Final" ) );
}

