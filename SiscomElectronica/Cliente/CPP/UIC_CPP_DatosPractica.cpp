/****************************************************************************
** Form implementation generated from reading ui file 'UI/DatosPractica.ui'
**
** Created: Thu Dec 21 12:53:46 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DatosPractica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlMateriasSE.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlMateriasSE.h"

/*
 *  Constructs a DatosPractica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
DatosPractica::DatosPractica( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "DatosPractica" );
    DatosPracticaLayout = new QGridLayout( this, 1, 1, 11, 6, "DatosPracticaLayout"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel1_2 );

    QCtrMaterias = new QCtrlMateriasSE( this, "QCtrMaterias" );
    layout2->addWidget( QCtrMaterias );
    layout3->addLayout( layout2 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout10->addWidget( textLabel1 );

    lineEdit3 = new QLineEdit( this, "lineEdit3" );
    layout10->addWidget( lineEdit3 );
    layout3->addLayout( layout10 );

    DatosPracticaLayout->addMultiCellLayout( layout3, 0, 0, 0, 1 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    textEdit1 = new QTextEdit( this, "textEdit1" );
    layout4->addWidget( textEdit1 );

    DatosPracticaLayout->addMultiCellLayout( layout4, 1, 1, 0, 1 );

    pushButton5 = new QPushButton( this, "pushButton5" );

    DatosPracticaLayout->addWidget( pushButton5, 2, 0 );

    pushButton6 = new QPushButton( this, "pushButton6" );

    DatosPracticaLayout->addWidget( pushButton6, 2, 1 );
    languageChange();
    resize( QSize(457, 362).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DatosPractica::~DatosPractica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DatosPractica::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_2->setText( tr( "Materias" ) );
    textLabel1->setText( tr( "Profesor" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    pushButton5->setText( tr( "Registrar Practica" ) );
    pushButton6->setText( tr( "Cancelar" ) );
}

