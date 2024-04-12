/****************************************************************************
** Form implementation generated from reading ui file 'UI/ClavesSatSiscom.ui'
**
** Created: Thu Apr 11 21:39:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ClavesSatSiscom.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QCtrlProductosSE.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"

/*
 *  Constructs a ClavesSatSiscom as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ClavesSatSiscom::ClavesSatSiscom( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ClavesSatSiscom" );
    ClavesSatSiscomLayout = new QGridLayout( this, 1, 1, 11, 6, "ClavesSatSiscomLayout"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout6->addWidget( textLabel5 );

    layout5 = new QHBoxLayout( 0, 0, 6, "layout5"); 

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout3->addWidget( textLabel4 );

    QLEClaveSatReg = new QLineEdit( this, "QLEClaveSatReg" );
    QLEClaveSatReg->setEnabled( FALSE );
    layout3->addWidget( QLEClaveSatReg );
    layout5->addLayout( layout3 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout3_2->addWidget( textLabel4_2 );

    QLEPalabraClaveReg = new QLineEdit( this, "QLEPalabraClaveReg" );
    QLEPalabraClaveReg->setEnabled( FALSE );
    layout3_2->addWidget( QLEPalabraClaveReg );
    layout5->addLayout( layout3_2 );
    layout6->addLayout( layout5 );

    ClavesSatSiscomLayout->addMultiCellLayout( layout6, 1, 1, 0, 1 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrProductos );
    layout10->addLayout( layout1 );

    layout5_2 = new QHBoxLayout( 0, 0, 6, "layout5_2"); 

    layout3_3 = new QVBoxLayout( 0, 0, 6, "layout3_3"); 

    textLabel4_3 = new QLabel( this, "textLabel4_3" );
    layout3_3->addWidget( textLabel4_3 );

    QLEClaveSat = new QLineEdit( this, "QLEClaveSat" );
    QLEClaveSat->setReadOnly( TRUE );
    layout3_3->addWidget( QLEClaveSat );
    layout5_2->addLayout( layout3_3 );

    layout3_2_2 = new QVBoxLayout( 0, 0, 6, "layout3_2_2"); 

    textLabel4_2_2 = new QLabel( this, "textLabel4_2_2" );
    layout3_2_2->addWidget( textLabel4_2_2 );

    QLEPalabraClave = new QLineEdit( this, "QLEPalabraClave" );
    QLEPalabraClave->setReadOnly( TRUE );
    layout3_2_2->addWidget( QLEPalabraClave );
    layout5_2->addLayout( layout3_2_2 );
    layout10->addLayout( layout5_2 );
    layout11->addLayout( layout10 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout2->addWidget( textLabel3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    layout2->addWidget( QTEDescripcion );
    layout11->addLayout( layout2 );

    ClavesSatSiscomLayout->addMultiCellLayout( layout11, 0, 0, 0, 1 );

    pushButton2 = new QPushButton( this, "pushButton2" );
    pushButton2->setEnabled( FALSE );

    ClavesSatSiscomLayout->addWidget( pushButton2, 2, 1 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );

    ClavesSatSiscomLayout->addWidget( QPBRegistrar, 2, 0 );
    languageChange();
    resize( QSize(660, 408).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ClavesSatSiscom::~ClavesSatSiscom()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ClavesSatSiscom::languageChange()
{
    setCaption( tr( "Manejador Claves SAT" ) );
    textLabel5->setText( tr( "Datos para registro" ) );
    textLabel4->setText( tr( "Clave SAT" ) );
    textLabel4_2->setText( tr( "Palabras Clave Busqueda" ) );
    textLabel1->setText( tr( "Producto" ) );
    textLabel4_3->setText( tr( "Clave SAT" ) );
    textLabel4_2_2->setText( tr( "Palabras Clave Busqueda" ) );
    textLabel3->setText( tr( "Descripcion" ) );
    pushButton2->setText( tr( "Actualizar" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
}

