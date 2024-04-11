/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepCompras.ui'
**
** Created: Sat Jan 27 16:38:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepCompras.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProveedoresSS.h"
#include "QCtrlDepartamentosSS.h"

/*
 *  Constructs a RepCompras as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepCompras::RepCompras( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepCompras" );
    RepComprasLayout = new QGridLayout( this, 1, 1, 11, 6, "RepComprasLayout"); 

    layout2 = new QHBoxLayout( 0, 0, 6, "layout2"); 

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    layout2->addWidget( QPBConsultar );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout2->addWidget( QPBImprimir );

    RepComprasLayout->addMultiCellLayout( layout2, 2, 2, 0, 1 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout1->addWidget( QCtrProveedores );

    RepComprasLayout->addLayout( layout1, 0, 0 );

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout25->addWidget( textLabel1_2 );

    QCtrDepartamentos = new QCtrlDepartamentosSS( this, "QCtrDepartamentos" );
    layout25->addWidget( QCtrDepartamentos );

    RepComprasLayout->addLayout( layout25, 0, 1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cve" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Modelo" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Nombre" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "C. Bruto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "1" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "2" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "3" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "4" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Iva" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "C. Neto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "P. General" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Margen" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 12 );

    RepComprasLayout->addMultiCellWidget( QTDatos, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(943, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepCompras::~RepCompras()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepCompras::languageChange()
{
    setCaption( tr( "Registro de compras" ) );
    QPBConsultar->setText( tr( "Consultar" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    textLabel1->setText( tr( "Proveedores" ) );
    textLabel1_2->setText( tr( "Departamento" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Cve" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Modelo" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Nombre" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "C. Bruto" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "1" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "2" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "3" ) );
    QTDatos->horizontalHeader()->setLabel( 7, tr( "4" ) );
    QTDatos->horizontalHeader()->setLabel( 8, tr( "Iva" ) );
    QTDatos->horizontalHeader()->setLabel( 9, tr( "C. Neto" ) );
    QTDatos->horizontalHeader()->setLabel( 10, tr( "P. General" ) );
    QTDatos->horizontalHeader()->setLabel( 11, tr( "Margen" ) );
}

