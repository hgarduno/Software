/****************************************************************************
** Form implementation generated from reading ui file 'UI/PuntoVenta.ui'
**
** Created: Wed Apr 10 20:52:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_PuntoVenta.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtextbrowser.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QCtrlProductosSE.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"

/*
 *  Constructs a PuntoVenta as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PuntoVenta::PuntoVenta( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PuntoVenta" );
    PuntoVentaLayout = new QGridLayout( this, 1, 1, 11, 6, "PuntoVentaLayout"); 

    QTBPuntoVenta = new QTextBrowser( this, "QTBPuntoVenta" );

    PuntoVentaLayout->addMultiCellWidget( QTBPuntoVenta, 1, 1, 0, 3 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout2->addWidget( textLabel1 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QLECantidad );
    layout4->addLayout( layout2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout3->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QCtrProductos );
    layout4->addLayout( layout3 );

    PuntoVentaLayout->addMultiCellLayout( layout4, 0, 0, 0, 3 );

    QPBCargaArchivoHtml = new QPushButton( this, "QPBCargaArchivoHtml" );

    PuntoVentaLayout->addWidget( QPBCargaArchivoHtml, 2, 0 );

    QPBDecrementaTexto = new QPushButton( this, "QPBDecrementaTexto" );

    PuntoVentaLayout->addWidget( QPBDecrementaTexto, 2, 3 );

    QPBIncrementaTexto = new QPushButton( this, "QPBIncrementaTexto" );

    PuntoVentaLayout->addWidget( QPBIncrementaTexto, 2, 2 );

    QPBAnexarOrden = new QPushButton( this, "QPBAnexarOrden" );

    PuntoVentaLayout->addWidget( QPBAnexarOrden, 2, 1 );
    languageChange();
    resize( QSize(726, 576).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PuntoVenta::~PuntoVenta()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PuntoVenta::languageChange()
{
    setCaption( tr( "Punto de Venta (Version 2)" ) );
    textLabel1->setText( tr( "Cantidad" ) );
    textLabel2->setText( tr( "Productos" ) );
    QPBCargaArchivoHtml->setText( tr( "Carga Archivo HTML" ) );
    QPBDecrementaTexto->setText( tr( "Decrementa" ) );
    QPBIncrementaTexto->setText( tr( "Incrementa Texto" ) );
    QPBAnexarOrden->setText( tr( "Anexar A La Orden" ) );
}

