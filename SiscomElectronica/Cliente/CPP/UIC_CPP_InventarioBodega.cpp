/****************************************************************************
** Form implementation generated from reading ui file 'UI/InventarioBodega.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_InventarioBodega.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlBodegas.h>
#include <QCtrlProdSiscomElectronica.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlBodegas.h"
#include "QCtrlProdSiscomElectronica.h"

/*
 *  Constructs a InventarioBodega as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
InventarioBodega::InventarioBodega( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "InventarioBodega" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, sizePolicy().hasHeightForWidth() ) );
    InventarioBodegaLayout = new QGridLayout( this, 1, 1, 11, 6, "InventarioBodegaLayout"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1_4 );

    QCtrBodegas = new QCtrlBodegas( this, "QCtrBodegas" );
    QCtrBodegas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrBodegas->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( QCtrBodegas );

    InventarioBodegaLayout->addLayout( layout7, 0, 0 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProdSiscomElectronica( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrProductos );
    layout9->addLayout( layout1 );

    layout4_2 = new QVBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel1_3_2 = new QLabel( this, "textLabel1_3_2" );
    textLabel1_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3_2->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( textLabel1_3_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    QLECantidad->setReadOnly( FALSE );
    layout4_2->addWidget( QLECantidad );
    layout9->addLayout( layout4_2 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( textLabel1_3 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    QLEExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEExistencia->sizePolicy().hasHeightForWidth() ) );
    QLEExistencia->setReadOnly( TRUE );
    layout4->addWidget( QLEExistencia );
    layout9->addLayout( layout4 );
    layout10->addLayout( layout9 );
    spacer1 = new QSpacerItem( 188, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout10->addItem( spacer1 );

    InventarioBodegaLayout->addLayout( layout10, 1, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel1_2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QTEDescripcion );

    InventarioBodegaLayout->addLayout( layout2, 2, 0 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout3->addWidget( QPBRegistrar );

    QPBActivaBodegas = new QPushButton( this, "QPBActivaBodegas" );
    layout3->addWidget( QPBActivaBodegas );

    InventarioBodegaLayout->addLayout( layout3, 3, 0 );
    languageChange();
    resize( QSize(623, 299).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
InventarioBodega::~InventarioBodega()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void InventarioBodega::languageChange()
{
    setCaption( tr( "Capturando El Inventario de la bodega" ) );
    textLabel1_4->setText( tr( "Bodegas" ) );
    textLabel1->setText( tr( "Producto" ) );
    textLabel1_3_2->setText( tr( "Cantidad" ) );
    textLabel1_3->setText( tr( "Existencia Actual" ) );
    textLabel1_2->setText( tr( "Descripcion" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBActivaBodegas->setText( tr( "Activa Bodegas" ) );
}

