/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/PosicionesBeneficios.ui'
**
** Created: Thu Apr 11 21:07:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "PosicionesBeneficios.h"

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
 *  Constructs a PosicionesBeneficios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
PosicionesBeneficios::PosicionesBeneficios( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "PosicionesBeneficios" );
    PosicionesBeneficiosLayout = new QGridLayout( this, 1, 1, 11, 6, "PosicionesBeneficiosLayout"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout10->addWidget( textLabel1 );

    QTPosiciones = new QTable( this, "QTPosiciones" );
    QTPosiciones->setNumCols( QTPosiciones->numCols() + 1 );
    QTPosiciones->horizontalHeader()->setLabel( QTPosiciones->numCols() - 1, tr( "Campo" ) );
    QTPosiciones->setNumCols( QTPosiciones->numCols() + 1 );
    QTPosiciones->horizontalHeader()->setLabel( QTPosiciones->numCols() - 1, tr( "Posicion X" ) );
    QTPosiciones->setNumCols( QTPosiciones->numCols() + 1 );
    QTPosiciones->horizontalHeader()->setLabel( QTPosiciones->numCols() - 1, tr( "Posicion Y" ) );
    QTPosiciones->setNumRows( 0 );
    QTPosiciones->setNumCols( 3 );
    layout10->addWidget( QTPosiciones );

    PosicionesBeneficiosLayout->addLayout( layout10, 0, 0 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    QPBIncrementaX = new QPushButton( this, "QPBIncrementaX" );
    layout12->addWidget( QPBIncrementaX );

    QPBIncrementaY = new QPushButton( this, "QPBIncrementaY" );
    layout12->addWidget( QPBIncrementaY );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout12->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout12->addWidget( QPBCancelar );

    PosicionesBeneficiosLayout->addLayout( layout12, 1, 0 );
    languageChange();
    resize( QSize(695, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PosicionesBeneficios::~PosicionesBeneficios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PosicionesBeneficios::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Campos Posiciones" ) );
    QTPosiciones->horizontalHeader()->setLabel( 0, tr( "Campo" ) );
    QTPosiciones->horizontalHeader()->setLabel( 1, tr( "Posicion X" ) );
    QTPosiciones->horizontalHeader()->setLabel( 2, tr( "Posicion Y" ) );
    QPBIncrementaX->setText( tr( "Incrementa X" ) );
    QPBIncrementaY->setText( tr( "Incrementa Y" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

