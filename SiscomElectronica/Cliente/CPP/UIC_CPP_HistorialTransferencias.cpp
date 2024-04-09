/****************************************************************************
** Form implementation generated from reading ui file 'UI/HistorialTransferencias.ui'
**
** Created: lun abr 1 18:57:49 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_HistorialTransferencias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "IMP_QControlFecha.h"

/*
 *  Constructs a HistorialTransferencias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
HistorialTransferencias::HistorialTransferencias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "HistorialTransferencias" );
    HistorialTransferenciasLayout = new QGridLayout( this, 1, 1, 11, 6, "HistorialTransferenciasLayout"); 

    QPBConsulta = new QPushButton( this, "QPBConsulta" );

    HistorialTransferenciasLayout->addMultiCellWidget( QPBConsulta, 2, 2, 0, 2 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout11->addWidget( textLabel1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha Hora" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Expendio Origen" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Exendio Destino" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Estado" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 6 );
    QTDatos->setReadOnly( TRUE );
    layout11->addWidget( QTDatos );

    HistorialTransferenciasLayout->addMultiCellLayout( layout11, 1, 1, 0, 3 );

    QPBReEnviaTrans = new QPushButton( this, "QPBReEnviaTrans" );
    QPBReEnviaTrans->setEnabled( FALSE );

    HistorialTransferenciasLayout->addWidget( QPBReEnviaTrans, 2, 3 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    QCtrFecha = new CQControlFecha( this, "QCtrFecha" );
    QCtrFecha->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFecha->sizePolicy().hasHeightForWidth() ) );
    layout4->addWidget( QCtrFecha );

    HistorialTransferenciasLayout->addLayout( layout4, 0, 0 );

    layout4_2 = new QVBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout4_2->addWidget( textLabel2_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout4_2->addWidget( QCtrFechaFin );

    HistorialTransferenciasLayout->addLayout( layout4_2, 0, 1 );

    QPBSeleccionaExpendio = new QPushButton( this, "QPBSeleccionaExpendio" );
    QPBSeleccionaExpendio->setMinimumSize( QSize( 0, 40 ) );

    HistorialTransferenciasLayout->addMultiCellWidget( QPBSeleccionaExpendio, 0, 0, 2, 3 );
    languageChange();
    resize( QSize(623, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
HistorialTransferencias::~HistorialTransferencias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void HistorialTransferencias::languageChange()
{
    setCaption( tr( "Historial De Transferencias" ) );
    QPBConsulta->setText( tr( "Ejecutar Consulta" ) );
    textLabel1->setText( tr( "Tranferencias" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Fecha Hora" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Expendio Origen" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Exendio Destino" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Estado" ) );
    QPBReEnviaTrans->setText( tr( "Re Enviar Transferencia" ) );
    textLabel2->setText( tr( "Fecha Inicio" ) );
    textLabel2_2->setText( tr( "Fecha Fin" ) );
    QPBSeleccionaExpendio->setText( tr( "Selecciona Expendio" ) );
}

