/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/MantenimientoProductos.ui'
**
** Created: Thu Apr 11 21:07:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "MantenimientoProductos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSS.h"
#include "QCtrlDepartamentosSS.h"
#include "QCtrlProductosSS.h"

/*
 *  Constructs a MantenimientoProductos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
MantenimientoProductos::MantenimientoProductos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "MantenimientoProductos" );
    MantenimientoProductosLayout = new QGridLayout( this, 1, 1, 11, 6, "MantenimientoProductosLayout"); 

    layout65 = new QHBoxLayout( 0, 0, 6, "layout65"); 

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( textLabel2 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    QCtrProveedores->setEnabled( TRUE );
    layout26->addWidget( QCtrProveedores );
    layout65->addLayout( layout26 );

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    layout39 = new QVBoxLayout( 0, 0, 6, "layout39"); 

    textLabel8 = new QLabel( this, "textLabel8" );
    layout39->addWidget( textLabel8 );

    QLERazonSocial = new QLineEdit( this, "QLERazonSocial" );
    QLERazonSocial->setEnabled( TRUE );
    layout39->addWidget( QLERazonSocial );
    layout47->addLayout( layout39 );
    layout65->addLayout( layout47 );

    MantenimientoProductosLayout->addMultiCellLayout( layout65, 0, 0, 0, 4 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout42->addWidget( textLabel5 );

    QLEModelo = new QLineEdit( this, "QLEModelo" );
    QLEModelo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEModelo->sizePolicy().hasHeightForWidth() ) );
    layout42->addWidget( QLEModelo );

    MantenimientoProductosLayout->addLayout( layout42, 2, 0 );

    layout42_2_2 = new QVBoxLayout( 0, 0, 6, "layout42_2_2"); 

    textLabel5_2_2 = new QLabel( this, "textLabel5_2_2" );
    layout42_2_2->addWidget( textLabel5_2_2 );

    QLEIva = new QLineEdit( this, "QLEIva" );
    QLEIva->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEIva->sizePolicy().hasHeightForWidth() ) );
    layout42_2_2->addWidget( QLEIva );

    MantenimientoProductosLayout->addLayout( layout42_2_2, 2, 4 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel7 = new QLabel( this, "textLabel7" );
    layout25->addWidget( textLabel7 );

    QCtrDepartamentos = new QCtrlDepartamentosSS( this, "QCtrDepartamentos" );
    QCtrDepartamentos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrDepartamentos->sizePolicy().hasHeightForWidth() ) );
    layout25->addWidget( QCtrDepartamentos );

    MantenimientoProductosLayout->addLayout( layout25, 2, 1 );

    layout42_2 = new QVBoxLayout( 0, 0, 6, "layout42_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    layout42_2->addWidget( textLabel5_2 );

    QLECosto = new QLineEdit( this, "QLECosto" );
    QLECosto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLECosto->sizePolicy().hasHeightForWidth() ) );
    layout42_2->addWidget( QLECosto );

    MantenimientoProductosLayout->addLayout( layout42_2, 2, 2 );

    layout42_2_4 = new QVBoxLayout( 0, 0, 6, "layout42_2_4"); 

    textLabel5_2_4 = new QLabel( this, "textLabel5_2_4" );
    layout42_2_4->addWidget( textLabel5_2_4 );

    QLECostoNeto = new QLineEdit( this, "QLECostoNeto" );
    QLECostoNeto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLECostoNeto->sizePolicy().hasHeightForWidth() ) );
    QLECostoNeto->setReadOnly( TRUE );
    layout42_2_4->addWidget( QLECostoNeto );

    MantenimientoProductosLayout->addLayout( layout42_2_4, 2, 3 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );

    MantenimientoProductosLayout->addMultiCellWidget( QPBRegistrar, 5, 5, 0, 4 );

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    layout28 = new QVBoxLayout( 0, 0, 6, "layout28"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout28->addWidget( textLabel1_3 );

    QLEDescuento1 = new QLineEdit( this, "QLEDescuento1" );
    layout28->addWidget( QLEDescuento1 );
    layout33->addLayout( layout28 );

    layout28_2 = new QVBoxLayout( 0, 0, 6, "layout28_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout28_2->addWidget( textLabel1_2_2 );

    QLEDescuento2 = new QLineEdit( this, "QLEDescuento2" );
    layout28_2->addWidget( QLEDescuento2 );
    layout33->addLayout( layout28_2 );

    layout28_3 = new QVBoxLayout( 0, 0, 6, "layout28_3"); 

    textLabel1_3_2 = new QLabel( this, "textLabel1_3_2" );
    layout28_3->addWidget( textLabel1_3_2 );

    QLEDescuento3 = new QLineEdit( this, "QLEDescuento3" );
    layout28_3->addWidget( QLEDescuento3 );
    layout33->addLayout( layout28_3 );

    layout28_2_2 = new QVBoxLayout( 0, 0, 6, "layout28_2_2"); 

    textLabel1_2_2_2 = new QLabel( this, "textLabel1_2_2_2" );
    layout28_2_2->addWidget( textLabel1_2_2_2 );

    QLEDescuento4 = new QLineEdit( this, "QLEDescuento4" );
    layout28_2_2->addWidget( QLEDescuento4 );
    layout33->addLayout( layout28_2_2 );

    MantenimientoProductosLayout->addMultiCellLayout( layout33, 3, 3, 0, 4 );

    layout41_2 = new QVBoxLayout( 0, 0, 6, "layout41_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout41_2->addWidget( textLabel4_2 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout41_2->addWidget( QLENombre );

    MantenimientoProductosLayout->addMultiCellLayout( layout41_2, 1, 1, 2, 4 );

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout23->addWidget( textLabel1_2 );

    QCtrProductos = new QCtrlProductosSS( this, "QCtrProductos" );
    layout23->addWidget( QCtrProductos );

    MantenimientoProductosLayout->addMultiCellLayout( layout23, 1, 1, 0, 1 );

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    layout42_2_3_2 = new QVBoxLayout( 0, 0, 6, "layout42_2_3_2"); 

    textLabel5_2_3_2 = new QLabel( this, "textLabel5_2_3_2" );
    layout42_2_3_2->addWidget( textLabel5_2_3_2 );

    QLEPrecio = new QLineEdit( this, "QLEPrecio" );
    QLEPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEPrecio->sizePolicy().hasHeightForWidth() ) );
    layout42_2_3_2->addWidget( QLEPrecio );
    layout29->addLayout( layout42_2_3_2 );

    layout42_2_3 = new QVBoxLayout( 0, 0, 6, "layout42_2_3"); 

    textLabel5_2_3 = new QLabel( this, "textLabel5_2_3" );
    layout42_2_3->addWidget( textLabel5_2_3 );

    QLEPorUtilidadPrecio = new QLineEdit( this, "QLEPorUtilidadPrecio" );
    QLEPorUtilidadPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEPorUtilidadPrecio->sizePolicy().hasHeightForWidth() ) );
    QLEPorUtilidadPrecio->setReadOnly( TRUE );
    layout42_2_3->addWidget( QLEPorUtilidadPrecio );
    layout29->addLayout( layout42_2_3 );

    layout42_2_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout42_2_3_2_2"); 

    textLabel5_2_3_2_2 = new QLabel( this, "textLabel5_2_3_2_2" );
    layout42_2_3_2_2->addWidget( textLabel5_2_3_2_2 );

    QLEPrecioForaneo = new QLineEdit( this, "QLEPrecioForaneo" );
    QLEPrecioForaneo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEPrecioForaneo->sizePolicy().hasHeightForWidth() ) );
    layout42_2_3_2_2->addWidget( QLEPrecioForaneo );
    layout29->addLayout( layout42_2_3_2_2 );

    layout42_2_3_3 = new QVBoxLayout( 0, 0, 6, "layout42_2_3_3"); 

    textLabel5_2_3_3 = new QLabel( this, "textLabel5_2_3_3" );
    layout42_2_3_3->addWidget( textLabel5_2_3_3 );

    QLEPorUtilidadForaneo = new QLineEdit( this, "QLEPorUtilidadForaneo" );
    QLEPorUtilidadForaneo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEPorUtilidadForaneo->sizePolicy().hasHeightForWidth() ) );
    layout42_2_3_3->addWidget( QLEPorUtilidadForaneo );
    layout29->addLayout( layout42_2_3_3 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout29->addItem( spacer1 );

    MantenimientoProductosLayout->addMultiCellLayout( layout29, 4, 4, 0, 3 );
    languageChange();
    resize( QSize(543, 277).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MantenimientoProductos::~MantenimientoProductos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MantenimientoProductos::languageChange()
{
    setCaption( tr( "Mantenimiento Productos" ) );
    textLabel2->setText( tr( "Proveedor:" ) );
    textLabel8->setText( tr( "Razon Social:" ) );
    textLabel5->setText( tr( "Modelo:" ) );
    textLabel5_2_2->setText( tr( "Iva" ) );
    QLEIva->setText( tr( "15" ) );
    textLabel7->setText( tr( "Departamento:" ) );
    textLabel5_2->setText( tr( "Costo" ) );
    QLECosto->setText( tr( "1.00" ) );
    textLabel5_2_4->setText( tr( "Costo Neto" ) );
    QPBRegistrar->setText( tr( "Registra Producto" ) );
    textLabel1_3->setText( tr( "Descuento 1" ) );
    QLEDescuento1->setText( tr( "0.00" ) );
    textLabel1_2_2->setText( tr( "Descuento 2" ) );
    QLEDescuento2->setText( tr( "0.00" ) );
    textLabel1_3_2->setText( tr( "Descuento 3" ) );
    QLEDescuento3->setText( tr( "0.00" ) );
    textLabel1_2_2_2->setText( tr( "Descuento 4" ) );
    QLEDescuento4->setText( tr( "0.00" ) );
    textLabel4_2->setText( tr( "Nombre Producto:" ) );
    textLabel1_2->setText( tr( "Numero Producto" ) );
    textLabel5_2_3_2->setText( tr( "Precio" ) );
    QLEPrecio->setText( tr( "1.00" ) );
    textLabel5_2_3->setText( tr( "%Utilidad" ) );
    textLabel5_2_3_2_2->setText( tr( "Precio Foraneo" ) );
    textLabel5_2_3_3->setText( tr( "%Utilidad" ) );
}

