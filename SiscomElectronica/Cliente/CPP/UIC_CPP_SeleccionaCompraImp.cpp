/****************************************************************************
** Form implementation generated from reading ui file 'UI/SeleccionaCompraImp.ui'
**
** Created: Thu Dec 21 12:53:46 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SeleccionaCompraImp.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a SeleccionaCompraImp as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SeleccionaCompraImp::SeleccionaCompraImp( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SeleccionaCompraImp" );
    SeleccionaCompraImpLayout = new QGridLayout( this, 1, 1, 11, 6, "SeleccionaCompraImpLayout"); 

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout25->addWidget( textLabel1 );

    QTCompsImportacion = new QTable( this, "QTCompsImportacion" );
    QTCompsImportacion->setNumCols( QTCompsImportacion->numCols() + 1 );
    QTCompsImportacion->horizontalHeader()->setLabel( QTCompsImportacion->numCols() - 1, tr( "Empresa" ) );
    QTCompsImportacion->setNumCols( QTCompsImportacion->numCols() + 1 );
    QTCompsImportacion->horizontalHeader()->setLabel( QTCompsImportacion->numCols() - 1, tr( "Descripcion" ) );
    QTCompsImportacion->setNumCols( QTCompsImportacion->numCols() + 1 );
    QTCompsImportacion->horizontalHeader()->setLabel( QTCompsImportacion->numCols() - 1, tr( "Importe" ) );
    QTCompsImportacion->setNumCols( QTCompsImportacion->numCols() + 1 );
    QTCompsImportacion->horizontalHeader()->setLabel( QTCompsImportacion->numCols() - 1, tr( "Peso" ) );
    QTCompsImportacion->setNumRows( 0 );
    QTCompsImportacion->setNumCols( 4 );
    QTCompsImportacion->setReadOnly( TRUE );
    layout25->addWidget( QTCompsImportacion );

    SeleccionaCompraImpLayout->addLayout( layout25, 0, 0 );

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    pushButton8 = new QPushButton( this, "pushButton8" );
    pushButton8->setAutoDefault( FALSE );
    layout26->addWidget( pushButton8 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout26->addWidget( QPBAceptar );

    pushButton8_2_2 = new QPushButton( this, "pushButton8_2_2" );
    pushButton8_2_2->setAutoDefault( FALSE );
    layout26->addWidget( pushButton8_2_2 );

    SeleccionaCompraImpLayout->addLayout( layout26, 1, 0 );
    languageChange();
    resize( QSize(818, 315).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SeleccionaCompraImp::~SeleccionaCompraImp()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SeleccionaCompraImp::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Compras Importacion" ) );
    QTCompsImportacion->horizontalHeader()->setLabel( 0, tr( "Empresa" ) );
    QTCompsImportacion->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTCompsImportacion->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    QTCompsImportacion->horizontalHeader()->setLabel( 3, tr( "Peso" ) );
    pushButton8->setText( tr( "Cancelar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    pushButton8_2_2->setText( tr( "pushButton8" ) );
}

