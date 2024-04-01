/****************************************************************************
** Form implementation generated from reading ui file 'UI/ClavesProveedor4.ui'
**
** Created: Wed Jan 31 10:48:13 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ClavesProveedor4.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <QCtrlProveedoresSE.h>
#include <QCtrlProductosSE.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "QCtrlProveedoresSE.h"
#include "QCtrlProductosSE.h"

/*
 *  Constructs a ClavesProveedor4 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ClavesProveedor4::ClavesProveedor4( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ClavesProveedor4" );
    ClavesProveedor4Layout = new QGridLayout( this, 1, 1, 11, 6, "ClavesProveedor4Layout"); 

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    layout12->addWidget( textLabel4 );

    QTClaves = new QTable( this, "QTClaves" );
    QTClaves->setNumCols( QTClaves->numCols() + 1 );
    QTClaves->horizontalHeader()->setLabel( QTClaves->numCols() - 1, tr( "Clave Siscom" ) );
    QTClaves->setNumCols( QTClaves->numCols() + 1 );
    QTClaves->horizontalHeader()->setLabel( QTClaves->numCols() - 1, tr( "Clave Proveedor" ) );
    QTClaves->setNumCols( QTClaves->numCols() + 1 );
    QTClaves->horizontalHeader()->setLabel( QTClaves->numCols() - 1, tr( "Descripcion" ) );
    QTClaves->setNumRows( 0 );
    QTClaves->setNumCols( 3 );
    QTClaves->setReadOnly( TRUE );
    layout12->addWidget( QTClaves );

    ClavesProveedor4Layout->addLayout( layout12, 1, 0 );

    layout37 = new QHBoxLayout( 0, 0, 6, "layout37"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setEnabled( FALSE );
    layout37->addWidget( QPBAnexar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    QPBActualizar->setEnabled( FALSE );
    layout37->addWidget( QPBActualizar );

    QPBRegistra = new QPushButton( this, "QPBRegistra" );
    QPBRegistra->setEnabled( FALSE );
    layout37->addWidget( QPBRegistra );

    ClavesProveedor4Layout->addLayout( layout37, 2, 0 );

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout13_2 = new QVBoxLayout( 0, 0, 6, "layout13_2"); 

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( textLabel1 );

    QCtrProveedores = new QCtrlProveedoresSE( this, "QCtrProveedores" );
    QCtrProveedores->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QCtrProveedores->sizePolicy().hasHeightForWidth() ) );
    layout9->addWidget( QCtrProveedores );
    layout13_2->addLayout( layout9 );

    layout12_2 = new QVBoxLayout( 0, 0, 6, "layout12_2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout12_2->addWidget( textLabel2 );

    QCtrProductos = new QCtrlProductosSE( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout12_2->addWidget( QCtrProductos );
    layout13_2->addLayout( layout12_2 );

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel3->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( textLabel3 );

    QLEClaveP = new QLineEdit( this, "QLEClaveP" );
    QLEClaveP->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, QLEClaveP->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( QLEClaveP );
    layout13_2->addLayout( layout11 );
    layout13->addLayout( layout13_2 );

    layout15 = new QHBoxLayout( 0, 0, 6, "layout15"); 

    layout13_3 = new QVBoxLayout( 0, 0, 6, "layout13_3"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5->sizePolicy().hasHeightForWidth() ) );
    layout13_3->addWidget( textLabel5 );

    QTEDescripcionS = new QTextEdit( this, "QTEDescripcionS" );
    QTEDescripcionS->setMinimumSize( QSize( 0, 130 ) );
    QTEDescripcionS->setMaximumSize( QSize( 32767, 136 ) );
    QTEDescripcionS->setReadOnly( TRUE );
    layout13_3->addWidget( QTEDescripcionS );
    layout15->addLayout( layout13_3 );

    layout13_2_2 = new QVBoxLayout( 0, 0, 6, "layout13_2_2"); 

    textLabel5_2 = new QLabel( this, "textLabel5_2" );
    textLabel5_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)0, 0, 0, textLabel5_2->sizePolicy().hasHeightForWidth() ) );
    layout13_2_2->addWidget( textLabel5_2 );

    QTEDescripcionP = new QTextEdit( this, "QTEDescripcionP" );
    QTEDescripcionP->setMinimumSize( QSize( 0, 130 ) );
    QTEDescripcionP->setMaximumSize( QSize( 32767, 136 ) );
    layout13_2_2->addWidget( QTEDescripcionP );
    layout15->addLayout( layout13_2_2 );
    layout13->addLayout( layout15 );

    ClavesProveedor4Layout->addLayout( layout13, 0, 0 );
    languageChange();
    resize( QSize(712, 338).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ClavesProveedor4::~ClavesProveedor4()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ClavesProveedor4::languageChange()
{
    setCaption( tr( "Form2" ) );
    textLabel4->setText( tr( "Productos" ) );
    QTClaves->horizontalHeader()->setLabel( 0, tr( "Clave Siscom" ) );
    QTClaves->horizontalHeader()->setLabel( 1, tr( "Clave Proveedor" ) );
    QTClaves->horizontalHeader()->setLabel( 2, tr( "Descripcion" ) );
    QPBAnexar->setText( tr( "&Anexar" ) );
    QPBAnexar->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    QPBActualizar->setText( tr( "Actualiza" ) );
    QPBRegistra->setText( tr( "Registrar" ) );
    textLabel1->setText( tr( "Proveedores" ) );
    textLabel2->setText( tr( "Productos Siscom" ) );
    textLabel3->setText( tr( "Clave Proveedor" ) );
    textLabel5->setText( tr( "Descripcion Siscom" ) );
    textLabel5_2->setText( tr( "Descripcion Proveedor" ) );
}

