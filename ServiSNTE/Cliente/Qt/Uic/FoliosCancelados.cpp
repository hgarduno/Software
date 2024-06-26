/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/FoliosCancelados.ui'
**
** Created: Thu Apr 11 21:07:38 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "FoliosCancelados.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"

/*
 *  Constructs a FoliosCancelados as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
FoliosCancelados::FoliosCancelados( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "FoliosCancelados" );
    FoliosCanceladosLayout = new QGridLayout( this, 1, 1, 11, 6, "FoliosCanceladosLayout"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );
    layout2->addWidget( QCtrTiendas );
    layout11->addLayout( layout2 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout8->addWidget( textLabel2 );

    QLEFechaInicio = new QLineEdit( this, "QLEFechaInicio" );
    layout8->addWidget( QLEFechaInicio );
    layout10->addLayout( layout8 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout9->addWidget( textLabel2_2 );

    QLEFechaFinal = new QLineEdit( this, "QLEFechaFinal" );
    QLEFechaFinal->setEnabled( TRUE );
    layout9->addWidget( QLEFechaFinal );
    layout10->addLayout( layout9 );
    layout11->addLayout( layout10 );
    layout13->addLayout( layout11 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout12->addWidget( textLabel1_2 );

    QTFoliosCancelados = new QTable( this, "QTFoliosCancelados" );
    QTFoliosCancelados->setNumCols( QTFoliosCancelados->numCols() + 1 );
    QTFoliosCancelados->horizontalHeader()->setLabel( QTFoliosCancelados->numCols() - 1, tr( "Folio" ) );
    QTFoliosCancelados->setNumCols( QTFoliosCancelados->numCols() + 1 );
    QTFoliosCancelados->horizontalHeader()->setLabel( QTFoliosCancelados->numCols() - 1, tr( "Nuevo Folio" ) );
    QTFoliosCancelados->setNumCols( QTFoliosCancelados->numCols() + 1 );
    QTFoliosCancelados->horizontalHeader()->setLabel( QTFoliosCancelados->numCols() - 1, tr( "Motivos" ) );
    QTFoliosCancelados->setNumCols( QTFoliosCancelados->numCols() + 1 );
    QTFoliosCancelados->horizontalHeader()->setLabel( QTFoliosCancelados->numCols() - 1, tr( "Fecha" ) );
    QTFoliosCancelados->setNumRows( 0 );
    QTFoliosCancelados->setNumCols( 4 );
    layout12->addWidget( QTFoliosCancelados );
    layout13->addLayout( layout12 );

    layout9_2 = new QHBoxLayout( 0, 0, 6, "layout9_2"); 

    QPBMostrar = new QPushButton( this, "QPBMostrar" );
    layout9_2->addWidget( QPBMostrar );

    QPBBorrar = new QPushButton( this, "QPBBorrar" );
    layout9_2->addWidget( QPBBorrar );
    layout13->addLayout( layout9_2 );

    FoliosCanceladosLayout->addLayout( layout13, 0, 0 );
    languageChange();
    resize( QSize(508, 578).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FoliosCancelados::~FoliosCancelados()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FoliosCancelados::languageChange()
{
    setCaption( tr( "Folios Cancelados" ) );
    textLabel1->setText( tr( "Tienda" ) );
    textLabel2->setText( tr( "Fecha Inicio" ) );
    QLEFechaInicio->setInputMask( QString::null );
    textLabel2_2->setText( tr( "Fecha Final" ) );
    QLEFechaFinal->setInputMask( QString::null );
    textLabel1_2->setText( tr( "Folios Cancelados por Tienda" ) );
    QTFoliosCancelados->horizontalHeader()->setLabel( 0, tr( "Folio" ) );
    QTFoliosCancelados->horizontalHeader()->setLabel( 1, tr( "Nuevo Folio" ) );
    QTFoliosCancelados->horizontalHeader()->setLabel( 2, tr( "Motivos" ) );
    QTFoliosCancelados->horizontalHeader()->setLabel( 3, tr( "Fecha" ) );
    QPBMostrar->setText( tr( "Mostrar" ) );
    QPBBorrar->setText( tr( "Borrar" ) );
}

