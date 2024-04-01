/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorProductos4.ui'
**
** Created: Wed Jan 31 10:48:13 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorProductos4.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlProductosSE.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <QCtrlCajasUbicacion.h>
#include <QCtrlEstantes.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"
#include "QCtrlCajasUbicacion.h"
#include "QCtrlEstantes.h"

/*
 *  Constructs a ManejadorProductos4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorProductos4::ManejadorProductos4( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorProductos4" );
    ManejadorProductos4Layout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorProductos4Layout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    layout1->addWidget( QCtrProductos );

    ManejadorProductos4Layout->addMultiCellLayout( layout1, 0, 0, 0, 2 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout3->addWidget( textLabel3 );

    QTUbicacion = new QTable( this, "QTUbicacion" );
    QTUbicacion->setNumCols( QTUbicacion->numCols() + 1 );
    QTUbicacion->horizontalHeader()->setLabel( QTUbicacion->numCols() - 1, tr( "Producto" ) );
    QTUbicacion->setNumCols( QTUbicacion->numCols() + 1 );
    QTUbicacion->horizontalHeader()->setLabel( QTUbicacion->numCols() - 1, tr( "Estante" ) );
    QTUbicacion->setNumCols( QTUbicacion->numCols() + 1 );
    QTUbicacion->horizontalHeader()->setLabel( QTUbicacion->numCols() - 1, tr( "Caja" ) );
    QTUbicacion->setNumRows( 0 );
    QTUbicacion->setNumCols( 3 );
    QTUbicacion->setReadOnly( TRUE );
    layout3->addWidget( QTUbicacion );
    layout6->addLayout( layout3 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setReadOnly( TRUE );
    layout2->addWidget( QTEDescripcion );
    layout6->addLayout( layout2 );

    ManejadorProductos4Layout->addMultiCellLayout( layout6, 2, 2, 0, 6 );

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout9->addWidget( textLabel2_2 );

    QLECveProducto = new QLineEdit( this, "QLECveProducto" );
    QLECveProducto->setReadOnly( TRUE );
    layout9->addWidget( QLECveProducto );
    layout11->addLayout( layout9 );

    layout9_2 = new QVBoxLayout( 0, 0, 6, "layout9_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    layout9_2->addWidget( textLabel2_2_2 );

    QLECaja = new QLineEdit( this, "QLECaja" );
    QLECaja->setReadOnly( TRUE );
    layout9_2->addWidget( QLECaja );
    layout11->addLayout( layout9_2 );

    ManejadorProductos4Layout->addMultiCellLayout( layout11, 1, 1, 0, 6 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout5->addWidget( textLabel1_2 );

    QCtrCajas = new QCtrlCajasUbicacion( this, "QCtrCajas" );
    QCtrCajas->setEnabled( FALSE );
    layout5->addWidget( QCtrCajas );

    ManejadorProductos4Layout->addMultiCellLayout( layout5, 0, 0, 5, 6 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout10->addWidget( textLabel1_3 );

    QCtrEstantes = new QCtrlEstantes( this, "QCtrEstantes" );
    QCtrEstantes->setEnabled( FALSE );
    layout10->addWidget( QCtrEstantes );

    ManejadorProductos4Layout->addMultiCellLayout( layout10, 0, 0, 3, 4 );

    QPBAsignarUbicacion = new QPushButton( this, "QPBAsignarUbicacion" );
    QPBAsignarUbicacion->setEnabled( FALSE );

    ManejadorProductos4Layout->addWidget( QPBAsignarUbicacion, 3, 0 );

    QPBAsigCajaDeDescripcion = new QPushButton( this, "QPBAsigCajaDeDescripcion" );
    QPBAsigCajaDeDescripcion->setEnabled( FALSE );

    ManejadorProductos4Layout->addWidget( QPBAsigCajaDeDescripcion, 3, 4 );

    QPBRegistrarCaja = new QPushButton( this, "QPBRegistrarCaja" );

    ManejadorProductos4Layout->addWidget( QPBRegistrarCaja, 3, 6 );

    QPBRegistrarCaja_2 = new QPushButton( this, "QPBRegistrarCaja_2" );

    ManejadorProductos4Layout->addWidget( QPBRegistrarCaja_2, 3, 5 );

    pushButton5 = new QPushButton( this, "pushButton5" );
    pushButton5->setEnabled( FALSE );

    ManejadorProductos4Layout->addWidget( pushButton5, 3, 1 );

    pushButton5_2 = new QPushButton( this, "pushButton5_2" );
    pushButton5_2->setEnabled( FALSE );

    ManejadorProductos4Layout->addMultiCellWidget( pushButton5_2, 3, 3, 2, 3 );
    languageChange();
    resize( QSize(796, 399).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorProductos4::~ManejadorProductos4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorProductos4::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel3->setText( tr( "Productos" ) );
    QTUbicacion->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTUbicacion->horizontalHeader()->setLabel( 1, tr( "Estante" ) );
    QTUbicacion->horizontalHeader()->setLabel( 2, tr( "Caja" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    textLabel2_2->setText( tr( "Producto" ) );
    textLabel2_2_2->setText( tr( "Ubicacion" ) );
    textLabel1_2->setText( tr( "Caja" ) );
    textLabel1_3->setText( tr( "Estantes" ) );
    QPBAsignarUbicacion->setText( tr( "Asignar Ubicacion" ) );
    QPBAsigCajaDeDescripcion->setText( tr( "Asigna Caja de La Descripcion" ) );
    QToolTip::add( QPBAsigCajaDeDescripcion, tr( "Solo para probar" ) );
    QPBRegistrarCaja->setText( tr( "Registrar Caja" ) );
    QPBRegistrarCaja_2->setText( tr( "Registrar Estante" ) );
    pushButton5->setText( tr( "Productos Ubicacion" ) );
    pushButton5_2->setText( tr( "Productos Por Caja" ) );
}

