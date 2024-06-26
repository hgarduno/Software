/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ReporteCompras.ui'
**
** Created: Thu Apr 11 21:07:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ReporteCompras.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ReporteCompras as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ReporteCompras::ReporteCompras( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ReporteCompras" );
    ReporteComprasLayout = new QGridLayout( this, 1, 1, 11, 6, "ReporteComprasLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QLERangoFechas = new QLineEdit( this, "QLERangoFechas" );
    layout1->addWidget( QLERangoFechas );

    ReporteComprasLayout->addLayout( layout1, 0, 0 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout41->addWidget( textLabel2 );

    QTCompras = new QTable( this, "QTCompras" );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Proveedor" ) );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Concepto Existencia" ) );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Tipo Documento" ) );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Serie Factura" ) );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Fecha" ) );
    QTCompras->setNumCols( QTCompras->numCols() + 1 );
    QTCompras->horizontalHeader()->setLabel( QTCompras->numCols() - 1, tr( "Folio" ) );
    QTCompras->setNumRows( 0 );
    QTCompras->setNumCols( 6 );
    layout41->addWidget( QTCompras );

    ReporteComprasLayout->addMultiCellLayout( layout41, 1, 1, 0, 1 );

    layout44 = new QHBoxLayout( 0, 0, 6, "layout44"); 

    pushButton15 = new QPushButton( this, "pushButton15" );
    layout44->addWidget( pushButton15 );

    pushButton15_2 = new QPushButton( this, "pushButton15_2" );
    layout44->addWidget( pushButton15_2 );

    ReporteComprasLayout->addMultiCellLayout( layout44, 3, 3, 0, 1 );

    layout49 = new QHBoxLayout( 0, 0, 6, "layout49"); 

    layout41_2 = new QVBoxLayout( 0, 0, 6, "layout41_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout41_2->addWidget( textLabel2_2 );

    QTDetalleCompras = new QTable( this, "QTDetalleCompras" );
    QTDetalleCompras->setNumCols( QTDetalleCompras->numCols() + 1 );
    QTDetalleCompras->horizontalHeader()->setLabel( QTDetalleCompras->numCols() - 1, tr( "Producto" ) );
    QTDetalleCompras->setNumCols( QTDetalleCompras->numCols() + 1 );
    QTDetalleCompras->horizontalHeader()->setLabel( QTDetalleCompras->numCols() - 1, tr( "Modelo" ) );
    QTDetalleCompras->setNumCols( QTDetalleCompras->numCols() + 1 );
    QTDetalleCompras->horizontalHeader()->setLabel( QTDetalleCompras->numCols() - 1, tr( "Serie" ) );
    QTDetalleCompras->setNumCols( QTDetalleCompras->numCols() + 1 );
    QTDetalleCompras->horizontalHeader()->setLabel( QTDetalleCompras->numCols() - 1, tr( "Cantidad" ) );
    QTDetalleCompras->setNumCols( QTDetalleCompras->numCols() + 1 );
    QTDetalleCompras->horizontalHeader()->setLabel( QTDetalleCompras->numCols() - 1, tr( "Precio" ) );
    QTDetalleCompras->setNumCols( QTDetalleCompras->numCols() + 1 );
    QTDetalleCompras->horizontalHeader()->setLabel( QTDetalleCompras->numCols() - 1, tr( "Iva" ) );
    QTDetalleCompras->setNumCols( QTDetalleCompras->numCols() + 1 );
    QTDetalleCompras->horizontalHeader()->setLabel( QTDetalleCompras->numCols() - 1, tr( "Total" ) );
    QTDetalleCompras->setEnabled( TRUE );
    QTDetalleCompras->setNumRows( 0 );
    QTDetalleCompras->setNumCols( 7 );
    layout41_2->addWidget( QTDetalleCompras );
    layout49->addLayout( layout41_2 );

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    layout45 = new QVBoxLayout( 0, 0, 6, "layout45"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout45->addWidget( textLabel3 );

    lCDNumber5 = new QLCDNumber( this, "lCDNumber5" );
    lCDNumber5->setSmallDecimalPoint( TRUE );
    lCDNumber5->setNumDigits( 6 );
    lCDNumber5->setMode( QLCDNumber::Dec );
    layout45->addWidget( lCDNumber5 );
    layout48->addLayout( layout45 );

    layout45_2 = new QVBoxLayout( 0, 0, 6, "layout45_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout45_2->addWidget( textLabel3_2 );

    lCDNumber5_2 = new QLCDNumber( this, "lCDNumber5_2" );
    lCDNumber5_2->setSmallDecimalPoint( TRUE );
    lCDNumber5_2->setNumDigits( 6 );
    lCDNumber5_2->setMode( QLCDNumber::Dec );
    layout45_2->addWidget( lCDNumber5_2 );
    layout48->addLayout( layout45_2 );

    layout45_2_2 = new QVBoxLayout( 0, 0, 6, "layout45_2_2"); 

    textLabel3_2_2 = new QLabel( this, "textLabel3_2_2" );
    layout45_2_2->addWidget( textLabel3_2_2 );

    lCDNumber5_2_2 = new QLCDNumber( this, "lCDNumber5_2_2" );
    lCDNumber5_2_2->setSmallDecimalPoint( TRUE );
    lCDNumber5_2_2->setNumDigits( 6 );
    lCDNumber5_2_2->setMode( QLCDNumber::Dec );
    layout45_2_2->addWidget( lCDNumber5_2_2 );
    layout48->addLayout( layout45_2_2 );
    layout49->addLayout( layout48 );

    ReporteComprasLayout->addMultiCellLayout( layout49, 2, 2, 0, 1 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ReporteComprasLayout->addItem( spacer2, 0, 1 );
    languageChange();
    resize( QSize(830, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReporteCompras::~ReporteCompras()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReporteCompras::languageChange()
{
    setCaption( tr( "Reporte de Compras" ) );
    textLabel1->setText( tr( "Fechas" ) );
    QLERangoFechas->setText( tr( "-- --" ) );
    QLERangoFechas->setInputMask( tr( "0000-00-00 0000-00-00; " ) );
    textLabel2->setText( tr( "Compras Registradas" ) );
    QTCompras->horizontalHeader()->setLabel( 0, tr( "Proveedor" ) );
    QTCompras->horizontalHeader()->setLabel( 1, tr( "Concepto Existencia" ) );
    QTCompras->horizontalHeader()->setLabel( 2, tr( "Tipo Documento" ) );
    QTCompras->horizontalHeader()->setLabel( 3, tr( "Serie Factura" ) );
    QTCompras->horizontalHeader()->setLabel( 4, tr( "Fecha" ) );
    QTCompras->horizontalHeader()->setLabel( 5, tr( "Folio" ) );
    pushButton15->setText( tr( "Registrar" ) );
    pushButton15_2->setText( tr( "pushButton15" ) );
    textLabel2_2->setText( tr( "Compras Registradas" ) );
    QTDetalleCompras->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDetalleCompras->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTDetalleCompras->horizontalHeader()->setLabel( 2, tr( "Serie" ) );
    QTDetalleCompras->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTDetalleCompras->horizontalHeader()->setLabel( 4, tr( "Precio" ) );
    QTDetalleCompras->horizontalHeader()->setLabel( 5, tr( "Iva" ) );
    QTDetalleCompras->horizontalHeader()->setLabel( 6, tr( "Total" ) );
    textLabel3->setText( tr( "Importe" ) );
    textLabel3_2->setText( tr( "IVA" ) );
    textLabel3_2_2->setText( tr( "Total" ) );
}

