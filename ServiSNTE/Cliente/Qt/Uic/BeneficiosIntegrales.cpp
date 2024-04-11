/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/BeneficiosIntegrales.ui'
**
** Created: Sat Jan 27 16:37:45 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "BeneficiosIntegrales.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a BeneficiosIntegrales as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
BeneficiosIntegrales::BeneficiosIntegrales( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "BeneficiosIntegrales" );
    BeneficiosIntegralesLayout = new QGridLayout( this, 1, 1, 11, 6, "BeneficiosIntegralesLayout"); 

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout13->addWidget( textLabel1 );

    QLEArriba = new QLineEdit( this, "QLEArriba" );
    QLEArriba->setEnabled( FALSE );
    layout13->addWidget( QLEArriba );
    layout15->addLayout( layout13 );

    layout13_2 = new QVBoxLayout( 0, 0, 6, "layout13_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout13_2->addWidget( textLabel1_2 );

    QLEIzquierda = new QLineEdit( this, "QLEIzquierda" );
    QLEIzquierda->setEnabled( FALSE );
    layout13_2->addWidget( QLEIzquierda );
    layout15->addLayout( layout13_2 );
    layout19->addLayout( layout15 );

    layout15_2 = new QHBoxLayout( 0, 0, 6, "layout15_2"); 

    layout13_3 = new QVBoxLayout( 0, 0, 6, "layout13_3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout13_3->addWidget( textLabel1_3 );

    QLEAbajo = new QLineEdit( this, "QLEAbajo" );
    QLEAbajo->setEnabled( FALSE );
    layout13_3->addWidget( QLEAbajo );
    layout15_2->addLayout( layout13_3 );

    layout13_2_2 = new QVBoxLayout( 0, 0, 6, "layout13_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout13_2_2->addWidget( textLabel1_2_2 );

    QLEDerecha = new QLineEdit( this, "QLEDerecha" );
    QLEDerecha->setEnabled( FALSE );
    layout13_2_2->addWidget( QLEDerecha );
    layout15_2->addLayout( layout13_2_2 );
    layout19->addLayout( layout15_2 );

    BeneficiosIntegralesLayout->addLayout( layout19, 1, 0 );

    QTEFormato = new QTextEdit( this, "QTEFormato" );

    BeneficiosIntegralesLayout->addWidget( QTEFormato, 0, 0 );

    layout63 = new QHBoxLayout( 0, 0, 6, "layout63"); 

    layout62 = new QHBoxLayout( 0, 0, 6, "layout62"); 

    layout61 = new QVBoxLayout( 0, 0, 0, "layout61"); 

    QPBSelCredito = new QPushButton( this, "QPBSelCredito" );
    QPBSelCredito->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBSelCredito->sizePolicy().hasHeightForWidth() ) );
    QPBSelCredito->setMinimumSize( QSize( 0, 25 ) );
    layout61->addWidget( QPBSelCredito );

    QPBCreditos = new QPushButton( this, "QPBCreditos" );
    QPBCreditos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBCreditos->sizePolicy().hasHeightForWidth() ) );
    QPBCreditos->setMinimumSize( QSize( 0, 25 ) );
    layout61->addWidget( QPBCreditos );
    layout62->addLayout( layout61 );

    QPBGeneralesContrato = new QPushButton( this, "QPBGeneralesContrato" );
    QPBGeneralesContrato->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBGeneralesContrato->sizePolicy().hasHeightForWidth() ) );
    QPBGeneralesContrato->setMinimumSize( QSize( 0, 50 ) );
    layout62->addWidget( QPBGeneralesContrato );

    QPBGenerales = new QPushButton( this, "QPBGenerales" );
    QPBGenerales->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBGenerales->sizePolicy().hasHeightForWidth() ) );
    QPBGenerales->setMinimumSize( QSize( 0, 50 ) );
    layout62->addWidget( QPBGenerales );

    QPBComunicacion = new QPushButton( this, "QPBComunicacion" );
    QPBComunicacion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBComunicacion->sizePolicy().hasHeightForWidth() ) );
    QPBComunicacion->setMinimumSize( QSize( 0, 50 ) );
    layout62->addWidget( QPBComunicacion );

    QPBCapDirParticular = new QPushButton( this, "QPBCapDirParticular" );
    QPBCapDirParticular->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBCapDirParticular->sizePolicy().hasHeightForWidth() ) );
    QPBCapDirParticular->setMinimumSize( QSize( 0, 50 ) );
    layout62->addWidget( QPBCapDirParticular );

    QPBCapDatEmpleo = new QPushButton( this, "QPBCapDatEmpleo" );
    QPBCapDatEmpleo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBCapDatEmpleo->sizePolicy().hasHeightForWidth() ) );
    QPBCapDatEmpleo->setMinimumSize( QSize( 0, 50 ) );
    layout62->addWidget( QPBCapDatEmpleo );

    QPBCapDatComplementarios = new QPushButton( this, "QPBCapDatComplementarios" );
    QPBCapDatComplementarios->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBCapDatComplementarios->sizePolicy().hasHeightForWidth() ) );
    QPBCapDatComplementarios->setMinimumSize( QSize( 0, 50 ) );
    layout62->addWidget( QPBCapDatComplementarios );

    QPBCapDatCentroTrabajo = new QPushButton( this, "QPBCapDatCentroTrabajo" );
    QPBCapDatCentroTrabajo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBCapDatCentroTrabajo->sizePolicy().hasHeightForWidth() ) );
    QPBCapDatCentroTrabajo->setMinimumSize( QSize( 0, 50 ) );
    layout62->addWidget( QPBCapDatCentroTrabajo );

    QPBPosBeneficios = new QPushButton( this, "QPBPosBeneficios" );
    QPBPosBeneficios->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 50, QPBPosBeneficios->sizePolicy().hasHeightForWidth() ) );
    QPBPosBeneficios->setMinimumSize( QSize( 0, 50 ) );
    layout62->addWidget( QPBPosBeneficios );
    layout63->addLayout( layout62 );

    layout12 = new QVBoxLayout( 0, 0, 0, "layout12"); 

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    QPBImprimir->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 25, QPBImprimir->sizePolicy().hasHeightForWidth() ) );
    QPBImprimir->setMinimumSize( QSize( 0, 25 ) );
    layout11->addWidget( QPBImprimir );

    QPBImprimeAArchivo = new QPushButton( this, "QPBImprimeAArchivo" );
    QPBImprimeAArchivo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 25, QPBImprimeAArchivo->sizePolicy().hasHeightForWidth() ) );
    QPBImprimeAArchivo->setMinimumSize( QSize( 0, 25 ) );
    layout11->addWidget( QPBImprimeAArchivo );
    layout12->addLayout( layout11 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    QPBImprimeFrente = new QPushButton( this, "QPBImprimeFrente" );
    QPBImprimeFrente->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 25, QPBImprimeFrente->sizePolicy().hasHeightForWidth() ) );
    QPBImprimeFrente->setMinimumSize( QSize( 0, 25 ) );
    layout9->addWidget( QPBImprimeFrente );

    QPBImprimeAtras = new QPushButton( this, "QPBImprimeAtras" );
    QPBImprimeAtras->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 25, QPBImprimeAtras->sizePolicy().hasHeightForWidth() ) );
    QPBImprimeAtras->setMinimumSize( QSize( 0, 25 ) );
    layout9->addWidget( QPBImprimeAtras );
    layout12->addLayout( layout9 );
    layout63->addLayout( layout12 );

    BeneficiosIntegralesLayout->addLayout( layout63, 2, 0 );
    languageChange();
    resize( QSize(1074, 657).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
BeneficiosIntegrales::~BeneficiosIntegrales()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void BeneficiosIntegrales::languageChange()
{
    setCaption( tr( "Contrato Beneficios Integrales" ) );
    textLabel1->setText( tr( "Arriba" ) );
    QLEArriba->setText( tr( "-10" ) );
    textLabel1_2->setText( tr( "Izquierda" ) );
    QLEIzquierda->setText( tr( "0" ) );
    textLabel1_3->setText( tr( "Abajo" ) );
    QLEAbajo->setText( tr( "0" ) );
    textLabel1_2_2->setText( tr( "Derecha" ) );
    QLEDerecha->setText( tr( "0" ) );
    QPBSelCredito->setText( tr( "Credito RFC" ) );
    QPBCreditos->setText( tr( "Creditos Registrados" ) );
    QPBGeneralesContrato->setText( tr( "Generales Contrato" ) );
    QPBGenerales->setText( tr( "Generales" ) );
    QPBComunicacion->setText( tr( "Comunicacion" ) );
    QPBCapDirParticular->setText( tr( "Direccion Particular" ) );
    QPBCapDatEmpleo->setText( tr( "Empleo" ) );
    QPBCapDatComplementarios->setText( tr( "Complementarios" ) );
    QPBCapDatCentroTrabajo->setText( tr( "Datos Centro \n"
"De Trabajo" ) );
    QPBPosBeneficios->setText( tr( "Posiciones" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QPBImprimeAArchivo->setText( tr( "Imprime A Archivo" ) );
    QPBImprimeFrente->setText( tr( "Imprimir Frente" ) );
    QPBImprimeAtras->setText( tr( "Imprimir Atras" ) );
}

