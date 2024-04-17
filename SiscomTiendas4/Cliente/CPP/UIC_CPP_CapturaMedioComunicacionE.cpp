/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaMedioComunicacionE.ui'
**
** Created: Fri Apr 12 21:36:42 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaMedioComunicacionE.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlMedComunicacion.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlMedComunicacion.h"

/*
 *  Constructs a CapturaMedioComunicacionE as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaMedioComunicacionE::CapturaMedioComunicacionE( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaMedioComunicacionE" );
    CapturaMedioComunicacionELayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaMedioComunicacionELayout"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QCtrMedioComunicacion = new QCtrlMedComunicacion( this, "QCtrMedioComunicacion" );
    layout2->addWidget( QCtrMedioComunicacion );
    layout6->addLayout( layout2 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout3->addWidget( textLabel2 );

    QLEDato = new QLineEdit( this, "QLEDato" );
    layout3->addWidget( QLEDato );
    layout5->addLayout( layout3 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout4->addWidget( textLabel3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout4->addWidget( QTEDescripcion );
    layout5->addLayout( layout4 );
    layout6->addLayout( layout5 );
    layout8->addLayout( layout6 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout7->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout7->addWidget( QPBCancelar );
    layout8->addLayout( layout7 );

    CapturaMedioComunicacionELayout->addLayout( layout8, 0, 0 );
    languageChange();
    resize( QSize(373, 257).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaMedioComunicacionE::~CapturaMedioComunicacionE()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaMedioComunicacionE::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Medio De Comunicacion" ) );
    textLabel2->setText( tr( "Dato" ) );
    textLabel3->setText( tr( "Descripcion" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

