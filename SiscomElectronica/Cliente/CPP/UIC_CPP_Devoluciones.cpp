/****************************************************************************
** Form implementation generated from reading ui file 'UI/Devoluciones.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Devoluciones.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Devoluciones as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Devoluciones::Devoluciones( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Devoluciones" );
    DevolucionesLayout = new QGridLayout( this, 1, 1, 11, 6, "DevolucionesLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLENoOrden = new QLineEdit( this, "QLENoOrden" );
    layout1->addWidget( QLENoOrden );
    layout4->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLEFecha = new QLineEdit( this, "QLEFecha" );
    layout1_2->addWidget( QLEFecha );
    layout4->addLayout( layout1_2 );

    DevolucionesLayout->addLayout( layout4, 0, 0 );

    QTPOrden = new QTable( this, "QTPOrden" );
    QTPOrden->setNumCols( QTPOrden->numCols() + 1 );
    QTPOrden->horizontalHeader()->setLabel( QTPOrden->numCols() - 1, tr( "Producto" ) );
    QTPOrden->setNumCols( QTPOrden->numCols() + 1 );
    QTPOrden->horizontalHeader()->setLabel( QTPOrden->numCols() - 1, tr( "Cantidad" ) );
    QTPOrden->setNumCols( QTPOrden->numCols() + 1 );
    QTPOrden->horizontalHeader()->setLabel( QTPOrden->numCols() - 1, tr( "Precio" ) );
    QTPOrden->setNumCols( QTPOrden->numCols() + 1 );
    QTPOrden->horizontalHeader()->setLabel( QTPOrden->numCols() - 1, tr( "Total" ) );
    QTPOrden->setNumRows( 0 );
    QTPOrden->setNumCols( 4 );
    QTPOrden->setReadOnly( TRUE );

    DevolucionesLayout->addWidget( QTPOrden, 2, 0 );

    textLabel3 = new QLabel( this, "textLabel3" );

    DevolucionesLayout->addWidget( textLabel3, 3, 0 );

    textLabel2 = new QLabel( this, "textLabel2" );

    DevolucionesLayout->addWidget( textLabel2, 1, 0 );

    QTPDevolver = new QTable( this, "QTPDevolver" );
    QTPDevolver->setNumCols( QTPDevolver->numCols() + 1 );
    QTPDevolver->horizontalHeader()->setLabel( QTPDevolver->numCols() - 1, tr( "Producto" ) );
    QTPDevolver->setNumCols( QTPDevolver->numCols() + 1 );
    QTPDevolver->horizontalHeader()->setLabel( QTPDevolver->numCols() - 1, tr( "Cantidad" ) );
    QTPDevolver->setNumCols( QTPDevolver->numCols() + 1 );
    QTPDevolver->horizontalHeader()->setLabel( QTPDevolver->numCols() - 1, tr( "Precio" ) );
    QTPDevolver->setNumCols( QTPDevolver->numCols() + 1 );
    QTPDevolver->horizontalHeader()->setLabel( QTPDevolver->numCols() - 1, tr( "Total" ) );
    QTPDevolver->setNumRows( 0 );
    QTPDevolver->setNumCols( 4 );
    QTPDevolver->setReadOnly( TRUE );

    DevolucionesLayout->addWidget( QTPDevolver, 4, 0 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    QPBDevuelve = new QPushButton( this, "QPBDevuelve" );
    QPBDevuelve->setMinimumSize( QSize( 0, 40 ) );
    layout7->addWidget( QPBDevuelve );

    pushButton1 = new QPushButton( this, "pushButton1" );
    pushButton1->setMinimumSize( QSize( 0, 40 ) );
    layout7->addWidget( pushButton1 );
    layout9->addLayout( layout7 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2->addWidget( textLabel2_2_2 );

    QLCDNTDevolver = new QLCDNumber( this, "QLCDNTDevolver" );
    QLCDNTDevolver->setNumDigits( 7 );
    layout5_2->addWidget( QLCDNTDevolver );
    layout8->addLayout( layout5_2 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel2_2 );

    QLCDNTOrden = new QLCDNumber( this, "QLCDNTOrden" );
    QLCDNTOrden->setNumDigits( 7 );
    layout5->addWidget( QLCDNTOrden );
    layout8->addLayout( layout5 );
    layout9->addLayout( layout8 );

    DevolucionesLayout->addLayout( layout9, 5, 0 );
    languageChange();
    resize( QSize(600, 577).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Devoluciones::~Devoluciones()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Devoluciones::languageChange()
{
    setCaption( tr( "Devoluciones Siscom" ) );
    textLabel1->setText( tr( "No De Orden" ) );
    QLENoOrden->setText( tr( "1346589051" ) );
    textLabel1_2->setText( tr( "Fecha Venta" ) );
    QTPOrden->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTPOrden->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTPOrden->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTPOrden->horizontalHeader()->setLabel( 3, tr( "Total" ) );
    textLabel3->setText( tr( "Productos A Devolver" ) );
    textLabel2->setText( tr( "Productos De La Orden" ) );
    QTPDevolver->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTPDevolver->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTPDevolver->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTPDevolver->horizontalHeader()->setLabel( 3, tr( "Total" ) );
    QPBDevuelve->setText( tr( "Ejecutar \n"
"Devolucion" ) );
    pushButton1->setText( tr( "pushButton1" ) );
    textLabel2_2_2->setText( tr( "Total A Devolver" ) );
    textLabel2_2->setText( tr( "Total Orden" ) );
}

