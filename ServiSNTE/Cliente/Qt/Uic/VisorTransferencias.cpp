/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/VisorTransferencias.ui'
**
** Created: Thu Apr 11 21:07:18 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "VisorTransferencias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qdatetimeedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a VisorTransferencias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
VisorTransferencias::VisorTransferencias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "VisorTransferencias" );
    VisorTransferenciasLayout = new QGridLayout( this, 1, 1, 11, 6, "VisorTransferenciasLayout"); 

    frame14 = new QFrame( this, "frame14" );
    frame14->setFrameShape( QFrame::StyledPanel );
    frame14->setFrameShadow( QFrame::Raised );
    frame14Layout = new QHBoxLayout( frame14, 11, 6, "frame14Layout"); 

    QPBRecibir = new QPushButton( frame14, "QPBRecibir" );
    QPBRecibir->setEnabled( FALSE );
    frame14Layout->addWidget( QPBRecibir );

    pushButton4_2 = new QPushButton( frame14, "pushButton4_2" );
    pushButton4_2->setEnabled( FALSE );
    frame14Layout->addWidget( pushButton4_2 );

    pushButton4_3 = new QPushButton( frame14, "pushButton4_3" );
    pushButton4_3->setEnabled( FALSE );
    frame14Layout->addWidget( pushButton4_3 );

    VisorTransferenciasLayout->addWidget( frame14, 1, 1 );

    frame13 = new QFrame( this, "frame13" );
    frame13->setFrameShape( QFrame::StyledPanel );
    frame13->setFrameShadow( QFrame::Raised );
    frame13Layout = new QGridLayout( frame13, 1, 1, 11, 6, "frame13Layout"); 

    groupBox3 = new QGroupBox( frame13, "groupBox3" );
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
    QTDetalleTransferencias->setNumRows( 0 );
    QTDetalleTransferencias->setNumCols( 5 );

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

    frame13Layout->addWidget( groupBox3, 0, 0 );

    VisorTransferenciasLayout->addWidget( frame13, 0, 1 );

    frame4 = new QFrame( this, "frame4" );
    frame4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, frame4->sizePolicy().hasHeightForWidth() ) );
    frame4->setFrameShape( QFrame::StyledPanel );
    frame4->setFrameShadow( QFrame::Raised );
    frame4Layout = new QGridLayout( frame4, 1, 1, 11, 6, "frame4Layout"); 

    dateEdit1 = new QDateEdit( frame4, "dateEdit1" );
    dateEdit1->setOrder( QDateEdit::YMD );

    frame4Layout->addWidget( dateEdit1, 0, 0 );

    groupBox2 = new QGroupBox( frame4, "groupBox2" );
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
    QTTransferencias->setNumRows( 0 );
    QTTransferencias->setNumCols( 2 );
    QTTransferencias->setReadOnly( TRUE );

    groupBox2Layout->addWidget( QTTransferencias, 0, 0 );

    frame4Layout->addWidget( groupBox2, 1, 0 );

    VisorTransferenciasLayout->addMultiCellWidget( frame4, 0, 1, 0, 0 );
    languageChange();
    resize( QSize(889, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
VisorTransferencias::~VisorTransferencias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void VisorTransferencias::languageChange()
{
    setCaption( tr( "Visor  Transferencias" ) );
    QPBRecibir->setText( tr( "Recibir Transferencia" ) );
    pushButton4_2->setText( tr( "pushButton4" ) );
    pushButton4_3->setText( tr( "pushButton4" ) );
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
    groupBox4->setTitle( tr( "Observacion General" ) );
    groupBox2->setTitle( tr( "Lista de Transferencias" ) );
    QTTransferencias->horizontalHeader()->setLabel( 0, tr( "Id Transferencia" ) );
    QTTransferencias->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
}

