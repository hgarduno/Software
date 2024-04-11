/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroEmpresas2.ui'
**
** Created: Thu Apr 11 20:30:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroEmpresas2.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a RegistroEmpresas2 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
RegistroEmpresas2::RegistroEmpresas2( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "RegistroEmpresas2" );
    RegistroEmpresas2Layout = new QGridLayout( this, 1, 1, 11, 6, "RegistroEmpresas2Layout"); 

    layout8 = new QHBoxLayout( 0, 0, 6, "layout8"); 

    QPBADireccion = new QPushButton( this, "QPBADireccion" );
    layout8->addWidget( QPBADireccion );

    QPBAMedComunicacion = new QPushButton( this, "QPBAMedComunicacion" );
    layout8->addWidget( QPBAMedComunicacion );

    QPBAContacto = new QPushButton( this, "QPBAContacto" );
    layout8->addWidget( QPBAContacto );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    layout8->addWidget( QPBRegistra );

    RegistroEmpresas2Layout->addLayout( layout8, 3, 0 );

    layout9 = new QHBoxLayout( 0, 0, 6, "layout9"); 

    layout7 = new QVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout7->addWidget( textLabel4 );

    QTDirecciones = new QTable( this, "QTDirecciones" );
    QTDirecciones->setNumCols( QTDirecciones->numCols() + 1 );
    QTDirecciones->horizontalHeader()->setLabel( QTDirecciones->numCols() - 1, tr( "Direccion" ) );
    QTDirecciones->setNumRows( 0 );
    QTDirecciones->setNumCols( 1 );
    QTDirecciones->setReadOnly( TRUE );
    layout7->addWidget( QTDirecciones );
    layout9->addLayout( layout7 );

    layout7_2 = new QVBoxLayout( 0, 0, 6, "layout7_2"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    layout7_2->addWidget( textLabel4_2 );

    QTMedComunicacion = new QTable( this, "QTMedComunicacion" );
    QTMedComunicacion->setNumCols( QTMedComunicacion->numCols() + 1 );
    QTMedComunicacion->horizontalHeader()->setLabel( QTMedComunicacion->numCols() - 1, tr( "Dato" ) );
    QTMedComunicacion->setNumCols( QTMedComunicacion->numCols() + 1 );
    QTMedComunicacion->horizontalHeader()->setLabel( QTMedComunicacion->numCols() - 1, tr( "Descripcion" ) );
    QTMedComunicacion->setNumRows( 0 );
    QTMedComunicacion->setNumCols( 2 );
    QTMedComunicacion->setReadOnly( TRUE );
    layout7_2->addWidget( QTMedComunicacion );
    layout9->addLayout( layout7_2 );

    RegistroEmpresas2Layout->addLayout( layout9, 1, 0 );

    layout7_3 = new QVBoxLayout( 0, 0, 6, "layout7_3"); 

    textLabel4_3 = new QLabel( this, "textLabel4_3" );
    layout7_3->addWidget( textLabel4_3 );

    QTContactos = new QTable( this, "QTContactos" );
    QTContactos->setNumCols( QTContactos->numCols() + 1 );
    QTContactos->horizontalHeader()->setLabel( QTContactos->numCols() - 1, tr( "Nombre" ) );
    QTContactos->setNumCols( QTContactos->numCols() + 1 );
    QTContactos->horizontalHeader()->setLabel( QTContactos->numCols() - 1, tr( "Descripcion" ) );
    QTContactos->setNumRows( 0 );
    QTContactos->setNumCols( 2 );
    QTContactos->setReadOnly( TRUE );
    layout7_3->addWidget( QTContactos );

    RegistroEmpresas2Layout->addLayout( layout7_3, 2, 0 );

    layout11 = new QHBoxLayout( 0, 0, 6, "layout11"); 

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout2->addWidget( textLabel2 );

    QLERSocial = new QLineEdit( this, "QLERSocial" );
    layout2->addWidget( QLERSocial );
    layout11->addLayout( layout2 );

    QBGTEmpresa = new QButtonGroup( this, "QBGTEmpresa" );
    QBGTEmpresa->setColumnLayout(0, Qt::Vertical );
    QBGTEmpresa->layout()->setSpacing( 6 );
    QBGTEmpresa->layout()->setMargin( 11 );
    QBGTEmpresaLayout = new QGridLayout( QBGTEmpresa->layout() );
    QBGTEmpresaLayout->setAlignment( Qt::AlignTop );

    layout10 = new QHBoxLayout( 0, 0, 6, "layout10"); 

    radioButton1 = new QRadioButton( QBGTEmpresa, "radioButton1" );
    layout10->addWidget( radioButton1 );

    radioButton2 = new QRadioButton( QBGTEmpresa, "radioButton2" );
    layout10->addWidget( radioButton2 );

    QBGTEmpresaLayout->addLayout( layout10, 0, 0 );
    layout11->addWidget( QBGTEmpresa );

    RegistroEmpresas2Layout->addLayout( layout11, 0, 0 );
    languageChange();
    resize( QSize(676, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroEmpresas2::~RegistroEmpresas2()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroEmpresas2::languageChange()
{
    setCaption( tr( "Form3" ) );
    QPBADireccion->setText( tr( "Anexar Direccion" ) );
    QPBAMedComunicacion->setText( tr( "Anexar Medio De Comunicacion" ) );
    QPBAContacto->setText( tr( "Anexar Contacto" ) );
    QPBRegistra->setText( tr( "Registra" ) );
    textLabel4->setText( tr( "Direcciones" ) );
    QTDirecciones->horizontalHeader()->setLabel( 0, tr( "Direccion" ) );
    textLabel4_2->setText( tr( "Comunicacion" ) );
    QTMedComunicacion->horizontalHeader()->setLabel( 0, tr( "Dato" ) );
    QTMedComunicacion->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    textLabel4_3->setText( tr( "Contactos" ) );
    QTContactos->horizontalHeader()->setLabel( 0, tr( "Nombre" ) );
    QTContactos->horizontalHeader()->setLabel( 1, tr( "Descripcion" ) );
    textLabel2->setText( tr( "Razon Social" ) );
    QBGTEmpresa->setTitle( tr( "Tipo Empresa" ) );
    radioButton1->setText( tr( "Cliente" ) );
    radioButton2->setText( tr( "Proveedor" ) );
}

