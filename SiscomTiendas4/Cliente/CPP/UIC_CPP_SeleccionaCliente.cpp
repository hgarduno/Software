/****************************************************************************
** Form implementation generated from reading ui file 'UI/SeleccionaCliente.ui'
**
** Created: Thu Apr 11 20:30:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_SeleccionaCliente.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlClientes3Qt.h>
#include <QCtrlContactos3Qt.h>
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlClientes3Qt.h"
#include "QCtrlContactos3Qt.h"

/*
 *  Constructs a SeleccionaCliente as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
SeleccionaCliente::SeleccionaCliente( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "SeleccionaCliente" );
    SeleccionaClienteLayout = new QGridLayout( this, 1, 1, 11, 6, "SeleccionaClienteLayout"); 

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout2->addWidget( textLabel1_2 );

    QCtrClientes = new QCtrlClientes3Qt( this, "QCtrClientes" );
    layout2->addWidget( QCtrClientes );
    layout37->addLayout( layout2 );

    layout3 = new QVBoxLayout( 0, 0, 6, "layout3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout3->addWidget( textLabel1_3 );

    QCtrContactos = new QCtrlContactos3Qt( this, "QCtrContactos" );
    layout3->addWidget( QCtrContactos );
    layout37->addLayout( layout3 );

    QPBSCliente = new QPushButton( this, "QPBSCliente" );
    QPBSCliente->setMinimumSize( QSize( 0, 40 ) );
    layout37->addWidget( QPBSCliente );

    SeleccionaClienteLayout->addLayout( layout37, 0, 0 );

    groupBox3 = new QGroupBox( this, "groupBox3" );
    groupBox3->setEnabled( FALSE );
    groupBox3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, groupBox3->sizePolicy().hasHeightForWidth() ) );
    groupBox3->setColumnLayout(0, Qt::Vertical );
    groupBox3->layout()->setSpacing( 6 );
    groupBox3->layout()->setMargin( 11 );
    groupBox3Layout = new QGridLayout( groupBox3->layout() );
    groupBox3Layout->setAlignment( Qt::AlignTop );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    textLabel6 = new QLabel( groupBox3, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout20->addWidget( textLabel6 );

    QLENombre = new QLineEdit( groupBox3, "QLENombre" );
    layout20->addWidget( QLENombre );
    layout23->addLayout( layout20 );

    layout20_2 = new QVBoxLayout( 0, 0, 6, "layout20_2"); 

    textLabel6_2 = new QLabel( groupBox3, "textLabel6_2" );
    textLabel6_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel6_2->sizePolicy().hasHeightForWidth() ) );
    layout20_2->addWidget( textLabel6_2 );

    QLEAPaterno = new QLineEdit( groupBox3, "QLEAPaterno" );
    layout20_2->addWidget( QLEAPaterno );
    layout23->addLayout( layout20_2 );

    layout20_2_2 = new QVBoxLayout( 0, 0, 6, "layout20_2_2"); 

    textLabel6_2_2 = new QLabel( groupBox3, "textLabel6_2_2" );
    textLabel6_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel6_2_2->sizePolicy().hasHeightForWidth() ) );
    layout20_2_2->addWidget( textLabel6_2_2 );

    QLEAMaterno = new QLineEdit( groupBox3, "QLEAMaterno" );
    layout20_2_2->addWidget( QLEAMaterno );
    layout23->addLayout( layout20_2_2 );

    groupBox3Layout->addLayout( layout23, 0, 0 );

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel8 = new QLabel( groupBox3, "textLabel8" );
    textLabel8->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel8->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( textLabel8 );

    QTEDscContacto = new QTextEdit( groupBox3, "QTEDscContacto" );
    QTEDscContacto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)3, 0, 0, QTEDscContacto->sizePolicy().hasHeightForWidth() ) );
    QTEDscContacto->setMinimumSize( QSize( 0, 50 ) );
    QTEDscContacto->setMaximumSize( QSize( 32767, 50 ) );
    layout26->addWidget( QTEDscContacto );

    groupBox3Layout->addLayout( layout26, 1, 0 );

    SeleccionaClienteLayout->addWidget( groupBox3, 1, 0 );

    groupBox5 = new QGroupBox( this, "groupBox5" );
    groupBox5->setColumnLayout(0, Qt::Vertical );
    groupBox5->layout()->setSpacing( 6 );
    groupBox5->layout()->setMargin( 11 );
    groupBox5Layout = new QGridLayout( groupBox5->layout() );
    groupBox5Layout->setAlignment( Qt::AlignTop );

    layout43 = new QVBoxLayout( 0, 0, 6, "layout43"); 

    textLabel2 = new QLabel( groupBox5, "textLabel2" );
    layout43->addWidget( textLabel2 );

    lineEdit14 = new QLineEdit( groupBox5, "lineEdit14" );
    layout43->addWidget( lineEdit14 );

    groupBox5Layout->addLayout( layout43, 0, 0 );

    tabWidget2 = new QTabWidget( groupBox5, "tabWidget2" );

    tab = new QWidget( tabWidget2, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    textLabel3 = new QLabel( tab, "textLabel3" );

    tabLayout->addWidget( textLabel3, 0, 0 );

    table4 = new QTable( tab, "table4" );
    table4->setNumCols( table4->numCols() + 1 );
    table4->horizontalHeader()->setLabel( table4->numCols() - 1, tr( "1" ) );
    table4->setNumCols( table4->numCols() + 1 );
    table4->horizontalHeader()->setLabel( table4->numCols() - 1, tr( "2" ) );
    table4->setNumCols( table4->numCols() + 1 );
    table4->horizontalHeader()->setLabel( table4->numCols() - 1, tr( "3" ) );
    table4->setNumRows( 0 );
    table4->setNumCols( 3 );

    tabLayout->addWidget( table4, 1, 0 );

    QPBSCliente_2 = new QPushButton( tab, "QPBSCliente_2" );
    QPBSCliente_2->setMinimumSize( QSize( 0, 40 ) );

    tabLayout->addWidget( QPBSCliente_2, 2, 0 );
    tabWidget2->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget2, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout44_2 = new QVBoxLayout( 0, 0, 6, "layout44_2"); 

    textLabel3_2 = new QLabel( tab_2, "textLabel3_2" );
    layout44_2->addWidget( textLabel3_2 );

    table4_2 = new QTable( tab_2, "table4_2" );
    table4_2->setNumCols( table4_2->numCols() + 1 );
    table4_2->horizontalHeader()->setLabel( table4_2->numCols() - 1, tr( "1" ) );
    table4_2->setNumCols( table4_2->numCols() + 1 );
    table4_2->horizontalHeader()->setLabel( table4_2->numCols() - 1, tr( "2" ) );
    table4_2->setNumCols( table4_2->numCols() + 1 );
    table4_2->horizontalHeader()->setLabel( table4_2->numCols() - 1, tr( "3" ) );
    table4_2->setNumRows( 0 );
    table4_2->setNumCols( 3 );
    layout44_2->addWidget( table4_2 );

    tabLayout_2->addLayout( layout44_2, 0, 0 );

    QPBSCliente_2_2 = new QPushButton( tab_2, "QPBSCliente_2_2" );
    QPBSCliente_2_2->setMinimumSize( QSize( 0, 40 ) );

    tabLayout_2->addWidget( QPBSCliente_2_2, 1, 0 );
    tabWidget2->insertTab( tab_2, QString::fromLatin1("") );

    groupBox5Layout->addWidget( tabWidget2, 1, 0 );

    SeleccionaClienteLayout->addWidget( groupBox5, 2, 0 );
    languageChange();
    resize( QSize(568, 672).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
SeleccionaCliente::~SeleccionaCliente()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void SeleccionaCliente::languageChange()
{
    setCaption( tr( "Selecciona Cliente" ) );
    textLabel1_2->setText( tr( "Clientes" ) );
    textLabel1_3->setText( tr( "Contactos" ) );
    QPBSCliente->setText( tr( "Anexar\n"
"Contacto" ) );
    groupBox3->setTitle( tr( "Datos Contacto" ) );
    textLabel6->setText( tr( "Nombre" ) );
    textLabel6_2->setText( tr( "Apellido Paterno" ) );
    textLabel6_2_2->setText( tr( "Apellido Materno" ) );
    textLabel8->setText( tr( "Descripcion" ) );
    groupBox5->setTitle( tr( "Cliente Seleccionado" ) );
    textLabel2->setText( tr( "Cliente" ) );
    textLabel3->setText( tr( "Direcciones" ) );
    table4->horizontalHeader()->setLabel( 0, tr( "1" ) );
    table4->horizontalHeader()->setLabel( 1, tr( "2" ) );
    table4->horizontalHeader()->setLabel( 2, tr( "3" ) );
    QPBSCliente_2->setText( tr( "Anexar\n"
"Direccion" ) );
    tabWidget2->changeTab( tab, tr( "Direcciones" ) );
    textLabel3_2->setText( tr( "Medios De Comunicacion" ) );
    table4_2->horizontalHeader()->setLabel( 0, tr( "1" ) );
    table4_2->horizontalHeader()->setLabel( 1, tr( "2" ) );
    table4_2->horizontalHeader()->setLabel( 2, tr( "3" ) );
    QPBSCliente_2_2->setText( tr( "Anexar\n"
"Medio De Comunicacion" ) );
    tabWidget2->changeTab( tab_2, tr( "Medios De Comunicacion" ) );
}

