/****************************************************************************
** Form implementation generated from reading ui file 'UI/PuntosAlumnos.ui'
**
** Created: Thu Apr 11 21:39:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PuntosAlumnos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlAlumnos.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlAlumnos.h"

/*
 *  Constructs a PuntosAlumnos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PuntosAlumnos::PuntosAlumnos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PuntosAlumnos" );
    PuntosAlumnosLayout = new QGridLayout( this, 1, 1, 11, 6, "PuntosAlumnosLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrAlumnos = new QCtrlAlumnos( this, "QCtrAlumnos" );
    layout1->addWidget( QCtrAlumnos );
    layout4->addLayout( layout1 );

    QLCDNPuntos = new QLCDNumber( this, "QLCDNPuntos" );
    QLCDNPuntos->setNumDigits( 8 );
    layout4->addWidget( QLCDNPuntos );

    PuntosAlumnosLayout->addMultiCellLayout( layout4, 0, 0, 0, 1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Promocion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Puntos" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout2->addWidget( QTDatos );

    PuntosAlumnosLayout->addMultiCellLayout( layout2, 1, 1, 0, 1 );

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( textLabel3_2 );

    QLCDNPPSel = new QLCDNumber( this, "QLCDNPPSel" );
    QLCDNPPSel->setNumDigits( 8 );
    layout16->addWidget( QLCDNPPSel );
    layout21->addLayout( layout16 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    layout16_2 = new QVBoxLayout( 0, 0, 6, "layout16_2"); 

    textLabel3_2_2 = new QLabel( this, "textLabel3_2_2" );
    textLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2->addWidget( textLabel3_2_2 );

    QLCDNSaldo = new QLCDNumber( this, "QLCDNSaldo" );
    QLCDNSaldo->setNumDigits( 8 );
    layout16_2->addWidget( QLCDNSaldo );
    layout20->addLayout( layout16_2 );

    layout16_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2"); 

    textLabel3_2_2_2 = new QLabel( this, "textLabel3_2_2_2" );
    textLabel3_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2->addWidget( textLabel3_2_2_2 );

    QLCDNSaldo_2 = new QLCDNumber( this, "QLCDNSaldo_2" );
    QLCDNSaldo_2->setNumDigits( 8 );
    layout16_2_2->addWidget( QLCDNSaldo_2 );
    layout20->addLayout( layout16_2_2 );
    layout21->addLayout( layout20 );

    PuntosAlumnosLayout->addLayout( layout21, 2, 1 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    QPBValidaPSel = new QPushButton( this, "QPBValidaPSel" );
    QPBValidaPSel->setEnabled( FALSE );
    QPBValidaPSel->setMinimumSize( QSize( 0, 35 ) );
    layout15->addWidget( QPBValidaPSel );

    QPBTomaPromocion = new QPushButton( this, "QPBTomaPromocion" );
    QPBTomaPromocion->setEnabled( FALSE );
    QPBTomaPromocion->setMinimumSize( QSize( 0, 35 ) );
    layout15->addWidget( QPBTomaPromocion );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    QPBReInicia = new QPushButton( this, "QPBReInicia" );
    QPBReInicia->setEnabled( TRUE );
    QPBReInicia->setMinimumSize( QSize( 0, 38 ) );
    layout14->addWidget( QPBReInicia );

    QPBRPSeleccionadas_2 = new QPushButton( this, "QPBRPSeleccionadas_2" );
    QPBRPSeleccionadas_2->setEnabled( TRUE );
    QPBRPSeleccionadas_2->setMinimumSize( QSize( 0, 38 ) );
    layout14->addWidget( QPBRPSeleccionadas_2 );

    QPBRPSeleccionadas_3_2 = new QPushButton( this, "QPBRPSeleccionadas_3_2" );
    QPBRPSeleccionadas_3_2->setEnabled( TRUE );
    QPBRPSeleccionadas_3_2->setMinimumSize( QSize( 0, 38 ) );
    layout14->addWidget( QPBRPSeleccionadas_3_2 );
    layout15->addLayout( layout14 );

    PuntosAlumnosLayout->addLayout( layout15, 2, 0 );
    languageChange();
    resize( QSize(673, 494).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PuntosAlumnos::~PuntosAlumnos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PuntosAlumnos::languageChange()
{
    setCaption( tr( "Controlador de Puntos Electronica" ) );
    textLabel1->setText( tr( "Selecciona El Alumno" ) );
    textLabel2->setText( tr( "Promociones" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Promocion" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Puntos" ) );
    textLabel3_2->setText( tr( "Puntos Promociones" ) );
    textLabel3_2_2->setText( tr( "Saldo Puntos" ) );
    textLabel3_2_2_2->setText( tr( "Diferencia Puntos" ) );
    QPBValidaPSel->setText( tr( "Valida Puntos\n"
"Seleccion" ) );
    QPBTomaPromocion->setText( tr( "Toma \n"
"Promociones" ) );
    QPBReInicia->setText( tr( "Reinicia\n"
"Promociones\n"
"Seleccionadas" ) );
    QPBRPSeleccionadas_2->setText( tr( "Reinicia\n"
"Promociones\n"
"Seleccionadas" ) );
    QPBRPSeleccionadas_3_2->setText( tr( "Reinicia\n"
"Promociones\n"
"Seleccionadas" ) );
}

