/****************************************************************************
** Form implementation generated from reading ui file 'UI/EmpleadosExpendio.ui'
**
** Created: Wed Jan 31 10:57:50 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_EmpleadosExpendio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a EmpleadosExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EmpleadosExpendio::EmpleadosExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "EmpleadosExpendio" );
    EmpleadosExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "EmpleadosExpendioLayout"); 

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout27->addWidget( textLabel3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Usuario" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Firma" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "IdEmpleado" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout27->addWidget( QTDatos );

    EmpleadosExpendioLayout->addLayout( layout27, 0, 0 );

    layout29 = new QVBoxLayout( 0, 0, 6, "layout29"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout29->addWidget( textLabel5 );

    QIVExpendios = new QIconView( this, "QIVExpendios" );
    layout29->addWidget( QIVExpendios );

    EmpleadosExpendioLayout->addLayout( layout29, 1, 0 );

    layout30 = new QHBoxLayout( 0, 0, 6, "layout30"); 

    QPBValEmpleado = new QPushButton( this, "QPBValEmpleado" );
    layout30->addWidget( QPBValEmpleado );

    QPBAsignaEmpleado = new QPushButton( this, "QPBAsignaEmpleado" );
    layout30->addWidget( QPBAsignaEmpleado );

    EmpleadosExpendioLayout->addLayout( layout30, 2, 0 );
    languageChange();
    resize( QSize(432, 524).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EmpleadosExpendio::~EmpleadosExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EmpleadosExpendio::languageChange()
{
    setCaption( tr( "Form3" ) );
    textLabel3->setText( tr( "Usuarios En Base De Seguridad" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Usuario" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Firma" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "IdEmpleado" ) );
    textLabel5->setText( tr( "Expendios" ) );
    QPBValEmpleado->setText( tr( "Valida Empleado" ) );
    QPBAsignaEmpleado->setText( tr( "Asigna Empleado Al Expendio" ) );
}

