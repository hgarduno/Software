/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RegistroInventario.ui'
**
** Created: Sat Jan 27 16:38:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RegistroInventario.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlVendedores.h"

/*
 *  Constructs a RegistroInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroInventario::RegistroInventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroInventario" );
    RegistroInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroInventarioLayout"); 

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    pushButton4 = new QPushButton( this, "pushButton4" );
    layout7->addWidget( pushButton4 );

    RegistroInventarioLayout->addLayout( layout7, 2, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout6->addWidget( textLabel4 );

    textEdit1 = new QTextEdit( this, "textEdit1" );
    layout6->addWidget( textEdit1 );

    RegistroInventarioLayout->addLayout( layout6, 1, 0 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel1 );

    ctrlTiendasEntrega2 = new QCtrlTiendasEntrega( this, "ctrlTiendasEntrega2" );
    layout3->addWidget( ctrlTiendasEntrega2 );
    layout9->addLayout( layout3 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( textLabel2 );

    ctrlVendedores1 = new QCtrlVendedores( this, "ctrlVendedores1" );
    layout4->addWidget( ctrlVendedores1 );
    layout9->addLayout( layout4 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel5 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    lineEdit1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( lineEdit1 );
    layout9->addLayout( layout8 );

    RegistroInventarioLayout->addLayout( layout9, 0, 0 );
    languageChange();
    resize( QSize(674, 287).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroInventario::~RegistroInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroInventario::languageChange()
{
    setCaption( tr( "Registro de Inventarios" ) );
    pushButton4->setText( tr( "Registrar Inventario" ) );
    textLabel4->setText( tr( "Observaciones" ) );
    textLabel1->setText( tr( "Tiendas" ) );
    textLabel2->setText( tr( "Responsables" ) );
    textLabel5->setText( tr( "Fecha Programada" ) );
}

