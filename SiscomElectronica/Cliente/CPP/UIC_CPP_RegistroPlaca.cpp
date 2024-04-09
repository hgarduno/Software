/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroPlaca.ui'
**
** Created: lun abr 1 18:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroPlaca.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <QCtrlFechaHora.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFechaHora.h"

/*
 *  Constructs a RegistroPlaca as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RegistroPlaca::RegistroPlaca( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RegistroPlaca" );
    RegistroPlacaLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroPlacaLayout"); 

    layout25 = new QGridLayout( 0, 1, 1, 0, 6, "layout25"); 

    QPBRegistraCelular = new QPushButton( this, "QPBRegistraCelular" );
    QPBRegistraCelular->setEnabled( FALSE );
    QPBRegistraCelular->setAutoDefault( FALSE );

    layout25->addWidget( QPBRegistraCelular, 0, 1 );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setEnabled( FALSE );
    QPBRegistra->setAutoDefault( FALSE );

    layout25->addWidget( QPBRegistra, 0, 3 );

    QPBImprimeComprobante = new QPushButton( this, "QPBImprimeComprobante" );
    QPBImprimeComprobante->setEnabled( FALSE );
    QPBImprimeComprobante->setAutoDefault( FALSE );

    layout25->addWidget( QPBImprimeComprobante, 0, 2 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setEnabled( FALSE );
    QPBCancelar->setAutoDefault( FALSE );

    layout25->addWidget( QPBCancelar, 0, 5 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );

    layout25->addWidget( QPBAceptar, 0, 4 );

    QPBRegistraPersonales = new QPushButton( this, "QPBRegistraPersonales" );
    QPBRegistraPersonales->setEnabled( FALSE );
    QPBRegistraPersonales->setAutoDefault( FALSE );

    layout25->addWidget( QPBRegistraPersonales, 0, 0 );

    RegistroPlacaLayout->addLayout( layout25, 3, 0 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel2_5 = new QLabel( this, "textLabel2_5" );
    layout42->addWidget( textLabel2_5 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Alumno" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Celular" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Estatus" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Clave" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Hora de Entrega" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Memoria" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Archivo" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 8 );
    QTDatos->setReadOnly( TRUE );
    layout42->addWidget( QTDatos );

    RegistroPlacaLayout->addLayout( layout42, 2, 0 );

    layout78 = new QHBoxLayout( 0, 0, 6, "layout78"); 

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( textLabel1 );

    QTEArchivo = new QTextEdit( this, "QTEArchivo" );
    QTEArchivo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QTEArchivo->sizePolicy().hasHeightForWidth() ) );
    QTEArchivo->setWordWrap( QTextEdit::WidgetWidth );
    layout16->addWidget( QTEArchivo );
    layout17->addLayout( layout16 );

    layout16_2 = new QVBoxLayout( 0, 0, 6, "layout16_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2->addWidget( textLabel1_2 );

    QTEMemoria = new QTextEdit( this, "QTEMemoria" );
    QTEMemoria->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QTEMemoria->sizePolicy().hasHeightForWidth() ) );
    QTEMemoria->setWordWrap( QTextEdit::WidgetWidth );
    layout16_2->addWidget( QTEMemoria );
    layout17->addLayout( layout16_2 );
    layout78->addLayout( layout17 );

    RegistroPlacaLayout->addLayout( layout78, 1, 0 );

    layout90 = new QHBoxLayout( 0, 0, 6, "layout90"); 

    layout82 = new QVBoxLayout( 0, 0, 6, "layout82"); 

    layout74 = new QHBoxLayout( 0, 0, 6, "layout74"); 

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel2_6 = new QLabel( this, "textLabel2_6" );
    textLabel2_6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel2_6->sizePolicy().hasHeightForWidth() ) );
    layout24->addWidget( textLabel2_6 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCBProductos->sizePolicy().hasHeightForWidth() ) );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout24->addWidget( QCBProductos );
    layout74->addLayout( layout24 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    QLENombre->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENombre->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QLENombre );
    layout74->addLayout( layout2 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( textLabel2_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    QLEAPaterno->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEAPaterno->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( QLEAPaterno );
    layout74->addLayout( layout2_2 );

    layout2_3 = new QVBoxLayout( 0, 0, 6, "layout2_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout2_3->addWidget( textLabel2_3 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    QLEAMaterno->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEAMaterno->sizePolicy().hasHeightForWidth() ) );
    layout2_3->addWidget( QLEAMaterno );
    layout74->addLayout( layout2_3 );
    layout82->addLayout( layout74 );

    layout80 = new QHBoxLayout( 0, 0, 6, "layout80"); 

    layout2_4 = new QVBoxLayout( 0, 0, 6, "layout2_4"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout2_4->addWidget( textLabel2_4 );

    QLECelular = new QLineEdit( this, "QLECelular" );
    QLECelular->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECelular->sizePolicy().hasHeightForWidth() ) );
    layout2_4->addWidget( QLECelular );
    layout80->addLayout( layout2_4 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel2_4_2 = new QLabel( this, "textLabel2_4_2" );
    textLabel2_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel2_4_2->sizePolicy().hasHeightForWidth() ) );
    layout13->addWidget( textLabel2_4_2 );

    QLEReCelular = new QLineEdit( this, "QLEReCelular" );
    QLEReCelular->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEReCelular->sizePolicy().hasHeightForWidth() ) );
    layout13->addWidget( QLEReCelular );
    layout80->addLayout( layout13 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout15->addWidget( textLabel1_3 );

    QCtrFechaEntrega = new QCtrlFechaHora( this, "QCtrFechaEntrega" );
    QCtrFechaEntrega->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaEntrega->sizePolicy().hasHeightForWidth() ) );
    layout15->addWidget( QCtrFechaEntrega );
    layout80->addLayout( layout15 );
    layout82->addLayout( layout80 );
    layout90->addLayout( layout82 );

    layout89 = new QHBoxLayout( 0, 0, 6, "layout89"); 

    layout65 = new QVBoxLayout( 0, 0, 6, "layout65"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout65->addWidget( textLabel1_4 );

    QLCDNNImpresos = new QLCDNumber( this, "QLCDNNImpresos" );
    QLCDNNImpresos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLCDNNImpresos->sizePolicy().hasHeightForWidth() ) );
    layout65->addWidget( QLCDNNImpresos );
    layout89->addLayout( layout65 );

    layout65_2 = new QVBoxLayout( 0, 0, 6, "layout65_2"); 

    textLabel1_4_2 = new QLabel( this, "textLabel1_4_2" );
    textLabel1_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4_2->sizePolicy().hasHeightForWidth() ) );
    layout65_2->addWidget( textLabel1_4_2 );

    QLCDNNImpRegistrados = new QLCDNumber( this, "QLCDNNImpRegistrados" );
    QLCDNNImpRegistrados->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QLCDNNImpRegistrados->sizePolicy().hasHeightForWidth() ) );
    layout65_2->addWidget( QLCDNNImpRegistrados );
    layout89->addLayout( layout65_2 );
    layout90->addLayout( layout89 );

    RegistroPlacaLayout->addLayout( layout90, 0, 0 );
    languageChange();
    resize( QSize(917, 461).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroPlaca::~RegistroPlaca()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroPlaca::languageChange()
{
    setCaption( tr( "Programacion de Placas" ) );
    QPBRegistraCelular->setText( tr( "Registra Celular" ) );
    QPBRegistra->setText( tr( "Registra Impreso" ) );
    QPBImprimeComprobante->setText( tr( "Imprime Comprobante" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBRegistraPersonales->setText( tr( "Registra Datos Personales" ) );
    textLabel2_5->setText( tr( "Placas Pendientes" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Alumno" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Celular" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Estatus" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Clave" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Fecha" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Hora de Entrega" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Memoria" ) );
    QTDatos->horizontalHeader()->setLabel( 7, tr( "Archivo" ) );
    textLabel1->setText( tr( "Archivo" ) );
    QTEArchivo->setText( QString::null );
    textLabel1_2->setText( tr( "Observaciones" ) );
    QTEMemoria->setText( QString::null );
    textLabel2_6->setText( tr( "Selecciona Impreso" ) );
    textLabel2->setText( tr( "Nombre" ) );
    textLabel2_2->setText( tr( "Apellido Paterno" ) );
    textLabel2_3->setText( tr( "Apellido Materno" ) );
    textLabel2_4->setText( tr( "Celular" ) );
    textLabel2_4_2->setText( tr( "Re Celular" ) );
    textLabel1_3->setText( tr( "Fecha y Hora de Entrega" ) );
    textLabel1_4->setText( tr( "Circuitos Impresos Orden" ) );
    textLabel1_4_2->setText( tr( "Impresos Registrados" ) );
}

