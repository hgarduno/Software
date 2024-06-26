/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CargaBaseDeDatosMaestros.ui'
**
** Created: Thu Apr 11 21:07:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CargaBaseDeDatosMaestros.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CargaBaseDeDatosMaestros as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CargaBaseDeDatosMaestros::CargaBaseDeDatosMaestros( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CargaBaseDeDatosMaestros" );
    CargaBaseDeDatosMaestrosLayout = new QGridLayout( this, 1, 1, 11, 6, "CargaBaseDeDatosMaestrosLayout"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QLEArchivoNomina = new QLineEdit( this, "QLEArchivoNomina" );
    layout2->addWidget( QLEArchivoNomina );

    CargaBaseDeDatosMaestrosLayout->addLayout( layout2, 0, 0 );

    QPBSelArchivo = new QPushButton( this, "QPBSelArchivo" );

    CargaBaseDeDatosMaestrosLayout->addWidget( QPBSelArchivo, 1, 0 );
    languageChange();
    resize( QSize(495, 90).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CargaBaseDeDatosMaestros::~CargaBaseDeDatosMaestros()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CargaBaseDeDatosMaestros::languageChange()
{
    setCaption( tr( "Carga Base De Datos Maestros" ) );
    textLabel1->setText( tr( "Archivo" ) );
    QPBSelArchivo->setText( tr( "Selecciona Archivo" ) );
}

