/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaDireccion.ui'
**
** Created: Sat Jan 27 16:37:23 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaDireccion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CapturaDireccion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDireccion::CapturaDireccion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDireccion" );
    CapturaDireccionLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDireccionLayout"); 

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout22->addWidget( textLabel6 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    layout22->addWidget( QLECalle );
    layout25->addLayout( layout22 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( textLabel5 );

    QLENoExterior = new QLineEdit( this, "QLENoExterior" );
    QLENoExterior->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENoExterior->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( QLENoExterior );
    layout25->addLayout( layout16 );

    layout16_2 = new QVBoxLayout( 0, 0, 6, "layout16_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2->addWidget( textLabel5_2 );

    QLENoInterior = new QLineEdit( this, "QLENoInterior" );
    QLENoInterior->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENoInterior->sizePolicy().hasHeightForWidth() ) );
    layout16_2->addWidget( QLENoInterior );
    layout25->addLayout( layout16_2 );

    CapturaDireccionLayout->addLayout( layout25, 0, 0 );

    layout32 = new QHBoxLayout( 0, 0, 6, "layout32"); 

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setAutoDefault( FALSE );
    layout32->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout32->addWidget( QPBCancelar );

    CapturaDireccionLayout->addLayout( layout32, 3, 0 );

    layout29 = new QVBoxLayout( 0, 0, 6, "layout29"); 

    textLabel7 = new QLabel( this, "textLabel7" );
    layout29->addWidget( textLabel7 );

    QTEReferencias = new QTextEdit( this, "QTEReferencias" );
    layout29->addWidget( QTEReferencias );

    CapturaDireccionLayout->addLayout( layout29, 2, 0 );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    layout22_2 = new QVBoxLayout( 0, 0, 6, "layout22_2"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    layout22_2->addWidget( textLabel6_2 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    layout22_2->addWidget( QLEColonia );
    layout36->addLayout( layout22_2 );

    layout22_2_2 = new QVBoxLayout( 0, 0, 6, "layout22_2_2"); 

    textLabel6_2_2 = new QLabel( this, "textLabel6_2_2" );
    layout22_2_2->addWidget( textLabel6_2_2 );

    QLEDelegacionMunicipio = new QLineEdit( this, "QLEDelegacionMunicipio" );
    layout22_2_2->addWidget( QLEDelegacionMunicipio );
    layout36->addLayout( layout22_2_2 );

    layout16_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2"); 

    textLabel5_2_2 = new QLabel( this, "textLabel5_2_2" );
    textLabel5_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2->addWidget( textLabel5_2_2 );

    QLEEstado = new QLineEdit( this, "QLEEstado" );
    QLEEstado->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEEstado->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2->addWidget( QLEEstado );
    layout36->addLayout( layout16_2_2 );

    layout16_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2_2"); 

    textLabel5_2_2_2 = new QLabel( this, "textLabel5_2_2_2" );
    textLabel5_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2->addWidget( textLabel5_2_2_2 );

    QLECodigoPostal = new QLineEdit( this, "QLECodigoPostal" );
    QLECodigoPostal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECodigoPostal->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2->addWidget( QLECodigoPostal );
    layout36->addLayout( layout16_2_2_2 );

    CapturaDireccionLayout->addLayout( layout36, 1, 0 );
    languageChange();
    resize( QSize(680, 288).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( QLECalle, QLENoExterior );
    setTabOrder( QLENoExterior, QLENoInterior );
    setTabOrder( QLENoInterior, QLEColonia );
    setTabOrder( QLEColonia, QLEDelegacionMunicipio );
    setTabOrder( QLEDelegacionMunicipio, QLEEstado );
    setTabOrder( QLEEstado, QLECodigoPostal );
    setTabOrder( QLECodigoPostal, QTEReferencias );
    setTabOrder( QTEReferencias, QPBAceptar );
    setTabOrder( QPBAceptar, QPBCancelar );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaDireccion::~CapturaDireccion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDireccion::languageChange()
{
    setCaption( tr( "Captura Direccion" ) );
    textLabel6->setText( tr( "Calle" ) );
    textLabel5->setText( tr( "No Exterior" ) );
    textLabel5_2->setText( tr( "No Interior" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel7->setText( tr( "Referencias" ) );
    textLabel6_2->setText( tr( "Colonia" ) );
    textLabel6_2_2->setText( tr( "Delegacion/Municipio" ) );
    textLabel5_2_2->setText( tr( "Estado" ) );
    textLabel5_2_2_2->setText( tr( "Codigo Postal" ) );
}

