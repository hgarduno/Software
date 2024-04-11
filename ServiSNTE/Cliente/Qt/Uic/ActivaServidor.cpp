/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ActivaServidor.ui'
**
** Created: Sat Jan 27 16:38:21 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ActivaServidor.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTiendasEntrega.h"

/*
 *  Constructs a ActivaServidor as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActivaServidor::ActivaServidor( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActivaServidor" );
    ActivaServidorLayout = new QGridLayout( this, 1, 1, 11, 6, "ActivaServidorLayout"); 

    textLabel1 = new QLabel( this, "textLabel1" );

    ActivaServidorLayout->addWidget( textLabel1, 0, 0 );

    QCtrTiendas = new QCtrlTiendasEntrega( this, "QCtrTiendas" );

    ActivaServidorLayout->addWidget( QCtrTiendas, 1, 0 );

    QTServidores = new QTable( this, "QTServidores" );
    QTServidores->setNumCols( QTServidores->numCols() + 1 );
    QTServidores->horizontalHeader()->setLabel( QTServidores->numCols() - 1, tr( "ID" ) );
    QTServidores->setNumCols( QTServidores->numCols() + 1 );
    QTServidores->horizontalHeader()->setLabel( QTServidores->numCols() - 1, tr( "Nombre" ) );
    QTServidores->setNumCols( QTServidores->numCols() + 1 );
    QTServidores->horizontalHeader()->setLabel( QTServidores->numCols() - 1, tr( "Abreviatura" ) );
    QTServidores->setNumCols( QTServidores->numCols() + 1 );
    QTServidores->horizontalHeader()->setLabel( QTServidores->numCols() - 1, tr( "Codigo" ) );
    QTServidores->setNumRows( 0 );
    QTServidores->setNumCols( 4 );

    ActivaServidorLayout->addWidget( QTServidores, 2, 0 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    layout14->addWidget( QPBConsulta );

    QPBCambiarConexionA = new QPushButton( this, "QPBCambiarConexionA" );
    QPBCambiarConexionA->setEnabled( FALSE );
    layout14->addWidget( QPBCambiarConexionA );

    ActivaServidorLayout->addLayout( layout14, 3, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActivaServidor::~ActivaServidor()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActivaServidor::languageChange()
{
    setCaption( tr( "Activa Servidor" ) );
    textLabel1->setText( tr( "Tienda" ) );
    QTServidores->horizontalHeader()->setLabel( 0, tr( "ID" ) );
    QTServidores->horizontalHeader()->setLabel( 1, tr( "Nombre" ) );
    QTServidores->horizontalHeader()->setLabel( 2, tr( "Abreviatura" ) );
    QTServidores->horizontalHeader()->setLabel( 3, tr( "Codigo" ) );
    QPBConsulta->setText( tr( "Consultar" ) );
    QPBCambiarConexionA->setText( tr( "Cambia Conexia A" ) );
}

