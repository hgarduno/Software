/****************************************************************************
** Form implementation generated from reading ui file 'UI/PuntosEntrega.ui'
**
** Created: Wed Jan 31 10:48:13 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PuntosEntrega.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a PuntosEntrega as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PuntosEntrega::PuntosEntrega( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PuntosEntrega" );
    PuntosEntregaLayout = new QGridLayout( this, 1, 1, 11, 6, "PuntosEntregaLayout"); 

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout11->addWidget( QPBRegistrar );

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout11->addWidget( pushButton1_2 );

    pushButton1_3 = new QPushButton( this, "pushButton1_3" );
    layout11->addWidget( pushButton1_3 );

    PuntosEntregaLayout->addLayout( layout11, 2, 0 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLEPuntoEntrega = new QLineEdit( this, "QLEPuntoEntrega" );
    layout1->addWidget( QLEPuntoEntrega );
    layout14->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    layout1_2->addWidget( QLECalle );
    layout14->addLayout( layout1_2 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout1_2_2->addWidget( textLabel1_2_2 );

    QLENumExterior = new QLineEdit( this, "QLENumExterior" );
    layout1_2_2->addWidget( QLENumExterior );
    layout9->addLayout( layout1_2_2 );

    layout1_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2"); 

    textLabel1_2_2_2 = new QLabel( this, "textLabel1_2_2_2" );
    layout1_2_2_2->addWidget( textLabel1_2_2_2 );

    QLENumInterior = new QLineEdit( this, "QLENumInterior" );
    layout1_2_2_2->addWidget( QLENumInterior );
    layout9->addLayout( layout1_2_2_2 );

    layout1_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2_2"); 

    textLabel1_2_2_2_2 = new QLabel( this, "textLabel1_2_2_2_2" );
    textLabel1_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2_2->addWidget( textLabel1_2_2_2_2 );

    QLEMunicipio = new QLineEdit( this, "QLEMunicipio" );
    layout1_2_2_2_2->addWidget( QLEMunicipio );
    layout9->addLayout( layout1_2_2_2_2 );

    layout1_2_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2_2_2"); 

    textLabel1_2_2_2_2_2 = new QLabel( this, "textLabel1_2_2_2_2_2" );
    textLabel1_2_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2_2_2->addWidget( textLabel1_2_2_2_2_2 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    layout1_2_2_2_2_2->addWidget( QLEColonia );
    layout9->addLayout( layout1_2_2_2_2_2 );

    layout1_2_2_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2_2_2_2"); 

    textLabel1_2_2_2_2_2_2 = new QLabel( this, "textLabel1_2_2_2_2_2_2" );
    textLabel1_2_2_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2_2_2_2->addWidget( textLabel1_2_2_2_2_2_2 );

    QLECP = new QLineEdit( this, "QLECP" );
    QLECP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECP->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2_2_2_2->addWidget( QLECP );
    layout9->addLayout( layout1_2_2_2_2_2_2 );

    layout1_2_2_2_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2_2_2_2_2"); 

    textLabel1_2_2_2_2_2_2_2 = new QLabel( this, "textLabel1_2_2_2_2_2_2_2" );
    layout1_2_2_2_2_2_2_2->addWidget( textLabel1_2_2_2_2_2_2_2 );

    QLEEstado = new QLineEdit( this, "QLEEstado" );
    layout1_2_2_2_2_2_2_2->addWidget( QLEEstado );
    layout9->addLayout( layout1_2_2_2_2_2_2_2 );
    layout14->addLayout( layout9 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout13->addWidget( textLabel4 );

    QTEReferencias = new QTextEdit( this, "QTEReferencias" );
    layout13->addWidget( QTEReferencias );
    layout14->addLayout( layout13 );

    PuntosEntregaLayout->addLayout( layout14, 0, 0 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout12->addWidget( textLabel3 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Punto de Entrega" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Direccion" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Referencias" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 3 );
    layout12->addWidget( table1 );

    PuntosEntregaLayout->addLayout( layout12, 1, 0 );
    languageChange();
    resize( QSize(818, 426).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PuntosEntrega::~PuntosEntrega()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PuntosEntrega::languageChange()
{
    setCaption( tr( "Puntos de entrega Siscom" ) );
    QPBRegistrar->setText( tr( "&Registrar" ) );
    QPBRegistrar->setAccel( QKeySequence( tr( "Alt+R" ) ) );
    pushButton1_2->setText( tr( "Modificar" ) );
    pushButton1_3->setText( tr( "Eliminar" ) );
    textLabel1->setText( tr( "Nombre Punto de entrega" ) );
    textLabel1_2->setText( tr( "Calle" ) );
    textLabel1_2_2->setText( tr( "# Numero Exterior" ) );
    textLabel1_2_2_2->setText( tr( "#Numero Interior" ) );
    textLabel1_2_2_2_2->setText( tr( "Delegacion/Municipio" ) );
    textLabel1_2_2_2_2_2->setText( tr( "Colonia" ) );
    textLabel1_2_2_2_2_2_2->setText( tr( "Codigo Postal" ) );
    textLabel1_2_2_2_2_2_2_2->setText( tr( "Estado" ) );
    textLabel4->setText( tr( "Referencias" ) );
    textLabel3->setText( tr( "textLabel3" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Punto de Entrega" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Direccion" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "Referencias" ) );
}

