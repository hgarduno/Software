/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorPracticas.ui'
**
** Created: lun abr 1 18:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorPracticas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlProductosSE.h>
#include <qlineedit.h>
#include <qtable.h>
#include <QCtrlEscuelasSE.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProductosSE.h"
#include "QCtrlEscuelasSE.h"

/*
 *  Constructs a ManejadorPracticas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorPracticas::ManejadorPracticas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorPracticas" );
    ManejadorPracticasLayout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorPracticasLayout"); 

    layout20 = new QHBoxLayout( 0, 0, 6, "layout20"); 

    layout18 = new QVBoxLayout( 0, 0, 6, "layout18"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout18->addWidget( textLabel4 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout18->addWidget( QCtrProductos );
    layout20->addLayout( layout18 );

    layout8 = new QVBoxLayout( 0, 0, 6, "layout8"); 

    textLabel3_2 = new QLabel( this, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( textLabel3_2 );

    QLECantidad = new QLineEdit( this, "QLECantidad" );
    QLECantidad->setEnabled( FALSE );
    QLECantidad->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLECantidad->sizePolicy().hasHeightForWidth() ) );
    layout8->addWidget( QLECantidad );
    layout20->addLayout( layout8 );

    ManejadorPracticasLayout->addMultiCellLayout( layout20, 3, 3, 0, 3 );

    QTProductos = new QTable( this, "QTProductos" );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Producto" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Cantidad" ) );
    QTProductos->setNumCols( QTProductos->numCols() + 1 );
    QTProductos->horizontalHeader()->setLabel( QTProductos->numCols() - 1, tr( "Observaciones" ) );
    QTProductos->setNumRows( 0 );
    QTProductos->setNumCols( 3 );
    QTProductos->setReadOnly( TRUE );

    ManejadorPracticasLayout->addMultiCellWidget( QTProductos, 4, 4, 0, 3 );

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCtrEscuelas = new QCtrlEscuelasSE( this, "QCtrEscuelas" );
    QCtrEscuelas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrEscuelas->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCtrEscuelas );

    ManejadorPracticasLayout->addLayout( layout1, 0, 3 );

    layout2_3 = new QVBoxLayout( 0, 0, 6, "layout2_3"); 

    textLabel2_3 = new QLabel( this, "textLabel2_3" );
    textLabel2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, textLabel2_3->sizePolicy().hasHeightForWidth() ) );
    layout2_3->addWidget( textLabel2_3 );

    QLECvePractica = new QLineEdit( this, "QLECvePractica" );
    QLECvePractica->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, QLECvePractica->sizePolicy().hasHeightForWidth() ) );
    layout2_3->addWidget( QLECvePractica );

    ManejadorPracticasLayout->addLayout( layout2_3, 0, 0 );

    layout2_2 = new QVBoxLayout( 0, 0, 6, "layout2_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout2_2->addWidget( textLabel2_2 );

    QLEMateria = new QLineEdit( this, "QLEMateria" );
    layout2_2->addWidget( QLEMateria );

    ManejadorPracticasLayout->addLayout( layout2_2, 0, 2 );

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    QPBSeleccionaPractica = new QPushButton( this, "QPBSeleccionaPractica" );
    QPBSeleccionaPractica->setEnabled( TRUE );
    layout25->addWidget( QPBSeleccionaPractica );

    QPBRegistraPractica = new QPushButton( this, "QPBRegistraPractica" );
    QPBRegistraPractica->setEnabled( TRUE );
    layout25->addWidget( QPBRegistraPractica );

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout25->addWidget( QPBAnexar );

    QPBEliminaProducto = new QPushButton( this, "QPBEliminaProducto" );
    QPBEliminaProducto->setEnabled( FALSE );
    layout25->addWidget( QPBEliminaProducto );

    QPBRegistraProductos = new QPushButton( this, "QPBRegistraProductos" );
    QPBRegistraProductos->setEnabled( FALSE );
    layout25->addWidget( QPBRegistraProductos );

    ManejadorPracticasLayout->addMultiCellLayout( layout25, 5, 5, 0, 3 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QLENombrePractica = new QLineEdit( this, "QLENombrePractica" );
    layout2->addWidget( QLENombrePractica );

    ManejadorPracticasLayout->addLayout( layout2, 0, 1 );

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout4->addWidget( textLabel3 );

    QTEDescripcion = new QTextEdit( this, "QTEDescripcion" );
    QTEDescripcion->setReadOnly( TRUE );
    layout4->addWidget( QTEDescripcion );

    ManejadorPracticasLayout->addMultiCellLayout( layout4, 2, 2, 0, 1 );

    layout4_2 = new QVBoxLayout( 0, 0, 6, "layout4_2"); 

    textLabel3_3 = new QLabel( this, "textLabel3_3" );
    layout4_2->addWidget( textLabel3_3 );

    QTEObservaciones = new QTextEdit( this, "QTEObservaciones" );
    layout4_2->addWidget( QTEObservaciones );

    ManejadorPracticasLayout->addMultiCellLayout( layout4_2, 2, 2, 2, 3 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    layout2_4 = new QVBoxLayout( 0, 0, 6, "layout2_4"); 

    textLabel2_4 = new QLabel( this, "textLabel2_4" );
    layout2_4->addWidget( textLabel2_4 );

    QLENombre = new QLineEdit( this, "QLENombre" );
    layout2_4->addWidget( QLENombre );
    layout14->addLayout( layout2_4 );

    layout2_4_2 = new QVBoxLayout( 0, 0, 6, "layout2_4_2"); 

    textLabel2_4_2 = new QLabel( this, "textLabel2_4_2" );
    layout2_4_2->addWidget( textLabel2_4_2 );

    QLEAPaterno = new QLineEdit( this, "QLEAPaterno" );
    layout2_4_2->addWidget( QLEAPaterno );
    layout14->addLayout( layout2_4_2 );

    layout2_4_2_2 = new QVBoxLayout( 0, 0, 6, "layout2_4_2_2"); 

    textLabel2_4_2_2 = new QLabel( this, "textLabel2_4_2_2" );
    layout2_4_2_2->addWidget( textLabel2_4_2_2 );

    QLEAMaterno = new QLineEdit( this, "QLEAMaterno" );
    layout2_4_2_2->addWidget( QLEAMaterno );
    layout14->addLayout( layout2_4_2_2 );

    ManejadorPracticasLayout->addMultiCellLayout( layout14, 1, 1, 0, 3 );
    languageChange();
    resize( QSize(539, 585).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorPracticas::~ManejadorPracticas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorPracticas::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel4->setText( tr( "Productos" ) );
    textLabel3_2->setText( tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTProductos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTProductos->horizontalHeader()->setLabel( 2, tr( "Observaciones" ) );
    textLabel1->setText( tr( "Escuelas" ) );
    textLabel2_3->setText( tr( "Clave Practica" ) );
    textLabel2_2->setText( tr( "Materia" ) );
    QPBSeleccionaPractica->setText( tr( "Selecciona Practica" ) );
    QPBRegistraPractica->setText( tr( "Registra Practica" ) );
    QPBAnexar->setText( tr( "Anexar Producto" ) );
    QPBEliminaProducto->setText( tr( "Eliminar Producto" ) );
    QPBRegistraProductos->setText( tr( "Registra Productos" ) );
    textLabel2->setText( tr( "Nombre de La Practica" ) );
    textLabel3->setText( tr( "Descripcion Practica" ) );
    textLabel3_3->setText( tr( "Observaciones" ) );
    textLabel2_4->setText( tr( "Nombre" ) );
    textLabel2_4_2->setText( tr( "Apellido Paterno" ) );
    textLabel2_4_2_2->setText( tr( "Apellido Materno" ) );
}

