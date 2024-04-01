/****************************************************************************
** Form implementation generated from reading ui file 'UI/ExistenciaExpendios.ui'
**
** Created: Wed Jan 31 10:48:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ExistenciaExpendios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <QCtrlProductosSE.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProductosSE.h"

/*
 *  Constructs a ExistenciaExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ExistenciaExpendios::ExistenciaExpendios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ExistenciaExpendios" );
    ExistenciaExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "ExistenciaExpendiosLayout"); 

    tabWidget2 = new QTabWidget( this, "tabWidget2" );

    tab = new QWidget( tabWidget2, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( tab, "textLabel2" );
    layout3->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProductosSE( tab, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrProductos );
    layout7->addLayout( layout3 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel2_2 = new QLabel( tab, "textLabel2_2" );
    layout8->addWidget( textLabel2_2 );

    QTExistenciaExpendios = new QTable( tab, "QTExistenciaExpendios" );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Producto" ) );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Expendio" ) );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Existencia" ) );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Precio" ) );
    QTExistenciaExpendios->setNumRows( 0 );
    QTExistenciaExpendios->setNumCols( 4 );
    QTExistenciaExpendios->setReadOnly( TRUE );
    layout8->addWidget( QTExistenciaExpendios );
    layout7->addLayout( layout8 );

    tabLayout->addMultiCellLayout( layout7, 0, 0, 0, 1 );

    QPBAnexar = new QPushButton( tab, "QPBAnexar" );

    tabLayout->addWidget( QPBAnexar, 1, 0 );

    QPBActualizar = new QPushButton( tab, "QPBActualizar" );

    tabLayout->addWidget( QPBActualizar, 1, 1 );
    tabWidget2->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget2, "tab_2" );
    tabWidget2->insertTab( tab_2, QString::fromLatin1("") );

    ExistenciaExpendiosLayout->addWidget( tabWidget2, 0, 0 );
    languageChange();
    resize( QSize(707, 476).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ExistenciaExpendios::~ExistenciaExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ExistenciaExpendios::languageChange()
{
    setCaption( tr( "Existencias Expendios" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel2_2->setText( tr( "Existencias Producto Expendios" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 1, tr( "Expendio" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 2, tr( "Existencia" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 3, tr( "Precio" ) );
    QPBAnexar->setText( tr( "Anexar a La Lista" ) );
    QPBActualizar->setText( tr( "Actualiza" ) );
    tabWidget2->changeTab( tab, tr( "Producto En Expendios" ) );
    tabWidget2->changeTab( tab_2, tr( "Tab 2" ) );
}

