/****************************************************************************
** Form implementation generated from reading ui file 'UI/CorteCaja.ui'
**
** Created: Wed Jan 31 10:48:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CorteCaja.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a CorteCaja as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CorteCaja::CorteCaja( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CorteCaja" );
    CorteCajaLayout = new QGridLayout( this, 1, 1, 11, 6, "CorteCajaLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QTVentasPorCaja = new QTable( this, "QTVentasPorCaja" );
    QTVentasPorCaja->setNumCols( QTVentasPorCaja->numCols() + 1 );
    QTVentasPorCaja->horizontalHeader()->setLabel( QTVentasPorCaja->numCols() - 1, tr( "Corte" ) );
    QTVentasPorCaja->setNumCols( QTVentasPorCaja->numCols() + 1 );
    QTVentasPorCaja->horizontalHeader()->setLabel( QTVentasPorCaja->numCols() - 1, tr( "Caja" ) );
    QTVentasPorCaja->setNumCols( QTVentasPorCaja->numCols() + 1 );
    QTVentasPorCaja->horizontalHeader()->setLabel( QTVentasPorCaja->numCols() - 1, tr( "Total" ) );
    QTVentasPorCaja->setNumCols( QTVentasPorCaja->numCols() + 1 );
    QTVentasPorCaja->horizontalHeader()->setLabel( QTVentasPorCaja->numCols() - 1, tr( "Validacion" ) );
    QTVentasPorCaja->setNumCols( QTVentasPorCaja->numCols() + 1 );
    QTVentasPorCaja->horizontalHeader()->setLabel( QTVentasPorCaja->numCols() - 1, tr( "Importe Inicial" ) );
    QTVentasPorCaja->setNumCols( QTVentasPorCaja->numCols() + 1 );
    QTVentasPorCaja->horizontalHeader()->setLabel( QTVentasPorCaja->numCols() - 1, tr( "Total En Caja" ) );
    QTVentasPorCaja->setNumCols( QTVentasPorCaja->numCols() + 1 );
    QTVentasPorCaja->horizontalHeader()->setLabel( QTVentasPorCaja->numCols() - 1, tr( "Total Cortes" ) );
    QTVentasPorCaja->setNumRows( 0 );
    QTVentasPorCaja->setNumCols( 7 );
    QTVentasPorCaja->setReadOnly( TRUE );
    layout1->addWidget( QTVentasPorCaja );

    CorteCajaLayout->addLayout( layout1, 0, 0 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QTCorteCaja = new QTable( this, "QTCorteCaja" );
    QTCorteCaja->setNumCols( QTCorteCaja->numCols() + 1 );
    QTCorteCaja->horizontalHeader()->setLabel( QTCorteCaja->numCols() - 1, tr( "Denominacion" ) );
    QTCorteCaja->setNumCols( QTCorteCaja->numCols() + 1 );
    QTCorteCaja->horizontalHeader()->setLabel( QTCorteCaja->numCols() - 1, tr( "Cantidad" ) );
    QTCorteCaja->setNumCols( QTCorteCaja->numCols() + 1 );
    QTCorteCaja->horizontalHeader()->setLabel( QTCorteCaja->numCols() - 1, tr( "Total" ) );
    QTCorteCaja->setNumRows( 0 );
    QTCorteCaja->setNumCols( 3 );
    QTCorteCaja->setReadOnly( TRUE );
    layout1_2->addWidget( QTCorteCaja );

    CorteCajaLayout->addLayout( layout1_2, 1, 0 );

    layout19 = new QHBoxLayout( 0, 0, 0, "layout19"); 

    layout18 = new QVBoxLayout( 0, 0, 0, "layout18"); 

    QPBRangoFechas = new QPushButton( this, "QPBRangoFechas" );
    QPBRangoFechas->setEnabled( FALSE );
    QPBRangoFechas->setMinimumSize( QSize( 0, 50 ) );
    layout18->addWidget( QPBRangoFechas );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( TRUE );
    QPBActualizar->setMinimumSize( QSize( 0, 30 ) );
    layout18->addWidget( QPBActualizar );
    layout19->addLayout( layout18 );

    layout7 = new QVBoxLayout( 0, 0, 0, "layout7"); 

    QPBADenominacion = new QPushButton( this, "QPBADenominacion" );
    QPBADenominacion->setEnabled( FALSE );
    QPBADenominacion->setMinimumSize( QSize( 0, 40 ) );
    layout7->addWidget( QPBADenominacion );

    QPBEDenominacion = new QPushButton( this, "QPBEDenominacion" );
    QPBEDenominacion->setEnabled( FALSE );
    QPBEDenominacion->setMinimumSize( QSize( 0, 40 ) );
    layout7->addWidget( QPBEDenominacion );
    layout19->addLayout( layout7 );

    QBPRegistrarCaja = new QPushButton( this, "QBPRegistrarCaja" );
    QBPRegistrarCaja->setEnabled( FALSE );
    QBPRegistrarCaja->setMinimumSize( QSize( 0, 80 ) );
    layout19->addWidget( QBPRegistrarCaja );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( textLabel2_2 );

    QLCDTotalEnCaja = new QLCDNumber( this, "QLCDTotalEnCaja" );
    QLCDTotalEnCaja->setNumDigits( 8 );
    QLCDTotalEnCaja->setMode( QLCDNumber::Dec );
    layout3_2->addWidget( QLCDTotalEnCaja );
    layout19->addLayout( layout3_2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel2 );

    QLCDTotal = new QLCDNumber( this, "QLCDTotal" );
    QLCDTotal->setNumDigits( 8 );
    QLCDTotal->setMode( QLCDNumber::Dec );
    layout3->addWidget( QLCDTotal );
    layout19->addLayout( layout3 );

    CorteCajaLayout->addLayout( layout19, 2, 0 );
    languageChange();
    resize( QSize(608, 508).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CorteCaja::~CorteCaja()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CorteCaja::languageChange()
{
    setCaption( tr( "Captura Corte Caja" ) );
    textLabel1->setText( tr( "Cajas" ) );
    QTVentasPorCaja->horizontalHeader()->setLabel( 0, tr( "Corte" ) );
    QTVentasPorCaja->horizontalHeader()->setLabel( 1, tr( "Caja" ) );
    QTVentasPorCaja->horizontalHeader()->setLabel( 2, tr( "Total" ) );
    QTVentasPorCaja->horizontalHeader()->setLabel( 3, tr( "Validacion" ) );
    QTVentasPorCaja->horizontalHeader()->setLabel( 4, tr( "Importe Inicial" ) );
    QTVentasPorCaja->horizontalHeader()->setLabel( 5, tr( "Total En Caja" ) );
    QTVentasPorCaja->horizontalHeader()->setLabel( 6, tr( "Total Cortes" ) );
    textLabel1_2->setText( tr( "Cortando" ) );
    QTCorteCaja->horizontalHeader()->setLabel( 0, tr( "Denominacion" ) );
    QTCorteCaja->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTCorteCaja->horizontalHeader()->setLabel( 2, tr( "Total" ) );
    QPBRangoFechas->setText( tr( "Captura Rango\n"
"    De Fechas" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBADenominacion->setText( tr( "Agrega \n"
"Denominacion" ) );
    QPBEDenominacion->setText( tr( "Elimina\n"
"Denominacion" ) );
    QBPRegistrarCaja->setText( tr( "Registra\n"
"Corte De Caja" ) );
    textLabel2_2->setText( tr( "Estado Caja" ) );
    textLabel2->setText( tr( "Importe" ) );
}

