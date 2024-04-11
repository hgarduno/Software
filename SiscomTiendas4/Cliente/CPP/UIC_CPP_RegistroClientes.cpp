/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroClientes.ui'
**
** Created: Thu Apr 11 20:30:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroClientes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QSisDirecciones.h"
#include "QSisSepomex.h"
#include "QSisTelefonos.h"

/*
 *  Constructs a RegistroClientes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroClientes::RegistroClientes( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroClientes" );
    RegistroClientesLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroClientesLayout"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );

    RegistroClientesLayout->addWidget( QPBRegistrar, 2, 0 );

    QTWidget = new QTabWidget( this, "QTWidget" );
    QTWidget->setEnabled( TRUE );

    tab = new QWidget( QTWidget, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    QSDirecciones = new QSisDirecciones( tab, "QSDirecciones" );
    QSDirecciones->setEnabled( TRUE );

    tabLayout->addWidget( QSDirecciones, 0, 0 );
    QTWidget->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( QTWidget, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    QSTelefonos = new QSisTelefonos( tab_2, "QSTelefonos" );

    tabLayout_2->addWidget( QSTelefonos, 0, 0 );
    QTWidget->insertTab( tab_2, QString::fromLatin1("") );

    RegistroClientesLayout->addWidget( QTWidget, 1, 0 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout1->addWidget( QLENombre );
    layout6->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout1_2->addWidget( QLEAPaterno );
    layout6->addLayout( layout1_2 );

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout1_2_2->addWidget( textLabel1_2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout1_2_2->addWidget( QLEAMaterno );
    layout6->addLayout( layout1_2_2 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout5->addWidget( textLabel1_3 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    layout5->addWidget( QLERFC );
    layout6->addLayout( layout5 );

    RegistroClientesLayout->addLayout( layout6, 0, 0 );
    languageChange();
    resize( QSize(612, 646).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroClientes::~RegistroClientes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroClientes::languageChange()
{
    setCaption( tr( "Registro De Clientes" ) );
    QPBRegistrar->setText( tr( "Registrar Generales" ) );
    QTWidget->changeTab( tab, tr( "Direcciones" ) );
    QTWidget->changeTab( tab_2, tr( "Telefonos" ) );
    textLabel1->setText( tr( "Nombre" ) );
    textLabel1_2->setText( tr( "Apellido Paterno" ) );
    textLabel1_2_2->setText( tr( "Apellido Materno" ) );
    textLabel1_3->setText( tr( "RFC" ) );
}

