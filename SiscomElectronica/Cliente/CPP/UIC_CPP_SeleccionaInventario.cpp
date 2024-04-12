/****************************************************************************
** Form implementation generated from reading ui file 'UI/SeleccionaInventario.ui'
**
** Created: Thu Apr 11 21:39:55 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SeleccionaInventario.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a SeleccionaInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SeleccionaInventario::SeleccionaInventario( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SeleccionaInventario" );
    SeleccionaInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "SeleccionaInventarioLayout"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout11->addWidget( textLabel4 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Inventario" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha Inicio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha Fin" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout11->addWidget( QTDatos );

    SeleccionaInventarioLayout->addLayout( layout11, 0, 0 );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    pushButton5 = new QPushButton( this, "pushButton5" );
    layout13->addWidget( pushButton5 );

    pushButton5_2 = new QPushButton( this, "pushButton5_2" );
    layout13->addWidget( pushButton5_2 );

    SeleccionaInventarioLayout->addLayout( layout13, 1, 0 );
    languageChange();
    resize( QSize(600, 195).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SeleccionaInventario::~SeleccionaInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SeleccionaInventario::languageChange()
{
    setCaption( tr( "Selecciona Inventario" ) );
    textLabel4->setText( tr( "Inventarios" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Inventario" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Fecha Inicio" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Fecha Fin" ) );
    pushButton5->setText( tr( "pushButton5" ) );
    pushButton5_2->setText( tr( "pushButton5" ) );
}

