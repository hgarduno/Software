/****************************************************************************
** Form implementation generated from reading ui file 'UI/UI_ObjetosEjecucion.ui'
**
** Created: Thu Apr 11 21:35:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ObjetosEjecucion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ObjetosEjecucion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ObjetosEjecucion::ObjetosEjecucion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ObjetosEjecucion" );
    ObjetosEjecucionLayout = new QGridLayout( this, 1, 1, 11, 6, "ObjetosEjecucionLayout"); 

    QTDatosObj = new QTable( this, "QTDatosObj" );
    QTDatosObj->setNumCols( QTDatosObj->numCols() + 1 );
    QTDatosObj->horizontalHeader()->setLabel( QTDatosObj->numCols() - 1, tr( "Objeto" ) );
    QTDatosObj->setNumCols( QTDatosObj->numCols() + 1 );
    QTDatosObj->horizontalHeader()->setLabel( QTDatosObj->numCols() - 1, tr( "Nombre" ) );
    QTDatosObj->setNumRows( 0 );
    QTDatosObj->setNumCols( 2 );

    ObjetosEjecucionLayout->addWidget( QTDatosObj, 0, 2 );

    line1 = new QFrame( this, "line1" );
    line1->setFrameShape( QFrame::VLine );
    line1->setFrameShadow( QFrame::Sunken );
    line1->setFrameShape( QFrame::VLine );

    ObjetosEjecucionLayout->addWidget( line1, 0, 1 );

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    layout38 = new QHBoxLayout( 0, 0, 6, "layout38"); 

    QTDatosO = new QTable( this, "QTDatosO" );
    QTDatosO->setNumCols( QTDatosO->numCols() + 1 );
    QTDatosO->horizontalHeader()->setLabel( QTDatosO->numCols() - 1, tr( "Objeto" ) );
    QTDatosO->setNumRows( 0 );
    QTDatosO->setNumCols( 1 );
    QTDatosO->setReadOnly( TRUE );
    layout38->addWidget( QTDatosO );

    QTDatosP = new QTable( this, "QTDatosP" );
    QTDatosP->setNumCols( QTDatosP->numCols() + 1 );
    QTDatosP->horizontalHeader()->setLabel( QTDatosP->numCols() - 1, tr( "Propiedades" ) );
    QTDatosP->setNumRows( 0 );
    QTDatosP->setNumCols( 1 );
    layout38->addWidget( QTDatosP );
    layout44->addLayout( layout38 );

    layout42 = new QHBoxLayout( 0, 0, 6, "layout42"); 

    layout39_2 = new QVBoxLayout( 0, 0, 6, "layout39_2"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    layout39_2->addWidget( textLabel6_2 );

    QLEObjeto = new QLineEdit( this, "QLEObjeto" );
    QLEObjeto->setReadOnly( TRUE );
    layout39_2->addWidget( QLEObjeto );
    layout42->addLayout( layout39_2 );

    layout39 = new QVBoxLayout( 0, 0, 6, "layout39"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout39->addWidget( textLabel6 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout39->addWidget( QLENombre );
    layout42->addLayout( layout39 );
    layout44->addLayout( layout42 );

    layout43 = new QHBoxLayout( 0, 0, 6, "layout43"); 

    QPBAnexarObjeto = new QPushButton( this, "QPBAnexarObjeto" );
    layout43->addWidget( QPBAnexarObjeto );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout43->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout43->addWidget( QPBCancelar );
    layout44->addLayout( layout43 );

    ObjetosEjecucionLayout->addLayout( layout44, 0, 0 );
    languageChange();
    resize( QSize(654, 571).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ObjetosEjecucion::~ObjetosEjecucion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ObjetosEjecucion::languageChange()
{
    setCaption( tr( "Objetos En Tiempo De Ejecucion" ) );
    QTDatosObj->horizontalHeader()->setLabel( 0, tr( "Objeto" ) );
    QTDatosObj->horizontalHeader()->setLabel( 1, tr( "Nombre" ) );
    QTDatosO->horizontalHeader()->setLabel( 0, tr( "Objeto" ) );
    QTDatosP->horizontalHeader()->setLabel( 0, tr( "Propiedades" ) );
    textLabel6_2->setText( tr( "Objeto" ) );
    textLabel6->setText( tr( "Nombre Del Objeto" ) );
    QPBAnexarObjeto->setText( tr( "Anexar Objeto" ) );
    QPBAceptar->setText( tr( "Anexar A La Pantalla" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

