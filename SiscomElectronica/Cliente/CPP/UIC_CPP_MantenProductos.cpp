/****************************************************************************
** Form implementation generated from reading ui file 'UI/MantenProductos.ui'
**
** Created: Wed Apr 10 21:11:44 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_MantenProductos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a MantenProductos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
MantenProductos::MantenProductos( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "MantenProductos" );
    MantenProductosLayout = new QGridLayout( this, 1, 1, 11, 6, "MantenProductosLayout"); 

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout27->addWidget( textLabel1 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout27->addWidget( QCBProductos );
    layout28->addLayout( layout27 );
    spacer18_2 = new QSpacerItem( 50, 20, QSizePolicy::Minimum, QSizePolicy::Minimum );
    layout28->addItem( spacer18_2 );

    MantenProductosLayout->addLayout( layout28, 0, 0 );

    textLabel2_3 = new QLabel( this, "textLabel2_3" );

    MantenProductosLayout->addWidget( textLabel2_3, 1, 0 );

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    QPBModificar = new QPushButton( this, "QPBModificar" );
    QPBModificar->setMinimumSize( QSize( 0, 70 ) );
    QPBModificar->setMaximumSize( QSize( 32767, 70 ) );
    QPBModificar->setAutoDefault( FALSE );
    layout37->addWidget( QPBModificar );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setMinimumSize( QSize( 0, 70 ) );
    QPBCancelar->setMaximumSize( QSize( 32767, 70 ) );
    QPBCancelar->setAutoDefault( FALSE );
    layout37->addWidget( QPBCancelar );

    MantenProductosLayout->addLayout( layout37, 6, 0 );

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( textLabel4 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( QLEDescripcion );

    MantenProductosLayout->addLayout( layout23, 5, 0 );

    layout16 = new QHBoxLayout( 0, 0, 6, "layout16"); 

    layout35 = new QVBoxLayout( 0, 0, 6, "layout35"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout35->addWidget( textLabel2 );

    QCBFamilias = new QComboBox( FALSE, this, "QCBFamilias" );
    QCBFamilias->setMinimumSize( QSize( 200, 0 ) );
    QCBFamilias->setEditable( TRUE );
    QCBFamilias->setInsertionPolicy( QComboBox::NoInsertion );
    QCBFamilias->setAutoCompletion( TRUE );
    QCBFamilias->setDuplicatesEnabled( FALSE );
    layout35->addWidget( QCBFamilias );
    layout16->addLayout( layout35 );

    layout35_2 = new QVBoxLayout( 0, 0, 6, "layout35_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout35_2->addWidget( textLabel2_2 );

    QCBUnidades = new QComboBox( FALSE, this, "QCBUnidades" );
    QCBUnidades->setMinimumSize( QSize( 200, 0 ) );
    QCBUnidades->setEditable( TRUE );
    QCBUnidades->setInsertionPolicy( QComboBox::NoInsertion );
    QCBUnidades->setAutoCompletion( TRUE );
    QCBUnidades->setDuplicatesEnabled( FALSE );
    layout35_2->addWidget( QCBUnidades );
    layout16->addLayout( layout35_2 );

    layout36_2 = new QVBoxLayout( 0, 0, 6, "layout36_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout36_2->addWidget( textLabel3_2 );

    QLEAbreviatura = new QLineEdit( this, "QLEAbreviatura" );
    QLEAbreviatura->setReadOnly( TRUE );
    layout36_2->addWidget( QLEAbreviatura );
    layout16->addLayout( layout36_2 );
    spacer18 = new QSpacerItem( 60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout16->addItem( spacer18 );

    MantenProductosLayout->addLayout( layout16, 4, 0 );

    textLabel2_3_2 = new QLabel( this, "textLabel2_3_2" );

    MantenProductosLayout->addWidget( textLabel2_3_2, 3, 0 );

    layout136 = new QHBoxLayout( 0, 0, 6, "layout136"); 

    layout88 = new QVBoxLayout( 0, 0, 6, "layout88"); 

    layout86 = new QVBoxLayout( 0, 0, 6, "layout86"); 

    layout39 = new QVBoxLayout( 0, 0, 6, "layout39"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout39->addWidget( textLabel3 );

    QLEFamilia = new QLineEdit( this, "QLEFamilia" );
    QLEFamilia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEFamilia->sizePolicy().hasHeightForWidth() ) );
    QLEFamilia->setMinimumSize( QSize( 200, 0 ) );
    QLEFamilia->setReadOnly( TRUE );
    layout39->addWidget( QLEFamilia );
    layout86->addLayout( layout39 );

    layout39_2 = new QVBoxLayout( 0, 0, 6, "layout39_2"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    textLabel3_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_3->sizePolicy().hasHeightForWidth() ) );
    layout39_2->addWidget( textLabel3_3 );

    QLEUnidades = new QLineEdit( this, "QLEUnidades" );
    QLEUnidades->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEUnidades->sizePolicy().hasHeightForWidth() ) );
    QLEUnidades->setReadOnly( TRUE );
    layout39_2->addWidget( QLEUnidades );
    layout86->addLayout( layout39_2 );
    layout88->addLayout( layout86 );
    spacer10 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout88->addItem( spacer10 );
    layout136->addLayout( layout88 );

    layout85 = new QVBoxLayout( 0, 0, 6, "layout85"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout85->addWidget( textLabel4_2 );

    QLEDescripcionB = new QTextEdit( this, "QLEDescripcionB" );
    QLEDescripcionB->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLEDescripcionB->sizePolicy().hasHeightForWidth() ) );
    layout85->addWidget( QLEDescripcionB );
    layout136->addLayout( layout85 );

    MantenProductosLayout->addLayout( layout136, 2, 0 );
    languageChange();
    resize( QSize(600, 544).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MantenProductos::~MantenProductos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MantenProductos::languageChange()
{
    setCaption( tr( "Mantenimiento De Productos" ) );
    textLabel1->setText( tr( "Producto" ) );
    textLabel2_3->setText( tr( "Datos Actuales" ) );
    QPBModificar->setText( tr( "Modificar \n"
"Producto" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    textLabel4->setText( tr( "Descripcion" ) );
    textLabel2->setText( tr( "Familias" ) );
    textLabel2_2->setText( tr( "Unidades" ) );
    textLabel3_2->setText( tr( "Abreviatura" ) );
    textLabel2_3_2->setText( tr( "Datos para modificar" ) );
    textLabel3->setText( tr( "Familia" ) );
    textLabel3_3->setText( tr( "Unidades" ) );
    textLabel4_2->setText( tr( "Descripcion" ) );
}

