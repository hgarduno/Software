/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenesVendidas.ui'
**
** Created: Thu Apr 11 21:53:39 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenesVendidas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a OrdenesVendidas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
OrdenesVendidas::OrdenesVendidas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "OrdenesVendidas" );
    OrdenesVendidasLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenesVendidasLayout"); 

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    QPBOFecha = new QPushButton( this, "QPBOFecha" );
    layout37->addWidget( QPBOFecha );

    pushButton16 = new QPushButton( this, "pushButton16" );
    layout37->addWidget( pushButton16 );

    pushButton17 = new QPushButton( this, "pushButton17" );
    layout37->addWidget( pushButton17 );

    pushButton18 = new QPushButton( this, "pushButton18" );
    layout37->addWidget( pushButton18 );

    QPBFacturar = new QPushButton( this, "QPBFacturar" );
    layout37->addWidget( QPBFacturar );

    OrdenesVendidasLayout->addMultiCellLayout( layout37, 3, 3, 0, 1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "No Orden" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 5 );
    QTDatos->setReadOnly( TRUE );

    OrdenesVendidasLayout->addMultiCellWidget( QTDatos, 1, 1, 0, 1 );

    layout39 = new QHBoxLayout( 0, 0, 6, "layout39"); 

    layout38 = new QVBoxLayout( 0, 0, 6, "layout38"); 

    QPBAOrden = new QPushButton( this, "QPBAOrden" );
    layout38->addWidget( QPBAOrden );

    QPBNOrden = new QPushButton( this, "QPBNOrden" );
    layout38->addWidget( QPBNOrden );
    layout39->addLayout( layout38 );

    lCDNumber1 = new QLCDNumber( this, "lCDNumber1" );
    layout39->addWidget( lCDNumber1 );

    OrdenesVendidasLayout->addMultiCellLayout( layout39, 2, 2, 0, 1 );

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout31->addWidget( textLabel4 );

    QLENoOrden = new QLineEdit( this, "QLENoOrden" );
    layout31->addWidget( QLENoOrden );

    OrdenesVendidasLayout->addLayout( layout31, 0, 0 );

    layout68 = new QVBoxLayout( 0, 0, 6, "layout68"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setFrameShape( QLabel::NoFrame );
    textLabel5->setFrameShadow( QLabel::Plain );
    layout68->addWidget( textLabel5 );

    layout67 = new QHBoxLayout( 0, 0, 6, "layout67"); 

    QCFSFechaIni = new CQControlFecha( this, "QCFSFechaIni" );
    layout67->addWidget( QCFSFechaIni );

    QCFSFechaFin = new CQControlFecha( this, "QCFSFechaFin" );
    layout67->addWidget( QCFSFechaFin );
    spacer9 = new QSpacerItem( 139, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout67->addItem( spacer9 );
    layout68->addLayout( layout67 );

    OrdenesVendidasLayout->addLayout( layout68, 0, 1 );
    languageChange();
    resize( QSize(608, 574).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenesVendidas::~OrdenesVendidas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenesVendidas::languageChange()
{
    setCaption( tr( "Ordenes Vendidas" ) );
    QPBOFecha->setText( tr( "Ordenes Por Fecha" ) );
    pushButton16->setText( tr( "pushButton16" ) );
    pushButton17->setText( tr( "pushButton17" ) );
    pushButton18->setText( tr( "pushButton18" ) );
    QPBFacturar->setText( tr( "Facturar" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "No Orden" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Importe" ) );
    QPBAOrden->setText( tr( "Anexar Orden" ) );
    QPBNOrden->setText( tr( "Nueva Orden" ) );
    textLabel4->setText( tr( "Numero Orden" ) );
    textLabel5->setText( tr( "Ordenes Por Fecha" ) );
}

