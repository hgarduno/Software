/****************************************************************************
** Form implementation generated from reading ui file 'UI/RastreoProducto.ui'
**
** Created: Thu Dec 21 12:53:42 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RastreoProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <QCtrlProdSiscomElectronica.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"
#include "QCtrlProdSiscomElectronica.h"

/*
 *  Constructs a RastreoProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RastreoProducto::RastreoProducto( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RastreoProducto" );
    RastreoProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "RastreoProductoLayout"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout13->addWidget( textLabel3 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    QCtrFechaIni->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaIni->sizePolicy().hasHeightForWidth() ) );
    layout13->addWidget( QCtrFechaIni );

    RastreoProductoLayout->addLayout( layout13, 0, 0 );

    layout13_2 = new QVBoxLayout( 0, 0, 6, "layout13_2"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    textLabel3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_3->sizePolicy().hasHeightForWidth() ) );
    layout13_2->addWidget( textLabel3_3 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout13_2->addWidget( QCtrFechaFin );

    RastreoProductoLayout->addLayout( layout13_2, 0, 1 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProdSiscomElectronica( this, "QCtrProductos" );
    layout1->addWidget( QCtrProductos );

    RastreoProductoLayout->addLayout( layout1, 0, 2 );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout18->addWidget( textLabel4 );

    QLEEExpendio = new QLineEdit( this, "QLEEExpendio" );
    QLEEExpendio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEEExpendio->sizePolicy().hasHeightForWidth() ) );
    layout18->addWidget( QLEEExpendio );
    layout23->addLayout( layout18 );

    layout18_2 = new QVBoxLayout( 0, 0, 6, "layout18_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout18_2->addWidget( textLabel4_2 );

    QLEEBodegas = new QLineEdit( this, "QLEEBodegas" );
    QLEEBodegas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEEBodegas->sizePolicy().hasHeightForWidth() ) );
    layout18_2->addWidget( QLEEBodegas );
    layout23->addLayout( layout18_2 );

    RastreoProductoLayout->addLayout( layout23, 0, 3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "0" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "1" ) );
    QTDatos->setNumRows( QTDatos->numRows() + 1 );
    QTDatos->verticalHeader()->setLabel( QTDatos->numRows() - 1, tr( "0" ) );
    QTDatos->setNumRows( QTDatos->numRows() + 1 );
    QTDatos->verticalHeader()->setLabel( QTDatos->numRows() - 1, tr( "1" ) );
    QTDatos->setNumRows( QTDatos->numRows() + 1 );
    QTDatos->verticalHeader()->setLabel( QTDatos->numRows() - 1, tr( "2" ) );
    QTDatos->setNumRows( QTDatos->numRows() + 1 );
    QTDatos->verticalHeader()->setLabel( QTDatos->numRows() - 1, tr( "3" ) );
    QTDatos->setNumRows( QTDatos->numRows() + 1 );
    QTDatos->verticalHeader()->setLabel( QTDatos->numRows() - 1, tr( "4" ) );
    QTDatos->setNumRows( QTDatos->numRows() + 1 );
    QTDatos->verticalHeader()->setLabel( QTDatos->numRows() - 1, tr( "5" ) );
    QTDatos->setNumRows( 6 );
    QTDatos->setNumCols( 2 );
    QTDatos->setReadOnly( TRUE );

    RastreoProductoLayout->addMultiCellWidget( QTDatos, 1, 1, 0, 3 );

    QPBPCDesajuste = new QPushButton( this, "QPBPCDesajuste" );

    RastreoProductoLayout->addMultiCellWidget( QPBPCDesajuste, 2, 2, 0, 3 );
    languageChange();
    resize( QSize(912, 688).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RastreoProducto::~RastreoProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RastreoProducto::languageChange()
{
    setCaption( tr( "Rastreo De Productos" ) );
    textLabel3->setText( tr( "Fecha Referencia Inicio" ) );
    textLabel3_3->setText( tr( "Fecha Referencia Fin" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel4->setText( tr( "Existencia Expendio" ) );
    textLabel4_2->setText( tr( "Bodegas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "0" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "1" ) );
    QTDatos->verticalHeader()->setLabel( 0, tr( "0" ) );
    QTDatos->verticalHeader()->setLabel( 1, tr( "1" ) );
    QTDatos->verticalHeader()->setLabel( 2, tr( "2" ) );
    QTDatos->verticalHeader()->setLabel( 3, tr( "3" ) );
    QTDatos->verticalHeader()->setLabel( 4, tr( "4" ) );
    QTDatos->verticalHeader()->setLabel( 5, tr( "5" ) );
    QPBPCDesajuste->setText( tr( "Productos Con Desajuste Inventario" ) );
}

