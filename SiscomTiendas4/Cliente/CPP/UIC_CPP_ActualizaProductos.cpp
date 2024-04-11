/****************************************************************************
** Form implementation generated from reading ui file 'UI/ActualizaProductos.ui'
**
** Created: Thu Apr 11 20:30:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ActualizaProductos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <QCtrlProductos.h>
#include <QCtrlFamilias.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductos.h"
#include "QCtrlFamilias.h"

/*
 *  Constructs a ActualizaProductos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ActualizaProductos::ActualizaProductos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ActualizaProductos" );
    ActualizaProductosLayout = new QGridLayout( this, 1, 1, 11, 6, "ActualizaProductosLayout"); 

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel3 = new QLabel( groupBox1, "textLabel3" );
    layout2->addWidget( textLabel3 );

    QLEProducto = new QLineEdit( groupBox1, "QLEProducto" );
    QLEProducto->setReadOnly( TRUE );
    layout2->addWidget( QLEProducto );

    groupBox1Layout->addLayout( layout2, 0, 0 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel3_2 = new QLabel( groupBox1, "textLabel3_2" );
    layout2_2->addWidget( textLabel3_2 );

    QLEFamilia = new QLineEdit( groupBox1, "QLEFamilia" );
    QLEFamilia->setReadOnly( TRUE );
    layout2_2->addWidget( QLEFamilia );

    groupBox1Layout->addLayout( layout2_2, 0, 1 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel4 = new QLabel( groupBox1, "textLabel4" );
    layout5->addWidget( textLabel4 );

    QTEDscProducto = new QTextEdit( groupBox1, "QTEDscProducto" );
    QTEDscProducto->setReadOnly( TRUE );
    layout5->addWidget( QTEDscProducto );

    groupBox1Layout->addLayout( layout5, 1, 0 );

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel4_2 = new QLabel( groupBox1, "textLabel4_2" );
    layout6->addWidget( textLabel4_2 );

    QTEDscFamilia = new QTextEdit( groupBox1, "QTEDscFamilia" );
    QTEDscFamilia->setReadOnly( TRUE );
    layout6->addWidget( QTEDscFamilia );

    groupBox1Layout->addLayout( layout6, 1, 1 );

    ActualizaProductosLayout->addWidget( groupBox1, 1, 0 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QCtrProductos = new QCtrlProductos( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrProductos );
    layout7->addLayout( layout1 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout7->addItem( spacer2 );

    ActualizaProductosLayout->addLayout( layout7, 0, 0 );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( FALSE );

    ActualizaProductosLayout->addWidget( QPBActualizar, 3, 0 );

    groupBox2 = new QGroupBox( this, "groupBox2" );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel6 = new QLabel( groupBox2, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel6 );

    QCtrFamilias = new QCtrlFamilias( groupBox2, "QCtrFamilias" );
    QCtrFamilias->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrFamilias->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( QCtrFamilias );

    groupBox2Layout->addLayout( layout9, 0, 0 );

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel3_3 = new QLabel( groupBox2, "textLabel3_3" );
    layout15->addWidget( textLabel3_3 );

    QTEDsc = new QTextEdit( groupBox2, "QTEDsc" );
    QTEDsc->setEnabled( FALSE );
    layout15->addWidget( QTEDsc );

    groupBox2Layout->addMultiCellLayout( layout15, 2, 2, 0, 1 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel5 = new QLabel( groupBox2, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel5 );

    QLEClave = new QLineEdit( groupBox2, "QLEClave" );
    QLEClave->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEClave->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( QLEClave );

    groupBox2Layout->addLayout( layout8, 0, 1 );

    layout16 = new QVBoxLayout( 0, 0, 6, "layout16"); 

    textLabel7 = new QLabel( groupBox2, "textLabel7" );
    layout16->addWidget( textLabel7 );

    QLEFamSeleccionada = new QLineEdit( groupBox2, "QLEFamSeleccionada" );
    QLEFamSeleccionada->setReadOnly( TRUE );
    layout16->addWidget( QLEFamSeleccionada );

    groupBox2Layout->addMultiCellLayout( layout16, 1, 1, 0, 1 );

    ActualizaProductosLayout->addWidget( groupBox2, 2, 0 );
    languageChange();
    resize( QSize(600, 567).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( QTEDscProducto, QLEFamilia );
    setTabOrder( QLEFamilia, QLEProducto );
    setTabOrder( QLEProducto, QLEClave );
    setTabOrder( QLEClave, QTEDscFamilia );
    setTabOrder( QTEDscFamilia, QPBActualizar );
    setTabOrder( QPBActualizar, QTEDsc );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ActualizaProductos::~ActualizaProductos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ActualizaProductos::languageChange()
{
    setCaption( tr( "Actualiza Datos Del Producto" ) );
    groupBox1->setTitle( tr( "Datos De Registro Del Producto" ) );
    textLabel3->setText( tr( "Producto" ) );
    textLabel3_2->setText( tr( "Familia" ) );
    textLabel4->setText( tr( "Descripcion Producto" ) );
    textLabel4_2->setText( tr( "Descripcion Familia" ) );
    textLabel1->setText( tr( "Productos" ) );
    QPBActualizar->setText( tr( "Registra Actualizacion" ) );
    groupBox2->setTitle( tr( "Captura Actualizacion" ) );
    textLabel6->setText( tr( "Familia" ) );
    textLabel3_3->setText( tr( "Descripcion" ) );
    textLabel5->setText( tr( "Clave" ) );
    textLabel7->setText( tr( "Familia" ) );
}

