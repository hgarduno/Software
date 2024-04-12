/****************************************************************************
** Form implementation generated from reading ui file 'UI/CambiaEliminaClaveProducto.ui'
**
** Created: Thu Apr 11 21:39:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CambiaEliminaClaveProducto.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlProdSiscomElectronica.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProdSiscomElectronica.h"

/*
 *  Constructs a CambiaEliminaClaveProducto as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CambiaEliminaClaveProducto::CambiaEliminaClaveProducto( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CambiaEliminaClaveProducto" );
    CambiaEliminaClaveProductoLayout = new QGridLayout( this, 1, 1, 11, 6, "CambiaEliminaClaveProductoLayout"); 

    layout53 = new QVBoxLayout( 0, 0, 6, "layout53"); 

    layout51 = new QVBoxLayout( 0, 0, 6, "layout51"); 

    layout49 = new QVBoxLayout( 0, 0, 6, "layout49"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout49->addWidget( textLabel1 );

    QCtrProdSiscom = new QCtrlProdSiscomElectronica( this, "QCtrProdSiscom" );
    layout49->addWidget( QCtrProdSiscom );
    layout51->addLayout( layout49 );

    layout85 = new QVBoxLayout( 0, 0, 6, "layout85"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout85->addWidget( textLabel4_2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout85->addWidget( QTEDescripcion );
    layout51->addLayout( layout85 );
    layout53->addLayout( layout51 );

    layout52 = new QVBoxLayout( 0, 0, 6, "layout52"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout52->addWidget( textLabel2 );

    QLECveNueva = new QLineEdit( this, "QLECveNueva" );
    layout52->addWidget( QLECveNueva );
    layout53->addLayout( layout52 );

    CambiaEliminaClaveProductoLayout->addLayout( layout53, 0, 0 );

    layout54 = new QHBoxLayout( 0, 0, 6, "layout54"); 

    QPBCClave = new QPushButton( this, "QPBCClave" );
    QPBCClave->setMinimumSize( QSize( 0, 70 ) );
    QPBCClave->setMaximumSize( QSize( 32767, 70 ) );
    QPBCClave->setAutoDefault( FALSE );
    layout54->addWidget( QPBCClave );

    QPBEProducto = new QPushButton( this, "QPBEProducto" );
    QPBEProducto->setMinimumSize( QSize( 0, 70 ) );
    QPBEProducto->setMaximumSize( QSize( 32767, 70 ) );
    QPBEProducto->setAutoDefault( FALSE );
    layout54->addWidget( QPBEProducto );

    QPBAnexar_2_2 = new QPushButton( this, "QPBAnexar_2_2" );
    QPBAnexar_2_2->setMinimumSize( QSize( 0, 70 ) );
    QPBAnexar_2_2->setMaximumSize( QSize( 32767, 70 ) );
    QPBAnexar_2_2->setAutoDefault( FALSE );
    layout54->addWidget( QPBAnexar_2_2 );

    CambiaEliminaClaveProductoLayout->addLayout( layout54, 1, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CambiaEliminaClaveProducto::~CambiaEliminaClaveProducto()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CambiaEliminaClaveProducto::languageChange()
{
    setCaption( tr( "Cambia Elimina Clave" ) );
    textLabel1->setText( tr( "Clave Del Producto A Eliminar / Cambiar" ) );
    textLabel4_2->setText( tr( "Descripcion" ) );
    textLabel2->setText( tr( "Clave Actualizada" ) );
    QPBCClave->setText( tr( "Cambiar Clave\n"
"Del Producto" ) );
    QPBEProducto->setText( tr( "Eliminar Producto\n"
"Del Sistema" ) );
    QPBAnexar_2_2->setText( tr( "Cancelar" ) );
}

