/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenesDisponibles.ui'
**
** Created: lun abr 1 18:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenesDisponibles.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a OrdenesDisponibles as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
OrdenesDisponibles::OrdenesDisponibles( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "OrdenesDisponibles" );
    OrdenesDisponiblesLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenesDisponiblesLayout"); 

    layout1 = new QHBoxLayout( 0, 0, 6, "layout1"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout1->addWidget( QPBAceptar );

    pushButton2 = new QPushButton( this, "pushButton2" );
    pushButton2->setAutoDefault( FALSE );
    layout1->addWidget( pushButton2 );

    OrdenesDisponiblesLayout->addMultiCellLayout( layout1, 1, 1, 0, 1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Escuela" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Expendio" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout2->addWidget( QTDatos );

    OrdenesDisponiblesLayout->addLayout( layout2, 0, 0 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout2_2->addWidget( textLabel1_2 );

    QTDetalle = new QTable( this, "QTDetalle" );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Cantidad" ) );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Producto" ) );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Precio" ) );
    QTDetalle->setNumCols( QTDetalle->numCols() + 1 );
    QTDetalle->horizontalHeader()->setLabel( QTDetalle->numCols() - 1, tr( "Importe" ) );
    QTDetalle->setNumRows( 0 );
    QTDetalle->setNumCols( 4 );
    QTDetalle->setReadOnly( TRUE );
    layout2_2->addWidget( QTDetalle );

    OrdenesDisponiblesLayout->addLayout( layout2_2, 0, 1 );
    languageChange();
    resize( QSize(852, 518).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenesDisponibles::~OrdenesDisponibles()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenesDisponibles::languageChange()
{
    setCaption( tr( "Form1" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    pushButton2->setText( tr( "Cancelar" ) );
    textLabel1->setText( tr( "Ordenes" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Importe" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Escuela" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Expendio" ) );
    textLabel1_2->setText( tr( "Detalle Orden" ) );
    QTDetalle->horizontalHeader()->setLabel( 0, tr( "Cantidad" ) );
    QTDetalle->horizontalHeader()->setLabel( 1, tr( "Producto" ) );
    QTDetalle->horizontalHeader()->setLabel( 2, tr( "Precio" ) );
    QTDetalle->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
}

