/****************************************************************************
** Form implementation generated from reading ui file 'UI/VentasPorCaja.ui'
**
** Created: Thu Dec 21 12:53:41 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_VentasPorCaja.h"

#include <qvariant.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a VentasPorCaja as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
VentasPorCaja::VentasPorCaja( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "VentasPorCaja" );
    VentasPorCajaLayout = new QGridLayout( this, 1, 1, 11, 6, "VentasPorCajaLayout"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Caja" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Total" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Validacion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Corto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Total Cortes" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 6 );

    VentasPorCajaLayout->addWidget( QTDatos, 0, 0 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    QPBRangoFechas = new QPushButton( this, "QPBRangoFechas" );
    QPBRangoFechas->setMinimumSize( QSize( 0, 50 ) );
    layout20->addWidget( QPBRangoFechas );

    QPBADatos = new QPushButton( this, "QPBADatos" );
    QPBADatos->setMinimumSize( QSize( 0, 50 ) );
    layout20->addWidget( QPBADatos );
    layout21->addLayout( layout20 );

    QLCDTotalVentas = new QLCDNumber( this, "QLCDTotalVentas" );
    QLCDTotalVentas->setNumDigits( 10 );
    layout21->addWidget( QLCDTotalVentas );

    VentasPorCajaLayout->addLayout( layout21, 1, 0 );
    languageChange();
    resize( QSize(681, 583).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
VentasPorCaja::~VentasPorCaja()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void VentasPorCaja::languageChange()
{
    setCaption( tr( "Reporte de Ventas Por Caja" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Caja" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Total" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Validacion" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Corto" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Total Cortes" ) );
    QPBRangoFechas->setText( tr( "Captura Rango \n"
"De Fechas" ) );
    QPBADatos->setText( tr( "Actualiza \n"
"Datos" ) );
}

