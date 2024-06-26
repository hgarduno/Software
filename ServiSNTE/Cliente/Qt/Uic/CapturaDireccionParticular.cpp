/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaDireccionParticular.ui'
**
** Created: Thu Apr 11 21:07:25 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaDireccionParticular.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qgroupbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTipoViviendaSS.h"

/*
 *  Constructs a CapturaDireccionParticular as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CapturaDireccionParticular::CapturaDireccionParticular( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CapturaDireccionParticular" );
    CapturaDireccionParticularLayout = new QGridLayout( this, 1, 1, 11, 6, "CapturaDireccionParticularLayout"); 

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout22->addWidget( textLabel6 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    QLECalle->setReadOnly( TRUE );
    layout22->addWidget( QLECalle );
    layout25->addLayout( layout22 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout16->addWidget( textLabel5 );

    QLENoExterior = new QLineEdit( this, "QLENoExterior" );
    QLENoExterior->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENoExterior->sizePolicy().hasHeightForWidth() ) );
    QLENoExterior->setReadOnly( TRUE );
    layout16->addWidget( QLENoExterior );
    layout25->addLayout( layout16 );

    layout16_2 = new QVBoxLayout( 0, 0, 6, "layout16_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2->addWidget( textLabel5_2 );

    QLENoInterior = new QLineEdit( this, "QLENoInterior" );
    QLENoInterior->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENoInterior->sizePolicy().hasHeightForWidth() ) );
    QLENoInterior->setReadOnly( TRUE );
    layout16_2->addWidget( QLENoInterior );
    layout25->addLayout( layout16_2 );

    CapturaDireccionParticularLayout->addMultiCellLayout( layout25, 0, 0, 0, 1 );

    layout36 = new QHBoxLayout( 0, 0, 6, "layout36"); 

    layout22_2 = new QVBoxLayout( 0, 0, 6, "layout22_2"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    layout22_2->addWidget( textLabel6_2 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    QLEColonia->setReadOnly( TRUE );
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
    QLEEstado->setReadOnly( TRUE );
    layout16_2_2->addWidget( QLEEstado );
    layout36->addLayout( layout16_2_2 );

    layout16_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout16_2_2_2"); 

    textLabel5_2_2_2 = new QLabel( this, "textLabel5_2_2_2" );
    textLabel5_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout16_2_2_2->addWidget( textLabel5_2_2_2 );

    QLECodigoPostal = new QLineEdit( this, "QLECodigoPostal" );
    QLECodigoPostal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECodigoPostal->sizePolicy().hasHeightForWidth() ) );
    QLECodigoPostal->setReadOnly( TRUE );
    layout16_2_2_2->addWidget( QLECodigoPostal );
    layout36->addLayout( layout16_2_2_2 );

    CapturaDireccionParticularLayout->addMultiCellLayout( layout36, 1, 1, 0, 1 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel7 = new QLabel( this, "textLabel7" );
    layout12->addWidget( textLabel7 );

    QTEReferencias = new QTextEdit( this, "QTEReferencias" );
    QTEReferencias->setReadOnly( TRUE );
    layout12->addWidget( QTEReferencias );

    CapturaDireccionParticularLayout->addLayout( layout12, 2, 0 );

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    groupBox2 = new QGroupBox( this, "groupBox2" );
    groupBox2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, groupBox2->sizePolicy().hasHeightForWidth() ) );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    textLabel1 = new QLabel( groupBox2, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );

    groupBox2Layout->addWidget( textLabel1, 1, 0 );

    QLEViviendaOtra = new QLineEdit( groupBox2, "QLEViviendaOtra" );

    groupBox2Layout->addWidget( QLEViviendaOtra, 1, 1 );

    QCtrTipoVivienda = new QCtrlTipoViviendaSS( groupBox2, "QCtrTipoVivienda" );

    groupBox2Layout->addMultiCellWidget( QCtrTipoVivienda, 0, 0, 0, 1 );
    layout27->addWidget( groupBox2 );

    layout13_5 = new QGridLayout( 0, 1, 1, 0, 6, "layout13_5"); 

    textLabel2_5 = new QLabel( this, "textLabel2_5" );
    textLabel2_5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_5->sizePolicy().hasHeightForWidth() ) );

    layout13_5->addWidget( textLabel2_5, 0, 0 );

    QLETiempoResidir = new QLineEdit( this, "QLETiempoResidir" );
    QLETiempoResidir->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLETiempoResidir->sizePolicy().hasHeightForWidth() ) );

    layout13_5->addWidget( QLETiempoResidir, 1, 0 );
    layout27->addLayout( layout13_5 );

    CapturaDireccionParticularLayout->addLayout( layout27, 2, 1 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setAutoDefault( FALSE );
    layout14->addWidget( QPBRegistrar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setAutoDefault( FALSE );
    layout14->addWidget( QPBActualizar );

    QPBAceptar = new QPushButton( this, "QPBAceptar" );
    QPBAceptar->setEnabled( FALSE );
    QPBAceptar->setAutoDefault( FALSE );
    layout14->addWidget( QPBAceptar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout14->addWidget( QPBCancelar );

    CapturaDireccionParticularLayout->addMultiCellLayout( layout14, 3, 3, 0, 1 );
    languageChange();
    resize( QSize(667, 337).expandedTo(minimumSizeHint()) );
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
CapturaDireccionParticular::~CapturaDireccionParticular()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaDireccionParticular::languageChange()
{
    setCaption( tr( "Captura Direccion Particular" ) );
    textLabel6->setText( tr( "Calle" ) );
    textLabel5->setText( tr( "No Exterior" ) );
    textLabel5_2->setText( tr( "No Interior" ) );
    textLabel6_2->setText( tr( "Colonia" ) );
    textLabel6_2_2->setText( tr( "Delegacion/Municipio" ) );
    textLabel5_2_2->setText( tr( "Estado" ) );
    textLabel5_2_2_2->setText( tr( "Codigo Postal" ) );
    textLabel7->setText( tr( "Referencias" ) );
    groupBox2->setTitle( tr( "Tipo de Vivienda" ) );
    textLabel1->setText( tr( "Otra:" ) );
    textLabel2_5->setText( tr( "Tiempo de Residir" ) );
    QLETiempoResidir->setText( QString::null );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    QPBAceptar->setText( tr( "Aceptar" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

