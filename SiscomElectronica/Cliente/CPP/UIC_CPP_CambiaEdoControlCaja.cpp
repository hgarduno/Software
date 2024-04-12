/****************************************************************************
** Form implementation generated from reading ui file 'UI/CambiaEdoControlCaja.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CambiaEdoControlCaja.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CambiaEdoControlCaja as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CambiaEdoControlCaja::CambiaEdoControlCaja( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CambiaEdoControlCaja" );
    CambiaEdoControlCajaLayout = new QGridLayout( this, 1, 1, 11, 6, "CambiaEdoControlCajaLayout"); 

    QGBEstados = new QButtonGroup( this, "QGBEstados" );
    QGBEstados->setColumnLayout(0, Qt::Vertical );
    QGBEstados->layout()->setSpacing( 6 );
    QGBEstados->layout()->setMargin( 11 );
    QGBEstadosLayout = new QGridLayout( QGBEstados->layout() );
    QGBEstadosLayout->setAlignment( Qt::AlignTop );

    QRBHabilitado = new QRadioButton( QGBEstados, "QRBHabilitado" );

    QGBEstadosLayout->addWidget( QRBHabilitado, 0, 0 );

    QRBDesHabilitado = new QRadioButton( QGBEstados, "QRBDesHabilitado" );

    QGBEstadosLayout->addWidget( QRBDesHabilitado, 1, 0 );

    CambiaEdoControlCajaLayout->addMultiCellWidget( QGBEstados, 0, 0, 0, 1 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );

    CambiaEdoControlCajaLayout->addWidget( QPBAceptar, 1, 0 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );

    CambiaEdoControlCajaLayout->addWidget( QPBCancelar, 1, 1 );
    languageChange();
    resize( QSize(272, 181).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CambiaEdoControlCaja::~CambiaEdoControlCaja()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CambiaEdoControlCaja::languageChange()
{
    setCaption( tr( "Estado Del Control" ) );
    QGBEstados->setTitle( tr( "buttonGroup1" ) );
    QRBHabilitado->setText( tr( "Habilitado" ) );
    QRBDesHabilitado->setText( tr( "Deshabilitado" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

