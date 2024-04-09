/****************************************************************************
** Form implementation generated from reading ui file 'UI/PagaConTransferencia.ui'
**
** Created: lun abr 1 18:57:56 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PagaConTransferencia.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a PagaConTransferencia as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
PagaConTransferencia::PagaConTransferencia( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "PagaConTransferencia" );
    PagaConTransferenciaLayout = new QGridLayout( this, 1, 1, 11, 6, "PagaConTransferenciaLayout"); 

    layout49 = new QVBoxLayout( 0, 0, 6, "layout49"); 

    layout40 = new QVBoxLayout( 0, 0, 6, "layout40"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout40->addWidget( textLabel2 );

    QLETelefono = new QLineEdit( this, "QLETelefono" );
    layout40->addWidget( QLETelefono );
    layout49->addLayout( layout40 );

    layout48 = new QHBoxLayout( 0, 0, 6, "layout48"); 

    QBGEdoTransferencia = new QButtonGroup( this, "QBGEdoTransferencia" );
    QBGEdoTransferencia->setColumnLayout(0, Qt::Vertical );
    QBGEdoTransferencia->layout()->setSpacing( 6 );
    QBGEdoTransferencia->layout()->setMargin( 11 );
    QBGEdoTransferenciaLayout = new QGridLayout( QBGEdoTransferencia->layout() );
    QBGEdoTransferenciaLayout->setAlignment( Qt::AlignTop );

    radioButton2 = new QRadioButton( QBGEdoTransferencia, "radioButton2" );
    QBGEdoTransferencia->insert( radioButton2, 1 );

    QBGEdoTransferenciaLayout->addWidget( radioButton2, 1, 0 );

    QRBSeReflejo = new QRadioButton( QBGEdoTransferencia, "QRBSeReflejo" );
    QBGEdoTransferencia->insert( QRBSeReflejo, 0 );

    QBGEdoTransferenciaLayout->addWidget( QRBSeReflejo, 0, 0 );
    layout48->addWidget( QBGEdoTransferencia );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout41->addWidget( textLabel3 );

    QTEObservaciones = new QTextEdit( this, "QTEObservaciones" );
    layout41->addWidget( QTEObservaciones );
    layout48->addLayout( layout41 );
    layout49->addLayout( layout48 );

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout47->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout47->addWidget( QPBCancelar );
    layout49->addLayout( layout47 );

    PagaConTransferenciaLayout->addLayout( layout49, 0, 0 );
    languageChange();
    resize( QSize(406, 151).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PagaConTransferencia::~PagaConTransferencia()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PagaConTransferencia::languageChange()
{
    setCaption( tr( "Form3" ) );
    textLabel2->setText( tr( "Telefono" ) );
    QLETelefono->setInputMask( tr( "##-####-####; " ) );
    QBGEdoTransferencia->setTitle( tr( "EstadoTransferencia" ) );
    radioButton2->setText( tr( "&No se valido la transferencia" ) );
    radioButton2->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    QRBSeReflejo->setText( tr( "&Se Reflejo la transferencia" ) );
    QRBSeReflejo->setAccel( QKeySequence( tr( "Alt+S" ) ) );
    textLabel3->setText( tr( "Observaciones" ) );
    QPBAceptar->setText( tr( "&Aceptar" ) );
    QPBAceptar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QPBCancelar->setText( tr( "&Cancelar" ) );
    QPBCancelar->setAccel( QKeySequence( tr( "Alt+C" ) ) );
}

