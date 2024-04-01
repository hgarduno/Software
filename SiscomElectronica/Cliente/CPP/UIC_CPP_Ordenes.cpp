/****************************************************************************
** Form implementation generated from reading ui file 'UI/Ordenes.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Ordenes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Ordenes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Ordenes::Ordenes( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Ordenes" );
    OrdenesLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenesLayout"); 

    layout77 = new QVBoxLayout( 0, 0, 6, "layout77"); 

    textLabel9 = new QLabel( this, "textLabel9" );
    layout77->addWidget( textLabel9 );

    QTOrdenes = new QTable( this, "QTOrdenes" );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "# Orden" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Fecha" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Importe" ) );
    QTOrdenes->setNumRows( 0 );
    QTOrdenes->setNumCols( 3 );
    layout77->addWidget( QTOrdenes );

    OrdenesLayout->addLayout( layout77, 0, 0 );

    layout77_2 = new QVBoxLayout( 0, 0, 6, "layout77_2"); 

    textLabel9_2 = new QLabel( this, "textLabel9_2" );
    layout77_2->addWidget( textLabel9_2 );

    QTDetalleOrden = new QTable( this, "QTDetalleOrden" );
    QTDetalleOrden->setNumCols( QTDetalleOrden->numCols() + 1 );
    QTDetalleOrden->horizontalHeader()->setLabel( QTDetalleOrden->numCols() - 1, tr( "Cantidad" ) );
    QTDetalleOrden->setNumCols( QTDetalleOrden->numCols() + 1 );
    QTDetalleOrden->horizontalHeader()->setLabel( QTDetalleOrden->numCols() - 1, tr( "Producto" ) );
    QTDetalleOrden->setNumCols( QTDetalleOrden->numCols() + 1 );
    QTDetalleOrden->horizontalHeader()->setLabel( QTDetalleOrden->numCols() - 1, tr( "Precio" ) );
    QTDetalleOrden->setNumCols( QTDetalleOrden->numCols() + 1 );
    QTDetalleOrden->horizontalHeader()->setLabel( QTDetalleOrden->numCols() - 1, tr( "Total" ) );
    QTDetalleOrden->setNumRows( 0 );
    QTDetalleOrden->setNumCols( 4 );
    layout77_2->addWidget( QTDetalleOrden );

    OrdenesLayout->addLayout( layout77_2, 1, 0 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    QPBRangoFechas = new QPushButton( this, "QPBRangoFechas" );
    QPBRangoFechas->setMinimumSize( QSize( 0, 50 ) );
    layout3->addWidget( QPBRangoFechas );

    QPBAContabilidad = new QPushButton( this, "QPBAContabilidad" );
    QPBAContabilidad->setMinimumSize( QSize( 0, 50 ) );
    layout3->addWidget( QPBAContabilidad );

    QPBCopiar_2 = new QPushButton( this, "QPBCopiar_2" );
    QPBCopiar_2->setMinimumSize( QSize( 0, 50 ) );
    layout3->addWidget( QPBCopiar_2 );

    QPBCopiar = new QPushButton( this, "QPBCopiar" );
    QPBCopiar->setMinimumSize( QSize( 0, 50 ) );
    layout3->addWidget( QPBCopiar );

    OrdenesLayout->addLayout( layout3, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Ordenes::~Ordenes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Ordenes::languageChange()
{
    setCaption( tr( "Form6" ) );
    textLabel9->setText( tr( "textLabel9" ) );
    QTOrdenes->horizontalHeader()->setLabel( 0, tr( "# Orden" ) );
    QTOrdenes->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTOrdenes->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    textLabel9_2->setText( tr( "Detalle Orden" ) );
    QTDetalleOrden->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTDetalleOrden->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTDetalleOrden->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTDetalleOrden->horizontalHeader()->setLabel( 3, tr( "Total" ) );
    QPBRangoFechas->setText( tr( "Rango \n"
"De \n"
"Fechas" ) );
    QPBAContabilidad->setText( tr( "Anexar Orden\n"
"A La Contabilidad" ) );
    QPBCopiar_2->setText( tr( "Copiar" ) );
    QPBCopiar->setText( tr( "Copiar" ) );
}

