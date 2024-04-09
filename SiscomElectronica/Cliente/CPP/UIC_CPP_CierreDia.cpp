/****************************************************************************
** Form implementation generated from reading ui file 'UI/CierreDia.ui'
**
** Created: lun abr 1 18:57:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CierreDia.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a CierreDia as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CierreDia::CierreDia( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CierreDia" );
    CierreDiaLayout = new QGridLayout( this, 1, 1, 11, 6, "CierreDiaLayout"); 

    layout65 = new QHBoxLayout( 0, 0, 6, "layout65"); 

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel3 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( QCtrFechaInicio );
    layout12->addLayout( layout10 );

    layout10_2 = new QVBoxLayout( 0, 0, 6, "layout10_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout10_2->addWidget( textLabel3_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout10_2->addWidget( QCtrFechaFin );
    layout12->addLayout( layout10_2 );
    layout65->addLayout( layout12 );
    spacer11 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout65->addItem( spacer11 );

    CierreDiaLayout->addLayout( layout65, 0, 0 );

    layout67 = new QHBoxLayout( 0, 0, 6, "layout67"); 

    QPBSeleccionarExpendio = new QPushButton( this, "QPBSeleccionarExpendio" );
    layout67->addWidget( QPBSeleccionarExpendio );

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    layout67->addWidget( QPBConsulta );

    QPBSeleccionarExpendio_2 = new QPushButton( this, "QPBSeleccionarExpendio_2" );
    layout67->addWidget( QPBSeleccionarExpendio_2 );

    CierreDiaLayout->addLayout( layout67, 3, 0 );

    layout63 = new QHBoxLayout( 0, 0, 6, "layout63"); 

    layout59 = new QVBoxLayout( 0, 0, 6, "layout59"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout59->addWidget( textLabel2 );

    lineEdit10 = new QLineEdit( this, "lineEdit10" );
    layout59->addWidget( lineEdit10 );
    layout63->addLayout( layout59 );

    layout59_3 = new QVBoxLayout( 0, 0, 6, "layout59_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout59_3->addWidget( textLabel2_3 );

    lineEdit10_3 = new QLineEdit( this, "lineEdit10_3" );
    layout59_3->addWidget( lineEdit10_3 );
    layout63->addLayout( layout59_3 );

    layout59_2 = new QVBoxLayout( 0, 0, 6, "layout59_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout59_2->addWidget( textLabel2_2 );

    lineEdit10_2 = new QLineEdit( this, "lineEdit10_2" );
    layout59_2->addWidget( lineEdit10_2 );
    layout63->addLayout( layout59_2 );

    layout59_2_2 = new QVBoxLayout( 0, 0, 6, "layout59_2_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout59_2_2->addWidget( textLabel2_2_2 );

    lineEdit10_2_2 = new QLineEdit( this, "lineEdit10_2_2" );
    layout59_2_2->addWidget( lineEdit10_2_2 );
    layout63->addLayout( layout59_2_2 );

    CierreDiaLayout->addLayout( layout63, 2, 0 );

    layout74 = new QHBoxLayout( 0, 0, 6, "layout74"); 

    layout73 = new QVBoxLayout( 0, 0, 6, "layout73"); 

    layout63_2 = new QHBoxLayout( 0, 0, 6, "layout63_2"); 

    layout59_4 = new QVBoxLayout( 0, 0, 6, "layout59_4"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    textLabel2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_4->sizePolicy().hasHeightForWidth() ) );
    layout59_4->addWidget( textLabel2_4 );

    QLEVentasEfectivo = new QLineEdit( this, "QLEVentasEfectivo" );
    QLEVentasEfectivo->setReadOnly( TRUE );
    layout59_4->addWidget( QLEVentasEfectivo );
    layout63_2->addLayout( layout59_4 );

    layout59_3_2 = new QVBoxLayout( 0, 0, 6, "layout59_3_2"); 

    textLabel2_3_2 = new QLabel( this, "textLabel2_3_2" );
    textLabel2_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_3_2->sizePolicy().hasHeightForWidth() ) );
    layout59_3_2->addWidget( textLabel2_3_2 );

    QLEVentasTarjeta = new QLineEdit( this, "QLEVentasTarjeta" );
    QLEVentasTarjeta->setReadOnly( TRUE );
    layout59_3_2->addWidget( QLEVentasTarjeta );
    layout63_2->addLayout( layout59_3_2 );

    layout59_2_3 = new QVBoxLayout( 0, 0, 6, "layout59_2_3"); 

    textLabel2_2_3 = new QLabel( this, "textLabel2_2_3" );
    textLabel2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2_3->sizePolicy().hasHeightForWidth() ) );
    layout59_2_3->addWidget( textLabel2_2_3 );

    QLEVentasPedidos = new QLineEdit( this, "QLEVentasPedidos" );
    QLEVentasPedidos->setReadOnly( TRUE );
    layout59_2_3->addWidget( QLEVentasPedidos );
    layout63_2->addLayout( layout59_2_3 );
    layout73->addLayout( layout63_2 );

    table16 = new QTable( this, "table16" );
    table16->setNumRows( 0 );
    table16->setNumCols( 3 );
    layout73->addWidget( table16 );
    layout74->addLayout( layout73 );

    layout57 = new QVBoxLayout( 0, 0, 6, "layout57"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout57->addWidget( textLabel1 );

    QLCDNTotal = new QLCDNumber( this, "QLCDNTotal" );
    QLCDNTotal->setNumDigits( 10 );
    layout57->addWidget( QLCDNTotal );
    layout74->addLayout( layout57 );

    CierreDiaLayout->addLayout( layout74, 1, 0 );
    languageChange();
    resize( QSize(736, 462).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CierreDia::~CierreDia()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CierreDia::languageChange()
{
    setCaption( tr( "Cierre Caja" ) );
    textLabel3->setText( tr( "Fecha Inicio" ) );
    textLabel3_2->setText( tr( "Fecha Fin" ) );
    QPBSeleccionarExpendio->setText( tr( "Seleccionar Exependio" ) );
    QPBConsulta->setText( tr( "Consulta" ) );
    QPBSeleccionarExpendio_2->setText( tr( "Registra Cierre" ) );
    textLabel2->setText( tr( "Billete" ) );
    textLabel2_3->setText( tr( "Cambio" ) );
    textLabel2_2->setText( tr( "Tarjeta" ) );
    textLabel2_2_2->setText( tr( "Gastos" ) );
    textLabel2_4->setText( tr( "Efectivo" ) );
    textLabel2_3_2->setText( tr( "Tarjeta" ) );
    textLabel2_2_3->setText( tr( "Pedidos" ) );
    textLabel1->setText( tr( "Total" ) );
}

