/****************************************************************************
** Form implementation generated from reading ui file 'UI/CtrExistenciasMinimas.ui'
**
** Created: lun abr 1 19:07:39 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CtrExistenciasMinimas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a CtrExistenciasMinimas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CtrExistenciasMinimas::CtrExistenciasMinimas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CtrExistenciasMinimas" );
    CtrExistenciasMinimasLayout = new QGridLayout( this, 1, 1, 11, 6, "CtrExistenciasMinimasLayout"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

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
    layout13->addLayout( layout12 );

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( textLabel1 );

    QLEExistenciaM = new QLineEdit( this, "QLEExistenciaM" );
    QLEExistenciaM->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEExistenciaM->sizePolicy().hasHeightForWidth() ) );
    layout7->addWidget( QLEExistenciaM );
    layout13->addLayout( layout7 );

    CtrExistenciasMinimasLayout->addLayout( layout13, 0, 0 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia Minima" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 2 );
    QTDatos->setReadOnly( TRUE );

    CtrExistenciasMinimasLayout->addWidget( QTDatos, 1, 0 );

    layout72 = new QVBoxLayout( 0, 0, 6, "layout72"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout72->addWidget( textLabel1_2 );

    QLEDescripcion = new QTextEdit( this, "QLEDescripcion" );
    QLEDescripcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QLEDescripcion->sizePolicy().hasHeightForWidth() ) );
    layout72->addWidget( QLEDescripcion );

    CtrExistenciasMinimasLayout->addLayout( layout72, 2, 0 );

    layout13_2 = new QHBoxLayout( 0, 0, 6, "layout13_2"); 

    QPBAELista = new QPushButton( this, "QPBAELista" );
    layout13_2->addWidget( QPBAELista );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    layout13_2->addWidget( QPBEliminar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    layout13_2->addWidget( QPBActualizar );

    CtrExistenciasMinimasLayout->addLayout( layout13_2, 3, 0 );
    languageChange();
    resize( QSize(543, 541).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CtrExistenciasMinimas::~CtrExistenciasMinimas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CtrExistenciasMinimas::languageChange()
{
    setCaption( tr( "Controlador De Existencias Minimas" ) );
    textLabel2->setText( tr( "Productos" ) );
    textLabel1->setText( tr( "Existencia Minima" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Existencia Minima" ) );
    textLabel1_2->setText( tr( "Descripcion" ) );
    QPBAELista->setText( tr( "Asigna Existencia Minima A Productos" ) );
    QPBEliminar->setText( tr( "Eliminar" ) );
    QPBActualizar->setText( tr( "Actualizar Existencia Minima" ) );
}

