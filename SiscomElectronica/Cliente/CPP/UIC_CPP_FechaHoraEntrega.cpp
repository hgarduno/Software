/****************************************************************************
** Form implementation generated from reading ui file 'UI/FechaHoraEntrega.ui'
**
** Created: Wed Jan 31 10:48:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_FechaHoraEntrega.h"

#include <qvariant.h>
#include <qlabel.h>
#include <QCtrlFechaHora.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFechaHora.h"

/*
 *  Constructs a FechaHoraEntrega as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FechaHoraEntrega::FechaHoraEntrega( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "FechaHoraEntrega" );
    FechaHoraEntregaLayout = new QGridLayout( this, 1, 1, 11, 6, "FechaHoraEntregaLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    ctrlFechaHora1 = new QCtrlFechaHora( this, "ctrlFechaHora1" );
    layout1->addWidget( ctrlFechaHora1 );

    FechaHoraEntregaLayout->addLayout( layout1, 0, 0 );

    layout2 = new QHBoxLayout( 0, 0, 6, "layout2"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout2->addWidget( pushButton1 );

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout2->addWidget( pushButton2 );

    FechaHoraEntregaLayout->addLayout( layout2, 1, 0 );
    languageChange();
    resize( QSize(210, 99).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FechaHoraEntrega::~FechaHoraEntrega()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FechaHoraEntrega::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Fecha Hora Entrega" ) );
    pushButton1->setText( tr( "Aceptar" ) );
    pushButton2->setText( tr( "Cancelar" ) );
}

