/****************************************************************************
** Form implementation generated from reading ui file 'UI/ModuloBodegas.ui'
**
** Created: Fri Apr 12 21:26:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ModuloBodegas.h"

#include <qvariant.h>
#include <qlabel.h>
#include <QCtrlBodegas4.h>
#include <qtabwidget.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlBodegas4.h"

/*
 *  Constructs a ModuloBodegas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ModuloBodegas::ModuloBodegas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ModuloBodegas" );
    ModuloBodegasLayout = new QGridLayout( this, 1, 1, 11, 6, "ModuloBodegasLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrBodegas = new QCtrlBodegas4( this, "QCtrBodegas" );
    layout1->addWidget( QCtrBodegas );

    ModuloBodegasLayout->addLayout( layout1, 0, 0 );

    QTWOperaciones = new QTabWidget( this, "QTWOperaciones" );
    QTWOperaciones->setEnabled( TRUE );

    tab = new QWidget( QTWOperaciones, "tab" );
    QTWOperaciones->insertTab( tab, QString::fromLatin1("") );

    ModuloBodegasLayout->addWidget( QTWOperaciones, 0, 1 );
    languageChange();
    resize( QSize(1054, 513).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ModuloBodegas::~ModuloBodegas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ModuloBodegas::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Bodegas Expendios" ) );
    QTWOperaciones->changeTab( tab, tr( "Tab 1" ) );
}

