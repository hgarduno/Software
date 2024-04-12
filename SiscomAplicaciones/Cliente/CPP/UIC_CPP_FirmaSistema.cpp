/****************************************************************************
** Form implementation generated from reading ui file 'UI/FirmaSistema.ui'
**
** Created: Thu Apr 11 21:37:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_FirmaSistema.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlServidoresSiscom.h>
#include <QCtrlPerfiles.h>
#include <QCtrlUsuarios.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlServidoresSiscom.h"
#include "QCtrlPerfiles.h"
#include "QCtrlUsuarios.h"

/*
 *  Constructs a FirmaSistema as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
FirmaSistema::FirmaSistema( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "FirmaSistema" );
    FirmaSistemaLayout = new QGridLayout( this, 1, 1, 11, 6, "FirmaSistemaLayout"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout12->addWidget( textLabel4 );

    QCtrServidores = new QCtrlServidoresSiscom( this, "QCtrServidores" );
    layout12->addWidget( QCtrServidores );

    FirmaSistemaLayout->addMultiCellLayout( layout12, 0, 0, 0, 2 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout13->addWidget( textLabel5 );

    QCtrPerfiles = new QCtrlPerfiles( this, "QCtrPerfiles" );
    layout13->addWidget( QCtrPerfiles );

    FirmaSistemaLayout->addMultiCellLayout( layout13, 1, 1, 0, 2 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout14->addWidget( textLabel6 );

    QCtrUsuarios = new QCtrlUsuarios( this, "QCtrUsuarios" );
    layout14->addWidget( QCtrUsuarios );

    FirmaSistemaLayout->addMultiCellLayout( layout14, 2, 2, 0, 2 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );

    FirmaSistemaLayout->addWidget( QPBCancelar, 3, 2 );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );

    FirmaSistemaLayout->addWidget( QPBAceptar, 3, 0 );

    QPBTipoLetra = new QPushButton( this, "QPBTipoLetra" );

    FirmaSistemaLayout->addWidget( QPBTipoLetra, 3, 1 );
    languageChange();
    resize( QSize(553, 500).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
FirmaSistema::~FirmaSistema()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void FirmaSistema::languageChange()
{
    setCaption( tr( "Acceso Al Sistema" ) );
    textLabel4->setText( tr( "Servidores" ) );
    textLabel5->setText( tr( "Perfil" ) );
    textLabel6->setText( tr( "Usuarios" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBTipoLetra->setText( tr( "Selecciona Tipo Letra" ) );
}

