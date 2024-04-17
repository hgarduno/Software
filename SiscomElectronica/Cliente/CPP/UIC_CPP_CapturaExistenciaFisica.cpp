/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaExistenciaFisica.ui'
**
** Created: Fri Apr 12 21:26:01 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaExistenciaFisica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaExistenciaFisica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaExistenciaFisica::CapturaExistenciaFisica( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaExistenciaFisica" );
    CapturaExistenciaFisicaLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaExistenciaFisicaLayout"); 

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1_3 );

    QLEExistenciaFisica = new QLineEdit( this, "QLEExistenciaFisica" );
    QLEExistenciaFisica->setReadOnly( FALSE );
    layout7->addWidget( QLEExistenciaFisica );
    layout13->addLayout( layout7 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    layout12->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout12->addWidget( QPBCancelar );
    layout13->addLayout( layout12 );

    CapturaExistenciaFisicaLayout->addLayout( layout13, 0, 0 );
    languageChange();
    resize( QSize(401, 111).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaExistenciaFisica::~CapturaExistenciaFisica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaExistenciaFisica::languageChange()
{
    setCaption( tr( "Existencia Fisica Del Producto" ) );
    textLabel1_3->setText( tr( "Existencia Fisica" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

