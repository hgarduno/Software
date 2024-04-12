/****************************************************************************
** Form implementation generated from reading ui file 'UI/Precios.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Precios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a Precios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Precios::Precios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Precios" );
    PreciosLayout = new QGridLayout( this, 1, 1, 11, 6, "PreciosLayout"); 

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel9 = new QLabel( this, "textLabel9" );
    layout18->addWidget( textLabel9 );

    QTEDsc = new QTextEdit( this, "QTEDsc" );
    layout18->addWidget( QTEDsc );

    PreciosLayout->addLayout( layout18, 1, 0 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel8 = new QLabel( this, "textLabel8" );
    textLabel8->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel8->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( textLabel8 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout17->addWidget( QLENombre );
    layout19->addLayout( layout17 );
    spacer3 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout19->addItem( spacer3 );

    PreciosLayout->addLayout( layout19, 0, 0 );

    textLabel10 = new QLabel( this, "textLabel10" );

    PreciosLayout->addWidget( textLabel10, 2, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Nombre" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 2 );
    QTDatos->setReadOnly( TRUE );

    PreciosLayout->addWidget( QTDatos, 3, 0 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    layout20->addWidget( QPBRegistra );

    pushButton4 = new QPushButton( this, "pushButton4" );
    layout20->addWidget( pushButton4 );

    pushButton5 = new QPushButton( this, "pushButton5" );
    layout20->addWidget( pushButton5 );

    PreciosLayout->addLayout( layout20, 4, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Precios::~Precios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Precios::languageChange()
{
    setCaption( tr( "Manejador De Precios" ) );
    textLabel9->setText( tr( "Descripcion" ) );
    textLabel8->setText( tr( "Nombre" ) );
    textLabel10->setText( tr( "Precios Registrados" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Nombre" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QPBRegistra->setText( tr( "Registrar Precio" ) );
    pushButton4->setText( tr( "pushButton4" ) );
    pushButton5->setText( tr( "pushButton5" ) );
}

