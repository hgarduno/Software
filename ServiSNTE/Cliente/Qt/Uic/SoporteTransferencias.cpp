/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/SoporteTransferencias.ui'
**
** Created: Sat Jan 27 16:38:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "SoporteTransferencias.h"

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
 *  Constructs a SoporteTransferencias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SoporteTransferencias::SoporteTransferencias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SoporteTransferencias" );
    SoporteTransferenciasLayout = new QGridLayout( this, 1, 1, 11, 6, "SoporteTransferenciasLayout"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    QCtrTiendas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrTiendas->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrTiendas );
    layout4->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QLERangoFechas = new QLineEdit( this, "QLERangoFechas" );
    layout2->addWidget( QLERangoFechas );
    layout4->addLayout( layout2 );
    layout5->addLayout( layout4 );

    QCtrSoporteVentas = new QCtrlSoporteVentas( this, "QCtrSoporteVentas" );
    QCtrSoporteVentas->setNumRows( 0 );
    QCtrSoporteVentas->setNumCols( 0 );
    layout5->addWidget( QCtrSoporteVentas );
    layout6->addLayout( layout5 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout3->addWidget( QPBImprimir );

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout3->addWidget( pushButton2 );
    layout6->addLayout( layout3 );

    SoporteTransferenciasLayout->addLayout( layout6, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SoporteTransferencias::~SoporteTransferencias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SoporteTransferencias::languageChange()
{
    setCaption( tr( "Soporte Transferencias" ) );
    textLabel1->setText( tr( "Tienda" ) );
    textLabel2->setText( tr( "Rango Fechas" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    pushButton2->setText( tr( "pushButton2" ) );
}

