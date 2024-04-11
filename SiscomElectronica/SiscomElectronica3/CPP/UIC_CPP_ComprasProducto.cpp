/****************************************************************************
** Form implementation generated from reading ui file 'UI/ComprasProducto.ui'
**
** Created: Wed Jan 31 10:47:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ComprasProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlineedit.h>
#include <QCtrlProdSiscomElectronica.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProdSiscomElectronica.h"
#include "IMP_QControlFecha.h"

/*
 *  Constructs a ComprasProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ComprasProducto::ComprasProducto( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ComprasProducto" );
    ComprasProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "ComprasProductoLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBHCompras = new QPushButton( this, "QPBHCompras" );
    layout4->addWidget( QPBHCompras );

    QPBRPorcentajes = new QPushButton( this, "QPBRPorcentajes" );
    layout4->addWidget( QPBRPorcentajes );

    ComprasProductoLayout->addMultiCellLayout( layout4, 4, 4, 0, 4 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QTEDescripcion );

    ComprasProductoLayout->addMultiCellLayout( layout2, 3, 3, 0, 4 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout9->addWidget( textLabel3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha Registro" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Hora Registro" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio De Compra" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Factura" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio Venta" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Proveedor" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 8 );
    QTDatos->setReadOnly( TRUE );
    layout9->addWidget( QTDatos );

    ComprasProductoLayout->addMultiCellLayout( layout9, 2, 2, 0, 4 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout6->addWidget( textLabel4 );

    QLEComprasSemAnterior = new QLineEdit( this, "QLEComprasSemAnterior" );
    layout6->addWidget( QLEComprasSemAnterior );

    ComprasProductoLayout->addLayout( layout6, 1, 0 );

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout6_2->addWidget( textLabel4_2 );

    QTEVentasSemAnterior = new QLineEdit( this, "QTEVentasSemAnterior" );
    layout6_2->addWidget( QTEVentasSemAnterior );

    ComprasProductoLayout->addLayout( layout6_2, 1, 1 );

    layout6_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_2_2"); 

    textLabel4_2_2 = new QLabel( this, "textLabel4_2_2" );
    layout6_2_2->addWidget( textLabel4_2_2 );

    QLEVentasActuales = new QLineEdit( this, "QLEVentasActuales" );
    layout6_2_2->addWidget( QLEVentasActuales );

    ComprasProductoLayout->addMultiCellLayout( layout6_2_2, 1, 1, 2, 3 );

    layout6_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_2_2_2"); 

    textLabel4_2_2_2 = new QLabel( this, "textLabel4_2_2_2" );
    layout6_2_2_2->addWidget( textLabel4_2_2_2 );

    QLEExistenciaA = new QLineEdit( this, "QLEExistenciaA" );
    layout6_2_2_2->addWidget( QLEExistenciaA );

    ComprasProductoLayout->addLayout( layout6_2_2_2, 1, 4 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrSis3QtProds = new QCtrlProdSiscomElectronica( this, "QCtrSis3QtProds" );
    layout1->addWidget( QCtrSis3QtProds );

    ComprasProductoLayout->addMultiCellLayout( layout1, 0, 0, 0, 2 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout9_2 = new QVBoxLayout( 0, 0, 6, "layout9_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout9_2->addWidget( textLabel1_2 );

    QCtrFechaRefVentas = new CQControlFecha( this, "QCtrFechaRefVentas" );
    layout9_2->addWidget( QCtrFechaRefVentas );
    layout10->addLayout( layout9_2 );
    spacer1 = new QSpacerItem( 63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout10->addItem( spacer1 );

    ComprasProductoLayout->addMultiCellLayout( layout10, 0, 0, 3, 4 );
    languageChange();
    resize( QSize(609, 622).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ComprasProducto::~ComprasProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ComprasProducto::languageChange()
{
    setCaption( tr( "Historial De Compras del Producto" ) );
    QPBHCompras->setText( tr( "Historial De Compras" ) );
    QPBRPorcentajes->setText( tr( "Selecciona Productos % De Existencia" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    textLabel3->setText( tr( "Ultimas Compras" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Fecha Registro" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Hora Registro" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Precio De Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Factura" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Precio Venta" ) );
    QTDatos->horizontalHeader()->setLabel( 7, tr( "Proveedor" ) );
    textLabel4->setText( tr( "Compras Semestre\n"
" Anterior" ) );
    textLabel4_2->setText( tr( "Ventas Totales \n"
"Semestre Anterior" ) );
    textLabel4_2_2->setText( tr( "Cantidad Vendida\n"
" Actual" ) );
    textLabel4_2_2_2->setText( tr( "Existencia\n"
"Actual" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel1_2->setText( tr( "Fecha Referencia Ventas" ) );
}

