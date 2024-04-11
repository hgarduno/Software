/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/Proveedores.ui'
**
** Created: Thu Apr 11 21:07:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Proveedores.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Proveedores as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Proveedores::Proveedores( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Proveedores" );
    ProveedoresLayout = new QGridLayout( this, 1, 1, 11, 6, "ProveedoresLayout"); 

    layout6 = new QHBoxLayout( 0, 0, 6, "layout6"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    lineEdit49 = new QLineEdit( this, "lineEdit49" );
    lineEdit49->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lineEdit49->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( lineEdit49 );
    layout6->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    lineEdit50 = new QLineEdit( this, "lineEdit50" );
    layout2->addWidget( lineEdit50 );
    layout6->addLayout( layout2 );

    ProveedoresLayout->addMultiCellLayout( layout6, 0, 0, 0, 1 );

    layout62 = new QHBoxLayout( 0, 0, 6, "layout62"); 

    pushButton10 = new QPushButton( this, "pushButton10" );
    layout62->addWidget( pushButton10 );

    pushButton10_2 = new QPushButton( this, "pushButton10_2" );
    layout62->addWidget( pushButton10_2 );

    pushButton10_2_2 = new QPushButton( this, "pushButton10_2_2" );
    layout62->addWidget( pushButton10_2_2 );

    ProveedoresLayout->addMultiCellLayout( layout62, 4, 4, 0, 1 );

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout42->addWidget( textLabel2_2 );

    textEdit2 = new QTextEdit( this, "textEdit2" );
    textEdit2->setWordWrap( QTextEdit::WidgetWidth );
    layout42->addWidget( textEdit2 );

    ProveedoresLayout->addMultiCellLayout( layout42, 1, 1, 0, 1 );

    layout46 = new QHBoxLayout( 0, 0, 6, "layout46"); 

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout43->addWidget( textLabel3 );

    lineEdit24 = new QLineEdit( this, "lineEdit24" );
    layout43->addWidget( lineEdit24 );
    layout46->addLayout( layout43 );

    layout43_2 = new QVBoxLayout( 0, 0, 6, "layout43_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    layout43_2->addWidget( textLabel3_2 );

    lineEdit24_2 = new QLineEdit( this, "lineEdit24_2" );
    layout43_2->addWidget( lineEdit24_2 );
    layout46->addLayout( layout43_2 );

    layout43_3 = new QVBoxLayout( 0, 0, 6, "layout43_3"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    layout43_3->addWidget( textLabel3_3 );

    lineEdit24_3 = new QLineEdit( this, "lineEdit24_3" );
    layout43_3->addWidget( lineEdit24_3 );
    layout46->addLayout( layout43_3 );

    ProveedoresLayout->addMultiCellLayout( layout46, 2, 2, 0, 1 );

    layout67 = new QHBoxLayout( 0, 0, 6, "layout67"); 

    layout43_5 = new QVBoxLayout( 0, 0, 6, "layout43_5"); 

    textLabel3_5 = new QLabel( this, "textLabel3_5" );
    layout43_5->addWidget( textLabel3_5 );

    lineEdit24_5 = new QLineEdit( this, "lineEdit24_5" );
    layout43_5->addWidget( lineEdit24_5 );
    layout67->addLayout( layout43_5 );

    layout43_5_2 = new QVBoxLayout( 0, 0, 6, "layout43_5_2"); 

    textLabel3_5_2 = new QLabel( this, "textLabel3_5_2" );
    layout43_5_2->addWidget( textLabel3_5_2 );

    lineEdit24_5_2 = new QLineEdit( this, "lineEdit24_5_2" );
    layout43_5_2->addWidget( lineEdit24_5_2 );
    layout67->addLayout( layout43_5_2 );

    layout43_5_4 = new QVBoxLayout( 0, 0, 6, "layout43_5_4"); 

    textLabel3_5_4 = new QLabel( this, "textLabel3_5_4" );
    layout43_5_4->addWidget( textLabel3_5_4 );

    lineEdit24_5_4 = new QLineEdit( this, "lineEdit24_5_4" );
    layout43_5_4->addWidget( lineEdit24_5_4 );
    layout67->addLayout( layout43_5_4 );

    layout43_5_3 = new QVBoxLayout( 0, 0, 6, "layout43_5_3"); 

    textLabel3_5_3 = new QLabel( this, "textLabel3_5_3" );
    layout43_5_3->addWidget( textLabel3_5_3 );

    lineEdit24_5_3 = new QLineEdit( this, "lineEdit24_5_3" );
    layout43_5_3->addWidget( lineEdit24_5_3 );
    layout67->addLayout( layout43_5_3 );

    ProveedoresLayout->addLayout( layout67, 3, 0 );

    layout70 = new QHBoxLayout( 0, 0, 6, "layout70"); 

    layout43_5_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout43_5_3_2_2"); 

    textLabel3_5_3_2_2 = new QLabel( this, "textLabel3_5_3_2_2" );
    layout43_5_3_2_2->addWidget( textLabel3_5_3_2_2 );

    lineEdit24_5_3_2_2 = new QLineEdit( this, "lineEdit24_5_3_2_2" );
    layout43_5_3_2_2->addWidget( lineEdit24_5_3_2_2 );
    layout70->addLayout( layout43_5_3_2_2 );

    layout43_5_3_2 = new QVBoxLayout( 0, 0, 6, "layout43_5_3_2"); 

    textLabel3_5_3_2 = new QLabel( this, "textLabel3_5_3_2" );
    layout43_5_3_2->addWidget( textLabel3_5_3_2 );

    lineEdit24_5_3_2 = new QLineEdit( this, "lineEdit24_5_3_2" );
    layout43_5_3_2->addWidget( lineEdit24_5_3_2 );
    layout70->addLayout( layout43_5_3_2 );

    ProveedoresLayout->addLayout( layout70, 3, 1 );
    languageChange();
    resize( QSize(508, 478).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Proveedores::~Proveedores()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Proveedores::languageChange()
{
    setCaption( tr( "Manejador de Proveedores" ) );
    textLabel1->setText( tr( "Clave Proveedor" ) );
    textLabel2->setText( tr( "Razon Social" ) );
    pushButton10->setText( tr( "Captura Direccion" ) );
    pushButton10_2->setText( tr( "Captura Contacto" ) );
    pushButton10_2_2->setText( tr( "Registra Proveedor" ) );
    textLabel2_2->setText( tr( "Direccion" ) );
    textEdit2->setText( tr( "Calle: Eva Samano de Lopez Mateos No 10 Int 3B\n"
"Colonia: Bo Tlacateco\n"
"Delegacion: Tepotzotlan Estado: Mexico CP:54605\n"
"\n"
"Por la cancha de basquet del Crea\n"
"\n"
"Nombre Contacto\n"
"\n"
"Heli Garduno Esquivel" ) );
    textLabel3->setText( tr( "Telefono 1" ) );
    textLabel3_2->setText( tr( "Telefono 2" ) );
    textLabel3_3->setText( tr( "Telefono 3" ) );
    textLabel3_5->setText( tr( "Descuento 1" ) );
    textLabel3_5_2->setText( tr( "Descuento 2" ) );
    textLabel3_5_4->setText( tr( "Descuento 3" ) );
    textLabel3_5_3->setText( tr( "Descuento 4" ) );
    textLabel3_5_3_2_2->setText( tr( "Iva" ) );
    textLabel3_5_3_2->setText( tr( "Plazo" ) );
}

