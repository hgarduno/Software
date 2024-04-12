/****************************************************************************
** Form implementation generated from reading ui file 'UI/Ganancias.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Ganancias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a Ganancias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Ganancias::Ganancias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Ganancias" );
    GananciasLayout = new QGridLayout( this, 1, 1, 11, 6, "GananciasLayout"); 

    QPFechas = new QPushButton( this, "QPFechas" );
    QPFechas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, QPFechas->sizePolicy().hasHeightForWidth() ) );
    QPFechas->setMinimumSize( QSize( 0, 70 ) );

    GananciasLayout->addWidget( QPFechas, 2, 0 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    QTGFecha = new QTable( this, "QTGFecha" );
    QTGFecha->setNumCols( QTGFecha->numCols() + 1 );
    QTGFecha->horizontalHeader()->setLabel( QTGFecha->numCols() - 1, tr( "Fecha" ) );
    QTGFecha->setNumCols( QTGFecha->numCols() + 1 );
    QTGFecha->horizontalHeader()->setLabel( QTGFecha->numCols() - 1, tr( "Total Ventas" ) );
    QTGFecha->setNumCols( QTGFecha->numCols() + 1 );
    QTGFecha->horizontalHeader()->setLabel( QTGFecha->numCols() - 1, tr( "Gancias" ) );
    QTGFecha->setNumRows( 0 );
    QTGFecha->setNumCols( 3 );
    QTGFecha->setReadOnly( TRUE );
    layout9->addWidget( QTGFecha );

    QTGProducto = new QTable( this, "QTGProducto" );
    QTGProducto->setNumCols( QTGProducto->numCols() + 1 );
    QTGProducto->horizontalHeader()->setLabel( QTGProducto->numCols() - 1, tr( "Producto" ) );
    QTGProducto->setNumCols( QTGProducto->numCols() + 1 );
    QTGProducto->horizontalHeader()->setLabel( QTGProducto->numCols() - 1, tr( "Total Ventas" ) );
    QTGProducto->setNumCols( QTGProducto->numCols() + 1 );
    QTGProducto->horizontalHeader()->setLabel( QTGProducto->numCols() - 1, tr( "Gancias" ) );
    QTGProducto->setNumRows( 0 );
    QTGProducto->setNumCols( 3 );
    QTGProducto->setReadOnly( TRUE );
    layout9->addWidget( QTGProducto );

    GananciasLayout->addLayout( layout9, 1, 0 );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( groupBox1, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLEPeriodo = new QLineEdit( groupBox1, "QLEPeriodo" );
    QLEPeriodo->setReadOnly( TRUE );
    layout1_2->addWidget( QLEPeriodo );

    groupBox1Layout->addLayout( layout1_2, 0, 0 );

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( groupBox1, "textLabel1_2_2" );
    layout1_2_2->addWidget( textLabel1_2_2 );

    QLETotalVentas = new QLineEdit( groupBox1, "QLETotalVentas" );
    QLETotalVentas->setReadOnly( TRUE );
    layout1_2_2->addWidget( QLETotalVentas );

    groupBox1Layout->addLayout( layout1_2_2, 0, 1 );

    layout1_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2"); 

    textLabel1_2_2_2 = new QLabel( groupBox1, "textLabel1_2_2_2" );
    layout1_2_2_2->addWidget( textLabel1_2_2_2 );

    QLEGanancias = new QLineEdit( groupBox1, "QLEGanancias" );
    QLEGanancias->setReadOnly( TRUE );
    layout1_2_2_2->addWidget( QLEGanancias );

    groupBox1Layout->addLayout( layout1_2_2_2, 0, 2 );

    GananciasLayout->addWidget( groupBox1, 0, 0 );
    languageChange();
    resize( QSize(732, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Ganancias::~Ganancias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Ganancias::languageChange()
{
    setCaption( tr( "Ganancias" ) );
    QPFechas->setText( tr( "Rango \n"
"   De \n"
"Fechas" ) );
    QTGFecha->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTGFecha->horizontalHeader()->setLabel( 1, tr( "Total Ventas" ) );
    QTGFecha->horizontalHeader()->setLabel( 2, tr( "Gancias" ) );
    QTGProducto->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTGProducto->horizontalHeader()->setLabel( 1, tr( "Total Ventas" ) );
    QTGProducto->horizontalHeader()->setLabel( 2, tr( "Gancias" ) );
    groupBox1->setTitle( tr( "Resumen" ) );
    textLabel1_2->setText( tr( "Periodo" ) );
    textLabel1_2_2->setText( tr( "Total Ventas" ) );
    textLabel1_2_2_2->setText( tr( "Ganancias" ) );
}

