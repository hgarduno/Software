/****************************************************************************
** Form implementation generated from reading ui file 'Qt/Ui/ControlReplicas.ui'
**
** Created: Sat Jan 27 16:37:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ControlReplicas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qgroupbox.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a ControlReplicas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ControlReplicas::ControlReplicas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ControlReplicas" );

    frame14 = new QFrame( this, "frame14" );
    frame14->setGeometry( QRect( 10, 500, 580, 43 ) );
    frame14->setFrameShape( QFrame::StyledPanel );
    frame14->setFrameShadow( QFrame::Raised );
    frame14Layout = new QHBoxLayout( frame14, 11, 6, "frame14Layout"); 

    QPBEjecutar = new QPushButton( frame14, "QPBEjecutar" );
    QPBEjecutar->setEnabled( FALSE );
    frame14Layout->addWidget( QPBEjecutar );

    pushButton4_2 = new QPushButton( frame14, "pushButton4_2" );
    pushButton4_2->setEnabled( FALSE );
    frame14Layout->addWidget( pushButton4_2 );

    pushButton4_3 = new QPushButton( frame14, "pushButton4_3" );
    pushButton4_3->setEnabled( FALSE );
    frame14Layout->addWidget( pushButton4_3 );

    frame4 = new QFrame( this, "frame4" );
    frame4->setGeometry( QRect( 10, 10, 580, 280 ) );
    frame4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, frame4->sizePolicy().hasHeightForWidth() ) );
    frame4->setFrameShape( QFrame::StyledPanel );
    frame4->setFrameShadow( QFrame::Raised );
    frame4Layout = new QGridLayout( frame4, 1, 1, 11, 6, "frame4Layout"); 

    groupBox2 = new QGroupBox( frame4, "groupBox2" );
    groupBox2->setColumnLayout(0, Qt::Vertical );
    groupBox2->layout()->setSpacing( 6 );
    groupBox2->layout()->setMargin( 11 );
    groupBox2Layout = new QGridLayout( groupBox2->layout() );
    groupBox2Layout->setAlignment( Qt::AlignTop );

    QTTransferencias = new QTable( groupBox2, "QTTransferencias" );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Id Replica" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Fecha" ) );
    QTTransferencias->setNumCols( QTTransferencias->numCols() + 1 );
    QTTransferencias->horizontalHeader()->setLabel( QTTransferencias->numCols() - 1, tr( "Destino" ) );
    QTTransferencias->setNumRows( 0 );
    QTTransferencias->setNumCols( 3 );
    QTTransferencias->setReadOnly( TRUE );

    groupBox2Layout->addWidget( QTTransferencias, 0, 0 );

    frame4Layout->addWidget( groupBox2, 0, 0 );

    frame6 = new QFrame( this, "frame6" );
    frame6->setGeometry( QRect( 10, 300, 580, 190 ) );
    frame6->setFrameShape( QFrame::StyledPanel );
    frame6->setFrameShadow( QFrame::Raised );
    frame6Layout = new QGridLayout( frame6, 1, 1, 11, 6, "frame6Layout"); 

    groupBox4 = new QGroupBox( frame6, "groupBox4" );

    frame6Layout->addWidget( groupBox4, 0, 0 );
    languageChange();
    resize( QSize(598, 550).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ControlReplicas::~ControlReplicas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ControlReplicas::languageChange()
{
    setCaption( tr( "Control de Replicas" ) );
    QPBEjecutar->setText( tr( "Ejecutar Accion" ) );
    pushButton4_2->setText( tr( "pushButton4" ) );
    pushButton4_3->setText( tr( "pushButton4" ) );
    groupBox2->setTitle( tr( "Replicas sin ejecutarse" ) );
    QTTransferencias->horizontalHeader()->setLabel( 0, tr( "Id Replica" ) );
    QTTransferencias->horizontalHeader()->setLabel( 1, tr( "Fecha" ) );
    QTTransferencias->horizontalHeader()->setLabel( 2, tr( "Destino" ) );
    groupBox4->setTitle( tr( "Informacion de la replica" ) );
}

