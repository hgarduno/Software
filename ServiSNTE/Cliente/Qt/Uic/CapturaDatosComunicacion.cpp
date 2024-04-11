/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaDatosComunicacion.ui'
**
** Created: Thu Apr 11 21:07:27 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaDatosComunicacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDatosComunicacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDatosComunicacion::CapturaDatosComunicacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDatosComunicacion" );
    CapturaDatosComunicacionLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDatosComunicacionLayout"); 

    groupBox3 = new QGroupBox( this, "groupBox3" );
    groupBox3->setColumnLayout(0, Qt::Vertical );
    groupBox3->layout()->setSpacing( 6 );
    groupBox3->layout()->setMargin( 11 );
    groupBox3Layout = new QGridLayout( groupBox3->layout() );
    groupBox3Layout->setAlignment( Qt::AlignTop );

    layout13 = new QGridLayout( 0, 1, 1, 0, 6, "layout13"); 

    textLabel2 = new QLabel( groupBox3, "textLabel2" );

    layout13->addWidget( textLabel2, 0, 0 );

    QLETelefonoParticular = new QLineEdit( groupBox3, "QLETelefonoParticular" );

    layout13->addWidget( QLETelefonoParticular, 1, 0 );

    groupBox3Layout->addLayout( layout13, 0, 0 );

    layout13_2 = new QGridLayout( 0, 1, 1, 0, 6, "layout13_2"); 

    textLabel2_2 = new QLabel( groupBox3, "textLabel2_2" );

    layout13_2->addWidget( textLabel2_2, 0, 0 );

    QLETelefonoCelular = new QLineEdit( groupBox3, "QLETelefonoCelular" );

    layout13_2->addWidget( QLETelefonoCelular, 1, 0 );

    groupBox3Layout->addLayout( layout13_2, 0, 1 );

    layout13_3 = new QGridLayout( 0, 1, 1, 0, 6, "layout13_3"); 

    textLabel2_3 = new QLabel( groupBox3, "textLabel2_3" );

    layout13_3->addWidget( textLabel2_3, 0, 0 );

    QLETelefonoRecados = new QLineEdit( groupBox3, "QLETelefonoRecados" );

    layout13_3->addWidget( QLETelefonoRecados, 1, 0 );

    groupBox3Layout->addLayout( layout13_3, 0, 2 );

    CapturaDatosComunicacionLayout->addWidget( groupBox3, 0, 0 );

    layout37 = new QVBoxLayout( 0, 0, 6, "layout37"); 

    textLabel2_6_2 = new QLabel( this, "textLabel2_6_2" );
    layout37->addWidget( textLabel2_6_2 );

    QLECorreo = new QLineEdit( this, "QLECorreo" );
    layout37->addWidget( QLECorreo );

    CapturaDatosComunicacionLayout->addLayout( layout37, 1, 0 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );
    layout6->addWidget( QPBRegistrar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setAutoDefault( FALSE );
    layout6->addWidget( QPBActualizar );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout6->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout6->addWidget( QPBCancelar );

    CapturaDatosComunicacionLayout->addLayout( layout6, 2, 0 );
    languageChange();
    resize( QSize(705, 197).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDatosComunicacion::~CapturaDatosComunicacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDatosComunicacion::languageChange()
{
    setCaption( tr( "Datos De Comunicacion" ) );
    groupBox3->setTitle( tr( "Telefonos de Contacto" ) );
    textLabel2->setText( tr( "Particular (Con LADA)" ) );
    QLETelefonoParticular->setText( QString::null );
    textLabel2_2->setText( tr( "Celular" ) );
    QLETelefonoCelular->setText( QString::null );
    textLabel2_3->setText( tr( "Para Dejar Recado" ) );
    QLETelefonoRecados->setText( QString::null );
    textLabel2_6_2->setText( tr( "Correo Electronico" ) );
    QLECorreo->setText( QString::null );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

