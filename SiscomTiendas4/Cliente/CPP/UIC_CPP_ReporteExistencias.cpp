/****************************************************************************
** Form implementation generated from reading ui file 'UI/ReporteExistencias.ui'
**
** Created: Thu Apr 11 22:09:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_ReporteExistencias.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QCtrlProductos.h>
#include <QCtrlFamilias.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "QCtrlProductos.h"
#include "QCtrlFamilias.h"

/*
 *  Constructs a ReporteExistencias as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
ReporteExistencias::ReporteExistencias( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ReporteExistencias" );
    ReporteExistenciasLayout = new QGridLayout( this, 1, 1, 11, 6, "ReporteExistenciasLayout"); 

    layout33 = new QVBoxLayout( 0, 0, 6, "layout33"); 

    layout82 = new QHBoxLayout( 0, 0, 6, "layout82"); 

    layout80 = new QHBoxLayout( 0, 0, 6, "layout80"); 

    layout78 = new QVBoxLayout( 0, 0, 6, "layout78"); 

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4->sizePolicy().hasHeightForWidth() ) );
    layout78->addWidget( textLabel4 );

    QCtrProductos = new QCtrlProductos( this, "QCtrProductos" );
    QCtrProductos->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)0, 0, 0, QCtrProductos->sizePolicy().hasHeightForWidth() ) );
    layout78->addWidget( QCtrProductos );
    layout80->addLayout( layout78 );

    layout79 = new QVBoxLayout( 0, 0, 6, "layout79"); 

    textLabel4_2 = new QLabel( this, "textLabel4_2" );
    textLabel4_2->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel4_2->sizePolicy().hasHeightForWidth() ) );
    layout79->addWidget( textLabel4_2 );

    QCtrFamilias = new QCtrlFamilias( this, "QCtrFamilias" );
    QCtrFamilias->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)3, (QSizePolicy::SizeType)0, 0, 0, QCtrFamilias->sizePolicy().hasHeightForWidth() ) );
    layout79->addWidget( QCtrFamilias );
    layout80->addLayout( layout79 );
    layout82->addLayout( layout80 );
    spacer2 = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout82->addItem( spacer2 );
    layout33->addLayout( layout82 );

    layout32 = new QVBoxLayout( 0, 0, 6, "layout32"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout32->addWidget( textLabel1 );

    QTEDsc = new QTextEdit( this, "QTEDsc" );
    QTEDsc->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)7, (QSizePolicy::SizeType)4, 0, 0, QTEDsc->sizePolicy().hasHeightForWidth() ) );
    layout32->addWidget( QTEDsc );
    layout33->addLayout( layout32 );

    layout81 = new QVBoxLayout( 0, 0, 6, "layout81"); 

    textLabel5 = new QLabel( this, "textLabel5" );
    layout81->addWidget( textLabel5 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia Minima" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 3 );
    QTDatos->setReadOnly( TRUE );
    layout81->addWidget( QTDatos );
    layout33->addLayout( layout81 );

    layout31 = new QHBoxLayout( 0, 0, 6, "layout31"); 

    pushButton27 = new QPushButton( this, "pushButton27" );
    layout31->addWidget( pushButton27 );

    QPBTodos = new QPushButton( this, "QPBTodos" );
    layout31->addWidget( QPBTodos );

    pushButton27_2_2 = new QPushButton( this, "pushButton27_2_2" );
    layout31->addWidget( pushButton27_2_2 );
    layout33->addLayout( layout31 );

    ReporteExistenciasLayout->addLayout( layout33, 0, 0 );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
ReporteExistencias::~ReporteExistencias()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void ReporteExistencias::languageChange()
{
    setCaption( tr( "Reporte De Existencias" ) );
    textLabel4->setText( tr( "Producto" ) );
    textLabel4_2->setText( tr( "Familias" ) );
    textLabel1->setText( tr( "Descripcion" ) );
    textLabel5->setText( tr( "Productos" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Existencia" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Existencia Minima" ) );
    pushButton27->setText( tr( "Consulta Por Producto" ) );
    QPBTodos->setText( tr( "Todos Los Productos" ) );
    pushButton27_2_2->setText( tr( "Consulta Por Familia" ) );
}

