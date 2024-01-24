/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistraCostoCurso.ui'
**
** Created: Thu Dec 21 12:53:43 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistraCostoCurso.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <QCtrlExplicacionPromocion.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlExplicacionPromocion.h"

/*
 *  Constructs a RegistraCostoCurso as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RegistraCostoCurso::RegistraCostoCurso( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RegistraCostoCurso" );
    RegistraCostoCursoLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistraCostoCursoLayout"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel1 );

    QLEProgramacion = new QLineEdit( this, "QLEProgramacion" );
    QLEProgramacion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEProgramacion->sizePolicy().hasHeightForWidth() ) );
    QLEProgramacion->setReadOnly( TRUE );
    layout2->addWidget( QLEProgramacion );

    RegistraCostoCursoLayout->addLayout( layout2, 0, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout6->addWidget( textLabel2 );

    QTCCurso = new QTable( this, "QTCCurso" );
    QTCCurso->setNumCols( QTCCurso->numCols() + 1 );
    QTCCurso->horizontalHeader()->setLabel( QTCCurso->numCols() - 1, tr( "Descripcion Costo" ) );
    QTCCurso->setNumCols( QTCCurso->numCols() + 1 );
    QTCCurso->horizontalHeader()->setLabel( QTCCurso->numCols() - 1, tr( "Costo" ) );
    QTCCurso->setNumRows( 0 );
    QTCCurso->setNumCols( 2 );
    layout6->addWidget( QTCCurso );

    RegistraCostoCursoLayout->addMultiCellLayout( layout6, 1, 1, 0, 3 );

    layout2_2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2_2->addWidget( textLabel1_2_2 );

    QLECosto = new QLineEdit( this, "QLECosto" );
    QLECosto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECosto->sizePolicy().hasHeightForWidth() ) );
    QLECosto->setReadOnly( FALSE );
    layout2_2_2->addWidget( QLECosto );

    RegistraCostoCursoLayout->addLayout( layout2_2_2, 0, 3 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout2_2->addWidget( textLabel1_2 );

    QLECurso = new QLineEdit( this, "QLECurso" );
    QLECurso->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLECurso->sizePolicy().hasHeightForWidth() ) );
    QLECurso->setReadOnly( TRUE );
    layout2_2->addWidget( QLECurso );

    RegistraCostoCursoLayout->addLayout( layout2_2, 0, 1 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout7->addWidget( textLabel1_3 );

    QCtrExPromocion = new QCtrlExplicacionPromocion( this, "QCtrExPromocion" );
    layout7->addWidget( QCtrExPromocion );

    RegistraCostoCursoLayout->addLayout( layout7, 0, 2 );

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    QPBAnexar->setAutoDefault( FALSE );
    layout8->addWidget( QPBAnexar );

    QPBRegPrecios = new QPushButton( this, "QPBRegPrecios" );
    QPBRegPrecios->setEnabled( TRUE );
    QPBRegPrecios->setAutoDefault( FALSE );
    layout8->addWidget( QPBRegPrecios );

    QPBTerminar = new QPushButton( this, "QPBTerminar" );
    QPBTerminar->setAutoDefault( FALSE );
    layout8->addWidget( QPBTerminar );

    RegistraCostoCursoLayout->addMultiCellLayout( layout8, 2, 2, 0, 3 );
    languageChange();
    resize( QSize(935, 549).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistraCostoCurso::~RegistraCostoCurso()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistraCostoCurso::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Programacion" ) );
    textLabel2->setText( tr( "Costos Curso" ) );
    QTCCurso->horizontalHeader()->setLabel( 0, tr( "Descripcion Costo" ) );
    QTCCurso->horizontalHeader()->setLabel( 1, tr( "Costo" ) );
    textLabel1_2_2->setText( tr( "Costo" ) );
    textLabel1_2->setText( tr( "Curso" ) );
    textLabel1_3->setText( tr( "Explicacion Promocion" ) );
    QPBAnexar->setText( tr( "Anexar Costo" ) );
    QPBRegPrecios->setText( tr( "Registrar Precios" ) );
    QPBTerminar->setText( tr( "Terminar" ) );
}

