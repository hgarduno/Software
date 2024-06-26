/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/PuntoDeVenta.ui'
**
** Created: Thu Apr 11 21:07:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "PuntoDeVenta.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTipoVentas.h"
#include "QCtrlFinanciadoras.h"
#include "QCtrlPlazos.h"
#include "QCtrlVendedores.h"
#include "QCtrlFormasEntrega.h"
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a PuntoDeVenta as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PuntoDeVenta::PuntoDeVenta( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PuntoDeVenta" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, sizePolicy().hasHeightForWidth() ) );
    PuntoDeVentaLayout = new QGridLayout( this, 1, 1, 11, 6, "PuntoDeVentaLayout"); 

    layout52 = new QHBoxLayout( 0, 0, 6, "layout52"); 

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout33->addWidget( textLabel1_3 );

    QCtrTipoVenta = new QCtrlTipoVentas( this, "QCtrTipoVenta" );
    QCtrTipoVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrTipoVenta->sizePolicy().hasHeightForWidth() ) );
    layout33->addWidget( QCtrTipoVenta );
    layout52->addLayout( layout33 );

    layout34 = new QVBoxLayout( 0, 0, 6, "layout34"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout34->addWidget( textLabel2_2 );

    QCtrFinanciadora = new QCtrlFinanciadoras( this, "QCtrFinanciadora" );
    QCtrFinanciadora->setEnabled( FALSE );
    QCtrFinanciadora->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrFinanciadora->sizePolicy().hasHeightForWidth() ) );
    layout34->addWidget( QCtrFinanciadora );
    layout52->addLayout( layout34 );

    layout33_2 = new QVBoxLayout( 0, 0, 6, "layout33_2"); 

    textLabel1_6 = new QLabel( this, "textLabel1_6" );
    layout33_2->addWidget( textLabel1_6 );

    QCtrPlazos = new QCtrlPlazos( this, "QCtrPlazos" );
    QCtrPlazos->setEnabled( FALSE );
    layout33_2->addWidget( QCtrPlazos );
    layout52->addLayout( layout33_2 );

    layout39 = new QVBoxLayout( 0, 0, 6, "layout39"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout39->addWidget( textLabel3 );

    QCtrVendedores = new QCtrlVendedores( this, "QCtrVendedores" );
    QCtrVendedores->setEnabled( FALSE );
    layout39->addWidget( QCtrVendedores );
    layout52->addLayout( layout39 );

    layout62 = new QVBoxLayout( 0, 0, 6, "layout62"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout62->addWidget( textLabel4 );

    QLEFolio = new QLineEdit( this, "QLEFolio" );
    QLEFolio->setEnabled( FALSE );
    QLEFolio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFolio->sizePolicy().hasHeightForWidth() ) );
    QLEFolio->setReadOnly( TRUE );
    layout62->addWidget( QLEFolio );
    layout52->addLayout( layout62 );

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout36->addWidget( textLabel5 );

    QLEFecha = new QLineEdit( this, "QLEFecha" );
    QLEFecha->setEnabled( FALSE );
    QLEFecha->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFecha->sizePolicy().hasHeightForWidth() ) );
    QLEFecha->setReadOnly( TRUE );
    layout36->addWidget( QLEFecha );
    layout52->addLayout( layout36 );

    PuntoDeVentaLayout->addMultiCellLayout( layout52, 0, 0, 0, 7 );

    layout50 = new QHBoxLayout( 0, 0, 6, "layout50"); 

    layout50_2 = new QHBoxLayout( 0, 0, 0, "layout50_2"); 

    textLabel10 = new QLabel( this, "textLabel10" );
    textLabel10->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel10->sizePolicy().hasHeightForWidth() ) );
    layout50_2->addWidget( textLabel10 );

    QLECliente = new QLineEdit( this, "QLECliente" );
    QLECliente->setEnabled( TRUE );
    QLECliente->setReadOnly( TRUE );
    layout50_2->addWidget( QLECliente );

    QPBCapturaCliente = new QPushButton( this, "QPBCapturaCliente" );
    QPBCapturaCliente->setEnabled( FALSE );
    QPBCapturaCliente->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPBCapturaCliente->sizePolicy().hasHeightForWidth() ) );
    layout50_2->addWidget( QPBCapturaCliente );
    layout50->addLayout( layout50_2 );

    layout49 = new QHBoxLayout( 0, 0, 0, "layout49"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    textLabel6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6_2->sizePolicy().hasHeightForWidth() ) );
    layout49->addWidget( textLabel6_2 );

    QLEDireccion = new QLineEdit( this, "QLEDireccion" );
    QLEDireccion->setEnabled( TRUE );
    QLEDireccion->setReadOnly( TRUE );
    layout49->addWidget( QLEDireccion );

    QPBCapturaDireccion = new QPushButton( this, "QPBCapturaDireccion" );
    QPBCapturaDireccion->setEnabled( FALSE );
    QPBCapturaDireccion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QPBCapturaDireccion->sizePolicy().hasHeightForWidth() ) );
    layout49->addWidget( QPBCapturaDireccion );
    layout50->addLayout( layout49 );

    PuntoDeVentaLayout->addMultiCellLayout( layout50, 1, 1, 0, 7 );

    layout46 = new QVBoxLayout( 0, 0, 6, "layout46"); 

    layout44 = new QHBoxLayout( 0, 0, 6, "layout44"); 

    QTDetalleFactura = new QTable( this, "QTDetalleFactura" );
    QTDetalleFactura->setNumCols( QTDetalleFactura->numCols() + 1 );
    QTDetalleFactura->horizontalHeader()->setLabel( QTDetalleFactura->numCols() - 1, tr( "#Producto" ) );
    QTDetalleFactura->setNumCols( QTDetalleFactura->numCols() + 1 );
    QTDetalleFactura->horizontalHeader()->setLabel( QTDetalleFactura->numCols() - 1, tr( "Modelo" ) );
    QTDetalleFactura->setNumCols( QTDetalleFactura->numCols() + 1 );
    QTDetalleFactura->horizontalHeader()->setLabel( QTDetalleFactura->numCols() - 1, tr( "Producto" ) );
    QTDetalleFactura->setNumCols( QTDetalleFactura->numCols() + 1 );
    QTDetalleFactura->horizontalHeader()->setLabel( QTDetalleFactura->numCols() - 1, tr( "Cantidad" ) );
    QTDetalleFactura->setNumCols( QTDetalleFactura->numCols() + 1 );
    QTDetalleFactura->horizontalHeader()->setLabel( QTDetalleFactura->numCols() - 1, tr( "Precio Unitario" ) );
    QTDetalleFactura->setNumCols( QTDetalleFactura->numCols() + 1 );
    QTDetalleFactura->horizontalHeader()->setLabel( QTDetalleFactura->numCols() - 1, tr( "Importe" ) );
    QTDetalleFactura->setEnabled( TRUE );
    QTDetalleFactura->setNumRows( 0 );
    QTDetalleFactura->setNumCols( 6 );
    QTDetalleFactura->setReadOnly( TRUE );
    layout44->addWidget( QTDetalleFactura );

    layout38 = new QVBoxLayout( 0, 0, 6, "layout38"); 

    layout36_2 = new QVBoxLayout( 0, 0, 6, "layout36_2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout36_2->addWidget( textLabel1 );

    QLCDImporte = new QLCDNumber( this, "QLCDImporte" );
    QLCDImporte->setEnabled( TRUE );
    QLCDImporte->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, QLCDImporte->sizePolicy().hasHeightForWidth() ) );
    QLCDImporte->setNumDigits( 8 );
    layout36_2->addWidget( QLCDImporte );
    layout38->addLayout( layout36_2 );

    layout37 = new QVBoxLayout( 0, 0, 6, "layout37"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout37->addWidget( textLabel2_3 );

    QLCDExistencia = new QLCDNumber( this, "QLCDExistencia" );
    QLCDExistencia->setEnabled( TRUE );
    QLCDExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, QLCDExistencia->sizePolicy().hasHeightForWidth() ) );
    QLCDExistencia->setNumDigits( 8 );
    layout37->addWidget( QLCDExistencia );
    layout38->addLayout( layout37 );
    layout44->addLayout( layout38 );
    layout46->addLayout( layout44 );

    QTEInfoCredito = new QTextEdit( this, "QTEInfoCredito" );
    QTEInfoCredito->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QTEInfoCredito->sizePolicy().hasHeightForWidth() ) );
    QTEInfoCredito->setMinimumSize( QSize( 0, 54 ) );
    QTEInfoCredito->setMaximumSize( QSize( 32767, 54 ) );
    QTEInfoCredito->setReadOnly( TRUE );
    layout46->addWidget( QTEInfoCredito );

    PuntoDeVentaLayout->addMultiCellLayout( layout46, 5, 5, 0, 7 );

    layout33_3 = new QHBoxLayout( 0, 0, 6, "layout33_3"); 

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    textLabel1_5 = new QLabel( this, "textLabel1_5" );
    layout31->addWidget( textLabel1_5 );

    QLEDescripcionProducto = new QLineEdit( this, "QLEDescripcionProducto" );
    QLEDescripcionProducto->setEnabled( TRUE );
    QLEDescripcionProducto->setReadOnly( TRUE );
    layout31->addWidget( QLEDescripcionProducto );
    layout33_3->addLayout( layout31 );

    layout39_2 = new QHBoxLayout( 0, 0, 6, "layout39_2"); 

    layout84 = new QVBoxLayout( 0, 0, 6, "layout84"); 

    textLabel13 = new QLabel( this, "textLabel13" );
    textLabel13->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, textLabel13->sizePolicy().hasHeightForWidth() ) );
    layout84->addWidget( textLabel13 );

    QLEModelo = new QLineEdit( this, "QLEModelo" );
    QLEModelo->setEnabled( TRUE );
    QLEModelo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEModelo->sizePolicy().hasHeightForWidth() ) );
    QLEModelo->setReadOnly( TRUE );
    layout84->addWidget( QLEModelo );
    layout39_2->addLayout( layout84 );

    layout85 = new QVBoxLayout( 0, 0, 6, "layout85"); 

    textLabel14 = new QLabel( this, "textLabel14" );
    textLabel14->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, textLabel14->sizePolicy().hasHeightForWidth() ) );
    layout85->addWidget( textLabel14 );

    QLESerie = new QLineEdit( this, "QLESerie" );
    QLESerie->setEnabled( TRUE );
    QLESerie->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLESerie->sizePolicy().hasHeightForWidth() ) );
    QLESerie->setReadOnly( FALSE );
    layout85->addWidget( QLESerie );
    layout39_2->addLayout( layout85 );

    layout175 = new QVBoxLayout( 0, 0, 6, "layout175"); 

    textLabel16 = new QLabel( this, "textLabel16" );
    textLabel16->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)4, 0, 0, textLabel16->sizePolicy().hasHeightForWidth() ) );
    layout175->addWidget( textLabel16 );

    QLEPrecioVenta = new QLineEdit( this, "QLEPrecioVenta" );
    QLEPrecioVenta->setEnabled( FALSE );
    QLEPrecioVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)4, 0, 0, QLEPrecioVenta->sizePolicy().hasHeightForWidth() ) );
    layout175->addWidget( QLEPrecioVenta );
    layout39_2->addLayout( layout175 );
    layout33_3->addLayout( layout39_2 );

    PuntoDeVentaLayout->addMultiCellLayout( layout33_3, 4, 4, 0, 7 );

    layout37_2 = new QHBoxLayout( 0, 0, 6, "layout37_2"); 

    layout37_3 = new QVBoxLayout( 0, 0, 6, "layout37_3"); 

    textLabel7 = new QLabel( this, "textLabel7" );
    textLabel7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)4, 0, 0, textLabel7->sizePolicy().hasHeightForWidth() ) );
    layout37_3->addWidget( textLabel7 );

    QTEInstrucionesEntrega = new QTextEdit( this, "QTEInstrucionesEntrega" );
    QTEInstrucionesEntrega->setEnabled( FALSE );
    QTEInstrucionesEntrega->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, QTEInstrucionesEntrega->sizePolicy().hasHeightForWidth() ) );
    layout37_3->addWidget( QTEInstrucionesEntrega );
    layout37_2->addLayout( layout37_3 );

    layout36_3 = new QVBoxLayout( 0, 0, 6, "layout36_3"); 

    layout37_4 = new QHBoxLayout( 0, 0, 6, "layout37_4"); 

    textLabel8 = new QLabel( this, "textLabel8" );
    textLabel8->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel8->sizePolicy().hasHeightForWidth() ) );
    layout37_4->addWidget( textLabel8 );

    QLCDSuma = new QLCDNumber( this, "QLCDSuma" );
    QLCDSuma->setEnabled( TRUE );
    QLCDSuma->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, QLCDSuma->sizePolicy().hasHeightForWidth() ) );
    QLCDSuma->setNumDigits( 8 );
    layout37_4->addWidget( QLCDSuma );
    layout36_3->addLayout( layout37_4 );

    layout38_3 = new QHBoxLayout( 0, 0, 6, "layout38_3"); 

    textLabel9 = new QLabel( this, "textLabel9" );
    textLabel9->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel9->sizePolicy().hasHeightForWidth() ) );
    layout38_3->addWidget( textLabel9 );

    QLCDIva = new QLCDNumber( this, "QLCDIva" );
    QLCDIva->setEnabled( TRUE );
    QLCDIva->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, QLCDIva->sizePolicy().hasHeightForWidth() ) );
    QLCDIva->setNumDigits( 8 );
    layout38_3->addWidget( QLCDIva );
    layout36_3->addLayout( layout38_3 );

    layout49_2 = new QHBoxLayout( 0, 0, 6, "layout49_2"); 

    textLabel10_2 = new QLabel( this, "textLabel10_2" );
    textLabel10_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel10_2->sizePolicy().hasHeightForWidth() ) );
    layout49_2->addWidget( textLabel10_2 );

    QLCDTotal = new QLCDNumber( this, "QLCDTotal" );
    QLCDTotal->setEnabled( TRUE );
    QLCDTotal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, QLCDTotal->sizePolicy().hasHeightForWidth() ) );
    QLCDTotal->setMaximumSize( QSize( 32767, 32767 ) );
    QLCDTotal->setNumDigits( 8 );
    QLCDTotal->setSegmentStyle( QLCDNumber::Outline );
    layout49_2->addWidget( QLCDTotal );
    layout36_3->addLayout( layout49_2 );
    layout37_2->addLayout( layout36_3 );

    PuntoDeVentaLayout->addMultiCellLayout( layout37_2, 6, 6, 0, 7 );

    layout52_2 = new QHBoxLayout( 0, 0, 6, "layout52_2"); 

    layout50_3 = new QVBoxLayout( 0, 0, 6, "layout50_3"); 

    textLabel1_7 = new QLabel( this, "textLabel1_7" );
    textLabel1_7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_7->sizePolicy().hasHeightForWidth() ) );
    layout50_3->addWidget( textLabel1_7 );

    QLETelefono = new QLineEdit( this, "QLETelefono" );
    QLETelefono->setEnabled( FALSE );
    QLETelefono->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)1, 0, 0, QLETelefono->sizePolicy().hasHeightForWidth() ) );
    layout50_3->addWidget( QLETelefono );
    layout52_2->addLayout( layout50_3 );

    layout51 = new QVBoxLayout( 0, 0, 6, "layout51"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout51->addWidget( textLabel1_4 );

    QCtrFormaEntrega = new QCtrlFormasEntrega( this, "QCtrFormaEntrega" );
    QCtrFormaEntrega->setEnabled( FALSE );
    QCtrFormaEntrega->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrFormaEntrega->sizePolicy().hasHeightForWidth() ) );
    layout51->addWidget( QCtrFormaEntrega );
    layout52_2->addLayout( layout51 );

    PuntoDeVentaLayout->addMultiCellLayout( layout52_2, 2, 2, 0, 7 );

    layout57 = new QHBoxLayout( 0, 0, 6, "layout57"); 

    layout55 = new QHBoxLayout( 0, 0, 6, "layout55"); 

    layout47 = new QVBoxLayout( 0, 0, 6, "layout47"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout47->addWidget( textLabel1_2_2 );

    QLECantidadCotiza = new QLineEdit( this, "QLECantidadCotiza" );
    QLECantidadCotiza->setEnabled( FALSE );
    QLECantidadCotiza->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidadCotiza->sizePolicy().hasHeightForWidth() ) );
    layout47->addWidget( QLECantidadCotiza );
    layout55->addLayout( layout47 );

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( textLabel1_2 );

    QLECodigoBarras = new QLineEdit( this, "QLECodigoBarras" );
    QLECodigoBarras->setEnabled( FALSE );
    QLECodigoBarras->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLECodigoBarras->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( QLECodigoBarras );
    layout55->addLayout( layout48 );

    layout49_3 = new QVBoxLayout( 0, 0, 6, "layout49_3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout49_3->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    QCtrProveedores->setEnabled( FALSE );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    layout49_3->addWidget( QCtrProveedores );
    layout55->addLayout( layout49_3 );

    layout48_2 = new QVBoxLayout( 0, 0, 6, "layout48_2"); 

    textLabel1_2_3 = new QLabel( this, "textLabel1_2_3" );
    textLabel1_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_3->sizePolicy().hasHeightForWidth() ) );
    layout48_2->addWidget( textLabel1_2_3 );

    QLENumeroProducto = new QLineEdit( this, "QLENumeroProducto" );
    QLENumeroProducto->setEnabled( FALSE );
    QLENumeroProducto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLENumeroProducto->sizePolicy().hasHeightForWidth() ) );
    layout48_2->addWidget( QLENumeroProducto );
    layout55->addLayout( layout48_2 );
    layout57->addLayout( layout55 );

    QPBProductosProveedor = new QPushButton( this, "QPBProductosProveedor" );
    QPBProductosProveedor->setEnabled( FALSE );
    QPBProductosProveedor->setMinimumSize( QSize( 0, 38 ) );
    layout57->addWidget( QPBProductosProveedor );

    PuntoDeVentaLayout->addMultiCellLayout( layout57, 3, 3, 0, 7 );

    QPRegistrarVenta = new QPushButton( this, "QPRegistrarVenta" );
    QPRegistrarVenta->setEnabled( FALSE );
    QPRegistrarVenta->setMinimumSize( QSize( 0, 30 ) );

    PuntoDeVentaLayout->addWidget( QPRegistrarVenta, 7, 0 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );
    QPBImprimir->setMinimumSize( QSize( 0, 30 ) );

    PuntoDeVentaLayout->addWidget( QPBImprimir, 7, 1 );

    QPBNuevaVenta = new QPushButton( this, "QPBNuevaVenta" );
    QPBNuevaVenta->setEnabled( FALSE );
    QPBNuevaVenta->setMinimumSize( QSize( 0, 30 ) );

    PuntoDeVentaLayout->addWidget( QPBNuevaVenta, 7, 2 );

    QPBAgregar = new QPushButton( this, "QPBAgregar" );
    QPBAgregar->setEnabled( FALSE );
    QPBAgregar->setMinimumSize( QSize( 0, 30 ) );

    PuntoDeVentaLayout->addWidget( QPBAgregar, 7, 3 );

    QPBCambiarPrecio = new QPushButton( this, "QPBCambiarPrecio" );
    QPBCambiarPrecio->setEnabled( FALSE );
    QPBCambiarPrecio->setMinimumSize( QSize( 0, 30 ) );

    PuntoDeVentaLayout->addWidget( QPBCambiarPrecio, 7, 4 );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setEnabled( FALSE );
    QPBEliminar->setMinimumSize( QSize( 0, 30 ) );

    PuntoDeVentaLayout->addWidget( QPBEliminar, 7, 5 );

    QPBCancelarVenta = new QPushButton( this, "QPBCancelarVenta" );
    QPBCancelarVenta->setEnabled( FALSE );
    QPBCancelarVenta->setMinimumSize( QSize( 0, 30 ) );

    PuntoDeVentaLayout->addWidget( QPBCancelarVenta, 7, 6 );

    layout66 = new QVBoxLayout( 0, 0, 0, "layout66"); 

    QPBCodigoBarras = new QPushButton( this, "QPBCodigoBarras" );
    QPBCodigoBarras->setMaximumSize( QSize( 32767, 15 ) );
    layout66->addWidget( QPBCodigoBarras );

    QPBClaveProveedor = new QPushButton( this, "QPBClaveProveedor" );
    QPBClaveProveedor->setMaximumSize( QSize( 32767, 15 ) );
    layout66->addWidget( QPBClaveProveedor );

    PuntoDeVentaLayout->addLayout( layout66, 7, 7 );
    languageChange();
    resize( QSize(1101, 664).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PuntoDeVenta::~PuntoDeVenta()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PuntoDeVenta::languageChange()
{
    setCaption( tr( "Manejador de Ventas" ) );
    textLabel1_3->setText( tr( "Tipo Venta:" ) );
    textLabel2_2->setText( tr( "Financiadora:" ) );
    textLabel1_6->setText( tr( "Plazos:" ) );
    textLabel3->setText( tr( "Vendedor:" ) );
    textLabel4->setText( tr( "Folio:" ) );
    textLabel5->setText( tr( "Fecha:" ) );
    textLabel10->setText( tr( "Cliente:" ) );
    QPBCapturaCliente->setText( tr( "Cliente" ) );
    textLabel6_2->setText( tr( "Direccion:" ) );
    QPBCapturaDireccion->setText( tr( "Direccion" ) );
    QTDetalleFactura->horizontalHeader()->setLabel( 0, tr( "#Producto" ) );
    QTDetalleFactura->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTDetalleFactura->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
    QTDetalleFactura->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTDetalleFactura->horizontalHeader()->setLabel( 4, tr( "Precio Unitario" ) );
    QTDetalleFactura->horizontalHeader()->setLabel( 5, tr( "Importe" ) );
    textLabel1->setText( tr( "Importe" ) );
    textLabel2_3->setText( tr( "Existencia" ) );
    textLabel1_5->setText( trUtf8( "\x44\x65\x73\x63\x72\x69\x70\x63\x69\xc3\xb3\x6e\x20\x64\x65\x6c\x20\x50\x72\x6f\x64"
    "\x75\x63\x74\x6f\x3a" ) );
    textLabel13->setText( tr( "Modelo:" ) );
    textLabel14->setText( tr( "Serie:" ) );
    textLabel16->setText( tr( "Precio Venta:" ) );
    textLabel7->setText( tr( "Instrucciones de Entrega:" ) );
    textLabel8->setText( tr( "Suma:" ) );
    textLabel9->setText( tr( "I.V.A.:" ) );
    textLabel10_2->setText( tr( "Total:" ) );
    textLabel1_7->setText( tr( "Numero Telefonico" ) );
    QLETelefono->setInputMask( tr( "#############; " ) );
    textLabel1_4->setText( tr( "Formas Entrega:" ) );
    textLabel1_2_2->setText( tr( "Cantidad" ) );
    QLECantidadCotiza->setText( tr( "1" ) );
    textLabel1_2->setText( trUtf8( "\x43\xc3\xb3\x64\x69\x67\x6f\x20\x64\x65\x20\x42\x61\x72\x72\x61\x73\x20\x64\x65\x20"
    "\x50\x72\x6f\x64\x75\x63\x74\x6f" ) );
    textLabel2->setText( tr( "Clave Proveedor" ) );
    textLabel1_2_3->setText( tr( "Numero Producto" ) );
    QLENumeroProducto->setInputMask( tr( "###; " ) );
    QPBProductosProveedor->setText( tr( "Productos del Proveedor" ) );
    QPRegistrarVenta->setText( tr( "Registrar Venta" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBNuevaVenta->setText( tr( "Nueva Venta" ) );
    QPBAgregar->setText( tr( "Agrega Producto" ) );
    QPBCambiarPrecio->setText( tr( "Cambiar Precio" ) );
    QPBEliminar->setText( tr( "Elimina Producto" ) );
    QPBCancelarVenta->setText( tr( "Cancelar Factura" ) );
    QPBCodigoBarras->setText( tr( "Por Codigo Barras" ) );
    QPBClaveProveedor->setText( tr( "Por Clave Proveedor" ) );
}

