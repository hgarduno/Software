/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorProveedores.ui'
**
** Created: lun abr 1 19:07:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorProveedores.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ManejadorProveedores as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorProveedores::ManejadorProveedores( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorProveedores" );
    ManejadorProveedoresLayout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorProveedoresLayout"); 

    layout121 = new QVBoxLayout( 0, 0, 6, "layout121"); 

    textLabel18 = new QLabel( this, "textLabel18" );
    layout121->addWidget( textLabel18 );

    QLERazonSocial = new QLineEdit( this, "QLERazonSocial" );
    QLERazonSocial->setMinimumSize( QSize( 200, 0 ) );
    layout121->addWidget( QLERazonSocial );

    ManejadorProveedoresLayout->addMultiCellLayout( layout121, 0, 0, 0, 1 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel7 = new QLabel( this, "textLabel7" );
    layout19->addWidget( textLabel7 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    QLERFC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLERFC->sizePolicy().hasHeightForWidth() ) );
    QLERFC->setMinimumSize( QSize( 100, 0 ) );
    QLERFC->setMaximumSize( QSize( 100, 32767 ) );
    QLERFC->setReadOnly( FALSE );
    layout19->addWidget( QLERFC );

    ManejadorProveedoresLayout->addLayout( layout19, 0, 2 );

    textLabel19 = new QLabel( this, "textLabel19" );

    ManejadorProveedoresLayout->addMultiCellWidget( textLabel19, 1, 1, 0, 1 );

    layout138 = new QVBoxLayout( 0, 0, 6, "layout138"); 

    textLabel19_2 = new QLabel( this, "textLabel19_2" );
    layout138->addWidget( textLabel19_2 );

    QTDirecciones = new QTable( this, "QTDirecciones" );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Direccion" ) );
    QTDirecciones->setNumRows( 0 );
    QTDirecciones->setNumCols( 1 );
    layout138->addWidget( QTDirecciones );

    ManejadorProveedoresLayout->addMultiCellLayout( layout138, 3, 3, 0, 3 );

    layout140 = new QHBoxLayout( 0, 0, 6, "layout140"); 

    layout136 = new QVBoxLayout( 0, 0, 6, "layout136"); 

    textLabel20_2 = new QLabel( this, "textLabel20_2" );
    layout136->addWidget( textLabel20_2 );

    QTTelefonos = new QTable( this, "QTTelefonos" );
    QTTelefonos->setNumCols( QTTelefonos->numCols() + 1 );
    QTTelefonos->horizontalHeader()->setLabel( QTTelefonos->numCols() - 1, tr( "Telefono" ) );
    QTTelefonos->setNumRows( 0 );
    QTTelefonos->setNumCols( 1 );
    layout136->addWidget( QTTelefonos );
    layout140->addLayout( layout136 );

    layout137 = new QVBoxLayout( 0, 0, 6, "layout137"); 

    textLabel20 = new QLabel( this, "textLabel20" );
    layout137->addWidget( textLabel20 );

    QTContactos = new QTable( this, "QTContactos" );
    QTContactos->setNumCols( QTContactos->numCols() + 1 );
    QTContactos->horizontalHeader()->setLabel( QTContactos->numCols() - 1, tr( "Contacto" ) );
    QTContactos->setNumRows( 0 );
    QTContactos->setNumCols( 1 );
    layout137->addWidget( QTContactos );
    layout140->addLayout( layout137 );

    ManejadorProveedoresLayout->addMultiCellLayout( layout140, 4, 4, 0, 3 );

    layout146 = new QVBoxLayout( 0, 0, 6, "layout146"); 

    layout141 = new QVBoxLayout( 0, 0, 6, "layout141"); 

    QPBAnexarDireccion = new QPushButton( this, "QPBAnexarDireccion" );
    QPBAnexarDireccion->setEnabled( FALSE );
    layout141->addWidget( QPBAnexarDireccion );

    QPBAnexarTelefono = new QPushButton( this, "QPBAnexarTelefono" );
    QPBAnexarTelefono->setEnabled( FALSE );
    layout141->addWidget( QPBAnexarTelefono );

    QPBAnexarContacto = new QPushButton( this, "QPBAnexarContacto" );
    QPBAnexarContacto->setEnabled( FALSE );
    layout141->addWidget( QPBAnexarContacto );
    layout146->addLayout( layout141 );
    spacer8_3 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred );
    layout146->addItem( spacer8_3 );

    ManejadorProveedoresLayout->addLayout( layout146, 5, 0 );

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    layout6_4 = new QVBoxLayout( 0, 0, 6, "layout6_4"); 

    textLabel3_4 = new QLabel( this, "textLabel3_4" );
    textLabel3_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_4->sizePolicy().hasHeightForWidth() ) );
    layout6_4->addWidget( textLabel3_4 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    QLECalle->setMinimumSize( QSize( 250, 0 ) );
    QLECalle->setMaximumSize( QSize( 1000, 32767 ) );
    layout6_4->addWidget( QLECalle );
    layout32->addLayout( layout6_4 );

    layout11_2 = new QVBoxLayout( 0, 0, 6, "layout11_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( textLabel4_2 );

    QLENumero = new QLineEdit( this, "QLENumero" );
    QLENumero->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLENumero->sizePolicy().hasHeightForWidth() ) );
    QLENumero->setMinimumSize( QSize( 50, 0 ) );
    QLENumero->setMaximumSize( QSize( 50, 32767 ) );
    layout11_2->addWidget( QLENumero );
    layout32->addLayout( layout11_2 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel4 );

    QLECP = new QLineEdit( this, "QLECP" );
    QLECP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLECP->sizePolicy().hasHeightForWidth() ) );
    QLECP->setMinimumSize( QSize( 50, 0 ) );
    QLECP->setMaximumSize( QSize( 50, 32767 ) );
    layout11->addWidget( QLECP );
    layout32->addLayout( layout11 );
    layout36->addLayout( layout32 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout14->addWidget( textLabel5 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    QLEColonia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEColonia->sizePolicy().hasHeightForWidth() ) );
    QLEColonia->setMinimumSize( QSize( 200, 0 ) );
    layout14->addWidget( QLEColonia );
    layout18->addLayout( layout14 );

    layout14_2 = new QVBoxLayout( 0, 0, 6, "layout14_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    layout14_2->addWidget( textLabel5_2 );

    QLEMunicipio = new QLineEdit( this, "QLEMunicipio" );
    QLEMunicipio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEMunicipio->sizePolicy().hasHeightForWidth() ) );
    QLEMunicipio->setMinimumSize( QSize( 200, 0 ) );
    layout14_2->addWidget( QLEMunicipio );
    layout18->addLayout( layout14_2 );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout17->addWidget( textLabel6 );

    QCBEstados = new QComboBox( FALSE, this, "QCBEstados" );
    QCBEstados->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCBEstados->sizePolicy().hasHeightForWidth() ) );
    QCBEstados->setMinimumSize( QSize( 150, 0 ) );
    layout17->addWidget( QCBEstados );
    layout18->addLayout( layout17 );
    layout36->addLayout( layout18 );

    ManejadorProveedoresLayout->addMultiCellLayout( layout36, 2, 2, 0, 2 );
    spacer15 = new QSpacerItem( 74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    ManejadorProveedoresLayout->addItem( spacer15, 2, 3 );

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    QPBRProveedor = new QPushButton( this, "QPBRProveedor" );
    QPBRProveedor->setEnabled( FALSE );
    QPBRProveedor->setMinimumSize( QSize( 0, 70 ) );
    QPBRProveedor->setMaximumSize( QSize( 32767, 70 ) );
    layout25->addWidget( QPBRProveedor );

    QPBCnsProveedor = new QPushButton( this, "QPBCnsProveedor" );
    QPBCnsProveedor->setMinimumSize( QSize( 0, 70 ) );
    QPBCnsProveedor->setMaximumSize( QSize( 32767, 70 ) );
    layout25->addWidget( QPBCnsProveedor );
    layout27->addLayout( layout25 );

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    QPBMDatos = new QPushButton( this, "QPBMDatos" );
    QPBMDatos->setMinimumSize( QSize( 0, 70 ) );
    QPBMDatos->setMaximumSize( QSize( 32767, 70 ) );
    layout26->addWidget( QPBMDatos );

    QPBCnsProveedor_2_2 = new QPushButton( this, "QPBCnsProveedor_2_2" );
    QPBCnsProveedor_2_2->setMinimumSize( QSize( 0, 70 ) );
    QPBCnsProveedor_2_2->setMaximumSize( QSize( 32767, 70 ) );
    layout26->addWidget( QPBCnsProveedor_2_2 );
    layout27->addLayout( layout26 );
    spacer12 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed );
    layout27->addItem( spacer12 );

    ManejadorProveedoresLayout->addLayout( layout27, 5, 1 );
    languageChange();
    resize( QSize(676, 702).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorProveedores::~ManejadorProveedores()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorProveedores::languageChange()
{
    setCaption( tr( "Manejador De Proveedores" ) );
    textLabel18->setText( tr( "Razon Social" ) );
    textLabel7->setText( tr( "RFC" ) );
    textLabel19->setText( tr( "Direccion" ) );
    textLabel19_2->setText( tr( "Direcciones" ) );
    QTDirecciones->horizontalHeader()->setLabel( 0, tr( "Direccion" ) );
    textLabel20_2->setText( tr( "Telefonos" ) );
    QTTelefonos->horizontalHeader()->setLabel( 0, tr( "Telefono" ) );
    textLabel20->setText( tr( "Contactos" ) );
    QTContactos->horizontalHeader()->setLabel( 0, tr( "Contacto" ) );
    QPBAnexarDireccion->setText( tr( "Anexar Direccion" ) );
    QPBAnexarTelefono->setText( tr( "Anexar Telefono" ) );
    QPBAnexarContacto->setText( tr( "Anexar Contacto" ) );
    textLabel3_4->setText( tr( "Calle" ) );
    textLabel4_2->setText( tr( "Numero" ) );
    textLabel4->setText( tr( "Codigo Postal" ) );
    textLabel5->setText( tr( "Colonia" ) );
    textLabel5_2->setText( tr( "Municipio" ) );
    textLabel6->setText( tr( "Estado" ) );
    QPBRProveedor->setText( tr( "Registrar\n"
"Proveedor" ) );
    QPBCnsProveedor->setText( tr( "Consultar\n"
"Datos Proveedor" ) );
    QPBMDatos->setText( tr( "Modificar \n"
"Datos Del Proveedor" ) );
    QPBCnsProveedor_2_2->setText( tr( "Consultar\n"
"Datos Proveedor" ) );
}

