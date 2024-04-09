/****************************************************************************
** Form implementation generated from reading ui file 'UI/ReportandoVentas.ui'
**
** Created: lun abr 1 18:57:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ReportandoVentas.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "IMP_QControlFecha.h"

/*
 *  Constructs a ReportandoVentas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ReportandoVentas::ReportandoVentas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ReportandoVentas" );
    ReportandoVentasLayout = new QGridLayout( this, 1, 1, 11, 6, "ReportandoVentasLayout"); 

    QPBConsultar = new QPushButton( this, "QPBConsultar" );

    ReportandoVentasLayout->addWidget( QPBConsultar, 2, 0 );

    table8 = new QTable( this, "table8" );
    table8->setNumCols( table8->numCols() + 1 );
    table8->horizontalHeader()->setLabel( table8->numCols() - 1, tr( "1" ) );
    table8->setNumCols( table8->numCols() + 1 );
    table8->horizontalHeader()->setLabel( table8->numCols() - 1, tr( "2" ) );
    table8->setNumCols( table8->numCols() + 1 );
    table8->horizontalHeader()->setLabel( table8->numCols() - 1, tr( "3" ) );
    table8->setNumRows( 0 );
    table8->setNumCols( 3 );

    ReportandoVentasLayout->addWidget( table8, 1, 0 );

    layout14 = new QHBoxLayout( 0, 0, 6, "layout14"); 

    layout13 = new QHBoxLayout( 0, 0, 6, "layout13"); 

    layout11 = new QVBoxLayout( 0, 0, 6, "layout11"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout11->addWidget( textLabel1 );

    QCtrFechaInicio = new CQControlFecha( this, "QCtrFechaInicio" );
    QCtrFechaInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaInicio->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( QCtrFechaInicio );
    layout13->addLayout( layout11 );

    layout11_2 = new QVBoxLayout( 0, 0, 6, "layout11_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout11_2->addWidget( textLabel1_2 );

    QCtrFechaFin = new CQControlFecha( this, "QCtrFechaFin" );
    QCtrFechaFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCtrFechaFin->sizePolicy().hasHeightForWidth() ) );
    layout11_2->addWidget( QCtrFechaFin );
    layout13->addLayout( layout11_2 );
    layout14->addLayout( layout13 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout14->addItem( spacer1 );

    ReportandoVentasLayout->addLayout( layout14, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReportandoVentas::~ReportandoVentas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReportandoVentas::languageChange()
{
    setCaption( tr( "Form1" ) );
    QPBConsultar->setText( tr( "Consultar" ) );
    table8->horizontalHeader()->setLabel( 0, tr( "1" ) );
    table8->horizontalHeader()->setLabel( 1, tr( "2" ) );
    table8->horizontalHeader()->setLabel( 2, tr( "3" ) );
    textLabel1->setText( tr( "Fecha Inicio" ) );
    textLabel1_2->setText( tr( "Fecha Fin" ) );
}

