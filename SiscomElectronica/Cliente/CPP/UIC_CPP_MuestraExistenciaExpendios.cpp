/****************************************************************************
** Form implementation generated from reading ui file 'UI/MuestraExistenciaExpendios.ui'
**
** Created: Wed Jan 31 10:48:12 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_MuestraExistenciaExpendios.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a MuestraExistenciaExpendios as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
MuestraExistenciaExpendios::MuestraExistenciaExpendios( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "MuestraExistenciaExpendios" );
    MuestraExistenciaExpendiosLayout = new QGridLayout( this, 1, 1, 11, 6, "MuestraExistenciaExpendiosLayout"); 

    textLabel1 = new QLabel( this, "textLabel1" );

    MuestraExistenciaExpendiosLayout->addWidget( textLabel1, 0, 0 );

    QTExistenciaExpendios = new QTable( this, "QTExistenciaExpendios" );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Producto" ) );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Expendio" ) );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Existencia" ) );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Precio" ) );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "Bodega" ) );
    QTExistenciaExpendios->setNumCols( QTExistenciaExpendios->numCols() + 1 );
    QTExistenciaExpendios->horizontalHeader()->setLabel( QTExistenciaExpendios->numCols() - 1, tr( "E. Bodega" ) );
    QTExistenciaExpendios->setNumRows( 0 );
    QTExistenciaExpendios->setNumCols( 6 );
    QTExistenciaExpendios->setReadOnly( TRUE );

    MuestraExistenciaExpendiosLayout->addWidget( QTExistenciaExpendios, 1, 0 );

    layout21 = new QHBoxLayout( 0, 0, 6, "layout21"); 

    pushButton10 = new QPushButton( this, "pushButton10" );
    layout21->addWidget( pushButton10 );

    pushButton11 = new QPushButton( this, "pushButton11" );
    layout21->addWidget( pushButton11 );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    layout21->addWidget( QPBCancelar );

    MuestraExistenciaExpendiosLayout->addLayout( layout21, 2, 0 );
    languageChange();
    resize( QSize(785, 458).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MuestraExistenciaExpendios::~MuestraExistenciaExpendios()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MuestraExistenciaExpendios::languageChange()
{
    setCaption( tr( "Form1" ) );
    textLabel1->setText( tr( "Existencia Expendios" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 1, tr( "Expendio" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 2, tr( "Existencia" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 3, tr( "Precio" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 4, tr( "Bodega" ) );
    QTExistenciaExpendios->horizontalHeader()->setLabel( 5, tr( "E. Bodega" ) );
    pushButton10->setText( tr( "pushButton10" ) );
    pushButton11->setText( tr( "pushButton11" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

