/****************************************************************************
** Form implementation generated from reading ui file 'UI/ConExpendiosVenta.ui'
**
** Created: Wed Apr 10 20:52:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ConExpendiosVenta.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ConExpendiosVenta as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ConExpendiosVenta::ConExpendiosVenta( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ConExpendiosVenta" );
    ConExpendiosVentaLayout = new QGridLayout( this, 1, 1, 11, 6, "ConExpendiosVentaLayout"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout22->addWidget( textLabel3 );

    QLEPrincipal = new QLineEdit( this, "QLEPrincipal" );
    QLEPrincipal->setReadOnly( TRUE );
    layout22->addWidget( QLEPrincipal );

    ConExpendiosVentaLayout->addLayout( layout22, 0, 0 );

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout20->addWidget( textLabel2 );

    QTExpendios = new QTable( this, "QTExpendios" );
    QTExpendios->setNumCols( QTExpendios->numCols() + 1 );
    QTExpendios->horizontalHeader()->setLabel( QTExpendios->numCols() - 1, tr( "Expendio" ) );
    QTExpendios->setNumRows( 0 );
    QTExpendios->setNumCols( 1 );
    QTExpendios->setReadOnly( TRUE );
    layout20->addWidget( QTExpendios );

    ConExpendiosVentaLayout->addLayout( layout20, 1, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBOExpendio = new QPushButton( this, "QPBOExpendio" );
    QPBOExpendio->setAutoDefault( FALSE );
    layout4->addWidget( QPBOExpendio );

    QPBDejaPrecios = new QPushButton( this, "QPBDejaPrecios" );
    QPBDejaPrecios->setAutoDefault( FALSE );
    layout4->addWidget( QPBDejaPrecios );

    QPBElimina = new QPushButton( this, "QPBElimina" );
    QPBElimina->setAutoDefault( FALSE );
    layout4->addWidget( QPBElimina );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    QPBAceptar->setDefault( FALSE );
    layout4->addWidget( QPBAceptar );

    ConExpendiosVentaLayout->addLayout( layout4, 2, 0 );
    languageChange();
    resize( QSize(662, 322).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ConExpendiosVenta::~ConExpendiosVenta()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ConExpendiosVenta::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel3->setText( tr( "Expendio Principal" ) );
    textLabel2->setText( tr( "Expendios Activos" ) );
    QTExpendios->horizontalHeader()->setLabel( 0, tr( "Expendio" ) );
    QPBOExpendio->setText( tr( "Otro Expendio" ) );
    QPBDejaPrecios->setText( tr( "Deja Precios" ) );
    QPBElimina->setText( tr( "Eliminar Conexiones" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
}

