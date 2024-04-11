/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaDatosGenerales.ui'
**
** Created: Thu Apr 11 21:07:24 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaDatosGenerales.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDatosGenerales as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDatosGenerales::CapturaDatosGenerales( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDatosGenerales" );
    CapturaDatosGeneralesLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDatosGeneralesLayout"); 

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout22->addWidget( textLabel6 );

    QLERFCHomoclave = new QLineEdit( this, "QLERFCHomoclave" );
    QLERFCHomoclave->setReadOnly( TRUE );
    layout22->addWidget( QLERFCHomoclave );
    layout17->addLayout( layout22 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( textLabel5 );

    QLECurp = new QLineEdit( this, "QLECurp" );
    QLECurp->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLECurp->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( QLECurp );
    layout17->addLayout( layout16 );

    layout16_2 = new QVBoxLayout( 0, 0, 6, "layout16_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2->addWidget( textLabel5_2 );

    QLEEstadoNacimiento = new QLineEdit( this, "QLEEstadoNacimiento" );
    QLEEstadoNacimiento->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEEstadoNacimiento->sizePolicy().hasHeightForWidth() ) );
    layout16_2->addWidget( QLEEstadoNacimiento );
    layout17->addLayout( layout16_2 );

    CapturaDatosGeneralesLayout->addLayout( layout17, 0, 0 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    layout22_2 = new QVBoxLayout( 0, 0, 6, "layout22_2"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    layout22_2->addWidget( textLabel6_2 );

    QLEPaisNacimiento = new QLineEdit( this, "QLEPaisNacimiento" );
    layout22_2->addWidget( QLEPaisNacimiento );
    layout21->addLayout( layout22_2 );

    QGBSexo = new QButtonGroup( this, "QGBSexo" );
    QGBSexo->setAlignment( int( QButtonGroup::AlignHCenter ) );
    QGBSexo->setColumnLayout(0, Qt::Vertical );
    QGBSexo->layout()->setSpacing( 6 );
    QGBSexo->layout()->setMargin( 11 );
    QGBSexoLayout = new QHBoxLayout( QGBSexo->layout() );
    QGBSexoLayout->setAlignment( Qt::AlignTop );

    QRBMasculino = new QRadioButton( QGBSexo, "QRBMasculino" );
    QGBSexoLayout->addWidget( QRBMasculino );

    QRBFemenino = new QRadioButton( QGBSexo, "QRBFemenino" );
    QGBSexoLayout->addWidget( QRBFemenino );
    layout21->addWidget( QGBSexo );

    buttonGroup1_2 = new QButtonGroup( this, "buttonGroup1_2" );
    buttonGroup1_2->setAlignment( int( QButtonGroup::AlignHCenter ) );
    buttonGroup1_2->setColumnLayout(0, Qt::Vertical );
    buttonGroup1_2->layout()->setSpacing( 6 );
    buttonGroup1_2->layout()->setMargin( 11 );
    buttonGroup1_2Layout = new QHBoxLayout( buttonGroup1_2->layout() );
    buttonGroup1_2Layout->setAlignment( Qt::AlignTop );

    QRBCasado = new QRadioButton( buttonGroup1_2, "QRBCasado" );
    buttonGroup1_2Layout->addWidget( QRBCasado );

    QRBSoltero = new QRadioButton( buttonGroup1_2, "QRBSoltero" );
    buttonGroup1_2Layout->addWidget( QRBSoltero );
    layout21->addWidget( buttonGroup1_2 );

    layout16_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2_2"); 

    textLabel5_2_2_2 = new QLabel( this, "textLabel5_2_2_2" );
    textLabel5_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2->addWidget( textLabel5_2_2_2 );

    QLEEdad = new QLineEdit( this, "QLEEdad" );
    QLEEdad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEEdad->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2->addWidget( QLEEdad );
    layout21->addLayout( layout16_2_2_2 );

    layout16_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2_2_2"); 

    textLabel5_2_2_2_2 = new QLabel( this, "textLabel5_2_2_2_2" );
    textLabel5_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2_2->addWidget( textLabel5_2_2_2_2 );

    QLEFechaNacimiento = new QLineEdit( this, "QLEFechaNacimiento" );
    QLEFechaNacimiento->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEFechaNacimiento->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2_2->addWidget( QLEFechaNacimiento );
    layout21->addLayout( layout16_2_2_2_2 );

    CapturaDatosGeneralesLayout->addLayout( layout21, 1, 0 );

    layout22_3 = new QHBoxLayout( 0, 0, 6, "layout22_3"); 

    layout13_5 = new QGridLayout( 0, 1, 1, 0, 6, "layout13_5"); 

    textLabel2_5 = new QLabel( this, "textLabel2_5" );

    layout13_5->addWidget( textLabel2_5, 0, 0 );

    QLEIdentificacion = new QLineEdit( this, "QLEIdentificacion" );
    QLEIdentificacion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEIdentificacion->sizePolicy().hasHeightForWidth() ) );

    layout13_5->addWidget( QLEIdentificacion, 1, 0 );
    layout22_3->addLayout( layout13_5 );

    layout13_6 = new QGridLayout( 0, 1, 1, 0, 6, "layout13_6"); 

    textLabel2_6 = new QLabel( this, "textLabel2_6" );

    layout13_6->addWidget( textLabel2_6, 0, 0 );

    QLENoIdentificacion = new QLineEdit( this, "QLENoIdentificacion" );

    layout13_6->addWidget( QLENoIdentificacion, 1, 0 );
    layout22_3->addLayout( layout13_6 );

    layout13_6_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout13_6_2"); 

    textLabel2_6_2 = new QLabel( this, "textLabel2_6_2" );

    layout13_6_2->addWidget( textLabel2_6_2, 0, 0 );

    QLEOcupacion = new QLineEdit( this, "QLEOcupacion" );

    layout13_6_2->addWidget( QLEOcupacion, 1, 0 );
    layout22_3->addLayout( layout13_6_2 );

    layout13_6_2_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout13_6_2_2"); 

    textLabel2_6_2_2 = new QLabel( this, "textLabel2_6_2_2" );

    layout13_6_2_2->addWidget( textLabel2_6_2_2, 0, 0 );

    QLENacionalidad = new QLineEdit( this, "QLENacionalidad" );

    layout13_6_2_2->addWidget( QLENacionalidad, 1, 0 );
    layout22_3->addLayout( layout13_6_2_2 );

    CapturaDatosGeneralesLayout->addLayout( layout22_3, 2, 0 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );
    layout15->addWidget( QPBRegistrar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setAutoDefault( FALSE );
    layout15->addWidget( QPBActualizar );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout15->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout15->addWidget( QPBCancelar );

    CapturaDatosGeneralesLayout->addLayout( layout15, 3, 0 );
    languageChange();
    resize( QSize(839, 189).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( QLERFCHomoclave, QLECurp );
    setTabOrder( QLECurp, QLEEstadoNacimiento );
    setTabOrder( QLEEstadoNacimiento, QLEPaisNacimiento );
    setTabOrder( QLEPaisNacimiento, QLEEdad );
    setTabOrder( QLEEdad, QPBAceptar );
    setTabOrder( QPBAceptar, QPBCancelar );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDatosGenerales::~CapturaDatosGenerales()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDatosGenerales::languageChange()
{
    setCaption( tr( "Captura Datos Generales" ) );
    textLabel6->setText( tr( "R.F.C. con Homoclave" ) );
    QLERFCHomoclave->setText( QString::null );
    textLabel5->setText( tr( "CURP" ) );
    QLECurp->setText( QString::null );
    textLabel5_2->setText( tr( "Entidad Federativa De Nacimiento" ) );
    QLEEstadoNacimiento->setText( QString::null );
    textLabel6_2->setText( tr( "Pais Nacimiento" ) );
    QLEPaisNacimiento->setText( QString::null );
    QGBSexo->setTitle( tr( "Genero" ) );
    QRBMasculino->setText( tr( "Masculino" ) );
    QRBFemenino->setText( tr( "Femenino" ) );
    buttonGroup1_2->setTitle( tr( "Estado Civil" ) );
    QRBCasado->setText( tr( "Casado(a)" ) );
    QRBSoltero->setText( tr( "Soltero(a)" ) );
    textLabel5_2_2_2->setText( tr( "Edad" ) );
    QLEEdad->setText( QString::null );
    textLabel5_2_2_2_2->setText( tr( "Fecha De Nacimiento (AAAA-MM-DD)" ) );
    QLEFechaNacimiento->setText( tr( "--" ) );
    QLEFechaNacimiento->setInputMask( tr( "0000-00-00; " ) );
    textLabel2_5->setText( tr( "Identificacion que presenta" ) );
    QLEIdentificacion->setText( QString::null );
    textLabel2_6->setText( tr( "No. De Indentificacion" ) );
    QLENoIdentificacion->setText( QString::null );
    textLabel2_6_2->setText( tr( "Ocupacion" ) );
    QLEOcupacion->setText( QString::null );
    textLabel2_6_2_2->setText( tr( "Nacionalidad" ) );
    QLENacionalidad->setText( QString::null );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

