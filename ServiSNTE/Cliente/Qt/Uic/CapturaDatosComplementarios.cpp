/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaDatosComplementarios.ui'
**
** Created: Sat Jan 27 16:37:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaDatosComplementarios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qlabel.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDatosComplementarios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDatosComplementarios::CapturaDatosComplementarios( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDatosComplementarios" );
    CapturaDatosComplementariosLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDatosComplementariosLayout"); 

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout12->addWidget( QPBAceptar );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    QPBRegistrar->setAutoDefault( FALSE );
    layout12->addWidget( QPBRegistrar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout12->addWidget( QPBCancelar );

    CapturaDatosComplementariosLayout->addLayout( layout12, 1, 0 );

    QTWComplementarios = new QTabWidget( this, "QTWComplementarios" );

    tab = new QWidget( QTWComplementarios, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout71 = new QVBoxLayout( 0, 0, 6, "layout71"); 

    QGBCargoPublico = new QButtonGroup( tab, "QGBCargoPublico" );
    QGBCargoPublico->setAlignment( int( QButtonGroup::AlignHCenter ) );
    QGBCargoPublico->setFlat( FALSE );
    QGBCargoPublico->setColumnLayout(0, Qt::Vertical );
    QGBCargoPublico->layout()->setSpacing( 6 );
    QGBCargoPublico->layout()->setMargin( 11 );
    QGBCargoPublicoLayout = new QHBoxLayout( QGBCargoPublico->layout() );
    QGBCargoPublicoLayout->setAlignment( Qt::AlignTop );

    textLabel2_2 = new QLabel( QGBCargoPublico, "textLabel2_2" );
    QGBCargoPublicoLayout->addWidget( textLabel2_2 );

    QRBCPublicoSi = new QRadioButton( QGBCargoPublico, "QRBCPublicoSi" );
    QRBCPublicoSi->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QRBCPublicoSi->sizePolicy().hasHeightForWidth() ) );
    QGBCargoPublicoLayout->addWidget( QRBCPublicoSi );

    QRBCPublicoNo = new QRadioButton( QGBCargoPublico, "QRBCPublicoNo" );
    QRBCPublicoNo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QRBCPublicoNo->sizePolicy().hasHeightForWidth() ) );
    QGBCargoPublicoLayout->addWidget( QRBCPublicoNo );
    layout71->addWidget( QGBCargoPublico );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1_4_6 = new QLabel( tab, "textLabel1_4_6" );
    layout6->addWidget( textLabel1_4_6 );

    QLEEspecifica = new QLineEdit( tab, "QLEEspecifica" );
    QLEEspecifica->setEnabled( FALSE );
    layout6->addWidget( QLEEspecifica );
    layout71->addLayout( layout6 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout6_3_5 = new QVBoxLayout( 0, 0, 6, "layout6_3_5"); 

    textLabel1_4_4_5 = new QLabel( tab, "textLabel1_4_4_5" );
    layout6_3_5->addWidget( textLabel1_4_4_5 );

    QLEDependencia = new QLineEdit( tab, "QLEDependencia" );
    QLEDependencia->setEnabled( FALSE );
    layout6_3_5->addWidget( QLEDependencia );
    layout17->addLayout( layout6_3_5 );

    layout6_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_2_2"); 

    textLabel1_4_4_2_2 = new QLabel( tab, "textLabel1_4_4_2_2" );
    layout6_3_2_2->addWidget( textLabel1_4_4_2_2 );

    QLEPuesto = new QLineEdit( tab, "QLEPuesto" );
    QLEPuesto->setEnabled( FALSE );
    layout6_3_2_2->addWidget( QLEPuesto );
    layout17->addLayout( layout6_3_2_2 );
    layout71->addLayout( layout17 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout6_3_3_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_3_2"); 

    textLabel1_4_4_3_2 = new QLabel( tab, "textLabel1_4_4_3_2" );
    layout6_3_3_2->addWidget( textLabel1_4_4_3_2 );

    QLEFunciones = new QLineEdit( tab, "QLEFunciones" );
    QLEFunciones->setEnabled( FALSE );
    layout6_3_3_2->addWidget( QLEFunciones );
    layout18->addLayout( layout6_3_3_2 );

    layout6_3_4_2 = new QVBoxLayout( 0, 0, 6, "layout6_3_4_2"); 

    textLabel1_4_4_4_2 = new QLabel( tab, "textLabel1_4_4_4_2" );
    layout6_3_4_2->addWidget( textLabel1_4_4_4_2 );

    QLEPeriodo = new QLineEdit( tab, "QLEPeriodo" );
    QLEPeriodo->setEnabled( FALSE );
    layout6_3_4_2->addWidget( QLEPeriodo );
    layout18->addLayout( layout6_3_4_2 );
    layout71->addLayout( layout18 );

    tabLayout->addLayout( layout71, 0, 0 );
    spacer1 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout->addItem( spacer1, 1, 0 );
    QTWComplementarios->insertTab( tab, QString::fromLatin1("") );

    TabPage = new QWidget( QTWComplementarios, "TabPage" );
    TabPageLayout = new QGridLayout( TabPage, 1, 1, 11, 6, "TabPageLayout"); 

    layout72 = new QVBoxLayout( 0, 0, 6, "layout72"); 

    QGBBeneficios = new QButtonGroup( TabPage, "QGBBeneficios" );
    QGBBeneficios->setAlignment( int( QButtonGroup::AlignLeft ) );
    QGBBeneficios->setFlat( FALSE );
    QGBBeneficios->setColumnLayout(0, Qt::Vertical );
    QGBBeneficios->layout()->setSpacing( 6 );
    QGBBeneficios->layout()->setMargin( 11 );
    QGBBeneficiosLayout = new QHBoxLayout( QGBBeneficios->layout() );
    QGBBeneficiosLayout->setAlignment( Qt::AlignTop );

    textLabel2_2_2 = new QLabel( QGBBeneficios, "textLabel2_2_2" );
    QGBBeneficiosLayout->addWidget( textLabel2_2_2 );

    radioButton2_3_2_2 = new QRadioButton( QGBBeneficios, "radioButton2_3_2_2" );
    radioButton2_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, radioButton2_3_2_2->sizePolicy().hasHeightForWidth() ) );
    QGBBeneficiosLayout->addWidget( radioButton2_3_2_2 );

    radioButton2_2_2_2_2 = new QRadioButton( QGBBeneficios, "radioButton2_2_2_2_2" );
    radioButton2_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, radioButton2_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    QGBBeneficiosLayout->addWidget( radioButton2_2_2_2_2 );
    layout72->addWidget( QGBBeneficios );

    layout30_2 = new QVBoxLayout( 0, 0, 6, "layout30_2"); 

    textLabel3_2 = new QLabel( TabPage, "textLabel3_2" );
    layout30_2->addWidget( textLabel3_2 );

    QLENombreBeneficiado = new QLineEdit( TabPage, "QLENombreBeneficiado" );
    QLENombreBeneficiado->setEnabled( FALSE );
    layout30_2->addWidget( QLENombreBeneficiado );
    layout72->addLayout( layout30_2 );

    QGBAportaTercero = new QButtonGroup( TabPage, "QGBAportaTercero" );
    QGBAportaTercero->setAlignment( int( QButtonGroup::AlignLeft ) );
    QGBAportaTercero->setFlat( FALSE );
    QGBAportaTercero->setColumnLayout(0, Qt::Vertical );
    QGBAportaTercero->layout()->setSpacing( 6 );
    QGBAportaTercero->layout()->setMargin( 11 );
    QGBAportaTerceroLayout = new QHBoxLayout( QGBAportaTercero->layout() );
    QGBAportaTerceroLayout->setAlignment( Qt::AlignTop );

    textLabel2_2_2_2 = new QLabel( QGBAportaTercero, "textLabel2_2_2_2" );
    QGBAportaTerceroLayout->addWidget( textLabel2_2_2_2 );

    radioButton2_3_2_2_2 = new QRadioButton( QGBAportaTercero, "radioButton2_3_2_2_2" );
    radioButton2_3_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, radioButton2_3_2_2_2->sizePolicy().hasHeightForWidth() ) );
    QGBAportaTerceroLayout->addWidget( radioButton2_3_2_2_2 );

    radioButton2_2_2_2_2_2 = new QRadioButton( QGBAportaTercero, "radioButton2_2_2_2_2_2" );
    radioButton2_2_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, radioButton2_2_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    QGBAportaTerceroLayout->addWidget( radioButton2_2_2_2_2_2 );
    layout72->addWidget( QGBAportaTercero );

    layout30_2_2 = new QVBoxLayout( 0, 0, 6, "layout30_2_2"); 

    textLabel3_2_2 = new QLabel( TabPage, "textLabel3_2_2" );
    layout30_2_2->addWidget( textLabel3_2_2 );

    QLEAportaTercero = new QLineEdit( TabPage, "QLEAportaTercero" );
    QLEAportaTercero->setEnabled( FALSE );
    layout30_2_2->addWidget( QLEAportaTercero );
    layout72->addLayout( layout30_2_2 );

    TabPageLayout->addLayout( layout72, 0, 0 );
    spacer2 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    TabPageLayout->addItem( spacer2, 1, 0 );
    QTWComplementarios->insertTab( TabPage, QString::fromLatin1("") );

    TabPage_2 = new QWidget( QTWComplementarios, "TabPage_2" );
    TabPageLayout_2 = new QGridLayout( TabPage_2, 1, 1, 11, 6, "TabPageLayout_2"); 

    QTReferencias = new QTable( TabPage_2, "QTReferencias" );
    QTReferencias->setNumCols( QTReferencias->numCols() + 1 );
    QTReferencias->horizontalHeader()->setLabel( QTReferencias->numCols() - 1, tr( "Nombre Completo" ) );
    QTReferencias->setNumCols( QTReferencias->numCols() + 1 );
    QTReferencias->horizontalHeader()->setLabel( QTReferencias->numCols() - 1, tr( "Domicilio" ) );
    QTReferencias->setNumCols( QTReferencias->numCols() + 1 );
    QTReferencias->horizontalHeader()->setLabel( QTReferencias->numCols() - 1, tr( "Telefono" ) );
    QTReferencias->setNumCols( QTReferencias->numCols() + 1 );
    QTReferencias->horizontalHeader()->setLabel( QTReferencias->numCols() - 1, tr( "Parentesco" ) );
    QTReferencias->setNumRows( 0 );
    QTReferencias->setNumCols( 4 );

    TabPageLayout_2->addMultiCellWidget( QTReferencias, 5, 5, 0, 1 );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel6 = new QLabel( TabPage_2, "textLabel6" );
    layout22->addWidget( textLabel6 );

    QLECalle = new QLineEdit( TabPage_2, "QLECalle" );
    QLECalle->setReadOnly( FALSE );
    layout22->addWidget( QLECalle );
    layout25->addLayout( layout22 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel5 = new QLabel( TabPage_2, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( textLabel5 );

    QLENoExterior = new QLineEdit( TabPage_2, "QLENoExterior" );
    QLENoExterior->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENoExterior->sizePolicy().hasHeightForWidth() ) );
    QLENoExterior->setReadOnly( FALSE );
    layout16->addWidget( QLENoExterior );
    layout25->addLayout( layout16 );

    layout16_2 = new QVBoxLayout( 0, 0, 6, "layout16_2"); 

    textLabel5_2 = new QLabel( TabPage_2, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2->addWidget( textLabel5_2 );

    QLENoInterior = new QLineEdit( TabPage_2, "QLENoInterior" );
    QLENoInterior->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENoInterior->sizePolicy().hasHeightForWidth() ) );
    QLENoInterior->setReadOnly( FALSE );
    layout16_2->addWidget( QLENoInterior );
    layout25->addLayout( layout16_2 );

    TabPageLayout_2->addMultiCellLayout( layout25, 1, 1, 0, 1 );

    layout87 = new QHBoxLayout( 0, 0, 6, "layout87"); 

    layout81 = new QVBoxLayout( 0, 0, 6, "layout81"); 

    textLabel3 = new QLabel( TabPage_2, "textLabel3" );
    layout81->addWidget( textLabel3 );

    QLEApellidoPaterno = new QLineEdit( TabPage_2, "QLEApellidoPaterno" );
    layout81->addWidget( QLEApellidoPaterno );
    layout87->addLayout( layout81 );

    layout83 = new QVBoxLayout( 0, 0, 6, "layout83"); 

    textLabel3_2_3 = new QLabel( TabPage_2, "textLabel3_2_3" );
    layout83->addWidget( textLabel3_2_3 );

    QLEApellidoMaterno = new QLineEdit( TabPage_2, "QLEApellidoMaterno" );
    layout83->addWidget( QLEApellidoMaterno );
    layout87->addLayout( layout83 );

    layout84 = new QVBoxLayout( 0, 0, 6, "layout84"); 

    textLabel4 = new QLabel( TabPage_2, "textLabel4" );
    layout84->addWidget( textLabel4 );

    QLENombres = new QLineEdit( TabPage_2, "QLENombres" );
    layout84->addWidget( QLENombres );
    layout87->addLayout( layout84 );

    TabPageLayout_2->addMultiCellLayout( layout87, 0, 0, 0, 1 );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    layout22_2 = new QVBoxLayout( 0, 0, 6, "layout22_2"); 

    textLabel6_2 = new QLabel( TabPage_2, "textLabel6_2" );
    layout22_2->addWidget( textLabel6_2 );

    QLEColonia = new QLineEdit( TabPage_2, "QLEColonia" );
    QLEColonia->setReadOnly( FALSE );
    layout22_2->addWidget( QLEColonia );
    layout36->addLayout( layout22_2 );

    layout22_2_2 = new QVBoxLayout( 0, 0, 6, "layout22_2_2"); 

    textLabel6_2_2 = new QLabel( TabPage_2, "textLabel6_2_2" );
    layout22_2_2->addWidget( textLabel6_2_2 );

    QLEDelegacionMunicipio = new QLineEdit( TabPage_2, "QLEDelegacionMunicipio" );
    layout22_2_2->addWidget( QLEDelegacionMunicipio );
    layout36->addLayout( layout22_2_2 );

    layout16_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2"); 

    textLabel5_2_2 = new QLabel( TabPage_2, "textLabel5_2_2" );
    textLabel5_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2->addWidget( textLabel5_2_2 );

    QLEEstado = new QLineEdit( TabPage_2, "QLEEstado" );
    QLEEstado->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEEstado->sizePolicy().hasHeightForWidth() ) );
    QLEEstado->setReadOnly( FALSE );
    layout16_2_2->addWidget( QLEEstado );
    layout36->addLayout( layout16_2_2 );

    layout16_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2_2"); 

    textLabel5_2_2_2 = new QLabel( TabPage_2, "textLabel5_2_2_2" );
    textLabel5_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2->addWidget( textLabel5_2_2_2 );

    QLECodigoPostal = new QLineEdit( TabPage_2, "QLECodigoPostal" );
    QLECodigoPostal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECodigoPostal->sizePolicy().hasHeightForWidth() ) );
    QLECodigoPostal->setReadOnly( FALSE );
    layout16_2_2_2->addWidget( QLECodigoPostal );
    layout36->addLayout( layout16_2_2_2 );

    TabPageLayout_2->addMultiCellLayout( layout36, 2, 2, 0, 1 );

    QPBAgregaReferencia = new QPushButton( TabPage_2, "QPBAgregaReferencia" );
    QPBAgregaReferencia->setEnabled( FALSE );
    QPBAgregaReferencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QPBAgregaReferencia->sizePolicy().hasHeightForWidth() ) );
    QPBAgregaReferencia->setAutoDefault( FALSE );

    TabPageLayout_2->addMultiCellWidget( QPBAgregaReferencia, 4, 4, 0, 1 );

    layout81_2_2 = new QVBoxLayout( 0, 0, 6, "layout81_2_2"); 

    textLabel3_3_2 = new QLabel( TabPage_2, "textLabel3_3_2" );
    layout81_2_2->addWidget( textLabel3_3_2 );

    QLETelefono = new QLineEdit( TabPage_2, "QLETelefono" );
    layout81_2_2->addWidget( QLETelefono );

    TabPageLayout_2->addLayout( layout81_2_2, 3, 0 );

    layout92 = new QVBoxLayout( 0, 0, 6, "layout92"); 

    textLabel3_3 = new QLabel( TabPage_2, "textLabel3_3" );
    layout92->addWidget( textLabel3_3 );

    QLEParentesco = new QLineEdit( TabPage_2, "QLEParentesco" );
    layout92->addWidget( QLEParentesco );

    TabPageLayout_2->addLayout( layout92, 3, 1 );
    QTWComplementarios->insertTab( TabPage_2, QString::fromLatin1("") );

    CapturaDatosComplementariosLayout->addWidget( QTWComplementarios, 0, 0 );
    languageChange();
    resize( QSize(776, 441).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDatosComplementarios::~CapturaDatosComplementarios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDatosComplementarios::languageChange()
{
    setCaption( tr( "Captura Datos Complementarios" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBAceptar->setAccel( QKeySequence( QString::null ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBRegistrar->setAccel( QKeySequence( QString::null ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBCancelar->setAccel( QKeySequence( QString::null ) );
    QGBCargoPublico->setTitle( tr( "Cargo Publico" ) );
    textLabel2_2->setText( trUtf8( "\xc2\xbf\x44\x65\x73\x65\x6d\x70\x65\xc3\xb1\x61\x20\x61\x63\x74\x75\x61\x6c\x6d\x65"
    "\x6e\x74\x6f\x20\x6f\x20\x64\x65\x73\x65\x6d\x70\x65\xc3\xb1\x6f\x20\x64\x75\x72"
    "\x61\x6e\x74\x65\x20\x65\x6c\x20\x61\xc3\xb1\x6f\x20\x69\x6e\x6d\x65\x64\x69\x61"
    "\x74\x6f\x20\x61\x6e\x74\x65\x72\x69\x6f\x72\x20\x61\x6c\x67\x75\x6e\x20\x63\x61"
    "\x72\x67\x6f\x20\x70\x75\x62\x6c\x69\x63\x6f\x20\x64\x65\x73\x74\x61\x63\x61\x64"
    "\x6f\x20\x61\x20\x6e\x69\x76\x65\x6c\x20\x66\x65\x64\x65\x72\x61\x6c\x2c\x20\x65"
    "\x73\x74\x61\x74\x61\x6c\x2c\x20\xa\x6d\x75\x6e\x69\x63\x69\x70\x61\x6c\x20\x6f"
    "\x20\x64\x69\x73\x74\x72\x69\x74\x61\x6c\x20\x65\x6e\x20\x4d\x65\x78\x69\x63\x6f"
    "\x20\x6f\x20\x65\x6e\x20\x61\x6c\x67\x75\x6e\x20\x70\x61\x69\x73\x20\x65\x78\x74"
    "\x72\x61\x6e\x6a\x65\x72\x6f\x3f" ) );
    QRBCPublicoSi->setText( tr( "Si" ) );
    QRBCPublicoNo->setText( tr( "No" ) );
    textLabel1_4_6->setText( tr( "En Caso Positivo, especificar:" ) );
    textLabel1_4_4_5->setText( tr( "Dependencia:" ) );
    textLabel1_4_4_2_2->setText( tr( "Puesto:" ) );
    textLabel1_4_4_3_2->setText( tr( "Principales Funciones:" ) );
    textLabel1_4_4_4_2->setText( tr( "Periodo De Ejercicio:" ) );
    QTWComplementarios->changeTab( tab, tr( "Cargo Publico" ) );
    QGBBeneficios->setTitle( tr( "Beneficios - Terceros" ) );
    textLabel2_2_2->setText( trUtf8( "\xc2\xbf\x41\x6c\x67\x75\x6e\x20\x74\x65\x72\x63\x65\x72\x6f\x20\x6f\x62\x74\x65\x6e"
    "\x64\x72\x61\x20\x6c\x6f\x73\x20\x62\x65\x6e\x65\x66\x69\x63\x69\x6f\x73\x20\x64"
    "\x65\x72\x69\x76\x61\x64\x6f\x73\x20\x64\x65\x20\x6c\x61\x73\x20\x6f\x70\x65\x72"
    "\x61\x63\x69\x6f\x6e\x65\x73\x20\x72\x65\x61\x6c\x69\x7a\x61\x64\x61\x73\x20\x63"
    "\x6f\x6e\x20\x22\x42\x45\x4e\x45\x46\x49\x43\x49\x4f\x53\x20\x49\x4e\x54\x45\x47"
    "\x52\x41\x4c\x45\x53\x20\x42\x53\x41\x22\x20\x79\x20\x65\x6a\x65\x72\x7a\x61\x20"
    "\x6c\x6f\x73\xa\x64\x65\x72\x65\x63\x68\x6f\x73\x20\x64\x65\x20\x75\x73\x6f\x2c"
    "\x20\x61\x70\x72\x6f\x76\x65\x63\x68\x61\x6d\x69\x65\x6e\x74\x6f\x20\x6f\x20\x64"
    "\x69\x73\x70\x6f\x73\x69\x63\x69\x6f\x6e\x20\x64\x65\x20\x6c\x6f\x73\x20\x72\x65"
    "\x63\x75\x72\x73\x6f\x73\x20\x6f\x70\x65\x72\x61\x64\x6f\x73\x2c\x20\x73\x69\x65"
    "\x6e\x64\x6f\x20\x65\x6c\x20\x76\x65\x72\x64\x61\x64\x65\x72\x6f\x20\x70\x72\x6f"
    "\x70\x69\x65\x74\x61\x72\x69\x6f\x20\x64\x65\x20\x6c\x6f\x73\x20\x6d\x69\x73\x6d"
    "\x6f\x73\x3f" ) );
    radioButton2_3_2_2->setText( tr( "Si" ) );
    radioButton2_2_2_2_2->setText( tr( "No" ) );
    textLabel3_2->setText( tr( "<p align=\"center\">En caso positivo, especificar el nombre de la persona fisica o moral y llenar el \"Formato De Identificacion De Propietarios Reales\"</p>" ) );
    QGBAportaTercero->setTitle( tr( "Aportador - Terceros" ) );
    textLabel2_2_2_2->setText( trUtf8( "\xc2\xbf\x41\x6c\x67\x75\x6e\x20\x74\x65\x72\x63\x65\x72\x6f\x20\x61\x70\x6f\x72\x74"
    "\x61\x72\x61\x20\x72\x65\x67\x75\x6c\x61\x72\x6d\x65\x6e\x74\x65\x20\x72\x65\x63"
    "\x75\x72\x73\x6f\x73\x20\x70\x61\x72\x61\x20\x65\x6c\x20\x63\x75\x6d\x70\x6c\x69"
    "\x6d\x69\x65\x6e\x74\x6f\x20\x64\x65\x20\x6c\x61\x73\x20\x6f\x62\x6c\x69\x67\x61"
    "\x63\x69\x6f\x6e\x65\x73\x20\x64\x65\x72\x69\x76\x61\x64\x61\x73\x20\x64\x65\x6c"
    "\x20\x63\x6f\x6e\x74\x72\x61\x74\x6f\x20\x71\x75\x65\x20\x73\x65\x20\x65\x73\x74"
    "\x61\x62\x6c\x65\x7a\x63\x61\x20\x63\x6f\x6e\xa\x22\x42\x45\x4e\x45\x46\x49\x43"
    "\x49\x4f\x53\x20\x49\x4e\x54\x45\x47\x52\x41\x4c\x45\x53\x20\x42\x53\x41\x22\x2c"
    "\x20\x73\x69\x6e\x20\x73\x65\x72\x20\x65\x6c\x20\x74\x69\x74\x75\x6c\x61\x72\x20"
    "\x64\x65\x20\x64\x69\x63\x68\x6f\x20\x63\x6f\x6e\x74\x72\x61\x74\x6f\x20\x6e\x69"
    "\x20\x6f\x62\x74\x65\x6e\x65\x72\x20\x6c\x6f\x73\x20\x62\x65\x6e\x65\x66\x69\x63"
    "\x69\x6f\x73\x20\x65\x63\x6f\x6e\x6f\x6d\x69\x63\x6f\x73\x20\x64\x65\x72\x69\x76"
    "\x61\x64\x6f\x73\x20\x64\x65\x6c\x20\x6d\x69\x73\x6d\x6f\x3f" ) );
    radioButton2_3_2_2_2->setText( tr( "Si" ) );
    radioButton2_2_2_2_2_2->setText( tr( "No" ) );
    textLabel3_2_2->setText( tr( "<p align=\"center\">En caso positivo, especificar el nombre de la persona fisica o moral y llenar el \"Formato De Identificacion De Proveedores De Recursos\"</p>" ) );
    QTWComplementarios->changeTab( TabPage, tr( "Beneficios" ) );
    QTReferencias->horizontalHeader()->setLabel( 0, tr( "Nombre Completo" ) );
    QTReferencias->horizontalHeader()->setLabel( 1, tr( "Domicilio" ) );
    QTReferencias->horizontalHeader()->setLabel( 2, tr( "Telefono" ) );
    QTReferencias->horizontalHeader()->setLabel( 3, tr( "Parentesco" ) );
    textLabel6->setText( tr( "Calle" ) );
    textLabel5->setText( tr( "No Exterior" ) );
    textLabel5_2->setText( tr( "No Interior" ) );
    textLabel3->setText( tr( "Apellido Paterno:" ) );
    textLabel3_2_3->setText( tr( "Apellido Materno:" ) );
    textLabel4->setText( tr( "Nombres:" ) );
    textLabel6_2->setText( tr( "Colonia" ) );
    textLabel6_2_2->setText( tr( "Delegacion/Municipio" ) );
    textLabel5_2_2->setText( tr( "Estado" ) );
    textLabel5_2_2_2->setText( tr( "Codigo Postal" ) );
    QPBAgregaReferencia->setText( tr( "Agregar Referencia" ) );
    textLabel3_3_2->setText( tr( "Telefono" ) );
    textLabel3_3->setText( tr( "Parentesco" ) );
    QTWComplementarios->changeTab( TabPage_2, tr( "Referencias Personales" ) );
}

