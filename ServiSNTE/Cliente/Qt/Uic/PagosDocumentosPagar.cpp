/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/PagosDocumentosPagar.ui'
**
** Created: Sat Jan 27 16:38:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "PagosDocumentosPagar.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSS.h"

/*
 *  Constructs a PagosDocumentosPagar as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
PagosDocumentosPagar::PagosDocumentosPagar( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "PagosDocumentosPagar" );
    PagosDocumentosPagarLayout = new QGridLayout( this, 1, 1, 11, 6, "PagosDocumentosPagarLayout"); 

    layout14 = new QVBoxLayout( 0, 0, 6, "layout14"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout14->addWidget( textLabel6 );

    table1 = new QTable( this, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Sec" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Libro" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Aplicacion" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Factura" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Fecha" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Imp Aplicacion" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Imp Pago" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Sts" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 8 );
    layout14->addWidget( table1 );

    PagosDocumentosPagarLayout->addLayout( layout14, 1, 0 );

    layout30 = new QHBoxLayout( 0, 0, 6, "layout30"); 

    pushButton1 = new QPushButton( this, "pushButton1" );
    layout30->addWidget( pushButton1 );

    pushButton2 = new QPushButton( this, "pushButton2" );
    layout30->addWidget( pushButton2 );

    QPBImprimir = new QPushButton( this, "QPBImprimir" );
    layout30->addWidget( QPBImprimir );

    PagosDocumentosPagarLayout->addLayout( layout30, 2, 0 );

    layout34 = new QVBoxLayout( 0, 0, 6, "layout34"); 

    layout27 = new QHBoxLayout( 0, 0, 6, "layout27"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    lineEdit1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( lineEdit1 );
    layout27->addLayout( layout1 );

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout5->addWidget( textLabel4 );

    comboBox1 = new QComboBox( FALSE, this, "comboBox1" );
    comboBox1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, comboBox1->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( comboBox1 );
    layout27->addLayout( layout5 );

    layout3_2 = new QVBoxLayout( 0, 0, 6, "layout3_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    layout3_2->addWidget( textLabel2_2 );

    ctrlProveedoresSS1_2 = new QCtrlProveedoresSS( this, "ctrlProveedoresSS1_2" );
    ctrlProveedoresSS1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, ctrlProveedoresSS1_2->sizePolicy().hasHeightForWidth() ) );
    layout3_2->addWidget( ctrlProveedoresSS1_2 );
    layout27->addLayout( layout3_2 );
    layout34->addLayout( layout27 );

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    layout1_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout1_2_2->addWidget( textLabel1_2_2 );

    lineEdit1_2_2 = new QLineEdit( this, "lineEdit1_2_2" );
    lineEdit1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2->addWidget( lineEdit1_2_2 );
    layout33->addLayout( layout1_2_2 );

    layout1_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2"); 

    textLabel1_2_2_2 = new QLabel( this, "textLabel1_2_2_2" );
    layout1_2_2_2->addWidget( textLabel1_2_2_2 );

    lineEdit1_2_2_2 = new QLineEdit( this, "lineEdit1_2_2_2" );
    lineEdit1_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2->addWidget( lineEdit1_2_2_2 );
    layout33->addLayout( layout1_2_2_2 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout5_2->addWidget( textLabel4_2 );

    comboBox1_2 = new QComboBox( FALSE, this, "comboBox1_2" );
    layout5_2->addWidget( comboBox1_2 );
    layout33->addLayout( layout5_2 );

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    layout1_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2_2"); 

    textLabel1_2_2_2_2 = new QLabel( this, "textLabel1_2_2_2_2" );
    layout1_2_2_2_2->addWidget( textLabel1_2_2_2_2 );

    lineEdit1_2_2_2_2 = new QLineEdit( this, "lineEdit1_2_2_2_2" );
    lineEdit1_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2_2->addWidget( lineEdit1_2_2_2_2 );
    layout29->addLayout( layout1_2_2_2_2 );

    layout1_2_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2_2_2"); 

    textLabel1_2_2_2_2_2 = new QLabel( this, "textLabel1_2_2_2_2_2" );
    layout1_2_2_2_2_2->addWidget( textLabel1_2_2_2_2_2 );

    lineEdit1_2_2_2_2_2 = new QLineEdit( this, "lineEdit1_2_2_2_2_2" );
    lineEdit1_2_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1_2_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2_2_2->addWidget( lineEdit1_2_2_2_2_2 );
    layout29->addLayout( layout1_2_2_2_2_2 );

    layout1_2_2_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout1_2_2_2_2_2_2"); 

    textLabel1_2_2_2_2_2_2 = new QLabel( this, "textLabel1_2_2_2_2_2_2" );
    layout1_2_2_2_2_2_2->addWidget( textLabel1_2_2_2_2_2_2 );

    lineEdit1_2_2_2_2_2_2 = new QLineEdit( this, "lineEdit1_2_2_2_2_2_2" );
    lineEdit1_2_2_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit1_2_2_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout1_2_2_2_2_2_2->addWidget( lineEdit1_2_2_2_2_2_2 );
    layout29->addLayout( layout1_2_2_2_2_2_2 );
    layout33->addLayout( layout29 );
    layout34->addLayout( layout33 );

    PagosDocumentosPagarLayout->addLayout( layout34, 0, 0 );
    languageChange();
    resize( QSize(1001, 484).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
PagosDocumentosPagar::~PagosDocumentosPagar()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PagosDocumentosPagar::languageChange()
{
    setCaption( tr( "Registro de pagos a documentos por pagar" ) );
    textLabel6->setText( tr( "Libros Registrados" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Sec" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Libro" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "Aplicacion" ) );
    table1->horizontalHeader()->setLabel( 3, tr( "Factura" ) );
    table1->horizontalHeader()->setLabel( 4, tr( "Fecha" ) );
    table1->horizontalHeader()->setLabel( 5, tr( "Imp Aplicacion" ) );
    table1->horizontalHeader()->setLabel( 6, tr( "Imp Pago" ) );
    table1->horizontalHeader()->setLabel( 7, tr( "Sts" ) );
    pushButton1->setText( tr( "Registrar Pago" ) );
    pushButton2->setText( tr( "Modificar Pago" ) );
    QPBImprimir->setText( tr( "Imprimir Relacion de cheques a pagar" ) );
    textLabel1->setText( tr( "Folio del Cheque" ) );
    textLabel4->setText( tr( "Concepto" ) );
    comboBox1->clear();
    comboBox1->insertItem( tr( "5301-Pago a proveedor con cheque" ) );
    textLabel2_2->setText( tr( "Proveedores" ) );
    textLabel1_2_2->setText( tr( "Fecha Documento" ) );
    textLabel1_2_2_2->setText( tr( "Importe Cheque" ) );
    textLabel4_2->setText( tr( "Aplicaciones" ) );
    comboBox1_2->clear();
    comboBox1_2->insertItem( tr( "0006-0000654" ) );
    textLabel1_2_2_2_2->setText( tr( "Saldo" ) );
    textLabel1_2_2_2_2_2->setText( tr( "Importe" ) );
    textLabel1_2_2_2_2_2_2->setText( tr( "Total" ) );
}

