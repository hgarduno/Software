/****************************************************************************
** Form implementation generated from reading ui file 'UI/Contabilidad.ui'
**
** Created: Wed Apr 10 20:52:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Contabilidad.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtabwidget.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Contabilidad as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Contabilidad::Contabilidad( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Contabilidad" );
    ContabilidadLayout = new QGridLayout( this, 1, 1, 11, 6, "ContabilidadLayout"); 

    layout51 = new QHBoxLayout( 0, 0, 6, "layout51"); 

    layout49 = new QVBoxLayout( 0, 0, 6, "layout49"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout49->addWidget( textLabel5 );

    QTFacturas = new QTable( this, "QTFacturas" );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "# Factura" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Fecha" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Proveedor" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Total" ) );
    QTFacturas->setNumRows( 0 );
    QTFacturas->setNumCols( 4 );
    QTFacturas->setReadOnly( TRUE );
    layout49->addWidget( QTFacturas );
    layout51->addLayout( layout49 );

    layout49_2 = new QVBoxLayout( 0, 0, 6, "layout49_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    layout49_2->addWidget( textLabel5_2 );

    QTFacturas_2 = new QTable( this, "QTFacturas_2" );
    QTFacturas_2->setNumCols( QTFacturas_2->numCols() + 1 );
    QTFacturas_2->horizontalHeader()->setLabel( QTFacturas_2->numCols() - 1, tr( "# Factura" ) );
    QTFacturas_2->setNumCols( QTFacturas_2->numCols() + 1 );
    QTFacturas_2->horizontalHeader()->setLabel( QTFacturas_2->numCols() - 1, tr( "Fecha" ) );
    QTFacturas_2->setNumCols( QTFacturas_2->numCols() + 1 );
    QTFacturas_2->horizontalHeader()->setLabel( QTFacturas_2->numCols() - 1, tr( "Cliente" ) );
    QTFacturas_2->setNumCols( QTFacturas_2->numCols() + 1 );
    QTFacturas_2->horizontalHeader()->setLabel( QTFacturas_2->numCols() - 1, tr( "Total" ) );
    QTFacturas_2->setNumRows( 0 );
    QTFacturas_2->setNumCols( 4 );
    QTFacturas_2->setReadOnly( TRUE );
    layout49_2->addWidget( QTFacturas_2 );
    layout51->addLayout( layout49_2 );

    ContabilidadLayout->addMultiCellLayout( layout51, 0, 0, 0, 1 );

    layout58 = new QHBoxLayout( 0, 0, 6, "layout58"); 

    QPBPFacturasC = new QPushButton( this, "QPBPFacturasC" );
    QPBPFacturasC->setMinimumSize( QSize( 0, 50 ) );
    layout58->addWidget( QPBPFacturasC );

    pushButton16_3_2 = new QPushButton( this, "pushButton16_3_2" );
    pushButton16_3_2->setMinimumSize( QSize( 0, 50 ) );
    layout58->addWidget( pushButton16_3_2 );

    pushButton16 = new QPushButton( this, "pushButton16" );
    pushButton16->setMinimumSize( QSize( 0, 50 ) );
    layout58->addWidget( pushButton16 );

    QPBEjecutaContabilidad = new QPushButton( this, "QPBEjecutaContabilidad" );
    QPBEjecutaContabilidad->setMinimumSize( QSize( 0, 50 ) );
    layout58->addWidget( QPBEjecutaContabilidad );

    pushButton16_2_2 = new QPushButton( this, "pushButton16_2_2" );
    pushButton16_2_2->setMinimumSize( QSize( 0, 50 ) );
    layout58->addWidget( pushButton16_2_2 );

    ContabilidadLayout->addMultiCellLayout( layout58, 3, 3, 0, 1 );

    tabWidget3 = new QTabWidget( this, "tabWidget3" );

    tab = new QWidget( tabWidget3, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout55 = new QVBoxLayout( 0, 0, 6, "layout55"); 

    textLabel7 = new QLabel( tab, "textLabel7" );
    layout55->addWidget( textLabel7 );

    table8 = new QTable( tab, "table8" );
    table8->setNumCols( table8->numCols() + 1 );
    table8->horizontalHeader()->setLabel( table8->numCols() - 1, tr( "Producto" ) );
    table8->setNumCols( table8->numCols() + 1 );
    table8->horizontalHeader()->setLabel( table8->numCols() - 1, tr( "Cantidad" ) );
    table8->setNumCols( table8->numCols() + 1 );
    table8->horizontalHeader()->setLabel( table8->numCols() - 1, tr( "Importe Existencia" ) );
    table8->setNumRows( 0 );
    table8->setNumCols( 3 );
    layout55->addWidget( table8 );

    tabLayout->addLayout( layout55, 0, 0 );
    tabWidget3->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget3, "tab_2" );
    tabWidget3->insertTab( tab_2, QString::fromLatin1("") );

    ContabilidadLayout->addMultiCellWidget( tabWidget3, 1, 1, 0, 1 );

    layout67 = new QVBoxLayout( 0, 0, 6, "layout67"); 

    textLabel8 = new QLabel( this, "textLabel8" );
    textLabel8->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel8->sizePolicy().hasHeightForWidth() ) );
    layout67->addWidget( textLabel8 );

    textEdit3 = new QTextEdit( this, "textEdit3" );
    textEdit3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textEdit3->sizePolicy().hasHeightForWidth() ) );
    layout67->addWidget( textEdit3 );

    ContabilidadLayout->addLayout( layout67, 2, 1 );

    layout76 = new QVBoxLayout( 0, 0, 6, "layout76"); 

    layout52 = new QVBoxLayout( 0, 0, 6, "layout52"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout52->addWidget( textLabel6 );

    lineEdit18 = new QLineEdit( this, "lineEdit18" );
    layout52->addWidget( lineEdit18 );
    layout76->addLayout( layout52 );

    layout75 = new QVBoxLayout( 0, 0, 6, "layout75"); 

    layout74 = new QHBoxLayout( 0, 0, 6, "layout74"); 

    layout69 = new QVBoxLayout( 0, 0, 6, "layout69"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    textLabel6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel6_2->sizePolicy().hasHeightForWidth() ) );
    layout69->addWidget( textLabel6_2 );

    lCDNumber3 = new QLCDNumber( this, "lCDNumber3" );
    lCDNumber3->setNumDigits( 10 );
    layout69->addWidget( lCDNumber3 );
    layout74->addLayout( layout69 );

    layout69_2 = new QVBoxLayout( 0, 0, 6, "layout69_2"); 

    textLabel6_2_3 = new QLabel( this, "textLabel6_2_3" );
    textLabel6_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel6_2_3->sizePolicy().hasHeightForWidth() ) );
    layout69_2->addWidget( textLabel6_2_3 );

    lCDNumber3_3 = new QLCDNumber( this, "lCDNumber3_3" );
    lCDNumber3_3->setNumDigits( 10 );
    layout69_2->addWidget( lCDNumber3_3 );
    layout74->addLayout( layout69_2 );
    layout75->addLayout( layout74 );

    layout73 = new QHBoxLayout( 0, 0, 6, "layout73"); 

    layout70 = new QVBoxLayout( 0, 0, 6, "layout70"); 

    textLabel6_2_2 = new QLabel( this, "textLabel6_2_2" );
    textLabel6_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel6_2_2->sizePolicy().hasHeightForWidth() ) );
    layout70->addWidget( textLabel6_2_2 );

    lCDNumber3_2 = new QLCDNumber( this, "lCDNumber3_2" );
    lCDNumber3_2->setNumDigits( 10 );
    layout70->addWidget( lCDNumber3_2 );
    layout73->addLayout( layout70 );

    layout69_2_2 = new QVBoxLayout( 0, 0, 6, "layout69_2_2"); 

    textLabel6_2_3_2 = new QLabel( this, "textLabel6_2_3_2" );
    textLabel6_2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel6_2_3_2->sizePolicy().hasHeightForWidth() ) );
    layout69_2_2->addWidget( textLabel6_2_3_2 );

    lCDNumber3_3_2 = new QLCDNumber( this, "lCDNumber3_3_2" );
    lCDNumber3_3_2->setNumDigits( 10 );
    layout69_2_2->addWidget( lCDNumber3_3_2 );
    layout73->addLayout( layout69_2_2 );
    layout75->addLayout( layout73 );
    layout76->addLayout( layout75 );

    ContabilidadLayout->addLayout( layout76, 2, 0 );
    languageChange();
    resize( QSize(717, 732).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Contabilidad::~Contabilidad()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Contabilidad::languageChange()
{
    setCaption( tr( "Contabilidad Siscom" ) );
    textLabel5->setText( tr( "Facturas Compras" ) );
    QTFacturas->horizontalHeader()->setLabel( 0, tr( "# Factura" ) );
    QTFacturas->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTFacturas->horizontalHeader()->setLabel( 2, tr( "Proveedor" ) );
    QTFacturas->horizontalHeader()->setLabel( 3, tr( "Total" ) );
    textLabel5_2->setText( tr( "Facturas Ventas" ) );
    QTFacturas_2->horizontalHeader()->setLabel( 0, tr( "# Factura" ) );
    QTFacturas_2->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTFacturas_2->horizontalHeader()->setLabel( 2, tr( "Cliente" ) );
    QTFacturas_2->horizontalHeader()->setLabel( 3, tr( "Total" ) );
    QPBPFacturasC->setText( tr( "Pegar Facturas\n"
"Compras" ) );
    pushButton16_3_2->setText( tr( "Pegar Facturas\n"
"Ventas" ) );
    pushButton16->setText( tr( "Rango Fechas" ) );
    QPBEjecutaContabilidad->setText( tr( "Ejecuta\n"
"Contabilidad" ) );
    pushButton16_2_2->setText( tr( "Descripcion\n"
"Proceso" ) );
    textLabel7->setText( tr( "Estado Inventario" ) );
    table8->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    table8->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    table8->horizontalHeader()->setLabel( 2, tr( "Importe Existencia" ) );
    tabWidget3->changeTab( tab, tr( "Tab 1" ) );
    tabWidget3->changeTab( tab_2, tr( "Tab 2" ) );
    textLabel8->setText( tr( "textLabel8" ) );
    textLabel6->setText( tr( "Fecha De Aplicacion" ) );
    textLabel6_2->setText( tr( "Total Compras" ) );
    textLabel6_2_3->setText( tr( "Total Compras" ) );
    textLabel6_2_2->setText( tr( "Total Ventas" ) );
    textLabel6_2_3_2->setText( tr( "Total Compras" ) );
}

