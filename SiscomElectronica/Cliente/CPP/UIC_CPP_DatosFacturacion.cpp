/****************************************************************************
** Form implementation generated from reading ui file 'UI/DatosFacturacion.ui'
**
** Created: Wed Apr 10 20:52:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DatosFacturacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <QCtrlFormaPagoSat.h>
#include <QCtrlMetodoPagoSat.h>
#include <QCtrlUsoCFDISat.h>
#include <QCtrlRFCs.h>
#include <QCtrlRegimenFiscal.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFormaPagoSat.h"
#include "QCtrlMetodoPagoSat.h"
#include "QCtrlUsoCFDISat.h"
#include "QCtrlRFCs.h"
#include "QCtrlRegimenFiscal.h"

/*
 *  Constructs a DatosFacturacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DatosFacturacion::DatosFacturacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "DatosFacturacion" );
    DatosFacturacionLayout = new QGridLayout( this, 1, 1, 11, 6, "DatosFacturacionLayout"); 

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout19_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_2"); 

    textLabel6_2_2 = new QLabel( this, "textLabel6_2_2" );
    layout19_2_2->addWidget( textLabel6_2_2 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    QLENombre->setEnabled( FALSE );
    layout19_2_2->addWidget( QLENombre );
    layout25->addLayout( layout19_2_2 );

    layout19_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_2_2"); 

    textLabel6_2_2_2 = new QLabel( this, "textLabel6_2_2_2" );
    layout19_2_2_2->addWidget( textLabel6_2_2_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    QLEAPaterno->setEnabled( FALSE );
    layout19_2_2_2->addWidget( QLEAPaterno );
    layout25->addLayout( layout19_2_2_2 );

    layout19_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_2_2_2"); 

    textLabel6_2_2_2_2 = new QLabel( this, "textLabel6_2_2_2_2" );
    layout19_2_2_2_2->addWidget( textLabel6_2_2_2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    QLEAMaterno->setEnabled( FALSE );
    layout19_2_2_2_2->addWidget( QLEAMaterno );
    layout25->addLayout( layout19_2_2_2_2 );

    DatosFacturacionLayout->addMultiCellLayout( layout25, 1, 1, 0, 4 );

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    layout19_3 = new QVBoxLayout( 0, 0, 6, "layout19_3"); 

    textLabel6_3 = new QLabel( this, "textLabel6_3" );
    layout19_3->addWidget( textLabel6_3 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    QLECalle->setEnabled( FALSE );
    layout19_3->addWidget( QLECalle );
    layout35->addLayout( layout19_3 );

    layout19_3_2 = new QVBoxLayout( 0, 0, 6, "layout19_3_2"); 

    textLabel6_3_2 = new QLabel( this, "textLabel6_3_2" );
    textLabel6_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6_3_2->sizePolicy().hasHeightForWidth() ) );
    layout19_3_2->addWidget( textLabel6_3_2 );

    QLENumero = new QLineEdit( this, "QLENumero" );
    QLENumero->setEnabled( FALSE );
    QLENumero->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumero->sizePolicy().hasHeightForWidth() ) );
    layout19_3_2->addWidget( QLENumero );
    layout35->addLayout( layout19_3_2 );

    layout19_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_3_2_2"); 

    textLabel6_3_2_2 = new QLabel( this, "textLabel6_3_2_2" );
    textLabel6_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout19_3_2_2->addWidget( textLabel6_3_2_2 );

    QLENumeroInt = new QLineEdit( this, "QLENumeroInt" );
    QLENumeroInt->setEnabled( FALSE );
    QLENumeroInt->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumeroInt->sizePolicy().hasHeightForWidth() ) );
    layout19_3_2_2->addWidget( QLENumeroInt );
    layout35->addLayout( layout19_3_2_2 );

    DatosFacturacionLayout->addMultiCellLayout( layout35, 2, 2, 0, 4 );

    layout19_3_3_2 = new QVBoxLayout( 0, 0, 6, "layout19_3_3_2"); 

    textLabel6_3_3_2 = new QLabel( this, "textLabel6_3_3_2" );
    textLabel6_3_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel6_3_3_2->sizePolicy().hasHeightForWidth() ) );
    layout19_3_3_2->addWidget( textLabel6_3_3_2 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    QLEColonia->setEnabled( FALSE );
    layout19_3_3_2->addWidget( QLEColonia );

    DatosFacturacionLayout->addMultiCellLayout( layout19_3_3_2, 3, 3, 1, 2 );

    layout19_3_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_3_3_2_2"); 

    textLabel6_3_3_2_2 = new QLabel( this, "textLabel6_3_3_2_2" );
    textLabel6_3_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6_3_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout19_3_3_2_2->addWidget( textLabel6_3_3_2_2 );

    QLECP = new QLineEdit( this, "QLECP" );
    QLECP->setEnabled( FALSE );
    QLECP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECP->sizePolicy().hasHeightForWidth() ) );
    layout19_3_3_2_2->addWidget( QLECP );

    DatosFacturacionLayout->addLayout( layout19_3_3_2_2, 3, 4 );

    layout19_3_3 = new QVBoxLayout( 0, 0, 6, "layout19_3_3"); 

    textLabel6_3_3 = new QLabel( this, "textLabel6_3_3" );
    layout19_3_3->addWidget( textLabel6_3_3 );

    QLEDelegacion = new QLineEdit( this, "QLEDelegacion" );
    QLEDelegacion->setEnabled( FALSE );
    QLEDelegacion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEDelegacion->sizePolicy().hasHeightForWidth() ) );
    layout19_3_3->addWidget( QLEDelegacion );

    DatosFacturacionLayout->addLayout( layout19_3_3, 3, 0 );

    layout19_3_3_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout19_3_3_2_2_3"); 

    textLabel6_3_3_2_2_3 = new QLabel( this, "textLabel6_3_3_2_2_3" );
    textLabel6_3_3_2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6_3_3_2_2_3->sizePolicy().hasHeightForWidth() ) );
    layout19_3_3_2_2_3->addWidget( textLabel6_3_3_2_2_3 );

    QLEEstado = new QLineEdit( this, "QLEEstado" );
    QLEEstado->setEnabled( FALSE );
    QLEEstado->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEEstado->sizePolicy().hasHeightForWidth() ) );
    layout19_3_3_2_2_3->addWidget( QLEEstado );

    DatosFacturacionLayout->addLayout( layout19_3_3_2_2_3, 3, 3 );

    layout39 = new QHBoxLayout( 0, 0, 6, "layout39"); 

    layout19_3_3_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_3_3_2_2_2"); 

    textLabel6_3_3_2_2_2 = new QLabel( this, "textLabel6_3_3_2_2_2" );
    layout19_3_3_2_2_2->addWidget( textLabel6_3_3_2_2_2 );

    QLECorreo = new QLineEdit( this, "QLECorreo" );
    QLECorreo->setEnabled( TRUE );
    layout19_3_3_2_2_2->addWidget( QLECorreo );
    layout39->addLayout( layout19_3_3_2_2_2 );

    layout19_3_3_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_3_3_2_2_2_2"); 

    textLabel6_3_3_2_2_2_2 = new QLabel( this, "textLabel6_3_3_2_2_2_2" );
    layout19_3_3_2_2_2_2->addWidget( textLabel6_3_3_2_2_2_2 );

    QLECorreoOtraVez = new QLineEdit( this, "QLECorreoOtraVez" );
    QLECorreoOtraVez->setEnabled( TRUE );
    layout19_3_3_2_2_2_2->addWidget( QLECorreoOtraVez );
    layout39->addLayout( layout19_3_3_2_2_2_2 );

    DatosFacturacionLayout->addMultiCellLayout( layout39, 4, 4, 0, 1 );

    layout19_3_3_2_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_3_3_2_2_2_2_2"); 

    textLabel6_3_3_2_2_2_2_2 = new QLabel( this, "textLabel6_3_3_2_2_2_2_2" );
    layout19_3_3_2_2_2_2_2->addWidget( textLabel6_3_3_2_2_2_2_2 );

    QLETelefono = new QLineEdit( this, "QLETelefono" );
    QLETelefono->setEnabled( FALSE );
    layout19_3_3_2_2_2_2_2->addWidget( QLETelefono );

    DatosFacturacionLayout->addMultiCellLayout( layout19_3_3_2_2_2_2_2, 4, 4, 2, 4 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    QPBAgregarCorreo = new QPushButton( this, "QPBAgregarCorreo" );
    QPBAgregarCorreo->setEnabled( FALSE );
    QPBAgregarCorreo->setAutoDefault( FALSE );
    layout20->addWidget( QPBAgregarCorreo );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    QPBRegistrar->setAutoDefault( FALSE );
    layout20->addWidget( QPBRegistrar );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout20->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout20->addWidget( QPBCancelar );

    DatosFacturacionLayout->addMultiCellLayout( layout20, 6, 6, 0, 4 );

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout21->addWidget( textLabel1 );

    QTCorreos = new QTable( this, "QTCorreos" );
    QTCorreos->setNumCols( QTCorreos->numCols() + 1 );
    QTCorreos->horizontalHeader()->setLabel( QTCorreos->numCols() - 1, tr( "Correo" ) );
    QTCorreos->setNumRows( 0 );
    QTCorreos->setNumCols( 1 );
    QTCorreos->setReadOnly( TRUE );
    layout21->addWidget( QTCorreos );
    layout32->addLayout( layout21 );

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    layout30 = new QVBoxLayout( 0, 0, 6, "layout30"); 

    layout29 = new QVBoxLayout( 0, 0, 6, "layout29"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout29->addWidget( textLabel1_2 );

    QCtrFormaPagoSat = new QCtrlFormaPagoSat( this, "QCtrFormaPagoSat" );
    QCtrFormaPagoSat->setEnabled( TRUE );
    QCtrFormaPagoSat->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrFormaPagoSat->sizePolicy().hasHeightForWidth() ) );
    layout29->addWidget( QCtrFormaPagoSat );

    QLEFormaPago = new QLineEdit( this, "QLEFormaPago" );
    layout29->addWidget( QLEFormaPago );
    layout30->addLayout( layout29 );

    layout28 = new QVBoxLayout( 0, 0, 6, "layout28"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout28->addWidget( textLabel1_3 );

    QCtrMetodoPago = new QCtrlMetodoPagoSat( this, "QCtrMetodoPago" );
    QCtrMetodoPago->setEnabled( TRUE );
    QCtrMetodoPago->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrMetodoPago->sizePolicy().hasHeightForWidth() ) );
    layout28->addWidget( QCtrMetodoPago );

    QLEMetodoPago = new QLineEdit( this, "QLEMetodoPago" );
    layout28->addWidget( QLEMetodoPago );
    layout30->addLayout( layout28 );

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout27->addWidget( textLabel2 );

    QCtrUsoCFDI = new QCtrlUsoCFDISat( this, "QCtrUsoCFDI" );
    QCtrUsoCFDI->setEnabled( TRUE );
    layout27->addWidget( QCtrUsoCFDI );

    QLEUsoFactura = new QLineEdit( this, "QLEUsoFactura" );
    layout27->addWidget( QLEUsoFactura );
    layout30->addLayout( layout27 );
    layout31->addLayout( layout30 );
    layout32->addLayout( layout31 );

    DatosFacturacionLayout->addMultiCellLayout( layout32, 5, 5, 0, 4 );

    layout31_2 = new QHBoxLayout( 0, 0, 6, "layout31_2"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout22->addWidget( textLabel6 );

    QCtrRFCs = new QCtrlRFCs( this, "QCtrRFCs" );
    QCtrRFCs->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrRFCs->sizePolicy().hasHeightForWidth() ) );
    layout22->addWidget( QCtrRFCs );
    layout31_2->addLayout( layout22 );

    layout19_2 = new QVBoxLayout( 0, 0, 6, "layout19_2"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    textLabel6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel6_2->sizePolicy().hasHeightForWidth() ) );
    layout19_2->addWidget( textLabel6_2 );

    QLERazonSocial = new QLineEdit( this, "QLERazonSocial" );
    QLERazonSocial->setEnabled( FALSE );
    layout19_2->addWidget( QLERazonSocial );
    layout31_2->addLayout( layout19_2 );

    layout29_2 = new QVBoxLayout( 0, 0, 6, "layout29_2"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout29_2->addWidget( textLabel1_4 );

    QCtrRegimenFiscal = new QCtrlRegimenFiscal( this, "QCtrRegimenFiscal" );
    QCtrRegimenFiscal->setEnabled( FALSE );
    QCtrRegimenFiscal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrRegimenFiscal->sizePolicy().hasHeightForWidth() ) );
    layout29_2->addWidget( QCtrRegimenFiscal );
    layout31_2->addLayout( layout29_2 );

    DatosFacturacionLayout->addMultiCellLayout( layout31_2, 0, 0, 0, 4 );
    languageChange();
    resize( QSize(889, 461).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DatosFacturacion::~DatosFacturacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DatosFacturacion::languageChange()
{
    setCaption( tr( "Datos Facturacion" ) );
    textLabel6_2_2->setText( tr( "Nombre" ) );
    textLabel6_2_2_2->setText( tr( "Apellido Paterno" ) );
    textLabel6_2_2_2_2->setText( tr( "Apellido Materno" ) );
    textLabel6_3->setText( tr( "Calle" ) );
    textLabel6_3_2->setText( tr( "Numero" ) );
    textLabel6_3_2_2->setText( tr( "Interior" ) );
    textLabel6_3_3_2->setText( tr( "Colonia" ) );
    textLabel6_3_3_2_2->setText( tr( "Codigo Postal" ) );
    textLabel6_3_3->setText( tr( "Delegacion Municipio" ) );
    textLabel6_3_3_2_2_3->setText( tr( "Estado" ) );
    textLabel6_3_3_2_2_2->setText( tr( "Correo Electronico" ) );
    textLabel6_3_3_2_2_2_2->setText( tr( "Correo Electronico Otra Vez" ) );
    textLabel6_3_3_2_2_2_2_2->setText( tr( "Telefono" ) );
    QPBAgregarCorreo->setText( tr( "Agregar Correo" ) );
    QPBRegistrar->setText( tr( "Registrar Datos" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Correos" ) );
    QTCorreos->horizontalHeader()->setLabel( 0, tr( "Correo" ) );
    textLabel1_2->setText( tr( "Formas De Pago" ) );
    textLabel1_3->setText( tr( "Metodo Pago" ) );
    textLabel2->setText( tr( "Uso Factura" ) );
    textLabel6->setText( tr( "RFC" ) );
    textLabel6_2->setText( tr( "Razon Social" ) );
    textLabel1_4->setText( tr( "Regimen Fiscal" ) );
}

