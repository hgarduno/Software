/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/CapturaTienda.ui'
**
** Created: Sat Jan 27 16:37:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CapturaTienda.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlTipoVentas.h"
#include "QCtrlFinanciadoras.h"

/*
 *  Constructs a CapturaTienda as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CapturaTienda::CapturaTienda( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CapturaTienda" );

    QWidget* privateLayoutWidget = new QWidget( this, "layout311" );
    privateLayoutWidget->setGeometry( QRect( 12, 79, 504, 61 ) );
    layout311 = new QHBoxLayout( privateLayoutWidget, 11, 6, "layout311"); 

    layout306 = new QVBoxLayout( 0, 0, 6, "layout306"); 

    textLabel13 = new QLabel( privateLayoutWidget, "textLabel13" );
    layout306->addWidget( textLabel13 );

    lineEdit75 = new QLineEdit( privateLayoutWidget, "lineEdit75" );
    layout306->addWidget( lineEdit75 );
    layout311->addLayout( layout306 );

    layout307 = new QVBoxLayout( 0, 0, 6, "layout307"); 

    textLabel14 = new QLabel( privateLayoutWidget, "textLabel14" );
    layout307->addWidget( textLabel14 );

    lineEdit76 = new QLineEdit( privateLayoutWidget, "lineEdit76" );
    lineEdit76->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit76->sizePolicy().hasHeightForWidth() ) );
    layout307->addWidget( lineEdit76 );
    layout311->addLayout( layout307 );

    layout308 = new QVBoxLayout( 0, 0, 6, "layout308"); 

    textLabel15 = new QLabel( privateLayoutWidget, "textLabel15" );
    layout308->addWidget( textLabel15 );

    lineEdit77 = new QLineEdit( privateLayoutWidget, "lineEdit77" );
    lineEdit77->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit77->sizePolicy().hasHeightForWidth() ) );
    layout308->addWidget( lineEdit77 );
    layout311->addLayout( layout308 );

    QWidget* privateLayoutWidget_2 = new QWidget( this, "layout136" );
    privateLayoutWidget_2->setGeometry( QRect( 12, 146, 504, 33 ) );
    layout136 = new QHBoxLayout( privateLayoutWidget_2, 11, 6, "layout136"); 

    textLabel16 = new QLabel( privateLayoutWidget_2, "textLabel16" );
    layout136->addWidget( textLabel16 );

    lineEdit78 = new QLineEdit( privateLayoutWidget_2, "lineEdit78" );
    layout136->addWidget( lineEdit78 );

    pushButton46 = new QPushButton( privateLayoutWidget_2, "pushButton46" );
    layout136->addWidget( pushButton46 );

    QWidget* privateLayoutWidget_3 = new QWidget( this, "layout24" );
    privateLayoutWidget_3->setGeometry( QRect( 12, 185, 504, 117 ) );
    layout24 = new QVBoxLayout( privateLayoutWidget_3, 11, 6, "layout24"); 

    textLabel18 = new QLabel( privateLayoutWidget_3, "textLabel18" );
    layout24->addWidget( textLabel18 );

    table1 = new QTable( privateLayoutWidget_3, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Calle" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "No. Ext." ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "No. Int." ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Colonia" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Deleg/Munic" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Estado" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, trUtf8( "\x43\xc3\xb3\x64\x69\x67\x6f\x20\x50\x6f\x73\x74\x61\x6c" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Referencias" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 8 );
    layout24->addWidget( table1 );

    QWidget* privateLayoutWidget_4 = new QWidget( this, "layout25" );
    privateLayoutWidget_4->setGeometry( QRect( 12, 308, 504, 117 ) );
    layout25 = new QVBoxLayout( privateLayoutWidget_4, 11, 6, "layout25"); 

    textLabel17 = new QLabel( privateLayoutWidget_4, "textLabel17" );
    layout25->addWidget( textLabel17 );

    table2 = new QTable( privateLayoutWidget_4, "table2" );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Telefono" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, trUtf8( "\x44\x65\x73\x63\x72\x69\x70\x63\x69\xc3\xb3\x6e" ) );
    table2->setNumRows( 0 );
    table2->setNumCols( 2 );
    layout25->addWidget( table2 );

    QWidget* privateLayoutWidget_5 = new QWidget( this, "layout146" );
    privateLayoutWidget_5->setGeometry( QRect( 12, 431, 504, 33 ) );
    layout146 = new QHBoxLayout( privateLayoutWidget_5, 11, 6, "layout146"); 

    pushButton40 = new QPushButton( privateLayoutWidget_5, "pushButton40" );
    layout146->addWidget( pushButton40 );

    pushButton41 = new QPushButton( privateLayoutWidget_5, "pushButton41" );
    layout146->addWidget( pushButton41 );

    QWidget* privateLayoutWidget_6 = new QWidget( this, "layout145" );
    privateLayoutWidget_6->setGeometry( QRect( 12, 470, 504, 33 ) );
    layout145 = new QHBoxLayout( privateLayoutWidget_6, 11, 6, "layout145"); 

    pushButton39 = new QPushButton( privateLayoutWidget_6, "pushButton39" );
    layout145->addWidget( pushButton39 );

    pushButton50 = new QPushButton( privateLayoutWidget_6, "pushButton50" );
    layout145->addWidget( pushButton50 );

    pushButton51 = new QPushButton( privateLayoutWidget_6, "pushButton51" );
    layout145->addWidget( pushButton51 );

    pushButton42 = new QPushButton( privateLayoutWidget_6, "pushButton42" );
    layout145->addWidget( pushButton42 );

    QWidget* privateLayoutWidget_7 = new QWidget( this, "layout13" );
    privateLayoutWidget_7->setGeometry( QRect( 10, 10, 477, 61 ) );
    layout13 = new QHBoxLayout( privateLayoutWidget_7, 11, 6, "layout13"); 

    layout309 = new QVBoxLayout( 0, 0, 6, "layout309"); 

    textLabel12 = new QLabel( privateLayoutWidget_7, "textLabel12" );
    layout309->addWidget( textLabel12 );

    lineEdit74 = new QLineEdit( privateLayoutWidget_7, "lineEdit74" );
    lineEdit74->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, lineEdit74->sizePolicy().hasHeightForWidth() ) );
    layout309->addWidget( lineEdit74 );
    layout13->addLayout( layout309 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 
    spacer9 = new QSpacerItem( 80, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout12->addItem( spacer9 );

    QCtrTipoVentas = new QCtrlTipoVentas( privateLayoutWidget_7, "QCtrTipoVentas" );
    layout12->addWidget( QCtrTipoVentas );

    QCtrFinanciadoras = new QCtrlFinanciadoras( privateLayoutWidget_7, "QCtrFinanciadoras" );
    layout12->addWidget( QCtrFinanciadoras );
    layout13->addLayout( layout12 );
    languageChange();
    resize( QSize(528, 515).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CapturaTienda::~CapturaTienda()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CapturaTienda::languageChange()
{
    setCaption( tr( "Captura de Tiendas" ) );
    textLabel13->setText( tr( "Nombre:" ) );
    textLabel14->setText( tr( "Abreviatura:" ) );
    textLabel15->setText( tr( "Siglas" ) );
    textLabel16->setText( tr( "Responsable:" ) );
    pushButton46->setText( tr( "Captura Responsable" ) );
    textLabel18->setText( trUtf8( "\x44\x69\x72\x65\x63\x63\x69\xc3\xb3\x6e\x3a" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Calle" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "No. Ext." ) );
    table1->horizontalHeader()->setLabel( 2, tr( "No. Int." ) );
    table1->horizontalHeader()->setLabel( 3, tr( "Colonia" ) );
    table1->horizontalHeader()->setLabel( 4, tr( "Deleg/Munic" ) );
    table1->horizontalHeader()->setLabel( 5, tr( "Estado" ) );
    table1->horizontalHeader()->setLabel( 6, trUtf8( "\x43\xc3\xb3\x64\x69\x67\x6f\x20\x50\x6f\x73\x74\x61\x6c" ) );
    table1->horizontalHeader()->setLabel( 7, tr( "Referencias" ) );
    textLabel17->setText( trUtf8( "\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f\x73\x3a" ) );
    table2->horizontalHeader()->setLabel( 0, tr( "Telefono" ) );
    table2->horizontalHeader()->setLabel( 1, trUtf8( "\x44\x65\x73\x63\x72\x69\x70\x63\x69\xc3\xb3\x6e" ) );
    pushButton40->setText( trUtf8( "\x43\x61\x70\x74\x75\x72\x61\x20\x44\x69\x72\x65\x63\x63\x69\xc3\xb3\x6e" ) );
    pushButton41->setText( trUtf8( "\x43\x61\x70\x74\x75\x72\x61\x20\x54\x65\x6c\xc3\xa9\x66\x6f\x6e\x6f\x73" ) );
    pushButton39->setText( tr( "Crear" ) );
    pushButton50->setText( tr( "Consultar" ) );
    pushButton51->setText( tr( "Actualizar" ) );
    pushButton42->setText( tr( "Cancelar" ) );
    textLabel12->setText( tr( "Tienda:" ) );
}

