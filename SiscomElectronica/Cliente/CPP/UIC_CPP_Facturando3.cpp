/****************************************************************************
** Form implementation generated from reading ui file 'UI/Facturando3.ui'
**
** Created: Fri Apr 12 21:26:00 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Facturando3.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Facturando3 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Facturando3::Facturando3( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Facturando3" );
    Facturando3Layout = new QGridLayout( this, 1, 1, 11, 6, "Facturando3Layout"); 

    layout46 = new QHBoxLayout( 0, 0, 6, "layout46"); 

    QTWTipoCliente = new QTabWidget( this, "QTWTipoCliente" );
    QTWTipoCliente->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTWTipoCliente->sizePolicy().hasHeightForWidth() ) );

    tab = new QWidget( QTWTipoCliente, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1_2 = new QLabel( tab, "textLabel1_2" );
    layout6->addWidget( textLabel1_2 );

    QLENombre = new QLineEdit( tab, "QLENombre" );
    QLENombre->setReadOnly( TRUE );
    layout6->addWidget( QLENombre );
    layout20->addLayout( layout6 );

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel1_2_2 = new QLabel( tab, "textLabel1_2_2" );
    layout6_2->addWidget( textLabel1_2_2 );

    QLEAPaterno = new QLineEdit( tab, "QLEAPaterno" );
    QLEAPaterno->setReadOnly( TRUE );
    layout6_2->addWidget( QLEAPaterno );
    layout20->addLayout( layout6_2 );

    layout6_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_2_2"); 

    textLabel1_2_2_2 = new QLabel( tab, "textLabel1_2_2_2" );
    layout6_2_2->addWidget( textLabel1_2_2_2 );

    QLEAMaterno = new QLineEdit( tab, "QLEAMaterno" );
    QLEAMaterno->setReadOnly( FALSE );
    layout6_2_2->addWidget( QLEAMaterno );
    layout20->addLayout( layout6_2_2 );

    tabLayout->addLayout( layout20, 0, 0 );
    QTWTipoCliente->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( QTWTipoCliente, "tab_2" );
    tabLayout_2 = new QHBoxLayout( tab_2, 11, 6, "tabLayout_2"); 

    layout6_5 = new QVBoxLayout( 0, 0, 6, "layout6_5"); 

    textLabel1_2_5 = new QLabel( tab_2, "textLabel1_2_5" );
    layout6_5->addWidget( textLabel1_2_5 );

    QLERazonSocial = new QLineEdit( tab_2, "QLERazonSocial" );
    layout6_5->addWidget( QLERazonSocial );
    tabLayout_2->addLayout( layout6_5 );
    QTWTipoCliente->insertTab( tab_2, QString::fromLatin1("") );
    layout46->addWidget( QTWTipoCliente );

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    layout6_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout6_2_2_3"); 

    textLabel1_2_2_2_3 = new QLabel( this, "textLabel1_2_2_2_3" );
    textLabel1_2_2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2_3->sizePolicy().hasHeightForWidth() ) );
    layout6_2_2_3->addWidget( textLabel1_2_2_2_3 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    QLERFC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLERFC->sizePolicy().hasHeightForWidth() ) );
    QLERFC->setReadOnly( TRUE );
    layout6_2_2_3->addWidget( QLERFC );
    layout44->addLayout( layout6_2_2_3 );
    spacer1 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed );
    layout44->addItem( spacer1 );
    layout46->addLayout( layout44 );

    Facturando3Layout->addMultiCellLayout( layout46, 0, 0, 0, 1 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout41->addWidget( textLabel1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Total" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );
    layout41->addWidget( QTDatos );

    Facturando3Layout->addMultiCellLayout( layout41, 3, 3, 0, 1 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    layout6_3 = new QVBoxLayout( 0, 0, 6, "layout6_3"); 

    textLabel1_2_3 = new QLabel( this, "textLabel1_2_3" );
    layout6_3->addWidget( textLabel1_2_3 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    QLECalle->setReadOnly( TRUE );
    layout6_3->addWidget( QLECalle );
    layout21->addLayout( layout6_3 );

    layout6_3_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2"); 

    textLabel1_2_3_2 = new QLabel( this, "textLabel1_2_3_2" );
    layout6_3_2->addWidget( textLabel1_2_3_2 );

    QLENumero = new QLineEdit( this, "QLENumero" );
    QLENumero->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumero->sizePolicy().hasHeightForWidth() ) );
    QLENumero->setReadOnly( TRUE );
    layout6_3_2->addWidget( QLENumero );
    layout21->addLayout( layout6_3_2 );

    layout6_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2"); 

    textLabel1_2_3_2_2 = new QLabel( this, "textLabel1_2_3_2_2" );
    layout6_3_2_2->addWidget( textLabel1_2_3_2_2 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    QLEColonia->setReadOnly( TRUE );
    layout6_3_2_2->addWidget( QLEColonia );
    layout21->addLayout( layout6_3_2_2 );

    layout6_3_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2_3"); 

    textLabel1_2_3_2_2_3 = new QLabel( this, "textLabel1_2_3_2_2_3" );
    layout6_3_2_2_3->addWidget( textLabel1_2_3_2_2_3 );

    QLECP = new QLineEdit( this, "QLECP" );
    QLECP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECP->sizePolicy().hasHeightForWidth() ) );
    QLECP->setReadOnly( TRUE );
    layout6_3_2_2_3->addWidget( QLECP );
    layout21->addLayout( layout6_3_2_2_3 );
    layout42->addLayout( layout21 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout6_3_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2_2"); 

    textLabel1_2_3_2_2_2 = new QLabel( this, "textLabel1_2_3_2_2_2" );
    layout6_3_2_2_2->addWidget( textLabel1_2_3_2_2_2 );

    QLEDelMun = new QLineEdit( this, "QLEDelMun" );
    QLEDelMun->setReadOnly( TRUE );
    layout6_3_2_2_2->addWidget( QLEDelMun );
    layout22->addLayout( layout6_3_2_2_2 );

    layout6_3_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2_2_2"); 

    textLabel1_2_3_2_2_2_2 = new QLabel( this, "textLabel1_2_3_2_2_2_2" );
    layout6_3_2_2_2_2->addWidget( textLabel1_2_3_2_2_2_2 );

    QLEEstado = new QLineEdit( this, "QLEEstado" );
    QLEEstado->setReadOnly( TRUE );
    layout6_3_2_2_2_2->addWidget( QLEEstado );
    layout22->addLayout( layout6_3_2_2_2_2 );
    layout42->addLayout( layout22 );

    Facturando3Layout->addMultiCellLayout( layout42, 2, 2, 0, 1 );

    layout41_2 = new QHBoxLayout( 0, 0, 6, "layout41_2"); 

    layout25 = new QGridLayout( 0, 1, 1, 0, 6, "layout25"); 

    QPBAnexarFactura_2 = new QPushButton( this, "QPBAnexarFactura_2" );
    QPBAnexarFactura_2->setMinimumSize( QSize( 0, 50 ) );

    layout25->addWidget( QPBAnexarFactura_2, 1, 0 );

    QPBAnexarOrden = new QPushButton( this, "QPBAnexarOrden" );
    QPBAnexarOrden->setMinimumSize( QSize( 0, 50 ) );

    layout25->addWidget( QPBAnexarOrden, 0, 1 );

    QPBCliente = new QPushButton( this, "QPBCliente" );
    QPBCliente->setMinimumSize( QSize( 0, 50 ) );

    layout25->addWidget( QPBCliente, 0, 0 );

    QPBImpFactura = new QPushButton( this, "QPBImpFactura" );
    QPBImpFactura->setMinimumSize( QSize( 0, 50 ) );

    layout25->addWidget( QPBImpFactura, 1, 1 );
    layout41_2->addLayout( layout25 );

    layout39 = new QHBoxLayout( 0, 0, 6, "layout39"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( textLabel2 );

    QLCNTotal = new QLCDNumber( this, "QLCNTotal" );
    QLCNTotal->setNumDigits( 10 );
    layout23->addWidget( QLCNTotal );
    layout39->addLayout( layout23 );

    layout23_2 = new QVBoxLayout( 0, 0, 6, "layout23_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout23_2->addWidget( textLabel2_2 );

    QLCDNTotalMIVA = new QLCDNumber( this, "QLCDNTotalMIVA" );
    QLCDNTotalMIVA->setNumDigits( 10 );
    layout23_2->addWidget( QLCDNTotalMIVA );
    layout39->addLayout( layout23_2 );

    layout23_3 = new QVBoxLayout( 0, 0, 6, "layout23_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout23_3->addWidget( textLabel2_3 );

    QLCNIVA = new QLCDNumber( this, "QLCNIVA" );
    QLCNIVA->setNumDigits( 10 );
    layout23_3->addWidget( QLCNIVA );
    layout39->addLayout( layout23_3 );
    layout41_2->addLayout( layout39 );

    Facturando3Layout->addMultiCellLayout( layout41_2, 4, 4, 0, 1 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout19->addWidget( textLabel1_3 );

    QLETelefono = new QLineEdit( this, "QLETelefono" );
    QLETelefono->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLETelefono->sizePolicy().hasHeightForWidth() ) );
    QLETelefono->setReadOnly( TRUE );
    layout19->addWidget( QLETelefono );

    Facturando3Layout->addLayout( layout19, 1, 0 );

    layout19_2 = new QVBoxLayout( 0, 0, 6, "layout19_2"); 

    textLabel1_3_2 = new QLabel( this, "textLabel1_3_2" );
    layout19_2->addWidget( textLabel1_3_2 );

    QLECorreo = new QLineEdit( this, "QLECorreo" );
    QLECorreo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECorreo->sizePolicy().hasHeightForWidth() ) );
    QLECorreo->setReadOnly( TRUE );
    layout19_2->addWidget( QLECorreo );

    Facturando3Layout->addLayout( layout19_2, 1, 1 );
    languageChange();
    resize( QSize(567, 524).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Facturando3::~Facturando3()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Facturando3::languageChange()
{
    setCaption( tr( "Factura" ) );
    textLabel1_2->setText( tr( "Nombre" ) );
    textLabel1_2_2->setText( tr( "Apellido Paterno" ) );
    textLabel1_2_2_2->setText( tr( "Apellido Materno" ) );
    QTWTipoCliente->changeTab( tab, tr( "Persona Fisica" ) );
    textLabel1_2_5->setText( tr( "Razon Social" ) );
    QTWTipoCliente->changeTab( tab_2, tr( "Persona Moral" ) );
    textLabel1_2_2_2_3->setText( tr( "RFC" ) );
    textLabel1->setText( tr( "Productos A Facturar" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Total" ) );
    textLabel1_2_3->setText( tr( "Calle" ) );
    textLabel1_2_3_2->setText( tr( "Numero" ) );
    textLabel1_2_3_2_2->setText( tr( "Colonia" ) );
    textLabel1_2_3_2_2_3->setText( tr( "CP" ) );
    textLabel1_2_3_2_2_2->setText( tr( "Delegacion/Municipio" ) );
    textLabel1_2_3_2_2_2_2->setText( tr( "Estado" ) );
    QPBAnexarFactura_2->setText( tr( "Anexa Factura\n"
"Por Numero" ) );
    QPBAnexarOrden->setText( tr( "Anexar \n"
"Orden" ) );
    QPBCliente->setText( tr( "Datos Cliente" ) );
    QPBImpFactura->setText( tr( "Imprimir\n"
"Factura" ) );
    textLabel2->setText( tr( "Total" ) );
    textLabel2_2->setText( tr( "Total +IVA" ) );
    textLabel2_3->setText( tr( "16% IVA" ) );
    textLabel1_3->setText( tr( "Telefono" ) );
    textLabel1_3_2->setText( tr( "Correo Electronico" ) );
}

