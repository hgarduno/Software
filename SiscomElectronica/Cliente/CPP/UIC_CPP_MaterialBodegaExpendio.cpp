/****************************************************************************
** Form implementation generated from reading ui file 'UI/MaterialBodegaExpendio.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_MaterialBodegaExpendio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <QCtrlProdSiscomElectronica.h>
#include <qlineedit.h>
#include <QCtrlBodegas.h>
#include <QCtrlExpendios.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProdSiscomElectronica.h"
#include "QCtrlBodegas.h"
#include "QCtrlExpendios.h"

/*
 *  Constructs a MaterialBodegaExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
MaterialBodegaExpendio::MaterialBodegaExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "MaterialBodegaExpendio" );
    setEnabled( TRUE );
    MaterialBodegaExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "MaterialBodegaExpendioLayout"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel1_2_2 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    layout3->addWidget( QTDatos );

    MaterialBodegaExpendioLayout->addMultiCellLayout( layout3, 2, 2, 0, 3 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1_2_2_2 = new QLabel( this, "textLabel1_2_2_2" );
    textLabel1_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( textLabel1_2_2_2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( QTEDescripcion );

    MaterialBodegaExpendioLayout->addMultiCellLayout( layout6, 3, 3, 0, 3 );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );

    MaterialBodegaExpendioLayout->addWidget( QPBAnexar, 4, 0 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );

    MaterialBodegaExpendioLayout->addMultiCellWidget( QPBRegistrar, 4, 4, 1, 2 );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );

    MaterialBodegaExpendioLayout->addWidget( QPBEliminar, 4, 3 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel1_2 );

    QCtrProductos = new QCtrlProdSiscomElectronica( this, "QCtrProductos" );
    layout2->addWidget( QCtrProductos );
    layout15->addLayout( layout2 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel1_4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setReadOnly( FALSE );
    layout8->addWidget( QLECantidad );
    layout15->addLayout( layout8 );

    layout8_2 = new QVBoxLayout( 0, 0, 6, "layout8_2"); 

    textLabel1_4_2 = new QLabel( this, "textLabel1_4_2" );
    textLabel1_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_4_2->sizePolicy().hasHeightForWidth() ) );
    layout8_2->addWidget( textLabel1_4_2 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    QLEExistencia->setReadOnly( TRUE );
    layout8_2->addWidget( QLEExistencia );
    layout15->addLayout( layout8_2 );
    spacer1 = new QSpacerItem( 140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout15->addItem( spacer1 );

    MaterialBodegaExpendioLayout->addMultiCellLayout( layout15, 1, 1, 0, 3 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1_3 );

    QCtrBodegas = new QCtrlBodegas( this, "QCtrBodegas" );
    QCtrBodegas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrBodegas->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( QCtrBodegas );

    MaterialBodegaExpendioLayout->addMultiCellLayout( layout7, 0, 0, 0, 1 );

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout6_2->addWidget( textLabel1 );

    QCtrExpendios = new QCtrlExpendios( this, "QCtrExpendios" );
    QCtrExpendios->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrExpendios->sizePolicy().hasHeightForWidth() ) );
    layout6_2->addWidget( QCtrExpendios );

    MaterialBodegaExpendioLayout->addMultiCellLayout( layout6_2, 0, 0, 2, 3 );
    languageChange();
    resize( QSize(600, 621).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MaterialBodegaExpendio::~MaterialBodegaExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MaterialBodegaExpendio::languageChange()
{
    setCaption( tr( "Transfiriendo Material" ) );
    textLabel1_2_2->setText( tr( "Productos" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Existencia" ) );
    textLabel1_2_2_2->setText( tr( "Producto" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBEliminar->setText( tr( "Elimina Producto" ) );
    textLabel1_2->setText( tr( "Productos" ) );
    textLabel1_4->setText( tr( "Cantidad" ) );
    textLabel1_4_2->setText( tr( "Existencia" ) );
    textLabel1_3->setText( tr( "Bodegas" ) );
    textLabel1->setText( tr( "Expendios" ) );
}

