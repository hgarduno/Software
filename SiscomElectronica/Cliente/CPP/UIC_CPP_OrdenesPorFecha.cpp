/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenesPorFecha.ui'
**
** Created: Thu Dec 21 13:54:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenesPorFecha.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a OrdenesPorFecha as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
OrdenesPorFecha::OrdenesPorFecha( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "OrdenesPorFecha" );
    OrdenesPorFechaLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenesPorFechaLayout"); 

    textLabel6 = new QLabel( this, "textLabel6" );

    OrdenesPorFechaLayout->addWidget( textLabel6, 0, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Num. Orden" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe Total" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe Con IVA" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cliente" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 5 );
    QTDatos->setReadOnly( TRUE );

    OrdenesPorFechaLayout->addWidget( QTDatos, 1, 0 );

    layout80 = new QHBoxLayout( 0, 0, 6, "layout80"); 

    layout75 = new QVBoxLayout( 0, 0, 6, "layout75"); 

    QPBSOrdenes = new QPushButton( this, "QPBSOrdenes" );
    QPBSOrdenes->setAutoDefault( FALSE );
    layout75->addWidget( QPBSOrdenes );

    pushButton44_2 = new QPushButton( this, "pushButton44_2" );
    pushButton44_2->setAutoDefault( FALSE );
    layout75->addWidget( pushButton44_2 );

    pushButton44_2_2 = new QPushButton( this, "pushButton44_2_2" );
    pushButton44_2_2->setAutoDefault( FALSE );
    layout75->addWidget( pushButton44_2_2 );
    layout80->addLayout( layout75 );

    layout79 = new QVBoxLayout( 0, 0, 6, "layout79"); 

    textLabel7 = new QLabel( this, "textLabel7" );
    textLabel7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel7->sizePolicy().hasHeightForWidth() ) );
    layout79->addWidget( textLabel7 );

    QLCDTotal = new QLCDNumber( this, "QLCDTotal" );
    QLCDTotal->setNumDigits( 8 );
    layout79->addWidget( QLCDTotal );
    layout80->addLayout( layout79 );

    layout78 = new QVBoxLayout( 0, 0, 6, "layout78"); 

    textLabel7_2 = new QLabel( this, "textLabel7_2" );
    textLabel7_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel7_2->sizePolicy().hasHeightForWidth() ) );
    layout78->addWidget( textLabel7_2 );

    QLCDTotIVA = new QLCDNumber( this, "QLCDTotIVA" );
    QLCDTotIVA->setNumDigits( 8 );
    layout78->addWidget( QLCDTotIVA );
    layout80->addLayout( layout78 );

    OrdenesPorFechaLayout->addLayout( layout80, 2, 0 );
    languageChange();
    resize( QSize(669, 517).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenesPorFecha::~OrdenesPorFecha()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenesPorFecha::languageChange()
{
    setCaption( tr( "Ordenes Por Fecha" ) );
    textLabel6->setText( tr( "Ordenes Registradas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Num. Orden" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Importe Total" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Importe Con IVA" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Fecha" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Cliente" ) );
    QPBSOrdenes->setText( tr( "Selecciona Ordenes" ) );
    pushButton44_2->setText( tr( "pushButton44" ) );
    pushButton44_2_2->setText( tr( "pushButton44" ) );
    textLabel7->setText( tr( "Importe" ) );
    textLabel7_2->setText( tr( "Importe Con IVA" ) );
}

