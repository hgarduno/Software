/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroEmpresa.ui'
**
** Created: Fri Apr 12 21:36:41 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroEmpresa.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qtoolbox.h>
#include <qtabwidget.h>
#include <QSisSepomex.h>
#include <qgroupbox.h>
#include <qtextedit.h>
#include <QCtrlMedComunicacion.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QSisSepomex.h"
#include "QCtrlMedComunicacion.h"

/*
 *  Constructs a RegistroEmpresa as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroEmpresa::RegistroEmpresa( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroEmpresa" );
    RegistroEmpresaLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroEmpresaLayout"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout19->addWidget( textLabel5 );

    QLERSocial = new QLineEdit( this, "QLERSocial" );
    layout19->addWidget( QLERSocial );

    RegistroEmpresaLayout->addLayout( layout19, 0, 0 );

    layout12 = new QHBoxLayout( 0, 0, 6, "layout12"); 

    QBGTipo = new QButtonGroup( this, "QBGTipo" );
    QBGTipo->setColumnLayout(0, Qt::Vertical );
    QBGTipo->layout()->setSpacing( 6 );
    QBGTipo->layout()->setMargin( 11 );
    QBGTipoLayout = new QGridLayout( QBGTipo->layout() );
    QBGTipoLayout->setAlignment( Qt::AlignTop );

    radioButton2 = new QRadioButton( QBGTipo, "radioButton2" );

    QBGTipoLayout->addWidget( radioButton2, 1, 0 );

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    radioButton1 = new QRadioButton( QBGTipo, "radioButton1" );
    layout33->addWidget( radioButton1 );

    radioButton3 = new QRadioButton( QBGTipo, "radioButton3" );
    layout33->addWidget( radioButton3 );

    QBGTipoLayout->addLayout( layout33, 0, 0 );
    layout12->addWidget( QBGTipo );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)5, 0, 0, QPBRegistrar->sizePolicy().hasHeightForWidth() ) );
    layout12->addWidget( QPBRegistrar );

    RegistroEmpresaLayout->addLayout( layout12, 2, 0 );

    QTBEmpresas = new QToolBox( this, "QTBEmpresas" );
    QTBEmpresas->setCurrentIndex( 1 );

    page1 = new QWidget( QTBEmpresas, "page1" );
    page1->setBackgroundMode( QWidget::PaletteBackground );
    page1Layout = new QGridLayout( page1, 1, 1, 11, 6, "page1Layout"); 

    tabWidget2 = new QTabWidget( page1, "tabWidget2" );

    tab = new QWidget( tabWidget2, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    QCtrSepomex = new QSisSepomex( tab, "QCtrSepomex" );

    tabLayout->addWidget( QCtrSepomex, 0, 0 );
    spacer4 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    tabLayout->addItem( spacer4, 1, 0 );
    tabWidget2->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( tabWidget2, "tab_2" );
    tabLayout_2 = new QGridLayout( tab_2, 1, 1, 11, 6, "tabLayout_2"); 

    groupBox3 = new QGroupBox( tab_2, "groupBox3" );
    groupBox3->setColumnLayout(0, Qt::Vertical );
    groupBox3->layout()->setSpacing( 6 );
    groupBox3->layout()->setMargin( 11 );
    groupBox3Layout = new QGridLayout( groupBox3->layout() );
    groupBox3Layout->setAlignment( Qt::AlignTop );

    layout23 = new QHBoxLayout( 0, 0, 6, "layout23"); 

    layout20 = new QVBoxLayout( 0, 0, 6, "layout20"); 

    textLabel6 = new QLabel( groupBox3, "textLabel6" );
    layout20->addWidget( textLabel6 );

    QLENombre = new QLineEdit( groupBox3, "QLENombre" );
    layout20->addWidget( QLENombre );
    layout23->addLayout( layout20 );

    layout20_2 = new QVBoxLayout( 0, 0, 6, "layout20_2"); 

    textLabel6_2 = new QLabel( groupBox3, "textLabel6_2" );
    layout20_2->addWidget( textLabel6_2 );

    QLEAPaterno = new QLineEdit( groupBox3, "QLEAPaterno" );
    layout20_2->addWidget( QLEAPaterno );
    layout23->addLayout( layout20_2 );

    layout20_2_2 = new QVBoxLayout( 0, 0, 6, "layout20_2_2"); 

    textLabel6_2_2 = new QLabel( groupBox3, "textLabel6_2_2" );
    layout20_2_2->addWidget( textLabel6_2_2 );

    QLEAMaterno = new QLineEdit( groupBox3, "QLEAMaterno" );
    layout20_2_2->addWidget( QLEAMaterno );
    layout23->addLayout( layout20_2_2 );

    groupBox3Layout->addLayout( layout23, 0, 0 );

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel8 = new QLabel( groupBox3, "textLabel8" );
    layout26->addWidget( textLabel8 );

    QTEDscContacto = new QTextEdit( groupBox3, "QTEDscContacto" );
    layout26->addWidget( QTEDscContacto );

    groupBox3Layout->addLayout( layout26, 1, 0 );

    tabLayout_2->addWidget( groupBox3, 0, 0 );
    tabWidget2->insertTab( tab_2, QString::fromLatin1("") );

    TabPage = new QWidget( tabWidget2, "TabPage" );
    TabPageLayout = new QGridLayout( TabPage, 1, 1, 11, 6, "TabPageLayout"); 

    groupBox4 = new QGroupBox( TabPage, "groupBox4" );
    groupBox4->setColumnLayout(0, Qt::Vertical );
    groupBox4->layout()->setSpacing( 6 );
    groupBox4->layout()->setMargin( 11 );
    groupBox4Layout = new QGridLayout( groupBox4->layout() );
    groupBox4Layout->setAlignment( Qt::AlignTop );

    layout20_3 = new QHBoxLayout( 0, 0, 6, "layout20_3"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel1_3 = new QLabel( groupBox4, "textLabel1_3" );
    layout11->addWidget( textLabel1_3 );

    QCtrMedCom = new QCtrlMedComunicacion( groupBox4, "QCtrMedCom" );
    layout11->addWidget( QCtrMedCom );
    layout20_3->addLayout( layout11 );

    layout19_2 = new QVBoxLayout( 0, 0, 6, "layout19_2"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( groupBox4, "textLabel1" );
    layout10->addWidget( textLabel1 );

    QLEMedio = new QLineEdit( groupBox4, "QLEMedio" );
    QLEMedio->setEnabled( TRUE );
    layout10->addWidget( QLEMedio );
    layout19_2->addLayout( layout10 );
    spacer2 = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layout19_2->addItem( spacer2 );
    layout20_3->addLayout( layout19_2 );

    groupBox4Layout->addLayout( layout20_3, 0, 0 );

    layout26_2 = new QVBoxLayout( 0, 0, 6, "layout26_2"); 

    textLabel8_2 = new QLabel( groupBox4, "textLabel8_2" );
    layout26_2->addWidget( textLabel8_2 );

    QTEDscTelefono = new QTextEdit( groupBox4, "QTEDscTelefono" );
    layout26_2->addWidget( QTEDscTelefono );

    groupBox4Layout->addLayout( layout26_2, 1, 0 );

    TabPageLayout->addWidget( groupBox4, 0, 0 );
    tabWidget2->insertTab( TabPage, QString::fromLatin1("") );

    page1Layout->addWidget( tabWidget2, 0, 0 );
    QTBEmpresas->addItem( page1, QString::fromLatin1("") );

    page2 = new QWidget( QTBEmpresas, "page2" );
    page2->setBackgroundMode( QWidget::PaletteBackground );
    page2Layout = new QGridLayout( page2, 1, 1, 11, 6, "page2Layout"); 

    layout28 = new QVBoxLayout( 0, 0, 6, "layout28"); 

    layout24 = new QVBoxLayout( 0, 0, 6, "layout24"); 

    textLabel3 = new QLabel( page2, "textLabel3" );
    layout24->addWidget( textLabel3 );

    QTDirecciones = new QTable( page2, "QTDirecciones" );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Calle" ) );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "#" ) );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Colonia" ) );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Delegacion" ) );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Estado" ) );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "CP" ) );
    QTDirecciones->setNumRows( 0 );
    QTDirecciones->setNumCols( 6 );
    QTDirecciones->setReadOnly( TRUE );
    layout24->addWidget( QTDirecciones );
    layout28->addLayout( layout24 );

    layout27 = new QHBoxLayout( 0, 0, 6, "layout27"); 

    layout24_2 = new QVBoxLayout( 0, 0, 6, "layout24_2"); 

    textLabel3_2 = new QLabel( page2, "textLabel3_2" );
    layout24_2->addWidget( textLabel3_2 );

    QTContactos = new QTable( page2, "QTContactos" );
    QTContactos->setNumCols( QTContactos->numCols() + 1 );
    QTContactos->horizontalHeader()->setLabel( QTContactos->numCols() - 1, tr( "Nombre" ) );
    QTContactos->setNumCols( QTContactos->numCols() + 1 );
    QTContactos->horizontalHeader()->setLabel( QTContactos->numCols() - 1, tr( "A. Paterno" ) );
    QTContactos->setNumCols( QTContactos->numCols() + 1 );
    QTContactos->horizontalHeader()->setLabel( QTContactos->numCols() - 1, tr( "A. Materno" ) );
    QTContactos->setNumCols( QTContactos->numCols() + 1 );
    QTContactos->horizontalHeader()->setLabel( QTContactos->numCols() - 1, tr( "Observaciones" ) );
    QTContactos->setNumRows( 0 );
    QTContactos->setNumCols( 4 );
    QTContactos->setReadOnly( TRUE );
    layout24_2->addWidget( QTContactos );
    layout27->addLayout( layout24_2 );

    layout24_2_2 = new QVBoxLayout( 0, 0, 6, "layout24_2_2"); 

    textLabel3_2_2 = new QLabel( page2, "textLabel3_2_2" );
    layout24_2_2->addWidget( textLabel3_2_2 );

    QTMedCom = new QTable( page2, "QTMedCom" );
    QTMedCom->setNumCols( QTMedCom->numCols() + 1 );
    QTMedCom->horizontalHeader()->setLabel( QTMedCom->numCols() - 1, tr( "Medio Comunicacion" ) );
    QTMedCom->setNumCols( QTMedCom->numCols() + 1 );
    QTMedCom->horizontalHeader()->setLabel( QTMedCom->numCols() - 1, tr( "Observaciones" ) );
    QTMedCom->setNumRows( 0 );
    QTMedCom->setNumCols( 2 );
    QTMedCom->setReadOnly( TRUE );
    layout24_2_2->addWidget( QTMedCom );
    layout27->addLayout( layout24_2_2 );
    layout28->addLayout( layout27 );

    page2Layout->addLayout( layout28, 0, 0 );
    QTBEmpresas->addItem( page2, QString::fromLatin1("") );

    page = new QWidget( QTBEmpresas, "page" );
    page->setBackgroundMode( QWidget::PaletteBackground );
    QTBEmpresas->addItem( page, QString::fromLatin1("") );

    page_2 = new QWidget( QTBEmpresas, "page_2" );
    page_2->setBackgroundMode( QWidget::PaletteBackground );
    QTBEmpresas->addItem( page_2, QString::fromLatin1("") );

    page_3 = new QWidget( QTBEmpresas, "page_3" );
    page_3->setBackgroundMode( QWidget::PaletteBackground );
    QTBEmpresas->addItem( page_3, QString::fromLatin1("") );

    RegistroEmpresaLayout->addWidget( QTBEmpresas, 1, 0 );
    languageChange();
    resize( QSize(722, 607).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroEmpresa::~RegistroEmpresa()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroEmpresa::languageChange()
{
    setCaption( tr( "Registro De Empresas" ) );
    textLabel5->setText( tr( "Razon Social" ) );
    QBGTipo->setTitle( tr( "Tipo De Empresa" ) );
    radioButton2->setText( tr( "Proveedor" ) );
    radioButton1->setText( tr( "Cliente" ) );
    radioButton3->setText( tr( "Expendio" ) );
    QPBRegistrar->setText( tr( "Registra Empresa" ) );
    tabWidget2->changeTab( tab, tr( "Direccion" ) );
    groupBox3->setTitle( tr( "Datos Contacto" ) );
    textLabel6->setText( tr( "Nombre" ) );
    textLabel6_2->setText( tr( "Apellido Paterno" ) );
    textLabel6_2_2->setText( tr( "Apellido Materno" ) );
    textLabel8->setText( tr( "Descripcion" ) );
    tabWidget2->changeTab( tab_2, tr( "Datos Contacto" ) );
    groupBox4->setTitle( tr( "Datos Comunicacion" ) );
    textLabel1_3->setText( tr( "Medios De Comunicacion" ) );
    textLabel1->setText( tr( "Dato" ) );
    textLabel8_2->setText( tr( "Descripcion" ) );
    tabWidget2->changeTab( TabPage, tr( "Datos Comunicacion" ) );
    QTBEmpresas->setItemLabel( QTBEmpresas->indexOf(page1), tr( "Captura Datos" ) );
    textLabel3->setText( tr( "Direcciones Registradas" ) );
    QTDirecciones->horizontalHeader()->setLabel( 0, tr( "Calle" ) );
    QTDirecciones->horizontalHeader()->setLabel( 1, tr( "#" ) );
    QTDirecciones->horizontalHeader()->setLabel( 2, tr( "Colonia" ) );
    QTDirecciones->horizontalHeader()->setLabel( 3, tr( "Delegacion" ) );
    QTDirecciones->horizontalHeader()->setLabel( 4, tr( "Estado" ) );
    QTDirecciones->horizontalHeader()->setLabel( 5, tr( "CP" ) );
    textLabel3_2->setText( tr( "Contactos" ) );
    QTContactos->horizontalHeader()->setLabel( 0, tr( "Nombre" ) );
    QTContactos->horizontalHeader()->setLabel( 1, tr( "A. Paterno" ) );
    QTContactos->horizontalHeader()->setLabel( 2, tr( "A. Materno" ) );
    QTContactos->horizontalHeader()->setLabel( 3, tr( "Observaciones" ) );
    textLabel3_2_2->setText( tr( "Medios De Comunicacion" ) );
    QTMedCom->horizontalHeader()->setLabel( 0, tr( "Medio Comunicacion" ) );
    QTMedCom->horizontalHeader()->setLabel( 1, tr( "Observaciones" ) );
    QTBEmpresas->setItemLabel( QTBEmpresas->indexOf(page2), tr( "Informacion De La Empresa" ) );
    QTBEmpresas->setItemLabel( QTBEmpresas->indexOf(page), tr( "Mantenimiento De Contactos" ) );
    QTBEmpresas->setItemLabel( QTBEmpresas->indexOf(page_2), tr( "Mantenimiento De Direcciones" ) );
    QTBEmpresas->setItemLabel( QTBEmpresas->indexOf(page_3), tr( "Mantenimiento De Medios De Comunicacion" ) );
}

