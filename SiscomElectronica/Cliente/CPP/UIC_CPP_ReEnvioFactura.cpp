/****************************************************************************
** Form implementation generated from reading ui file 'UI/ReEnvioFactura.ui'
**
** Created: lun abr 1 18:57:54 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ReEnvioFactura.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a ReEnvioFactura as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
ReEnvioFactura::ReEnvioFactura( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "ReEnvioFactura" );
    ReEnvioFacturaLayout = new QGridLayout( this, 1, 1, 11, 6, "ReEnvioFacturaLayout"); 

    layout10_2 = new QVBoxLayout( 0, 0, 6, "layout10_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout10_2->addWidget( textLabel1_2 );

    QLERFC = new QLineEdit( this, "QLERFC" );
    layout10_2->addWidget( QLERFC );

    ReEnvioFacturaLayout->addLayout( layout10_2, 0, 1 );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    QPBReEnvia = new QPushButton( this, "QPBReEnvia" );
    QPBReEnvia->setEnabled( FALSE );
    QPBReEnvia->setAutoDefault( FALSE );
    layout13->addWidget( QPBReEnvia );

    pushButton5_2 = new QPushButton( this, "pushButton5_2" );
    pushButton5_2->setAutoDefault( FALSE );
    layout13->addWidget( pushButton5_2 );

    pushButton5_2_2 = new QPushButton( this, "pushButton5_2_2" );
    pushButton5_2_2->setAutoDefault( FALSE );
    layout13->addWidget( pushButton5_2_2 );

    ReEnvioFacturaLayout->addMultiCellLayout( layout13, 3, 3, 0, 1 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout12->addWidget( textLabel2 );

    QTCorreos = new QTable( this, "QTCorreos" );
    QTCorreos->setNumCols( QTCorreos->numCols() + 1 );
    QTCorreos->horizontalHeader()->setLabel( QTCorreos->numCols() - 1, tr( "Correo" ) );
    QTCorreos->setNumRows( 0 );
    QTCorreos->setNumCols( 1 );
    layout12->addWidget( QTCorreos );

    ReEnvioFacturaLayout->addMultiCellLayout( layout12, 2, 2, 0, 1 );

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout10->addWidget( textLabel1 );

    QLERazonSocial = new QLineEdit( this, "QLERazonSocial" );
    layout10->addWidget( QLERazonSocial );

    ReEnvioFacturaLayout->addLayout( layout10, 0, 0 );

    layout10_3 = new QVBoxLayout( 0, 0, 6, "layout10_3"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    layout10_3->addWidget( textLabel1_3 );

    QLEOtroCorreo = new QLineEdit( this, "QLEOtroCorreo" );
    layout10_3->addWidget( QLEOtroCorreo );

    ReEnvioFacturaLayout->addMultiCellLayout( layout10_3, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(600, 485).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReEnvioFactura::~ReEnvioFactura()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReEnvioFactura::languageChange()
{
    setCaption( tr( "Re Enviando Factura" ) );
    textLabel1_2->setText( tr( "RFC" ) );
    QPBReEnvia->setText( tr( "Envia" ) );
    pushButton5_2->setText( tr( "Agrega Correo" ) );
    pushButton5_2_2->setText( tr( "Cancelar" ) );
    textLabel2->setText( tr( "Correos" ) );
    QTCorreos->horizontalHeader()->setLabel( 0, tr( "Correo" ) );
    textLabel1->setText( tr( "Razon Social" ) );
    textLabel1_3->setText( tr( "Otro Correo" ) );
}

