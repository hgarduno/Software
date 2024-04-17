/****************************************************************************
** Form implementation generated from reading ui file 'UI/OrdenServicio.ui'
**
** Created: Fri Apr 12 21:36:42 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_OrdenServicio.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <QCtrlFechaHora.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlFechaHora.h"

/*
 *  Constructs a OrdenServicio as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
OrdenServicio::OrdenServicio( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "OrdenServicio" );
    OrdenServicioLayout = new QGridLayout( this, 1, 1, 11, 6, "OrdenServicioLayout"); 

    pushButton17 = new QPushButton( this, "pushButton17" );

    OrdenServicioLayout->addMultiCellWidget( pushButton17, 2, 2, 0, 2 );

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    layout2 = new QHBoxLayout( 0, 0, 6, "layout2"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout1->addWidget( textLabel1 );

    QLEResponsableCargo = new QLineEdit( this, "QLEResponsableCargo" );
    QLEResponsableCargo->setReadOnly( TRUE );
    layout1->addWidget( QLEResponsableCargo );
    layout2->addLayout( layout1 );

    QPBCEVehiculo = new QPushButton( this, "QPBCEVehiculo" );
    QPBCEVehiculo->setMinimumSize( QSize( 40, 40 ) );
    layout2->addWidget( QPBCEVehiculo );
    layout43->addLayout( layout2 );

    layout2_2 = new QHBoxLayout( 0, 0, 6, "layout2_2"); 

    layout1_2 = new QVBoxLayout( 0, 0, 6, "layout1_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout1_2->addWidget( textLabel1_2 );

    QLEPropietario = new QLineEdit( this, "QLEPropietario" );
    QLEPropietario->setReadOnly( TRUE );
    layout1_2->addWidget( QLEPropietario );
    layout2_2->addLayout( layout1_2 );

    QPBPropietario = new QPushButton( this, "QPBPropietario" );
    QPBPropietario->setMinimumSize( QSize( 40, 40 ) );
    layout2_2->addWidget( QPBPropietario );
    layout43->addLayout( layout2_2 );
    layout44->addLayout( layout43 );

    layout41 = new QVBoxLayout( 0, 0, 6, "layout41"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout5->addWidget( textLabel1_3 );

    QTDirecciones = new QTable( this, "QTDirecciones" );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Direccion" ) );
    QTDirecciones->setNumRows( 0 );
    QTDirecciones->setNumCols( 1 );
    layout5->addWidget( QTDirecciones );
    layout41->addLayout( layout5 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel1_3_2 = new QLabel( this, "textLabel1_3_2" );
    layout5_2->addWidget( textLabel1_3_2 );

    QTTelefonos = new QTable( this, "QTTelefonos" );
    QTTelefonos->setNumCols( QTTelefonos->numCols() + 1 );
    QTTelefonos->horizontalHeader()->setLabel( QTTelefonos->numCols() - 1, tr( "Telefonos" ) );
    QTTelefonos->setNumRows( 0 );
    QTTelefonos->setNumCols( 1 );
    layout5_2->addWidget( QTTelefonos );
    layout41->addLayout( layout5_2 );
    layout44->addLayout( layout41 );

    layout47 = new QVBoxLayout( 0, 0, 6, "layout47"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout47->addWidget( textLabel1_4 );

    textEdit3 = new QTextEdit( this, "textEdit3" );
    textEdit3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textEdit3->sizePolicy().hasHeightForWidth() ) );
    layout47->addWidget( textEdit3 );
    layout44->addLayout( layout47 );

    OrdenServicioLayout->addLayout( layout44, 0, 0 );

    layout55 = new QVBoxLayout( 0, 0, 6, "layout55"); 

    textLabel4_3 = new QLabel( this, "textLabel4_3" );
    textLabel4_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel4_3->sizePolicy().hasHeightForWidth() ) );
    layout55->addWidget( textLabel4_3 );

    table7 = new QTable( this, "table7" );
    table7->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, table7->sizePolicy().hasHeightForWidth() ) );
    table7->setNumRows( 0 );
    table7->setNumCols( 3 );
    layout55->addWidget( table7 );

    OrdenServicioLayout->addMultiCellLayout( layout55, 1, 1, 0, 1 );

    layout64 = new QVBoxLayout( 0, 0, 6, "layout64"); 

    layout63 = new QVBoxLayout( 0, 0, 6, "layout63"); 

    layout56_3 = new QVBoxLayout( 0, 0, 6, "layout56_3"); 

    textLabel5_3_3 = new QLabel( this, "textLabel5_3_3" );
    layout56_3->addWidget( textLabel5_3_3 );

    lCDNumber2_3 = new QLCDNumber( this, "lCDNumber2_3" );
    lCDNumber2_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lCDNumber2_3->sizePolicy().hasHeightForWidth() ) );
    layout56_3->addWidget( lCDNumber2_3 );
    layout63->addLayout( layout56_3 );

    layout56_2 = new QVBoxLayout( 0, 0, 6, "layout56_2"); 

    textLabel5_3_2 = new QLabel( this, "textLabel5_3_2" );
    layout56_2->addWidget( textLabel5_3_2 );

    lCDNumber2_2 = new QLCDNumber( this, "lCDNumber2_2" );
    lCDNumber2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lCDNumber2_2->sizePolicy().hasHeightForWidth() ) );
    layout56_2->addWidget( lCDNumber2_2 );
    layout63->addLayout( layout56_2 );
    layout64->addLayout( layout63 );

    layout62 = new QHBoxLayout( 0, 0, 6, "layout62"); 

    layout56_4_2 = new QVBoxLayout( 0, 0, 6, "layout56_4_2"); 

    textLabel5_3_4_2 = new QLabel( this, "textLabel5_3_4_2" );
    layout56_4_2->addWidget( textLabel5_3_4_2 );

    lCDNumber2_4_2 = new QLCDNumber( this, "lCDNumber2_4_2" );
    lCDNumber2_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lCDNumber2_4_2->sizePolicy().hasHeightForWidth() ) );
    layout56_4_2->addWidget( lCDNumber2_4_2 );
    layout62->addLayout( layout56_4_2 );

    layout56 = new QVBoxLayout( 0, 0, 6, "layout56"); 

    textLabel5_3 = new QLabel( this, "textLabel5_3" );
    layout56->addWidget( textLabel5_3 );

    lCDNumber2 = new QLCDNumber( this, "lCDNumber2" );
    lCDNumber2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lCDNumber2->sizePolicy().hasHeightForWidth() ) );
    layout56->addWidget( lCDNumber2 );
    layout62->addLayout( layout56 );

    layout56_4 = new QVBoxLayout( 0, 0, 6, "layout56_4"); 

    textLabel5_3_4 = new QLabel( this, "textLabel5_3_4" );
    layout56_4->addWidget( textLabel5_3_4 );

    lCDNumber2_4 = new QLCDNumber( this, "lCDNumber2_4" );
    lCDNumber2_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)0, 0, 0, lCDNumber2_4->sizePolicy().hasHeightForWidth() ) );
    layout56_4->addWidget( lCDNumber2_4 );
    layout62->addLayout( layout56_4 );
    layout64->addLayout( layout62 );

    OrdenServicioLayout->addLayout( layout64, 1, 2 );

    layout48 = new QVBoxLayout( 0, 0, 6, "layout48"); 

    layout66 = new QHBoxLayout( 0, 0, 6, "layout66"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel4 );

    CtrFHRecepcion = new QCtrlFechaHora( this, "CtrFHRecepcion" );
    CtrFHRecepcion->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, CtrFHRecepcion->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( CtrFHRecepcion );
    layout66->addLayout( layout11 );
    spacer2_2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout66->addItem( spacer2_2 );
    layout48->addLayout( layout66 );

    layout67 = new QHBoxLayout( 0, 0, 6, "layout67"); 

    layout11_2 = new QVBoxLayout( 0, 0, 6, "layout11_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( textLabel4_2 );

    CtrFHEntrega = new QCtrlFechaHora( this, "CtrFHEntrega" );
    CtrFHEntrega->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, CtrFHEntrega->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( CtrFHEntrega );
    layout67->addLayout( layout11_2 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout67->addItem( spacer2 );
    layout48->addLayout( layout67 );

    layout13 = new QVBoxLayout( 0, 0, 6, "layout13"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout13->addWidget( textLabel5 );

    lineEdit5 = new QLineEdit( this, "lineEdit5" );
    layout13->addWidget( lineEdit5 );
    layout48->addLayout( layout13 );

    layout13_2 = new QVBoxLayout( 0, 0, 6, "layout13_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout13_2->addWidget( textLabel5_2 );

    lineEdit5_2 = new QLineEdit( this, "lineEdit5_2" );
    layout13_2->addWidget( lineEdit5_2 );
    layout48->addLayout( layout13_2 );

    layout17 = new QHBoxLayout( 0, 0, 6, "layout17"); 

    layout13_2_2 = new QVBoxLayout( 0, 0, 6, "layout13_2_2"); 

    textLabel5_2_2 = new QLabel( this, "textLabel5_2_2" );
    textLabel5_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2_2->sizePolicy().hasHeightForWidth() ) );
    layout13_2_2->addWidget( textLabel5_2_2 );

    lineEdit5_2_2 = new QLineEdit( this, "lineEdit5_2_2" );
    lineEdit5_2_2->setReadOnly( TRUE );
    layout13_2_2->addWidget( lineEdit5_2_2 );
    layout17->addLayout( layout13_2_2 );

    pushButton7 = new QPushButton( this, "pushButton7" );
    pushButton7->setMinimumSize( QSize( 0, 40 ) );
    layout17->addWidget( pushButton7 );
    layout48->addLayout( layout17 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout13_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout13_2_2_2"); 

    textLabel5_2_2_2 = new QLabel( this, "textLabel5_2_2_2" );
    textLabel5_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout13_2_2_2->addWidget( textLabel5_2_2_2 );

    lineEdit5_2_2_2 = new QLineEdit( this, "lineEdit5_2_2_2" );
    lineEdit5_2_2_2->setReadOnly( TRUE );
    layout13_2_2_2->addWidget( lineEdit5_2_2_2 );
    layout18->addLayout( layout13_2_2_2 );

    pushButton7_2 = new QPushButton( this, "pushButton7_2" );
    pushButton7_2->setMinimumSize( QSize( 0, 40 ) );
    layout18->addWidget( pushButton7_2 );
    layout48->addLayout( layout18 );

    layout47_2 = new QVBoxLayout( 0, 0, 6, "layout47_2"); 

    textLabel1_4_2 = new QLabel( this, "textLabel1_4_2" );
    textLabel1_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4_2->sizePolicy().hasHeightForWidth() ) );
    layout47_2->addWidget( textLabel1_4_2 );

    textEdit3_2 = new QTextEdit( this, "textEdit3_2" );
    textEdit3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, textEdit3_2->sizePolicy().hasHeightForWidth() ) );
    layout47_2->addWidget( textEdit3_2 );
    layout48->addLayout( layout47_2 );

    OrdenServicioLayout->addMultiCellLayout( layout48, 0, 0, 1, 2 );
    languageChange();
    resize( QSize(788, 673).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
OrdenServicio::~OrdenServicio()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void OrdenServicio::languageChange()
{
    setCaption( tr( "Orden De Servicio" ) );
    pushButton17->setText( tr( "Inventario y Estado Del Vehiculo" ) );
    textLabel1->setText( tr( "Nombre Y Cargo de quien entrega" ) );
    QPBCEVehiculo->setText( tr( "Nombre Y Cargo de\n"
"Quien entrega el Vehiculo" ) );
    textLabel1_2->setText( tr( "Propietario" ) );
    QPBPropietario->setText( tr( "Propietario" ) );
    textLabel1_3->setText( tr( "Direcciones" ) );
    QTDirecciones->horizontalHeader()->setLabel( 0, tr( "Direccion" ) );
    textLabel1_3_2->setText( tr( "Telefonos" ) );
    QTTelefonos->horizontalHeader()->setLabel( 0, tr( "Telefonos" ) );
    textLabel1_4->setText( trUtf8( "\x44\x65\x73\x63\x72\x69\x70\x63\x69\xc3\xb3\x6e\x20\x44\x65\x6c\x20\x54\x72\x61\x62"
    "\x61\x6a\x6f" ) );
    textLabel4_3->setText( trUtf8( "\x43\x6f\x74\x69\x7a\x61\x63\x69\xc3\xb3\x6e" ) );
    textLabel5_3_3->setText( tr( "Total Mano De Obra" ) );
    textLabel5_3_2->setText( tr( "Total Refacciones" ) );
    textLabel5_3_4_2->setText( tr( "Sub Total" ) );
    textLabel5_3->setText( tr( "IVA" ) );
    textLabel5_3_4->setText( tr( "Total" ) );
    textLabel4->setText( trUtf8( "\x46\x65\x63\x68\x61\x20\x59\x20\x48\x6f\x72\x61\x20\x44\x65\x20\x52\x65\x63\x65\x70"
    "\x63\x69\xc3\xb3\x6e" ) );
    textLabel4_2->setText( tr( "Fecha Y Hora De Entrega" ) );
    textLabel5->setText( tr( "No. Serie Y/O Motor" ) );
    textLabel5_2->setText( tr( "Placas" ) );
    textLabel5_2_2->setText( tr( "Marca" ) );
    pushButton7->setText( tr( "Marca Vehiculo" ) );
    textLabel5_2_2_2->setText( trUtf8( "\x41\xc3\xb1\x6f\x2f\x4d\x6f\x64\x65\x6c\x6f" ) );
    pushButton7_2->setText( trUtf8( "\x41\xc3\xb1\x6f\x20\x2f\x20\x4d\x6f\x64\x65\x6c\x6f" ) );
    textLabel1_4_2->setText( tr( "Diagnostico, posibles consecuencias" ) );
}

