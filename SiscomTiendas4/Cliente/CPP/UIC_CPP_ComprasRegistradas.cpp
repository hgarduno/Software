/****************************************************************************
** Form implementation generated from reading ui file 'UI/ComprasRegistradas.ui'
**
** Created: Fri Apr 12 21:36:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ComprasRegistradas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a ComprasRegistradas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ComprasRegistradas::ComprasRegistradas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ComprasRegistradas" );
    ComprasRegistradasLayout = new QGridLayout( this, 1, 1, 11, 6, "ComprasRegistradasLayout"); 

    layout51 = new QHBoxLayout( 0, 0, 6, "layout51"); 

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( textLabel2 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    QCtrFechaIni->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaIni->sizePolicy().hasHeightForWidth() ) );
    layout48->addWidget( QCtrFechaIni );
    layout51->addLayout( layout48 );

    layout48_2 = new QVBoxLayout( 0, 0, 6, "layout48_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout48_2->addWidget( textLabel2_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout48_2->addWidget( QCtrFechaFin );
    layout51->addLayout( layout48_2 );

    layout50 = new QVBoxLayout( 0, 0, 6, "layout50"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout50->addWidget( textLabel2_3 );

    lineEdit4 = new QLineEdit( this, "lineEdit4" );
    layout50->addWidget( lineEdit4 );
    layout51->addLayout( layout50 );

    ComprasRegistradasLayout->addLayout( layout51, 0, 0 );

    layout52 = new QVBoxLayout( 0, 0, 6, "layout52"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout52->addWidget( textLabel3 );

    QTCompras = new QTable( this, "QTCompras" );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Fecha" ) );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "# Factura" ) );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Proveedor" ) );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Contacto" ) );
    QTCompras->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QTCompras->sizePolicy().hasHeightForWidth() ) );
    QTCompras->setNumRows( 0 );
    QTCompras->setNumCols( 4 );
    QTCompras->setReadOnly( TRUE );
    layout52->addWidget( QTCompras );

    ComprasRegistradasLayout->addLayout( layout52, 1, 0 );

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout44->addWidget( textLabel2_4 );

    QTDetalleCompra = new QTable( this, "QTDetalleCompra" );
    QTDetalleCompra->setNumCols( QTDetalleCompra->numCols() + 1 );
    QTDetalleCompra->horizontalHeader()->setLabel( QTDetalleCompra->numCols() - 1, tr( "Producto" ) );
    QTDetalleCompra->setNumCols( QTDetalleCompra->numCols() + 1 );
    QTDetalleCompra->horizontalHeader()->setLabel( QTDetalleCompra->numCols() - 1, tr( "Cantidad" ) );
    QTDetalleCompra->setNumCols( QTDetalleCompra->numCols() + 1 );
    QTDetalleCompra->horizontalHeader()->setLabel( QTDetalleCompra->numCols() - 1, tr( "Precio" ) );
    QTDetalleCompra->setNumCols( QTDetalleCompra->numCols() + 1 );
    QTDetalleCompra->horizontalHeader()->setLabel( QTDetalleCompra->numCols() - 1, tr( "Importe" ) );
    QTDetalleCompra->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QTDetalleCompra->sizePolicy().hasHeightForWidth() ) );
    QTDetalleCompra->setNumRows( 0 );
    QTDetalleCompra->setNumCols( 4 );
    QTDetalleCompra->setReadOnly( TRUE );
    layout44->addWidget( QTDetalleCompra );

    ComprasRegistradasLayout->addLayout( layout44, 2, 0 );

    layout73 = new QHBoxLayout( 0, 0, 6, "layout73"); 

    QPBEjecuta = new QPushButton( this, "QPBEjecuta" );
    layout73->addWidget( QPBEjecuta );

    QPBModificar = new QPushButton( this, "QPBModificar" );
    layout73->addWidget( QPBModificar );

    QPBEProducto = new QPushButton( this, "QPBEProducto" );
    layout73->addWidget( QPBEProducto );

    ComprasRegistradasLayout->addLayout( layout73, 3, 0 );
    languageChange();
    resize( QSize(515, 618).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ComprasRegistradas::~ComprasRegistradas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ComprasRegistradas::languageChange()
{
    setCaption( tr( "Compras Registradas" ) );
    textLabel2->setText( tr( "Fecha Inicio" ) );
    textLabel2_2->setText( tr( "Fecha Fin" ) );
    textLabel2_3->setText( tr( "# De Factura" ) );
    textLabel3->setText( tr( "Facturas" ) );
    QTCompras->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTCompras->horizontalHeader()->setLabel( 1, tr( "# Factura" ) );
    QTCompras->horizontalHeader()->setLabel( 2, tr( "Proveedor" ) );
    QTCompras->horizontalHeader()->setLabel( 3, tr( "Contacto" ) );
    textLabel2_4->setText( tr( "Detalle Orden" ) );
    QTDetalleCompra->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDetalleCompra->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDetalleCompra->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTDetalleCompra->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    QPBEjecuta->setText( tr( "Ejecuta Consulta" ) );
    QPBModificar->setText( tr( "Modificar Compra" ) );
    QPBEProducto->setText( tr( "Eliminar Producto" ) );
}

