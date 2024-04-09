/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorProductos.ui'
**
** Created: lun abr 1 19:07:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorProductos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ManejadorProductos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorProductos::ManejadorProductos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorProductos" );
    ManejadorProductosLayout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorProductosLayout"); 

    layout30 = new QVBoxLayout( 0, 0, 6, "layout30"); 

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

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
    layout28->addLayout( layout35 );

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
    layout28->addLayout( layout35_2 );

    layout36_2 = new QVBoxLayout( 0, 0, 6, "layout36_2"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout36_2->addWidget( textLabel3_2 );

    QLEAbreviatura = new QLineEdit( this, "QLEAbreviatura" );
    layout36_2->addWidget( QLEAbreviatura );
    layout28->addLayout( layout36_2 );
    layout30->addLayout( layout28 );

    layout27 = new QHBoxLayout( 0, 0, 6, "layout27"); 

    layout36 = new QVBoxLayout( 0, 0, 6, "layout36"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout36->addWidget( textLabel3 );

    QLEProducto = new QLineEdit( this, "QLEProducto" );
    layout36->addWidget( QLEProducto );
    layout27->addLayout( layout36 );

    layout24_2 = new QVBoxLayout( 0, 0, 6, "layout24_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout24_2->addWidget( textLabel1_2 );

    QLENClave = new QLineEdit( this, "QLENClave" );
    QLENClave->setReadOnly( TRUE );
    layout24_2->addWidget( QLENClave );
    layout27->addLayout( layout24_2 );

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout24->addWidget( textLabel1 );

    QLENCDescripcion = new QLineEdit( this, "QLENCDescripcion" );
    QLENCDescripcion->setReadOnly( TRUE );
    layout24->addWidget( QLENCDescripcion );
    layout27->addLayout( layout24 );
    layout30->addLayout( layout27 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout13->addWidget( textLabel4 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    layout13->addWidget( QLEDescripcion );
    layout30->addLayout( layout13 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Descripcion" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Familia" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Unidades" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 4 );
    layout30->addWidget( QTDatos );

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    QPBAnexar->setMinimumSize( QSize( 0, 70 ) );
    QPBAnexar->setMaximumSize( QSize( 32767, 70 ) );
    layout29->addWidget( QPBAnexar );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    QPBRegistrar->setMinimumSize( QSize( 0, 70 ) );
    QPBRegistrar->setMaximumSize( QSize( 32767, 70 ) );
    layout29->addWidget( QPBRegistrar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setMinimumSize( QSize( 0, 70 ) );
    QPBEliminar->setMaximumSize( QSize( 32767, 70 ) );
    layout29->addWidget( QPBEliminar );

    QPBMDatos = new QPushButton( this, "QPBMDatos" );
    QPBMDatos->setMinimumSize( QSize( 0, 70 ) );
    QPBMDatos->setMaximumSize( QSize( 32767, 70 ) );
    layout29->addWidget( QPBMDatos );

    QPBModEliClave = new QPushButton( this, "QPBModEliClave" );
    QPBModEliClave->setMinimumSize( QSize( 0, 70 ) );
    QPBModEliClave->setMaximumSize( QSize( 32767, 70 ) );
    layout29->addWidget( QPBModEliClave );
    layout30->addLayout( layout29 );

    ManejadorProductosLayout->addLayout( layout30, 0, 0 );
    languageChange();
    resize( QSize(795, 535).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorProductos::~ManejadorProductos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorProductos::languageChange()
{
    setCaption( tr( "Manejador De Productos" ) );
    textLabel2->setText( tr( "Familias" ) );
    textLabel2_2->setText( tr( "Unidades" ) );
    textLabel3_2->setText( tr( "Abreviatura" ) );
    textLabel3->setText( tr( "Producto" ) );
    textLabel1_2->setText( tr( "# Caracteres Clave" ) );
    textLabel1->setText( tr( "# Caracteres Descripcion" ) );
    textLabel4->setText( tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Familia" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Unidades" ) );
    QPBAnexar->setText( tr( "Anexar\n"
"Producto" ) );
    QPBRegistrar->setText( tr( "Registrar\n"
"Productos" ) );
    QPBEliminar->setText( tr( "Eliminar De\n"
" La Lista" ) );
    QPBMDatos->setText( tr( "Modifica\n"
"Datos Del \n"
"Producto" ) );
    QPBModEliClave->setText( tr( "Modificar / Eliminar\n"
"Clave Del Producto" ) );
}

