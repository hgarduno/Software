/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaCamiones.ui'
**
** Created: Sat Jan 27 16:37:26 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaCamiones.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaCamiones as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CapturaCamiones::CapturaCamiones( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CapturaCamiones" );
    CapturaCamionesLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaCamionesLayout"); 

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    frame33 = new QFrame( this, "frame33" );
    frame33->setFrameShape( QFrame::StyledPanel );
    frame33->setFrameShadow( QFrame::Raised );
    frame33Layout = new QGridLayout( frame33, 1, 1, 11, 6, "frame33Layout"); 

    layout392 = new QHBoxLayout( 0, 0, 6, "layout392"); 

    layout386 = new QVBoxLayout( 0, 0, 6, "layout386"); 

    textLabel22 = new QLabel( frame33, "textLabel22" );
    layout386->addWidget( textLabel22 );

    QLEClaveCamion = new QLineEdit( frame33, "QLEClaveCamion" );
    QLEClaveCamion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEClaveCamion->sizePolicy().hasHeightForWidth() ) );
    layout386->addWidget( QLEClaveCamion );
    layout392->addLayout( layout386 );

    layout387 = new QVBoxLayout( 0, 0, 6, "layout387"); 

    textLabel23 = new QLabel( frame33, "textLabel23" );
    layout387->addWidget( textLabel23 );

    QLENombre = new QLineEdit( frame33, "QLENombre" );
    layout387->addWidget( QLENombre );
    layout392->addLayout( layout387 );

    QCBActivo = new QCheckBox( frame33, "QCBActivo" );
    layout392->addWidget( QCBActivo );

    frame33Layout->addLayout( layout392, 0, 0 );

    layout393 = new QHBoxLayout( 0, 0, 6, "layout393"); 

    layout388 = new QVBoxLayout( 0, 0, 6, "layout388"); 

    textLabel24 = new QLabel( frame33, "textLabel24" );
    layout388->addWidget( textLabel24 );

    QLEMarca = new QLineEdit( frame33, "QLEMarca" );
    layout388->addWidget( QLEMarca );
    layout393->addLayout( layout388 );

    layout389 = new QVBoxLayout( 0, 0, 6, "layout389"); 

    textLabel25 = new QLabel( frame33, "textLabel25" );
    layout389->addWidget( textLabel25 );

    QLETipo = new QLineEdit( frame33, "QLETipo" );
    layout389->addWidget( QLETipo );
    layout393->addLayout( layout389 );

    layout390 = new QVBoxLayout( 0, 0, 6, "layout390"); 

    textLabel26 = new QLabel( frame33, "textLabel26" );
    layout390->addWidget( textLabel26 );

    QLEModelo = new QLineEdit( frame33, "QLEModelo" );
    layout390->addWidget( QLEModelo );
    layout393->addLayout( layout390 );

    layout391 = new QVBoxLayout( 0, 0, 6, "layout391"); 

    textLabel27 = new QLabel( frame33, "textLabel27" );
    layout391->addWidget( textLabel27 );

    QLEPlacas = new QLineEdit( frame33, "QLEPlacas" );
    layout391->addWidget( QLEPlacas );
    layout393->addLayout( layout391 );

    frame33Layout->addLayout( layout393, 1, 0 );
    layout44->addWidget( frame33 );

    layout43 = new QHBoxLayout( 0, 0, 6, "layout43"); 

    QPBCrear = new QPushButton( this, "QPBCrear" );
    layout43->addWidget( QPBCrear );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout43->addWidget( QPBCancelar );

    pushButton11 = new QPushButton( this, "pushButton11" );
    layout43->addWidget( pushButton11 );

    pushButton61 = new QPushButton( this, "pushButton61" );
    layout43->addWidget( pushButton61 );
    layout44->addLayout( layout43 );

    CapturaCamionesLayout->addLayout( layout44, 0, 0 );
    languageChange();
    resize( QSize(523, 173).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaCamiones::~CapturaCamiones()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaCamiones::languageChange()
{
    setCaption( tr( "Captura de Camiones" ) );
    textLabel22->setText( trUtf8( "\x43\x61\x6d\x69\xc3\xb3\x6e\x3a" ) );
    textLabel23->setText( tr( "Nombre:" ) );
    QCBActivo->setText( tr( "Activo" ) );
    textLabel24->setText( tr( "Marca:" ) );
    textLabel25->setText( tr( "Tipo:" ) );
    textLabel26->setText( tr( "Modelo:" ) );
    textLabel27->setText( tr( "Placas:" ) );
    QPBCrear->setText( tr( "Crear" ) );
    QPBCancelar->setText( tr( "Consultar" ) );
    pushButton11->setText( tr( "Actualizar" ) );
    pushButton61->setText( tr( "Cancelar" ) );
}

