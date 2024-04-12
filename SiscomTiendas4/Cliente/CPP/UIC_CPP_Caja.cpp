/****************************************************************************
** Form implementation generated from reading ui file 'UI/Caja.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Caja.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <QCtrlOrdenes.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"
#include "QCtrlOrdenes.h"

/*
 *  Constructs a Caja as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Caja::Caja( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Caja" );
    CajaLayout = new QGridLayout( this, 1, 1, 11, 6, "CajaLayout"); 

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( textLabel1 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    QCtrFechaIni->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaIni->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( QCtrFechaIni );
    layout28->addLayout( layout26 );

    layout26_2 = new QVBoxLayout( 0, 0, 6, "layout26_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout26_2->addWidget( textLabel1_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout26_2->addWidget( QCtrFechaFin );
    layout28->addLayout( layout26_2 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout28->addItem( spacer1 );

    CajaLayout->addLayout( layout28, 0, 0 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout25->addWidget( textLabel4 );

    QCtrOrdenes = new QCtrlOrdenes( this, "QCtrOrdenes" );
    QCtrOrdenes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)7, 0, 0, QCtrOrdenes->sizePolicy().hasHeightForWidth() ) );
    layout25->addWidget( QCtrOrdenes );

    CajaLayout->addLayout( layout25, 1, 0 );

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout44->addWidget( textLabel2_4 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTDatos->sizePolicy().hasHeightForWidth() ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );
    QTDatos->setReadOnly( TRUE );
    layout44->addWidget( QTDatos );

    CajaLayout->addLayout( layout44, 2, 0 );

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    layout46 = new QHBoxLayout( 0, 0, 6, "layout46"); 

    QPBOrdenes = new QPushButton( this, "QPBOrdenes" );
    QPBOrdenes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPBOrdenes->sizePolicy().hasHeightForWidth() ) );
    QPBOrdenes->setMinimumSize( QSize( 0, 70 ) );
    QPBOrdenes->setMaximumSize( QSize( 32767, 70 ) );
    layout46->addWidget( QPBOrdenes );

    layout43 = new QVBoxLayout( 0, 0, 0, "layout43"); 

    pushButton13 = new QPushButton( this, "pushButton13" );
    layout43->addWidget( pushButton13 );

    pushButton13_2 = new QPushButton( this, "pushButton13_2" );
    layout43->addWidget( pushButton13_2 );

    pushButton13_2_2 = new QPushButton( this, "pushButton13_2_2" );
    layout43->addWidget( pushButton13_2_2 );
    layout46->addLayout( layout43 );

    QPBMOrden = new QPushButton( this, "QPBMOrden" );
    QPBMOrden->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPBMOrden->sizePolicy().hasHeightForWidth() ) );
    QPBMOrden->setMinimumSize( QSize( 0, 70 ) );
    QPBMOrden->setMaximumSize( QSize( 32767, 70 ) );
    layout46->addWidget( QPBMOrden );

    QPBRVenta = new QPushButton( this, "QPBRVenta" );
    QPBRVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPBRVenta->sizePolicy().hasHeightForWidth() ) );
    QPBRVenta->setMinimumSize( QSize( 0, 70 ) );
    QPBRVenta->setMaximumSize( QSize( 32767, 70 ) );
    layout46->addWidget( QPBRVenta );
    layout47->addLayout( layout46 );

    layout55 = new QVBoxLayout( 0, 0, 6, "layout55"); 

    textLabel2_4_2 = new QLabel( this, "textLabel2_4_2" );
    textLabel2_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4_2->sizePolicy().hasHeightForWidth() ) );
    layout55->addWidget( textLabel2_4_2 );

    QLCDNTotal = new QLCDNumber( this, "QLCDNTotal" );
    QLCDNTotal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLCDNTotal->sizePolicy().hasHeightForWidth() ) );
    QLCDNTotal->setNumDigits( 10 );
    layout55->addWidget( QLCDNTotal );
    layout47->addLayout( layout55 );

    CajaLayout->addLayout( layout47, 3, 0 );
    languageChange();
    resize( QSize(625, 612).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Caja::~Caja()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Caja::languageChange()
{
    setCaption( tr( "Sistema De Caja" ) );
    textLabel1->setText( tr( "Fecha Inicio" ) );
    textLabel1_2->setText( tr( "Fecha Fin" ) );
    textLabel4->setText( tr( "Ordenes" ) );
    textLabel2_4->setText( tr( "Detalle Orden" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    QPBOrdenes->setText( tr( "Consulta\n"
"Ordenes" ) );
    pushButton13->setText( tr( "Eliminar" ) );
    pushButton13_2->setText( tr( "M. Cantidad" ) );
    pushButton13_2_2->setText( tr( "A. Orden" ) );
    QPBMOrden->setText( tr( "Modificar\n"
"Orden" ) );
    QPBRVenta->setText( tr( "Registra\n"
"Venta" ) );
    textLabel2_4_2->setText( tr( "Total De La Orden" ) );
}

