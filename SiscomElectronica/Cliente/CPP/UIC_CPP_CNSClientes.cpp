/****************************************************************************
** Form implementation generated from reading ui file 'UI/CNSClientes.ui'
**
** Created: Thu Dec 21 13:55:30 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CNSClientes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlEscuelas.h"

/*
 *  Constructs a CNSClientes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CNSClientes::CNSClientes( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CNSClientes" );
    CNSClientesLayout = new QGridLayout( this, 1, 1, 11, 6, "CNSClientesLayout"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout11->addWidget( textLabel1 );

    QCBRFC = new QComboBox( FALSE, this, "QCBRFC" );
    QCBRFC->setEditable( TRUE );
    QCBRFC->setInsertionPolicy( QComboBox::NoInsertion );
    QCBRFC->setAutoCompletion( TRUE );
    layout11->addWidget( QCBRFC );

    CNSClientesLayout->addLayout( layout11, 0, 0 );

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    layout15_2 = new QVBoxLayout( 0, 0, 6, "layout15_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout15_2->addWidget( textLabel4_2 );

    QLECliente = new QLineEdit( this, "QLECliente" );
    QLECliente->setReadOnly( TRUE );
    layout15_2->addWidget( QLECliente );
    layout18->addLayout( layout15_2 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout16->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout16->addWidget( QPBCancelar );
    layout18->addLayout( layout16 );

    CNSClientesLayout->addLayout( layout18, 5, 0 );
    spacer2 = new QSpacerItem( 20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding );
    CNSClientesLayout->addItem( spacer2, 4, 0 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout15->addWidget( textLabel4 );

    lineEdit10 = new QLineEdit( this, "lineEdit10" );
    lineEdit10->setReadOnly( TRUE );
    layout15->addWidget( lineEdit10 );

    CNSClientesLayout->addLayout( layout15, 3, 0 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout12->addWidget( textLabel2 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    QLENombre->setReadOnly( TRUE );
    layout12->addWidget( QLENombre );
    layout9->addLayout( layout12 );

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout12_2->addWidget( textLabel2_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    QLEAPaterno->setReadOnly( TRUE );
    layout12_2->addWidget( QLEAPaterno );
    layout9->addLayout( layout12_2 );

    layout12_3 = new QVBoxLayout( 0, 0, 6, "layout12_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    layout12_3->addWidget( textLabel2_3 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    QLEAMaterno->setReadOnly( TRUE );
    layout12_3->addWidget( QLEAMaterno );
    layout9->addLayout( layout12_3 );

    CNSClientesLayout->addLayout( layout9, 2, 0 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout10->addWidget( textLabel1_2 );

    QCtrEscuelas = new QCtrlEscuelas( this, "QCtrEscuelas" );
    layout10->addWidget( QCtrEscuelas );

    CNSClientesLayout->addLayout( layout10, 1, 0 );
    languageChange();
    resize( QSize(424, 446).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CNSClientes::~CNSClientes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CNSClientes::languageChange()
{
    setCaption( tr( "Consulta Clientes" ) );
    textLabel1->setText( tr( "RFC" ) );
    textLabel4_2->setText( tr( "Cliente" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel4->setText( tr( "Correo Electronico" ) );
    textLabel2->setText( tr( "Nombre" ) );
    textLabel2_2->setText( tr( "Apellido Paterno" ) );
    textLabel2_3->setText( tr( "Apellido Materno" ) );
    textLabel1_2->setText( tr( "Escuelas" ) );
}

