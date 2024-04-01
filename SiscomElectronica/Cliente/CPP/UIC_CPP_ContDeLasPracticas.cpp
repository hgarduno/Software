/****************************************************************************
** Form implementation generated from reading ui file 'UI/ContDeLasPracticas.ui'
**
** Created: Wed Jan 31 10:58:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ContDeLasPracticas.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ContDeLasPracticas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ContDeLasPracticas::ContDeLasPracticas( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ContDeLasPracticas" );
    ContDeLasPracticasLayout = new QGridLayout( this, 1, 1, 11, 6, "ContDeLasPracticasLayout"); 

    layout64 = new QVBoxLayout( 0, 0, 6, "layout64"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout64->addWidget( textLabel4 );

    QLEPractica = new QLineEdit( this, "QLEPractica" );
    layout64->addWidget( QLEPractica );

    ContDeLasPracticasLayout->addLayout( layout64, 0, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Practica" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Estado Del Registro" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 2 );

    ContDeLasPracticasLayout->addWidget( QTDatos, 1, 0 );

    layout68 = new QHBoxLayout( 0, 0, 6, "layout68"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setAutoDefault( FALSE );
    layout68->addWidget( QPBAnexar );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );
    layout68->addWidget( QPBRegistrar );

    QPBSelEscuela = new QPushButton( this, "QPBSelEscuela" );
    QPBSelEscuela->setAutoDefault( FALSE );
    layout68->addWidget( QPBSelEscuela );

    pushButton27_3 = new QPushButton( this, "pushButton27_3" );
    pushButton27_3->setAutoDefault( FALSE );
    layout68->addWidget( pushButton27_3 );

    ContDeLasPracticasLayout->addLayout( layout68, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ContDeLasPracticas::~ContDeLasPracticas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ContDeLasPracticas::languageChange()
{
    setCaption( tr( "Controlador De Las Practicas" ) );
    textLabel4->setText( tr( "Nombre De La Practica" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Practica" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Estado Del Registro" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBSelEscuela->setText( tr( "Seleccionar Practica" ) );
    pushButton27_3->setText( tr( "Eliminar" ) );
}

