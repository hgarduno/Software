/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaCliente.ui'
**
** Created: Thu Apr 11 21:07:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaCliente.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaCliente as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaCliente::CapturaCliente( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaCliente" );
    CapturaClienteLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaClienteLayout"); 

    layout87 = new QHBoxLayout( 0, 0, 6, "layout87"); 

    layout81 = new QVBoxLayout( 0, 0, 6, "layout81"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout81->addWidget( textLabel3 );

    QLEApellidoPaterno = new QLineEdit( this, "QLEApellidoPaterno" );
    QLEApellidoPaterno->setEnabled( FALSE );
    layout81->addWidget( QLEApellidoPaterno );
    layout87->addLayout( layout81 );

    layout83 = new QVBoxLayout( 0, 0, 6, "layout83"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout83->addWidget( textLabel3_2 );

    QLEApellidoMaterno = new QLineEdit( this, "QLEApellidoMaterno" );
    QLEApellidoMaterno->setEnabled( FALSE );
    layout83->addWidget( QLEApellidoMaterno );
    layout87->addLayout( layout83 );

    layout84 = new QVBoxLayout( 0, 0, 6, "layout84"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout84->addWidget( textLabel4 );

    QLENombres = new QLineEdit( this, "QLENombres" );
    QLENombres->setEnabled( FALSE );
    layout84->addWidget( QLENombres );
    layout87->addLayout( layout84 );

    CapturaClienteLayout->addMultiCellLayout( layout87, 1, 1, 0, 1 );

    layout72 = new QHBoxLayout( 0, 0, 6, "layout72"); 

    QPBCrear = new QPushButton( this, "QPBCrear" );
    QPBCrear->setEnabled( FALSE );
    QPBCrear->setAutoDefault( FALSE );
    layout72->addWidget( QPBCrear );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout72->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout72->addWidget( QPBCancelar );

    CapturaClienteLayout->addMultiCellLayout( layout72, 2, 2, 0, 1 );

    layout80 = new QVBoxLayout( 0, 0, 6, "layout80"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout80->addWidget( textLabel2 );

    QLEClaveCliente = new QLineEdit( this, "QLEClaveCliente" );
    QLEClaveCliente->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEClaveCliente->sizePolicy().hasHeightForWidth() ) );
    layout80->addWidget( QLEClaveCliente );

    CapturaClienteLayout->addLayout( layout80, 0, 0 );

    layout92 = new QVBoxLayout( 0, 0, 6, "layout92"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout92->addWidget( textLabel6 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    layout92->addWidget( QLERFC );

    CapturaClienteLayout->addLayout( layout92, 0, 1 );
    languageChange();
    resize( QSize(646, 137).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaCliente::~CapturaCliente()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaCliente::languageChange()
{
    setCaption( tr( "Captura Cliente" ) );
    textLabel3->setText( tr( "Apellido Paterno:" ) );
    textLabel3_2->setText( tr( "Apellido Materno:" ) );
    textLabel4->setText( tr( "Nombres:" ) );
    QPBCrear->setText( tr( "Crear" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel2->setText( tr( "Clave Cliente:" ) );
    textLabel6->setText( tr( "R.F.C.:" ) );
}

