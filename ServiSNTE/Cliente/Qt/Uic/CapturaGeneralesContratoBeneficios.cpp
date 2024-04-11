/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaGeneralesContratoBeneficios.ui'
**
** Created: Sat Jan 27 16:38:00 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaGeneralesContratoBeneficios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaGeneralesContratoBeneficios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaGeneralesContratoBeneficios::CapturaGeneralesContratoBeneficios( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaGeneralesContratoBeneficios" );
    CapturaGeneralesContratoBeneficiosLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaGeneralesContratoBeneficiosLayout"); 

    layout67 = new QHBoxLayout( 0, 0, 6, "layout67"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout22->addWidget( textLabel6 );

    QLELugar = new QLineEdit( this, "QLELugar" );
    QLELugar->setReadOnly( FALSE );
    layout22->addWidget( QLELugar );
    layout67->addLayout( layout22 );

    layout16_2_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2_2_2_2"); 

    textLabel5_2_2_2_2_2 = new QLabel( this, "textLabel5_2_2_2_2_2" );
    textLabel5_2_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2_2_2->addWidget( textLabel5_2_2_2_2_2 );

    QLEFecha = new QLineEdit( this, "QLEFecha" );
    QLEFecha->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFecha->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2_2_2->addWidget( QLEFecha );
    layout67->addLayout( layout16_2_2_2_2_2 );

    CapturaGeneralesContratoBeneficiosLayout->addLayout( layout67, 0, 0 );

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    QPBRegistrar->setAutoDefault( FALSE );
    layout6->addWidget( QPBRegistrar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setAutoDefault( FALSE );
    layout6->addWidget( QPBActualizar );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout6->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout6->addWidget( QPBCancelar );

    CapturaGeneralesContratoBeneficiosLayout->addLayout( layout6, 1, 0 );
    languageChange();
    resize( QSize(820, 113).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaGeneralesContratoBeneficios::~CapturaGeneralesContratoBeneficios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaGeneralesContratoBeneficios::languageChange()
{
    setCaption( tr( "Generales Contrato" ) );
    textLabel6->setText( tr( "Lugar" ) );
    QLELugar->setText( QString::null );
    textLabel5_2_2_2_2_2->setText( tr( "Fecha (AAAA-MM-DD)" ) );
    QLEFecha->setText( tr( "--" ) );
    QLEFecha->setInputMask( tr( "0000-00-00; " ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

