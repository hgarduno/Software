/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_ControladorSeguridad.ui'
**
** Created: Sat Jan 27 16:42:49 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ControladorSeguridad.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ControladorSeguridad as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ControladorSeguridad::ControladorSeguridad( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ControladorSeguridad" );
    ControladorSeguridadLayout = new QGridLayout( this, 1, 1, 11, 6, "ControladorSeguridadLayout"); 

    groupBox12 = new QGroupBox( this, "groupBox12" );
    groupBox12->setColumnLayout(0, Qt::Vertical );
    groupBox12->layout()->setSpacing( 6 );
    groupBox12->layout()->setMargin( 11 );
    groupBox12Layout = new QGridLayout( groupBox12->layout() );
    groupBox12Layout->setAlignment( Qt::AlignTop );

    layout17_2 = new QVBoxLayout( 0, 0, 6, "layout17_2"); 

    textLabel4_2 = new QLabel( groupBox12, "textLabel4_2" );
    layout17_2->addWidget( textLabel4_2 );

    QCBPerfiles = new QComboBox( FALSE, groupBox12, "QCBPerfiles" );
    layout17_2->addWidget( QCBPerfiles );

    groupBox12Layout->addLayout( layout17_2, 0, 0 );

    layout20_2 = new QVBoxLayout( 0, 0, 6, "layout20_2"); 

    textLabel6_2 = new QLabel( groupBox12, "textLabel6_2" );
    layout20_2->addWidget( textLabel6_2 );

    QLEDscPerfil = new QLineEdit( groupBox12, "QLEDscPerfil" );
    QLEDscPerfil->setEnabled( TRUE );
    QLEDscPerfil->setReadOnly( TRUE );
    layout20_2->addWidget( QLEDscPerfil );

    groupBox12Layout->addLayout( layout20_2, 1, 0 );

    ControladorSeguridadLayout->addWidget( groupBox12, 3, 0 );

    groupBox4_2 = new QGroupBox( this, "groupBox4_2" );
    groupBox4_2->setColumnLayout(0, Qt::Vertical );
    groupBox4_2->layout()->setSpacing( 6 );
    groupBox4_2->layout()->setMargin( 11 );
    groupBox4_2Layout = new QGridLayout( groupBox4_2->layout() );
    groupBox4_2Layout->setAlignment( Qt::AlignTop );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel4 = new QLabel( groupBox4_2, "textLabel4" );
    layout17->addWidget( textLabel4 );

    QCBPantallas = new QComboBox( FALSE, groupBox4_2, "QCBPantallas" );
    layout17->addWidget( QCBPantallas );
    layout18->addLayout( layout17 );
    spacer3 = new QSpacerItem( 40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout18->addItem( spacer3 );

    groupBox4_2Layout->addLayout( layout18, 0, 0 );

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    textLabel6 = new QLabel( groupBox4_2, "textLabel6" );
    layout20->addWidget( textLabel6 );

    QLEAPantalla = new QLineEdit( groupBox4_2, "QLEAPantalla" );
    QLEAPantalla->setReadOnly( TRUE );
    layout20->addWidget( QLEAPantalla );

    groupBox4_2Layout->addLayout( layout20, 2, 0 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel5 = new QLabel( groupBox4_2, "textLabel5" );
    layout19->addWidget( textLabel5 );

    QLEIdPantalla = new QLineEdit( groupBox4_2, "QLEIdPantalla" );
    QLEIdPantalla->setReadOnly( TRUE );
    layout19->addWidget( QLEIdPantalla );
    layout21->addLayout( layout19 );
    spacer4 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout21->addItem( spacer4 );

    groupBox4_2Layout->addLayout( layout21, 1, 0 );

    pushButton21 = new QPushButton( groupBox4_2, "pushButton21" );
    pushButton21->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, pushButton21->sizePolicy().hasHeightForWidth() ) );

    groupBox4_2Layout->addWidget( pushButton21, 3, 0 );

    ControladorSeguridadLayout->addWidget( groupBox4_2, 4, 0 );

    groupBox5 = new QGroupBox( this, "groupBox5" );
    groupBox5->setColumnLayout(0, Qt::Vertical );
    groupBox5->layout()->setSpacing( 6 );
    groupBox5->layout()->setMargin( 11 );
    groupBox5Layout = new QGridLayout( groupBox5->layout() );
    groupBox5Layout->setAlignment( Qt::AlignTop );

    QTDatosU = new QTable( groupBox5, "QTDatosU" );
    QTDatosU->setNumCols( QTDatosU->numCols() + 1 );
    QTDatosU->horizontalHeader()->setLabel( QTDatosU->numCols() - 1, tr( "Usuario" ) );
    QTDatosU->setNumCols( QTDatosU->numCols() + 1 );
    QTDatosU->horizontalHeader()->setLabel( QTDatosU->numCols() - 1, tr( "Firma" ) );
    QTDatosU->setNumRows( 0 );
    QTDatosU->setNumCols( 2 );

    groupBox5Layout->addWidget( QTDatosU, 1, 0 );

    ControladorSeguridadLayout->addWidget( groupBox5, 2, 0 );

    groupBox4 = new QGroupBox( this, "groupBox4" );
    groupBox4->setColumnLayout(0, Qt::Vertical );
    groupBox4->layout()->setSpacing( 6 );
    groupBox4->layout()->setMargin( 11 );
    groupBox4Layout = new QGridLayout( groupBox4->layout() );
    groupBox4Layout->setAlignment( Qt::AlignTop );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    textLabel7 = new QLabel( groupBox4, "textLabel7" );
    layout41->addWidget( textLabel7 );

    QLEDirIpSvr = new QLineEdit( groupBox4, "QLEDirIpSvr" );
    layout41->addWidget( QLEDirIpSvr );

    groupBox4Layout->addLayout( layout41, 0, 0 );

    layout41_2 = new QVBoxLayout( 0, 0, 6, "layout41_2"); 

    textLabel7_2 = new QLabel( groupBox4, "textLabel7_2" );
    layout41_2->addWidget( textLabel7_2 );

    QLEUsuario = new QLineEdit( groupBox4, "QLEUsuario" );
    layout41_2->addWidget( QLEUsuario );

    groupBox4Layout->addLayout( layout41_2, 1, 0 );

    layout41_2_2 = new QVBoxLayout( 0, 0, 6, "layout41_2_2"); 

    textLabel7_2_2 = new QLabel( groupBox4, "textLabel7_2_2" );
    layout41_2_2->addWidget( textLabel7_2_2 );

    QLEPtoCom = new QLineEdit( groupBox4, "QLEPtoCom" );
    layout41_2_2->addWidget( QLEPtoCom );

    groupBox4Layout->addLayout( layout41_2_2, 0, 1 );

    layout41_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout41_2_2_2"); 

    textLabel7_2_2_2 = new QLabel( groupBox4, "textLabel7_2_2_2" );
    layout41_2_2_2->addWidget( textLabel7_2_2_2 );

    QLEPassword = new QLineEdit( groupBox4, "QLEPassword" );
    QLEPassword->setEchoMode( QLineEdit::Password );
    layout41_2_2_2->addWidget( QLEPassword );

    groupBox4Layout->addLayout( layout41_2_2_2, 1, 1 );

    ControladorSeguridadLayout->addWidget( groupBox4, 1, 0 );

    groupBox2 = new QGroupBox( this, "groupBox2" );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    QPBCapAplicacion = new QPushButton( groupBox2, "QPBCapAplicacion" );
    layout10->addWidget( QPBCapAplicacion );

    QPBCarAplicacion = new QPushButton( groupBox2, "QPBCarAplicacion" );
    QPBCarAplicacion->setEnabled( FALSE );
    layout10->addWidget( QPBCarAplicacion );

    groupBox2Layout->addMultiCellLayout( layout10, 0, 0, 0, 1 );

    QPBIniCom = new QPushButton( groupBox2, "QPBIniCom" );

    groupBox2Layout->addWidget( QPBIniCom, 1, 1 );

    QPBCreaFirma = new QPushButton( groupBox2, "QPBCreaFirma" );

    groupBox2Layout->addWidget( QPBCreaFirma, 2, 1 );

    QPBRegAplicacion = new QPushButton( groupBox2, "QPBRegAplicacion" );
    QPBRegAplicacion->setEnabled( FALSE );

    groupBox2Layout->addWidget( QPBRegAplicacion, 1, 0 );

    QPBCreaPerfil = new QPushButton( groupBox2, "QPBCreaPerfil" );
    QPBCreaPerfil->setEnabled( TRUE );

    groupBox2Layout->addWidget( QPBCreaPerfil, 2, 0 );

    QPBUsuarios = new QPushButton( groupBox2, "QPBUsuarios" );
    QPBUsuarios->setEnabled( TRUE );

    groupBox2Layout->addWidget( QPBUsuarios, 3, 0 );

    QPBActualizaP = new QPushButton( groupBox2, "QPBActualizaP" );

    groupBox2Layout->addWidget( QPBActualizaP, 3, 1 );

    QPBActAplicacion = new QPushButton( groupBox2, "QPBActAplicacion" );

    groupBox2Layout->addWidget( QPBActAplicacion, 4, 0 );

    QPBCopiaP_3 = new QPushButton( groupBox2, "QPBCopiaP_3" );

    groupBox2Layout->addWidget( QPBCopiaP_3, 4, 1 );

    ControladorSeguridadLayout->addWidget( groupBox2, 0, 0 );
    languageChange();
    resize( QSize(313, 910).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ControladorSeguridad::~ControladorSeguridad()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ControladorSeguridad::languageChange()
{
    setCaption( tr( "Controlador De Seguridad" ) );
    groupBox12->setTitle( tr( "Perfiles" ) );
    textLabel4_2->setText( tr( "Perfil" ) );
    textLabel6_2->setText( tr( "Descripcion Perfil" ) );
    groupBox4_2->setTitle( tr( "Pantallas" ) );
    textLabel4->setText( tr( "Clase" ) );
    textLabel6->setText( tr( "Archivo UI" ) );
    textLabel5->setText( tr( "IdPantalla" ) );
    pushButton21->setText( tr( "Muestra \n"
"Pantalla" ) );
    groupBox5->setTitle( tr( "Usuarios De La Aplicacion" ) );
    QTDatosU->horizontalHeader()->setLabel( 0, tr( "Usuario" ) );
    QTDatosU->horizontalHeader()->setLabel( 1, tr( "Firma" ) );
    groupBox4->setTitle( tr( "Datos Servidor" ) );
    textLabel7->setText( tr( "Dir Ip Svr" ) );
    QLEDirIpSvr->setText( tr( "127.0.0.1" ) );
    textLabel7_2->setText( tr( "Usuario" ) );
    QLEUsuario->setText( tr( "hgarduno" ) );
    textLabel7_2_2->setText( tr( "Puerto Comunicaciones" ) );
    QLEPtoCom->setText( tr( "1645" ) );
    textLabel7_2_2_2->setText( tr( "Password" ) );
    QLEPassword->setText( tr( "hgarduno" ) );
    groupBox2->setTitle( tr( "Operaciones" ) );
    QPBCapAplicacion->setText( tr( "Captura Datos\n"
"De La  \n"
"Aplicacion" ) );
    QPBCarAplicacion->setText( tr( "Actualiza \n"
"Seguridad De La\n"
"Aplicacion" ) );
    QPBIniCom->setText( tr( "Inicia \n"
"Comunicaciones" ) );
    QPBCreaFirma->setText( tr( "Crear\n"
"Firmas" ) );
    QPBRegAplicacion->setText( tr( "Registra \n"
"Aplicacion" ) );
    QPBCreaPerfil->setText( tr( "Manejador De\n"
"Perfiles" ) );
    QPBUsuarios->setText( tr( "Manejador De \n"
"Usuarios" ) );
    QPBActualizaP->setText( tr( "Actualizar\n"
"Archivo UI" ) );
    QPBActAplicacion->setText( tr( "Actualiza\n"
"Controles" ) );
    QPBCopiaP_3->setText( tr( "Copia\n"
"Pantalla" ) );
}

