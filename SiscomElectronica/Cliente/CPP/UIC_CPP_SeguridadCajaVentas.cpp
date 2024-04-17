/****************************************************************************
** Form implementation generated from reading ui file 'UI/SeguridadCajaVentas.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SeguridadCajaVentas.h"

#include <qvariant.h>
#include <qheader.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a SeguridadCajaVentas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SeguridadCajaVentas::SeguridadCajaVentas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SeguridadCajaVentas" );
    SeguridadCajaVentasLayout = new QGridLayout( this, 1, 1, 11, 6, "SeguridadCajaVentasLayout"); 

    QLVCajas = new QListView( this, "QLVCajas" );
    QLVCajas->addColumn( tr( "Caja" ) );
    QLVCajas->setRootIsDecorated( TRUE );

    SeguridadCajaVentasLayout->addMultiCellWidget( QLVCajas, 0, 0, 0, 1 );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setMinimumSize( QSize( 0, 40 ) );

    SeguridadCajaVentasLayout->addWidget( QPBActualizar, 1, 0 );

    QPBRCambios = new QPushButton( this, "QPBRCambios" );
    QPBRCambios->setMinimumSize( QSize( 0, 40 ) );

    SeguridadCajaVentasLayout->addWidget( QPBRCambios, 1, 1 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SeguridadCajaVentas::~SeguridadCajaVentas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SeguridadCajaVentas::languageChange()
{
    setCaption( tr( "Seguridad Cajas Ventas" ) );
    QLVCajas->header()->setLabel( 0, tr( "Caja" ) );
    QPBActualizar->setText( tr( "Actualizar\n"
"Datos" ) );
    QPBRCambios->setText( tr( "Registrar\n"
"Cambios" ) );
}

