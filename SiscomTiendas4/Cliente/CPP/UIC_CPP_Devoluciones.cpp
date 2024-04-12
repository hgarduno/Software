/****************************************************************************
** Form implementation generated from reading ui file 'UI/Devoluciones.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_Devoluciones.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a Devoluciones as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
Devoluciones::Devoluciones( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "Devoluciones" );
    DevolucionesLayout = new QGridLayout( this, 1, 1, 11, 6, "DevolucionesLayout"); 

    layout25 = new QHBoxLayout( 0, 0, 6, "layout25"); 

    layout23 = new QVBoxLayout( 0, 0, 6, "layout23"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout23->addWidget( textLabel1 );

    QLENOrden = new QLineEdit( this, "QLENOrden" );
    layout23->addWidget( QLENOrden );
    layout25->addLayout( layout23 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout25->addItem( spacer1 );

    DevolucionesLayout->addLayout( layout25, 0, 0 );

    layout33 = new QHBoxLayout( 0, 0, 6, "layout33"); 

    layout26 = new QVBoxLayout( 0, 0, 6, "layout26"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    textLabel1_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2->sizePolicy().hasHeightForWidth() ) );
    layout26->addWidget( textLabel1_2 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTDatos->sizePolicy().hasHeightForWidth() ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout26->addWidget( QTDatos );
    layout33->addLayout( layout26 );

    layout32 = new QVBoxLayout( 0, 0, 6, "layout32"); 

    layout27 = new QVBoxLayout( 0, 0, 6, "layout27"); 

    textLabel1_3 = new QLabel( this, "textLabel1_3" );
    textLabel1_3->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_3->sizePolicy().hasHeightForWidth() ) );
    layout27->addWidget( textLabel1_3 );

    QTEDsc = new QTextEdit( this, "QTEDsc" );
    QTEDsc->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTEDsc->sizePolicy().hasHeightForWidth() ) );
    QTEDsc->setReadOnly( TRUE );
    layout27->addWidget( QTEDsc );
    layout32->addLayout( layout27 );

    layout28 = new QVBoxLayout( 0, 0, 6, "layout28"); 

    textLabel1_4 = new QLabel( this, "textLabel1_4" );
    textLabel1_4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4->sizePolicy().hasHeightForWidth() ) );
    layout28->addWidget( textLabel1_4 );

    QLCDNTotal = new QLCDNumber( this, "QLCDNTotal" );
    QLCDNTotal->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDNTotal->sizePolicy().hasHeightForWidth() ) );
    layout28->addWidget( QLCDNTotal );
    layout32->addLayout( layout28 );

    layout28_2 = new QVBoxLayout( 0, 0, 6, "layout28_2"); 

    textLabel1_4_2 = new QLabel( this, "textLabel1_4_2" );
    textLabel1_4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_4_2->sizePolicy().hasHeightForWidth() ) );
    layout28_2->addWidget( textLabel1_4_2 );

    QLCDNTotalD = new QLCDNumber( this, "QLCDNTotalD" );
    QLCDNTotalD->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QLCDNTotalD->sizePolicy().hasHeightForWidth() ) );
    layout28_2->addWidget( QLCDNTotalD );
    layout32->addLayout( layout28_2 );
    layout33->addLayout( layout32 );

    DevolucionesLayout->addLayout( layout33, 1, 0 );

    layout26_2 = new QVBoxLayout( 0, 0, 6, "layout26_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    textLabel1_2_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel1_2_2->sizePolicy().hasHeightForWidth() ) );
    layout26_2->addWidget( textLabel1_2_2 );

    QTPADevolver = new QTable( this, "QTPADevolver" );
    QTPADevolver->setNumCols( QTPADevolver->numCols() + 1 );
    QTPADevolver->horizontalHeader()->setLabel( QTPADevolver->numCols() - 1, tr( "Producto" ) );
    QTPADevolver->setNumCols( QTPADevolver->numCols() + 1 );
    QTPADevolver->horizontalHeader()->setLabel( QTPADevolver->numCols() - 1, tr( "Cantidad" ) );
    QTPADevolver->setNumCols( QTPADevolver->numCols() + 1 );
    QTPADevolver->horizontalHeader()->setLabel( QTPADevolver->numCols() - 1, tr( "Importe" ) );
    QTPADevolver->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)7, 0, 0, QTPADevolver->sizePolicy().hasHeightForWidth() ) );
    QTPADevolver->setNumRows( 0 );
    QTPADevolver->setNumCols( 3 );
    QTPADevolver->setReadOnly( TRUE );
    layout26_2->addWidget( QTPADevolver );

    DevolucionesLayout->addLayout( layout26_2, 2, 0 );

    layout35 = new QHBoxLayout( 0, 0, 6, "layout35"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    layout35->addWidget( QPBAnexar );

    QPBEliminar = new QPushButton( this, "QPBEliminar" );
    layout35->addWidget( QPBEliminar );

    QPBDevuelve = new QPushButton( this, "QPBDevuelve" );
    layout35->addWidget( QPBDevuelve );

    DevolucionesLayout->addLayout( layout35, 3, 0 );
    languageChange();
    resize( QSize(600, 747).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Devoluciones::~Devoluciones()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Devoluciones::languageChange()
{
    setCaption( tr( "Devoluciones" ) );
    textLabel1->setText( tr( "# De Orden" ) );
    QLENOrden->setText( tr( "1197973457" ) );
    textLabel1_2->setText( tr( "Productos de la orden" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    textLabel1_3->setText( tr( "Descripcion" ) );
    textLabel1_4->setText( tr( "Total" ) );
    textLabel1_4_2->setText( tr( "Total A Devolver" ) );
    textLabel1_2_2->setText( tr( "Productos A Devolver" ) );
    QTPADevolver->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTPADevolver->horizontalHeader()->setLabel( 1, tr( "Cantidad" ) );
    QTPADevolver->horizontalHeader()->setLabel( 2, tr( "Importe" ) );
    QPBAnexar->setText( tr( "Anexar Productos" ) );
    QPBEliminar->setText( tr( "Eliminar Productos" ) );
    QPBDevuelve->setText( tr( "Ejecutar La Devolucion" ) );
}

