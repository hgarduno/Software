/****************************************************************************
** Form implementation generated from reading ui file 'UI/ComprasImportaciones.ui'
**
** Created: Thu Apr 11 21:39:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ComprasImportaciones.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlProveedoresSE.h>
#include <qlineedit.h>
#include <QCtrlProductosSE.h>
#include <qtable.h>
#include <qgroupbox.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSE.h"
#include "QCtrlProductosSE.h"

/*
 *  Constructs a ComprasImportaciones as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ComprasImportaciones::ComprasImportaciones( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ComprasImportaciones" );
    ComprasImportacionesLayout = new QGridLayout( this, 1, 1, 11, 6, "ComprasImportacionesLayout"); 

    layout63 = new QVBoxLayout( 0, 0, 6, "layout63"); 

    layout61 = new QHBoxLayout( 0, 0, 6, "layout61"); 

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout25->addWidget( textLabel1_3 );

    QCtrProveedores = new QCtrlProveedoresSE( this, "QCtrProveedores" );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    QCtrProveedores->setMinimumSize( QSize( 250, 0 ) );
    QCtrProveedores->setMaximumSize( QSize( 1000, 32767 ) );
    layout25->addWidget( QCtrProveedores );
    layout61->addLayout( layout25 );

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    layout1_4 = new QVBoxLayout( 0, 0, 6, "layout1_4"); 

    textLabel1_6 = new QLabel( this, "textLabel1_6" );
    textLabel1_6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_6->sizePolicy().hasHeightForWidth() ) );
    layout1_4->addWidget( textLabel1_6 );

    QLENumFactura = new QLineEdit( this, "QLENumFactura" );
    QLENumFactura->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumFactura->sizePolicy().hasHeightForWidth() ) );
    layout1_4->addWidget( QLENumFactura );
    layout29->addLayout( layout1_4 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QLECostoEnvio = new QLineEdit( this, "QLECostoEnvio" );
    QLECostoEnvio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoEnvio->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QLECostoEnvio );
    layout29->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( textLabel1_2 );

    QLECostoDolar = new QLineEdit( this, "QLECostoDolar" );
    QLECostoDolar->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoDolar->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( QLECostoDolar );
    layout29->addLayout( layout1_2 );

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2->addWidget( textLabel1_2_2 );

    QLECostoAdministrativo = new QLineEdit( this, "QLECostoAdministrativo" );
    QLECostoAdministrativo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoAdministrativo->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2->addWidget( QLECostoAdministrativo );
    layout29->addLayout( layout1_2_2 );

    layout1_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2"); 

    textLabel1_2_2_2 = new QLabel( this, "textLabel1_2_2_2" );
    textLabel1_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2->addWidget( textLabel1_2_2_2 );

    QLENumPartidas = new QLineEdit( this, "QLENumPartidas" );
    QLENumPartidas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumPartidas->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2->addWidget( QLENumPartidas );
    layout29->addLayout( layout1_2_2_2 );
    layout61->addLayout( layout29 );
    layout63->addLayout( layout61 );

    layout62 = new QHBoxLayout( 0, 0, 6, "layout62"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel3 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setEnabled( FALSE );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    QCtrProductos->setMinimumSize( QSize( 250, 0 ) );
    QCtrProductos->setMaximumSize( QSize( 1000, 32767 ) );
    layout5->addWidget( QCtrProductos );
    layout62->addLayout( layout5 );

    layout30 = new QHBoxLayout( 0, 0, 6, "layout30"); 

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    textLabel1_7 = new QLabel( this, "textLabel1_7" );
    textLabel1_7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_7->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( textLabel1_7 );

    QLEFiltro = new QLineEdit( this, "QLEFiltro" );
    QLEFiltro->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFiltro->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( QLEFiltro );
    layout30->addLayout( layout48 );

    layout1_3 = new QVBoxLayout( 0, 0, 6, "layout1_3"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout1_3->addWidget( textLabel1_4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout1_3->addWidget( QLECantidad );
    layout30->addLayout( layout1_3 );

    layout1_3_2 = new QVBoxLayout( 0, 0, 6, "layout1_3_2"); 

    textLabel1_4_2 = new QLabel( this, "textLabel1_4_2" );
    textLabel1_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2->addWidget( textLabel1_4_2 );

    QLECostoUnitario = new QLineEdit( this, "QLECostoUnitario" );
    QLECostoUnitario->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoUnitario->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2->addWidget( QLECostoUnitario );
    layout30->addLayout( layout1_3_2 );

    layout1_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_3_2_2"); 

    textLabel1_4_2_2 = new QLabel( this, "textLabel1_4_2_2" );
    textLabel1_4_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_3_2_2->addWidget( textLabel1_4_2_2 );

    QLEPeso = new QLineEdit( this, "QLEPeso" );
    QLEPeso->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPeso->sizePolicy().hasHeightForWidth() ) );
    QLEPeso->setReadOnly( TRUE );
    layout1_3_2_2->addWidget( QLEPeso );
    layout30->addLayout( layout1_3_2_2 );

    layout1_3_3 = new QVBoxLayout( 0, 0, 6, "layout1_3_3"); 

    textLabel1_4_3 = new QLabel( this, "textLabel1_4_3" );
    textLabel1_4_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_3->sizePolicy().hasHeightForWidth() ) );
    layout1_3_3->addWidget( textLabel1_4_3 );

    QLECostoGrEnvio = new QLineEdit( this, "QLECostoGrEnvio" );
    QLECostoGrEnvio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoGrEnvio->sizePolicy().hasHeightForWidth() ) );
    QLECostoGrEnvio->setReadOnly( TRUE );
    layout1_3_3->addWidget( QLECostoGrEnvio );
    layout30->addLayout( layout1_3_3 );
    layout62->addLayout( layout30 );
    layout63->addLayout( layout62 );

    ComprasImportacionesLayout->addMultiCellLayout( layout63, 0, 0, 0, 2 );

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    textLabel1_8 = new QLabel( this, "textLabel1_8" );
    layout27->addWidget( textLabel1_8 );

    QLEDscCompra = new QLineEdit( this, "QLEDscCompra" );
    layout27->addWidget( QLEDscCompra );

    ComprasImportacionesLayout->addMultiCellLayout( layout27, 3, 3, 0, 2 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel2 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Proveedor" ) );
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
    QTProductos->setNumCols( 12 );
    layout8->addWidget( QTProductos );

    ComprasImportacionesLayout->addMultiCellLayout( layout8, 2, 2, 0, 2 );

    groupBox2 = new QGroupBox( this, "groupBox2" );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    layout30_2 = new QHBoxLayout( 0, 0, 6, "layout30_2"); 

    layout27_2 = new QVBoxLayout( 0, 0, 6, "layout27_2"); 

    textLabel1_9 = new QLabel( groupBox2, "textLabel1_9" );
    layout27_2->addWidget( textLabel1_9 );

    QLEProveedor = new QLineEdit( groupBox2, "QLEProveedor" );
    layout27_2->addWidget( QLEProveedor );
    layout30_2->addLayout( layout27_2 );

    layout27_2_2 = new QVBoxLayout( 0, 0, 6, "layout27_2_2"); 

    textLabel1_9_2 = new QLabel( groupBox2, "textLabel1_9_2" );
    textLabel1_9_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabel1_9_2->sizePolicy().hasHeightForWidth() ) );
    layout27_2_2->addWidget( textLabel1_9_2 );

    QLECveProveedor = new QLineEdit( groupBox2, "QLECveProveedor" );
    QLECveProveedor->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLECveProveedor->sizePolicy().hasHeightForWidth() ) );
    layout27_2_2->addWidget( QLECveProveedor );
    layout30_2->addLayout( layout27_2_2 );

    groupBox2Layout->addLayout( layout30_2, 0, 0 );

    ComprasImportacionesLayout->addWidget( groupBox2, 1, 0 );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout28 = new QVBoxLayout( 0, 0, 6, "layout28"); 

    textLabel1_10 = new QLabel( groupBox1, "textLabel1_10" );
    textLabel1_10->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabel1_10->sizePolicy().hasHeightForWidth() ) );
    layout28->addWidget( textLabel1_10 );

    QLECantidadUC = new QLineEdit( groupBox1, "QLECantidadUC" );
    QLECantidadUC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLECantidadUC->sizePolicy().hasHeightForWidth() ) );
    QLECantidadUC->setReadOnly( TRUE );
    layout28->addWidget( QLECantidadUC );

    groupBox1Layout->addLayout( layout28, 0, 0 );

    layout28_2 = new QVBoxLayout( 0, 0, 6, "layout28_2"); 

    textLabel1_10_2 = new QLabel( groupBox1, "textLabel1_10_2" );
    textLabel1_10_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_10_2->sizePolicy().hasHeightForWidth() ) );
    layout28_2->addWidget( textLabel1_10_2 );

    QLECostoUC = new QLineEdit( groupBox1, "QLECostoUC" );
    QLECostoUC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLECostoUC->sizePolicy().hasHeightForWidth() ) );
    QLECostoUC->setReadOnly( TRUE );
    layout28_2->addWidget( QLECostoUC );

    groupBox1Layout->addLayout( layout28_2, 0, 1 );

    layout32 = new QVBoxLayout( 0, 0, 6, "layout32"); 

    textLabel2_2 = new QLabel( groupBox1, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout32->addWidget( textLabel2_2 );

    QLEFechaUC = new QLineEdit( groupBox1, "QLEFechaUC" );
    QLEFechaUC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLEFechaUC->sizePolicy().hasHeightForWidth() ) );
    QLEFechaUC->setReadOnly( TRUE );
    layout32->addWidget( QLEFechaUC );

    groupBox1Layout->addLayout( layout32, 0, 2 );

    ComprasImportacionesLayout->addWidget( groupBox1, 1, 1 );

    groupBox3 = new QGroupBox( this, "groupBox3" );
    groupBox3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, groupBox3->sizePolicy().hasHeightForWidth() ) );
    groupBox3->setColumnLayout(0, Qt::Vertical );
    groupBox3->layout()->setSpacing( 6 );
    groupBox3->layout()->setMargin( 11 );
    groupBox3Layout = new QGridLayout( groupBox3->layout() );
    groupBox3Layout->setAlignment( Qt::AlignTop );

    layout32_2 = new QVBoxLayout( 0, 0, 6, "layout32_2"); 

    textLabel1_11 = new QLabel( groupBox3, "textLabel1_11" );
    layout32_2->addWidget( textLabel1_11 );

    QLEBodega = new QLineEdit( groupBox3, "QLEBodega" );
    QLEBodega->setReadOnly( TRUE );
    layout32_2->addWidget( QLEBodega );

    groupBox3Layout->addLayout( layout32_2, 0, 0 );

    ComprasImportacionesLayout->addWidget( groupBox3, 1, 2 );

    layout56 = new QVBoxLayout( 0, 0, 6, "layout56"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel1_5 = new QLabel( this, "textLabel1_5" );
    textLabel1_5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_5->sizePolicy().hasHeightForWidth() ) );
    layout21->addWidget( textLabel1_5 );

    QLCNPesoCompra = new QLCDNumber( this, "QLCNPesoCompra" );
    QLCNPesoCompra->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 0, 0, QLCNPesoCompra->sizePolicy().hasHeightForWidth() ) );
    QLCNPesoCompra->setMinimumSize( QSize( 240, 0 ) );
    QLCNPesoCompra->setMaximumSize( QSize( 240, 32767 ) );
    QLCNPesoCompra->setNumDigits( 10 );
    layout21->addWidget( QLCNPesoCompra );
    layout56->addLayout( layout21 );

    layout21_2 = new QVBoxLayout( 0, 0, 6, "layout21_2"); 

    textLabel1_5_2 = new QLabel( this, "textLabel1_5_2" );
    textLabel1_5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_5_2->sizePolicy().hasHeightForWidth() ) );
    layout21_2->addWidget( textLabel1_5_2 );

    QLCDNImporteFactura = new QLCDNumber( this, "QLCDNImporteFactura" );
    QLCDNImporteFactura->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 0, 0, QLCDNImporteFactura->sizePolicy().hasHeightForWidth() ) );
    QLCDNImporteFactura->setMinimumSize( QSize( 240, 0 ) );
    QLCDNImporteFactura->setMaximumSize( QSize( 240, 32767 ) );
    QLCDNImporteFactura->setNumDigits( 10 );
    layout21_2->addWidget( QLCDNImporteFactura );
    layout56->addLayout( layout21_2 );

    layout21_3 = new QVBoxLayout( 0, 0, 6, "layout21_3"); 

    textLabel1_5_3 = new QLabel( this, "textLabel1_5_3" );
    textLabel1_5_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_5_3->sizePolicy().hasHeightForWidth() ) );
    layout21_3->addWidget( textLabel1_5_3 );

    QLCNCostoGrEnvio = new QLCDNumber( this, "QLCNCostoGrEnvio" );
    QLCNCostoGrEnvio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)1, 0, 0, QLCNCostoGrEnvio->sizePolicy().hasHeightForWidth() ) );
    QLCNCostoGrEnvio->setMinimumSize( QSize( 240, 0 ) );
    QLCNCostoGrEnvio->setMaximumSize( QSize( 240, 32767 ) );
    QLCNCostoGrEnvio->setNumDigits( 10 );
    layout21_3->addWidget( QLCNCostoGrEnvio );
    layout56->addLayout( layout21_3 );

    ComprasImportacionesLayout->addMultiCellLayout( layout56, 0, 4, 3, 3 );

    layout32_3 = new QHBoxLayout( 0, 0, 6, "layout32_3"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    QPBAnexar->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPBAnexar->sizePolicy().hasHeightForWidth() ) );
    QPBAnexar->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBAnexar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setEnabled( FALSE );
    QPBEliminar->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBEliminar );

    QPBCargaCompraAProveedor = new QPushButton( this, "QPBCargaCompraAProveedor" );
    QPBCargaCompraAProveedor->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBCargaCompraAProveedor );

    QPBCargaCompra = new QPushButton( this, "QPBCargaCompra" );
    QPBCargaCompra->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBCargaCompra );

    QPBGuardaCompra = new QPushButton( this, "QPBGuardaCompra" );
    QPBGuardaCompra->setEnabled( FALSE );
    QPBGuardaCompra->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBGuardaCompra );

    QPBGuardaCompraComo = new QPushButton( this, "QPBGuardaCompraComo" );
    QPBGuardaCompraComo->setEnabled( FALSE );
    QPBGuardaCompraComo->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBGuardaCompraComo );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( TRUE );
    QPBActualizar->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBActualizar );

    QPBProveedores = new QPushButton( this, "QPBProveedores" );
    QPBProveedores->setEnabled( FALSE );
    QPBProveedores->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBProveedores );

    QPBOtroProveedor = new QPushButton( this, "QPBOtroProveedor" );
    QPBOtroProveedor->setEnabled( TRUE );
    QPBOtroProveedor->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBOtroProveedor );

    QPBRegParProductos = new QPushButton( this, "QPBRegParProductos" );
    QPBRegParProductos->setEnabled( TRUE );
    QPBRegParProductos->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBRegParProductos );

    QPBRegistraCompra = new QPushButton( this, "QPBRegistraCompra" );
    QPBRegistraCompra->setEnabled( FALSE );
    QPBRegistraCompra->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBRegistraCompra );

    QPBBodegas = new QPushButton( this, "QPBBodegas" );
    QPBBodegas->setEnabled( FALSE );
    QPBBodegas->setMinimumSize( QSize( 0, 30 ) );
    layout32_3->addWidget( QPBBodegas );

    ComprasImportacionesLayout->addMultiCellLayout( layout32_3, 4, 4, 0, 2 );
    languageChange();
    resize( QSize(1203, 632).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ComprasImportaciones::~ComprasImportaciones()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ComprasImportaciones::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_3->setText( tr( "Proveedores\n"
"Siscom" ) );
    textLabel1_6->setText( tr( "Factura" ) );
    textLabel1->setText( tr( "Costo\n"
"Envio" ) );
    textLabel1_2->setText( tr( "Cotizacion\n"
"Dolar" ) );
    textLabel1_2_2->setText( tr( "Costo\n"
"Administrativo" ) );
    textLabel1_2_2_2->setText( tr( "Numero\n"
"Partidas" ) );
    textLabel3->setText( tr( "Producto" ) );
    textLabel1_7->setText( tr( "Filtro\n"
"Productos" ) );
    textLabel1_4->setText( tr( "Cantidad" ) );
    textLabel1_4_2->setText( tr( "Costo\n"
"Unitario" ) );
    textLabel1_4_2_2->setText( tr( "Peso\n"
"Unitario" ) );
    textLabel1_4_3->setText( tr( "Costo Por\n"
"Gramo" ) );
    textLabel1_8->setText( tr( "Descripcion Compra" ) );
    textLabel2->setText( tr( "Importacion" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Proveedor" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Clave" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "C Prov" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Cant" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "Peso" ) );
    QTProductos->horizontalHeader()->setLabel( 5, tr( "P T" ) );
    QTProductos->horizontalHeader()->setLabel( 6, tr( "C Envio" ) );
    QTProductos->horizontalHeader()->setLabel( 7, tr( "C U $" ) );
    QTProductos->horizontalHeader()->setLabel( 8, tr( "P C Envio" ) );
    QTProductos->horizontalHeader()->setLabel( 9, tr( "C F Pesos" ) );
    QTProductos->horizontalHeader()->setLabel( 10, tr( "C Final" ) );
    QTProductos->horizontalHeader()->setLabel( 11, tr( "C Partida" ) );
    groupBox2->setTitle( tr( "Proveedor" ) );
    textLabel1_9->setText( tr( "Proveedor Seleccionado" ) );
    textLabel1_9_2->setText( tr( "Clave Proveedor" ) );
    groupBox1->setTitle( tr( "Ultima Compra" ) );
    textLabel1_10->setText( tr( "Cantidad" ) );
    textLabel1_10_2->setText( tr( "Costo" ) );
    textLabel2_2->setText( tr( "Fecha" ) );
    groupBox3->setTitle( tr( "Bodega Siscom" ) );
    textLabel1_11->setText( tr( "Bodega para almacenar material" ) );
    textLabel1_5->setText( tr( "Peso Compra" ) );
    textLabel1_5_2->setText( tr( "Importe Compra" ) );
    textLabel1_5_3->setText( tr( "Costo Por Gramo Envio" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBAnexar->setAccel( QKeySequence( QString::null ) );
    QPBEliminar->setText( tr( "Eliminar" ) );
    QPBEliminar->setAccel( QKeySequence( QString::null ) );
    QPBCargaCompraAProveedor->setText( tr( "Compra Archivo\n"
"Proveedor" ) );
    QPBCargaCompraAProveedor->setAccel( QKeySequence( QString::null ) );
    QPBCargaCompra->setText( tr( "Carga\n"
"Compra" ) );
    QPBCargaCompra->setAccel( QKeySequence( QString::null ) );
    QPBGuardaCompra->setText( tr( "Guardar\n"
"Compra" ) );
    QPBGuardaCompra->setAccel( QKeySequence( QString::null ) );
    QPBGuardaCompraComo->setText( tr( "Guardar\n"
"Como" ) );
    QPBGuardaCompraComo->setAccel( QKeySequence( QString::null ) );
    QPBActualizar->setText( tr( "&Actualizar\n"
"Producto" ) );
    QPBActualizar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QPBProveedores->setText( tr( "Proveedores en \n"
"la Compra" ) );
    QPBOtroProveedor->setText( tr( "Otro \n"
"Proveedor" ) );
    QPBRegParProductos->setText( tr( "Registro Parcial\n"
"Productos" ) );
    QPBRegistraCompra->setText( tr( "Registra \n"
"Compra" ) );
    QPBBodegas->setText( tr( "Bodega donde \n"
"Se almacenara" ) );
}

