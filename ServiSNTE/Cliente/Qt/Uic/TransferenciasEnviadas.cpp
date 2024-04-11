/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/TransferenciasEnviadas.ui'
**
** Created: Sat Jan 27 16:38:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "TransferenciasEnviadas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a TransferenciasEnviadas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
TransferenciasEnviadas::TransferenciasEnviadas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TransferenciasEnviadas" );
    TransferenciasEnviadasLayout = new QGridLayout( this, 1, 1, 11, 6, "TransferenciasEnviadasLayout"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLERangoFecha = new QLineEdit( this, "QLERangoFecha" );
    layout1->addWidget( QLERangoFecha );
    layout3->addLayout( layout1 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3->addItem( spacer1 );

    TransferenciasEnviadasLayout->addMultiCellLayout( layout3, 0, 0, 0, 1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QTTransferencias = new QTable( this, "QTTransferencias" );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Fecha" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Estado" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Tienda" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Almacenista" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Chofer" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Camion" ) );
    QTTransferencias->setNumRows( 0 );
    QTTransferencias->setNumCols( 6 );
    layout2->addWidget( QTTransferencias );

    TransferenciasEnviadasLayout->addMultiCellLayout( layout2, 1, 1, 0, 1 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout2_2->addWidget( textLabel2_2 );

    QTDetalleTransferencia = new QTable( this, "QTDetalleTransferencia" );
    QTDetalleTransferencia->setNumCols( QTDetalleTransferencia->numCols() + 1 );
    QTDetalleTransferencia->horizontalHeader()->setLabel( QTDetalleTransferencia->numCols() - 1, tr( "Cantidad" ) );
    QTDetalleTransferencia->setNumCols( QTDetalleTransferencia->numCols() + 1 );
    QTDetalleTransferencia->horizontalHeader()->setLabel( QTDetalleTransferencia->numCols() - 1, tr( "Modelo" ) );
    QTDetalleTransferencia->setNumCols( QTDetalleTransferencia->numCols() + 1 );
    QTDetalleTransferencia->horizontalHeader()->setLabel( QTDetalleTransferencia->numCols() - 1, tr( "Producto" ) );
    QTDetalleTransferencia->setNumCols( QTDetalleTransferencia->numCols() + 1 );
    QTDetalleTransferencia->horizontalHeader()->setLabel( QTDetalleTransferencia->numCols() - 1, tr( "#Producto" ) );
    QTDetalleTransferencia->setNumCols( QTDetalleTransferencia->numCols() + 1 );
    QTDetalleTransferencia->horizontalHeader()->setLabel( QTDetalleTransferencia->numCols() - 1, tr( "Proveedor" ) );
    QTDetalleTransferencia->setNumRows( 0 );
    QTDetalleTransferencia->setNumCols( 5 );
    layout2_2->addWidget( QTDetalleTransferencia );

    TransferenciasEnviadasLayout->addMultiCellLayout( layout2_2, 2, 2, 0, 1 );

    QPBConsultar = new QPushButton( this, "QPBConsultar" );

    TransferenciasEnviadasLayout->addWidget( QPBConsultar, 3, 0 );

    QPBCopiar = new QPushButton( this, "QPBCopiar" );

    TransferenciasEnviadasLayout->addWidget( QPBCopiar, 3, 1 );
    languageChange();
    resize( QSize(677, 548).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
TransferenciasEnviadas::~TransferenciasEnviadas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TransferenciasEnviadas::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Rango Fechas" ) );
    QLERangoFecha->setInputMask( tr( "####-##-## ####-##-##; " ) );
    textLabel2->setText( tr( "Transferencias Enviadas" ) );
    QTTransferencias->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTTransferencias->horizontalHeader()->setLabel( 1, tr( "Estado" ) );
    QTTransferencias->horizontalHeader()->setLabel( 2, tr( "Tienda" ) );
    QTTransferencias->horizontalHeader()->setLabel( 3, tr( "Almacenista" ) );
    QTTransferencias->horizontalHeader()->setLabel( 4, tr( "Chofer" ) );
    QTTransferencias->horizontalHeader()->setLabel( 5, tr( "Camion" ) );
    textLabel2_2->setText( tr( "Detalle de la Transferencia" ) );
    QTDetalleTransferencia->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTDetalleTransferencia->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTDetalleTransferencia->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
    QTDetalleTransferencia->horizontalHeader()->setLabel( 3, tr( "#Producto" ) );
    QTDetalleTransferencia->horizontalHeader()->setLabel( 4, tr( "Proveedor" ) );
    QPBConsultar->setText( tr( "Consultar" ) );
    QPBCopiar->setText( tr( "Copiar" ) );
}

