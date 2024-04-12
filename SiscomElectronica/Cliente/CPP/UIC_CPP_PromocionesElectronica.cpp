/****************************************************************************
** Form implementation generated from reading ui file 'UI/PromocionesElectronica.ui'
**
** Created: Thu Apr 11 21:39:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PromocionesElectronica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <IMP_QControlFecha.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a PromocionesElectronica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PromocionesElectronica::PromocionesElectronica( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PromocionesElectronica" );
    PromocionesElectronicaLayout = new QHBoxLayout( this, 11, 6, "PromocionesElectronicaLayout"); 

    layout25 = new QVBoxLayout( 0, 0, 6, "layout25"); 

    layout24 = new QHBoxLayout( 0, 0, 6, "layout24"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel3 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout5->addWidget( QLENombre );
    layout24->addLayout( layout5 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2->addWidget( textLabel3_2 );

    QLEPuntosSiscom = new QLineEdit( this, "QLEPuntosSiscom" );
    layout5_2->addWidget( QLEPuntosSiscom );
    layout24->addLayout( layout5_2 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout15->addWidget( textLabel1 );

    QCtrFechaIni = new CQControlFecha( this, "QCtrFechaIni" );
    layout15->addWidget( QCtrFechaIni );
    layout24->addLayout( layout15 );

    layout15_2 = new QVBoxLayout( 0, 0, 6, "layout15_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout15_2->addWidget( textLabel1_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    layout15_2->addWidget( QCtrFechaFin );
    layout24->addLayout( layout15_2 );
    layout25->addLayout( layout24 );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout17->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout17->addWidget( QTEDescripcion );
    layout25->addLayout( layout17 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    layout19->addWidget( QPBRegistra );

    pushButton3_2 = new QPushButton( this, "pushButton3_2" );
    layout19->addWidget( pushButton3_2 );

    pushButton3_2_2 = new QPushButton( this, "pushButton3_2_2" );
    layout19->addWidget( pushButton3_2_2 );
    layout25->addLayout( layout19 );
    PromocionesElectronicaLayout->addLayout( layout25 );
    languageChange();
    resize( QSize(517, 331).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PromocionesElectronica::~PromocionesElectronica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PromocionesElectronica::languageChange()
{
    setCaption( tr( "Promociones Siscom Electronica" ) );
    textLabel3->setText( tr( "Nombre De La Promocion" ) );
    textLabel3_2->setText( tr( "Puntos Siscom" ) );
    textLabel1->setText( tr( "Fecha Inicio" ) );
    textLabel1_2->setText( tr( "Fecha Fin" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    QPBRegistra->setText( tr( "Registra Promocion" ) );
    pushButton3_2->setText( tr( "Actualiza Promocion" ) );
    pushButton3_2_2->setText( tr( "Finaliza Promocion" ) );
}

