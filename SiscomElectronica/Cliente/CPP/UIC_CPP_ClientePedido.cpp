/****************************************************************************
** Form implementation generated from reading ui file 'UI/ClientePedido.ui'
**
** Created: Fri Dec 22 20:21:52 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ClientePedido.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlEscuelasSE.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlEscuelasSE.h"

/*
 *  Constructs a ClientePedido as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ClientePedido::ClientePedido( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ClientePedido" );
    ClientePedidoLayout = new QGridLayout( this, 1, 1, 11, 6, "ClientePedidoLayout"); 

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    layout45 = new QHBoxLayout( 0, 0, 6, "layout45"); 

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    layout44 = new QHBoxLayout( 0, 0, 6, "layout44"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrEscuelas = new QCtrlEscuelasSE( this, "QCtrEscuelas" );
    QCtrEscuelas->setEnabled( FALSE );
    QCtrEscuelas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)0, 0, 0, QCtrEscuelas->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrEscuelas );
    layout44->addLayout( layout1 );

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout2->addWidget( QLENombre );
    layout28->addLayout( layout2 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( textLabel2_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout2_2->addWidget( QLEAPaterno );
    layout28->addLayout( layout2_2 );

    layout2_3 = new QVBoxLayout( 0, 0, 6, "layout2_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout2_3->addWidget( textLabel2_3 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout2_3->addWidget( QLEAMaterno );
    layout28->addLayout( layout2_3 );
    layout44->addLayout( layout28 );
    layout47->addLayout( layout44 );

    layout46 = new QHBoxLayout( 0, 0, 6, "layout46"); 

    layout2_4 = new QVBoxLayout( 0, 0, 6, "layout2_4"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout2_4->addWidget( textLabel2_4 );

    QLECelular = new QLineEdit( this, "QLECelular" );
    QLECelular->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECelular->sizePolicy().hasHeightForWidth() ) );
    layout2_4->addWidget( QLECelular );
    layout46->addLayout( layout2_4 );

    layout2_4_2 = new QVBoxLayout( 0, 0, 6, "layout2_4_2"); 

    textLabel2_4_2 = new QLabel( this, "textLabel2_4_2" );
    textLabel2_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4_2->sizePolicy().hasHeightForWidth() ) );
    layout2_4_2->addWidget( textLabel2_4_2 );

    QLEReCelular = new QLineEdit( this, "QLEReCelular" );
    QLEReCelular->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEReCelular->sizePolicy().hasHeightForWidth() ) );
    layout2_4_2->addWidget( QLEReCelular );
    layout46->addLayout( layout2_4_2 );
    layout47->addLayout( layout46 );
    layout45->addLayout( layout47 );

    layout43 = new QHBoxLayout( 0, 0, 6, "layout43"); 

    layout2_3_2 = new QVBoxLayout( 0, 0, 6, "layout2_3_2"); 

    textLabel2_3_2 = new QLabel( this, "textLabel2_3_2" );
    textLabel2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3_2->sizePolicy().hasHeightForWidth() ) );
    layout2_3_2->addWidget( textLabel2_3_2 );

    QLEEscuela = new QLineEdit( this, "QLEEscuela" );
    layout2_3_2->addWidget( QLEEscuela );
    layout43->addLayout( layout2_3_2 );

    layout29 = new QVBoxLayout( 0, 0, 6, "layout29"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout29->addWidget( textLabel5 );

    QLENumCliente = new QLineEdit( this, "QLENumCliente" );
    QLENumCliente->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumCliente->sizePolicy().hasHeightForWidth() ) );
    layout29->addWidget( QLENumCliente );
    layout43->addLayout( layout29 );
    layout45->addLayout( layout43 );
    layout48->addLayout( layout45 );

    layout42 = new QHBoxLayout( 0, 0, 6, "layout42"); 

    QPBPuntoEntrega = new QPushButton( this, "QPBPuntoEntrega" );
    QPBPuntoEntrega->setAutoDefault( FALSE );
    layout42->addWidget( QPBPuntoEntrega );

    QPBDireccionCliente = new QPushButton( this, "QPBDireccionCliente" );
    QPBDireccionCliente->setAutoDefault( FALSE );
    layout42->addWidget( QPBDireccionCliente );

    QPBDireccionCliente_2 = new QPushButton( this, "QPBDireccionCliente_2" );
    QPBDireccionCliente_2->setAutoDefault( FALSE );
    layout42->addWidget( QPBDireccionCliente_2 );
    layout48->addLayout( layout42 );

    layout47_2 = new QHBoxLayout( 0, 0, 6, "layout47_2"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    layout32 = new QVBoxLayout( 0, 0, 6, "layout32"); 

    layout69 = new QHBoxLayout( 0, 0, 6, "layout69"); 

    layout2_5 = new QVBoxLayout( 0, 0, 6, "layout2_5"); 

    textLabel2_5 = new QLabel( this, "textLabel2_5" );
    textLabel2_5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5->sizePolicy().hasHeightForWidth() ) );
    layout2_5->addWidget( textLabel2_5 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    layout2_5->addWidget( QLECalle );
    layout69->addLayout( layout2_5 );

    layout2_5_2 = new QVBoxLayout( 0, 0, 6, "layout2_5_2"); 

    textLabel2_5_2 = new QLabel( this, "textLabel2_5_2" );
    textLabel2_5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5_2->sizePolicy().hasHeightForWidth() ) );
    layout2_5_2->addWidget( textLabel2_5_2 );

    QLENumero = new QLineEdit( this, "QLENumero" );
    QLENumero->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENumero->sizePolicy().hasHeightForWidth() ) );
    layout2_5_2->addWidget( QLENumero );
    layout69->addLayout( layout2_5_2 );

    layout2_5_2_2_3_2 = new QVBoxLayout( 0, 0, 6, "layout2_5_2_2_3_2"); 

    textLabel2_5_2_2_3_2 = new QLabel( this, "textLabel2_5_2_2_3_2" );
    textLabel2_5_2_2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5_2_2_3_2->sizePolicy().hasHeightForWidth() ) );
    layout2_5_2_2_3_2->addWidget( textLabel2_5_2_2_3_2 );

    QLECP = new QLineEdit( this, "QLECP" );
    QLECP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECP->sizePolicy().hasHeightForWidth() ) );
    layout2_5_2_2_3_2->addWidget( QLECP );
    layout69->addLayout( layout2_5_2_2_3_2 );
    layout32->addLayout( layout69 );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    layout2_5_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout2_5_2_2_2"); 

    textLabel2_5_2_2_2 = new QLabel( this, "textLabel2_5_2_2_2" );
    textLabel2_5_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_5_2_2_2->addWidget( textLabel2_5_2_2_2 );

    QLEDelegacion = new QLineEdit( this, "QLEDelegacion" );
    layout2_5_2_2_2->addWidget( QLEDelegacion );
    layout23->addLayout( layout2_5_2_2_2 );

    layout2_5_2_2 = new QVBoxLayout( 0, 0, 6, "layout2_5_2_2"); 

    textLabel2_5_2_2 = new QLabel( this, "textLabel2_5_2_2" );
    textLabel2_5_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5_2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_5_2_2->addWidget( textLabel2_5_2_2 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    layout2_5_2_2->addWidget( QLEColonia );
    layout23->addLayout( layout2_5_2_2 );

    layout2_5_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout2_5_2_2_3"); 

    textLabel2_5_2_2_3 = new QLabel( this, "textLabel2_5_2_2_3" );
    textLabel2_5_2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5_2_2_3->sizePolicy().hasHeightForWidth() ) );
    layout2_5_2_2_3->addWidget( textLabel2_5_2_2_3 );

    QLEEstado = new QLineEdit( this, "QLEEstado" );
    QLEEstado->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEEstado->sizePolicy().hasHeightForWidth() ) );
    layout2_5_2_2_3->addWidget( QLEEstado );
    layout23->addLayout( layout2_5_2_2_3 );
    layout32->addLayout( layout23 );
    layout36->addLayout( layout32 );

    layout35 = new QVBoxLayout( 0, 0, 6, "layout35"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout35->addWidget( textLabel1_3 );

    layout34 = new QHBoxLayout( 0, 0, 6, "layout34"); 

    layout2_5_3 = new QVBoxLayout( 0, 0, 6, "layout2_5_3"); 

    textLabel2_5_3 = new QLabel( this, "textLabel2_5_3" );
    textLabel2_5_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5_3->sizePolicy().hasHeightForWidth() ) );
    layout2_5_3->addWidget( textLabel2_5_3 );

    QLECalle1 = new QLineEdit( this, "QLECalle1" );
    layout2_5_3->addWidget( QLECalle1 );
    layout34->addLayout( layout2_5_3 );

    layout2_5_3_2 = new QVBoxLayout( 0, 0, 6, "layout2_5_3_2"); 

    textLabel2_5_3_2 = new QLabel( this, "textLabel2_5_3_2" );
    textLabel2_5_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5_3_2->sizePolicy().hasHeightForWidth() ) );
    layout2_5_3_2->addWidget( textLabel2_5_3_2 );

    QLECalle2 = new QLineEdit( this, "QLECalle2" );
    layout2_5_3_2->addWidget( QLECalle2 );
    layout34->addLayout( layout2_5_3_2 );
    layout35->addLayout( layout34 );
    layout36->addLayout( layout35 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout25->addWidget( textLabel4 );

    QTEReferencias = new QTextEdit( this, "QTEReferencias" );
    layout25->addWidget( QTEReferencias );
    layout36->addLayout( layout25 );

    layout53 = new QHBoxLayout( 0, 0, 6, "layout53"); 

    QPBRegistraPersonales = new QPushButton( this, "QPBRegistraPersonales" );
    QPBRegistraPersonales->setEnabled( FALSE );
    QPBRegistraPersonales->setMinimumSize( QSize( 0, 40 ) );
    QPBRegistraPersonales->setAutoDefault( FALSE );
    layout53->addWidget( QPBRegistraPersonales );

    QPBRegistraCelular = new QPushButton( this, "QPBRegistraCelular" );
    QPBRegistraCelular->setEnabled( FALSE );
    QPBRegistraCelular->setMinimumSize( QSize( 0, 40 ) );
    QPBRegistraCelular->setAutoDefault( FALSE );
    layout53->addWidget( QPBRegistraCelular );

    QPBRegistraCorreo = new QPushButton( this, "QPBRegistraCorreo" );
    QPBRegistraCorreo->setEnabled( FALSE );
    QPBRegistraCorreo->setMinimumSize( QSize( 0, 40 ) );
    QPBRegistraCorreo->setAutoDefault( FALSE );
    layout53->addWidget( QPBRegistraCorreo );

    QPBRegistraDireccion = new QPushButton( this, "QPBRegistraDireccion" );
    QPBRegistraDireccion->setEnabled( FALSE );
    QPBRegistraDireccion->setMinimumSize( QSize( 0, 40 ) );
    QPBRegistraDireccion->setAutoDefault( FALSE );
    layout53->addWidget( QPBRegistraDireccion );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setMinimumSize( QSize( 150, 40 ) );
    QPBAceptar->setAutoDefault( FALSE );
    layout53->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setMinimumSize( QSize( 0, 40 ) );
    QPBCancelar->setAutoDefault( FALSE );
    layout53->addWidget( QPBCancelar );
    layout36->addLayout( layout53 );
    layout47_2->addLayout( layout36 );

    layout44_2 = new QVBoxLayout( 0, 0, 6, "layout44_2"); 

    layout39 = new QHBoxLayout( 0, 0, 6, "layout39"); 

    layout37 = new QVBoxLayout( 0, 0, 6, "layout37"); 

    textLabel2_6 = new QLabel( this, "textLabel2_6" );
    layout37->addWidget( textLabel2_6 );

    QLETarifa = new QLineEdit( this, "QLETarifa" );
    QLETarifa->setReadOnly( TRUE );
    layout37->addWidget( QLETarifa );
    layout39->addLayout( layout37 );

    layout37_2 = new QVBoxLayout( 0, 0, 6, "layout37_2"); 

    textLabel2_6_2 = new QLabel( this, "textLabel2_6_2" );
    layout37_2->addWidget( textLabel2_6_2 );

    QLEDiasEntrega = new QLineEdit( this, "QLEDiasEntrega" );
    QLEDiasEntrega->setReadOnly( TRUE );
    layout37_2->addWidget( QLEDiasEntrega );
    layout39->addLayout( layout37_2 );
    layout44_2->addLayout( layout39 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    layout41->addWidget( textLabel1_4 );

    table3 = new QTable( this, "table3" );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Telefono" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Descripcion" ) );
    table3->setNumRows( 0 );
    table3->setNumCols( 2 );
    layout41->addWidget( table3 );
    layout44_2->addLayout( layout41 );

    layout70 = new QVBoxLayout( 0, 0, 6, "layout70"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout70->addWidget( textLabel1_2 );

    QTDirecciones = new QTable( this, "QTDirecciones" );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Direccion" ) );
    QFont QTDirecciones_font(  QTDirecciones->font() );
    QTDirecciones_font.setPointSize( 6 );
    QTDirecciones->setFont( QTDirecciones_font ); 
    QTDirecciones->setNumRows( 0 );
    QTDirecciones->setNumCols( 1 );
    QTDirecciones->setReadOnly( TRUE );
    layout70->addWidget( QTDirecciones );

    layout49 = new QHBoxLayout( 0, 0, 6, "layout49"); 
    layout70->addLayout( layout49 );
    layout44_2->addLayout( layout70 );
    layout47_2->addLayout( layout44_2 );
    layout48->addLayout( layout47_2 );

    ClientePedidoLayout->addLayout( layout48, 0, 0 );
    languageChange();
    resize( QSize(885, 512).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ClientePedido::~ClientePedido()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ClientePedido::languageChange()
{
    setCaption( tr( "Datos Cliente" ) );
    textLabel1->setText( tr( "Escuelas" ) );
    textLabel2->setText( tr( "Nombre" ) );
    textLabel2_2->setText( tr( "Apellido Paterno" ) );
    textLabel2_3->setText( tr( "Apellido Materno" ) );
    textLabel2_4->setText( tr( "Celular" ) );
    QLECelular->setInputMask( tr( "##-####-####; " ) );
    textLabel2_4_2->setText( tr( "Re Celular" ) );
    QLEReCelular->setInputMask( tr( "##-####-####; " ) );
    textLabel2_3_2->setText( tr( "Escuela Cliente" ) );
    textLabel5->setText( tr( "Numero Cliente" ) );
    QPBPuntoEntrega->setText( tr( "Punto de &Entrega Siscom" ) );
    QPBPuntoEntrega->setAccel( QKeySequence( tr( "Alt+E" ) ) );
    QPBDireccionCliente->setText( tr( "Envio &Por Paqueteria" ) );
    QPBDireccionCliente->setAccel( QKeySequence( tr( "Alt+P" ) ) );
    QPBDireccionCliente_2->setText( tr( "Envio Siscom" ) );
    textLabel2_5->setText( tr( "Calle" ) );
    textLabel2_5_2->setText( tr( "Numero" ) );
    textLabel2_5_2_2_3_2->setText( tr( "Codigo Postal" ) );
    QLECP->setInputMask( tr( "######; " ) );
    textLabel2_5_2_2_2->setText( tr( "Delegacion" ) );
    textLabel2_5_2_2->setText( tr( "Colonia" ) );
    textLabel2_5_2_2_3->setText( tr( "Estado" ) );
    textLabel1_3->setText( tr( "Entre Calles" ) );
    textLabel2_5_3->setText( tr( "Calle" ) );
    textLabel2_5_3_2->setText( tr( "Calle" ) );
    textLabel4->setText( tr( "Referencias" ) );
    QPBRegistraPersonales->setText( tr( "Registra Datos \n"
"Personales" ) );
    QPBRegistraCelular->setText( tr( "Registra\n"
"Celular" ) );
    QPBRegistraCorreo->setText( tr( "Registra\n"
"Correo" ) );
    QPBRegistraDireccion->setText( tr( "Registra \n"
"Direccion" ) );
    QPBAceptar->setText( tr( "&Aceptar" ) );
    QPBAceptar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel2_6->setText( tr( "Tarifa" ) );
    textLabel2_6_2->setText( tr( "Dias Entrega" ) );
    textLabel1_4->setText( tr( "Telefonos" ) );
    table3->horizontalHeader()->setLabel( 0, tr( "Telefono" ) );
    table3->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    textLabel1_2->setText( tr( "Direcciones Entrega" ) );
    QTDirecciones->horizontalHeader()->setLabel( 0, tr( "Direccion" ) );
}

