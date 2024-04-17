/****************************************************************************
** Form implementation generated from reading ui file 'UI/CorteCajaSucursal.ui'
**
** Created: Fri Apr 12 21:26:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CorteCajaSucursal.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QtCorteCajaImp.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QtCorteCajaImp.h"

/*
 *  Constructs a CorteCajaSucursal as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CorteCajaSucursal::CorteCajaSucursal( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CorteCajaSucursal" );
    CorteCajaSucursalLayout = new QGridLayout( this, 1, 1, 11, 6, "CorteCajaSucursalLayout"); 

    textLabel1 = new QLabel( this, "textLabel1" );

    CorteCajaSucursalLayout->addWidget( textLabel1, 0, 0 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout1->addWidget( textLabel2 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    layout1->addWidget( lineEdit1 );

    CorteCajaSucursalLayout->addLayout( layout1, 2, 0 );

    layout2 = new QHBoxLayout( 0, 0, 6, "layout2"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout2->addWidget( pushButton1 );

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout2->addWidget( pushButton2 );

    pushButton3 = new QPushButton( this, "pushButton3" );
    layout2->addWidget( pushButton3 );

    CorteCajaSucursalLayout->addLayout( layout2, 3, 0 );

    QtCCaja = new QtCorteCajaImp( this, "QtCCaja" );
    QtCCaja->setNumRows( 0 );
    QtCCaja->setNumCols( 0 );

    CorteCajaSucursalLayout->addWidget( QtCCaja, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CorteCajaSucursal::~CorteCajaSucursal()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CorteCajaSucursal::languageChange()
{
    setCaption( tr( "Corte Caja Sucursal" ) );
    textLabel1->setText( tr( "Corte Caja" ) );
    textLabel2->setText( tr( "Estatus Corte Caja" ) );
    pushButton1->setText( tr( "Registra Corte" ) );
    pushButton2->setText( tr( "pushButton2" ) );
    pushButton3->setText( tr( "pushButton3" ) );
}

