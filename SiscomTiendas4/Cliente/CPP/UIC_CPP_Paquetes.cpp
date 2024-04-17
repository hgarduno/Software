/****************************************************************************
** Form implementation generated from reading ui file 'UI/Paquetes.ui'
**
** Created: Fri Apr 12 21:36:42 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Paquetes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <QCtrlProductos3Qt.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProductos3Qt.h"

/*
 *  Constructs a Paquetes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Paquetes::Paquetes( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Paquetes" );
    PaquetesLayout = new QGridLayout( this, 1, 1, 11, 6, "PaquetesLayout"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout12->addWidget( textLabel3 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio Venta" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio Total" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 5 );
    layout12->addWidget( QTDatos );

    PaquetesLayout->addLayout( layout12, 1, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel1_2 );

    QLEClave = new QLineEdit( this, "QLEClave" );
    layout9->addWidget( QLEClave );
    layout21->addLayout( layout9 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( textLabel2 );

    QTEDescripcionP = new QTextEdit( this, "QTEDescripcionP" );
    QTEDescripcionP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTEDescripcionP->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( QTEDescripcionP );
    layout21->addLayout( layout3 );
    layout22->addLayout( layout21 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductos3Qt( this, "QCtrProductos" );
    QCtrProductos->setEnabled( FALSE );
    layout1->addWidget( QCtrProductos );
    layout19->addLayout( layout1 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout17->addWidget( textLabel4 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout17->addWidget( QLECantidad );
    layout18->addLayout( layout17 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout18->addItem( spacer1 );
    layout19->addLayout( layout18 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout3_2->addWidget( textLabel2_2 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QTEDescripcion->sizePolicy().hasHeightForWidth() ) );
    QTEDescripcion->setReadOnly( TRUE );
    layout3_2->addWidget( QTEDescripcion );
    layout19->addLayout( layout3_2 );
    layout22->addLayout( layout19 );

    PaquetesLayout->addLayout( layout22, 0, 0 );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    layout23->addWidget( QPBRegistra );

    QPBRProductos = new QPushButton( this, "QPBRProductos" );
    layout23->addWidget( QPBRProductos );
    layout24->addLayout( layout23 );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    layout24->addWidget( QPBAnexar );

    pushButton3_3 = new QPushButton( this, "pushButton3_3" );
    layout24->addWidget( pushButton3_3 );
    layout25->addLayout( layout24 );

    lCDNumber1 = new QLCDNumber( this, "lCDNumber1" );
    layout25->addWidget( lCDNumber1 );

    PaquetesLayout->addLayout( layout25, 2, 0 );
    languageChange();
    resize( QSize(595, 530).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Paquetes::~Paquetes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Paquetes::languageChange()
{
    setCaption( tr( "Registro de paquetes de servicio" ) );
    textLabel3->setText( tr( "Productos Del Paquete" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Precio Venta" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Precio Total" ) );
    textLabel1_2->setText( tr( "Clave Del Paquete" ) );
    textLabel2->setText( tr( "Descripcion" ) );
    textLabel1->setText( tr( "Productos" ) );
    textLabel4->setText( tr( "Cantidad" ) );
    textLabel2_2->setText( tr( "Descripcion" ) );
    QPBRegistra->setText( tr( "Registra Paquete" ) );
    QPBRProductos->setText( tr( "Registra Productos" ) );
    QPBAnexar->setText( tr( "Anexa Producto" ) );
    pushButton3_3->setText( tr( "Asigna Precio" ) );
}

