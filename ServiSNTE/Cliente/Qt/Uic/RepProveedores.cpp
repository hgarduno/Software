/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RepProveedores.ui'
**
** Created: Sat Jan 27 16:38:39 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RepProveedores.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a RepProveedores as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RepProveedores::RepProveedores( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RepProveedores" );
    RepProveedoresLayout = new QGridLayout( this, 1, 1, 11, 6, "RepProveedoresLayout"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QCtrProveedores = new QCtrlProveedoresSS( this, "QCtrProveedores" );
    layout2->addWidget( QCtrProveedores );

    RepProveedoresLayout->addLayout( layout2, 0, 0 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    QPBConsultar = new QPushButton( this, "QPBConsultar" );
    layout3->addWidget( QPBConsultar );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout3->addWidget( QPBImprimir );

    RepProveedoresLayout->addLayout( layout3, 3, 0 );

    QTProveedores = new QTable( this, "QTProveedores" );
    QTProveedores->setNumCols( QTProveedores->numCols() + 1 );
    QTProveedores->horizontalHeader()->setLabel( QTProveedores->numCols() - 1, tr( "#Prov" ) );
    QTProveedores->setNumCols( QTProveedores->numCols() + 1 );
    QTProveedores->horizontalHeader()->setLabel( QTProveedores->numCols() - 1, tr( "Razon Social" ) );
    QTProveedores->setNumCols( QTProveedores->numCols() + 1 );
    QTProveedores->horizontalHeader()->setLabel( QTProveedores->numCols() - 1, tr( "Contacto" ) );
    QTProveedores->setNumCols( QTProveedores->numCols() + 1 );
    QTProveedores->horizontalHeader()->setLabel( QTProveedores->numCols() - 1, tr( "Telefono" ) );
    QTProveedores->setNumRows( 0 );
    QTProveedores->setNumCols( 4 );

    RepProveedoresLayout->addWidget( QTProveedores, 1, 0 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    textEdit1 = new QTextEdit( this, "textEdit1" );
    layout4->addWidget( textEdit1 );

    RepProveedoresLayout->addLayout( layout4, 2, 0 );
    languageChange();
    resize( QSize(606, 433).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RepProveedores::~RepProveedores()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RepProveedores::languageChange()
{
    setCaption( tr( "Reporte de proveedores" ) );
    textLabel1->setText( tr( "Proveedores" ) );
    QPBConsultar->setText( tr( "Consultar" ) );
    QPBImprimir->setText( tr( "Imprimir" ) );
    QTProveedores->horizontalHeader()->setLabel( 0, tr( "#Prov" ) );
    QTProveedores->horizontalHeader()->setLabel( 1, tr( "Razon Social" ) );
    QTProveedores->horizontalHeader()->setLabel( 2, tr( "Contacto" ) );
    QTProveedores->horizontalHeader()->setLabel( 3, tr( "Telefono" ) );
    textLabel2->setText( tr( "Proveedor" ) );
}

