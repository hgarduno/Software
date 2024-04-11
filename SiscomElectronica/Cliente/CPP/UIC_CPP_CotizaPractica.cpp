/****************************************************************************
** Form implementation generated from reading ui file 'UI/CotizaPractica.ui'
**
** Created: Wed Apr 10 21:11:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_CotizaPractica.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a CotizaPractica as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
CotizaPractica::CotizaPractica( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "CotizaPractica" );
    CotizaPracticaLayout = new QGridLayout( this, 1, 1, 11, 6, "CotizaPracticaLayout"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel1 = new QLabel( this, "textLabel1" );
    layout10->addWidget( textLabel1 );

    QCBEscuelas = new QComboBox( FALSE, this, "QCBEscuelas" );
    QCBEscuelas->setEditable( TRUE );
    QCBEscuelas->setInsertionPolicy( QComboBox::NoInsertion );
    QCBEscuelas->setAutoCompletion( TRUE );
    QCBEscuelas->setDuplicatesEnabled( FALSE );
    layout10->addWidget( QCBEscuelas );

    CotizaPracticaLayout->addLayout( layout10, 0, 0 );

    layout10_2 = new QVBoxLayout( 0, 0, 6, "layout10_2"); 

    textLabel1_2 = new QLabel( this, "textLabel1_2" );
    layout10_2->addWidget( textLabel1_2 );

    QCBMaterias = new QComboBox( FALSE, this, "QCBMaterias" );
    QCBMaterias->setEditable( TRUE );
    QCBMaterias->setInsertionPolicy( QComboBox::NoInsertion );
    QCBMaterias->setAutoCompletion( TRUE );
    QCBMaterias->setDuplicatesEnabled( FALSE );
    layout10_2->addWidget( QCBMaterias );

    CotizaPracticaLayout->addLayout( layout10_2, 0, 1 );

    layout10_2_2 = new QVBoxLayout( 0, 0, 6, "layout10_2_2"); 

    textLabel1_2_2 = new QLabel( this, "textLabel1_2_2" );
    layout10_2_2->addWidget( textLabel1_2_2 );

    QCBPracticas = new QComboBox( FALSE, this, "QCBPracticas" );
    QCBPracticas->setEditable( TRUE );
    QCBPracticas->setInsertionPolicy( QComboBox::NoInsertion );
    QCBPracticas->setAutoCompletion( TRUE );
    QCBPracticas->setDuplicatesEnabled( FALSE );
    layout10_2_2->addWidget( QCBPracticas );

    CotizaPracticaLayout->addMultiCellLayout( layout10_2_2, 1, 1, 0, 1 );

    QTDatos = new QTable( this, "QTDatos" );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Producto" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Se Puede Vender" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Existencia" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Cantidad" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Precio" ) );
    QTDatos->setNumCols( QTDatos->numCols() + 1 );
    QTDatos->horizontalHeader()->setLabel( QTDatos->numCols() - 1, tr( "Importe" ) );
    QTDatos->setNumRows( 0 );
    QTDatos->setNumCols( 6 );
    QTDatos->setReadOnly( TRUE );

    CotizaPracticaLayout->addMultiCellWidget( QTDatos, 2, 2, 0, 1 );

    layout7 = new QHBoxLayout( 0, 0, 6, "layout7"); 

    layout6 = new QVBoxLayout( 0, 0, 0, "layout6"); 

    QPBAnexar = new QPushButton( this, "QPBAnexar" );
    QPBAnexar->setMinimumSize( QSize( 0, 20 ) );
    QPBAnexar->setMaximumSize( QSize( 32767, 20 ) );
    QPBAnexar->setAutoDefault( FALSE );
    layout6->addWidget( QPBAnexar );

    QPBVende = new QPushButton( this, "QPBVende" );
    QPBVende->setMinimumSize( QSize( 0, 20 ) );
    QPBVende->setMaximumSize( QSize( 32767, 20 ) );
    QPBVende->setAutoDefault( FALSE );
    layout6->addWidget( QPBVende );

    QPBCancelar = new QPushButton( this, "QPBCancelar" );
    QPBCancelar->setMinimumSize( QSize( 0, 20 ) );
    QPBCancelar->setMaximumSize( QSize( 32767, 20 ) );
    QPBCancelar->setAutoDefault( FALSE );
    layout6->addWidget( QPBCancelar );
    layout7->addLayout( layout6 );

    QLCNTotal = new QLCDNumber( this, "QLCNTotal" );
    QLCNTotal->setNumDigits( 8 );
    layout7->addWidget( QLCNTotal );

    CotizaPracticaLayout->addMultiCellLayout( layout7, 3, 3, 0, 1 );
    languageChange();
    resize( QSize(672, 532).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
CotizaPractica::~CotizaPractica()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CotizaPractica::languageChange()
{
    setCaption( tr( "Cotizador de practicas" ) );
    textLabel1->setText( tr( "Escuelas" ) );
    textLabel1_2->setText( tr( "Materia" ) );
    textLabel1_2_2->setText( tr( "Practica" ) );
    QTDatos->horizontalHeader()->setLabel( 0, tr( "Producto" ) );
    QTDatos->horizontalHeader()->setLabel( 1, tr( "Se Puede Vender" ) );
    QTDatos->horizontalHeader()->setLabel( 2, tr( "Existencia" ) );
    QTDatos->horizontalHeader()->setLabel( 3, tr( "Cantidad" ) );
    QTDatos->horizontalHeader()->setLabel( 4, tr( "Precio" ) );
    QTDatos->horizontalHeader()->setLabel( 5, tr( "Importe" ) );
    QPBAnexar->setText( tr( "Anexar A La Orden" ) );
    QPBVende->setText( tr( "Vende lo que hay" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
}

