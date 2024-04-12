/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaPrecios.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaPrecios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlFamilias.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlFamilias.h"

/*
 *  Constructs a ActualizaPrecios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActualizaPrecios::ActualizaPrecios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActualizaPrecios" );
    ActualizaPreciosLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaPreciosLayout"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel1 );

    QCtrFamilias = new QCtrlFamilias( this, "QCtrFamilias" );
    QCtrFamilias->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrFamilias->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( QCtrFamilias );
    layout13->addLayout( layout9 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Clave" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Descripcion" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Fecha" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Proveedor" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Precio Compra" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 6 );
    layout13->addWidget( QTProductos );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    layout10->addWidget( QPBConsulta );

    pushButton5_3 = new QPushButton( this, "pushButton5_3" );
    layout10->addWidget( pushButton5_3 );

    pushButton5_4 = new QPushButton( this, "pushButton5_4" );
    layout10->addWidget( pushButton5_4 );

    pushButton5_2 = new QPushButton( this, "pushButton5_2" );
    layout10->addWidget( pushButton5_2 );
    layout13->addLayout( layout10 );

    ActualizaPreciosLayout->addLayout( layout13, 0, 0 );
    languageChange();
    resize( QSize(750, 487).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaPrecios::~ActualizaPrecios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaPrecios::languageChange()
{
    setCaption( tr( "Controlador de precios" ) );
    textLabel1->setText( tr( "Familias" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Clave" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Fecha" ) );
    QTProductos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 4, tr( "Proveedor" ) );
    QTProductos->horizontalHeader()->setLabel( 5, tr( "Precio Compra" ) );
    QPBConsulta->setText( tr( "pushButton5" ) );
    pushButton5_3->setText( tr( "pushButton5" ) );
    pushButton5_4->setText( tr( "pushButton5" ) );
    pushButton5_2->setText( tr( "pushButton5" ) );
}

