/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CancelarFolioAbono.ui'
**
** Created: Thu Apr 11 21:07:39 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CancelarFolioAbono.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CancelarFolioAbono as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CancelarFolioAbono::CancelarFolioAbono( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CancelarFolioAbono" );
    CancelarFolioAbonoLayout = new QGridLayout( this, 1, 1, 11, 6, "CancelarFolioAbonoLayout"); 

    layout39 = new QVBoxLayout( 0, 0, 6, "layout39"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout39->addWidget( textLabel1 );

    QLEFolioCancelar = new QLineEdit( this, "QLEFolioCancelar" );
    QLEFolioCancelar->setReadOnly( TRUE );
    layout39->addWidget( QLEFolioCancelar );

    CancelarFolioAbonoLayout->addLayout( layout39, 0, 0 );

    layout39_2 = new QVBoxLayout( 0, 0, 6, "layout39_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout39_2->addWidget( textLabel1_2 );

    QLEFolioAAsignar = new QLineEdit( this, "QLEFolioAAsignar" );
    QLEFolioAAsignar->setReadOnly( TRUE );
    layout39_2->addWidget( QLEFolioAAsignar );

    CancelarFolioAbonoLayout->addLayout( layout39_2, 0, 1 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout42->addWidget( textLabel2 );

    QTEMotivo = new QTextEdit( this, "QTEMotivo" );
    layout42->addWidget( QTEMotivo );

    CancelarFolioAbonoLayout->addMultiCellLayout( layout42, 1, 1, 0, 1 );

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    QPBRegistrarCancelacion = new QPushButton( this, "QPBRegistrarCancelacion" );
    QPBRegistrarCancelacion->setAutoDefault( FALSE );
    layout47->addWidget( QPBRegistrarCancelacion );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout47->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout47->addWidget( QPBCancelar );

    CancelarFolioAbonoLayout->addMultiCellLayout( layout47, 2, 2, 0, 1 );
    languageChange();
    resize( QSize(635, 260).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CancelarFolioAbono::~CancelarFolioAbono()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CancelarFolioAbono::languageChange()
{
    setCaption( tr( "Cancelacion Folio Abono" ) );
    textLabel1->setText( tr( "Folio A Cancelar" ) );
    textLabel1_2->setText( tr( "Siguiente Folio" ) );
    textLabel2->setText( tr( "Motivo" ) );
    QPBRegistrarCancelacion->setText( tr( "Registrar Cancelacion" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}
