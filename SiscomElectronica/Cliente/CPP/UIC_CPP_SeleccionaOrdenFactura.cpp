/****************************************************************************
** Form implementation generated from reading ui file 'UI/SeleccionaOrdenFactura.ui'
**
** Created: Wed Jan 31 10:48:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SeleccionaOrdenFactura.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <IMP_QControlFecha.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a SeleccionaOrdenFactura as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SeleccionaOrdenFactura::SeleccionaOrdenFactura( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SeleccionaOrdenFactura" );
    SeleccionaOrdenFacturaLayout = new QGridLayout( this, 1, 1, 11, 6, "SeleccionaOrdenFacturaLayout"); 

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout5->addWidget( textLabel3 );

    QLENoOrden = new QLineEdit( this, "QLENoOrden" );
    layout5->addWidget( QLENoOrden );
    layout7->addLayout( layout5 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel2 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    QCtrFechaInicio->setEnabled( FALSE );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrFechaInicio );
    layout7->addLayout( layout3 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( textLabel2_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setEnabled( FALSE );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( QCtrFechaFin );
    layout7->addLayout( layout3_2 );

    SeleccionaOrdenFacturaLayout->addLayout( layout7, 0, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel1 );

    QTOrdenes = new QTable( this, "QTOrdenes" );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "# Orden" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Fecha" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "Importe" ) );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "IdFactura" ) );
    QTOrdenes->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)3, 0, 0, QTOrdenes->sizePolicy().hasHeightForWidth() ) );
    QTOrdenes->setNumRows( 0 );
    QTOrdenes->setNumCols( 4 );
    QTOrdenes->setReadOnly( TRUE );
    layout2->addWidget( QTOrdenes );

    SeleccionaOrdenFacturaLayout->addLayout( layout2, 1, 0 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout2_2->addWidget( textLabel1_2 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Precio" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Importe" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 4 );
    QTProductos->setReadOnly( TRUE );
    layout2_2->addWidget( QTProductos );

    SeleccionaOrdenFacturaLayout->addLayout( layout2_2, 2, 0 );

    layout9 = new QGridLayout( 0, 1, 1, 0, 6, "layout9"); 

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );

    layout9->addWidget( QPBCancelar, 0, 3 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );

    layout9->addWidget( QPBAceptar, 0, 1 );

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    QPBConsultar->setAutoDefault( FALSE );

    layout9->addWidget( QPBConsultar, 0, 0 );

    QPBReEnviar = new QPushButton( this, "QPBReEnviar" );
    QPBReEnviar->setEnabled( FALSE );
    QPBReEnviar->setAutoDefault( FALSE );

    layout9->addWidget( QPBReEnviar, 0, 2 );

    SeleccionaOrdenFacturaLayout->addLayout( layout9, 3, 0 );
    languageChange();
    resize( QSize(575, 646).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SeleccionaOrdenFactura::~SeleccionaOrdenFactura()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SeleccionaOrdenFactura::languageChange()
{
    setCaption( tr( "Ordenes a Facturar" ) );
    textLabel3->setText( tr( "No Orden" ) );
    textLabel2->setText( tr( "Fecha Inicio" ) );
    textLabel2_2->setText( tr( "Fecha Fin" ) );
    textLabel1->setText( tr( "Ordenes" ) );
    QTOrdenes->horizontalHeader()->setLabel( 0, tr( "# Orden" ) );
    QTOrdenes->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTOrdenes->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    QTOrdenes->horizontalHeader()->setLabel( 3, tr( "IdFactura" ) );
    textLabel1_2->setText( tr( "Detalle Factura" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBConsultar->setText( tr( "Consultar" ) );
    QPBReEnviar->setText( tr( "Re Enviar Factura" ) );
}

