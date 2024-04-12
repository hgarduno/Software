/****************************************************************************
** Form implementation generated from reading ui file 'UI/InventarioBodega4.ui'
**
** Created: Thu Apr 11 21:40:00 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_InventarioBodega4.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlProductosSE.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProductosSE.h"

/*
 *  Constructs a InventarioBodega4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
InventarioBodega4::InventarioBodega4( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "InventarioBodega4" );
    InventarioBodega4Layout = new QGridLayout( this, 1, 1, 11, 6, "InventarioBodega4Layout"); 

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCtrProductos );
    layout5->addLayout( layout2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout3->addWidget( textLabel3 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout3->addWidget( QLECantidad );
    layout5->addLayout( layout3 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout3_2->addWidget( textLabel3_2 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    QLEExistencia->setEnabled( TRUE );
    QLEExistencia->setReadOnly( TRUE );
    layout3_2->addWidget( QLEExistencia );
    layout5->addLayout( layout3_2 );

    InventarioBodega4Layout->addLayout( layout5, 0, 0 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    QPBActualiza = new QPushButton( this, "QPBActualiza" );
    layout7->addWidget( QPBActualiza );

    InventarioBodega4Layout->addLayout( layout7, 3, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout6->addWidget( textLabel4 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Bodega" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );
    QTDatos->setReadOnly( TRUE );
    layout6->addWidget( QTDatos );

    InventarioBodega4Layout->addLayout( layout6, 2, 0 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout8->addWidget( textLabel5 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( QTEDescripcion );

    InventarioBodega4Layout->addLayout( layout8, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
InventarioBodega4::~InventarioBodega4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void InventarioBodega4::languageChange()
{
    setCaption( tr( "Form2" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel3->setText( tr( "Cantidad" ) );
    textLabel3_2->setText( tr( "Existencia" ) );
    QPBActualiza->setText( tr( "Actualiza" ) );
    textLabel4->setText( tr( "Capturas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Bodega" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Existencia" ) );
    textLabel5->setText( tr( "Descripcion" ) );
}

