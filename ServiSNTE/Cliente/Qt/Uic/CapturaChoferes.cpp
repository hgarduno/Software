/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaChoferes.ui'
**
** Created: Thu Apr 11 21:07:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaChoferes.h"

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
 *  Constructs a CapturaChoferes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CapturaChoferes::CapturaChoferes( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CapturaChoferes" );
    CapturaChoferesLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaChoferesLayout"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    layout81 = new QHBoxLayout( 0, 0, 6, "layout81"); 

    layout79 = new QVBoxLayout( 0, 0, 6, "layout79"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout79->addWidget( textLabel1_2 );

    lineEdit32 = new QLineEdit( this, "lineEdit32" );
    layout79->addWidget( lineEdit32 );
    layout81->addLayout( layout79 );

    layout80 = new QVBoxLayout( 0, 0, 6, "layout80"); 

    pushButton60 = new QLabel( this, "pushButton60" );
    layout80->addWidget( pushButton60 );

    lineEdit33 = new QLineEdit( this, "lineEdit33" );
    layout80->addWidget( lineEdit33 );
    layout81->addLayout( layout80 );
    spacer7 = new QSpacerItem( 191, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout81->addItem( spacer7 );
    layout17->addLayout( layout81 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    layout74 = new QHBoxLayout( 0, 0, 6, "layout74"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout74->addWidget( textLabel2 );

    lineEdit34 = new QLineEdit( this, "lineEdit34" );
    layout74->addWidget( lineEdit34 );
    layout14->addLayout( layout74 );

    layout75 = new QHBoxLayout( 0, 0, 6, "layout75"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout75->addWidget( textLabel3 );

    lineEdit35 = new QLineEdit( this, "lineEdit35" );
    layout75->addWidget( lineEdit35 );
    layout14->addLayout( layout75 );
    layout15->addLayout( layout14 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    pushButton28 = new QPushButton( this, "pushButton28" );
    layout13->addWidget( pushButton28 );

    pushButton29 = new QPushButton( this, "pushButton29" );
    layout13->addWidget( pushButton29 );
    layout15->addLayout( layout13 );
    layout17->addLayout( layout15 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout12->addWidget( textLabel4 );

    QTTelefono = new QTable( this, "QTTelefono" );
    QTTelefono->setNumCols( QTTelefono->numCols() + 1 );
    QTTelefono->horizontalHeader()->setLabel( QTTelefono->numCols() - 1, trUtf8( "\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f" ) );
    QTTelefono->setNumCols( QTTelefono->numCols() + 1 );
    QTTelefono->horizontalHeader()->setLabel( QTTelefono->numCols() - 1, trUtf8( "\x44\x65\x73\x63\x72\x69\x70\x63\x69\xc3\xb3\x6e" ) );
    QTTelefono->setNumRows( 0 );
    QTTelefono->setNumCols( 2 );
    layout12->addWidget( QTTelefono );
    layout16->addLayout( layout12 );

    pushButton30 = new QPushButton( this, "pushButton30" );
    layout16->addWidget( pushButton30 );
    layout17->addLayout( layout16 );

    layout72 = new QHBoxLayout( 0, 0, 6, "layout72"); 

    pushButton26 = new QPushButton( this, "pushButton26" );
    layout72->addWidget( pushButton26 );

    pushButton27 = new QPushButton( this, "pushButton27" );
    layout72->addWidget( pushButton27 );

    pushButton11 = new QPushButton( this, "pushButton11" );
    layout72->addWidget( pushButton11 );

    pushButton61 = new QPushButton( this, "pushButton61" );
    layout72->addWidget( pushButton61 );
    layout17->addLayout( layout72 );

    CapturaChoferesLayout->addLayout( layout17, 0, 0 );
    languageChange();
    resize( QSize(482, 251).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaChoferes::~CapturaChoferes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaChoferes::languageChange()
{
    setCaption( tr( "Captura Choferes" ) );
    textLabel1_2->setText( tr( "Clave:" ) );
    pushButton60->setText( tr( "Abreviatura:" ) );
    textLabel2->setText( tr( "Nombre:" ) );
    textLabel3->setText( trUtf8( "\x44\x69\x72\x65\x63\x63\x69\xc3\xb3\x6e\x3a" ) );
    pushButton28->setText( tr( "Captura Nombre" ) );
    pushButton29->setText( trUtf8( "\x43\x61\x70\x74\x75\x72\x61\x20\x44\x69\x72\x65\x63\x63\x69\xc3\xb3\x6e" ) );
    textLabel4->setText( trUtf8( "\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f\x73\x3a" ) );
    QTTelefono->horizontalHeader()->setLabel( 0, trUtf8( "\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f" ) );
    QTTelefono->horizontalHeader()->setLabel( 1, trUtf8( "\x44\x65\x73\x63\x72\x69\x70\x63\x69\xc3\xb3\x6e" ) );
    pushButton30->setText( trUtf8( "\x43\x61\x70\x74\x75\x72\x61\x20\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f" ) );
    pushButton26->setText( tr( "Crear" ) );
    pushButton27->setText( tr( "Consultar" ) );
    pushButton11->setText( tr( "Actualizar" ) );
    pushButton61->setText( tr( "Cancelar" ) );
}

