/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/AbonosApartado.ui'
**
** Created: Thu Apr 11 21:07:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "AbonosApartado.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a AbonosApartado as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
AbonosApartado::AbonosApartado( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "AbonosApartado" );
    AbonosApartadoLayout = new QGridLayout( this, 1, 1, 11, 6, "AbonosApartadoLayout"); 

    layout48 = new QGridLayout( 0, 1, 1, 0, 6, "layout48"); 

    QPBCancelarFolio = new QPushButton( this, "QPBCancelarFolio" );
    QPBCancelarFolio->setEnabled( FALSE );

    layout48->addWidget( QPBCancelarFolio, 3, 4 );

    QPBCancelarAbono = new QPushButton( this, "QPBCancelarAbono" );
    QPBCancelarAbono->setEnabled( FALSE );

    layout48->addWidget( QPBCancelarAbono, 3, 2 );

    QPBCancelarApartado = new QPushButton( this, "QPBCancelarApartado" );
    QPBCancelarApartado->setEnabled( FALSE );

    layout48->addWidget( QPBCancelarApartado, 3, 3 );

    QPBCapturaAbono = new QPushButton( this, "QPBCapturaAbono" );
    QPBCapturaAbono->setEnabled( FALSE );

    layout48->addWidget( QPBCapturaAbono, 3, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QTApartados = new QTable( this, "QTApartados" );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Fecha" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Folio" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "No Orden" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Importe Total" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Pendiente Pago" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Total Abonado" ) );
    QTApartados->setNumRows( 0 );
    QTApartados->setNumCols( 6 );
    QTApartados->setReadOnly( TRUE );
    layout2->addWidget( QTApartados );

    layout48->addMultiCellLayout( layout2, 1, 1, 0, 4 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout2_2->addWidget( textLabel2_2 );

    QTAbonos = new QTable( this, "QTAbonos" );
    QTAbonos->setNumCols( QTAbonos->numCols() + 1 );
    QTAbonos->horizontalHeader()->setLabel( QTAbonos->numCols() - 1, tr( "Fecha" ) );
    QTAbonos->setNumCols( QTAbonos->numCols() + 1 );
    QTAbonos->horizontalHeader()->setLabel( QTAbonos->numCols() - 1, tr( "Monto" ) );
    QTAbonos->setNumRows( 0 );
    QTAbonos->setNumCols( 2 );
    QTAbonos->setReadOnly( TRUE );
    layout2_2->addWidget( QTAbonos );

    layout48->addMultiCellLayout( layout2_2, 2, 2, 0, 4 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    QLAFolioApartado = new QLabel( this, "QLAFolioApartado" );
    QLAFolioApartado->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QLAFolioApartado->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QLAFolioApartado );

    QLEFolioApartado = new QLineEdit( this, "QLEFolioApartado" );
    QLEFolioApartado->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFolioApartado->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QLEFolioApartado );
    layout4->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLECliente = new QLineEdit( this, "QLECliente" );
    QLECliente->setReadOnly( TRUE );
    layout1_2->addWidget( QLECliente );
    layout4->addLayout( layout1_2 );

    layout48->addMultiCellLayout( layout4, 0, 0, 0, 4 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );

    layout48->addWidget( QPBImprimir, 3, 1 );

    AbonosApartadoLayout->addLayout( layout48, 0, 0 );
    languageChange();
    resize( QSize(765, 475).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AbonosApartado::~AbonosApartado()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AbonosApartado::languageChange()
{
    setCaption( tr( "Abonos Apartado" ) );
    QPBCancelarFolio->setText( tr( "Cancelar Folio" ) );
    QPBCancelarAbono->setText( tr( "Cancelar Abono" ) );
    QPBCancelarApartado->setText( tr( "Cancelar Apartado" ) );
    QPBCapturaAbono->setText( tr( "Captura Abono" ) );
    textLabel2->setText( tr( "Apartados Cliente" ) );
    QTApartados->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTApartados->horizontalHeader()->setLabel( 1, tr( "Folio" ) );
    QTApartados->horizontalHeader()->setLabel( 2, tr( "No Orden" ) );
    QTApartados->horizontalHeader()->setLabel( 3, tr( "Importe Total" ) );
    QTApartados->horizontalHeader()->setLabel( 4, tr( "Pendiente Pago" ) );
    QTApartados->horizontalHeader()->setLabel( 5, tr( "Total Abonado" ) );
    textLabel2_2->setText( tr( "Abonos a Cuenta -" ) );
    QTAbonos->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    QTAbonos->horizontalHeader()->setLabel( 1, tr( "Monto" ) );
    QLAFolioApartado->setText( tr( "Folio Apartado" ) );
    textLabel1_2->setText( tr( "Cliente" ) );
    QPBImprimir->setText( tr( "Imprime Recibo" ) );
}

