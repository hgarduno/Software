/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/TransferenciaParcial.ui'
**
** Created: Sat Jan 27 16:37:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "TransferenciaParcial.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a TransferenciaParcial as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
TransferenciaParcial::TransferenciaParcial( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "TransferenciaParcial" );
    TransferenciaParcialLayout = new QGridLayout( this, 1, 1, 11, 6, "TransferenciaParcialLayout"); 

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    QTProductos = new QTable( groupBox1, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Modelo" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "CodigoBarras" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Observacion" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, trUtf8( "\xc2\xbf\x52\x65\x63\x69\x62\x69\x72\x20\x3f" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Motivo" ) );
    QTProductos->setNumRows( QTProductos->numRows() + 1 );
    QTProductos->verticalHeader()->setLabel( QTProductos->numRows() - 1, tr( "0" ) );
    QTProductos->setNumRows( QTProductos->numRows() + 1 );
    QTProductos->verticalHeader()->setLabel( QTProductos->numRows() - 1, tr( "1" ) );
    QTProductos->setNumRows( QTProductos->numRows() + 1 );
    QTProductos->verticalHeader()->setLabel( QTProductos->numRows() - 1, tr( "2" ) );
    QTProductos->setNumRows( QTProductos->numRows() + 1 );
    QTProductos->verticalHeader()->setLabel( QTProductos->numRows() - 1, tr( "3" ) );
    QTProductos->setNumRows( QTProductos->numRows() + 1 );
    QTProductos->verticalHeader()->setLabel( QTProductos->numRows() - 1, tr( "4" ) );
    QTProductos->setNumRows( 5 );
    QTProductos->setNumCols( 7 );
    QTProductos->setReadOnly( FALSE );

    groupBox1Layout->addWidget( QTProductos, 0, 0 );

    TransferenciaParcialLayout->addMultiCellWidget( groupBox1, 0, 0, 0, 1 );

    layout89 = new QHBoxLayout( 0, 0, 6, "layout89"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout89->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout89->addWidget( QPBCancelar );

    TransferenciaParcialLayout->addLayout( layout89, 1, 1 );
    spacer1 = new QSpacerItem( 340, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    TransferenciaParcialLayout->addItem( spacer1, 1, 0 );
    languageChange();
    resize( QSize(1147, 412).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
TransferenciaParcial::~TransferenciaParcial()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TransferenciaParcial::languageChange()
{
    setCaption( tr( "Recibir  Productos Parcialmente" ) );
    groupBox1->setTitle( tr( "Seleccion de productos por recibir" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "CodigoBarras" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "Observacion" ) );
    QTProductos->horizontalHeader()->setLabel( 5, trUtf8( "\xc2\xbf\x52\x65\x63\x69\x62\x69\x72\x20\x3f" ) );
    QTProductos->horizontalHeader()->setLabel( 6, tr( "Motivo" ) );
    QTProductos->verticalHeader()->setLabel( 0, tr( "0" ) );
    QTProductos->verticalHeader()->setLabel( 1, tr( "1" ) );
    QTProductos->verticalHeader()->setLabel( 2, tr( "2" ) );
    QTProductos->verticalHeader()->setLabel( 3, tr( "3" ) );
    QTProductos->verticalHeader()->setLabel( 4, tr( "4" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

