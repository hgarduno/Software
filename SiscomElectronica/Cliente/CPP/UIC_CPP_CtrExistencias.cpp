/****************************************************************************
** Form implementation generated from reading ui file 'UI/CtrExistencias.ui'
**
** Created: Wed Apr 10 21:12:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CtrExistencias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CtrExistencias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CtrExistencias::CtrExistencias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CtrExistencias" );
    CtrExistenciasLayout = new QGridLayout( this, 1, 1, 11, 6, "CtrExistenciasLayout"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout12->addWidget( textLabel2 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCBProductos->sizePolicy().hasHeightForWidth() ) );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout12->addWidget( QCBProductos );
    layout13->addLayout( layout12 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    lineEdit1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( lineEdit1 );
    layout13->addLayout( layout7 );

    CtrExistenciasLayout->addLayout( layout13, 0, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Ex. Total" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Ex. Expendio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Ex. Bodegas" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Ex Minima" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "U. Compra" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad U.C." ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio U.C." ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Proveedor" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Ventas Semestre Ant" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Compras Semestre Ant" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Ventas Actuales" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Compras Actuales" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 13 );
    QTDatos->setReadOnly( TRUE );

    CtrExistenciasLayout->addWidget( QTDatos, 1, 0 );

    layout66 = new QVBoxLayout( 0, 0, 6, "layout66"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout66->addWidget( textLabel1_2 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout66->addWidget( QLEDescripcion );

    CtrExistenciasLayout->addLayout( layout66, 2, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    QPBExExpendio = new QPushButton( this, "QPBExExpendio" );
    QPBExExpendio->setToggleButton( FALSE );
    QPBExExpendio->setOn( FALSE );
    QPBExExpendio->setFlat( FALSE );
    layout22->addWidget( QPBExExpendio );

    QPBExistenciaM = new QPushButton( this, "QPBExistenciaM" );
    layout22->addWidget( QPBExistenciaM );

    QPBPExistencia = new QPushButton( this, "QPBPExistencia" );
    layout22->addWidget( QPBPExistencia );

    QPBProdsBodega = new QPushButton( this, "QPBProdsBodega" );
    layout22->addWidget( QPBProdsBodega );

    pushButton3 = new QPushButton( this, "pushButton3" );
    layout22->addWidget( pushButton3 );

    QPBAAnexarP = new QPushButton( this, "QPBAAnexarP" );
    QPBAAnexarP->setToggleButton( FALSE );
    QPBAAnexarP->setOn( FALSE );
    QPBAAnexarP->setFlat( FALSE );
    layout22->addWidget( QPBAAnexarP );

    CtrExistenciasLayout->addLayout( layout22, 3, 0 );
    languageChange();
    resize( QSize(888, 641).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CtrExistencias::~CtrExistencias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CtrExistencias::languageChange()
{
    setCaption( tr( "Sistema De Existencias" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel1->setText( tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Ex. Total" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Ex. Expendio" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Ex. Bodegas" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Ex Minima" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "U. Compra" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Cantidad U.C." ) );
    QTDatos->horizontalHeader()->setLabel( 7, tr( "Precio U.C." ) );
    QTDatos->horizontalHeader()->setLabel( 8, tr( "Proveedor" ) );
    QTDatos->horizontalHeader()->setLabel( 9, tr( "Ventas Semestre Ant" ) );
    QTDatos->horizontalHeader()->setLabel( 10, tr( "Compras Semestre Ant" ) );
    QTDatos->horizontalHeader()->setLabel( 11, tr( "Ventas Actuales" ) );
    QTDatos->horizontalHeader()->setLabel( 12, tr( "Compras Actuales" ) );
    textLabel1_2->setText( tr( "Descripcion" ) );
    QPBExExpendio->setText( tr( "Existencias Expendio" ) );
    QPBExistenciaM->setText( tr( "Existencia Minima" ) );
    QPBPExistencia->setText( tr( "% De Existencia Minima" ) );
    QPBProdsBodega->setText( tr( "Productos Bodega" ) );
    pushButton3->setText( tr( "Imprimir" ) );
    QPBAAnexarP->setText( tr( "Activar Anexar Productos" ) );
}

