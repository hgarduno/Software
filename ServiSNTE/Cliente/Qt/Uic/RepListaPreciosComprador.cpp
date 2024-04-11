/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepListaPreciosComprador.ui'
**
** Created: Thu Apr 11 21:07:46 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepListaPreciosComprador.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a RepListaPreciosComprador as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepListaPreciosComprador::RepListaPreciosComprador( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepListaPreciosComprador" );
    RepListaPreciosCompradorLayout = new QGridLayout( this, 1, 1, 11, 6, "RepListaPreciosCompradorLayout"); 

    layout38 = new QVBoxLayout( 0, 0, 6, "layout38"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout38->addWidget( textLabel1 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout38->addWidget( QCtrProveedores );

    RepListaPreciosCompradorLayout->addLayout( layout38, 0, 0 );

    QTListaPrecios = new QTable( this, "QTListaPrecios" );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Clave" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Razon Social" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Clave Producto" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Producto" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Modelo" ) );
    QTListaPrecios->setNumCols( QTListaPrecios->numCols() + 1 );
    QTListaPrecios->horizontalHeader()->setLabel( QTListaPrecios->numCols() - 1, tr( "Precio Mexico" ) );
    QTListaPrecios->setNumRows( 0 );
    QTListaPrecios->setNumCols( 6 );

    RepListaPreciosCompradorLayout->addWidget( QTListaPrecios, 1, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    layout4->addWidget( QPBConsulta );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout4->addWidget( QPBImprimir );

    RepListaPreciosCompradorLayout->addLayout( layout4, 2, 0 );
    languageChange();
    resize( QSize(647, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepListaPreciosComprador::~RepListaPreciosComprador()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepListaPreciosComprador::languageChange()
{
    setCaption( tr( "Lista Precios Comprador (3)" ) );
    textLabel1->setText( tr( "Proveedores" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 0, tr( "Clave" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 1, tr( "Razon Social" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 2, tr( "Clave Producto" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 3, tr( "Producto" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 4, tr( "Modelo" ) );
    QTListaPrecios->horizontalHeader()->setLabel( 5, tr( "Precio Mexico" ) );
    QPBConsulta->setText( tr( "Consulta" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
}

