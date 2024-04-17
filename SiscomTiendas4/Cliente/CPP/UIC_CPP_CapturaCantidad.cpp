/****************************************************************************
** Form implementation generated from reading ui file 'UI/CapturaCantidad.ui'
**
** Created: Fri Apr 12 21:36:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CapturaCantidad.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlcdnumber.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaCantidad as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaCantidad::CapturaCantidad( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaCantidad" );
    CapturaCantidadLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaCantidadLayout"); 

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout32->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout32->addWidget( QPBCancelar );

    CapturaCantidadLayout->addLayout( layout32, 2, 0 );

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    textLabel2_2_3 = new QLabel( this, "textLabel2_2_3" );
    textLabel2_2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_3->sizePolicy().hasHeightForWidth() ) );
    layout31->addWidget( textLabel2_2_3 );

    QLCDNExistencia = new QLCDNumber( this, "QLCDNExistencia" );
    QLCDNExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)1, 0, 0, QLCDNExistencia->sizePolicy().hasHeightForWidth() ) );
    layout31->addWidget( QLCDNExistencia );

    CapturaCantidadLayout->addMultiCellLayout( layout31, 0, 2, 1, 1 );

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( textLabel2_2 );

    QLEClave = new QLineEdit( this, "QLEClave" );
    QLEClave->setReadOnly( TRUE );
    layout26->addWidget( QLEClave );
    layout33->addLayout( layout26 );

    layout26_2 = new QVBoxLayout( 0, 0, 6, "layout26_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    textLabel2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout26_2->addWidget( textLabel2_2_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout26_2->addWidget( QLECantidad );
    layout33->addLayout( layout26_2 );

    CapturaCantidadLayout->addLayout( layout33, 0, 0 );

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout43->addWidget( textLabel2_3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setMaximumSize( QSize( 32767, 150 ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout43->addWidget( QTEDescripcion );

    CapturaCantidadLayout->addLayout( layout43, 1, 0 );
    languageChange();
    resize( QSize(426, 275).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaCantidad::~CapturaCantidad()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaCantidad::languageChange()
{
    setCaption( tr( "Captura Cantidad" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel2_2_3->setText( tr( "Existencia" ) );
    textLabel2_2->setText( tr( "Producto" ) );
    textLabel2_2_2->setText( tr( "Cantidad" ) );
    textLabel2_3->setText( tr( "Descripcion Producto" ) );
}

