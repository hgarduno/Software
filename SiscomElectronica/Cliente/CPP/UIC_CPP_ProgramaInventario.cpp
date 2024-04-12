/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProgramaInventario.ui'
**
** Created: Thu Apr 11 21:53:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProgramaInventario.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtable.h>
#include <IMP_QControlFecha.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "IMP_QControlFecha.h"

/*
 *  Constructs a ProgramaInventario as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ProgramaInventario::ProgramaInventario( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ProgramaInventario" );
    ProgramaInventarioLayout = new QGridLayout( this, 1, 1, 11, 6, "ProgramaInventarioLayout"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout5->addWidget( textLabel1 );

    comboBox3 = new QComboBox( FALSE, this, "comboBox3" );
    comboBox3->setEditable( TRUE );
    comboBox3->setInsertionPolicy( QComboBox::NoInsertion );
    comboBox3->setAutoCompletion( TRUE );
    comboBox3->setDuplicatesEnabled( FALSE );
    layout5->addWidget( comboBox3 );

    ProgramaInventarioLayout->addLayout( layout5, 0, 0 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Fecha" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Empleado" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Estado Registro" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 3 );

    ProgramaInventarioLayout->addWidget( table1, 5, 0 );

    textLabel1_2 = new QLabel( this, "textLabel1_2" );

    ProgramaInventarioLayout->addWidget( textLabel1_2, 4, 0 );

    layout5_2 = new QHBoxLayout( 0, 0, 6, "layout5_2"); 

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    controlFechaDesarrollo21 = new CQControlFecha( this, "controlFechaDesarrollo21" );
    layout3->addWidget( controlFechaDesarrollo21 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout3->addItem( spacer1 );
    layout4->addLayout( layout3 );
    layout5_2->addLayout( layout4 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout5_2->addItem( spacer2 );

    ProgramaInventarioLayout->addLayout( layout5_2, 3, 0 );

    textLabel2_2 = new QLabel( this, "textLabel2_2" );

    ProgramaInventarioLayout->addWidget( textLabel2_2, 1, 0 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout10->addWidget( textLabel1_3 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    layout10->addWidget( lineEdit1 );
    layout16->addLayout( layout10 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout15->addWidget( textLabel3 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    controlFechaDesarrollo21_2 = new CQControlFecha( this, "controlFechaDesarrollo21_2" );
    layout14->addWidget( controlFechaDesarrollo21_2 );
    spacer5 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout14->addItem( spacer5 );
    layout15->addLayout( layout14 );
    layout16->addLayout( layout15 );

    ProgramaInventarioLayout->addLayout( layout16, 2, 0 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    pushButton1_2 = new QPushButton( this, "pushButton1_2" );
    layout17->addWidget( pushButton1_2 );

    pushButton1_3 = new QPushButton( this, "pushButton1_3" );
    layout17->addWidget( pushButton1_3 );

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout17->addWidget( pushButton1 );

    ProgramaInventarioLayout->addLayout( layout17, 6, 0 );
    languageChange();
    resize( QSize(634, 645).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProgramaInventario::~ProgramaInventario()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProgramaInventario::languageChange()
{
    setCaption( tr( "Programacion Inventario" ) );
    textLabel1->setText( tr( "Empleado" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Fecha" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Empleado" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "Estado Registro" ) );
    textLabel1_2->setText( tr( "Inventarios Programados" ) );
    textLabel2->setText( tr( "Fecha De Inventario" ) );
    textLabel2_2->setText( tr( "Ultimo Inventario" ) );
    textLabel1_3->setText( tr( "Empleado" ) );
    textLabel3->setText( tr( "Fecha" ) );
    pushButton1_2->setText( tr( "Expendio" ) );
    pushButton1_3->setText( tr( "Productos Al Empleado" ) );
    pushButton1->setText( tr( "Registrar" ) );
}

