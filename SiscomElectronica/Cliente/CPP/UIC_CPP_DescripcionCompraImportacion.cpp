/****************************************************************************
** Form implementation generated from reading ui file 'UI/DescripcionCompraImportacion.ui'
**
** Created: Wed Apr 10 20:52:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DescripcionCompraImportacion.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a DescripcionCompraImportacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DescripcionCompraImportacion::DescripcionCompraImportacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "DescripcionCompraImportacion" );

    QWidget* privateLayoutWidget = new QWidget( this, "layout1" );
    privateLayoutWidget->setGeometry( QRect( 10, 10, 580, 98 ) );
    layout1 = new QVBoxLayout( privateLayoutWidget, 11, 6, "layout1"); 

    textLabel1 = new QLabel( privateLayoutWidget, "textLabel1" );
    layout1->addWidget( textLabel1 );

    textEdit1 = new QTextEdit( privateLayoutWidget, "textEdit1" );
    layout1->addWidget( textEdit1 );

    QWidget* privateLayoutWidget_2 = new QWidget( this, "layout2" );
    privateLayoutWidget_2->setGeometry( QRect( 10, 110, 580, 22 ) );
    layout2 = new QHBoxLayout( privateLayoutWidget_2, 11, 6, "layout2"); 

    pushButton1 = new QPushButton( privateLayoutWidget_2, "pushButton1" );
    pushButton1->setAutoDefault( FALSE );
    layout2->addWidget( pushButton1 );

    pushButton1_2 = new QPushButton( privateLayoutWidget_2, "pushButton1_2" );
    pushButton1_2->setAutoDefault( FALSE );
    layout2->addWidget( pushButton1_2 );

    pushButton1_2_2 = new QPushButton( privateLayoutWidget_2, "pushButton1_2_2" );
    pushButton1_2_2->setAutoDefault( FALSE );
    layout2->addWidget( pushButton1_2_2 );
    languageChange();
    resize( QSize(600, 140).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DescripcionCompraImportacion::~DescripcionCompraImportacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DescripcionCompraImportacion::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "textLabel1" ) );
    pushButton1->setText( tr( "pushButton1" ) );
    pushButton1_2->setText( tr( "pushButton1" ) );
    pushButton1_2_2->setText( tr( "pushButton1" ) );
}

