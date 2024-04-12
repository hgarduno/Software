/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_Firmas.ui'
**
** Created: Thu Apr 11 21:36:23 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Firmas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Firmas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Firmas::Firmas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Firmas" );
    FirmasLayout = new QGridLayout( this, 1, 1, 11, 6, "FirmasLayout"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Usuarios" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 1 );

    FirmasLayout->addMultiCellWidget( QTDatos, 0, 0, 0, 3 );

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout18->addWidget( textLabel1 );

    QLEUsuario = new QLineEdit( this, "QLEUsuario" );
    layout18->addWidget( QLEUsuario );

    FirmasLayout->addMultiCellLayout( layout18, 1, 1, 0, 3 );

    layout18_2 = new QVBoxLayout( 0, 0, 6, "layout18_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout18_2->addWidget( textLabel1_2 );

    QLEFirma = new QLineEdit( this, "QLEFirma" );
    layout18_2->addWidget( QLEFirma );

    FirmasLayout->addLayout( layout18_2, 2, 0 );

    layout18_2_2 = new QVBoxLayout( 0, 0, 6, "layout18_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout18_2_2->addWidget( textLabel1_2_2 );

    QLEPassword = new QLineEdit( this, "QLEPassword" );
    QLEPassword->setEchoMode( QLineEdit::Password );
    layout18_2_2->addWidget( QLEPassword );

    FirmasLayout->addMultiCellLayout( layout18_2_2, 2, 2, 1, 2 );
    spacer6 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    FirmasLayout->addItem( spacer6, 2, 3 );

    QPBRegistraF = new QPushButton( this, "QPBRegistraF" );

    FirmasLayout->addMultiCellWidget( QPBRegistraF, 3, 3, 0, 1 );

    pushButton15_2 = new QPushButton( this, "pushButton15_2" );

    FirmasLayout->addMultiCellWidget( pushButton15_2, 3, 3, 2, 3 );
    languageChange();
    resize( QSize(382, 296).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Firmas::~Firmas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Firmas::languageChange()
{
    setCaption( tr( "Firmas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Usuarios" ) );
    textLabel1->setText( tr( "Usuario" ) );
    textLabel1_2->setText( tr( "Firma" ) );
    textLabel1_2_2->setText( tr( "Password" ) );
    QPBRegistraF->setText( tr( "Registra Firma" ) );
    pushButton15_2->setText( tr( "Modifica Password" ) );
}

