/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaPrecioExpendios.ui'
**
** Created: Wed Apr 10 20:52:38 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaPrecioExpendios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <QCtrlProductosSE.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <QCtrlExpendios.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProductosSE.h"
#include "QCtrlExpendios.h"

/*
 *  Constructs a ActualizaPrecioExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActualizaPrecioExpendios::ActualizaPrecioExpendios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActualizaPrecioExpendios" );
    ActualizaPrecioExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaPrecioExpendiosLayout"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout31->addWidget( textLabel4 );

    QCBTipoPrecio = new QComboBox( FALSE, this, "QCBTipoPrecio" );
    QCBTipoPrecio->setEditable( TRUE );
    QCBTipoPrecio->setInsertionPolicy( QComboBox::NoInsertion );
    QCBTipoPrecio->setAutoCompletion( TRUE );
    QCBTipoPrecio->setDuplicatesEnabled( FALSE );
    layout31->addWidget( QCBTipoPrecio );
    layout12->addLayout( layout31 );

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout8->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    layout8->addWidget( QCtrProductos );
    layout11->addLayout( layout8 );

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout33->addWidget( textLabel5 );

    QLEPVenta = new QLineEdit( this, "QLEPVenta" );
    QLEPVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPVenta->sizePolicy().hasHeightForWidth() ) );
    QLEPVenta->setReadOnly( TRUE );
    layout33->addWidget( QLEPVenta );
    layout11->addLayout( layout33 );

    layout33_2 = new QVBoxLayout( 0, 0, 6, "layout33_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout33_2->addWidget( textLabel5_2 );

    QLENvoPrecio = new QLineEdit( this, "QLENvoPrecio" );
    QLENvoPrecio->setEnabled( FALSE );
    QLENvoPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENvoPrecio->sizePolicy().hasHeightForWidth() ) );
    layout33_2->addWidget( QLENvoPrecio );
    layout11->addLayout( layout33_2 );
    layout12->addLayout( layout11 );

    ActualizaPrecioExpendiosLayout->addLayout( layout12, 0, 0 );

    layout52 = new QVBoxLayout( 0, 0, 6, "layout52"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout52->addWidget( textLabel6 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout52->addWidget( QLEDescripcion );

    ActualizaPrecioExpendiosLayout->addLayout( layout52, 1, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( textLabel1_2 );

    QCtrExpendiosO = new QCtrlExpendios( this, "QCtrExpendiosO" );
    QCtrExpendiosO->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCtrExpendiosO->sizePolicy().hasHeightForWidth() ) );
    layout6->addWidget( QCtrExpendiosO );

    ActualizaPrecioExpendiosLayout->addLayout( layout6, 2, 0 );

    layout40 = new QHBoxLayout( 0, 0, 6, "layout40"); 

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( TRUE );
    layout40->addWidget( QPBActualizar );

    QPBImprimir_2 = new QPushButton( this, "QPBImprimir_2" );
    QPBImprimir_2->setEnabled( FALSE );
    layout40->addWidget( QPBImprimir_2 );

    QPBRegistrar_2 = new QPushButton( this, "QPBRegistrar_2" );
    QPBRegistrar_2->setEnabled( FALSE );
    layout40->addWidget( QPBRegistrar_2 );

    QPBEliminar_2 = new QPushButton( this, "QPBEliminar_2" );
    layout40->addWidget( QPBEliminar_2 );

    ActualizaPrecioExpendiosLayout->addLayout( layout40, 4, 0 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel1_2_2_2_2 = new QLabel( this, "textLabel1_2_2_2_2" );
    textLabel1_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( textLabel1_2_2_2_2 );

    QTExpendios = new QTable( this, "QTExpendios" );
    QTExpendios->setNumCols( QTExpendios->numCols() + 1 );
    QTExpendios->horizontalHeader()->setLabel( QTExpendios->numCols() - 1, tr( "Expendio" ) );
    QTExpendios->setNumRows( 0 );
    QTExpendios->setNumCols( 1 );
    layout3_2->addWidget( QTExpendios );

    ActualizaPrecioExpendiosLayout->addLayout( layout3_2, 3, 0 );
    languageChange();
    resize( QSize(647, 654).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaPrecioExpendios::~ActualizaPrecioExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaPrecioExpendios::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel4->setText( tr( "Tipo De Precio" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel5->setText( tr( "Precio De Venta" ) );
    textLabel5_2->setText( tr( "Precio De Venta Nuevo" ) );
    textLabel6->setText( tr( "Descripcion" ) );
    textLabel1_2->setText( tr( "Expendio Origen" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBImprimir_2->setText( tr( "Imprimir" ) );
    QPBRegistrar_2->setText( tr( "Registrar" ) );
    QPBEliminar_2->setText( tr( "Elimina Producto" ) );
    textLabel1_2_2_2_2->setText( tr( "Expendios" ) );
    QTExpendios->horizontalHeader()->setLabel( 0, tr( "Expendio" ) );
}

