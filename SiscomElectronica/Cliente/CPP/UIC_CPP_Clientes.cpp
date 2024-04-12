/****************************************************************************
** Form implementation generated from reading ui file 'UI/Clientes.ui'
**
** Created: Thu Apr 11 21:53:25 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Clientes.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qheader.h>
#include <qlistview.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Clientes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Clientes::Clientes( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Clientes" );
    ClientesLayout = new QGridLayout( this, 1, 1, 11, 6, "ClientesLayout"); 

    QTWTipoPersona = new QTabWidget( this, "QTWTipoPersona" );

    tab = new QWidget( QTWTipoPersona, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    layout50 = new QHBoxLayout( 0, 0, 6, "layout50"); 

    layout46 = new QVBoxLayout( 0, 0, 6, "layout46"); 

    textLabel10 = new QLabel( tab, "textLabel10" );
    layout46->addWidget( textLabel10 );

    QLENombre = new QLineEdit( tab, "QLENombre" );
    layout46->addWidget( QLENombre );
    layout50->addLayout( layout46 );

    layout46_2 = new QVBoxLayout( 0, 0, 6, "layout46_2"); 

    textLabel10_2 = new QLabel( tab, "textLabel10_2" );
    layout46_2->addWidget( textLabel10_2 );

    QLEAPaterno = new QLineEdit( tab, "QLEAPaterno" );
    layout46_2->addWidget( QLEAPaterno );
    layout50->addLayout( layout46_2 );

    layout46_2_2 = new QVBoxLayout( 0, 0, 6, "layout46_2_2"); 

    textLabel10_2_2 = new QLabel( tab, "textLabel10_2_2" );
    layout46_2_2->addWidget( textLabel10_2_2 );

    QLEAMaterno = new QLineEdit( tab, "QLEAMaterno" );
    layout46_2_2->addWidget( QLEAMaterno );
    layout50->addLayout( layout46_2_2 );

    layout46_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout46_2_2_2"); 

    textLabel10_2_2_2 = new QLabel( tab, "textLabel10_2_2_2" );
    layout46_2_2_2->addWidget( textLabel10_2_2_2 );

    QLERFC = new QLineEdit( tab, "QLERFC" );
    layout46_2_2_2->addWidget( QLERFC );
    layout50->addLayout( layout46_2_2_2 );

    tabLayout->addLayout( layout50, 0, 0 );
    QTWTipoPersona->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( QTWTipoPersona, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    layout53 = new QHBoxLayout( 0, 0, 6, "layout53"); 

    layout51 = new QVBoxLayout( 0, 0, 6, "layout51"); 

    textLabel11 = new QLabel( tab_2, "textLabel11" );
    layout51->addWidget( textLabel11 );

    QLERazonSocial = new QLineEdit( tab_2, "QLERazonSocial" );
    layout51->addWidget( QLERazonSocial );
    layout53->addLayout( layout51 );

    layout46_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout46_2_2_2_2"); 

    textLabel10_2_2_2_2 = new QLabel( tab_2, "textLabel10_2_2_2_2" );
    textLabel10_2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel10_2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout46_2_2_2_2->addWidget( textLabel10_2_2_2_2 );

    QLERFCEmpresa = new QLineEdit( tab_2, "QLERFCEmpresa" );
    QLERFCEmpresa->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLERFCEmpresa->sizePolicy().hasHeightForWidth() ) );
    QLERFCEmpresa->setMinimumSize( QSize( 150, 0 ) );
    QLERFCEmpresa->setMaximumSize( QSize( 150, 32767 ) );
    layout46_2_2_2_2->addWidget( QLERFCEmpresa );
    layout53->addLayout( layout46_2_2_2_2 );

    tabLayout_2->addLayout( layout53, 0, 0 );
    QTWTipoPersona->insertTab( tab_2, QString::fromLatin1("") );

    TabPage = new QWidget( QTWTipoPersona, "TabPage" );
    QTWTipoPersona->insertTab( TabPage, QString::fromLatin1("") );

    ClientesLayout->addMultiCellWidget( QTWTipoPersona, 0, 0, 0, 1 );

    layout54 = new QHBoxLayout( 0, 0, 6, "layout54"); 

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout54->addWidget( QPBRegistrar );

    QPBBuscar = new QPushButton( this, "QPBBuscar" );
    layout54->addWidget( QPBBuscar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    layout54->addWidget( QPBEliminar );

    ClientesLayout->addMultiCellLayout( layout54, 2, 2, 0, 1 );

    layout44 = new QVBoxLayout( 0, 0, 6, "layout44"); 

    tabWidget4 = new QTabWidget( this, "tabWidget4" );

    tab_3 = new QWidget( tabWidget4, "tab_3" );
    tabLayout_3 = new QGridLayout( tab_3, 1, 1, 11, 6, "tabLayout_3"); 

    layout42 = new QVBoxLayout( 0, 0, 6, "layout42"); 

    layout41 = new QHBoxLayout( 0, 0, 6, "layout41"); 

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel9 = new QLabel( tab_3, "textLabel9" );
    layout24->addWidget( textLabel9 );

    QLETelefono = new QLineEdit( tab_3, "QLETelefono" );
    QLETelefono->setMinimumSize( QSize( 100, 0 ) );
    QLETelefono->setMaximumSize( QSize( 100, 32767 ) );
    layout24->addWidget( QLETelefono );
    layout41->addLayout( layout24 );

    layout24_2 = new QVBoxLayout( 0, 0, 6, "layout24_2"); 

    textLabel9_2 = new QLabel( tab_3, "textLabel9_2" );
    layout24_2->addWidget( textLabel9_2 );

    QLEDescripcion = new QLineEdit( tab_3, "QLEDescripcion" );
    layout24_2->addWidget( QLEDescripcion );
    layout41->addLayout( layout24_2 );
    layout42->addLayout( layout41 );

    QLVTelefonos = new QListView( tab_3, "QLVTelefonos" );
    QLVTelefonos->addColumn( tr( "Telefonos" ) );
    layout42->addWidget( QLVTelefonos );

    tabLayout_3->addLayout( layout42, 0, 0 );

    layout43 = new QHBoxLayout( 0, 0, 6, "layout43"); 

    layout23_2 = new QHBoxLayout( 0, 0, 6, "layout23_2"); 

    QPBAnexarTelefono = new QPushButton( tab_3, "QPBAnexarTelefono" );
    QPBAnexarTelefono->setMinimumSize( QSize( 20, 0 ) );
    QPBAnexarTelefono->setMaximumSize( QSize( 20, 32767 ) );
    layout23_2->addWidget( QPBAnexarTelefono );

    QPBEliminarTelefono = new QPushButton( tab_3, "QPBEliminarTelefono" );
    QPBEliminarTelefono->setMinimumSize( QSize( 20, 0 ) );
    QPBEliminarTelefono->setMaximumSize( QSize( 20, 32767 ) );
    layout23_2->addWidget( QPBEliminarTelefono );
    layout43->addLayout( layout23_2 );
    spacer4 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout43->addItem( spacer4 );

    tabLayout_3->addLayout( layout43, 1, 0 );
    tabWidget4->insertTab( tab_3, QString::fromLatin1("") );
    layout44->addWidget( tabWidget4 );

    tabWidget8 = new QTabWidget( this, "tabWidget8" );

    tab_4 = new QWidget( tabWidget8, "tab_4" );
    tabLayout_4 = new QGridLayout( tab_4, 1, 1, 11, 6, "tabLayout_4"); 

    layout24_2_2 = new QVBoxLayout( 0, 0, 6, "layout24_2_2"); 

    textLabel9_2_2 = new QLabel( tab_4, "textLabel9_2_2" );
    layout24_2_2->addWidget( textLabel9_2_2 );

    lineEdit10_2_2 = new QLineEdit( tab_4, "lineEdit10_2_2" );
    layout24_2_2->addWidget( lineEdit10_2_2 );

    tabLayout_4->addMultiCellLayout( layout24_2_2, 0, 0, 0, 1 );

    layout23_2_2 = new QHBoxLayout( 0, 0, 6, "layout23_2_2"); 

    QPBAnexarCorreo = new QPushButton( tab_4, "QPBAnexarCorreo" );
    QPBAnexarCorreo->setMinimumSize( QSize( 20, 0 ) );
    QPBAnexarCorreo->setMaximumSize( QSize( 20, 32767 ) );
    layout23_2_2->addWidget( QPBAnexarCorreo );

    QPBEliminarCorreo = new QPushButton( tab_4, "QPBEliminarCorreo" );
    QPBEliminarCorreo->setMinimumSize( QSize( 20, 0 ) );
    QPBEliminarCorreo->setMaximumSize( QSize( 20, 32767 ) );
    layout23_2_2->addWidget( QPBEliminarCorreo );

    tabLayout_4->addLayout( layout23_2_2, 2, 0 );
    spacer3 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout_4->addItem( spacer3, 2, 1 );

    QLVCorreos = new QListView( tab_4, "QLVCorreos" );
    QLVCorreos->addColumn( tr( "Correos" ) );

    tabLayout_4->addMultiCellWidget( QLVCorreos, 1, 1, 0, 1 );
    tabWidget8->insertTab( tab_4, QString::fromLatin1("") );
    layout44->addWidget( tabWidget8 );

    ClientesLayout->addLayout( layout44, 1, 1 );

    tabWidget3 = new QTabWidget( this, "tabWidget3" );

    tab_5 = new QWidget( tabWidget3, "tab_5" );
    tabLayout_5 = new QGridLayout( tab_5, 1, 1, 11, 6, "tabLayout_5"); 

    layout21 = new QVBoxLayout( 0, 0, 6, "layout21"); 

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel2 = new QLabel( tab_5, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel2 );

    QLECalle = new QLineEdit( tab_5, "QLECalle" );
    QLECalle->setMinimumSize( QSize( 200, 0 ) );
    layout9->addWidget( QLECalle );
    layout14->addLayout( layout9 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel3 = new QLabel( tab_5, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel3 );

    QLENo = new QLineEdit( tab_5, "QLENo" );
    QLENo->setMinimumSize( QSize( 100, 0 ) );
    layout11->addWidget( QLENo );
    layout14->addLayout( layout11 );

    layout11_2 = new QVBoxLayout( 0, 0, 6, "layout11_2"); 

    textLabel3_2 = new QLabel( tab_5, "textLabel3_2" );
    textLabel3_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( textLabel3_2 );

    QLECP = new QLineEdit( tab_5, "QLECP" );
    QLECP->setMinimumSize( QSize( 50, 0 ) );
    QLECP->setMaximumSize( QSize( 50, 32767 ) );
    layout11_2->addWidget( QLECP );
    layout14->addLayout( layout11_2 );

    layout11_2_2 = new QVBoxLayout( 0, 0, 6, "layout11_2_2"); 

    textLabel3_2_2 = new QLabel( tab_5, "textLabel3_2_2" );
    textLabel3_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel3_2_2->sizePolicy().hasHeightForWidth() ) );
    layout11_2_2->addWidget( textLabel3_2_2 );

    QLEColonia = new QLineEdit( tab_5, "QLEColonia" );
    QLEColonia->setMinimumSize( QSize( 150, 0 ) );
    layout11_2_2->addWidget( QLEColonia );
    layout14->addLayout( layout11_2_2 );
    layout21->addLayout( layout14 );

    layout18 = new QHBoxLayout( 0, 0, 6, "layout18"); 

    layout15 = new QVBoxLayout( 0, 0, 6, "layout15"); 

    textLabel4 = new QLabel( tab_5, "textLabel4" );
    layout15->addWidget( textLabel4 );

    QLEMunicipio = new QLineEdit( tab_5, "QLEMunicipio" );
    layout15->addWidget( QLEMunicipio );
    layout18->addLayout( layout15 );

    layout17 = new QVBoxLayout( 0, 0, 6, "layout17"); 

    textLabel6 = new QLabel( tab_5, "textLabel6" );
    layout17->addWidget( textLabel6 );

    QCBEstados = new QComboBox( FALSE, tab_5, "QCBEstados" );
    QCBEstados->setAutoCompletion( TRUE );
    QCBEstados->setDuplicatesEnabled( FALSE );
    layout17->addWidget( QCBEstados );
    layout18->addLayout( layout17 );
    layout21->addLayout( layout18 );

    tabLayout_5->addMultiCellLayout( layout21, 0, 0, 0, 5 );

    layout22 = new QVBoxLayout( 0, 0, 6, "layout22"); 

    textLabel8 = new QLabel( tab_5, "textLabel8" );
    layout22->addWidget( textLabel8 );

    QTEDirecciones = new QTextEdit( tab_5, "QTEDirecciones" );
    QTEDirecciones->setWordWrap( QTextEdit::WidgetWidth );
    QTEDirecciones->setReadOnly( TRUE );
    layout22->addWidget( QTEDirecciones );

    tabLayout_5->addMultiCellLayout( layout22, 1, 1, 0, 5 );
    spacer2 = new QSpacerItem( 320, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    tabLayout_5->addItem( spacer2, 2, 5 );

    QPBSDireccion = new QPushButton( tab_5, "QPBSDireccion" );
    QPBSDireccion->setMinimumSize( QSize( 20, 0 ) );
    QPBSDireccion->setMaximumSize( QSize( 20, 32767 ) );

    tabLayout_5->addWidget( QPBSDireccion, 2, 0 );

    QPBAntDireccion = new QPushButton( tab_5, "QPBAntDireccion" );
    QPBAntDireccion->setMinimumSize( QSize( 20, 0 ) );
    QPBAntDireccion->setMaximumSize( QSize( 20, 32767 ) );

    tabLayout_5->addWidget( QPBAntDireccion, 2, 1 );

    QPBAgregarDireccion = new QPushButton( tab_5, "QPBAgregarDireccion" );
    QPBAgregarDireccion->setMinimumSize( QSize( 20, 0 ) );
    QPBAgregarDireccion->setMaximumSize( QSize( 20, 32767 ) );

    tabLayout_5->addWidget( QPBAgregarDireccion, 2, 2 );

    QPBEliminarDireccion = new QPushButton( tab_5, "QPBEliminarDireccion" );
    QPBEliminarDireccion->setMinimumSize( QSize( 20, 0 ) );
    QPBEliminarDireccion->setMaximumSize( QSize( 20, 32767 ) );

    tabLayout_5->addWidget( QPBEliminarDireccion, 2, 3 );

    QPBModificar = new QPushButton( tab_5, "QPBModificar" );
    QPBModificar->setMinimumSize( QSize( 20, 0 ) );
    QPBModificar->setMaximumSize( QSize( 20, 32767 ) );

    tabLayout_5->addWidget( QPBModificar, 2, 4 );
    tabWidget3->insertTab( tab_5, QString::fromLatin1("") );

    ClientesLayout->addWidget( tabWidget3, 1, 0 );
    languageChange();
    resize( QSize(797, 634).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Clientes::~Clientes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Clientes::languageChange()
{
    setCaption( tr( "Clientes" ) );
    textLabel10->setText( tr( "Nombre" ) );
    textLabel10_2->setText( tr( "Apellido Paterno" ) );
    textLabel10_2_2->setText( tr( "Apellido Materno" ) );
    textLabel10_2_2_2->setText( tr( "RFC" ) );
    QTWTipoPersona->changeTab( tab, tr( "Persona Fisica" ) );
    textLabel11->setText( tr( "Razon Social" ) );
    textLabel10_2_2_2_2->setText( tr( "RFC" ) );
    QTWTipoPersona->changeTab( tab_2, tr( "Empresa" ) );
    QTWTipoPersona->changeTab( TabPage, tr( "Mantenimiento Clientes" ) );
    QPBRegistrar->setText( tr( "Registrar Cliente" ) );
    QPBBuscar->setText( tr( "Buscar Cliente" ) );
    QPBEliminar->setText( tr( "Eliminar Cliente" ) );
    textLabel9->setText( tr( "Telefono" ) );
    QLETelefono->setText( QString::null );
    textLabel9_2->setText( tr( "Descripcion" ) );
    QLVTelefonos->header()->setLabel( 0, tr( "Telefonos" ) );
    QPBAnexarTelefono->setText( tr( "+" ) );
    QPBAnexarTelefono->setAccel( QKeySequence( QString::null ) );
    QPBEliminarTelefono->setText( tr( "-" ) );
    QPBEliminarTelefono->setAccel( QKeySequence( QString::null ) );
    tabWidget4->changeTab( tab_3, tr( "Telefonos" ) );
    textLabel9_2_2->setText( tr( "Correo Electronico" ) );
    lineEdit10_2_2->setText( tr( "hgarduno@gmail.com" ) );
    QPBAnexarCorreo->setText( tr( "+" ) );
    QPBAnexarCorreo->setAccel( QKeySequence( QString::null ) );
    QPBEliminarCorreo->setText( tr( "-" ) );
    QPBEliminarCorreo->setAccel( QKeySequence( QString::null ) );
    QLVCorreos->header()->setLabel( 0, tr( "Correos" ) );
    tabWidget8->changeTab( tab_4, tr( "Correo Electronico" ) );
    textLabel2->setText( tr( "Calle" ) );
    QLECalle->setText( QString::null );
    textLabel3->setText( tr( "No" ) );
    textLabel3_2->setText( tr( "CP" ) );
    QLECP->setText( QString::null );
    textLabel3_2_2->setText( tr( "Colonia" ) );
    QLEColonia->setText( QString::null );
    textLabel4->setText( tr( "Municipio" ) );
    textLabel6->setText( tr( "Estados" ) );
    QCBEstados->clear();
    QCBEstados->insertItem( tr( "Mexico" ) );
    QCBEstados->insertItem( tr( "D.F." ) );
    QCBEstados->insertItem( tr( "Aguascalientes" ) );
    QCBEstados->insertItem( tr( "Zacatecas" ) );
    QCBEstados->insertItem( tr( "Queretaro" ) );
    QCBEstados->insertItem( tr( "Hidalgo" ) );
    textLabel8->setText( tr( "Direcciones" ) );
    QTEDirecciones->setText( QString::null );
    QPBSDireccion->setText( tr( ">" ) );
    QPBAntDireccion->setText( tr( "<" ) );
    QPBAgregarDireccion->setText( tr( "+" ) );
    QPBAgregarDireccion->setAccel( QKeySequence( QString::null ) );
    QPBEliminarDireccion->setText( tr( "-" ) );
    QPBEliminarDireccion->setAccel( QKeySequence( QString::null ) );
    QPBModificar->setText( tr( "M" ) );
    QPBModificar->setAccel( QKeySequence( QString::null ) );
    tabWidget3->changeTab( tab_5, tr( "Direcciones" ) );
}

