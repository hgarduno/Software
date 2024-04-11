/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroClientes2.ui'
**
** Created: Thu Apr 11 20:30:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroClientes2.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a RegistroClientes2 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroClientes2::RegistroClientes2( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroClientes2" );
    RegistroClientes2Layout = new QGridLayout( this, 1, 1, 11, 6, "RegistroClientes2Layout"); 

    QTWPersonas = new QTabWidget( this, "QTWPersonas" );

    tab = new QWidget( QTWPersonas, "tab" );
    tabLayout = new QVBoxLayout( tab, 11, 6, "tabLayout"); 

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( tab, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QLENombre = new QLineEdit( tab, "QLENombre" );
    layout1->addWidget( QLENombre );
    layout6->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( tab, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( textLabel1_2 );

    QLEAPaterno = new QLineEdit( tab, "QLEAPaterno" );
    layout1_2->addWidget( QLEAPaterno );
    layout6->addLayout( layout1_2 );

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( tab, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2->addWidget( textLabel1_2_2 );

    QLEAMaterno = new QLineEdit( tab, "QLEAMaterno" );
    layout1_2_2->addWidget( QLEAMaterno );
    layout6->addLayout( layout1_2_2 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1_3 = new QLabel( tab, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel1_3 );

    QLERFC = new QLineEdit( tab, "QLERFC" );
    layout5->addWidget( QLERFC );
    layout6->addLayout( layout5 );
    tabLayout->addLayout( layout6 );
    spacer1 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout->addItem( spacer1 );
    QTWPersonas->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( QTWPersonas, "tab_2" );
    tabLayout_2 = new QVBoxLayout( tab_2, 11, 6, "tabLayout_2"); 

    layout1_3 = new QVBoxLayout( 0, 0, 6, "layout1_3"); 

    textLabel1_4 = new QLabel( tab_2, "textLabel1_4" );
    layout1_3->addWidget( textLabel1_4 );

    QLERazonSocial = new QLineEdit( tab_2, "QLERazonSocial" );
    layout1_3->addWidget( QLERazonSocial );
    tabLayout_2->addLayout( layout1_3 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel1_3_2 = new QLabel( tab_2, "textLabel1_3_2" );
    layout5_2->addWidget( textLabel1_3_2 );

    QLERFCPM = new QLineEdit( tab_2, "QLERFCPM" );
    layout5_2->addWidget( QLERFCPM );
    tabLayout_2->addLayout( layout5_2 );
    spacer2 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout_2->addItem( spacer2 );
    QTWPersonas->insertTab( tab_2, QString::fromLatin1("") );

    RegistroClientes2Layout->addWidget( QTWPersonas, 0, 0 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout16->addWidget( textLabel4 );

    QTDirecciones = new QTable( this, "QTDirecciones" );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Direccion" ) );
    QTDirecciones->setNumRows( 0 );
    QTDirecciones->setNumCols( 1 );
    QTDirecciones->setReadOnly( TRUE );
    layout16->addWidget( QTDirecciones );

    RegistroClientes2Layout->addLayout( layout16, 2, 0 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    QPBRegistraG = new QPushButton( this, "QPBRegistraG" );
    layout18->addWidget( QPBRegistraG );

    QPBADireccion = new QPushButton( this, "QPBADireccion" );
    layout18->addWidget( QPBADireccion );

    pushButton2_3 = new QPushButton( this, "pushButton2_3" );
    layout18->addWidget( pushButton2_3 );

    RegistroClientes2Layout->addLayout( layout18, 3, 0 );

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel1_5 = new QLabel( this, "textLabel1_5" );
    layout23->addWidget( textLabel1_5 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout14->addWidget( textLabel2 );

    QLEDLinea1 = new QLineEdit( this, "QLEDLinea1" );
    layout14->addWidget( QLEDLinea1 );
    layout23->addLayout( layout14 );

    layout14_2 = new QHBoxLayout( 0, 0, 6, "layout14_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout14_2->addWidget( textLabel2_2 );

    QLEDLinea2 = new QLineEdit( this, "QLEDLinea2" );
    layout14_2->addWidget( QLEDLinea2 );
    layout23->addLayout( layout14_2 );

    layout14_2_2 = new QHBoxLayout( 0, 0, 6, "layout14_2_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    layout14_2_2->addWidget( textLabel2_2_2 );

    QLEDLinea3 = new QLineEdit( this, "QLEDLinea3" );
    layout14_2_2->addWidget( QLEDLinea3 );
    layout23->addLayout( layout14_2_2 );

    layout14_2_3 = new QHBoxLayout( 0, 0, 6, "layout14_2_3"); 

    textLabel2_2_3 = new QLabel( this, "textLabel2_2_3" );
    layout14_2_3->addWidget( textLabel2_2_3 );

    QLEDLinea4 = new QLineEdit( this, "QLEDLinea4" );
    layout14_2_3->addWidget( QLEDLinea4 );
    layout23->addLayout( layout14_2_3 );

    RegistroClientes2Layout->addLayout( layout23, 1, 0 );
    languageChange();
    resize( QSize(600, 576).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroClientes2::~RegistroClientes2()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroClientes2::languageChange()
{
    setCaption( tr( "Registro De Clientes" ) );
    textLabel1->setText( tr( "Nombre" ) );
    textLabel1_2->setText( tr( "Apellido Paterno" ) );
    textLabel1_2_2->setText( tr( "Apellido Materno" ) );
    textLabel1_3->setText( tr( "RFC" ) );
    QTWPersonas->changeTab( tab, tr( "Persona Fisica" ) );
    textLabel1_4->setText( tr( "Razon Social" ) );
    textLabel1_3_2->setText( tr( "RFC" ) );
    QTWPersonas->changeTab( tab_2, tr( "Persona Moral" ) );
    textLabel4->setText( tr( "Direcciones Registradas" ) );
    QTDirecciones->horizontalHeader()->setLabel( 0, tr( "Direccion" ) );
    QPBRegistraG->setText( tr( "Registra Generales" ) );
    QPBADireccion->setText( tr( "Anexa Direccion" ) );
    pushButton2_3->setText( tr( "pushButton2" ) );
    textLabel1_5->setText( tr( "Direccion" ) );
    textLabel2->setText( tr( "Linea 1" ) );
    QLEDLinea1->setText( QString::null );
    textLabel2_2->setText( tr( "Linea 2" ) );
    QLEDLinea2->setText( QString::null );
    textLabel2_2_2->setText( tr( "Linea 3" ) );
    QLEDLinea3->setText( QString::null );
    textLabel2_2_3->setText( tr( "Linea 4" ) );
    QLEDLinea4->setText( QString::null );
}

