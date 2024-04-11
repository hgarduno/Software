/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaDatosEmpleo.ui'
**
** Created: Sat Jan 27 16:37:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaDatosEmpleo.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFrecuenciaPagosSS.h"

/*
 *  Constructs a CapturaDatosEmpleo as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDatosEmpleo::CapturaDatosEmpleo( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDatosEmpleo" );
    CapturaDatosEmpleoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDatosEmpleoLayout"); 

    groupBox1_2 = new QGroupBox( this, "groupBox1_2" );
    groupBox1_2->setColumnLayout(0, Qt::Vertical );
    groupBox1_2->layout()->setSpacing( 6 );
    groupBox1_2->layout()->setMargin( 11 );
    groupBox1_2Layout = new QGridLayout( groupBox1_2->layout() );
    groupBox1_2Layout->setAlignment( Qt::AlignTop );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout22_4 = new QVBoxLayout( 0, 0, 6, "layout22_4"); 

    textLabel6_4 = new QLabel( groupBox1_2, "textLabel6_4" );
    layout22_4->addWidget( textLabel6_4 );

    QLECalle = new QLineEdit( groupBox1_2, "QLECalle" );
    layout22_4->addWidget( QLECalle );
    layout25->addLayout( layout22_4 );

    layout16_4 = new QVBoxLayout( 0, 0, 6, "layout16_4"); 

    textLabel5_4 = new QLabel( groupBox1_2, "textLabel5_4" );
    textLabel5_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_4->sizePolicy().hasHeightForWidth() ) );
    layout16_4->addWidget( textLabel5_4 );

    QLENoExterior = new QLineEdit( groupBox1_2, "QLENoExterior" );
    QLENoExterior->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENoExterior->sizePolicy().hasHeightForWidth() ) );
    layout16_4->addWidget( QLENoExterior );
    layout25->addLayout( layout16_4 );

    layout16_2_4 = new QVBoxLayout( 0, 0, 6, "layout16_2_4"); 

    textLabel5_2_4 = new QLabel( groupBox1_2, "textLabel5_2_4" );
    textLabel5_2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_4->sizePolicy().hasHeightForWidth() ) );
    layout16_2_4->addWidget( textLabel5_2_4 );

    QLENoInterior = new QLineEdit( groupBox1_2, "QLENoInterior" );
    QLENoInterior->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENoInterior->sizePolicy().hasHeightForWidth() ) );
    layout16_2_4->addWidget( QLENoInterior );
    layout25->addLayout( layout16_2_4 );

    groupBox1_2Layout->addLayout( layout25, 0, 0 );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    layout22_2_4 = new QVBoxLayout( 0, 0, 6, "layout22_2_4"); 

    textLabel6_2_4 = new QLabel( groupBox1_2, "textLabel6_2_4" );
    layout22_2_4->addWidget( textLabel6_2_4 );

    QLEColonia = new QLineEdit( groupBox1_2, "QLEColonia" );
    layout22_2_4->addWidget( QLEColonia );
    layout36->addLayout( layout22_2_4 );

    layout22_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout22_2_2_3"); 

    textLabel6_2_2_3 = new QLabel( groupBox1_2, "textLabel6_2_2_3" );
    layout22_2_2_3->addWidget( textLabel6_2_2_3 );

    QLEDelegacionMunicipio = new QLineEdit( groupBox1_2, "QLEDelegacionMunicipio" );
    layout22_2_2_3->addWidget( QLEDelegacionMunicipio );
    layout36->addLayout( layout22_2_2_3 );

    layout16_2_2_4 = new QVBoxLayout( 0, 0, 6, "layout16_2_2_4"); 

    textLabel5_2_2_4 = new QLabel( groupBox1_2, "textLabel5_2_2_4" );
    textLabel5_2_2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2_4->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_4->addWidget( textLabel5_2_2_4 );

    QLEEstado = new QLineEdit( groupBox1_2, "QLEEstado" );
    QLEEstado->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEEstado->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_4->addWidget( QLEEstado );
    layout36->addLayout( layout16_2_2_4 );

    layout16_2_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout16_2_2_2_3"); 

    textLabel5_2_2_2_3 = new QLabel( groupBox1_2, "textLabel5_2_2_2_3" );
    textLabel5_2_2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2_2_3->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2_3->addWidget( textLabel5_2_2_2_3 );

    QLECodigoPostal = new QLineEdit( groupBox1_2, "QLECodigoPostal" );
    QLECodigoPostal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECodigoPostal->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2_3->addWidget( QLECodigoPostal );
    layout36->addLayout( layout16_2_2_2_3 );

    groupBox1_2Layout->addLayout( layout36, 1, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout2_2_5 = new QVBoxLayout( 0, 0, 6, "layout2_2_5"); 

    textLabel1_2_5 = new QLabel( groupBox1_2, "textLabel1_2_5" );
    layout2_2_5->addWidget( textLabel1_2_5 );

    QLEPais = new QLineEdit( groupBox1_2, "QLEPais" );
    QLEPais->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEPais->sizePolicy().hasHeightForWidth() ) );
    layout2_2_5->addWidget( QLEPais );
    layout22->addLayout( layout2_2_5 );

    layout2_2_5_2 = new QVBoxLayout( 0, 0, 6, "layout2_2_5_2"); 

    textLabel1_2_5_2 = new QLabel( groupBox1_2, "textLabel1_2_5_2" );
    layout2_2_5_2->addWidget( textLabel1_2_5_2 );

    QLETelefono = new QLineEdit( groupBox1_2, "QLETelefono" );
    QLETelefono->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLETelefono->sizePolicy().hasHeightForWidth() ) );
    layout2_2_5_2->addWidget( QLETelefono );
    layout22->addLayout( layout2_2_5_2 );

    layout2_2_5_3 = new QVBoxLayout( 0, 0, 6, "layout2_2_5_3"); 

    textLabel1_2_5_3 = new QLabel( groupBox1_2, "textLabel1_2_5_3" );
    layout2_2_5_3->addWidget( textLabel1_2_5_3 );

    QLEExtension = new QLineEdit( groupBox1_2, "QLEExtension" );
    QLEExtension->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEExtension->sizePolicy().hasHeightForWidth() ) );
    layout2_2_5_3->addWidget( QLEExtension );
    layout22->addLayout( layout2_2_5_3 );

    layout2_2_5_4 = new QVBoxLayout( 0, 0, 6, "layout2_2_5_4"); 

    textLabel1_2_5_4 = new QLabel( groupBox1_2, "textLabel1_2_5_4" );
    layout2_2_5_4->addWidget( textLabel1_2_5_4 );

    QLECorreoElectronico = new QLineEdit( groupBox1_2, "QLECorreoElectronico" );
    layout2_2_5_4->addWidget( QLECorreoElectronico );
    layout22->addLayout( layout2_2_5_4 );

    groupBox1_2Layout->addLayout( layout22, 2, 0 );

    CapturaDatosEmpleoLayout->addWidget( groupBox1_2, 1, 0 );

    groupBox1_2_2 = new QGroupBox( this, "groupBox1_2_2" );
    groupBox1_2_2->setColumnLayout(0, Qt::Vertical );
    groupBox1_2_2->layout()->setSpacing( 6 );
    groupBox1_2_2->layout()->setMargin( 11 );
    groupBox1_2_2Layout = new QGridLayout( groupBox1_2_2->layout() );
    groupBox1_2_2Layout->setAlignment( Qt::AlignTop );

    layout31 = new QHBoxLayout( 0, 0, 6, "layout31"); 

    layout2_2_5_5_2 = new QVBoxLayout( 0, 0, 6, "layout2_2_5_5_2"); 

    textLabel1_2_5_5_3 = new QLabel( groupBox1_2_2, "textLabel1_2_5_5_3" );
    layout2_2_5_5_2->addWidget( textLabel1_2_5_5_3 );

    QLEOtrosIngresos = new QLineEdit( groupBox1_2_2, "QLEOtrosIngresos" );
    QLEOtrosIngresos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEOtrosIngresos->sizePolicy().hasHeightForWidth() ) );
    layout2_2_5_5_2->addWidget( QLEOtrosIngresos );
    layout31->addLayout( layout2_2_5_5_2 );

    layout2_2_5_5_2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2_5_5_2_2"); 

    textLabel1_2_5_5_3_2 = new QLabel( groupBox1_2_2, "textLabel1_2_5_5_3_2" );
    layout2_2_5_5_2_2->addWidget( textLabel1_2_5_5_3_2 );

    QLEEspecificacionIngresos = new QLineEdit( groupBox1_2_2, "QLEEspecificacionIngresos" );
    layout2_2_5_5_2_2->addWidget( QLEEspecificacionIngresos );
    layout31->addLayout( layout2_2_5_5_2_2 );

    layout2_2_5_5_2_3 = new QVBoxLayout( 0, 0, 6, "layout2_2_5_5_2_3"); 

    textLabel1_2_5_5_3_3 = new QLabel( groupBox1_2_2, "textLabel1_2_5_5_3_3" );
    layout2_2_5_5_2_3->addWidget( textLabel1_2_5_5_3_3 );

    QLETotalIngresos = new QLineEdit( groupBox1_2_2, "QLETotalIngresos" );
    QLETotalIngresos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLETotalIngresos->sizePolicy().hasHeightForWidth() ) );
    layout2_2_5_5_2_3->addWidget( QLETotalIngresos );
    layout31->addLayout( layout2_2_5_5_2_3 );

    groupBox1_2_2Layout->addMultiCellLayout( layout31, 1, 1, 0, 1 );

    layout2_2_5_5 = new QVBoxLayout( 0, 0, 6, "layout2_2_5_5"); 

    textLabel1_2_5_5 = new QLabel( groupBox1_2_2, "textLabel1_2_5_5" );
    layout2_2_5_5->addWidget( textLabel1_2_5_5 );

    QLESueldo = new QLineEdit( groupBox1_2_2, "QLESueldo" );
    QLESueldo->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLESueldo->sizePolicy().hasHeightForWidth() ) );
    layout2_2_5_5->addWidget( QLESueldo );

    groupBox1_2_2Layout->addLayout( layout2_2_5_5, 0, 0 );

    layout30 = new QVBoxLayout( 0, 0, 6, "layout30"); 

    textLabel1_2_5_5_2 = new QLabel( groupBox1_2_2, "textLabel1_2_5_5_2" );
    layout30->addWidget( textLabel1_2_5_5_2 );

    QCtrFrecuenciaPago = new QCtrlFrecuenciaPagosSS( groupBox1_2_2, "QCtrFrecuenciaPago" );
    layout30->addWidget( QCtrFrecuenciaPago );

    groupBox1_2_2Layout->addLayout( layout30, 0, 1 );

    CapturaDatosEmpleoLayout->addWidget( groupBox1_2_2, 2, 0 );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( groupBox1, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QLENombreEmpresa = new QLineEdit( groupBox1, "QLENombreEmpresa" );
    layout2->addWidget( QLENombreEmpresa );
    layout6->addLayout( layout2 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel1_2 = new QLabel( groupBox1, "textLabel1_2" );
    layout2_2->addWidget( textLabel1_2 );

    QLEAntiguedad = new QLineEdit( groupBox1, "QLEAntiguedad" );
    QLEAntiguedad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEAntiguedad->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( QLEAntiguedad );
    layout6->addLayout( layout2_2 );

    layout2_2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2_2"); 

    textLabel1_2_2 = new QLabel( groupBox1, "textLabel1_2_2" );
    layout2_2_2->addWidget( textLabel1_2_2 );

    QLEPuesto = new QLineEdit( groupBox1, "QLEPuesto" );
    QLEPuesto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEPuesto->sizePolicy().hasHeightForWidth() ) );
    layout2_2_2->addWidget( QLEPuesto );
    layout6->addLayout( layout2_2_2 );

    groupBox1Layout->addMultiCellLayout( layout6, 0, 0, 0, 1 );

    layout2_2_3 = new QVBoxLayout( 0, 0, 6, "layout2_2_3"); 

    textLabel1_2_3 = new QLabel( groupBox1, "textLabel1_2_3" );
    layout2_2_3->addWidget( textLabel1_2_3 );

    QLEActGiroEmpresa = new QLineEdit( groupBox1, "QLEActGiroEmpresa" );
    QLEActGiroEmpresa->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEActGiroEmpresa->sizePolicy().hasHeightForWidth() ) );
    layout2_2_3->addWidget( QLEActGiroEmpresa );

    groupBox1Layout->addLayout( layout2_2_3, 1, 0 );

    groupBox6 = new QGroupBox( groupBox1, "groupBox6" );
    groupBox6->setColumnLayout(0, Qt::Vertical );
    groupBox6->layout()->setSpacing( 6 );
    groupBox6->layout()->setMargin( 11 );
    groupBox6Layout = new QGridLayout( groupBox6->layout() );
    groupBox6Layout->setAlignment( Qt::AlignTop );

    layout96 = new QVBoxLayout( 0, 0, 6, "layout96"); 

    textLabel1_2_4 = new QLabel( groupBox6, "textLabel1_2_4" );
    layout96->addWidget( textLabel1_2_4 );

    QLENombre = new QLineEdit( groupBox6, "QLENombre" );
    layout96->addWidget( QLENombre );

    groupBox6Layout->addLayout( layout96, 0, 0 );

    layout96_3 = new QVBoxLayout( 0, 0, 6, "layout96_3"); 

    textLabel1_2_4_3 = new QLabel( groupBox6, "textLabel1_2_4_3" );
    layout96_3->addWidget( textLabel1_2_4_3 );

    QLEAPaterno = new QLineEdit( groupBox6, "QLEAPaterno" );
    layout96_3->addWidget( QLEAPaterno );

    groupBox6Layout->addLayout( layout96_3, 0, 1 );

    layout96_2 = new QVBoxLayout( 0, 0, 6, "layout96_2"); 

    textLabel1_2_4_2 = new QLabel( groupBox6, "textLabel1_2_4_2" );
    layout96_2->addWidget( textLabel1_2_4_2 );

    QLEAMaterno = new QLineEdit( groupBox6, "QLEAMaterno" );
    layout96_2->addWidget( QLEAMaterno );

    groupBox6Layout->addLayout( layout96_2, 0, 2 );

    groupBox1Layout->addWidget( groupBox6, 1, 1 );

    CapturaDatosEmpleoLayout->addWidget( groupBox1, 0, 0 );

    layout30_2 = new QHBoxLayout( 0, 0, 6, "layout30_2"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );
    layout30_2->addWidget( QPBRegistrar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setAutoDefault( FALSE );
    layout30_2->addWidget( QPBActualizar );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout30_2->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout30_2->addWidget( QPBCancelar );

    CapturaDatosEmpleoLayout->addLayout( layout30_2, 3, 0 );
    languageChange();
    resize( QSize(710, 473).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDatosEmpleo::~CapturaDatosEmpleo()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDatosEmpleo::languageChange()
{
    setCaption( tr( "Captura Datos Empleo" ) );
    groupBox1_2->setTitle( tr( "Domicilio" ) );
    textLabel6_4->setText( tr( "Calle" ) );
    QLECalle->setText( QString::null );
    textLabel5_4->setText( tr( "No Exterior" ) );
    QLENoExterior->setText( QString::null );
    textLabel5_2_4->setText( tr( "No Interior" ) );
    QLENoInterior->setText( QString::null );
    textLabel6_2_4->setText( tr( "Colonia" ) );
    QLEColonia->setText( QString::null );
    textLabel6_2_2_3->setText( tr( "Delegacion/Municipio" ) );
    QLEDelegacionMunicipio->setText( QString::null );
    textLabel5_2_2_4->setText( tr( "Estado" ) );
    QLEEstado->setText( QString::null );
    textLabel5_2_2_2_3->setText( tr( "Codigo Postal" ) );
    QLECodigoPostal->setText( QString::null );
    textLabel1_2_5->setText( tr( "Pais" ) );
    QLEPais->setText( QString::null );
    textLabel1_2_5_2->setText( tr( "Telefono" ) );
    QLETelefono->setText( QString::null );
    textLabel1_2_5_3->setText( tr( "Extension" ) );
    QLEExtension->setText( QString::null );
    textLabel1_2_5_4->setText( tr( "Correo Electronico" ) );
    QLECorreoElectronico->setText( QString::null );
    groupBox1_2_2->setTitle( tr( "Ingresos Mensuales" ) );
    textLabel1_2_5_5_3->setText( tr( "Otros Ingresos" ) );
    QLEOtrosIngresos->setText( QString::null );
    textLabel1_2_5_5_3_2->setText( tr( "Expecifique Fuente (Otros Ingresos)" ) );
    QLEEspecificacionIngresos->setText( QString::null );
    textLabel1_2_5_5_3_3->setText( tr( "Total De Ingresos" ) );
    QLETotalIngresos->setText( QString::null );
    textLabel1_2_5_5->setText( tr( "Sueldo" ) );
    QLESueldo->setText( QString::null );
    textLabel1_2_5_5_2->setText( tr( "Frecuencia De Pago (Nomina)" ) );
    groupBox1->setTitle( tr( "Datos Generales" ) );
    textLabel1->setText( tr( "Nombre De La Empresa" ) );
    QLENombreEmpresa->setText( QString::null );
    textLabel1_2->setText( tr( "Antiguedad" ) );
    QLEAntiguedad->setText( QString::null );
    textLabel1_2_2->setText( tr( "Puesto Actual" ) );
    QLEPuesto->setText( QString::null );
    textLabel1_2_3->setText( tr( "Actividad/Giro De La Empresa" ) );
    QLEActGiroEmpresa->setText( QString::null );
    groupBox6->setTitle( tr( "Nombre del jefe directo" ) );
    textLabel1_2_4->setText( tr( "Nombre" ) );
    QLENombre->setText( QString::null );
    textLabel1_2_4_3->setText( tr( "Apellido Paterno" ) );
    QLEAPaterno->setText( QString::null );
    textLabel1_2_4_2->setText( tr( "Apellido Materno" ) );
    QLEAMaterno->setText( QString::null );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

