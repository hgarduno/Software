/****************************************************************************
** Form implementation generated from reading ui file 'UI/AccionTraspasoBodegaExp.ui'
**
** Created: Wed Apr 10 20:52:38 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_AccionTraspasoBodegaExp.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a AccionTraspasoBodegaExp as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
AccionTraspasoBodegaExp::AccionTraspasoBodegaExp( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "AccionTraspasoBodegaExp" );
    AccionTraspasoBodegaExpLayout = new QGridLayout( this, 1, 1, 11, 6, "AccionTraspasoBodegaExpLayout"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLECveProducto = new QLineEdit( this, "QLECveProducto" );
    layout1->addWidget( QLECveProducto );

    AccionTraspasoBodegaExpLayout->addLayout( layout1, 0, 0 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QLEExistenciaE = new QLineEdit( this, "QLEExistenciaE" );
    layout2->addWidget( QLEExistenciaE );

    AccionTraspasoBodegaExpLayout->addLayout( layout2, 0, 1 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout2_2->addWidget( textLabel2_2 );

    QLEExistenciaB = new QLineEdit( this, "QLEExistenciaB" );
    layout2_2->addWidget( QLEExistenciaB );

    AccionTraspasoBodegaExpLayout->addLayout( layout2_2, 0, 2 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    QPBPasarEB = new QPushButton( this, "QPBPasarEB" );
    QPBPasarEB->setMinimumSize( QSize( 0, 40 ) );
    QPBPasarEB->setAutoRepeat( FALSE );
    QPBPasarEB->setAutoDefault( FALSE );
    layout4->addWidget( QPBPasarEB );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setMinimumSize( QSize( 0, 40 ) );
    QPBCancelar->setAutoRepeat( FALSE );
    QPBCancelar->setAutoDefault( FALSE );
    layout4->addWidget( QPBCancelar );

    AccionTraspasoBodegaExpLayout->addMultiCellLayout( layout4, 2, 2, 0, 2 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout5->addWidget( textLabel3 );

    QTEError = new QTextEdit( this, "QTEError" );
    layout5->addWidget( QTEError );

    AccionTraspasoBodegaExpLayout->addMultiCellLayout( layout5, 1, 1, 0, 2 );
    languageChange();
    resize( QSize(342, 239).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
AccionTraspasoBodegaExp::~AccionTraspasoBodegaExp()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void AccionTraspasoBodegaExp::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Producto" ) );
    textLabel2->setText( tr( "Existencia Expendio" ) );
    textLabel2_2->setText( tr( "Existencia Bodega" ) );
    QPBPasarEB->setText( tr( "Pasar A Expendio\n"
"Lo de la Bodega" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel3->setText( tr( "Error" ) );
}

