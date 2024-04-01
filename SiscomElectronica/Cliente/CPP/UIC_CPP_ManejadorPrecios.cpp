/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorPrecios.ui'
**
** Created: Wed Jan 31 10:58:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorPrecios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ManejadorPrecios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorPrecios::ManejadorPrecios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorPrecios" );
    ManejadorPreciosLayout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorPreciosLayout"); 

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout31->addWidget( textLabel4 );

    QCBTipoPrecio = new QComboBox( FALSE, this, "QCBTipoPrecio" );
    QCBTipoPrecio->setEditable( TRUE );
    QCBTipoPrecio->setInsertionPolicy( QComboBox::NoInsertion );
    QCBTipoPrecio->setAutoCompletion( TRUE );
    QCBTipoPrecio->setDuplicatesEnabled( FALSE );
    layout31->addWidget( QCBTipoPrecio );

    ManejadorPreciosLayout->addLayout( layout31, 0, 0 );

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    layout31_2 = new QVBoxLayout( 0, 0, 6, "layout31_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout31_2->addWidget( textLabel4_2 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEnabled( FALSE );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout31_2->addWidget( QCBProductos );
    layout35->addLayout( layout31_2 );

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout33->addWidget( textLabel5 );

    QLEPVenta = new QLineEdit( this, "QLEPVenta" );
    QLEPVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPVenta->sizePolicy().hasHeightForWidth() ) );
    QLEPVenta->setReadOnly( TRUE );
    layout33->addWidget( QLEPVenta );
    layout35->addLayout( layout33 );

    layout33_2 = new QVBoxLayout( 0, 0, 6, "layout33_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout33_2->addWidget( textLabel5_2 );

    QLENvoPrecio = new QLineEdit( this, "QLENvoPrecio" );
    QLENvoPrecio->setEnabled( FALSE );
    QLENvoPrecio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLENvoPrecio->sizePolicy().hasHeightForWidth() ) );
    layout33_2->addWidget( QLENvoPrecio );
    layout35->addLayout( layout33_2 );

    ManejadorPreciosLayout->addLayout( layout35, 1, 0 );

    QPBRegistrarPrecio = new QPushButton( this, "QPBRegistrarPrecio" );
    QPBRegistrarPrecio->setEnabled( FALSE );

    ManejadorPreciosLayout->addWidget( QPBRegistrarPrecio, 3, 0 );

    layout52 = new QVBoxLayout( 0, 0, 6, "layout52"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout52->addWidget( textLabel6 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    layout52->addWidget( QLEDescripcion );

    ManejadorPreciosLayout->addLayout( layout52, 2, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorPrecios::~ManejadorPrecios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorPrecios::languageChange()
{
    setCaption( tr( "Manejador De Precios" ) );
    textLabel4->setText( tr( "Tipo De Precio" ) );
    textLabel4_2->setText( tr( "Producto" ) );
    textLabel5->setText( tr( "Precio De Venta" ) );
    textLabel5_2->setText( tr( "Precio De Venta Nuevo" ) );
    QPBRegistrarPrecio->setText( tr( "Registrar Precio" ) );
    textLabel6->setText( tr( "Descripcion" ) );
}

