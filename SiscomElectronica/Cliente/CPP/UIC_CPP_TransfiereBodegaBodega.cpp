/****************************************************************************
** Form implementation generated from reading ui file 'UI/TransfiereBodegaBodega.ui'
**
** Created: Thu Dec 21 12:53:47 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_TransfiereBodegaBodega.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlCmbBodegas4.h>
#include <qtable.h>
#include <qtextedit.h>
#include <QCtrlProductosSE.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlCmbBodegas4.h"
#include "QCtrlProductosSE.h"

/*
 *  Constructs a TransfiereBodegaBodega as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
TransfiereBodegaBodega::TransfiereBodegaBodega( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "TransfiereBodegaBodega" );
    TransfiereBodegaBodegaLayout = new QGridLayout( this, 1, 1, 11, 6, "TransfiereBodegaBodegaLayout"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCmbBodegasO = new QCtrlCmbBodegas4( this, "QCmbBodegasO" );
    layout1->addWidget( QCmbBodegasO );
    layout3->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QCmbBodegasD = new QCtrlCmbBodegas4( this, "QCmbBodegasD" );
    QCmbBodegasD->setEnabled( FALSE );
    layout1_2->addWidget( QCmbBodegasD );
    layout3->addLayout( layout1_2 );

    TransfiereBodegaBodegaLayout->addMultiCellLayout( layout3, 0, 0, 0, 1 );

    QPBTransfiere = new QPushButton( this, "QPBTransfiere" );
    QPBTransfiere->setEnabled( FALSE );

    TransfiereBodegaBodegaLayout->addMultiCellWidget( QPBTransfiere, 5, 5, 0, 1 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout6->addWidget( textLabel4 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Bodega O" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia O" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Bodega D" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia D" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 6 );
    QTDatos->setReadOnly( TRUE );
    layout6->addWidget( QTDatos );

    TransfiereBodegaBodegaLayout->addMultiCellLayout( layout6, 4, 4, 0, 1 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout8->addWidget( textLabel5 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout8->addWidget( QTEDescripcion );

    TransfiereBodegaBodegaLayout->addMultiCellLayout( layout8, 3, 3, 0, 1 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    layout4->addWidget( QCtrProductos );

    TransfiereBodegaBodegaLayout->addLayout( layout4, 2, 0 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel1_3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( QLECantidad );

    TransfiereBodegaBodegaLayout->addLayout( layout10, 2, 1 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout16->addWidget( textLabel3 );

    QLEBodegaO = new QLineEdit( this, "QLEBodegaO" );
    layout16->addWidget( QLEBodegaO );
    layout13->addLayout( layout16 );

    layout16_3 = new QVBoxLayout( 0, 0, 6, "layout16_3"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    layout16_3->addWidget( textLabel3_3 );

    QLEExistenciaO = new QLineEdit( this, "QLEExistenciaO" );
    layout16_3->addWidget( QLEExistenciaO );
    layout13->addLayout( layout16_3 );
    layout15->addLayout( layout13 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    layout16_2 = new QVBoxLayout( 0, 0, 6, "layout16_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout16_2->addWidget( textLabel3_2 );

    QLEBodegaD = new QLineEdit( this, "QLEBodegaD" );
    layout16_2->addWidget( QLEBodegaD );
    layout14->addLayout( layout16_2 );

    layout16_3_2 = new QVBoxLayout( 0, 0, 6, "layout16_3_2"); 

    textLabel3_3_2 = new QLabel( this, "textLabel3_3_2" );
    layout16_3_2->addWidget( textLabel3_3_2 );

    QLEExistenciaD = new QLineEdit( this, "QLEExistenciaD" );
    layout16_3_2->addWidget( QLEExistenciaD );
    layout14->addLayout( layout16_3_2 );
    layout15->addLayout( layout14 );

    TransfiereBodegaBodegaLayout->addMultiCellLayout( layout15, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(650, 633).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
TransfiereBodegaBodega::~TransfiereBodegaBodega()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TransfiereBodegaBodega::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Bodega Origen" ) );
    textLabel1_2->setText( tr( "Bodega Destinp" ) );
    QPBTransfiere->setText( tr( "Actualiza" ) );
    textLabel4->setText( tr( "Capturas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Bodega O" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Existencia O" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Bodega D" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Existencia D" ) );
    textLabel5->setText( tr( "Descripcion" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel1_3->setText( tr( "Cantidad" ) );
    textLabel3->setText( tr( "Bodega Origen" ) );
    textLabel3_3->setText( tr( "Existencia O" ) );
    textLabel3_2->setText( tr( "Bodega Destino" ) );
    textLabel3_3_2->setText( tr( "Existencia D" ) );
}

