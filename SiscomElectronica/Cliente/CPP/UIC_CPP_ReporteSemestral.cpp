/****************************************************************************
** Form implementation generated from reading ui file 'UI/ReporteSemestral.ui'
**
** Created: Wed Jan 31 10:48:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ReporteSemestral.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <IMP_QControlFecha.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "IMP_QControlFecha.h"

/*
 *  Constructs a ReporteSemestral as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ReporteSemestral::ReporteSemestral( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ReporteSemestral" );
    ReporteSemestralLayout = new QGridLayout( this, 1, 1, 11, 6, "ReporteSemestralLayout"); 

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    layout1 = new QVBoxLayout( 0, 0, 6, "layout1"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel1->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( textLabel1 );

    QCFInicio = new CQControlFecha( this, "QCFInicio" );
    QCFInicio->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCFInicio->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( QCFInicio );
    layout3->addLayout( layout1 );

    layout2 = new QVBoxLayout( 0, 0, 6, "layout2"); 

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, textLabel2->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( textLabel2 );

    QCFFin = new CQControlFecha( this, "QCFFin" );
    QCFFin->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)5, 0, 0, QCFFin->sizePolicy().hasHeightForWidth() ) );
    layout2->addWidget( QCFFin );
    layout3->addLayout( layout2 );
    layout4->addLayout( layout3 );
    spacer1 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout4->addItem( spacer1 );

    ReporteSemestralLayout->addMultiCellLayout( layout4, 0, 0, 0, 1 );

    QPBReporte = new QPushButton( this, "QPBReporte" );

    ReporteSemestralLayout->addWidget( QPBReporte, 2, 0 );

    QPBImprime = new QPushButton( this, "QPBImprime" );

    ReporteSemestralLayout->addWidget( QPBImprime, 2, 1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "P. Venta" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad V." ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Inventario" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Fecha U. C" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad U. C" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio U. C" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Proveedor" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 8 );
    QTDatos->setReadOnly( TRUE );

    ReporteSemestralLayout->addMultiCellWidget( QTDatos, 1, 1, 0, 1 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReporteSemestral::~ReporteSemestral()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReporteSemestral::languageChange()
{
    setCaption( tr( "Reporte Semestral" ) );
    textLabel1->setText( tr( "Fecha Inicio" ) );
    textLabel2->setText( tr( "Fecha Final" ) );
    QPBReporte->setText( tr( "Ejecuta Reporte" ) );
    QPBImprime->setText( tr( "Imprime Reporte" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "P. Venta" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Cantidad V." ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Inventario" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Fecha U. C" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Cantidad U. C" ) );
    QTDatos->horizontalHeader()->setLabel( 6, tr( "Precio U. C" ) );
    QTDatos->horizontalHeader()->setLabel( 7, tr( "Proveedor" ) );
}

