/****************************************************************************
** Form implementation generated from reading ui file 'UI/CotizaDispositivos.ui'
**
** Created: Fri Apr 12 21:34:49 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CotizaDispositivos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CotizaDispositivos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CotizaDispositivos::CotizaDispositivos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CotizaDispositivos" );
    CotizaDispositivosLayout = new QGridLayout( this, 1, 1, 11, 6, "CotizaDispositivosLayout"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel1 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( QLECantidad );
    layout13->addLayout( layout8 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout9->addWidget( textLabel2 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout9->addWidget( QCBProductos );
    layout13->addLayout( layout9 );

    CotizaDispositivosLayout->addLayout( layout13, 0, 0 );

    layout99 = new QHBoxLayout( 0, 0, 6, "layout99"); 

    QPBAnexarOrden = new QPushButton( this, "QPBAnexarOrden" );
    QPBAnexarOrden->setEnabled( FALSE );
    layout99->addWidget( QPBAnexarOrden );

    QPBPDescripcion = new QPushButton( this, "QPBPDescripcion" );
    layout99->addWidget( QPBPDescripcion );

    pushButton22 = new QPushButton( this, "pushButton22" );
    layout99->addWidget( pushButton22 );

    CotizaDispositivosLayout->addLayout( layout99, 3, 0 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout10->addWidget( textLabel1_2 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setReadOnly( TRUE );
    layout10->addWidget( QLEDescripcion );

    CotizaDispositivosLayout->addLayout( layout10, 2, 0 );

    layout19 = new QHBoxLayout( 0, 0, 6, "layout19"); 

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    layout8_3 = new QVBoxLayout( 0, 0, 6, "layout8_3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout8_3->addWidget( textLabel1_3 );

    QLEPrcVenta = new QLineEdit( this, "QLEPrcVenta" );
    QLEPrcVenta->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPrcVenta->sizePolicy().hasHeightForWidth() ) );
    QLEPrcVenta->setReadOnly( TRUE );
    layout8_3->addWidget( QLEPrcVenta );
    layout18->addLayout( layout8_3 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout8_3_2 = new QVBoxLayout( 0, 0, 6, "layout8_3_2"); 

    textLabel1_3_2 = new QLabel( this, "textLabel1_3_2" );
    textLabel1_3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3_2->sizePolicy().hasHeightForWidth() ) );
    layout8_3_2->addWidget( textLabel1_3_2 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    QLEExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEExistencia->sizePolicy().hasHeightForWidth() ) );
    QLEExistencia->setEchoMode( QLineEdit::Normal );
    QLEExistencia->setReadOnly( TRUE );
    layout8_3_2->addWidget( QLEExistencia );
    layout17->addLayout( layout8_3_2 );

    layout8_3_2_2 = new QVBoxLayout( 0, 0, 6, "layout8_3_2_2"); 

    textLabel1_3_2_2 = new QLabel( this, "textLabel1_3_2_2" );
    textLabel1_3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel1_3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout8_3_2_2->addWidget( textLabel1_3_2_2 );

    QLEExistBodega = new QLineEdit( this, "QLEExistBodega" );
    QLEExistBodega->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLEExistBodega->sizePolicy().hasHeightForWidth() ) );
    QLEExistBodega->setEchoMode( QLineEdit::Normal );
    QLEExistBodega->setReadOnly( TRUE );
    layout8_3_2_2->addWidget( QLEExistBodega );
    layout17->addLayout( layout8_3_2_2 );
    layout18->addLayout( layout17 );
    layout19->addLayout( layout18 );

    QLCNTotal = new QLCDNumber( this, "QLCNTotal" );
    QLCNTotal->setNumDigits( 7 );
    layout19->addWidget( QLCNTotal );

    CotizaDispositivosLayout->addLayout( layout19, 1, 0 );
    languageChange();
    resize( QSize(405, 354).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CotizaDispositivos::~CotizaDispositivos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CotizaDispositivos::languageChange()
{
    setCaption( tr( "Cotizando Dispositivos" ) );
    textLabel1->setText( tr( "Cantidad" ) );
    QLECantidad->setText( tr( "1" ) );
    textLabel2->setText( tr( "Dispositivos" ) );
    QPBAnexarOrden->setText( tr( "Anexar A La Orden" ) );
    QPBPDescripcion->setText( tr( "Por Descripcion" ) );
    pushButton22->setText( tr( "Por Familia" ) );
    textLabel1_2->setText( tr( "Descripcion" ) );
    textLabel1_3->setText( tr( "Precio De Venta" ) );
    textLabel1_3_2->setText( tr( "Existencia" ) );
    textLabel1_3_2_2->setText( tr( "Bodegas" ) );
}

