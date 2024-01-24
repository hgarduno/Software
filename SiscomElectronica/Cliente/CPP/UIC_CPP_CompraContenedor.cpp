/****************************************************************************
** Form implementation generated from reading ui file 'UI/CompraContenedor.ui'
**
** Created: Thu Dec 21 12:53:46 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CompraContenedor.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a CompraContenedor as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CompraContenedor::CompraContenedor( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CompraContenedor" );
    CompraContenedorLayout = new QGridLayout( this, 1, 1, 11, 6, "CompraContenedorLayout"); 
    spacer2 = new QSpacerItem( 410, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    CompraContenedorLayout->addItem( spacer2, 0, 1 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout9->addWidget( textLabel2 );

    QTFacturas = new QTable( this, "QTFacturas" );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Proveedor" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "#Factura" ) );
    QTFacturas->setNumCols( QTFacturas->numCols() + 1 );
    QTFacturas->horizontalHeader()->setLabel( QTFacturas->numCols() - 1, tr( "Partidas" ) );
    QTFacturas->setNumRows( 0 );
    QTFacturas->setNumCols( 3 );
    QTFacturas->setReadOnly( TRUE );
    layout9->addWidget( QTFacturas );

    CompraContenedorLayout->addMultiCellLayout( layout9, 1, 1, 0, 1 );

    layout53 = new QHBoxLayout( 0, 0, 6, "layout53"); 

    layout51 = new QHBoxLayout( 0, 0, 6, "layout51"); 

    layout49 = new QVBoxLayout( 0, 0, 6, "layout49"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout49->addWidget( textLabel3 );

    textEdit1 = new QTextEdit( this, "textEdit1" );
    textEdit1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textEdit1->sizePolicy().hasHeightForWidth() ) );
    layout49->addWidget( textEdit1 );
    layout51->addLayout( layout49 );

    layout50 = new QVBoxLayout( 0, 0, 6, "layout50"); 

    layout40_2 = new QVBoxLayout( 0, 0, 6, "layout40_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout40_2->addWidget( textLabel3_2 );

    QLECostoEnvio = new QLineEdit( this, "QLECostoEnvio" );
    QLECostoEnvio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoEnvio->sizePolicy().hasHeightForWidth() ) );
    layout40_2->addWidget( QLECostoEnvio );
    layout50->addLayout( layout40_2 );

    layout40_2_2 = new QVBoxLayout( 0, 0, 6, "layout40_2_2"); 

    textLabel3_2_2 = new QLabel( this, "textLabel3_2_2" );
    textLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout40_2_2->addWidget( textLabel3_2_2 );

    QLECostoDolar = new QLineEdit( this, "QLECostoDolar" );
    QLECostoDolar->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoDolar->sizePolicy().hasHeightForWidth() ) );
    layout40_2_2->addWidget( QLECostoDolar );
    layout50->addLayout( layout40_2_2 );
    layout51->addLayout( layout50 );
    layout53->addLayout( layout51 );

    layout52 = new QVBoxLayout( 0, 0, 6, "layout52"); 

    layout40_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout40_2_2_2"); 

    textLabel3_2_2_2 = new QLabel( this, "textLabel3_2_2_2" );
    textLabel3_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout40_2_2_2->addWidget( textLabel3_2_2_2 );

    QLECostoAdministrativo = new QLineEdit( this, "QLECostoAdministrativo" );
    QLECostoAdministrativo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECostoAdministrativo->sizePolicy().hasHeightForWidth() ) );
    layout40_2_2_2->addWidget( QLECostoAdministrativo );
    layout52->addLayout( layout40_2_2_2 );
    spacer3 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed );
    layout52->addItem( spacer3 );
    layout53->addLayout( layout52 );

    CompraContenedorLayout->addLayout( layout53, 0, 0 );

    layout54 = new QHBoxLayout( 0, 0, 6, "layout54"); 

    pushButton5 = new QPushButton( this, "pushButton5" );
    layout54->addWidget( pushButton5 );

    QPBAgregaFactura = new QPushButton( this, "QPBAgregaFactura" );
    QPBAgregaFactura->setEnabled( TRUE );
    layout54->addWidget( QPBAgregaFactura );

    CompraContenedorLayout->addMultiCellLayout( layout54, 2, 2, 0, 1 );
    languageChange();
    resize( QSize(956, 469).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CompraContenedor::~CompraContenedor()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CompraContenedor::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel2->setText( tr( "Facturas" ) );
    QTFacturas->horizontalHeader()->setLabel( 0, tr( "Proveedor" ) );
    QTFacturas->horizontalHeader()->setLabel( 1, tr( "#Factura" ) );
    QTFacturas->horizontalHeader()->setLabel( 2, tr( "Partidas" ) );
    textLabel3->setText( tr( "Descripcion Compra" ) );
    textLabel3_2->setText( tr( "Costo Envio" ) );
    textLabel3_2_2->setText( tr( "Cotizacion Dolar" ) );
    textLabel3_2_2_2->setText( tr( "Costo Administrativo" ) );
    pushButton5->setText( tr( "Registrar Contenedor" ) );
    QPBAgregaFactura->setText( tr( "Agrega Factura" ) );
}

