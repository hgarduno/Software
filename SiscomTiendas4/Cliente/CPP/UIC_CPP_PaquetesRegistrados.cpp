/****************************************************************************
** Form implementation generated from reading ui file 'UI/PaquetesRegistrados.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PaquetesRegistrados.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a PaquetesRegistrados as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PaquetesRegistrados::PaquetesRegistrados( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PaquetesRegistrados" );
    PaquetesRegistradosLayout = new QGridLayout( this, 1, 1, 11, 6, "PaquetesRegistradosLayout"); 

    QPBEliminar = new QPushButton( this, "QPBEliminar" );

    PaquetesRegistradosLayout->addMultiCellWidget( QPBEliminar, 1, 1, 0, 1 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout12->addWidget( textLabel3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Clave" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout12->addWidget( QTDatos );

    PaquetesRegistradosLayout->addLayout( layout12, 0, 0 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout12_2->addWidget( textLabel3_2 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Descripcion" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 3 );
    QTProductos->setReadOnly( TRUE );
    layout12_2->addWidget( QTProductos );
    layout4->addLayout( layout12_2 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    QPBAPaquete = new QPushButton( this, "QPBAPaquete" );
    layout3->addWidget( QPBAPaquete );

    QPBEProducto = new QPushButton( this, "QPBEProducto" );
    layout3->addWidget( QPBEProducto );
    layout4->addLayout( layout3 );

    PaquetesRegistradosLayout->addLayout( layout4, 0, 1 );
    languageChange();
    resize( QSize(750, 487).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PaquetesRegistrados::~PaquetesRegistrados()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PaquetesRegistrados::languageChange()
{
    setCaption( tr( "Paquetes Registrados" ) );
    QPBEliminar->setText( tr( "Eliminar Paquete" ) );
    textLabel3->setText( tr( "Productos Del Paquete" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Clave" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    textLabel3_2->setText( tr( "Productos Del Paquete" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QPBAPaquete->setText( tr( "Anexar Producto" ) );
    QPBEProducto->setText( tr( "Eliminar Producto" ) );
}

