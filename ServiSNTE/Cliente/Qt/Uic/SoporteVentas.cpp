/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/SoporteVentas.ui'
**
** Created: Sat Jan 27 16:38:29 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "SoporteVentas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"
#include "QCtrlSoporteVentas.h"

/*
 *  Constructs a SoporteVentas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SoporteVentas::SoporteVentas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SoporteVentas" );
    SoporteVentasLayout = new QGridLayout( this, 1, 1, 11, 6, "SoporteVentasLayout"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    QCtrTiendas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrTiendas->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrTiendas );
    layout10->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QLERangoFechas = new QLineEdit( this, "QLERangoFechas" );
    layout2->addWidget( QLERangoFechas );
    layout10->addLayout( layout2 );
    layout11->addLayout( layout10 );

    QCtrSoporteVentas = new QCtrlSoporteVentas( this, "QCtrSoporteVentas" );
    QCtrSoporteVentas->setNumRows( 0 );
    QCtrSoporteVentas->setNumCols( 0 );
    layout11->addWidget( QCtrSoporteVentas );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout3->addWidget( QPBImprimir );

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout3->addWidget( pushButton2 );
    layout11->addLayout( layout3 );

    SoporteVentasLayout->addLayout( layout11, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SoporteVentas::~SoporteVentas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SoporteVentas::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Tienda" ) );
    textLabel2->setText( tr( "Rango Fechas" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    pushButton2->setText( tr( "pushButton2" ) );
}

