/****************************************************************************
** Form implementation generated from reading ui file 'UI/SalidaMaterial.ui'
**
** Created: Thu Dec 21 12:53:42 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SalidaMaterial.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a SalidaMaterial as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
SalidaMaterial::SalidaMaterial( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "SalidaMaterial" );
    SalidaMaterialLayout = new QGridLayout( this, 1, 1, 11, 6, "SalidaMaterialLayout"); 

    layout72 = new QVBoxLayout( 0, 0, 6, "layout72"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout72->addWidget( textLabel1_2 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout72->addWidget( QLEDescripcion );

    SalidaMaterialLayout->addLayout( layout72, 2, 0 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    layout18->addWidget( QPBAnexar );

    QPBElimina = new QPushButton( this, "QPBElimina" );
    layout18->addWidget( QPBElimina );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout18->addWidget( QPBRegistrar );

    SalidaMaterialLayout->addLayout( layout18, 3, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 2 );
    QTDatos->setReadOnly( FALSE );

    SalidaMaterialLayout->addWidget( QTDatos, 1, 0 );

    layout22 = new QHBoxLayout( 0, 0, 6, "layout22"); 

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout16->addWidget( textLabel2_2 );

    QCBMotivos = new QComboBox( FALSE, this, "QCBMotivos" );
    QCBMotivos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCBMotivos->sizePolicy().hasHeightForWidth() ) );
    QCBMotivos->setEditable( TRUE );
    QCBMotivos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBMotivos->setAutoCompletion( TRUE );
    QCBMotivos->setDuplicatesEnabled( FALSE );
    layout16->addWidget( QCBMotivos );
    layout22->addLayout( layout16 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout13->addWidget( textLabel1 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    layout13->addWidget( QLECantidad );
    layout22->addLayout( layout13 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout12->addWidget( textLabel2 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCBProductos->sizePolicy().hasHeightForWidth() ) );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout12->addWidget( QCBProductos );
    layout22->addLayout( layout12 );

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( textLabel3 );

    QLCDNExistencia = new QLCDNumber( this, "QLCDNExistencia" );
    QLCDNExistencia->setNumDigits( 10 );
    layout19->addWidget( QLCDNExistencia );
    layout22->addLayout( layout19 );

    layout19_2 = new QVBoxLayout( 0, 0, 6, "layout19_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout19_2->addWidget( textLabel3_2 );

    QLCDNExistenciaBodega = new QLCDNumber( this, "QLCDNExistenciaBodega" );
    QLCDNExistenciaBodega->setNumDigits( 10 );
    layout19_2->addWidget( QLCDNExistenciaBodega );
    layout22->addLayout( layout19_2 );

    SalidaMaterialLayout->addLayout( layout22, 0, 0 );
    languageChange();
    resize( QSize(921, 556).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SalidaMaterial::~SalidaMaterial()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SalidaMaterial::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1_2->setText( tr( "Descripcion" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBElimina->setText( tr( "Elimina" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    textLabel2_2->setText( tr( "Motivos" ) );
    textLabel1->setText( tr( "Cantidad" ) );
    QLECantidad->setText( tr( "1" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel3->setText( tr( "Existencia" ) );
    textLabel3_2->setText( tr( "Existencia Bodega" ) );
}

