/****************************************************************************
** Form implementation generated from reading ui file 'UI/ManejadorExpendios.ui'
**
** Created: Wed Apr 10 20:52:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ManejadorExpendios.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <QCtrlExpendios.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlExpendios.h"

/*
 *  Constructs a ManejadorExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ManejadorExpendios::ManejadorExpendios( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ManejadorExpendios" );
    ManejadorExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "ManejadorExpendiosLayout"); 

    layout30 = new QVBoxLayout( 0, 0, 6, "layout30"); 

    layout28 = new QHBoxLayout( 0, 0, 6, "layout28"); 

    layout19 = new QVBoxLayout( 0, 0, 6, "layout19"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout19->addWidget( textLabel2 );

    QLERazonSocial = new QLineEdit( this, "QLERazonSocial" );
    layout19->addWidget( QLERazonSocial );
    layout28->addLayout( layout19 );

    layout19_2 = new QVBoxLayout( 0, 0, 6, "layout19_2"); 

    textLabel2_2 = new QLabel( this, "textLabel2_2" );
    textLabel2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2->sizePolicy().hasHeightForWidth() ) );
    layout19_2->addWidget( textLabel2_2 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    QLERFC->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLERFC->sizePolicy().hasHeightForWidth() ) );
    layout19_2->addWidget( QLERFC );
    layout28->addLayout( layout19_2 );
    layout30->addLayout( layout28 );

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    layout19_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_2"); 

    textLabel2_2_2 = new QLabel( this, "textLabel2_2_2" );
    layout19_2_2->addWidget( textLabel2_2_2 );

    QLEDireccionIp = new QLineEdit( this, "QLEDireccionIp" );
    QLEDireccionIp->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEDireccionIp->sizePolicy().hasHeightForWidth() ) );
    layout19_2_2->addWidget( QLEDireccionIp );
    layout29->addLayout( layout19_2_2 );

    layout19_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_2_2"); 

    textLabel2_2_2_2 = new QLabel( this, "textLabel2_2_2_2" );
    textLabel2_2_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2_2_2_2->sizePolicy().hasHeightForWidth() ) );
    layout19_2_2_2->addWidget( textLabel2_2_2_2 );

    QLEPuerto = new QLineEdit( this, "QLEPuerto" );
    QLEPuerto->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEPuerto->sizePolicy().hasHeightForWidth() ) );
    layout19_2_2_2->addWidget( QLEPuerto );
    layout29->addLayout( layout19_2_2_2 );

    layout19_2_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout19_2_2_2_2"); 

    textLabel2_2_2_2_2 = new QLabel( this, "textLabel2_2_2_2_2" );
    layout19_2_2_2_2->addWidget( textLabel2_2_2_2_2 );

    QLEBase = new QLineEdit( this, "QLEBase" );
    layout19_2_2_2_2->addWidget( QLEBase );
    layout29->addLayout( layout19_2_2_2_2 );
    layout30->addLayout( layout29 );

    ManejadorExpendiosLayout->addLayout( layout30, 0, 0 );

    layout31 = new QVBoxLayout( 0, 0, 6, "layout31"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout31->addWidget( textLabel4 );

    QCtrExpendios = new QCtrlExpendios( this, "QCtrExpendios" );
    layout31->addWidget( QCtrExpendios );

    ManejadorExpendiosLayout->addLayout( layout31, 1, 0 );

    layout47 = new QHBoxLayout( 0, 0, 6, "layout47"); 

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    layout47->addWidget( QPBRegistra );

    QPBIniciar = new QPushButton( this, "QPBIniciar" );
    layout47->addWidget( QPBIniciar );

    QPBActualiza = new QPushButton( this, "QPBActualiza" );
    layout47->addWidget( QPBActualiza );

    QPBElimina = new QPushButton( this, "QPBElimina" );
    layout47->addWidget( QPBElimina );

    ManejadorExpendiosLayout->addLayout( layout47, 2, 0 );
    languageChange();
    resize( QSize(600, 363).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ManejadorExpendios::~ManejadorExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ManejadorExpendios::languageChange()
{
    setCaption( tr( "Registro De Expendios" ) );
    textLabel2->setText( tr( "Razon Social" ) );
    textLabel2_2->setText( tr( "RFC" ) );
    textLabel2_2_2->setText( tr( "Direccion Ip" ) );
    textLabel2_2_2_2->setText( tr( "Puerto Comunicaciones" ) );
    textLabel2_2_2_2_2->setText( tr( "Base De Datos" ) );
    textLabel4->setText( tr( "Expendios Registrados" ) );
    QPBRegistra->setText( tr( "Registrar" ) );
    QPBRegistra->setAccel( QKeySequence( QString::null ) );
    QPBIniciar->setText( tr( "Iniciar Expendio" ) );
    QPBIniciar->setAccel( QKeySequence( QString::null ) );
    QPBActualiza->setText( tr( "Actualizar Datos" ) );
    QPBActualiza->setAccel( QKeySequence( tr( "Shift+Q" ) ) );
    QPBElimina->setText( tr( "Eliminar" ) );
}

