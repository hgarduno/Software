/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaRangoFechas.ui'
**
** Created: Thu Apr 11 21:05:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaRangoFechas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a CapturaRangoFechas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaRangoFechas::CapturaRangoFechas( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaRangoFechas" );
    CapturaRangoFechasLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaRangoFechasLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QSisContFechaIni = new CQControlFecha( this, "QSisContFechaIni" );
    layout1->addWidget( QSisContFechaIni );

    CapturaRangoFechasLayout->addMultiCellLayout( layout1, 0, 0, 0, 1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout2->addWidget( textLabel1_2 );

    QSisContFechaFin = new CQControlFecha( this, "QSisContFechaFin" );
    layout2->addWidget( QSisContFechaFin );

    CapturaRangoFechasLayout->addLayout( layout2, 0, 2 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );

    CapturaRangoFechasLayout->addWidget( QPBAceptar, 1, 0 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );

    CapturaRangoFechasLayout->addMultiCellWidget( QPBCancelar, 1, 1, 1, 2 );
    languageChange();
    resize( QSize(298, 103).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaRangoFechas::~CapturaRangoFechas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaRangoFechas::languageChange()
{
    setCaption( tr( "Rango De Fechas" ) );
    textLabel1->setText( tr( "Fecha Inicio" ) );
    textLabel1_2->setText( tr( "Fecha Fin" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

