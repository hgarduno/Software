/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaCentroTrabajo.ui'
**
** Created: Sat Jan 27 16:38:02 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaCentroTrabajo.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaCentroTrabajo as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaCentroTrabajo::CapturaCentroTrabajo( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaCentroTrabajo" );
    CapturaCentroTrabajoLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaCentroTrabajoLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLECentroTrabajo = new QLineEdit( this, "QLECentroTrabajo" );
    layout1_2->addWidget( QLECentroTrabajo );
    layout4->addLayout( layout1_2 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLEClavePresupuestal = new QLineEdit( this, "QLEClavePresupuestal" );
    layout1->addWidget( QLEClavePresupuestal );
    layout4->addLayout( layout1 );

    CapturaCentroTrabajoLayout->addMultiCellLayout( layout4, 0, 0, 0, 3 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );

    CapturaCentroTrabajoLayout->addWidget( QPBRegistrar, 1, 0 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );

    CapturaCentroTrabajoLayout->addWidget( QPBCancelar, 1, 3 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );

    CapturaCentroTrabajoLayout->addWidget( QPBAceptar, 1, 1 );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( FALSE );
    QPBActualizar->setAutoDefault( FALSE );

    CapturaCentroTrabajoLayout->addWidget( QPBActualizar, 1, 2 );
    languageChange();
    resize( QSize(543, 93).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaCentroTrabajo::~CapturaCentroTrabajo()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaCentroTrabajo::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_2->setText( tr( "Centro de Trabajo" ) );
    textLabel1->setText( tr( "Clave Presupuestal" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
}

