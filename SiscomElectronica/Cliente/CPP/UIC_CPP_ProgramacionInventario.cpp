/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProgramacionInventario.ui'
**
** Created: Fri Apr 12 21:26:01 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProgramacionInventario.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlMotivoInventario.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlMotivoInventario.h"

/*
 *  Constructs a ProgramacionInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ProgramacionInventario::ProgramacionInventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ProgramacionInventario" );
    ProgramacionInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "ProgramacionInventarioLayout"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout6->addWidget( textLabel1_2 );

    QCtrMotivoInventario = new QCtrlMotivoInventario( this, "QCtrMotivoInventario" );
    layout6->addWidget( QCtrMotivoInventario );

    ProgramacionInventarioLayout->addLayout( layout6, 0, 0 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout8->addWidget( textLabel2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout8->addWidget( QTEDescripcion );

    ProgramacionInventarioLayout->addLayout( layout8, 1, 0 );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    layout10->addWidget( QPBRegistra );

    QPBTerminaInventario = new QPushButton( this, "QPBTerminaInventario" );
    layout10->addWidget( QPBTerminaInventario );

    ProgramacionInventarioLayout->addLayout( layout10, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProgramacionInventario::~ProgramacionInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProgramacionInventario::languageChange()
{
    setCaption( tr( "Programacion Inventario" ) );
    textLabel1_2->setText( tr( "Motivo Inventario" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    QPBRegistra->setText( tr( "Registra" ) );
    QPBTerminaInventario->setText( tr( "Termina Inventario" ) );
}

