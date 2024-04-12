/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_ActualizaPantalla.ui'
**
** Created: Thu Apr 11 21:36:26 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaPantalla.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ActualizaPantalla as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActualizaPantalla::ActualizaPantalla( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActualizaPantalla" );
    ActualizaPantallaLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaPantallaLayout"); 

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout13_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout13_2_2_2"); 

    textLabel1_2_2_2 = new QLabel( this, "textLabel1_2_2_2" );
    layout13_2_2_2->addWidget( textLabel1_2_2_2 );

    lineEdit8_2_2_2 = new QLineEdit( this, "lineEdit8_2_2_2" );
    lineEdit8_2_2_2->setReadOnly( TRUE );
    layout13_2_2_2->addWidget( lineEdit8_2_2_2 );
    layout18->addLayout( layout13_2_2_2 );
    spacer4 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout18->addItem( spacer4 );

    ActualizaPantallaLayout->addLayout( layout18, 2, 0 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout13->addWidget( textLabel1 );

    QLENmbAplicacion = new QLineEdit( this, "QLENmbAplicacion" );
    QLENmbAplicacion->setReadOnly( TRUE );
    layout13->addWidget( QLENmbAplicacion );
    layout19->addLayout( layout13 );

    layout13_2 = new QVBoxLayout( 0, 0, 6, "layout13_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout13_2->addWidget( textLabel1_2 );

    QLEArchivoUI = new QLineEdit( this, "QLEArchivoUI" );
    QLEArchivoUI->setReadOnly( TRUE );
    layout13_2->addWidget( QLEArchivoUI );
    layout19->addLayout( layout13_2 );

    ActualizaPantallaLayout->addLayout( layout19, 0, 0 );

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    QPBSArchivo = new QPushButton( this, "QPBSArchivo" );
    layout20->addWidget( QPBSArchivo );

    QPBCopiaP_2_2 = new QPushButton( this, "QPBCopiaP_2_2" );
    layout20->addWidget( QPBCopiaP_2_2 );

    ActualizaPantallaLayout->addLayout( layout20, 3, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout13_2_2 = new QVBoxLayout( 0, 0, 6, "layout13_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout13_2_2->addWidget( textLabel1_2_2 );

    QLEClase = new QLineEdit( this, "QLEClase" );
    QLEClase->setReadOnly( TRUE );
    layout13_2_2->addWidget( QLEClase );
    layout22->addLayout( layout13_2_2 );

    layout13_2_2_3 = new QVBoxLayout( 0, 0, 6, "layout13_2_2_3"); 

    textLabel1_2_2_3 = new QLabel( this, "textLabel1_2_2_3" );
    layout13_2_2_3->addWidget( textLabel1_2_2_3 );

    QLEPantalla = new QLineEdit( this, "QLEPantalla" );
    QLEPantalla->setReadOnly( TRUE );
    layout13_2_2_3->addWidget( QLEPantalla );
    layout22->addLayout( layout13_2_2_3 );
    spacer3 = new QSpacerItem( 100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout22->addItem( spacer3 );

    ActualizaPantallaLayout->addLayout( layout22, 1, 0 );
    languageChange();
    resize( QSize(496, 218).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaPantalla::~ActualizaPantalla()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaPantalla::languageChange()
{
    setCaption( tr( "Actualiza Pantalla" ) );
    textLabel1_2_2_2->setText( tr( "Perfil" ) );
    textLabel1->setText( tr( "Aplicacion" ) );
    textLabel1_2->setText( tr( "Archivo" ) );
    QPBSArchivo->setText( tr( "Selecciona\n"
"Archivo UI" ) );
    QPBCopiaP_2_2->setText( tr( "Actualiza\n"
"En Base De Datos" ) );
    textLabel1_2_2->setText( tr( "Clase" ) );
    textLabel1_2_2_3->setText( tr( "Pantalla" ) );
}

