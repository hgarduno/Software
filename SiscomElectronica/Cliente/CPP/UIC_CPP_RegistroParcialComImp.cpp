/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroParcialComImp.ui'
**
** Created: Fri Apr 12 21:26:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroParcialComImp.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RegistroParcialComImp as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroParcialComImp::RegistroParcialComImp( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroParcialComImp" );
    RegistroParcialComImpLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroParcialComImpLayout"); 

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout33->addWidget( textLabel1 );

    lineEdit18 = new QLineEdit( this, "lineEdit18" );
    layout33->addWidget( lineEdit18 );

    RegistroParcialComImpLayout->addLayout( layout33, 0, 0 );

    layout34 = new QVBoxLayout( 0, 0, 6, "layout34"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout34->addWidget( textLabel2 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 3 );
    layout34->addWidget( QTProductos );

    RegistroParcialComImpLayout->addLayout( layout34, 1, 0 );

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    QPBRegistroProdsFaltantes = new QPushButton( this, "QPBRegistroProdsFaltantes" );
    layout35->addWidget( QPBRegistroProdsFaltantes );

    pushButton14 = new QPushButton( this, "pushButton14" );
    layout35->addWidget( pushButton14 );

    RegistroParcialComImpLayout->addLayout( layout35, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroParcialComImp::~RegistroParcialComImp()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroParcialComImp::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Proveedor" ) );
    textLabel2->setText( tr( "Productos" ) );
    QPBRegistroProdsFaltantes->setText( tr( "&Registra\n"
"Productos\n"
"Faltantes" ) );
    QPBRegistroProdsFaltantes->setAccel( QKeySequence( tr( "Alt+R" ) ) );
    pushButton14->setText( tr( "pushButton14" ) );
}

