/****************************************************************************
** Form implementation generated from reading ui file 'UI/Inventario.ui'
**
** Created: Wed Jan 31 10:58:01 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Inventario.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <QCtrlMotivoInventario.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlMotivoInventario.h"

/*
 *  Constructs a Inventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Inventario::Inventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Inventario" );
    InventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "InventarioLayout"); 

    layout37 = new QVBoxLayout( 0, 0, 6, "layout37"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout37->addWidget( textLabel3 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setReadOnly( TRUE );
    layout37->addWidget( QLEDescripcion );

    InventarioLayout->addMultiCellLayout( layout37, 2, 2, 0, 1 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout6->addWidget( textLabel1_2 );

    QCtrMotivoInventario = new QCtrlMotivoInventario( this, "QCtrMotivoInventario" );
    QCtrMotivoInventario->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrMotivoInventario->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( QCtrMotivoInventario );

    InventarioLayout->addLayout( layout6, 0, 0 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1_3 );

    QLEInventario = new QLineEdit( this, "QLEInventario" );
    QLEInventario->setReadOnly( TRUE );
    layout7->addWidget( QLEInventario );

    InventarioLayout->addLayout( layout7, 0, 1 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout10->addWidget( QPBRegistrar );

    QPBActualiza = new QPushButton( this, "QPBActualiza" );
    layout10->addWidget( QPBActualiza );

    QPBActivaMotivo = new QPushButton( this, "QPBActivaMotivo" );
    layout10->addWidget( QPBActivaMotivo );

    InventarioLayout->addMultiCellLayout( layout10, 3, 3, 0, 1 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCBProductos->sizePolicy().hasHeightForWidth() ) );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout2->addWidget( QCBProductos );
    layout15->addLayout( layout2 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout1->addWidget( QLECantidad );
    layout15->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    layout1_2->addWidget( textLabel1_4 );

    QLEExistenciaFisica = new QLineEdit( this, "QLEExistenciaFisica" );
    QLEExistenciaFisica->setReadOnly( TRUE );
    layout1_2->addWidget( QLEExistenciaFisica );
    layout15->addLayout( layout1_2 );

    InventarioLayout->addMultiCellLayout( layout15, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(557, 476).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Inventario::~Inventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Inventario::languageChange()
{
    setCaption( tr( "Actualiza Inventario" ) );
    textLabel3->setText( tr( "Descripcion" ) );
    textLabel1_2->setText( tr( "Motivo Inventario" ) );
    textLabel1_3->setText( tr( "Inventario" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBActualiza->setText( tr( "Actualizar Registro" ) );
    QPBActivaMotivo->setText( tr( "Activa Motivo Inventario" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel1->setText( tr( "Cantidad" ) );
    textLabel1_4->setText( tr( "Existencia Fisica" ) );
}

