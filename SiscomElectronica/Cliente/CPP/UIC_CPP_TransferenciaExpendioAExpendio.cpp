/****************************************************************************
** Form implementation generated from reading ui file 'UI/TransferenciaExpendioAExpendio.ui'
**
** Created: Wed Jan 31 10:48:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_TransferenciaExpendioAExpendio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <QCtrlExpendios.h>
#include <qlineedit.h>
#include <QCtrlProductosSE.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlExpendios.h"
#include "QCtrlProductosSE.h"

/*
 *  Constructs a TransferenciaExpendioAExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
TransferenciaExpendioAExpendio::TransferenciaExpendioAExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TransferenciaExpendioAExpendio" );
    TransferenciaExpendioAExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "TransferenciaExpendioAExpendioLayout"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel1_2_2 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 2 );
    layout3->addWidget( QTDatos );

    TransferenciaExpendioAExpendioLayout->addLayout( layout3, 2, 0 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( textLabel1 );

    QCtrExpendiosO = new QCtrlExpendios( this, "QCtrExpendiosO" );
    QCtrExpendiosO->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrExpendiosO->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( QCtrExpendiosO );
    layout17->addLayout( layout6 );

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    textLabel1_4_2 = new QLabel( this, "textLabel1_4_2" );
    textLabel1_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2->sizePolicy().hasHeightForWidth() ) );
    layout8_2->addWidget( textLabel1_4_2 );

    QLEExistenciaOrigen = new QLineEdit( this, "QLEExistenciaOrigen" );
    QLEExistenciaOrigen->setEnabled( TRUE );
    QLEExistenciaOrigen->setReadOnly( TRUE );
    layout8_2->addWidget( QLEExistenciaOrigen );
    layout17->addLayout( layout8_2 );
    layout20->addLayout( layout17 );

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout6_2->addWidget( textLabel1_2 );

    QCtrExpendiosD = new QCtrlExpendios( this, "QCtrExpendiosD" );
    QCtrExpendiosD->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrExpendiosD->sizePolicy().hasHeightForWidth() ) );
    layout6_2->addWidget( QCtrExpendiosD );
    layout18->addLayout( layout6_2 );

    layout8_2_2 = new QVBoxLayout( 0, 0, 6, "layout8_2_2"); 

    textLabel1_4_2_2 = new QLabel( this, "textLabel1_4_2_2" );
    textLabel1_4_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2_2->sizePolicy().hasHeightForWidth() ) );
    layout8_2_2->addWidget( textLabel1_4_2_2 );

    QLEExistenciaDestino = new QLineEdit( this, "QLEExistenciaDestino" );
    QLEExistenciaDestino->setReadOnly( TRUE );
    layout8_2_2->addWidget( QLEExistenciaDestino );
    layout18->addLayout( layout8_2_2 );
    layout20->addLayout( layout18 );

    TransferenciaExpendioAExpendioLayout->addLayout( layout20, 0, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout13->addWidget( textLabel1_3 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setEnabled( FALSE );
    layout13->addWidget( QCtrProductos );
    layout22->addLayout( layout13 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel1_4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    QLECantidad->setReadOnly( FALSE );
    layout8->addWidget( QLECantidad );
    layout22->addLayout( layout8 );

    TransferenciaExpendioAExpendioLayout->addLayout( layout22, 1, 0 );

    layout40 = new QHBoxLayout( 0, 0, 6, "layout40"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout40->addWidget( QPBAnexar );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );
    layout40->addWidget( QPBImprimir );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    layout40->addWidget( QPBRegistrar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    layout40->addWidget( QPBEliminar );

    TransferenciaExpendioAExpendioLayout->addLayout( layout40, 3, 0 );
    languageChange();
    resize( QSize(623, 563).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
TransferenciaExpendioAExpendio::~TransferenciaExpendioAExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TransferenciaExpendioAExpendio::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_2_2->setText( tr( "Productos" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    textLabel1->setText( tr( "Expendio Origen" ) );
    textLabel1_4_2->setText( tr( "Existencia" ) );
    textLabel1_2->setText( tr( "Expendio Destino" ) );
    textLabel1_4_2_2->setText( tr( "Existencia" ) );
    textLabel1_3->setText( tr( "Productos" ) );
    textLabel1_4->setText( tr( "Cantidad" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBEliminar->setText( tr( "Elimina Producto" ) );
}

