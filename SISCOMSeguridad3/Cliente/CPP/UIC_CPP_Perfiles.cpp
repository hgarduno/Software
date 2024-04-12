/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_Perfiles.ui'
**
** Created: Thu Apr 11 21:36:14 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Perfiles.h"

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
 *  Constructs a Perfiles as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Perfiles::Perfiles( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Perfiles" );
    PerfilesLayout = new QGridLayout( this, 1, 1, 11, 6, "PerfilesLayout"); 

    textLabel1 = new QLabel( this, "textLabel1" );

    PerfilesLayout->addMultiCellWidget( textLabel1, 2, 2, 0, 1 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout1_2->addWidget( textLabel2_2 );

    QLEDscPerfil = new QLineEdit( this, "QLEDscPerfil" );
    layout1_2->addWidget( QLEDscPerfil );
    layout3->addLayout( layout1_2 );
    spacer1_2 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout3->addItem( spacer1_2 );

    PerfilesLayout->addMultiCellLayout( layout3, 1, 1, 0, 1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Id Perfil" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Perfil" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );

    PerfilesLayout->addMultiCellWidget( QTDatos, 3, 3, 0, 1 );

    QPBRPerfil = new QPushButton( this, "QPBRPerfil" );
    QPBRPerfil->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, QPBRPerfil->sizePolicy().hasHeightForWidth() ) );

    PerfilesLayout->addWidget( QPBRPerfil, 4, 0 );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    pushButton1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, pushButton1_2->sizePolicy().hasHeightForWidth() ) );

    PerfilesLayout->addWidget( pushButton1_2, 4, 1 );
    spacer1 = new QSpacerItem( 226, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    PerfilesLayout->addItem( spacer1, 0, 1 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout1->addWidget( textLabel2 );

    QLENmbPerfil = new QLineEdit( this, "QLENmbPerfil" );
    layout1->addWidget( QLENmbPerfil );

    PerfilesLayout->addLayout( layout1, 0, 0 );
    languageChange();
    resize( QSize(482, 434).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Perfiles::~Perfiles()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Perfiles::languageChange()
{
    setCaption( tr( "Perfiles De La Aplicacion" ) );
    textLabel1->setText( tr( "Resumen" ) );
    textLabel2_2->setText( tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Id Perfil" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Perfil" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Descripcion" ) );
    QPBRPerfil->setText( tr( "Registra\n"
"Perfil" ) );
    pushButton1_2->setText( tr( "Eliminar\n"
"Perfiles" ) );
    textLabel2->setText( tr( "Perfil" ) );
}

