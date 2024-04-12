/****************************************************************************
** Form implementation generated from reading ui file 'UI/MaterialPractica.ui'
**
** Created: Thu Apr 11 21:52:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_MaterialPractica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a MaterialPractica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
MaterialPractica::MaterialPractica( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "MaterialPractica" );
    MaterialPracticaLayout = new QGridLayout( this, 1, 1, 11, 6, "MaterialPracticaLayout"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Estdo Registro" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );

    MaterialPracticaLayout->addMultiCellWidget( QTDatos, 1, 1, 0, 2 );

    layout64 = new QVBoxLayout( 0, 0, 6, "layout64"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout64->addWidget( textLabel4 );

    QLEEscuela = new QLineEdit( this, "QLEEscuela" );
    QLEEscuela->setReadOnly( TRUE );
    layout64->addWidget( QLEEscuela );

    MaterialPracticaLayout->addLayout( layout64, 0, 0 );

    layout64_2 = new QVBoxLayout( 0, 0, 6, "layout64_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout64_2->addWidget( textLabel4_2 );

    QLEMateria = new QLineEdit( this, "QLEMateria" );
    QLEMateria->setReadOnly( TRUE );
    layout64_2->addWidget( QLEMateria );

    MaterialPracticaLayout->addLayout( layout64_2, 0, 1 );

    layout64_2_2 = new QVBoxLayout( 0, 0, 6, "layout64_2_2"); 

    textLabel4_2_2 = new QLabel( this, "textLabel4_2_2" );
    layout64_2_2->addWidget( textLabel4_2_2 );

    QLEPractica = new QLineEdit( this, "QLEPractica" );
    QLEPractica->setReadOnly( TRUE );
    layout64_2_2->addWidget( QLEPractica );

    MaterialPracticaLayout->addLayout( layout64_2_2, 0, 2 );

    layout78 = new QHBoxLayout( 0, 0, 6, "layout78"); 

    layout76 = new QVBoxLayout( 0, 0, 6, "layout76"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setAutoDefault( FALSE );
    layout76->addWidget( QPBAnexar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setAutoDefault( FALSE );
    layout76->addWidget( QPBEliminar );
    layout78->addLayout( layout76 );

    layout77 = new QVBoxLayout( 0, 0, 6, "layout77"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );
    layout77->addWidget( QPBRegistrar );

    pushButton27_3 = new QPushButton( this, "pushButton27_3" );
    pushButton27_3->setAutoDefault( FALSE );
    layout77->addWidget( pushButton27_3 );
    layout78->addLayout( layout77 );

    QLCDNTotal = new QLCDNumber( this, "QLCDNTotal" );
    QLCDNTotal->setNumDigits( 7 );
    layout78->addWidget( QLCDNTotal );

    MaterialPracticaLayout->addMultiCellLayout( layout78, 2, 2, 0, 2 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MaterialPractica::~MaterialPractica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MaterialPractica::languageChange()
{
    setCaption( tr( "Controlador De Escuelas" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Estdo Registro" ) );
    textLabel4->setText( tr( "Escuela" ) );
    textLabel4_2->setText( tr( "Materia" ) );
    textLabel4_2_2->setText( tr( "Practica" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBEliminar->setText( tr( "Eliminar Producto" ) );
    QPBRegistrar->setText( tr( "Registrar Practica" ) );
    pushButton27_3->setText( tr( "Eliminar Practica" ) );
}

