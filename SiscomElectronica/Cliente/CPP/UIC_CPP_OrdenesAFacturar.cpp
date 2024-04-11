/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenesAFacturar.ui'
**
** Created: Wed Apr 10 20:52:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenesAFacturar.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlcdnumber.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a OrdenesAFacturar as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
OrdenesAFacturar::OrdenesAFacturar( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "OrdenesAFacturar" );
    OrdenesAFacturarLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenesAFacturarLayout"); 

    layout51 = new QHBoxLayout( 0, 0, 6, "layout51"); 

    QPBAnexarO = new QPushButton( this, "QPBAnexarO" );
    QPBAnexarO->setAutoDefault( FALSE );
    layout51->addWidget( QPBAnexarO );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout51->addWidget( QPBAceptar );

    pushButton9_2 = new QPushButton( this, "pushButton9_2" );
    pushButton9_2->setAutoDefault( FALSE );
    layout51->addWidget( pushButton9_2 );

    OrdenesAFacturarLayout->addLayout( layout51, 4, 0 );

    layout57 = new QHBoxLayout( 0, 0, 6, "layout57"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( textLabel2_4 );

    QLCNTotal = new QLCDNumber( this, "QLCNTotal" );
    QLCNTotal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, QLCNTotal->sizePolicy().hasHeightForWidth() ) );
    QLCNTotal->setMinimumSize( QSize( 0, 50 ) );
    QLCNTotal->setNumDigits( 10 );
    layout23->addWidget( QLCNTotal );
    layout57->addLayout( layout23 );

    layout23_3 = new QVBoxLayout( 0, 0, 6, "layout23_3"); 

    textLabel2_4_2 = new QLabel( this, "textLabel2_4_2" );
    textLabel2_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4_2->sizePolicy().hasHeightForWidth() ) );
    layout23_3->addWidget( textLabel2_4_2 );

    QLCNIVA = new QLCDNumber( this, "QLCNIVA" );
    QLCNIVA->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, QLCNIVA->sizePolicy().hasHeightForWidth() ) );
    QLCNIVA->setMinimumSize( QSize( 0, 50 ) );
    QLCNIVA->setNumDigits( 10 );
    layout23_3->addWidget( QLCNIVA );
    layout57->addLayout( layout23_3 );

    layout23_2 = new QVBoxLayout( 0, 0, 6, "layout23_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout23_2->addWidget( textLabel2_2_2 );

    QLCDNTotalMIVA = new QLCDNumber( this, "QLCDNTotalMIVA" );
    QLCDNTotalMIVA->setEnabled( TRUE );
    QLCDNTotalMIVA->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, QLCDNTotalMIVA->sizePolicy().hasHeightForWidth() ) );
    QLCDNTotalMIVA->setMinimumSize( QSize( 0, 50 ) );
    QLCDNTotalMIVA->setNumDigits( 10 );
    layout23_2->addWidget( QLCDNTotalMIVA );
    layout57->addLayout( layout23_2 );

    OrdenesAFacturarLayout->addLayout( layout57, 3, 0 );

    layout45 = new QVBoxLayout( 0, 0, 6, "layout45"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout45->addWidget( textLabel2 );

    QLEOrden = new QLineEdit( this, "QLEOrden" );
    layout45->addWidget( QLEOrden );

    OrdenesAFacturarLayout->addLayout( layout45, 0, 0 );

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout46 = new QVBoxLayout( 0, 0, 6, "layout46"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout46->addWidget( textLabel3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );
    layout46->addWidget( QTDatos );
    layout9->addLayout( layout46 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout8->addWidget( textLabel1 );

    QTOrdenes = new QTable( this, "QTOrdenes" );
    QTOrdenes->setNumCols( QTOrdenes->numCols() + 1 );
    QTOrdenes->horizontalHeader()->setLabel( QTOrdenes->numCols() - 1, tr( "No Orden" ) );
    QTOrdenes->setNumRows( 0 );
    QTOrdenes->setNumCols( 1 );
    layout8->addWidget( QTOrdenes );
    layout9->addLayout( layout8 );
    layout36->addLayout( layout9 );

    layout46_2 = new QVBoxLayout( 0, 0, 6, "layout46_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout46_2->addWidget( textLabel3_2 );

    QTProdOrden = new QTable( this, "QTProdOrden" );
    QTProdOrden->setNumCols( QTProdOrden->numCols() + 1 );
    QTProdOrden->horizontalHeader()->setLabel( QTProdOrden->numCols() - 1, tr( "Producto" ) );
    QTProdOrden->setNumCols( QTProdOrden->numCols() + 1 );
    QTProdOrden->horizontalHeader()->setLabel( QTProdOrden->numCols() - 1, tr( "Cantidad" ) );
    QTProdOrden->setNumCols( QTProdOrden->numCols() + 1 );
    QTProdOrden->horizontalHeader()->setLabel( QTProdOrden->numCols() - 1, tr( "Precio" ) );
    QTProdOrden->setNumCols( QTProdOrden->numCols() + 1 );
    QTProdOrden->horizontalHeader()->setLabel( QTProdOrden->numCols() - 1, tr( "Importe" ) );
    QTProdOrden->setMinimumSize( QSize( 0, 120 ) );
    QTProdOrden->setNumRows( 0 );
    QTProdOrden->setNumCols( 4 );
    layout46_2->addWidget( QTProdOrden );
    layout36->addLayout( layout46_2 );

    OrdenesAFacturarLayout->addLayout( layout36, 2, 0 );
    languageChange();
    resize( QSize(634, 590).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenesAFacturar::~OrdenesAFacturar()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenesAFacturar::languageChange()
{
    setCaption( tr( "Ordenes A Facturar" ) );
    QPBAnexarO->setText( tr( "Anexar Orden" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    pushButton9_2->setText( tr( "Cancelar" ) );
    textLabel2_4->setText( tr( "Total" ) );
    textLabel2_4_2->setText( tr( "IVA" ) );
    textLabel2_2_2->setText( tr( "Total +IVA" ) );
    textLabel2->setText( tr( "# Orden" ) );
    QLEOrden->setText( tr( "1284537353" ) );
    textLabel3->setText( tr( "Productos" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
    textLabel1->setText( tr( "Ordenes" ) );
    QTOrdenes->horizontalHeader()->setLabel( 0, tr( "No Orden" ) );
    textLabel3_2->setText( tr( "Productos Por Orden" ) );
    QTProdOrden->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProdOrden->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTProdOrden->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTProdOrden->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
}

