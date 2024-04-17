/****************************************************************************
** Form implementation generated from reading ui file 'UI/Familias.ui'
**
** Created: Fri Apr 12 21:36:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Familias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Familias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Familias::Familias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Familias" );
    FamiliasLayout = new QGridLayout( this, 1, 1, 11, 6, "FamiliasLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLEFamilia = new QLineEdit( this, "QLEFamilia" );
    layout1->addWidget( QLEFamilia );
    layout4->addLayout( layout1 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout4->addItem( spacer1 );

    FamiliasLayout->addLayout( layout4, 0, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QTEDsc = new QTextEdit( this, "QTEDsc" );
    layout2->addWidget( QTEDsc );

    FamiliasLayout->addLayout( layout2, 1, 0 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout5->addWidget( textLabel3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Familia" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 2 );
    QTDatos->setReadOnly( TRUE );
    QTDatos->setSorting( TRUE );
    layout5->addWidget( QTDatos );

    FamiliasLayout->addLayout( layout5, 2, 0 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout6->addWidget( QPBAnexar );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    pushButton1_2->setEnabled( FALSE );
    layout6->addWidget( pushButton1_2 );

    pushButton1_2_2 = new QPushButton( this, "pushButton1_2_2" );
    pushButton1_2_2->setEnabled( FALSE );
    layout6->addWidget( pushButton1_2_2 );

    FamiliasLayout->addLayout( layout6, 3, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Familias::~Familias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Familias::languageChange()
{
    setCaption( tr( "Registro De Familias" ) );
    textLabel1->setText( tr( "Familia" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    textLabel3->setText( tr( "Familias Registradas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Familia" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QPBAnexar->setText( tr( "Anexar Familia" ) );
    pushButton1_2->setText( tr( "Buscar Familia" ) );
    pushButton1_2_2->setText( tr( "Eliminar Familia" ) );
}

