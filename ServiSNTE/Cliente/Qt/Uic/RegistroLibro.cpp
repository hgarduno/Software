/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/RegistroLibro.ui'
**
** Created: Sat Jan 27 16:38:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "RegistroLibro.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSS.h"
#include "QCtrlConceptosExistencias.h"

/*
 *  Constructs a RegistroLibro as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroLibro::RegistroLibro( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroLibro" );
    RegistroLibroLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroLibroLayout"); 

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    lineEdit1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( lineEdit1 );
    layout11->addLayout( layout1 );

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    lineEdit1_2 = new QLineEdit( this, "lineEdit1_2" );
    lineEdit1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2->addWidget( lineEdit1_2 );
    layout11->addLayout( layout1_2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout3->addWidget( textLabel2 );

    ctrlProveedoresSS1 = new QCtrlProveedoresSS( this, "ctrlProveedoresSS1" );
    ctrlProveedoresSS1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, ctrlProveedoresSS1->sizePolicy().hasHeightForWidth() ) );
    layout3->addWidget( ctrlProveedoresSS1 );
    layout11->addLayout( layout3 );

    RegistroLibroLayout->addMultiCellLayout( layout11, 0, 0, 0, 2 );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout6 = new QVBoxLayout( 0, 0, 6, "layout6"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout6->addWidget( textLabel5 );

    lineEdit3 = new QLineEdit( this, "lineEdit3" );
    layout6->addWidget( lineEdit3 );
    layout13->addLayout( layout6 );

    layout6_2 = new QVBoxLayout( 0, 0, 6, "layout6_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    layout6_2->addWidget( textLabel5_2 );

    lineEdit3_2 = new QLineEdit( this, "lineEdit3_2" );
    layout6_2->addWidget( lineEdit3_2 );
    layout13->addLayout( layout6_2 );

    layout6_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_2_2"); 

    textLabel5_2_2 = new QLabel( this, "textLabel5_2_2" );
    layout6_2_2->addWidget( textLabel5_2_2 );

    lineEdit3_2_2 = new QLineEdit( this, "lineEdit3_2_2" );
    layout6_2_2->addWidget( lineEdit3_2_2 );
    layout13->addLayout( layout6_2_2 );

    layout6_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_2_2_2"); 

    textLabel5_2_2_2 = new QLabel( this, "textLabel5_2_2_2" );
    layout6_2_2_2->addWidget( textLabel5_2_2_2 );

    lineEdit3_2_2_2 = new QLineEdit( this, "lineEdit3_2_2_2" );
    layout6_2_2_2->addWidget( lineEdit3_2_2_2 );
    layout13->addLayout( layout6_2_2_2 );

    layout6_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout6_2_2_2_2"); 

    textLabel5_2_2_2_2 = new QLabel( this, "textLabel5_2_2_2_2" );
    layout6_2_2_2_2->addWidget( textLabel5_2_2_2_2 );

    lineEdit3_2_2_2_2 = new QLineEdit( this, "lineEdit3_2_2_2_2" );
    layout6_2_2_2_2->addWidget( lineEdit3_2_2_2_2 );
    layout13->addLayout( layout6_2_2_2_2 );

    RegistroLibroLayout->addMultiCellLayout( layout13, 2, 2, 0, 2 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    layout4 = new QVBoxLayout( 0, 0, 6, "layout4"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    layout4->addWidget( textLabel3 );

    ctrlConceptosExistencias1 = new QCtrlConceptosExistencias( this, "ctrlConceptosExistencias1" );
    layout4->addWidget( ctrlConceptosExistencias1 );
    layout12->addLayout( layout4 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout5->addWidget( textLabel4 );

    comboBox1 = new QComboBox( FALSE, this, "comboBox1" );
    layout5->addWidget( comboBox1 );
    layout12->addLayout( layout5 );

    RegistroLibroLayout->addMultiCellLayout( layout12, 1, 1, 0, 2 );

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout14->addWidget( textLabel6 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "#Proveedor" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Razon Social" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Libro" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Aplicacion" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Tip/Doc" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Ser" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Folio" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Fecha" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Importe" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Sts" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 10 );
    layout14->addWidget( table1 );

    RegistroLibroLayout->addMultiCellLayout( layout14, 3, 3, 0, 2 );

    pushButton1 = new QPushButton( this, "pushButton1" );

    RegistroLibroLayout->addWidget( pushButton1, 4, 0 );

    pushButton2 = new QPushButton( this, "pushButton2" );

    RegistroLibroLayout->addWidget( pushButton2, 4, 1 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );

    RegistroLibroLayout->addWidget( QPBImprimir, 4, 2 );
    languageChange();
    resize( QSize(590, 471).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroLibro::~RegistroLibro()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroLibro::languageChange()
{
    setCaption( tr( "Registro de Libro" ) );
    textLabel1->setText( tr( "Libro" ) );
    textLabel1_2->setText( tr( "Folio" ) );
    textLabel2->setText( tr( "Proveedores" ) );
    textLabel5->setText( tr( "Serie" ) );
    textLabel5_2->setText( tr( "Folio" ) );
    textLabel5_2_2->setText( tr( "Fecha de Documento" ) );
    textLabel5_2_2_2->setText( tr( "Fecha De Venc" ) );
    textLabel5_2_2_2_2->setText( tr( "Importe" ) );
    textLabel3->setText( tr( "Conceptos" ) );
    textLabel4->setText( tr( "Tipo Documento" ) );
    comboBox1->clear();
    comboBox1->insertItem( tr( "002 - Remision Proveedor" ) );
    textLabel6->setText( tr( "Libros Registrados" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "#Proveedor" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Razon Social" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "Libro" ) );
    table1->horizontalHeader()->setLabel( 3, tr( "Aplicacion" ) );
    table1->horizontalHeader()->setLabel( 4, tr( "Tip/Doc" ) );
    table1->horizontalHeader()->setLabel( 5, tr( "Ser" ) );
    table1->horizontalHeader()->setLabel( 6, tr( "Folio" ) );
    table1->horizontalHeader()->setLabel( 7, tr( "Fecha" ) );
    table1->horizontalHeader()->setLabel( 8, tr( "Importe" ) );
    table1->horizontalHeader()->setLabel( 9, tr( "Sts" ) );
    pushButton1->setText( tr( "Registro de Libro" ) );
    pushButton2->setText( tr( "Modificar Libro" ) );
    QPBImprimir->setText( tr( "Imprimir Reporte Cuentas por pagar" ) );
}

