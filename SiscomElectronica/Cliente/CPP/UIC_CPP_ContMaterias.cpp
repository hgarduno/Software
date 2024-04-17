/****************************************************************************
** Form implementation generated from reading ui file 'UI/ContMaterias.ui'
**
** Created: Fri Apr 12 21:35:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ContMaterias.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ContMaterias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ContMaterias::ContMaterias( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ContMaterias" );
    ContMateriasLayout = new QGridLayout( this, 1, 1, 11, 6, "ContMateriasLayout"); 

    layout64 = new QVBoxLayout( 0, 0, 6, "layout64"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout64->addWidget( textLabel4 );

    QLEMateria = new QLineEdit( this, "QLEMateria" );
    layout64->addWidget( QLEMateria );

    ContMateriasLayout->addLayout( layout64, 0, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Materia" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 1 );
    QTDatos->setReadOnly( TRUE );

    ContMateriasLayout->addWidget( QTDatos, 1, 0 );

    layout69 = new QHBoxLayout( 0, 0, 6, "layout69"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    layout69->addWidget( QPBAnexar );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout69->addWidget( QPBRegistrar );

    QPBSelEscuela = new QPushButton( this, "QPBSelEscuela" );
    QPBSelEscuela->setAutoDefault( FALSE );
    layout69->addWidget( QPBSelEscuela );

    pushButton27_3 = new QPushButton( this, "pushButton27_3" );
    layout69->addWidget( pushButton27_3 );

    ContMateriasLayout->addLayout( layout69, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ContMaterias::~ContMaterias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ContMaterias::languageChange()
{
    setCaption( tr( "Controlador De Materias" ) );
    textLabel4->setText( tr( "Materia" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Materia" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBSelEscuela->setText( tr( "Seleccionar Materia" ) );
    pushButton27_3->setText( tr( "Eliminar" ) );
}

