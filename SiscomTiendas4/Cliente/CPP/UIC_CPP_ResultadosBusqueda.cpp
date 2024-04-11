/****************************************************************************
** Form implementation generated from reading ui file 'UI/ResultadosBusqueda.ui'
**
** Created: Thu Apr 11 20:30:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ResultadosBusqueda.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ResultadosBusqueda as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ResultadosBusqueda::ResultadosBusqueda( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ResultadosBusqueda" );
    ResultadosBusquedaLayout = new QGridLayout( this, 1, 1, 11, 6, "ResultadosBusquedaLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Clave" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Escala" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 6 );
    QTDatos->setReadOnly( TRUE );
    layout1->addWidget( QTDatos );

    ResultadosBusquedaLayout->addLayout( layout1, 0, 0 );

    pushButton1 = new QPushButton( this, "pushButton1" );

    ResultadosBusquedaLayout->addWidget( pushButton1, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ResultadosBusqueda::~ResultadosBusqueda()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ResultadosBusqueda::languageChange()
{
    setCaption( tr( "Resultados de busqueda" ) );
    textLabel1->setText( tr( "Productos" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Clave" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Existencia" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Escala" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Cantidad" ) );
    pushButton1->setText( tr( "Cancelar" ) );
}

