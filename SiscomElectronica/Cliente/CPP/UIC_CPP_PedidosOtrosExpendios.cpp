/****************************************************************************
** Form implementation generated from reading ui file 'UI/PedidosOtrosExpendios.ui'
**
** Created: Thu Apr 11 21:39:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PedidosOtrosExpendios.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a PedidosOtrosExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PedidosOtrosExpendios::PedidosOtrosExpendios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PedidosOtrosExpendios" );
    PedidosOtrosExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "PedidosOtrosExpendiosLayout"); 

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
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Destino" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout3->addWidget( QTDatos );

    PedidosOtrosExpendiosLayout->addMultiCellLayout( layout3, 0, 0, 0, 1 );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( TRUE );

    PedidosOtrosExpendiosLayout->addWidget( QPBActualizar, 1, 0 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setEnabled( FALSE );

    PedidosOtrosExpendiosLayout->addWidget( QPBImprimir, 1, 1 );
    languageChange();
    resize( QSize(626, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PedidosOtrosExpendios::~PedidosOtrosExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PedidosOtrosExpendios::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_2_2->setText( tr( "Productos" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Destino" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
}

