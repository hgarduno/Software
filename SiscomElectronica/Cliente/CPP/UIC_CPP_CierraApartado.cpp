/****************************************************************************
** Form implementation generated from reading ui file 'UI/CierraApartado.ui'
**
** Created: lun abr 1 18:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CierraApartado.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a CierraApartado as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CierraApartado::CierraApartado( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CierraApartado" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setMinimumSize( QSize( 300, 0 ) );
    CierraApartadoLayout = new QGridLayout( this, 1, 1, 11, 6, "CierraApartadoLayout"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout6->addWidget( textLabel3 );

    QTApartados = new QTable( this, "QTApartados" );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "No Orden" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Fecha P." ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Hora P." ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Fecha E." ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Hora E." ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Cliente" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Adelanto" ) );
    QTApartados->setNumCols( QTApartados->numCols() + 1 );
    QTApartados->horizontalHeader()->setLabel( QTApartados->numCols() - 1, tr( "Pendiente P" ) );
    QTApartados->setNumRows( 0 );
    QTApartados->setNumCols( 8 );
    layout6->addWidget( QTApartados );

    CierraApartadoLayout->addMultiCellLayout( layout6, 1, 1, 0, 2 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    QLEOrden = new QLineEdit( this, "QLEOrden" );
    layout4->addWidget( QLEOrden );

    CierraApartadoLayout->addLayout( layout4, 0, 2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel1 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    QCtrFechaIni->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaIni->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrFechaIni );

    CierraApartadoLayout->addLayout( layout3, 0, 0 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( textLabel1_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( QCtrFechaFin );

    CierraApartadoLayout->addLayout( layout3_2, 0, 1 );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    QPBConsultar->setAutoDefault( FALSE );
    layout36->addWidget( QPBConsultar );

    QPBPagar = new QPushButton( this, "QPBPagar" );
    QPBPagar->setEnabled( FALSE );
    QPBPagar->setAutoDefault( FALSE );
    layout36->addWidget( QPBPagar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout36->addWidget( QPBCancelar );

    CierraApartadoLayout->addMultiCellLayout( layout36, 2, 2, 0, 2 );
    languageChange();
    resize( QSize(939, 290).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CierraApartado::~CierraApartado()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CierraApartado::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel3->setText( tr( "Apartados" ) );
    QTApartados->horizontalHeader()->setLabel( 0, tr( "No Orden" ) );
    QTApartados->horizontalHeader()->setLabel( 1, tr( "Fecha P." ) );
    QTApartados->horizontalHeader()->setLabel( 2, tr( "Hora P." ) );
    QTApartados->horizontalHeader()->setLabel( 3, tr( "Fecha E." ) );
    QTApartados->horizontalHeader()->setLabel( 4, tr( "Hora E." ) );
    QTApartados->horizontalHeader()->setLabel( 5, tr( "Cliente" ) );
    QTApartados->horizontalHeader()->setLabel( 6, tr( "Adelanto" ) );
    QTApartados->horizontalHeader()->setLabel( 7, tr( "Pendiente P" ) );
    textLabel2->setText( tr( "Numero" ) );
    textLabel1->setText( tr( "Fecha" ) );
    textLabel1_2->setText( tr( "Fecha" ) );
    QPBConsultar->setText( tr( "Consultar" ) );
    QPBPagar->setText( tr( "Pagar Efectivo" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

