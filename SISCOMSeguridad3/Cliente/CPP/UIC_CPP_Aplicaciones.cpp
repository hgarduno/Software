/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_Aplicaciones.ui'
**
** Created: Sat Jan 27 16:42:23 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Aplicaciones.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Aplicaciones as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Aplicaciones::Aplicaciones( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Aplicaciones" );
    AplicacionesLayout = new QGridLayout( this, 1, 1, 11, 6, "AplicacionesLayout"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout23->addWidget( textLabel3 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout23->addWidget( QLENombre );

    AplicacionesLayout->addLayout( layout23, 0, 0 );

    QLERutaQQt = new QLineEdit( this, "QLERutaQQt" );

    AplicacionesLayout->addMultiCellWidget( QLERutaQQt, 3, 3, 0, 1 );

    layout23_2 = new QVBoxLayout( 0, 0, 6, "layout23_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout23_2->addWidget( textLabel3_2 );

    QLEIdentificador = new QLineEdit( this, "QLEIdentificador" );
    QLEIdentificador->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEIdentificador->sizePolicy().hasHeightForWidth() ) );
    QLEIdentificador->setReadOnly( TRUE );
    layout23_2->addWidget( QLEIdentificador );

    AplicacionesLayout->addLayout( layout23_2, 0, 1 );

    layout23_3 = new QVBoxLayout( 0, 0, 6, "layout23_3"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    layout23_3->addWidget( textLabel3_3 );

    QLEDescripcion = new QLineEdit( this, "QLEDescripcion" );
    layout23_3->addWidget( QLEDescripcion );

    AplicacionesLayout->addMultiCellLayout( layout23_3, 1, 1, 0, 1 );

    QPBSDirectorio = new QPushButton( this, "QPBSDirectorio" );
    QPBSDirectorio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, QPBSDirectorio->sizePolicy().hasHeightForWidth() ) );

    AplicacionesLayout->addMultiCellWidget( QPBSDirectorio, 2, 2, 0, 1 );

    layout26 = new QHBoxLayout( 0, 0, 6, "layout26"); 

    QPBRAplicacion = new QPushButton( this, "QPBRAplicacion" );
    layout26->addWidget( QPBRAplicacion );

    pushButton12_2 = new QPushButton( this, "pushButton12_2" );
    layout26->addWidget( pushButton12_2 );

    AplicacionesLayout->addMultiCellLayout( layout26, 4, 4, 0, 1 );
    languageChange();
    resize( QSize(347, 222).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Aplicaciones::~Aplicaciones()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Aplicaciones::languageChange()
{
    setCaption( tr( "Captura Aplicacion" ) );
    textLabel3->setText( tr( "Nombre" ) );
    textLabel3_2->setText( tr( "Identificador" ) );
    textLabel3_3->setText( tr( "Descripcion" ) );
    QPBSDirectorio->setText( tr( "Directorio De Los\n"
"Archivos UI" ) );
    QPBRAplicacion->setText( tr( "Registra Aplicacion" ) );
    pushButton12_2->setText( tr( "Elimina Aplicacion" ) );
}

