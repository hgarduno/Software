/****************************************************************************
** Form implementation generated from reading ui file 'UI/ProductoPractica.ui'
**
** Created: Wed Jan 31 10:58:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ProductoPractica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ProductoPractica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ProductoPractica::ProductoPractica( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ProductoPractica" );
    ProductoPracticaLayout = new QGridLayout( this, 1, 1, 11, 6, "ProductoPracticaLayout"); 

    layout101 = new QHBoxLayout( 0, 0, 6, "layout101"); 

    layout100 = new QVBoxLayout( 0, 0, 6, "layout100"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setAutoDefault( FALSE );
    layout100->addWidget( QPBAnexar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setAutoDefault( FALSE );
    layout100->addWidget( QPBCancelar );
    layout101->addLayout( layout100 );

    QLCDNTotal = new QLCDNumber( this, "QLCDNTotal" );
    QLCDNTotal->setNumDigits( 7 );
    layout101->addWidget( QLCDNTotal );

    ProductoPracticaLayout->addMultiCellLayout( layout101, 1, 1, 0, 1 );

    layout97 = new QVBoxLayout( 0, 0, 6, "layout97"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout97->addWidget( textLabel5 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QCBProductos->sizePolicy().hasHeightForWidth() ) );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    layout97->addWidget( QCBProductos );

    ProductoPracticaLayout->addLayout( layout97, 0, 0 );

    layout104 = new QHBoxLayout( 0, 0, 6, "layout104"); 

    layout98 = new QVBoxLayout( 0, 0, 6, "layout98"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout98->addWidget( textLabel6 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout98->addWidget( QLECantidad );
    layout104->addLayout( layout98 );

    layout98_2 = new QVBoxLayout( 0, 0, 6, "layout98_2"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    textLabel6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6_2->sizePolicy().hasHeightForWidth() ) );
    layout98_2->addWidget( textLabel6_2 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    QLEExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEExistencia->sizePolicy().hasHeightForWidth() ) );
    QLEExistencia->setReadOnly( TRUE );
    layout98_2->addWidget( QLEExistencia );
    layout104->addLayout( layout98_2 );

    ProductoPracticaLayout->addLayout( layout104, 0, 1 );

    layout45 = new QVBoxLayout( 0, 0, 6, "layout45"); 

    textLabel8 = new QLabel( this, "textLabel8" );
    layout45->addWidget( textLabel8 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    layout45->addWidget( QLEDescripcion );

    ProductoPracticaLayout->addMultiCellLayout( layout45, 2, 2, 0, 1 );
    languageChange();
    resize( QSize(600, 297).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ProductoPractica::~ProductoPractica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ProductoPractica::languageChange()
{
    setCaption( tr( "Producto A La Practica" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel5->setText( tr( "Productos" ) );
    textLabel6->setText( tr( "Cantidad" ) );
    textLabel6_2->setText( tr( "Existencia" ) );
    textLabel8->setText( tr( "Descripcion" ) );
}

