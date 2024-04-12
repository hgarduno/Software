/****************************************************************************
** Form implementation generated from reading ui file 'UI/BuscaPersonas.ui'
**
** Created: Thu Apr 11 21:37:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_BuscaPersonas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a BuscaPersonas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
BuscaPersonas::BuscaPersonas( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "BuscaPersonas" );
    BuscaPersonasLayout = new QGridLayout( this, 1, 1, 11, 6, "BuscaPersonasLayout"); 

    layout34 = new QVBoxLayout( 0, 0, 6, "layout34"); 

    layout19_2 = new QHBoxLayout( 0, 0, 6, "layout19_2"); 

    layout5_3 = new QVBoxLayout( 0, 0, 6, "layout5_3"); 

    textLabel3_4 = new QLabel( this, "textLabel3_4" );
    textLabel3_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_4->sizePolicy().hasHeightForWidth() ) );
    layout5_3->addWidget( textLabel3_4 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout5_3->addWidget( QLENombre );
    layout19_2->addLayout( layout5_3 );

    layout5_2_3 = new QVBoxLayout( 0, 0, 6, "layout5_2_3"); 

    textLabel3_2_3 = new QLabel( this, "textLabel3_2_3" );
    textLabel3_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_3->sizePolicy().hasHeightForWidth() ) );
    layout5_2_3->addWidget( textLabel3_2_3 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout5_2_3->addWidget( QLEAPaterno );
    layout19_2->addLayout( layout5_2_3 );

    layout5_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout5_2_2_2"); 

    textLabel3_2_2_2 = new QLabel( this, "textLabel3_2_2_2" );
    textLabel3_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2_2_2->addWidget( textLabel3_2_2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout5_2_2_2->addWidget( QLEAMaterno );
    layout19_2->addLayout( layout5_2_2_2 );
    layout34->addLayout( layout19_2 );

    layout75 = new QHBoxLayout( 0, 0, 6, "layout75"); 

    layout74 = new QVBoxLayout( 0, 0, 6, "layout74"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout74->addWidget( textLabel6 );

    QLEIdPersona = new QLineEdit( this, "QLEIdPersona" );
    QLEIdPersona->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEIdPersona->sizePolicy().hasHeightForWidth() ) );
    QLEIdPersona->setReadOnly( FALSE );
    layout74->addWidget( QLEIdPersona );
    layout75->addLayout( layout74 );
    spacer10 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout75->addItem( spacer10 );
    layout34->addLayout( layout75 );

    BuscaPersonasLayout->addLayout( layout34, 0, 0 );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    QPBConsulta->setAutoDefault( FALSE );
    layout36->addWidget( QPBConsulta );

    QPBSPersona = new QPushButton( this, "QPBSPersona" );
    QPBSPersona->setAutoDefault( FALSE );
    layout36->addWidget( QPBSPersona );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout36->addWidget( QPBCancelar );

    BuscaPersonasLayout->addLayout( layout36, 2, 0 );

    tabWidget5 = new QTabWidget( this, "tabWidget5" );

    tab = new QWidget( tabWidget5, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout35 = new QVBoxLayout( 0, 0, 6, "layout35"); 

    textLabel1 = new QLabel( tab, "textLabel1" );
    layout35->addWidget( textLabel1 );

    QTDatos = new QTable( tab, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Paciente" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "# Paciente" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 2 );
    QTDatos->setReadOnly( TRUE );
    layout35->addWidget( QTDatos );

    tabLayout->addLayout( layout35, 0, 0 );
    tabWidget5->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget5, "tab_2" );
    tabWidget5->insertTab( tab_2, QString::fromLatin1("") );

    TabPage = new QWidget( tabWidget5, "TabPage" );
    tabWidget5->insertTab( TabPage, QString::fromLatin1("") );

    BuscaPersonasLayout->addWidget( tabWidget5, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
BuscaPersonas::~BuscaPersonas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void BuscaPersonas::languageChange()
{
    setCaption( tr( "Busqueda De Personas" ) );
    textLabel3_4->setText( tr( "Nombre" ) );
    textLabel3_2_3->setText( tr( "Apellido Paterno" ) );
    textLabel3_2_2_2->setText( tr( "Apellido Materno" ) );
    textLabel6->setText( tr( "Identificador Persona" ) );
    QPBConsulta->setText( tr( "Ejecutar Consulta" ) );
    QPBSPersona->setText( tr( "Selecciona Persona" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Pacientes" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Paciente" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "# Paciente" ) );
    tabWidget5->changeTab( tab, tr( "Datos Generales" ) );
    tabWidget5->changeTab( tab_2, tr( "Direcciones" ) );
    tabWidget5->changeTab( TabPage, tr( "Telefonos" ) );
}

