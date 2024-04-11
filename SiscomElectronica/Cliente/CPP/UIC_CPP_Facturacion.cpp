/****************************************************************************
** Form implementation generated from reading ui file 'UI/Facturacion.ui'
**
** Created: Wed Apr 10 21:10:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Facturacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Facturacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Facturacion::Facturacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "Facturacion" );
    FacturacionLayout = new QGridLayout( this, 1, 1, 11, 6, "FacturacionLayout"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout3->addWidget( textLabel2 );

    QLECliente = new QLineEdit( this, "QLECliente" );
    layout3->addWidget( QLECliente );

    FacturacionLayout->addLayout( layout3, 0, 0 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout3_2->addWidget( textLabel2_2 );

    lineEdit1_2 = new QLineEdit( this, "lineEdit1_2" );
    layout3_2->addWidget( lineEdit1_2 );

    FacturacionLayout->addLayout( layout3_2, 0, 2 );

    layout3_2_2 = new QVBoxLayout( 0, 0, 6, "layout3_2_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    layout3_2_2->addWidget( textLabel2_2_2 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    layout3_2_2->addWidget( QLERFC );

    FacturacionLayout->addLayout( layout3_2_2, 0, 1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe Unitario" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe Total" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );

    FacturacionLayout->addMultiCellWidget( QTDatos, 1, 1, 0, 2 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    tabWidget2 = new QTabWidget( this, "tabWidget2" );
    tabWidget2->setMaximumSize( QSize( 32767, 150 ) );

    tab = new QWidget( tabWidget2, "tab" );

    pushButton1_2 = new QPushButton( tab, "pushButton1_2" );
    pushButton1_2->setGeometry( QRect( 137, 10, 120, 26 ) );

    QPBImprime = new QPushButton( tab, "QPBImprime" );
    QPBImprime->setGeometry( QRect( 7, 10, 120, 26 ) );
    tabWidget2->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget2, "tab_2" );
    tabLayout = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout"); 

    QTDOrden = new QTable( tab_2, "QTDOrden" );
    QTDOrden->setNumCols( QTDOrden->numCols() + 1 );
    QTDOrden->horizontalHeader()->setLabel( QTDOrden->numCols() - 1, tr( "No Orden" ) );
    QTDOrden->setNumCols( QTDOrden->numCols() + 1 );
    QTDOrden->horizontalHeader()->setLabel( QTDOrden->numCols() - 1, tr( "Importe" ) );
    QTDOrden->setNumRows( 0 );
    QTDOrden->setNumCols( 2 );

    tabLayout->addWidget( QTDOrden, 0, 0 );
    tabWidget2->insertTab( tab_2, QString::fromLatin1("") );

    TabPage = new QWidget( tabWidget2, "TabPage" );
    tabWidget2->insertTab( TabPage, QString::fromLatin1("") );
    layout7->addWidget( tabWidget2 );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QLCDImpTotal = new QLCDNumber( this, "QLCDImpTotal" );
    QLCDImpTotal->setMaximumSize( QSize( 100, 150 ) );
    QLCDImpTotal->setNumDigits( 8 );
    layout1->addWidget( QLCDImpTotal );
    layout5->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel1_2 );

    QLCImpMIVA = new QLCDNumber( this, "QLCImpMIVA" );
    QLCImpMIVA->setMaximumSize( QSize( 150, 150 ) );
    QLCImpMIVA->setNumDigits( 8 );
    layout2->addWidget( QLCImpMIVA );
    layout5->addLayout( layout2 );
    layout7->addLayout( layout5 );

    FacturacionLayout->addMultiCellLayout( layout7, 2, 2, 0, 2 );
    languageChange();
    resize( QSize(668, 505).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Facturacion::~Facturacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Facturacion::languageChange()
{
    setCaption( tr( "Sistema De Facturacion" ) );
    textLabel2->setText( tr( "Cliente" ) );
    QLECliente->setText( tr( "Heli Garduno Esquivel" ) );
    textLabel2_2->setText( tr( "Fecha" ) );
    textLabel2_2_2->setText( tr( "RFC" ) );
    QLERFC->setText( tr( "GAEH720320LE8" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Importe Unitario" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Importe Total" ) );
    pushButton1_2->setText( tr( "Vista Previa" ) );
    QPBImprime->setText( tr( "Imprimir" ) );
    tabWidget2->changeTab( tab, tr( "Impresion" ) );
    QTDOrden->horizontalHeader()->setLabel( 0, tr( "No Orden" ) );
    QTDOrden->horizontalHeader()->setLabel( 1, tr( "Importe" ) );
    tabWidget2->changeTab( tab_2, tr( "Datos Ordenes" ) );
    tabWidget2->changeTab( TabPage, tr( "Informacion Cliente" ) );
    textLabel1->setText( tr( "Importe Total" ) );
    textLabel1_2->setText( tr( "Importe Mas IVA" ) );
}

