/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/FolioApartado.ui'
**
** Created: Sat Jan 27 16:38:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "FolioApartado.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiposFolio.h"
#include "QCtrlTiendasEntrega.h"

/*
 *  Constructs a FolioApartado as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
FolioApartado::FolioApartado( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "FolioApartado" );
    FolioApartadoLayout = new QGridLayout( this, 1, 1, 11, 6, "FolioApartadoLayout"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout9->addWidget( textLabel4 );

    table1 = new QTable( this, "table1" );
    table1->setNumRows( 0 );
    table1->setNumCols( 3 );
    layout9->addWidget( table1 );

    FolioApartadoLayout->addMultiCellLayout( layout9, 3, 3, 0, 1 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout6->addWidget( textLabel3 );

    QLERangoFechas = new QLineEdit( this, "QLERangoFechas" );
    layout6->addWidget( QLERangoFechas );

    FolioApartadoLayout->addMultiCellLayout( layout6, 2, 2, 0, 1 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout10->addWidget( QPBRegistrar );

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout10->addWidget( pushButton2 );

    FolioApartadoLayout->addMultiCellLayout( layout10, 4, 4, 0, 1 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout7->addWidget( textLabel5 );

    QCtrTiposFolio = new QCtrlTiposFolio( this, "QCtrTiposFolio" );
    layout7->addWidget( QCtrTiposFolio );
    layout8->addLayout( layout7 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout2->addWidget( textLabel1_3 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    layout2->addWidget( QCtrTiendas );
    layout8->addLayout( layout2 );

    FolioApartadoLayout->addMultiCellLayout( layout8, 0, 0, 0, 1 );

    layout9_2 = new QVBoxLayout( 0, 0, 6, "layout9_2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout9_2->addWidget( textLabel2 );

    QLEFolioInicio = new QLineEdit( this, "QLEFolioInicio" );
    layout9_2->addWidget( QLEFolioInicio );

    FolioApartadoLayout->addLayout( layout9_2, 1, 0 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout11->addWidget( textLabel2_2 );

    QLEFolioFin = new QLineEdit( this, "QLEFolioFin" );
    layout11->addWidget( QLEFolioFin );

    FolioApartadoLayout->addLayout( layout11, 1, 1 );
    languageChange();
    resize( QSize(582, 568).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FolioApartado::~FolioApartado()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FolioApartado::languageChange()
{
    setCaption( tr( "Registro de Folios" ) );
    textLabel4->setText( tr( "Folios Tiendas" ) );
    textLabel3->setText( tr( "Rango de Fechas Consulta" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    pushButton2->setText( tr( "Consultar" ) );
    textLabel5->setText( tr( "Tipo Folio" ) );
    textLabel1_3->setText( tr( "Tiendas" ) );
    textLabel2->setText( tr( "Folio Inicio" ) );
    textLabel2_2->setText( tr( "Folio Fin" ) );
}

