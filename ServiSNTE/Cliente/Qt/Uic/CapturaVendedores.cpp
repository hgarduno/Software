/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaVendedores.ui'
**
** Created: Thu Apr 11 21:07:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaVendedores.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"

/*
 *  Constructs a CapturaVendedores as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CapturaVendedores::CapturaVendedores( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CapturaVendedores" );
    CapturaVendedoresLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaVendedoresLayout"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    layout80 = new QVBoxLayout( 0, 0, 6, "layout80"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout80->addWidget( textLabel2 );

    lineEdit26 = new QLineEdit( this, "lineEdit26" );
    lineEdit26->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit26->sizePolicy().hasHeightForWidth() ) );
    layout80->addWidget( lineEdit26 );
    layout20->addLayout( layout80 );

    layout92 = new QVBoxLayout( 0, 0, 6, "layout92"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout92->addWidget( textLabel6 );

    lineEdit31 = new QLineEdit( this, "lineEdit31" );
    lineEdit31->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit31->sizePolicy().hasHeightForWidth() ) );
    layout92->addWidget( lineEdit31 );
    layout20->addLayout( layout92 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout19->addWidget( textLabel5 );

    QCtrTienda = new QCtrlTiendasEntrega( this, "QCtrTienda" );
    layout19->addWidget( QCtrTienda );
    layout20->addLayout( layout19 );
    layout21->addLayout( layout20 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    layout138 = new QHBoxLayout( 0, 0, 6, "layout138"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout138->addWidget( textLabel2_2 );

    lineEdit51 = new QLineEdit( this, "lineEdit51" );
    layout138->addWidget( lineEdit51 );
    layout15->addLayout( layout138 );

    layout139 = new QHBoxLayout( 0, 0, 6, "layout139"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout139->addWidget( textLabel3 );

    lineEdit52 = new QLineEdit( this, "lineEdit52" );
    layout139->addWidget( lineEdit52 );
    layout15->addLayout( layout139 );
    layout16->addLayout( layout15 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    pushButton47 = new QPushButton( this, "pushButton47" );
    layout14->addWidget( pushButton47 );

    pushButton48 = new QPushButton( this, "pushButton48" );
    layout14->addWidget( pushButton48 );
    layout16->addLayout( layout14 );
    layout21->addLayout( layout16 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout13->addWidget( textLabel4 );

    QTTelefono = new QTable( this, "QTTelefono" );
    QTTelefono->setNumCols( QTTelefono->numCols() + 1 );
    QTTelefono->horizontalHeader()->setLabel( QTTelefono->numCols() - 1, trUtf8( "\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f" ) );
    QTTelefono->setNumCols( QTTelefono->numCols() + 1 );
    QTTelefono->horizontalHeader()->setLabel( QTTelefono->numCols() - 1, trUtf8( "\x44\x65\x73\x63\x72\x69\x70\x63\x69\xc3\xb3\x6e" ) );
    QTTelefono->setNumRows( 0 );
    QTTelefono->setNumCols( 2 );
    layout13->addWidget( QTTelefono );
    layout18->addLayout( layout13 );

    pushButton49 = new QPushButton( this, "pushButton49" );
    layout18->addWidget( pushButton49 );
    spacer1 = new QSpacerItem( 121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout18->addItem( spacer1 );
    layout21->addLayout( layout18 );

    layout125 = new QHBoxLayout( 0, 0, 6, "layout125"); 

    pushButton11 = new QPushButton( this, "pushButton11" );
    layout125->addWidget( pushButton11 );

    pushButton39 = new QPushButton( this, "pushButton39" );
    layout125->addWidget( pushButton39 );

    pushButton40 = new QPushButton( this, "pushButton40" );
    layout125->addWidget( pushButton40 );

    pushButton12 = new QPushButton( this, "pushButton12" );
    layout125->addWidget( pushButton12 );
    layout21->addLayout( layout125 );

    CapturaVendedoresLayout->addLayout( layout21, 0, 0 );
    languageChange();
    resize( QSize(547, 250).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaVendedores::~CapturaVendedores()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaVendedores::languageChange()
{
    setCaption( tr( "Captura Vendedores" ) );
    textLabel2->setText( tr( "Clave Vendedor:" ) );
    textLabel6->setText( tr( "Abreviatura:" ) );
    textLabel5->setText( tr( "Tienda" ) );
    textLabel2_2->setText( tr( "Nombre:" ) );
    textLabel3->setText( trUtf8( "\x44\x69\x72\x65\x63\x63\x69\xc3\xb3\x6e\x3a" ) );
    pushButton47->setText( tr( "Captura Nombre" ) );
    pushButton48->setText( trUtf8( "\x43\x61\x70\x74\x75\x72\x61\x20\x44\x69\x72\x65\x63\x63\x69\xc3\xb3\x6e" ) );
    textLabel4->setText( trUtf8( "\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f\x3a" ) );
    QTTelefono->horizontalHeader()->setLabel( 0, trUtf8( "\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f" ) );
    QTTelefono->horizontalHeader()->setLabel( 1, trUtf8( "\x44\x65\x73\x63\x72\x69\x70\x63\x69\xc3\xb3\x6e" ) );
    pushButton49->setText( trUtf8( "\x43\x61\x70\x74\x75\x72\x61\x20\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f\x73" ) );
    pushButton11->setText( tr( "Crear" ) );
    pushButton39->setText( tr( "Consultar" ) );
    pushButton40->setText( tr( "Actualizar" ) );
    pushButton12->setText( tr( "Cancelar" ) );
}

