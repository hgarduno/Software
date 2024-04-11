/****************************************************************************
** Form implementation generated from reading ui file 'UI/EstadosPedido.ui'
**
** Created: Wed Apr 10 20:52:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_EstadosPedido.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "IMP_QControlFecha.h"

/*
 *  Constructs a EstadosPedido as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
EstadosPedido::EstadosPedido( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "EstadosPedido" );
    EstadosPedidoLayout = new QGridLayout( this, 1, 1, 11, 6, "EstadosPedidoLayout"); 

    layout28 = new QVBoxLayout( 0, 0, 6, "layout28"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    layout28->addWidget( textLabel2 );

    table3 = new QTable( this, "table3" );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Numero Pedido" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Cliente" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Escuela" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Direcion" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Telefono" ) );
    table3->setNumCols( table3->numCols() + 1 );
    table3->horizontalHeader()->setLabel( table3->numCols() - 1, tr( "Edo Pedido" ) );
    table3->setNumRows( 0 );
    table3->setNumCols( 6 );
    layout28->addWidget( table3 );

    EstadosPedidoLayout->addMultiCellLayout( layout28, 1, 1, 0, 3 );

    layout31 = new QHBoxLayout( 0, 0, 6, "layout31"); 

    layout29 = new QHBoxLayout( 0, 0, 6, "layout29"); 

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( textLabel1 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( QCtrFechaInicio );
    layout29->addLayout( layout26 );

    layout26_2 = new QVBoxLayout( 0, 0, 6, "layout26_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout26_2->addWidget( textLabel1_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout26_2->addWidget( QCtrFechaFin );
    layout29->addLayout( layout26_2 );
    layout31->addLayout( layout29 );
    spacer3 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout31->addItem( spacer3 );

    EstadosPedidoLayout->addMultiCellLayout( layout31, 0, 0, 0, 3 );

    pushButton14 = new QPushButton( this, "pushButton14" );
    pushButton14->setAutoDefault( FALSE );

    EstadosPedidoLayout->addWidget( pushButton14, 2, 0 );

    QPBConsulta = new QPushButton( this, "QPBConsulta" );
    QPBConsulta->setAutoDefault( FALSE );

    EstadosPedidoLayout->addWidget( QPBConsulta, 2, 1 );

    pushButton14_2 = new QPushButton( this, "pushButton14_2" );
    pushButton14_2->setAutoDefault( FALSE );

    EstadosPedidoLayout->addWidget( pushButton14_2, 2, 2 );

    pushButton14_2_2 = new QPushButton( this, "pushButton14_2_2" );
    pushButton14_2_2->setAutoDefault( FALSE );

    EstadosPedidoLayout->addWidget( pushButton14_2_2, 2, 3 );
    languageChange();
    resize( QSize(845, 442).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EstadosPedido::~EstadosPedido()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EstadosPedido::languageChange()
{
    setCaption( tr( "Estados Pedido" ) );
    textLabel2->setText( tr( "textLabel2" ) );
    table3->horizontalHeader()->setLabel( 0, tr( "Numero Pedido" ) );
    table3->horizontalHeader()->setLabel( 1, tr( "Cliente" ) );
    table3->horizontalHeader()->setLabel( 2, tr( "Escuela" ) );
    table3->horizontalHeader()->setLabel( 3, tr( "Direcion" ) );
    table3->horizontalHeader()->setLabel( 4, tr( "Telefono" ) );
    table3->horizontalHeader()->setLabel( 5, tr( "Edo Pedido" ) );
    textLabel1->setText( tr( "Fecha Inicio" ) );
    textLabel1_2->setText( tr( "Fecha Fin" ) );
    pushButton14->setText( tr( "Pedido Entregado" ) );
    QPBConsulta->setText( tr( "Consulta" ) );
    pushButton14_2->setText( tr( "Aceptar" ) );
    pushButton14_2_2->setText( tr( "Cancelar" ) );
}

