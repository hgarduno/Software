/****************************************************************************
** Form implementation generated from reading ui file 'UI/MaterialAExpendio.ui'
**
** Created: Thu Dec 21 13:56:32 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_MaterialAExpendio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a MaterialAExpendio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
MaterialAExpendio::MaterialAExpendio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "MaterialAExpendio" );
    MaterialAExpendioLayout = new QGridLayout( this, 1, 1, 11, 6, "MaterialAExpendioLayout"); 

    layout67 = new QVBoxLayout( 0, 0, 6, "layout67"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout67->addWidget( textLabel1 );

    QLEMatriz = new QLineEdit( this, "QLEMatriz" );
    QLEMatriz->setReadOnly( TRUE );
    layout67->addWidget( QLEMatriz );

    MaterialAExpendioLayout->addMultiCellLayout( layout67, 0, 0, 0, 5 );

    layout67_2 = new QVBoxLayout( 0, 0, 6, "layout67_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout67_2->addWidget( textLabel1_2 );

    QLEExpendio = new QLineEdit( this, "QLEExpendio" );
    QLEExpendio->setReadOnly( TRUE );
    layout67_2->addWidget( QLEExpendio );

    MaterialAExpendioLayout->addMultiCellLayout( layout67_2, 2, 2, 0, 5 );

    layout71 = new QVBoxLayout( 0, 0, 6, "layout71"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout71->addWidget( textLabel3 );

    QCBProductos = new QComboBox( FALSE, this, "QCBProductos" );
    QCBProductos->setEnabled( FALSE );
    QCBProductos->setEditable( TRUE );
    QCBProductos->setInsertionPolicy( QComboBox::NoInsertion );
    QCBProductos->setAutoCompletion( TRUE );
    QCBProductos->setDuplicatesEnabled( FALSE );
    layout71->addWidget( QCBProductos );

    MaterialAExpendioLayout->addMultiCellLayout( layout71, 1, 1, 0, 3 );

    layout70 = new QVBoxLayout( 0, 0, 6, "layout70"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout70->addWidget( textLabel2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout70->addWidget( QLECantidad );

    MaterialAExpendioLayout->addLayout( layout70, 1, 5 );

    layout70_2 = new QVBoxLayout( 0, 0, 6, "layout70_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout70_2->addWidget( textLabel2_2 );

    QLEExistencia = new QLineEdit( this, "QLEExistencia" );
    QLEExistencia->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEExistencia->sizePolicy().hasHeightForWidth() ) );
    layout70_2->addWidget( QLEExistencia );

    MaterialAExpendioLayout->addLayout( layout70_2, 1, 4 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );

    MaterialAExpendioLayout->addMultiCellWidget( QTDatos, 3, 3, 0, 5 );

    layout60 = new QVBoxLayout( 0, 0, 6, "layout60"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout60->addWidget( textLabel1_2_2 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout60->addWidget( QLEDescripcion );

    MaterialAExpendioLayout->addMultiCellLayout( layout60, 4, 4, 0, 5 );

    QPBSelExpendio = new QPushButton( this, "QPBSelExpendio" );

    MaterialAExpendioLayout->addWidget( QPBSelExpendio, 5, 0 );

    QPBRegistraEnvio = new QPushButton( this, "QPBRegistraEnvio" );
    QPBRegistraEnvio->setEnabled( FALSE );

    MaterialAExpendioLayout->addMultiCellWidget( QPBRegistraEnvio, 5, 5, 4, 5 );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );

    MaterialAExpendioLayout->addWidget( QPBAnexar, 5, 1 );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    QPBEliminar->setEnabled( FALSE );

    MaterialAExpendioLayout->addWidget( QPBEliminar, 5, 2 );

    QPBCambiaCantidad = new QPushButton( this, "QPBCambiaCantidad" );
    QPBCambiaCantidad->setEnabled( FALSE );

    MaterialAExpendioLayout->addWidget( QPBCambiaCantidad, 5, 3 );
    languageChange();
    resize( QSize(729, 643).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MaterialAExpendio::~MaterialAExpendio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MaterialAExpendio::languageChange()
{
    setCaption( tr( "Transferencia A Expendios" ) );
    textLabel1->setText( tr( "Matriz" ) );
    textLabel1_2->setText( tr( "Expendio Trabajo" ) );
    textLabel3->setText( tr( "Productos" ) );
    textLabel2->setText( tr( "Cantidad" ) );
    textLabel2_2->setText( tr( "Existencia" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Existencia" ) );
    textLabel1_2_2->setText( tr( "Descripcion" ) );
    QPBSelExpendio->setText( tr( "Selecciona Expendio" ) );
    QPBRegistraEnvio->setText( tr( "Registrar Envio" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBEliminar->setText( tr( "Eliminar Producto" ) );
    QPBCambiaCantidad->setText( tr( "Cambia Cantidad" ) );
}

