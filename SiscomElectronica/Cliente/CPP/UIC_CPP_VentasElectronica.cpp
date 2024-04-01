/****************************************************************************
** Form implementation generated from reading ui file 'UI/VentasElectronica.ui'
**
** Created: Wed Jan 31 10:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_VentasElectronica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtoolbox.h>
#include <qiconview.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a VentasElectronica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
VentasElectronica::VentasElectronica( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "VentasElectronica" );
    VentasElectronicaLayout = new QGridLayout( this, 1, 1, 11, 6, "VentasElectronicaLayout"); 

    toolBox1 = new QToolBox( this, "toolBox1" );
    toolBox1->setFrameShape( QToolBox::NoFrame );
    toolBox1->setFrameShadow( QToolBox::Plain );
    toolBox1->setCurrentIndex( 0 );

    page1 = new QWidget( toolBox1, "page1" );
    page1->setBackgroundMode( QWidget::PaletteBackground );
    page1Layout = new QGridLayout( page1, 1, 1, 11, 6, "page1Layout"); 

    QIVOrdenes = new QIconView( page1, "QIVOrdenes" );

    page1Layout->addWidget( QIVOrdenes, 0, 0 );

    textLabel1 = new QLabel( page1, "textLabel1" );

    page1Layout->addWidget( textLabel1, 1, 0 );

    iconView2 = new QIconView( page1, "iconView2" );

    page1Layout->addWidget( iconView2, 2, 0 );
    toolBox1->addItem( page1, QString::fromLatin1("") );

    VentasElectronicaLayout->addMultiCellWidget( toolBox1, 2, 2, 0, 2 );

    QPBNOrden = new QPushButton( this, "QPBNOrden" );
    QPBNOrden->setMinimumSize( QSize( 0, 70 ) );

    VentasElectronicaLayout->addWidget( QPBNOrden, 0, 0 );

    QPBVenderTodo = new QPushButton( this, "QPBVenderTodo" );
    QPBVenderTodo->setMinimumSize( QSize( 0, 70 ) );

    VentasElectronicaLayout->addWidget( QPBVenderTodo, 0, 1 );

    QPBRPSinOrden = new QPushButton( this, "QPBRPSinOrden" );
    QPBRPSinOrden->setMinimumSize( QSize( 0, 70 ) );

    VentasElectronicaLayout->addWidget( QPBRPSinOrden, 1, 1 );

    QPBCotizaPractica = new QPushButton( this, "QPBCotizaPractica" );
    QPBCotizaPractica->setMinimumSize( QSize( 0, 70 ) );

    VentasElectronicaLayout->addWidget( QPBCotizaPractica, 1, 0 );
    languageChange();
    resize( QSize(217, 574).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
VentasElectronica::~VentasElectronica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void VentasElectronica::languageChange()
{
    setCaption( tr( "Sistema De Ventas" ) );
    textLabel1->setText( tr( "Productos Sin Orden" ) );
    toolBox1->setItemLabel( toolBox1->indexOf(page1), tr( "Ordenes Activas" ) );
    QPBNOrden->setText( tr( "Nueva \n"
"Orden" ) );
    QPBVenderTodo->setText( tr( "Vender \n"
"Todo" ) );
    QPBRPSinOrden->setText( tr( "Agrega \n"
"Producto \n"
"Sin Orden" ) );
    QPBCotizaPractica->setText( tr( "Cotiza\n"
"Practica" ) );
}

