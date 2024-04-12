/****************************************************************************
** Form implementation generated from reading ui file 'UI/Familias.ui'
**
** Created: Thu Apr 11 21:52:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Familias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a FamiliasQ as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
FamiliasQ::FamiliasQ( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "FamiliasQ" );
    FamiliasQLayout = new QGridLayout( this, 1, 1, 11, 6, "FamiliasQLayout"); 

    layout95 = new QVBoxLayout( 0, 0, 6, "layout95"); 

    textLabel15 = new QLabel( this, "textLabel15" );
    layout95->addWidget( textLabel15 );

    QLEFamilia = new QLineEdit( this, "QLEFamilia" );
    QLEFamilia->setMinimumSize( QSize( 150, 0 ) );
    QLEFamilia->setMaximumSize( QSize( 150, 32767 ) );
    layout95->addWidget( QLEFamilia );

    FamiliasQLayout->addLayout( layout95, 0, 0 );

    layout96 = new QVBoxLayout( 0, 0, 6, "layout96"); 

    textLabel16 = new QLabel( this, "textLabel16" );
    layout96->addWidget( textLabel16 );

    QLEDscFamilia = new QLineEdit( this, "QLEDscFamilia" );
    QLEDscFamilia->setMinimumSize( QSize( 400, 0 ) );
    layout96->addWidget( QLEDscFamilia );

    FamiliasQLayout->addMultiCellLayout( layout96, 0, 0, 1, 2 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Familia" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Estado Registro" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );

    FamiliasQLayout->addMultiCellWidget( QTDatos, 1, 1, 0, 2 );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setMinimumSize( QSize( 0, 70 ) );
    QPBAnexar->setMaximumSize( QSize( 32767, 70 ) );

    FamiliasQLayout->addWidget( QPBAnexar, 2, 0 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setMinimumSize( QSize( 0, 70 ) );
    QPBRegistrar->setMaximumSize( QSize( 32767, 70 ) );

    FamiliasQLayout->addWidget( QPBRegistrar, 2, 1 );

    QPBModificar = new QPushButton( this, "QPBModificar" );
    QPBModificar->setMinimumSize( QSize( 0, 70 ) );
    QPBModificar->setMaximumSize( QSize( 32767, 70 ) );

    FamiliasQLayout->addWidget( QPBModificar, 2, 2 );
    languageChange();
    resize( QSize(582, 470).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FamiliasQ::~FamiliasQ()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FamiliasQ::languageChange()
{
    setCaption( tr( "Manejador De Familias" ) );
    textLabel15->setText( tr( "Familia" ) );
    textLabel16->setText( tr( "Descripcion Familia" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Familia" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Estado Registro" ) );
    QPBAnexar->setText( tr( "Anexar \n"
"Familia" ) );
    QPBRegistrar->setText( tr( "Registrar\n"
"Familia" ) );
    QPBModificar->setText( tr( "Modificar \n"
"Familia" ) );
}

