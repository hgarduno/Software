/****************************************************************************
** Form implementation generated from reading ui file 'UI/ClienteAlumno.ui'
**
** Created: Wed Apr 10 20:52:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ClienteAlumno.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <QCtrlEscuelasSE.h>
#include <QCtrlClientesMayoreo.h>
#include <qtextedit.h>
#include <QCtrlOrdenesFavoritas.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlEscuelasSE.h"
#include "QCtrlClientesMayoreo.h"
#include "QCtrlOrdenesFavoritas.h"

/*
 *  Constructs a ClienteAlumno as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ClienteAlumno::ClienteAlumno( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ClienteAlumno" );
    setEnabled( TRUE );
    ClienteAlumnoLayout = new QGridLayout( this, 1, 1, 11, 6, "ClienteAlumnoLayout"); 

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QPBOtrosMovimientos = new QPushButton( this, "QPBOtrosMovimientos" );
    QPBOtrosMovimientos->setEnabled( FALSE );
    QPBOtrosMovimientos->setAutoDefault( FALSE );
    layout8->addWidget( QPBOtrosMovimientos );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout8->addWidget( QPBAceptar );

    QPBNuevaOrden = new QPushButton( this, "QPBNuevaOrden" );
    QPBNuevaOrden->setEnabled( FALSE );
    QPBNuevaOrden->setAutoDefault( FALSE );
    layout8->addWidget( QPBNuevaOrden );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout8->addWidget( QPBCancelar );

    ClienteAlumnoLayout->addLayout( layout8, 4, 0 );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel1_2 );

    QLECliente = new QLineEdit( this, "QLECliente" );
    QLECliente->setReadOnly( TRUE );
    layout3->addWidget( QLECliente );
    layout5->addLayout( layout3 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( textLabel1_2_2 );

    QLEEscuela = new QLineEdit( this, "QLEEscuela" );
    QLEEscuela->setReadOnly( TRUE );
    layout3_2->addWidget( QLEEscuela );
    layout5->addLayout( layout3_2 );

    ClienteAlumnoLayout->addLayout( layout5, 1, 0 );

    QBGTipoOrden = new QButtonGroup( this, "QBGTipoOrden" );
    QBGTipoOrden->setEnabled( FALSE );
    QBGTipoOrden->setColumnLayout(0, Qt::Vertical );
    QBGTipoOrden->layout()->setSpacing( 6 );
    QBGTipoOrden->layout()->setMargin( 11 );
    QBGTipoOrdenLayout = new QGridLayout( QBGTipoOrden->layout() );
    QBGTipoOrdenLayout->setAlignment( Qt::AlignTop );

    QRBApartado = new QRadioButton( QBGTipoOrden, "QRBApartado" );
    QBGTipoOrden->insert( QRBApartado, 2 );

    QBGTipoOrdenLayout->addWidget( QRBApartado, 0, 0 );

    QRBCotizacion = new QRadioButton( QBGTipoOrden, "QRBCotizacion" );
    QBGTipoOrden->insert( QRBCotizacion, 1 );

    QBGTipoOrdenLayout->addWidget( QRBCotizacion, 1, 0 );

    radioButton5 = new QRadioButton( QBGTipoOrden, "radioButton5" );
    QBGTipoOrden->insert( radioButton5, 100 );

    QBGTipoOrdenLayout->addWidget( radioButton5, 2, 0 );

    radioButton12 = new QRadioButton( QBGTipoOrden, "radioButton12" );
    QBGTipoOrden->insert( radioButton12, 109 );

    QBGTipoOrdenLayout->addWidget( radioButton12, 3, 0 );

    QPBOrdenActual = new QRadioButton( QBGTipoOrden, "QPBOrdenActual" );
    QBGTipoOrden->insert( QPBOrdenActual, 103 );

    QBGTipoOrdenLayout->addWidget( QPBOrdenActual, 4, 0 );

    QRBCierraApartado = new QRadioButton( QBGTipoOrden, "QRBCierraApartado" );
    QBGTipoOrden->insert( QRBCierraApartado, 101 );

    QBGTipoOrdenLayout->addWidget( QRBCierraApartado, 5, 0 );

    radioButton4 = new QRadioButton( QBGTipoOrden, "radioButton4" );
    QBGTipoOrden->insert( radioButton4, 102 );

    QBGTipoOrdenLayout->addWidget( radioButton4, 6, 0 );

    radioButton7 = new QRadioButton( QBGTipoOrden, "radioButton7" );
    QBGTipoOrden->insert( radioButton7, 104 );

    QBGTipoOrdenLayout->addWidget( radioButton7, 7, 0 );

    radioButton8 = new QRadioButton( QBGTipoOrden, "radioButton8" );
    QBGTipoOrden->insert( radioButton8, 105 );

    QBGTipoOrdenLayout->addWidget( radioButton8, 8, 0 );

    radioButton8_2 = new QRadioButton( QBGTipoOrden, "radioButton8_2" );
    radioButton8_2->setEnabled( FALSE );
    QBGTipoOrden->insert( radioButton8_2, 106 );

    QBGTipoOrdenLayout->addWidget( radioButton8_2, 9, 0 );

    radioButton10 = new QRadioButton( QBGTipoOrden, "radioButton10" );
    QBGTipoOrden->insert( radioButton10, 107 );

    QBGTipoOrdenLayout->addWidget( radioButton10, 10, 0 );

    radioButton11 = new QRadioButton( QBGTipoOrden, "radioButton11" );
    QBGTipoOrden->insert( radioButton11, 108 );

    QBGTipoOrdenLayout->addWidget( radioButton11, 11, 0 );

    radioButton13 = new QRadioButton( QBGTipoOrden, "radioButton13" );
    QBGTipoOrden->insert( radioButton13, 111 );

    QBGTipoOrdenLayout->addWidget( radioButton13, 12, 0 );

    ClienteAlumnoLayout->addWidget( QBGTipoOrden, 3, 0 );

    layout41 = new QHBoxLayout( 0, 0, 6, "layout41"); 

    layout40 = new QVBoxLayout( 0, 0, 6, "layout40"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrEscuelas = new QCtrlEscuelasSE( this, "QCtrEscuelas" );
    QCtrEscuelas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrEscuelas->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrEscuelas );
    layout40->addLayout( layout1 );

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout8_2->addWidget( textLabel1_3 );

    QCtrClientesMayoreo = new QCtrlClientesMayoreo( this, "QCtrClientesMayoreo" );
    QCtrClientesMayoreo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrClientesMayoreo->sizePolicy().hasHeightForWidth() ) );
    layout8_2->addWidget( QCtrClientesMayoreo );
    layout40->addLayout( layout8_2 );
    layout41->addLayout( layout40 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    layout11->addWidget( textLabel1_4 );

    QTEDesVenta = new QTextEdit( this, "QTEDesVenta" );
    QTEDesVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDesVenta->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( QTEDesVenta );
    layout41->addLayout( layout11 );

    ClienteAlumnoLayout->addLayout( layout41, 0, 0 );

    QCtrOrdenesFavoritas = new QCtrlOrdenesFavoritas( this, "QCtrOrdenesFavoritas" );
    QCtrOrdenesFavoritas->setMinimumSize( QSize( 0, 50 ) );

    ClienteAlumnoLayout->addWidget( QCtrOrdenesFavoritas, 2, 0 );
    languageChange();
    resize( QSize(557, 555).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( QRBApartado, QRBCotizacion );
    setTabOrder( QRBCotizacion, radioButton5 );
    setTabOrder( radioButton5, QPBOrdenActual );
    setTabOrder( QPBOrdenActual, QRBCierraApartado );
    setTabOrder( QRBCierraApartado, radioButton4 );
    setTabOrder( radioButton4, radioButton7 );
    setTabOrder( radioButton7, QPBOtrosMovimientos );
    setTabOrder( QPBOtrosMovimientos, QPBAceptar );
    setTabOrder( QPBAceptar, QPBNuevaOrden );
    setTabOrder( QPBNuevaOrden, QPBCancelar );
    setTabOrder( QPBCancelar, QLECliente );
    setTabOrder( QLECliente, QLEEscuela );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ClienteAlumno::~ClienteAlumno()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ClienteAlumno::languageChange()
{
    setCaption( tr( "Datos Alumno" ) );
    QPBOtrosMovimientos->setText( tr( "Otros Movimientos" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBNuevaOrden->setText( tr( "&Nueva Orden" ) );
    QPBNuevaOrden->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel1_2->setText( tr( "Cliente" ) );
    textLabel1_2_2->setText( tr( "Escuela" ) );
    QBGTipoOrden->setTitle( tr( "Tipo de Orden" ) );
    QRBApartado->setText( tr( "Apartado" ) );
    QRBCotizacion->setText( tr( "Cotizacion" ) );
    radioButton5->setText( tr( "Vende Orden, Cotizacion , Apartado" ) );
    radioButton12->setText( tr( "Modificar Cotizacion" ) );
    QPBOrdenActual->setText( tr( "Orden Actual" ) );
    QRBCierraApartado->setText( tr( "Entrega Apartado" ) );
    radioButton4->setText( tr( "Estados Pedido" ) );
    radioButton7->setText( tr( "Recupera Orden Impresa" ) );
    radioButton8->setText( tr( "Programacion Placas" ) );
    radioButton8_2->setText( tr( "Entrega Placa" ) );
    radioButton10->setText( tr( "Material Area Diseno" ) );
    radioButton11->setText( tr( "Donacion" ) );
    radioButton13->setText( tr( "Registrar Practica" ) );
    textLabel1->setText( tr( "Escuelas" ) );
    textLabel1_3->setText( tr( "Clientes Mayoreo" ) );
    textLabel1_4->setText( tr( "Descripcion Venta" ) );
    QCtrOrdenesFavoritas->setTitle( QString::null );
}

