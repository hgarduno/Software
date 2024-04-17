/****************************************************************************
** Form implementation generated from reading ui file 'UI/QControlDireccion.ui'
**
** Created: Fri Apr 12 21:24:14 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_QControlDireccion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a QControlDireccion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
QControlDireccion::QControlDireccion( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "QControlDireccion" );
    QControlDireccionLayout = new QGridLayout( this, 1, 1, 11, 6, "QControlDireccionLayout"); 

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout4->addWidget( textLabel2 );

    QLECalle = new QLineEdit( this, "QLECalle" );
    QLECalle->setMinimumSize( QSize( 450, 0 ) );
    layout4->addWidget( QLECalle );
    layout11->addLayout( layout4 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout5->addWidget( textLabel3 );

    QLENumero = new QLineEdit( this, "QLENumero" );
    QLENumero->setMinimumSize( QSize( 100, 0 ) );
    layout5->addWidget( QLENumero );
    layout11->addLayout( layout5 );

    QControlDireccionLayout->addMultiCellLayout( layout11, 0, 0, 0, 2 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout7->addWidget( textLabel4 );

    QLEColonia = new QLineEdit( this, "QLEColonia" );
    QLEColonia->setMinimumSize( QSize( 180, 0 ) );
    layout7->addWidget( QLEColonia );

    QControlDireccionLayout->addLayout( layout7, 1, 0 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout15->addWidget( textLabel5 );

    QCBEstado = new QComboBox( FALSE, this, "QCBEstado" );
    QCBEstado->setEditable( TRUE );
    QCBEstado->setInsertionPolicy( QComboBox::NoInsertion );
    QCBEstado->setAutoCompletion( TRUE );
    QCBEstado->setDuplicatesEnabled( FALSE );
    layout15->addWidget( QCBEstado );

    QControlDireccionLayout->addLayout( layout15, 1, 2 );

    layout7_2_2 = new QVBoxLayout( 0, 0, 6, "layout7_2_2"); 

    textLabel4_2_2 = new QLabel( this, "textLabel4_2_2" );
    layout7_2_2->addWidget( textLabel4_2_2 );

    QLEMunicipio = new QLineEdit( this, "QLEMunicipio" );
    QLEMunicipio->setMinimumSize( QSize( 180, 0 ) );
    layout7_2_2->addWidget( QLEMunicipio );

    QControlDireccionLayout->addLayout( layout7_2_2, 1, 1 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2->addWidget( textLabel3_2 );

    QLECP = new QLineEdit( this, "QLECP" );
    QLECP->setMinimumSize( QSize( 100, 0 ) );
    QLECP->setMaximumSize( QSize( 100, 32767 ) );
    layout5_2->addWidget( QLECP );

    QControlDireccionLayout->addLayout( layout5_2, 0, 3 );
    languageChange();
    resize( QSize(692, 116).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
QControlDireccion::~QControlDireccion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void QControlDireccion::languageChange()
{
    setCaption( tr( "Form2" ) );
    textLabel2->setText( tr( "Calle" ) );
    textLabel3->setText( tr( "Numero" ) );
    textLabel4->setText( tr( "Colonia" ) );
    textLabel5->setText( tr( "Estado" ) );
    QCBEstado->clear();
    QCBEstado->insertItem( tr( "Estado De Mexico" ) );
    QCBEstado->insertItem( tr( "Aguascalientes" ) );
    QCBEstado->insertItem( tr( "B.C. Norte" ) );
    QCBEstado->insertItem( tr( "B.C. Sur." ) );
    QCBEstado->insertItem( tr( "Coahuila" ) );
    QCBEstado->insertItem( tr( "Colima" ) );
    QCBEstado->insertItem( tr( "Durango" ) );
    QCBEstado->insertItem( tr( "Tamaulipas" ) );
    QCBEstado->insertItem( tr( "Guerrero" ) );
    QCBEstado->insertItem( tr( "Yucatan" ) );
    QCBEstado->insertItem( tr( "Chiapas" ) );
    QCBEstado->insertItem( tr( "Veracruz" ) );
    QCBEstado->insertItem( tr( "Zacatecas" ) );
    QCBEstado->insertItem( tr( "Queretaro" ) );
    QCBEstado->insertItem( tr( "D.F." ) );
    QCBEstado->insertItem( tr( "Jalisco" ) );
    QCBEstado->insertItem( tr( "Quintana Roo" ) );
    QCBEstado->insertItem( tr( "Campeche" ) );
    QCBEstado->insertItem( tr( "Puebla" ) );
    QCBEstado->insertItem( tr( "Nayarit" ) );
    QCBEstado->insertItem( tr( "Tlaxcala" ) );
    QCBEstado->insertItem( tr( "Morelos" ) );
    QCBEstado->insertItem( tr( "Oaxaca" ) );
    QCBEstado->insertItem( tr( "Guanajuato" ) );
    QCBEstado->insertItem( tr( "Chihuahua" ) );
    QCBEstado->insertItem( tr( "Sonora" ) );
    QCBEstado->insertItem( tr( "Durango" ) );
    QCBEstado->insertItem( tr( "Monterrey" ) );
    textLabel4_2_2->setText( tr( "Municipio" ) );
    textLabel3_2->setText( tr( "Codigo Postal" ) );
}

