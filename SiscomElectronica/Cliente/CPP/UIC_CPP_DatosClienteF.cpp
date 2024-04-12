/****************************************************************************
** Form implementation generated from reading ui file 'UI/DatosClienteF.ui'
**
** Created: Thu Apr 11 21:52:21 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_DatosClienteF.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a DatosClienteF as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
DatosClienteF::DatosClienteF( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "DatosClienteF" );
    DatosClienteFLayout = new QGridLayout( this, 1, 1, 11, 6, "DatosClienteFLayout"); 

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Limite Inferior" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Limite Superior" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "% Descuento" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );

    DatosClienteFLayout->addWidget( QTDatos, 1, 0 );

    layout39 = new QHBoxLayout( 0, 0, 6, "layout39"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    layout39->addWidget( QPBAnexar );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    layout39->addWidget( QPBRegistrar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    layout39->addWidget( QPBEliminar );

    QPBActualizar = new QPushButton( this, "QPBActualizar" );
    layout39->addWidget( QPBActualizar );

    DatosClienteFLayout->addLayout( layout39, 2, 0 );

    layout42 = new QHBoxLayout( 0, 0, 6, "layout42"); 

    layout35 = new QVBoxLayout( 0, 0, 6, "layout35"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    layout35->addWidget( textLabel6 );

    QLELInferior = new QLineEdit( this, "QLELInferior" );
    layout35->addWidget( QLELInferior );
    layout42->addLayout( layout35 );

    layout35_2 = new QVBoxLayout( 0, 0, 6, "layout35_2"); 

    textLabel6_2 = new QLabel( this, "textLabel6_2" );
    layout35_2->addWidget( textLabel6_2 );

    QLELSuperior = new QLineEdit( this, "QLELSuperior" );
    layout35_2->addWidget( QLELSuperior );
    layout42->addLayout( layout35_2 );

    layout35_2_2 = new QVBoxLayout( 0, 0, 6, "layout35_2_2"); 

    textLabel6_2_2 = new QLabel( this, "textLabel6_2_2" );
    layout35_2_2->addWidget( textLabel6_2_2 );

    QLEDescuento = new QLineEdit( this, "QLEDescuento" );
    layout35_2_2->addWidget( QLEDescuento );
    layout42->addLayout( layout35_2_2 );

    layout35_2_2_2 = new QVBoxLayout( 0, 0, 6, "layout35_2_2_2"); 

    textLabel6_2_2_2 = new QLabel( this, "textLabel6_2_2_2" );
    layout35_2_2_2->addWidget( textLabel6_2_2_2 );

    QLENumDias = new QLineEdit( this, "QLENumDias" );
    QLENumDias->setReadOnly( FALSE );
    layout35_2_2_2->addWidget( QLENumDias );
    layout42->addLayout( layout35_2_2_2 );

    DatosClienteFLayout->addLayout( layout42, 0, 0 );
    languageChange();
    resize( QSize(452, 584).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
DatosClienteF::~DatosClienteF()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void DatosClienteF::languageChange()
{
    setCaption( tr( "Datos Cliente Frecuente" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Limite Inferior" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Limite Superior" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "% Descuento" ) );
    QPBAnexar->setText( tr( "Anexar" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    QPBEliminar->setText( tr( "Eliminar" ) );
    QPBActualizar->setText( tr( "Actualizar" ) );
    textLabel6->setText( tr( "Limite Inferior" ) );
    textLabel6_2->setText( tr( "Limite Superior" ) );
    textLabel6_2_2->setText( tr( "% Descuento" ) );
    textLabel6_2_2_2->setText( tr( "Numero De Dias" ) );
}

