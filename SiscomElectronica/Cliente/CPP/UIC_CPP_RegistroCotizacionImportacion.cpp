/****************************************************************************
** Form implementation generated from reading ui file 'UI/RegistroCotizacionImportacion.ui'
**
** Created: Fri Apr 12 21:26:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "H/UIC_H_RegistroCotizacionImportacion.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


/*
 *  Constructs a RegistroCotizacionImportacion as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RegistroCotizacionImportacion::RegistroCotizacionImportacion( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RegistroCotizacionImportacion" );
    RegistroCotizacionImportacionLayout = new QGridLayout( this, 1, 1, 11, 6, "RegistroCotizacionImportacionLayout"); 

    QPBCancelar = new QPushButton( this, "QPBCancelar" );

    RegistroCotizacionImportacionLayout->addWidget( QPBCancelar, 1, 1 );

    QPBRegistrar = new QPushButton( this, "QPBRegistrar" );
    QPBRegistrar->setEnabled( FALSE );
    QPBRegistrar->setAutoDefault( FALSE );

    RegistroCotizacionImportacionLayout->addWidget( QPBRegistrar, 1, 0 );

    layout12 = new QVBoxLayout( 0, 0, 6, "layout12"); 

    layout10 = new QVBoxLayout( 0, 0, 6, "layout10"); 

    textLabel6 = new QLabel( this, "textLabel6" );
    textLabel6->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, textLabel6->sizePolicy().hasHeightForWidth() ) );
    layout10->addWidget( textLabel6 );

    QTECotizacion = new QTextEdit( this, "QTECotizacion" );
    QTECotizacion->setMinimumSize( QSize( 0, 50 ) );
    QTECotizacion->setMaximumSize( QSize( 32767, 50 ) );
    layout10->addWidget( QTECotizacion );
    layout12->addLayout( layout10 );

    layout9 = new QVBoxLayout( 0, 0, 6, "layout9"); 

    textLabel7 = new QLabel( this, "textLabel7" );
    layout9->addWidget( textLabel7 );

    QTCotizaciones = new QTable( this, "QTCotizaciones" );
    QTCotizaciones->setNumCols( QTCotizaciones->numCols() + 1 );
    QTCotizaciones->horizontalHeader()->setLabel( QTCotizaciones->numCols() - 1, tr( "Cotizacion" ) );
    QTCotizaciones->setNumCols( QTCotizaciones->numCols() + 1 );
    QTCotizaciones->horizontalHeader()->setLabel( QTCotizaciones->numCols() - 1, tr( "Proveedor" ) );
    QTCotizaciones->setNumCols( QTCotizaciones->numCols() + 1 );
    QTCotizaciones->horizontalHeader()->setLabel( QTCotizaciones->numCols() - 1, tr( "Peso" ) );
    QTCotizaciones->setNumCols( QTCotizaciones->numCols() + 1 );
    QTCotizaciones->horizontalHeader()->setLabel( QTCotizaciones->numCols() - 1, tr( "Importe" ) );
    QTCotizaciones->setNumRows( 0 );
    QTCotizaciones->setNumCols( 4 );
    QTCotizaciones->setReadOnly( TRUE );
    layout9->addWidget( QTCotizaciones );
    layout12->addLayout( layout9 );

    RegistroCotizacionImportacionLayout->addMultiCellLayout( layout12, 0, 0, 0, 1 );
    languageChange();
    resize( QSize(468, 516).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RegistroCotizacionImportacion::~RegistroCotizacionImportacion()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RegistroCotizacionImportacion::languageChange()
{
    setCaption( tr( "Form2" ) );
    QPBCancelar->setText( tr( "Cancelar" ) );
    QPBRegistrar->setText( tr( "Registrar" ) );
    textLabel6->setText( tr( "Cotizacion" ) );
    textLabel7->setText( tr( "Cotizaciones" ) );
    QTCotizaciones->horizontalHeader()->setLabel( 0, tr( "Cotizacion" ) );
    QTCotizaciones->horizontalHeader()->setLabel( 1, tr( "Proveedor" ) );
    QTCotizaciones->horizontalHeader()->setLabel( 2, tr( "Peso" ) );
    QTCotizaciones->horizontalHeader()->setLabel( 3, tr( "Importe" ) );
}

