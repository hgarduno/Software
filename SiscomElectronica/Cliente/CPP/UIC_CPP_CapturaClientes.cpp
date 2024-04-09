/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaClientes.ui'
**
** Created: lun abr 1 18:57:49 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaClientes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaClientes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaClientes::CapturaClientes( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaClientes" );
    CapturaClientesLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaClientesLayout"); 

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( textLabel2 );

    QCBRFC = new QComboBox( FALSE, this, "QCBRFC" );
    QCBRFC->setEditable( TRUE );
    QCBRFC->setInsertionPolicy( QComboBox::NoInsertion );
    QCBRFC->setAutoCompletion( TRUE );
    QCBRFC->setDuplicatesEnabled( FALSE );
    layout48->addWidget( QCBRFC );

    CapturaClientesLayout->addMultiCellLayout( layout48, 0, 0, 0, 1 );

    layout98 = new QHBoxLayout( 0, 0, 6, "layout98"); 

    QTWTipoCliente = new QTabWidget( this, "QTWTipoCliente" );
    QTWTipoCliente->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTWTipoCliente->sizePolicy().hasHeightForWidth() ) );

    tab = new QWidget( QTWTipoCliente, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout95 = new QVBoxLayout( 0, 0, 6, "layout95"); 

    textLabel6 = new QLabel( tab, "textLabel6" );
    layout95->addWidget( textLabel6 );

    QLENombre = new QLineEdit( tab, "QLENombre" );
    layout95->addWidget( QLENombre );

    tabLayout->addLayout( layout95, 0, 0 );

    layout95_2 = new QVBoxLayout( 0, 0, 6, "layout95_2"); 

    textLabel6_2 = new QLabel( tab, "textLabel6_2" );
    layout95_2->addWidget( textLabel6_2 );

    QLEAPaterno = new QLineEdit( tab, "QLEAPaterno" );
    layout95_2->addWidget( QLEAPaterno );

    tabLayout->addLayout( layout95_2, 0, 1 );

    layout95_2_2 = new QVBoxLayout( 0, 0, 6, "layout95_2_2"); 

    textLabel6_2_2 = new QLabel( tab, "textLabel6_2_2" );
    layout95_2_2->addWidget( textLabel6_2_2 );

    QLEAMaterno = new QLineEdit( tab, "QLEAMaterno" );
    layout95_2_2->addWidget( QLEAMaterno );

    tabLayout->addLayout( layout95_2_2, 0, 2 );
    QTWTipoCliente->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( QTWTipoCliente, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout94 = new QVBoxLayout( 0, 0, 6, "layout94"); 

    textLabel5 = new QLabel( tab_2, "textLabel5" );
    layout94->addWidget( textLabel5 );

    QLERazonSocial = new QLineEdit( tab_2, "QLERazonSocial" );
    layout94->addWidget( QLERazonSocial );

    tabLayout_2->addLayout( layout94, 0, 0 );
    QTWTipoCliente->insertTab( tab_2, QString::fromLatin1("") );
    layout98->addWidget( QTWTipoCliente );

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    layout6_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout6_2_2_3"); 

    textLabel1_2_2_2_3 = new QLabel( this, "textLabel1_2_2_2_3" );
    textLabel1_2_2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2_3->sizePolicy().hasHeightForWidth() ) );
    layout6_2_2_3->addWidget( textLabel1_2_2_2_3 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    QLERFC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLERFC->sizePolicy().hasHeightForWidth() ) );
    QLERFC->setReadOnly( FALSE );
    layout6_2_2_3->addWidget( QLERFC );
    layout44->addLayout( layout6_2_2_3 );
    spacer1 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed );
    layout44->addItem( spacer1 );
    layout98->addLayout( layout44 );

    CapturaClientesLayout->addMultiCellLayout( layout98, 1, 1, 0, 1 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout18->addWidget( QPBAceptar );

    QPBNCliente = new QPushButton( this, "QPBNCliente" );
    QPBNCliente->setAutoDefault( FALSE );
    layout18->addWidget( QPBNCliente );

    QPBRCliente = new QPushButton( this, "QPBRCliente" );
    QPBRCliente->setAutoDefault( FALSE );
    layout18->addWidget( QPBRCliente );

    pushButton7_2_2 = new QPushButton( this, "pushButton7_2_2" );
    pushButton7_2_2->setAutoDefault( FALSE );
    layout18->addWidget( pushButton7_2_2 );

    CapturaClientesLayout->addMultiCellLayout( layout18, 5, 5, 0, 1 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout6_3_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2_2"); 

    textLabel1_2_3_2_2_2 = new QLabel( this, "textLabel1_2_3_2_2_2" );
    layout6_3_2_2_2->addWidget( textLabel1_2_3_2_2_2 );

    QLEDelMun = new QLineEdit( this, "QLEDelMun" );
    QLEDelMun->setReadOnly( FALSE );
    layout6_3_2_2_2->addWidget( QLEDelMun );
    layout22->addLayout( layout6_3_2_2_2 );

    layout6_3_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2_2_2"); 

    textLabel1_2_3_2_2_2_2 = new QLabel( this, "textLabel1_2_3_2_2_2_2" );
    layout6_3_2_2_2_2->addWidget( textLabel1_2_3_2_2_2_2 );

    QLEEstado = new QLineEdit( this, "QLEEstado" );
    QLEEstado->setReadOnly( FALSE );
    layout6_3_2_2_2_2->addWidget( QLEEstado );
    layout22->addLayout( layout6_3_2_2_2_2 );

    CapturaClientesLayout->addMultiCellLayout( layout22, 4, 4, 0, 1 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    layout6_3_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2"); 

    textLabel1_2_3_2 = new QLabel( this, "textLabel1_2_3_2" );
    layout6_3_2->addWidget( textLabel1_2_3_2 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    QLECalle->setReadOnly( FALSE );
    layout6_3_2->addWidget( QLECalle );
    layout21->addLayout( layout6_3_2 );

    layout6_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2"); 

    textLabel1_2_3_2_2 = new QLabel( this, "textLabel1_2_3_2_2" );
    layout6_3_2_2->addWidget( textLabel1_2_3_2_2 );

    QLENumero = new QLineEdit( this, "QLENumero" );
    QLENumero->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumero->sizePolicy().hasHeightForWidth() ) );
    QLENumero->setReadOnly( FALSE );
    layout6_3_2_2->addWidget( QLENumero );
    layout21->addLayout( layout6_3_2_2 );

    layout6_3_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2_3"); 

    textLabel1_2_3_2_2_3 = new QLabel( this, "textLabel1_2_3_2_2_3" );
    layout6_3_2_2_3->addWidget( textLabel1_2_3_2_2_3 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    QLEColonia->setReadOnly( FALSE );
    layout6_3_2_2_3->addWidget( QLEColonia );
    layout21->addLayout( layout6_3_2_2_3 );

    layout6_3_2_2_3_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2_3_2"); 

    textLabel1_2_3_2_2_3_2 = new QLabel( this, "textLabel1_2_3_2_2_3_2" );
    layout6_3_2_2_3_2->addWidget( textLabel1_2_3_2_2_3_2 );

    QLECP = new QLineEdit( this, "QLECP" );
    QLECP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECP->sizePolicy().hasHeightForWidth() ) );
    QLECP->setReadOnly( FALSE );
    layout6_3_2_2_3_2->addWidget( QLECP );
    layout21->addLayout( layout6_3_2_2_3_2 );

    CapturaClientesLayout->addMultiCellLayout( layout21, 3, 3, 0, 1 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout19->addWidget( textLabel1 );

    QLETelefono = new QLineEdit( this, "QLETelefono" );
    QLETelefono->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLETelefono->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( QLETelefono );

    CapturaClientesLayout->addLayout( layout19, 2, 0 );

    layout19_2 = new QVBoxLayout( 0, 0, 6, "layout19_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout19_2->addWidget( textLabel1_2 );

    QLECorreoE = new QLineEdit( this, "QLECorreoE" );
    QLECorreoE->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECorreoE->sizePolicy().hasHeightForWidth() ) );
    layout19_2->addWidget( QLECorreoE );

    CapturaClientesLayout->addLayout( layout19_2, 2, 1 );
    languageChange();
    resize( QSize(638, 333).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaClientes::~CapturaClientes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaClientes::languageChange()
{
    setCaption( tr( "Captura De Clientes" ) );
    textLabel2->setText( tr( "RFC" ) );
    textLabel6->setText( tr( "Nombre" ) );
    textLabel6_2->setText( tr( "Apellido Paterno" ) );
    textLabel6_2_2->setText( tr( "Apellido Materno" ) );
    QTWTipoCliente->changeTab( tab, tr( "Persona Fisica" ) );
    textLabel5->setText( tr( "Razon Social" ) );
    QTWTipoCliente->changeTab( tab_2, tr( "Persona Moral" ) );
    textLabel1_2_2_2_3->setText( tr( "RFC" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBNCliente->setText( tr( "Nuevo Cliente" ) );
    QPBRCliente->setText( tr( "Registra Cliente" ) );
    pushButton7_2_2->setText( tr( "Cancelar" ) );
    textLabel1_2_3_2_2_2->setText( tr( "Delegacion/Municipio" ) );
    textLabel1_2_3_2_2_2_2->setText( tr( "Estado" ) );
    textLabel1_2_3_2->setText( tr( "Calle" ) );
    textLabel1_2_3_2_2->setText( tr( "Numero" ) );
    textLabel1_2_3_2_2_3->setText( tr( "Colonia" ) );
    textLabel1_2_3_2_2_3_2->setText( tr( "CP" ) );
    textLabel1->setText( tr( "Telefono" ) );
    textLabel1_2->setText( tr( "Correo Electronico" ) );
    QLECorreoE->setText( QString::null );
}

