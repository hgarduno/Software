/****************************************************************************
** Form implementation generated from reading ui file 'UI/DispositivosVendidos.ui'
**
** Created: Fri Apr 12 21:26:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DispositivosVendidos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "IMP_QControlFecha.h"

/*
 *  Constructs a DispositivosVendidos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
DispositivosVendidos::DispositivosVendidos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "DispositivosVendidos" );
    DispositivosVendidosLayout = new QGridLayout( this, 1, 1, 11, 6, "DispositivosVendidosLayout"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCFInicio = new CQControlFecha( this, "QCFInicio" );
    QCFInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCFInicio->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCFInicio );
    layout3->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QCFFin = new CQControlFecha( this, "QCFFin" );
    QCFFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCFFin->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCFFin );
    layout3->addLayout( layout2 );

    DispositivosVendidosLayout->addLayout( layout3, 0, 0 );

    layout34 = new QHBoxLayout( 0, 0, 6, "layout34"); 

    pushButton14 = new QPushButton( this, "pushButton14" );
    layout34->addWidget( pushButton14 );

    pushButton15 = new QPushButton( this, "pushButton15" );
    layout34->addWidget( pushButton15 );

    DispositivosVendidosLayout->addMultiCellLayout( layout34, 2, 2, 0, 1 );

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout33->addWidget( textLabel1_2 );

    table10 = new QTable( this, "table10" );
    table10->setNumCols( table10->numCols() + 1 );
    table10->horizontalHeader()->setLabel( table10->numCols() - 1, tr( "Producto" ) );
    table10->setNumCols( table10->numCols() + 1 );
    table10->horizontalHeader()->setLabel( table10->numCols() - 1, tr( "Cantidad" ) );
    table10->setNumRows( 0 );
    table10->setNumCols( 2 );
    layout33->addWidget( table10 );

    DispositivosVendidosLayout->addMultiCellLayout( layout33, 1, 1, 0, 1 );
    spacer2 = new QSpacerItem( 290, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    DispositivosVendidosLayout->addItem( spacer2, 0, 1 );
    languageChange();
    resize( QSize(739, 626).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DispositivosVendidos::~DispositivosVendidos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DispositivosVendidos::languageChange()
{
    setCaption( tr( "Reportes Ventas" ) );
    textLabel1->setText( tr( "Fecha Inicio" ) );
    textLabel2->setText( tr( "Fecha Final" ) );
    pushButton14->setText( tr( "pushButton14" ) );
    pushButton15->setText( tr( "pushButton15" ) );
    textLabel1_2->setText( tr( "Reporte Ventas" ) );
    table10->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    table10->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
}

