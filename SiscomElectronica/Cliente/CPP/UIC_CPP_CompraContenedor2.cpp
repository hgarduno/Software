/****************************************************************************
** Form implementation generated from reading ui file 'UI/CompraContenedor2.ui'
**
** Created: Fri Apr 12 21:26:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CompraContenedor2.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CompraContenedor2 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CompraContenedor2::CompraContenedor2( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CompraContenedor2" );
    CompraContenedor2Layout = new QGridLayout( this, 1, 1, 11, 6, "CompraContenedor2Layout"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel2 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Clave" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "C Prov" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cant" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Peso" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "P T" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "C Envio" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "C U $" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "P C Envio" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "C F Pesos" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "C Final" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "C Partida" ) );
    QTProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTProductos->sizePolicy().hasHeightForWidth() ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 11 );
    layout8->addWidget( QTProductos );

    CompraContenedor2Layout->addLayout( layout8, 1, 0 );

    layout54 = new QHBoxLayout( 0, 0, 6, "layout54"); 

    pushButton5 = new QPushButton( this, "pushButton5" );
    layout54->addWidget( pushButton5 );

    QPBAgregaFactura = new QPushButton( this, "QPBAgregaFactura" );
    QPBAgregaFactura->setEnabled( TRUE );
    layout54->addWidget( QPBAgregaFactura );

    CompraContenedor2Layout->addLayout( layout54, 2, 0 );

    layout60 = new QHBoxLayout( 0, 0, 6, "layout60"); 

    layout59 = new QHBoxLayout( 0, 0, 6, "layout59"); 

    layout58 = new QVBoxLayout( 0, 0, 6, "layout58"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout58->addWidget( textLabel3 );

    textEdit3 = new QTextEdit( this, "textEdit3" );
    textEdit3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 1, 0, textEdit3->sizePolicy().hasHeightForWidth() ) );
    layout58->addWidget( textEdit3 );
    layout59->addLayout( layout58 );

    layout50 = new QVBoxLayout( 0, 0, 6, "layout50"); 

    layout40_2 = new QVBoxLayout( 0, 0, 6, "layout40_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout40_2->addWidget( textLabel3_2 );

    QLECostoEnvio = new QLineEdit( this, "QLECostoEnvio" );
    QLECostoEnvio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoEnvio->sizePolicy().hasHeightForWidth() ) );
    layout40_2->addWidget( QLECostoEnvio );
    layout50->addLayout( layout40_2 );

    layout40_2_2 = new QVBoxLayout( 0, 0, 6, "layout40_2_2"); 

    textLabel3_2_2 = new QLabel( this, "textLabel3_2_2" );
    textLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout40_2_2->addWidget( textLabel3_2_2 );

    QLECostoDolar = new QLineEdit( this, "QLECostoDolar" );
    QLECostoDolar->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoDolar->sizePolicy().hasHeightForWidth() ) );
    layout40_2_2->addWidget( QLECostoDolar );
    layout50->addLayout( layout40_2_2 );
    layout59->addLayout( layout50 );

    layout52 = new QVBoxLayout( 0, 0, 6, "layout52"); 

    layout40_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout40_2_2_2"); 

    textLabel3_2_2_2 = new QLabel( this, "textLabel3_2_2_2" );
    textLabel3_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout40_2_2_2->addWidget( textLabel3_2_2_2 );

    QLECostoAdministrativo = new QLineEdit( this, "QLECostoAdministrativo" );
    QLECostoAdministrativo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoAdministrativo->sizePolicy().hasHeightForWidth() ) );
    layout40_2_2_2->addWidget( QLECostoAdministrativo );
    layout52->addLayout( layout40_2_2_2 );
    spacer3 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed );
    layout52->addItem( spacer3 );
    layout59->addLayout( layout52 );
    layout60->addLayout( layout59 );

    layout57 = new QHBoxLayout( 0, 0, 6, "layout57"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel1_5 = new QLabel( this, "textLabel1_5" );
    textLabel1_5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel1_5->sizePolicy().hasHeightForWidth() ) );
    layout21->addWidget( textLabel1_5 );

    QLCNPesoCompra = new QLCDNumber( this, "QLCNPesoCompra" );
    QLCNPesoCompra->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QLCNPesoCompra->sizePolicy().hasHeightForWidth() ) );
    QLCNPesoCompra->setMinimumSize( QSize( 0, 0 ) );
    QLCNPesoCompra->setMaximumSize( QSize( 240, 32767 ) );
    QLCNPesoCompra->setNumDigits( 10 );
    layout21->addWidget( QLCNPesoCompra );
    layout57->addLayout( layout21 );

    layout21_2 = new QVBoxLayout( 0, 0, 6, "layout21_2"); 

    textLabel1_5_2 = new QLabel( this, "textLabel1_5_2" );
    textLabel1_5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel1_5_2->sizePolicy().hasHeightForWidth() ) );
    layout21_2->addWidget( textLabel1_5_2 );

    QLCDNImporteFactura = new QLCDNumber( this, "QLCDNImporteFactura" );
    QLCDNImporteFactura->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QLCDNImporteFactura->sizePolicy().hasHeightForWidth() ) );
    QLCDNImporteFactura->setMinimumSize( QSize( 0, 0 ) );
    QLCDNImporteFactura->setMaximumSize( QSize( 240, 32767 ) );
    QLCDNImporteFactura->setNumDigits( 10 );
    layout21_2->addWidget( QLCDNImporteFactura );
    layout57->addLayout( layout21_2 );

    layout21_3 = new QVBoxLayout( 0, 0, 6, "layout21_3"); 

    textLabel1_5_3_2 = new QLabel( this, "textLabel1_5_3_2" );
    textLabel1_5_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel1_5_3_2->sizePolicy().hasHeightForWidth() ) );
    layout21_3->addWidget( textLabel1_5_3_2 );

    QLCNCostoGrEnvio_2 = new QLCDNumber( this, "QLCNCostoGrEnvio_2" );
    QLCNCostoGrEnvio_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QLCNCostoGrEnvio_2->sizePolicy().hasHeightForWidth() ) );
    QLCNCostoGrEnvio_2->setMinimumSize( QSize( 0, 0 ) );
    QLCNCostoGrEnvio_2->setMaximumSize( QSize( 240, 32767 ) );
    QLCNCostoGrEnvio_2->setNumDigits( 10 );
    layout21_3->addWidget( QLCNCostoGrEnvio_2 );
    layout57->addLayout( layout21_3 );
    layout60->addLayout( layout57 );

    CompraContenedor2Layout->addLayout( layout60, 0, 0 );
    languageChange();
    resize( QSize(1098, 514).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CompraContenedor2::~CompraContenedor2()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CompraContenedor2::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel2->setText( tr( "Importacion" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Clave" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "C Prov" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Cant" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Peso" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "P T" ) );
    QTProductos->horizontalHeader()->setLabel( 5, tr( "C Envio" ) );
    QTProductos->horizontalHeader()->setLabel( 6, tr( "C U $" ) );
    QTProductos->horizontalHeader()->setLabel( 7, tr( "P C Envio" ) );
    QTProductos->horizontalHeader()->setLabel( 8, tr( "C F Pesos" ) );
    QTProductos->horizontalHeader()->setLabel( 9, tr( "C Final" ) );
    QTProductos->horizontalHeader()->setLabel( 10, tr( "C Partida" ) );
    pushButton5->setText( tr( "Registrar Contenedor" ) );
    QPBAgregaFactura->setText( tr( "Agrega Factura" ) );
    textLabel3->setText( tr( "Descripcion Compra" ) );
    textLabel3_2->setText( tr( "Costo Envio" ) );
    textLabel3_2_2->setText( tr( "Cotizacion Dolar" ) );
    textLabel3_2_2_2->setText( tr( "Costo Administrativo" ) );
    textLabel1_5->setText( tr( "Peso Compra" ) );
    textLabel1_5_2->setText( tr( "Importe Compra" ) );
    textLabel1_5_3_2->setText( tr( "Costo Por Gramo Envio" ) );
}

