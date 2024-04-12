/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroClientes.ui'
**
** Created: Thu Apr 11 21:37:50 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroClientes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <QSisSepomex.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QSisSepomex.h"
#include "QCtrlEscuelas.h"

/*
 *  Constructs a RegistroClientes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroClientes::RegistroClientes( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroClientes" );
    RegistroClientesLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroClientesLayout"); 

    layout40 = new QHBoxLayout( 0, 0, 6, "layout40"); 

    QPBRGenerales = new QPushButton( this, "QPBRGenerales" );
    layout40->addWidget( QPBRGenerales );

    pushButton19 = new QPushButton( this, "pushButton19" );
    layout40->addWidget( pushButton19 );

    pushButton20 = new QPushButton( this, "pushButton20" );
    layout40->addWidget( pushButton20 );

    RegistroClientesLayout->addMultiCellLayout( layout40, 3, 3, 0, 1 );

    tabWidget26 = new QTabWidget( this, "tabWidget26" );
    tabWidget26->setEnabled( FALSE );
    tabWidget26->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, tabWidget26->sizePolicy().hasHeightForWidth() ) );

    tab = new QWidget( tabWidget26, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout5_4 = new QVBoxLayout( 0, 0, 6, "layout5_4"); 

    textLabel3_5 = new QLabel( tab, "textLabel3_5" );
    textLabel3_5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_5->sizePolicy().hasHeightForWidth() ) );
    layout5_4->addWidget( textLabel3_5 );

    lineEdit4_4 = new QLineEdit( tab, "lineEdit4_4" );
    layout5_4->addWidget( lineEdit4_4 );

    tabLayout->addLayout( layout5_4, 0, 0 );

    layout37_3_2 = new QHBoxLayout( 0, 0, 6, "layout37_3_2"); 

    QPBSDireccion_4_2 = new QPushButton( tab, "QPBSDireccion_4_2" );
    QPBSDireccion_4_2->setMinimumSize( QSize( 20, 0 ) );
    QPBSDireccion_4_2->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3_2->addWidget( QPBSDireccion_4_2 );

    QPBAntDireccion_4_2 = new QPushButton( tab, "QPBAntDireccion_4_2" );
    QPBAntDireccion_4_2->setMinimumSize( QSize( 20, 0 ) );
    QPBAntDireccion_4_2->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3_2->addWidget( QPBAntDireccion_4_2 );

    QPBAgregarDireccion_4_2 = new QPushButton( tab, "QPBAgregarDireccion_4_2" );
    QPBAgregarDireccion_4_2->setMinimumSize( QSize( 20, 0 ) );
    QPBAgregarDireccion_4_2->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3_2->addWidget( QPBAgregarDireccion_4_2 );

    QPBEliminarDireccion_4_2 = new QPushButton( tab, "QPBEliminarDireccion_4_2" );
    QPBEliminarDireccion_4_2->setMinimumSize( QSize( 20, 0 ) );
    QPBEliminarDireccion_4_2->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3_2->addWidget( QPBEliminarDireccion_4_2 );

    QPBModificar_4_2 = new QPushButton( tab, "QPBModificar_4_2" );
    QPBModificar_4_2->setMinimumSize( QSize( 20, 0 ) );
    QPBModificar_4_2->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3_2->addWidget( QPBModificar_4_2 );
    spacer2_4_2 = new QSpacerItem( 70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout37_3_2->addItem( spacer2_4_2 );

    tabLayout->addLayout( layout37_3_2, 2, 0 );

    table6 = new QTable( tab, "table6" );
    table6->setNumCols( table6->numCols() + 1 );
    table6->horizontalHeader()->setLabel( table6->numCols() - 1, tr( "Correo" ) );
    table6->setNumRows( 0 );
    table6->setNumCols( 3 );

    tabLayout->addWidget( table6, 1, 0 );
    tabWidget26->insertTab( tab, QString::fromLatin1("") );

    RegistroClientesLayout->addWidget( tabWidget26, 2, 1 );

    tabWidget3 = new QTabWidget( this, "tabWidget3" );
    tabWidget3->setEnabled( FALSE );

    tab_2 = new QWidget( tabWidget3, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    table1 = new QTable( tab_2, "table1" );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Calle Y No" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "Colonia" ) );
    table1->setNumCols( table1->numCols() + 1 );
    table1->horizontalHeader()->setLabel( table1->numCols() - 1, tr( "CP" ) );
    table1->setNumRows( 0 );
    table1->setNumCols( 3 );

    tabLayout_2->addWidget( table1, 2, 0 );

    QCtrSepomex = new QSisSepomex( tab_2, "QCtrSepomex" );

    tabLayout_2->addWidget( QCtrSepomex, 0, 0 );

    textLabel4 = new QLabel( tab_2, "textLabel4" );

    tabLayout_2->addWidget( textLabel4, 1, 0 );

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    QPBSDireccion = new QPushButton( tab_2, "QPBSDireccion" );
    QPBSDireccion->setMinimumSize( QSize( 20, 0 ) );
    QPBSDireccion->setMaximumSize( QSize( 20, 32767 ) );
    layout37->addWidget( QPBSDireccion );

    QPBAntDireccion = new QPushButton( tab_2, "QPBAntDireccion" );
    QPBAntDireccion->setMinimumSize( QSize( 20, 0 ) );
    QPBAntDireccion->setMaximumSize( QSize( 20, 32767 ) );
    layout37->addWidget( QPBAntDireccion );

    QPBAgregarDireccion = new QPushButton( tab_2, "QPBAgregarDireccion" );
    QPBAgregarDireccion->setMinimumSize( QSize( 20, 0 ) );
    QPBAgregarDireccion->setMaximumSize( QSize( 20, 32767 ) );
    layout37->addWidget( QPBAgregarDireccion );

    QPBEliminarDireccion = new QPushButton( tab_2, "QPBEliminarDireccion" );
    QPBEliminarDireccion->setMinimumSize( QSize( 20, 0 ) );
    QPBEliminarDireccion->setMaximumSize( QSize( 20, 32767 ) );
    layout37->addWidget( QPBEliminarDireccion );

    QPBModificar = new QPushButton( tab_2, "QPBModificar" );
    QPBModificar->setMinimumSize( QSize( 20, 0 ) );
    QPBModificar->setMaximumSize( QSize( 20, 32767 ) );
    layout37->addWidget( QPBModificar );
    spacer2 = new QSpacerItem( 70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout37->addItem( spacer2 );

    tabLayout_2->addLayout( layout37, 3, 0 );
    tabWidget3->insertTab( tab_2, QString::fromLatin1("") );

    RegistroClientesLayout->addMultiCellWidget( tabWidget3, 1, 2, 0, 0 );

    tabWidget22 = new QTabWidget( this, "tabWidget22" );
    tabWidget22->setEnabled( FALSE );
    tabWidget22->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, tabWidget22->sizePolicy().hasHeightForWidth() ) );

    tab_3 = new QWidget( tabWidget22, "tab_3" );
    tabLayout_3 = new QGridLayout( tab_3, 1, 1, 11, 6, "tabLayout_3"); 

    layout37_3 = new QHBoxLayout( 0, 0, 6, "layout37_3"); 

    QPBSDireccion_4 = new QPushButton( tab_3, "QPBSDireccion_4" );
    QPBSDireccion_4->setMinimumSize( QSize( 20, 0 ) );
    QPBSDireccion_4->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3->addWidget( QPBSDireccion_4 );

    QPBAntDireccion_4 = new QPushButton( tab_3, "QPBAntDireccion_4" );
    QPBAntDireccion_4->setMinimumSize( QSize( 20, 0 ) );
    QPBAntDireccion_4->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3->addWidget( QPBAntDireccion_4 );

    QPBAgregarDireccion_4 = new QPushButton( tab_3, "QPBAgregarDireccion_4" );
    QPBAgregarDireccion_4->setMinimumSize( QSize( 20, 0 ) );
    QPBAgregarDireccion_4->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3->addWidget( QPBAgregarDireccion_4 );

    QPBEliminarDireccion_4 = new QPushButton( tab_3, "QPBEliminarDireccion_4" );
    QPBEliminarDireccion_4->setMinimumSize( QSize( 20, 0 ) );
    QPBEliminarDireccion_4->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3->addWidget( QPBEliminarDireccion_4 );

    QPBModificar_4 = new QPushButton( tab_3, "QPBModificar_4" );
    QPBModificar_4->setMinimumSize( QSize( 20, 0 ) );
    QPBModificar_4->setMaximumSize( QSize( 20, 32767 ) );
    layout37_3->addWidget( QPBModificar_4 );
    spacer2_4 = new QSpacerItem( 70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout37_3->addItem( spacer2_4 );

    tabLayout_3->addLayout( layout37_3, 2, 0 );

    table2 = new QTable( tab_3, "table2" );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Telefono" ) );
    table2->setNumCols( table2->numCols() + 1 );
    table2->horizontalHeader()->setLabel( table2->numCols() - 1, tr( "Descripcion" ) );
    table2->setNumRows( 0 );
    table2->setNumCols( 2 );

    tabLayout_3->addWidget( table2, 1, 0 );

    layout5_3 = new QVBoxLayout( 0, 0, 6, "layout5_3"); 

    textLabel3_4 = new QLabel( tab_3, "textLabel3_4" );
    textLabel3_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_4->sizePolicy().hasHeightForWidth() ) );
    layout5_3->addWidget( textLabel3_4 );

    lineEdit4_3 = new QLineEdit( tab_3, "lineEdit4_3" );
    layout5_3->addWidget( lineEdit4_3 );

    tabLayout_3->addLayout( layout5_3, 0, 0 );
    tabWidget22->insertTab( tab_3, QString::fromLatin1("") );

    RegistroClientesLayout->addWidget( tabWidget22, 1, 1 );

    tabWidget2 = new QTabWidget( this, "tabWidget2" );
    tabWidget2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, tabWidget2->sizePolicy().hasHeightForWidth() ) );

    tab_4 = new QWidget( tabWidget2, "tab_4" );
    tabLayout_4 = new QGridLayout( tab_4, 1, 1, 11, 6, "tabLayout_4"); 

    layout5 = new QVBoxLayout( 0, 0, 6, "layout5"); 

    textLabel3 = new QLabel( tab_4, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout5->addWidget( textLabel3 );

    QLENombre = new QLineEdit( tab_4, "QLENombre" );
    layout5->addWidget( QLENombre );

    tabLayout_4->addLayout( layout5, 0, 0 );

    layout5_2 = new QVBoxLayout( 0, 0, 6, "layout5_2"); 

    textLabel3_2 = new QLabel( tab_4, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2->addWidget( textLabel3_2 );

    QLEAPaterno = new QLineEdit( tab_4, "QLEAPaterno" );
    layout5_2->addWidget( QLEAPaterno );

    tabLayout_4->addLayout( layout5_2, 0, 1 );

    layout5_2_2 = new QVBoxLayout( 0, 0, 6, "layout5_2_2"); 

    textLabel3_2_2 = new QLabel( tab_4, "textLabel3_2_2" );
    textLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout5_2_2->addWidget( textLabel3_2_2 );

    QLEAMaterno = new QLineEdit( tab_4, "QLEAMaterno" );
    layout5_2_2->addWidget( QLEAMaterno );

    tabLayout_4->addLayout( layout5_2_2, 0, 2 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( tab_4, "textLabel1" );
    layout10->addWidget( textLabel1 );

    QCtrEscuelas = new QCtrlEscuelas( tab_4, "QCtrEscuelas" );
    QCtrEscuelas->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)5, 0, 0, QCtrEscuelas->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( QCtrEscuelas );
    layout12->addLayout( layout10 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel2 = new QLabel( tab_4, "textLabel2" );
    layout11->addWidget( textLabel2 );

    QLEGrupo = new QLineEdit( tab_4, "QLEGrupo" );
    layout11->addWidget( QLEGrupo );
    layout12->addLayout( layout11 );
    spacer4 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout12->addItem( spacer4 );

    tabLayout_4->addLayout( layout12, 1, 0 );
    tabWidget2->insertTab( tab_4, QString::fromLatin1("") );

    tab_5 = new QWidget( tabWidget2, "tab_5" );
    tabWidget2->insertTab( tab_5, QString::fromLatin1("") );

    TabPage = new QWidget( tabWidget2, "TabPage" );
    tabWidget2->insertTab( TabPage, QString::fromLatin1("") );

    RegistroClientesLayout->addMultiCellWidget( tabWidget2, 0, 0, 0, 1 );
    languageChange();
    resize( QSize(786, 638).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroClientes::~RegistroClientes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroClientes::languageChange()
{
    setCaption( tr( "Controlador De Clientes" ) );
    QPBRGenerales->setText( tr( "Registra Datos Generales" ) );
    pushButton19->setText( tr( "pushButton19" ) );
    pushButton20->setText( tr( "pushButton20" ) );
    textLabel3_5->setText( tr( "Correo Electronico" ) );
    QPBSDireccion_4_2->setText( tr( ">" ) );
    QPBAntDireccion_4_2->setText( tr( "<" ) );
    QPBAgregarDireccion_4_2->setText( tr( "+" ) );
    QPBAgregarDireccion_4_2->setAccel( QKeySequence( QString::null ) );
    QPBEliminarDireccion_4_2->setText( tr( "-" ) );
    QPBEliminarDireccion_4_2->setAccel( QKeySequence( QString::null ) );
    QPBModificar_4_2->setText( tr( "M" ) );
    QPBModificar_4_2->setAccel( QKeySequence( QString::null ) );
    table6->horizontalHeader()->setLabel( 0, tr( "Correo" ) );
    tabWidget26->changeTab( tab, tr( "Correo Eletronico" ) );
    table1->horizontalHeader()->setLabel( 0, tr( "Calle Y No" ) );
    table1->horizontalHeader()->setLabel( 1, tr( "Colonia" ) );
    table1->horizontalHeader()->setLabel( 2, tr( "CP" ) );
    textLabel4->setText( tr( "Direcciones Registradas" ) );
    QPBSDireccion->setText( tr( ">" ) );
    QPBAntDireccion->setText( tr( "<" ) );
    QPBAgregarDireccion->setText( tr( "+" ) );
    QPBAgregarDireccion->setAccel( QKeySequence( QString::null ) );
    QPBEliminarDireccion->setText( tr( "-" ) );
    QPBEliminarDireccion->setAccel( QKeySequence( QString::null ) );
    QPBModificar->setText( tr( "M" ) );
    QPBModificar->setAccel( QKeySequence( QString::null ) );
    tabWidget3->changeTab( tab_2, tr( "Direcciones" ) );
    QPBSDireccion_4->setText( tr( ">" ) );
    QPBAntDireccion_4->setText( tr( "<" ) );
    QPBAgregarDireccion_4->setText( tr( "+" ) );
    QPBAgregarDireccion_4->setAccel( QKeySequence( QString::null ) );
    QPBEliminarDireccion_4->setText( tr( "-" ) );
    QPBEliminarDireccion_4->setAccel( QKeySequence( QString::null ) );
    QPBModificar_4->setText( tr( "M" ) );
    QPBModificar_4->setAccel( QKeySequence( QString::null ) );
    table2->horizontalHeader()->setLabel( 0, tr( "Telefono" ) );
    table2->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    textLabel3_4->setText( tr( "Nombre" ) );
    tabWidget22->changeTab( tab_3, tr( "Telefonos" ) );
    textLabel3->setText( tr( "Nombre" ) );
    textLabel3_2->setText( tr( "Apellido Paterno" ) );
    textLabel3_2_2->setText( tr( "Apellido Materno" ) );
    textLabel1->setText( tr( "Escuela" ) );
    textLabel2->setText( tr( "Grupo" ) );
    tabWidget2->changeTab( tab_4, tr( "Alumnos" ) );
    tabWidget2->changeTab( tab_5, tr( "Persona Fisica" ) );
    tabWidget2->changeTab( TabPage, tr( "Persona Moral" ) );
}

