/****************************************************************************
** Form implementation generated from reading ui file 'UI/CotizacionImportacionCierre.ui'
**
** Created: lun abr 1 18:57:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CotizacionImportacionCierre.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CotizacionImportacionCierre as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CotizacionImportacionCierre::CotizacionImportacionCierre( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CotizacionImportacionCierre" );
    CotizacionImportacionCierreLayout = new QGridLayout( this, 1, 1, 11, 6, "CotizacionImportacionCierreLayout"); 

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    QPBCerrar = new QPushButton( this, "QPBCerrar" );
    QPBCerrar->setMinimumSize( QSize( 0, 50 ) );
    layout36->addWidget( QPBCerrar );

    QPBOtraCotizacion = new QPushButton( this, "QPBOtraCotizacion" );
    QPBOtraCotizacion->setMinimumSize( QSize( 0, 50 ) );
    layout36->addWidget( QPBOtraCotizacion );

    QPBRegistrarCotizacion = new QPushButton( this, "QPBRegistrarCotizacion" );
    QPBRegistrarCotizacion->setMinimumSize( QSize( 0, 50 ) );
    layout36->addWidget( QPBRegistrarCotizacion );

    CotizacionImportacionCierreLayout->addLayout( layout36, 0, 0 );
    languageChange();
    resize( QSize(384, 74).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CotizacionImportacionCierre::~CotizacionImportacionCierre()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CotizacionImportacionCierre::languageChange()
{
    setCaption( tr( "Cerrando Cotizacion" ) );
    QPBCerrar->setText( tr( "Cerrar Cotizaciones \n"
"Importacion" ) );
    QPBOtraCotizacion->setText( tr( "Seleccionar Otra\n"
"Cotizacion" ) );
    QPBRegistrarCotizacion->setText( tr( "Registrar Otra\n"
"Cotizacion" ) );
}

