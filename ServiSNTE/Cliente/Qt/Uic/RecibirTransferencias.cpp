/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RecibirTransferencias.ui'
**
** Created: Thu Apr 11 21:07:21 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RecibirTransferencias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RecibirTransferencias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RecibirTransferencias::RecibirTransferencias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RecibirTransferencias" );
    RecibirTransferenciasLayout = new QGridLayout( this, 1, 1, 11, 6, "RecibirTransferenciasLayout"); 

    groupBox3 = new QGroupBox( this, "groupBox3" );
    groupBox3->setColumnLayout(0, Qt::Vertical );
    groupBox3->layout()->setSpacing( 6 );
    groupBox3->layout()->setMargin( 11 );
    groupBox3Layout = new QGridLayout( groupBox3->layout() );
    groupBox3Layout->setAlignment( Qt::AlignTop );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2 = new QLabel( groupBox3, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( textLabel2 );

    QLETienda = new QLineEdit( groupBox3, "QLETienda" );
    QLETienda->setReadOnly( TRUE );
    layout6->addWidget( QLETienda );

    groupBox3Layout->addLayout( layout6, 0, 0 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    textLabel2_2 = new QLabel( groupBox3, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel2_2 );

    QLEResponsable = new QLineEdit( groupBox3, "QLEResponsable" );
    QLEResponsable->setReadOnly( TRUE );
    layout7->addWidget( QLEResponsable );

    groupBox3Layout->addLayout( layout7, 0, 1 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    textLabel2_4 = new QLabel( groupBox3, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel2_4 );

    QLECamion = new QLineEdit( groupBox3, "QLECamion" );
    QLECamion->setReadOnly( TRUE );
    layout8->addWidget( QLECamion );

    groupBox3Layout->addLayout( layout8, 1, 1 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    textLabel2_3 = new QLabel( groupBox3, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel2_3 );

    QLEChofer = new QLineEdit( groupBox3, "QLEChofer" );
    QLEChofer->setReadOnly( TRUE );
    layout9->addWidget( QLEChofer );

    groupBox3Layout->addLayout( layout9, 1, 0 );

    QTDetalleTransferencias = new QTable( groupBox3, "QTDetalleTransferencias" );
    QTDetalleTransferencias->setNumCols( QTDetalleTransferencias->numCols() + 1 );
    QTDetalleTransferencias->horizontalHeader()->setLabel( QTDetalleTransferencias->numCols() - 1, tr( "Producto" ) );
    QTDetalleTransferencias->setNumCols( QTDetalleTransferencias->numCols() + 1 );
    QTDetalleTransferencias->horizontalHeader()->setLabel( QTDetalleTransferencias->numCols() - 1, tr( "Modelo" ) );
    QTDetalleTransferencias->setNumCols( QTDetalleTransferencias->numCols() + 1 );
    QTDetalleTransferencias->horizontalHeader()->setLabel( QTDetalleTransferencias->numCols() - 1, tr( "Codigo Barras" ) );
    QTDetalleTransferencias->setNumCols( QTDetalleTransferencias->numCols() + 1 );
    QTDetalleTransferencias->horizontalHeader()->setLabel( QTDetalleTransferencias->numCols() - 1, tr( "Cantidad" ) );
    QTDetalleTransferencias->setNumCols( QTDetalleTransferencias->numCols() + 1 );
    QTDetalleTransferencias->horizontalHeader()->setLabel( QTDetalleTransferencias->numCols() - 1, tr( "Observacion" ) );
    QTDetalleTransferencias->setNumCols( QTDetalleTransferencias->numCols() + 1 );
    QTDetalleTransferencias->horizontalHeader()->setLabel( QTDetalleTransferencias->numCols() - 1, tr( "Es Stock" ) );
    QTDetalleTransferencias->setNumRows( 0 );
    QTDetalleTransferencias->setNumCols( 6 );
    QTDetalleTransferencias->setReadOnly( TRUE );

    groupBox3Layout->addMultiCellWidget( QTDetalleTransferencias, 2, 2, 0, 1 );

    groupBox4 = new QGroupBox( groupBox3, "groupBox4" );
    groupBox4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, groupBox4->sizePolicy().hasHeightForWidth() ) );
    groupBox4->setColumnLayout(0, Qt::Vertical );
    groupBox4->layout()->setSpacing( 6 );
    groupBox4->layout()->setMargin( 11 );
    groupBox4Layout = new QGridLayout( groupBox4->layout() );
    groupBox4Layout->setAlignment( Qt::AlignTop );

    QTEObservacionGeneral = new QTextEdit( groupBox4, "QTEObservacionGeneral" );
    QTEObservacionGeneral->setReadOnly( TRUE );

    groupBox4Layout->addWidget( QTEObservacionGeneral, 0, 0 );

    groupBox3Layout->addMultiCellWidget( groupBox4, 3, 3, 0, 1 );

    RecibirTransferenciasLayout->addWidget( groupBox3, 0, 1 );

    groupBox2 = new QGroupBox( this, "groupBox2" );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    QTTransferencias = new QTable( groupBox2, "QTTransferencias" );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Id Transferencia" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Fecha" ) );
    QTTransferencias->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)7, 0, 0, QTTransferencias->sizePolicy().hasHeightForWidth() ) );
    QTTransferencias->setMinimumSize( QSize( 200, 0 ) );
    QTTransferencias->setNumRows( 0 );
    QTTransferencias->setNumCols( 2 );
    QTTransferencias->setReadOnly( TRUE );

    groupBox2Layout->addWidget( QTTransferencias, 0, 0 );

    RecibirTransferenciasLayout->addMultiCellWidget( groupBox2, 0, 1, 0, 0 );

    layout44 = new QHBoxLayout( 0, 0, 6, "layout44"); 

    QPBRecibir = new QPushButton( this, "QPBRecibir" );
    layout44->addWidget( QPBRecibir );

    QPBParcial = new QPushButton( this, "QPBParcial" );
    QPBParcial->setEnabled( FALSE );
    layout44->addWidget( QPBParcial );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( TRUE );
    layout44->addWidget( QPBActualizar );

    RecibirTransferenciasLayout->addLayout( layout44, 1, 1 );
    languageChange();
    resize( QSize(961, 478).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RecibirTransferencias::~RecibirTransferencias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RecibirTransferencias::languageChange()
{
    setCaption( tr( "Recibir Transferencias" ) );
    groupBox3->setTitle( tr( "Informacion de Transferencia" ) );
    textLabel2->setText( tr( "Tienda a Transferir:" ) );
    textLabel2_2->setText( tr( "Responsable:" ) );
    textLabel2_4->setText( tr( "Camion:" ) );
    textLabel2_3->setText( tr( "Chofer:" ) );
    QTDetalleTransferencias->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDetalleTransferencias->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTDetalleTransferencias->horizontalHeader()->setLabel( 2, tr( "Codigo Barras" ) );
    QTDetalleTransferencias->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTDetalleTransferencias->horizontalHeader()->setLabel( 4, tr( "Observacion" ) );
    QTDetalleTransferencias->horizontalHeader()->setLabel( 5, tr( "Es Stock" ) );
    groupBox4->setTitle( tr( "Observacion General" ) );
    groupBox2->setTitle( tr( "Lista de Transferencias" ) );
    QTTransferencias->horizontalHeader()->setLabel( 0, tr( "Id Transferencia" ) );
    QTTransferencias->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QPBRecibir->setText( tr( "Recibir Transferencia" ) );
    QPBParcial->setText( tr( "Recibir Parcialmente" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
}

