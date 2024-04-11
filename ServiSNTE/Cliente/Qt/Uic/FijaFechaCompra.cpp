/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/FijaFechaCompra.ui'
**
** Created: Thu Apr 11 21:07:28 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "FijaFechaCompra.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a FijaFechaCompra as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
FijaFechaCompra::FijaFechaCompra( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "FijaFechaCompra" );
    FijaFechaCompraLayout = new QGridLayout( this, 1, 1, 11, 6, "FijaFechaCompraLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout1->addWidget( QCtrProveedores );

    FijaFechaCompraLayout->addLayout( layout1, 0, 0 );

    layout39 = new QVBoxLayout( 0, 0, 6, "layout39"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout39->addWidget( textLabel3 );

    QLEFecha = new QLineEdit( this, "QLEFecha" );
    QLEFecha->setEnabled( FALSE );
    QLEFecha->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFecha->sizePolicy().hasHeightForWidth() ) );
    QLEFecha->setReadOnly( FALSE );
    layout39->addWidget( QLEFecha );

    FijaFechaCompraLayout->addLayout( layout39, 0, 1 );

    layout45 = new QHBoxLayout( 0, 0, 6, "layout45"); 

    QPBRegistraFecha = new QPushButton( this, "QPBRegistraFecha" );
    layout45->addWidget( QPBRegistraFecha );

    pushButton17 = new QPushButton( this, "pushButton17" );
    layout45->addWidget( pushButton17 );

    FijaFechaCompraLayout->addMultiCellLayout( layout45, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(639, 93).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FijaFechaCompra::~FijaFechaCompra()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FijaFechaCompra::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Proveedores" ) );
    textLabel3->setText( tr( "Fecha:" ) );
    QLEFecha->setInputMask( tr( "0000-00-00; " ) );
    QPBRegistraFecha->setText( tr( "Registra Fecha Compras" ) );
    pushButton17->setText( tr( "pushButton17" ) );
}

